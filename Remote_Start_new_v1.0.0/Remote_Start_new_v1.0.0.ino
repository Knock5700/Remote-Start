
   //This sketch for remote start any car 
   //Car with automatic transmission only
   //version 1.0.0
   //WITHOUT ANY WARRANTY
   //Without delay();
   //Created by: MUS(KNOCK5700),1 Aug 2021
   //you can press button A in remote to start the car
   //you can press button A in remote and press brake pedal to moving the car from starting by key to remote start
   //you can press button B to Turn off the car when a remote start is active
   //you can press button C to horn while remote start is active only
   //you can press button D to horn and light every time
    #include "RCSwitch.h"
    RCSwitch mySwitch = RCSwitch();
    //-------------
    void(* resetFunc) (void) = 0;  // declare reset fuction at address 0 
    unsigned long int buttonA=1234567;//Put the remote control code here(A)
    unsigned long int buttonB=1234567;//Put the remote control code here(B)
    unsigned long int buttonC=1234567;//Put the remote control code here(C)
    unsigned long int buttonD=1234567;//Put the remote control code here(D)
    unsigned long Time1=600000;//10 minutes. time for car started by remote
    unsigned long Time2=1800000;//30 minutes. time for (moving the car from starting by key to remote start)
    unsigned long Time3=1000;//1 second. time for pressing button A in remote(remote start)
    unsigned long Time4=1000;//1 second. time for pressing button A in remote(moving the car from starting by key to remote start)
    //-------------
    unsigned long int rf_zero=0,rf,rfa=0,rfb=0,rfc=0,rfd=0;
    unsigned long t1=0,t2=0,t3=0,t4=0,t5=0,t6=0;
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0;
    int A=0,B=0,C=1,D=0,E=0,F=0,G=0,H=0,I=0,J=0;
    int s1=0,s2=0,s3=0,s4=0,s5=0;
    int car_started,brake_state,hand_brake,driver_door_state;
    int Active=0;//car started by remote
    
    #define light_on digitalWrite(13,1);
    #define light_off digitalWrite(13,0);
    #define ignition_on digitalWrite(12,1);
    #define ignition_off digitalWrite(12,0);
    #define horn_on digitalWrite(11,1);
    #define horn_off digitalWrite(11,0);
    #define starter_on digitalWrite(10,1);
    #define starter_off digitalWrite(10,0);
    #define key_on digitalWrite(9,1);
    #define key_off digitalWrite(9,0);
 void setup() {
    pinMode(13,OUTPUT);//switch light on relay
    pinMode(12,OUTPUT);//ignition1 relay //ignition2 relay
    pinMode(11,OUTPUT);//horn relay
    pinMode(10,OUTPUT);//starter relay
    pinMode(9,OUTPUT);//key pull relay
    ignition_off;
    horn_off;
    light_off;
    starter_off;
    key_off;
    pinMode(3,INPUT_PULLUP);//car started by key state (positive)
    pinMode(4,INPUT_PULLUP);//brake state(positive)
    pinMode(5,INPUT_PULLUP);//hand brake state (gnd)when it's pulled up
    pinMode(6,INPUT_PULLUP);//driver door state(gnd)when it's open
    Serial.begin(9600);
    mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2<-------------
  }
 void loop() {

  if(digitalRead(3)==0){
    car_started=1;
  }//convert Low to High.
  if(digitalRead(3)==1){
    car_started=0;
  }//convert High to Low.
  if(digitalRead(4)==0){
    brake_state=1;
  }//convert Low to High.
  if(digitalRead(4)==1){
    brake_state=0;
  }//convert High to Low.
  if(digitalRead(5)==0){
    hand_brake=1;
  }//convert Low to High.
  if(digitalRead(5)==1){
    hand_brake=0;
  }//convert High to Low.
  if(digitalRead(6)==0){
    driver_door_state=1;
  }//convert Low to High.
  if(digitalRead(6)==1){
    driver_door_state=0;
  }//convert High to Low.
  
  if (mySwitch.available()) {
  rf_zero=1;
  rf=mySwitch.getReceivedValue() ;
  Serial.println(".....");
  Serial.println("rf");
  Serial.println(rf);
  mySwitch.resetAvailable();
  mySwitch.enableReceive(0);
  }
  
  //Serial.println("rf");Serial.println(rf);
  if(!mySwitch.available() && rf_zero>0) {
    rf_zero+=1;
  }
  if(rf_zero>50){
    rf_zero=0;rf=0;
  }
  //Serial.println(rf_zero);
  //Serial.println("rfa");Serial.println(rfa);
  //---------------------------------------------
  
  if(rf==buttonA && rf_zero>0){
    rfa=1;
  //Serial.println("rfa");Serial.println(rfa);
  }
  if(rf!=buttonA && rf_zero==0){
    rfa=0;
  //Serial.println("rfa");Serial.println(rfa);
  }
  //---------------------------------------------
  if(rf==buttonB && rf_zero>0){
    rfb=1;
  //Serial.println("rfb");Serial.println(rfb);
  }
  if(rf!=buttonB && rf_zero==0){
    rfb=0;
  //Serial.println("rfb");Serial.println(rfb);
  }
  //---------------------------------------------
  if(rf==buttonC && rf_zero>0){
    rfc=1;
  //Serial.println("rfc");Serial.println(rfc);
  }
  if(rf!=buttonC && rf_zero==0){
    rfc=0;
  //Serial.println("rfc");Serial.println(rfc);
  }
  //---------------------------------------------
  if(rf==buttonD && rf_zero>0){
    rfd=1;
  //Serial.println("rfd");Serial.println(rfd);
  }
  if(rf!=buttonD && rf_zero==0){
    rfd=0;
  //Serial.println("rfd");Serial.println(rfd);
  }

   
  if (rfa==1 && Active==0 &&  brake_state==0 && car_started==0){// press button A in remote to start the car
    A=1;
  }
  if (A==1){
    counter_1();
  }
  if (B==1 && rfa==1){
    B=2;A=0;
  }
  if (B==1 && rfa==0){
    B=0;A=0;s3=0;
  }
  if (B==2){
    F=1;
  }
  if (F==1){
    Delay_600000();
  }//active remote start 
//---------------------------------------------------------------------------------------------------------------------------------
    
  if(rfb==1 && Active==1){
    I=1;
  }
  if(I==1 && Active==1){
    J=1;
  }
  if(J==1 && Active==1){//press button B to Turn off the car when a remote start is active
    TURN_OFF_BY_REMOTE();
  }

  if (rfd==1){//press button D to horn and light every time
    horn_on;
    light_on;
    D=1;
  }
  if (rfd==0 && D==1){//horn and light off
    horn_off;
    light_off;
    D=0;
  }

  if (rfc==1 && Active==1){//press button C to horn while remote start is active only
    horn_on;
    D=3;
  }
  if (rfc==0 && D==3){//horn off
    horn_off;
    D=0;
  }
  
  if (brake_state==1 && Active==1 && rfa==0){//press brake pedal will be turn off the car (security mode)
    resetFunc();
  }
  /*
  if (driver_door_state==1 && Active==1){//when driver door open the car will be off
  resetFunc();
  }
  */
//----------------------------------------------------------------------------------------------------------------------------------
  if (rfa==1&&Active==0&&brake_state==1&&car_started==1){//press button A in remote and press brake pedal to moving the car from starting by key to remote start
    E=1;
  }
  if (E==1){
    counter_2();
  }
  if (G==1 && rfa==1){
    G=2;
  }
  if (G==1 && rfa==0){
    G=0;s4=0;
  }
  if (G==2){
    H=1;
  }
  if (H==1){
    Delay_1800000();
  }//active remote start when the car started by key   
    
  
  //Serial.println(rfa);
  //Serial.println(rfb);
  //Serial.println(rfc);
  //Serial.println(rfd);
  //Serial.println("A");
  //Serial.println(A);
  //Serial.println("B");
  //Serial.println(B);
  //Serial.println(C);
  //Serial.println(D);
  //Serial.println("Active");
  //Serial.println(Active);
  //Serial.println("brake_state");
  //Serial.println(brake_state);
  //Serial.println("car_started");
  //Serial.println(car_started);
  //Serial.println(hand_brake);
  Serial.println("driver_door_state");
  Serial.println(driver_door_state);
  //Serial.println(G);
  
}


 
