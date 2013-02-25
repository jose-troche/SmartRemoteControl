#define CMD_MAX_LEN 32
#define IRledPin 3 // IR LED connected to digital pin 3
#define ledPin  13 // Regular LED to pin 13
#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

int tv_power[] = {
892, 430,
68, 40,
68, 40,
68, 150,
66, 42,
66, 42,
66, 40,
68, 40,
68, 40,
68, 150,
66, 150,
68, 40,
68, 150,
66, 150,
66, 150,
68, 148,
68, 150,
66, 42,
66, 42,
66, 42,
66, 150,
68, 40,
68, 40,
68, 40,
68, 40,
68, 148,
68, 150,
66, 150,
66, 42,
66, 150,
68, 148,
68, 150,
68, 148,
68, 3982,
892, 208,
68, 0};

int tv_tv[] = {
892, 430,
68, 40,
68, 40,
68, 148,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 150,
66, 150,
68, 40,
68, 148,
68, 150,
66, 150,
68, 148,
68, 150,
66, 42,
66, 150,
68, 148,
68, 40,
68, 148,
68, 40,
68, 150,
66, 150,
68, 148,
68, 40,
68, 40,
68, 150,
66, 42,
66, 150,
66, 42,
66, 42,
68, 0};

int tv_hdmi[] = {
898, 426,
74, 34,
72, 36,
72, 144,
72, 36,
72, 36,
72, 36,
72, 36,
74, 34,
72, 146,
72, 144,
72, 36,
72, 144,
74, 144,
70, 146,
72, 144,
72, 144,
74, 34,
74, 144,
72, 144,
72, 36,
70, 38,
72, 36,
72, 144,
72, 144,
74, 144,
72, 36,
72, 36,
72, 144,
74, 144,
72, 144,
72, 36,
72, 36,
72, 3978,
896, 204,
72, 0};

int tv_ch_up[] = {
894, 430,
68, 40,
68, 40,
68, 148,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 148,
68, 150,
68, 40,
66, 150,
68, 150,
66, 150,
68, 148,
68, 148,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 42,
66, 150,
66, 150,
68, 148,
68, 150,
66, 150,
68, 148,
68, 150,
66, 150,
68, 0};

int tv_ch_down[] = {
892, 432,
66, 42,
66, 40,
68, 150,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 148,
68, 150,
66, 42,
66, 150,
68, 148,
68, 148,
68, 150,
66, 150,
68, 148,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 150,
66, 150,
68, 148,
68, 148,
68, 150,
66, 150,
68, 148,
68, 3982,
892, 210,
66, 0};

int tv_vol_up[] = {
892, 430,
68, 40,
68, 40,
68, 150,
66, 42,
66, 42,
66, 42,
66, 42,
66, 42,
68, 148,
68, 148,
68, 40,
68, 148,
68, 150,
68, 148,
68, 148,
68, 148,
70, 40,
68, 148,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 148,
68, 40,
68, 148,
70, 148,
68, 148,
68, 148,
68, 150,
68, 148,
68, 3982,
892, 208,
68, 0};

int tv_vol_down[] = {
894, 430,
68, 40,
68, 40,
68, 148,
68, 40,
68, 40,
68, 40,
68, 40,
68, 40,
68, 148,
68, 150,
66, 42,
66, 150,
68, 148,
68, 148,
68, 150,
68, 148,
68, 148,
68, 150,
68, 40,
68, 40,
68, 40,
68, 40,
66, 42,
66, 42,
66, 42,
68, 40,
66, 150,
68, 148,
68, 148,
68, 150,
68, 148,
68, 150,
66, 3982,
894, 208,
66, 0};

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
      if (command[idx] == '\n') {
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
  if (strcmp("tv_power", command) == 0){
    int len = NELEMS(tv_power);
    sendIRsignal(tv_power, len);
  } 
  else if (strcmp("tv_tv", command) == 0){
    int len = NELEMS(tv_tv);
    sendIRsignal(tv_tv, len);
  }
  else if (strcmp("tv_hdmi", command) == 0){
    int len = NELEMS(tv_hdmi);
    sendIRsignal(tv_hdmi, len);
  }
  else if (strcmp("tv_ch_up", command) == 0){
    int len = NELEMS(tv_ch_up);
    sendIRsignal(tv_ch_up, len);
  }
  else if (strcmp("tv_ch_down", command) == 0){
    int len = NELEMS(tv_ch_down);
    sendIRsignal(tv_ch_down, len);
  }
  else if (strcmp("tv_vol_up", command) == 0){
    int len = NELEMS(tv_vol_up);
    sendIRsignal(tv_vol_up, len);
  }
  else if (strcmp("tv_vol_down", command) == 0){
    int len = NELEMS(tv_vol_down);
    sendIRsignal(tv_vol_down, len);
  }
  else {
    Serial.println("Unknonwn command");
  }
}

void sendIRsignal(int signal[], int len){
  long msecs;
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