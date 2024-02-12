#include <Arduino.h>

#define BUZZER 5
#define BUTTON 0
hw_timer_t *My_timer = NULL;

double c = 1000000/(2*1047) , D = 1000000/(2*1175) , D1 = 1000000/(2*587.3), D2 = 1000000/(2*2349), E = 1000000/(2*1319) , E1 = 1000000/(2*659.3) , F1 = 1000000/(2*1480) , 
      G1 = 1000000/(2*1661) , G = 1000000/(2*1568) , A = 1000000/(2*1760) , B = 1000000/(2*1976) , C = 1000000/(2*523.3) , Stop = 1000000;
double Speed = 2.5;

// This is the Timer ISR. It is automatically called 
// on a timer alarm event.
void IRAM_ATTR onTimer(){
  digitalWrite(BUZZER, !digitalRead(BUZZER));
}

void IRAM_ATTR onButton(){
  digitalWrite(LED, !digitalRead(LED));
  if(Speed > 0.5){
    Speed -= 0.5;
  }else{
    Speed = 2.5;
  }
  Serial.print(Speed);
}

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(BUZZER, OUTPUT);
  My_timer = timerBegin(0, 80, true);  // use timer 0 and set prescale to 80 so 1 tick is 1 uSec
  timerAttachInterrupt(My_timer, &onTimer, true); // point to the ISR
  // timerAlarmWrite(My_timer, 16.35 , true);  // set alarm every 1 sec
  // timerAlarmEnable(My_timer);  // enable the alarm
  //timerAttachInterrupt(My_timer, &onButton, true); // point to the ISR
  attachInterrupt(BUTTON, &onButton, FALLING);
}

void loop() {

  timerAlarmWrite(My_timer, E , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, D , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, c , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, D , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, E , true);
    delay(Speed * 500);
     timerAlarmWrite(My_timer, Stop , true);
      delay(Speed * 100);
  timerAlarmWrite(My_timer, E , true);
    delay(Speed * 400);
     timerAlarmWrite(My_timer, Stop , true);
      delay(Speed * 100);
  timerAlarmWrite(My_timer, E , true);
    delay(Speed * 600);
  timerAlarmWrite(My_timer, D , true);
    delay(Speed * 500);
     timerAlarmWrite(My_timer, Stop , true);
      delay(Speed * 100);
  timerAlarmWrite(My_timer, D , true);
    delay(Speed * 400);
     timerAlarmWrite(My_timer, Stop , true);
      delay(Speed * 100);
  timerAlarmWrite(My_timer, D , true);
    delay(Speed *600);
  timerAlarmWrite(My_timer, E , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, G , true);
    delay(Speed * 400);
      timerAlarmWrite(My_timer, Stop , true);
        delay(Speed * 100);
  timerAlarmWrite(My_timer, G , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, E , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, D , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, c , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, D , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, E , true);
    delay(Speed * 500);
     timerAlarmWrite(My_timer, Stop , true);
      delay(Speed * 100);
  timerAlarmWrite(My_timer, E , true);
    delay(Speed * 400);
     timerAlarmWrite(My_timer, Stop , true);
      delay(Speed * 100);
  timerAlarmWrite(My_timer, E , true);
    delay(Speed * 600);
  timerAlarmWrite(My_timer, D , true);
    delay(Speed * 500);
     timerAlarmWrite(My_timer, Stop , true);
      delay(Speed *100);
  timerAlarmWrite(My_timer, D , true);
    delay(Speed * 400);
     timerAlarmWrite(My_timer, Stop , true);
      delay(Speed * 100);
        timerAlarmWrite(My_timer, E , true);
          delay(Speed * 600);
  timerAlarmWrite(My_timer, D , true);
    delay(Speed * 500);
  timerAlarmWrite(My_timer, c , true);
    delay(Speed * 500);
      timerAlarmWrite(My_timer, Stop , true);
        delay(Speed * 500);
      
  timerAlarmEnable(My_timer);  // enable the alarm
}
