#define CMD_MAX_LEN 32
#define MAX_SIGNAL_LEN 200
#define IRledPin 3 // IR LED connected to digital pin 3
#define ledPin  13 // Regular LED to pin 13
#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))

/* Terminate the signal int arrays with 0 or a negative number ! */
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

int dvd_power[] = {
904, 430,
72, 150,
68, 40,
70, 152,
70, 38,
72, 38,
68, 40,
70, 40,
68, 152,
70, 152,
70, 38,
70, 152,
70, 150,
70, 40,
70, 150,
70, 152,
70, 150,
70, 38,
70, 152,
70, 152,
70, 38,
70, 40,
70, 38,
70, 40,
70, 38,
70, 150,
72, 38,
68, 40,
68, 154,
70, 150,
72, 150,
72, 148,
72, 150,
68, 3862,
902, 208,
70, 0};


int dvd_eject[] = {
896, 440,
64, 156,
64, 46,
62, 158,
64, 44,
66, 44,
66, 42,
68, 42,
64, 156,
64, 158,
66, 42,
66, 156,
66, 154,
66, 44,
64, 156,
66, 156,
64, 156,
68, 42,
64, 156,
66, 156,
66, 42,
64, 46,
64, 156,
62, 48,
62, 46,
64, 156,
66, 44,
68, 44,
62, 156,
64, 158,
64, 44,
66, 154,
68, 154,
66, 3864,
896, 212,
68, 0};
/*
int dvd_stop[] = {
894, 442,
60, 158,
68, 42,
64, 158,
66, 44,
64, 44,
62, 48,
64, 42,
64, 158,
66, 154,
66, 44,
64, 156,
66, 154,
66, 46,
62, 160,
62, 158,
64, 156,
64, 156,
66, 42,
68, 44,
64, 158,
64, 154,
68, 40,
68, 44,
62, 44,
64, 48,
62, 156,
64, 158,
66, 42,
68, 42,
64, 156,
64, 160,
64, 154,
66, 3864,
896, 214,
66, 0};

int dvd_play[] = {
904, 430,
70, 150,
72, 38,
70, 150,
72, 38,
70, 38,
74, 36,
68, 40,
72, 150,
70, 150,
70, 40,
70, 150,
68, 154,
68, 40,
72, 150,
70, 150,
70, 152,
70, 38,
70, 152,
70, 38,
72, 150,
68, 152,
70, 40,
70, 38,
70, 40,
68, 152,
70, 40,
70, 150,
70, 38,
72, 38,
72, 148,
70, 152,
70, 152,
70, 3858,
902, 208,
72, 0};

int dvd_menu[] = {
902, 432,
70, 152,
70, 38,
68, 154,
68, 40,
72, 38,
68, 40,
68, 44,
68, 150,
70, 152,
70, 38,
70, 152,
68, 154,
70, 36,
72, 150,
68, 154,
68, 152,
70, 152,
70, 150,
68, 42,
68, 152,
70, 40,
68, 40,
68, 42,
68, 40,
68, 40,
70, 40,
70, 150,
70, 40,
70, 150,
68, 154,
68, 152,
70, 152,
70, 3860,
900, 210,
66, 0};

int apple_center[] = {
904, 422,
74, 36,
74, 144,
72, 146,
72, 146,
72, 36,
74, 144,
74, 144,
72, 146,
74, 142,
74, 144,
74, 144,
74, 36,
74, 36,
72, 38,
72, 36,
74, 144,
74, 144,
72, 38,
70, 146,
74, 144,
74, 144,
74, 36,
72, 144,
74, 36,
72, 146,
74, 36,
72, 36,
74, 36,
74, 144,
76, 142,
74, 142,
74, 38,
72, 3530,
902, 422,
74, 36,
72, 146,
74, 142,
74, 144,
74, 36,
72, 144,
76, 142,
74, 144,
74, 144,
72, 146,
72, 146,
74, 34,
74, 36,
74, 36,
72, 36,
74, 144,
72, 38,
72, 38,
72, 146,
70, 38,
74, 36,
74, 36,
72, 36,
74, 36,
74, 144,
74, 36,
72, 38,
72, 38,
70, 146,
74, 144,
74, 144,
74, 36,
76, 0};

int apple_up[] = {
906, 422,
74, 36,
72, 146,
72, 144,
76, 142,
74, 36,
74, 144,
74, 144,
74, 142,
72, 146,
74, 144,
74, 144,
74, 36,
74, 34,
74, 36,
74, 36,
74, 144,
72, 144,
76, 142,
76, 34,
74, 144,
74, 36,
72, 38,
72, 36,
74, 36,
74, 144,
74, 36,
72, 36,
76, 34,
74, 144,
74, 144,
72, 146,
70, 40,
74, 0};

int apple_down[] = {
904, 422,
72, 38,
74, 144,
72, 146,
72, 144,
74, 36,
74, 144,
74, 144,
74, 144,
74, 142,
74, 144,
76, 142,
72, 38,
72, 38,
72, 36,
74, 36,
74, 144,
70, 146,
76, 34,
74, 144,
74, 144,
72, 38,
72, 38,
70, 38,
72, 38,
74, 144,
74, 36,
72, 36,
74, 36,
74, 144,
72, 146,
72, 144,
72, 40,
74, 0};

int apple_left[] = {
902, 424,
74, 36,
72, 146,
70, 146,
72, 146,
70, 40,
70, 148,
72, 146,
70, 146,
72, 146,
72, 146,
72, 146,
72, 38,
70, 38,
72, 38,
72, 38,
70, 148,
70, 40,
70, 38,
74, 36,
72, 146,
72, 38,
72, 36,
74, 36,
72, 38,
72, 146,
72, 38,
70, 38,
72, 38,
74, 144,
72, 146,
70, 148,
70, 40,
72, 0};

int apple_right[] = {
902, 424,
72, 38,
70, 146,
72, 146,
72, 146,
72, 38,
72, 146,
70, 148,
70, 146,
72, 146,
70, 148,
70, 148,
70, 38,
72, 38,
72, 38,
70, 40,
70, 146,
72, 146,
72, 146,
74, 144,
70, 40,
70, 40,
70, 38,
72, 38,
72, 38,
70, 148,
70, 38,
72, 38,
72, 38,
70, 148,
70, 148,
70, 146,
74, 38,
70, 0};

int apple_play[] = {
906, 422,
72, 36,
74, 144,
74, 144,
74, 144,
74, 34,
74, 144,
72, 146,
72, 146,
72, 146,
72, 146,
72, 144,
74, 36,
72, 38,
70, 40,
70, 40,
70, 146,
74, 36,
72, 146,
72, 146,
72, 144,
72, 146,
72, 38,
72, 146,
72, 38,
70, 148,
72, 36,
74, 36,
72, 38,
72, 146,
72, 144,
74, 144,
72, 40,
72, 3530,
902, 422,
74, 36,
74, 144,
72, 144,
74, 144,
74, 36,
74, 144,
74, 144,
72, 144,
72, 146,
74, 144,
72, 146,
72, 38,
72, 38,
72, 36,
72, 38,
70, 148,
72, 38,
72, 36,
72, 146,
74, 36,
72, 38,
72, 38,
70, 38,
72, 38,
72, 146,
72, 38,
72, 36,
74, 36,
74, 144,
74, 144,
72, 146,
72, 38,
72, 0};

int apple_menu[] = {
908, 418,
74, 36,
72, 146,
72, 144,
74, 144,
74, 36,
74, 144,
74, 144,
72, 146,
72, 144,
74, 144,
74, 144,
74, 36,
72, 36,
76, 34,
74, 36,
74, 144,
74, 36,
72, 144,
74, 36,
74, 36,
74, 36,
72, 36,
74, 36,
72, 38,
72, 146,
74, 36,
72, 36,
74, 36,
74, 144,
72, 146,
72, 144,
74, 38,
74, 0};
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
  if (strcmp("tv_power", command) == 0){
    sendIRsignal(tv_power);
  }
  else if (strcmp("tv_tv", command) == 0){
    sendIRsignal(tv_tv);
  }
  else if (strcmp("tv_hdmi", command) == 0){
    sendIRsignal(tv_hdmi);
  }
  else if (strcmp("tv_ch_up", command) == 0){
    sendIRsignal(tv_ch_up);
  }
  else if (strcmp("tv_ch_down", command) == 0){
    sendIRsignal(tv_ch_down);
  }
  else if (strcmp("tv_vol_up", command) == 0){
    sendIRsignal(tv_vol_up);
  }
  else if (strcmp("tv_vol_down", command) == 0){
    sendIRsignal(tv_vol_down);
  }
  else if (strcmp("dvd_power", command) == 0){
    sendIRsignal(dvd_power);
  }
  else if (strcmp("dvd_eject", command) == 0){
    sendIRsignal(dvd_eject);
  }/*
  else if (strcmp("dvd_stop", command) == 0){
    int len = NELEMS(dvd_stop);
    sendIRsignal(dvd_stop, len);
  }
  else if (strcmp("dvd_play", command) == 0){
    int len = NELEMS(dvd_play);
    sendIRsignal(dvd_play, len);
  }
  else if (strcmp("apple_play", command) == 0){
    int len = NELEMS(apple_play);
    sendIRsignal(apple_play, len);
  }
  else if (strcmp("apple_menu", command) == 0){
    int len = NELEMS(apple_menu);
    sendIRsignal(apple_menu, len);
  }
  else if (strcmp("apple_center", command) == 0){
    int len = NELEMS(apple_center);
    sendIRsignal(apple_center, len);
  }
  else if (strcmp("apple_up", command) == 0){
    int len = NELEMS(apple_up);
    sendIRsignal(apple_up, len);
  }
  else if (strcmp("apple_down", command) == 0){
    int len = NELEMS(apple_down);
    sendIRsignal(apple_down, len);
  }
  else if (strcmp("apple_left", command) == 0){
    int len = NELEMS(apple_left);
    sendIRsignal(apple_left, len);
  }
  else if (strcmp("apple_right", command) == 0){
    int len = NELEMS(apple_right);
    sendIRsignal(apple_right, len);
  }*/
  else if (strcmp("heli_up", command) == 0){
    /*int len = NELEMS(heli_up);*/
    sendIRsignal(heli_up);/*, len);*/
  }
  else {
    Serial.println("Unknonwn command");
  }
}

void sendIRsignal(int signal[]/*, int len*/){
  long msecs;
  digitalWrite(ledPin, HIGH);
  for (int i=0; signal[i]>0 && i<MAX_SIGNAL_LEN/*i<len*/; i++){
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
   delayMicroseconds(9);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(9);         // hang out for 10 microseconds, you can also change this to 9 if its not working
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
  
  sei();  // this turns them back on
}
