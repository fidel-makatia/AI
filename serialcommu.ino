#include <GSM.h>

GSMVoiceCall vcs;

// initialize the library instance
GSM gsmAccess;
GSM_SMS sms;
char remoteNum[]={'0','7','9','1','7','3','6','2','3','8'};
char msg[]={'i','n','t','r','u','d','e','r'};
#define PINNUMBER ""


int led=13;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
    // connection state
  boolean notConnected = true;
// Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while (notConnected) {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  Serial.println("GSM initialized");
  pinMode(led,OUTPUT);
  
 
}
void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()==0);
//read input
int val=Serial.read()-'0';
if(Serial.available() > 0){
  digitalWrite(led,HIGH);
  gsm();
  
 
  Serial.flush();
}
}
void gsm(){
   //Serial.print("Enter a mobile number: ");
  char remoteNum[20]="0791736238";  // telephone number to send sms
  //readSerial(remoteNum);
  //Serial.println(remoteNum);

  // sms text
 // Serial.print("Now, enter SMS content: ");
  char txtMsg[]="intruder around";
  //String msg="intruder around";
  //readSerial(txtMsg);
 /* Serial.println("SENDING");
  Serial.println();
  Serial.println("Message:");
  Serial.println(txtMsg);

  // send the message
  sms.beginSMS(remoteNum);
  sms.print(txtMsg);
  sms.endSMS();
  Serial.println("\nCOMPLETE!\n");
  */
   //remoteNumber.toCharArray(charbuffer, 20);

   if (vcs.voiceCall(remoteNum)) {
          Serial.println("Call Established. Enter line to end");
          // Wait for some input from the line
          while (Serial.read() != '\n' && (vcs.getvoiceCallStatus() == TALKING));
          // And hang up
          vcs.hangCall();
        }
        Serial.println("Call Finished");
     sms.beginSMS(remoteNum);
 sms.print(txtMsg);
 sms.endSMS();
 
}


/*void servo(){
 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

*/

