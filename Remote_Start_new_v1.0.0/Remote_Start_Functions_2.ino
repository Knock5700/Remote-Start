 
  void Delay_600000(){//---------------10 minutes
     
    unsigned long c1=millis();
    
    if(c1 - t1 > 0 && s1==0){
      s1=1;
      horn_on;
      light_on;
      t1 = c1;
      }
    if(c1 - t1 > 40 && s1==1){//time for first horn and light on
      s1=2;
      horn_off;
      light_off;
      t1 = c1;
      }
    if(c1 - t1 > 500 && s1==2){//time for first horn and light off
      s1=3;
      horn_on;
      light_on;
      t1 = c1;
      }
    if(c1 - t1 > 40 && s1==3){//time for second horn and light on
      s1=4;
      horn_off;
      light_off;
      t1 = c1;
      }
    if(c1 - t1 > 500 && s1==4){//time for second horn and light off
      s1=5;
      Active=1;
      ignition_on;
      light_on;
      t1 = c1;
      }
    if(c1 - t1 > 3000 && s1==5){//time for ignition and light on 
      s1=6;
      starter_on;
      t1 = c1;
      }
    if(c1 - t1 > 600 && s1==6){//time for starter on 
      s1=7;
      starter_off;
      t1 = c1;
      }
    if(c1 - t1 > Time1 && s1==7){//time for car started by remote
      s1=8;
      ignition_off;
      light_off;
      t1 = c1;
      }
    if(c1 - t1 > 8000 && s1==8){//time for ignition and light off 
      s1=9;
      horn_on;
      light_on;
      key_on;
      t1 = c1;
      }
    if(c1 - t1 > 30 && s1==9){//time for horn and light on after car turned off
      s1=10;
      horn_off;
      light_off;
      key_off;
      resetFunc();//reset all variables
      t1 = c1;
      }
    }
  void Delay_1800000(){//---------------30 minutes
     
    unsigned long c2=millis();
    
    if(c2 - t2 > 0 && s2==0){
      s2=1;
      ignition_on;
      t2 = c2;
      }
    if(c2 - t2 > 5000 && s2==1){//time for leaving brake pedal
      Active=1;
      s2=2;
      t2 = c2;
      }
    if(c2 - t2 > Time2 && s2==2){//time for (moving the car from starting by key to remote start)
      s2=3;
      ignition_off;
      light_off;
      t2 = c2;
      }
    if(c2 - t2 > 8000 && s2==3){//time for ignition and light off 
      s2=4;
      horn_on;
      light_on;
      key_on;
      t2 = c2;
      }
    if(c2 - t2 > 30 && s2==4){//time for horn and light on after car turned off
      s2=5;
      horn_off;
      light_off;
      key_off;
      resetFunc();//reset all variables
      t2 = c2;
      }
    }
  void TURN_OFF_BY_REMOTE(){
     
    unsigned long c5=millis();

    if(c5 - t5 > 0 && s5==0){
      s5=1;
      ignition_off;
      light_off;
      t5 = c5;
      }
    if(c5 - t5 > 8000 && s5==1){//time for ignition and light off
      s5=2;
      horn_on;
      light_on;
      key_on;
      t5 = c5;
      }
    if(c5 - t5 > 30 && s5==2){//time for horn and light on after car turned off
      s5=3;
      horn_off;
      light_off;
      key_off;
      resetFunc();//reset all variables
      t5 = c5;
      }
    }
 
