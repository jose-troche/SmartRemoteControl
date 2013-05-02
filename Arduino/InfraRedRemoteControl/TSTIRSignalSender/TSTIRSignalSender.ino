#define CMD_MAX_LEN 32
#define IRledPin 3 // IR LED connected to digital pin 3
#define ledPin  13 // Regular LED to pin 13
#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

int tv_vol_up[] = {
456, 428,
70, 150,
70, 152,
70, 150,
70, 40,
70, 38,
70, 38,
72, 38,
70, 38,
72, 150,
70, 150,
70, 152,
70, 38,
70, 40,
70, 38,
70, 38,
72, 38,
70, 150,
72, 150,
70, 150,
72, 38,
70, 38,
70, 40,
70, 38,
70, 38,
72, 38,
70, 38,
70, 40,
70, 150,
70, 152,
70, 150,
70, 152,
70, 150,
70, 4600,
456, 428,
70, 150,
70, 152,
70, 150,
70, 40,
70, 38,
70, 38,
72, 38,
70, 38,
72, 150,
70, 150,
70, 152,
70, 38,
72, 38,
70, 38,
72, 38,
70, 38,
70, 150,
72, 150,
70, 150,
72, 38,
70, 38,
72, 38,
70, 38,
72, 36,
72, 38,
72, 36,
72, 38,
70, 150,
72, 150,
70, 150,
72, 150,
70, 150,
70, 0};

int tv_vol_down[] = {
458, 426,
72, 148,
74, 148,
72, 148,
72, 38,
70, 38,
74, 36,
72, 36,
72, 38,
70, 150,
74, 146,
74, 148,
72, 38,
70, 38,
72, 36,
72, 38,
72, 36,
72, 150,
72, 148,
74, 36,
70, 150,
72, 38,
74, 34,
72, 38,
72, 36,
72, 36,
74, 36,
72, 148,
74, 36,
74, 146,
74, 148,
72, 148,
72, 150,
72, 4598,
458, 426,
72, 148,
72, 150,
70, 150,
72, 36,
74, 36,
70, 38,
74, 36,
72, 36,
72, 150,
72, 148,
72, 150,
72, 36,
72, 36,
72, 38,
72, 36,
72, 38,
72, 148,
74, 148,
72, 36,
72, 150,
72, 36,
72, 38,
70, 38,
72, 38,
72, 36,
70, 38,
74, 148,
72, 36,
72, 150,
70, 150,
72, 150,
72, 148,
72, 0};

int tv_source[] = {
454, 430,
68, 152,
70, 152,
68, 152,
68, 42,
68, 40,
68, 42,
68, 40,
68, 40,
70, 152,
68, 152,
68, 154,
68, 40,
68, 42,
68, 40,
68, 42,
68, 40,
68, 152,
68, 42,
68, 40,
68, 42,
68, 40,
68, 42,
68, 40,
68, 40,
68, 42,
68, 154,
66, 154,
68, 154,
66, 154,
68, 152,
70, 152,
68, 152,
68, 4602,
454, 430,
68, 152,
68, 154,
68, 152,
68, 42,
66, 42,
68, 42,
66, 42,
68, 42,
66, 154,
68, 152,
68, 154,
68, 40,
68, 42,
68, 40,
68, 42,
68, 40,
68, 152,
70, 40,
68, 40,
70, 40,
68, 40,
68, 42,
68, 40,
68, 42,
68, 40,
68, 152,
70, 152,
68, 152,
68, 154,
68, 152,
68, 154,
68, 152,
68, 0};

int tv_power[] = {
454, 430,
68, 152,
70, 152,
68, 152,
68, 42,
68, 40,
68, 40,
70, 40,
68, 40,
70, 152,
70, 150,
68, 154,
70, 38,
68, 42,
68, 40,
70, 38,
70, 40,
68, 40,
70, 152,
68, 40,
68, 42,
68, 40,
68, 42,
68, 40,
68, 40,
70, 152,
70, 38,
70, 152,
68, 152,
70, 152,
68, 152,
68, 152,
70, 152,
68, 4602,
452, 432,
66, 154,
70, 150,
72, 150,
70, 38,
70, 40,
68, 40,
70, 40,
68, 40,
68, 152,
70, 152,
68, 152,
70, 0};

/*
int tv_vol_up2[] = {
454, 428,
68, 154,
66, 154,
68, 154,
66, 42,
68, 42,
66, 42,
66, 44,
66, 42,
66, 156,
66, 154,
66, 154,
68, 42,
66, 42,
66, 44,
66, 42,
66, 44,
66, 154,
66, 154,
68, 154,
66, 42,
68, 42,
66, 42,
68, 42,
66, 42,
66, 44,
66, 42,
66, 44,
66, 154,
68, 152,
68, 154,
66, 154,
68, 154,
66, 4604,
454, 428,
70, 152,
68, 152,
70, 152,
68, 40,
70, 40,
68, 40,
70, 38,
70, 40,
70, 150,
70, 152,
70, 150,
70, 40,
70, 38,
70, 38,
72, 38,
70, 38,
70, 152,
70, 150,
70, 152,
70, 38,
70, 40,
70, 38,
70, 38,
72, 38,
70, 38,
70, 40,
70, 38,
70, 152,
70, 150,
70, 152,
70, 150,
70, 152,
70, 0};

int tv_vol_down2[] = {
456, 428,
68, 152,
68, 154,
68, 152,
70, 40,
66, 42,
76, 36,
64, 42,
76, 36,
64, 156,
68, 154,
68, 152,
64, 42,
68, 42,
74, 38,
64, 42,
72, 38,
66, 156,
72, 146,
70, 40,
66, 154,
66, 44,
70, 40,
70, 36,
68, 44,
64, 44,
68, 40,
72, 148,
68, 42,
74, 148,
64, 158,
74, 146,
64, 158,
72, 4594,
454, 432,
72, 150,
64, 156,
66, 154,
66, 42,
66, 42,
76, 36,
62, 44,
68, 44,
72, 148,
64, 154,
76, 148,
64, 44,
64, 44,
74, 36,
64, 42,
68, 42,
70, 150,
68, 154,
76, 34,
64, 156,
74, 36,
64, 42,
68, 44,
70, 38,
66, 44,
70, 38,
66, 156,
72, 34,
66, 156,
68, 152,
66, 156,
68, 152,
68, 0};
*/

int heli_up[] = {
56, 22,
168, 24,
56, 24,
92, 22,
92, 24,
94, 24,
54, 22,
54, 24,
56, 22,
92, 24,
56, 20,
94, 20,
58, 22,
56, 20,
58, 20,
56, 22,
56, 22,
92, 24,
92, 24,
92, 24,
92, 24,
94, 22,
56, 22,
54, 22,
56, 22,
58, 20,
94, 22,
92, 24,
94, 22,
94, 22,
94, 22,
56, 0};

void setup(void) {
  pinMode(IRledPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.flush();
  Serial.println("Ready to read commands!");
}

char command[CMD_MAX_LEN];
int idx = -1;

void loop() {
  if (Serial.available()) {
    if (++idx < CMD_MAX_LEN){
      command[idx] = Serial.read();
      if (command[idx] == '\n' || command[idx] == '\r') {
        command[idx] = 0;
        execute(command);
        idx = -1;
      }
    }
    else {
      Serial.print("Command is too long");
      idx = -1;
    }
  }
}

void execute(char * command){
  Serial.print("Executing command ");
  Serial.println(command);
  if (strcmp("tv_vol_up", command) == 0){
    int len = NELEMS(tv_vol_up);
    sendIRsignal(tv_vol_up, len);
  }
  else if (strcmp("tv_vol_down", command) == 0){
    int len = NELEMS(tv_vol_down);
    sendIRsignal(tv_vol_down, len);
  }
  else if (strcmp("tv_power", command) == 0){
    int len = NELEMS(tv_power);
    sendIRsignal(tv_power, len);
  }
  else if (strcmp("tv_source", command) == 0){
    int len = NELEMS(tv_source);
    sendIRsignal(tv_source, len);
  }
  else if (strcmp("heli_up", command) == 0){
    int len = NELEMS(heli_up);
    sendIRsignal(heli_up, len);
  }
  else {
    Serial.println("Unknonwn command");
  }
}

void sendIRsignal(int signal[], int len){
  long msecs;
  Serial.print("len ");
  Serial.println(len);
  digitalWrite(ledPin, HIGH);
  for (int i=0; i<len; i++){
    msecs = signal[i]*10;
    if (i%2 == 0){ 
      pulseIR(msecs);
    }
    else {
      delayMicroseconds(msecs);
    }
  }
  digitalWrite(ledPin, LOW);
}

// This function sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds.
// Copied from  http://learn.adafruit.com/ir-sensor/
void pulseIR(long microsecs) {
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
  
  sei();  // this turns them back on
}
