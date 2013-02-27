package arduino;

import java.io.*;
import java.net.*;
import java.util.StringTokenizer;

public class RemoteControlServer {
	private static String serialPortName = "COM4";
	
	public static void main(String args[]) throws Exception {
		String requestMessageLine;
		String command;
		String origin;
		BufferedReader in = null;
		PrintWriter out = null;
		Socket connectionSocket = null; 
		ServerSocket listenSocket;

		int serverPort = 80;
		if (args.length > 0) {
			serverPort = Integer.parseInt(args[0]);
		}
		
		if (args.length > 1) 
			serialPortName = args[1];

		listenSocket = new ServerSocket(serverPort);
		System.out.println("Server waiting for requests on port " + serverPort + 
				" and sending commands to serial port " + serialPortName);
		
		try {
			while(true){
				try{
					connectionSocket = listenSocket.accept();
					origin = connectionSocket.getInetAddress().getHostAddress();
			
					in = new BufferedReader(new InputStreamReader(
							connectionSocket.getInputStream()));
					out = new PrintWriter(
							connectionSocket.getOutputStream(), true); 
			
					requestMessageLine = in.readLine();
					
					if (requestMessageLine != null){
						System.out.println(origin + " - request: " + requestMessageLine);
						StringTokenizer tokenizedLine = new StringTokenizer(requestMessageLine);
				
						// Check for GET request
						if (tokenizedLine.nextToken().equals("GET")) {
							command = tokenizedLine.nextToken();
							if (command.startsWith("/cmd/") == true) {
								command = command.substring(5);
								if (command.length() > 32) 
									throw new Exception("Command too long"); 
								System.out.println("Executing command: " + command);
								writeToSerialPort(command);
							}
							else command = "Unrecognized request"; 
				
							// Send reply
							out.print("HTTP/1.1 200 OK\r\n");
							out.print("Content-Type: text/plain\r\n");
							out.print("\r\n");
							out.print("Executed command: " + command);
						}
					}
				}
				catch(Exception e){
					System.err.println("Error: "+e);
					out.print("HTTP/1.1 500 Error\r\n");
				}
				finally{
					out.close();
					in.close();
					connectionSocket.close();
				}
			}
		}
		finally {
			listenSocket.close();
		}
	}
	
	private static void writeToSerialPort(String command){
		try {
			String dosCommand = "mode " + serialPortName +
					" 9600,n,8,1 && echo " + command + ">" + serialPortName;
			Process pr = Runtime.getRuntime().exec("cmd /c " + dosCommand);
			pr.waitFor(); // Wait until execution is finished
		}
		catch (Exception e){
			System.err.println("Error when writing to serial port " +
					serialPortName + ", " + e);
			System.exit(-1);
		}
	}
}
