 void counter_1(){
    
    unsigned long c3=millis();
   
  if(c3 - t3 > 0 && s3==0){
    s3=1;
    t3 = c3;
    }
  if(c3 - t3 > Time3 && s3==1){//time for pressing button A in remote(remote start)
    s3=2;
    B=1;
    t3 = c3;
    }
  }

  void counter_2(){
    
    unsigned long c4=millis();
   
  if(c4 - t4 > 0 && s4==0){
    s4=1;
    t4 = c4;
    }
  if(c4 - t4 > Time4 && s4==1){//time for pressing button A in remote(moving the car from starting by key to remote start)
    s4=2;
    G=1;
    t4 = c4;
    }
  }
  

 
 
