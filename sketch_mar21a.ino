int up = 50; 
int down = 100;  
int back = 150;  
int forward = 200;  
int left = 250;  
int right = 300;  

#define up_button_pin 6
#define down_button_pin 5
#define back_button_pin 7
#define forward_button_pin 8
#define left_button_pin 9
#define right_button_pin 10

#define laser_pin 11

void setup() {
  pinMode(laser_pin , OUTPUT);
  pinMode(up_button_pin, INPUT_PULLUP);
  pinMode(down_button_pin, INPUT_PULLUP);
  pinMode(back_button_pin, INPUT_PULLUP);
  pinMode(forward_button_pin, INPUT_PULLUP);
  pinMode(left_button_pin, INPUT_PULLUP);
  pinMode(right_button_pin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  if(!digitalRead(up_button_pin)){
    digitalWrite(laser_pin, HIGH);
    int start = millis();
    Serial.println("up");
    while(millis()- start <= up){}
    digitalWrite(laser_pin, LOW);
    start = millis();
    while(millis()- start <= down){}
  }
  else if(!digitalRead(down_button_pin)){
    digitalWrite(laser_pin, HIGH);
    int start = millis();
    Serial.println("down");
    while(millis()- start <= down){}
    digitalWrite(laser_pin, LOW);
    start = millis();
    while(millis()- start <= down){}
  }
  else if(!digitalRead(back_button_pin)){
    int start = millis();
    digitalWrite(laser_pin, HIGH);
    Serial.println("back");
    while(millis()- start <= back){}
    digitalWrite(laser_pin, LOW);
    start = millis();
    while(millis()- start <= down){}
  }
  else if(!digitalRead(forward_button_pin)){
    int start = millis();
    digitalWrite(laser_pin, HIGH);
    Serial.println("forward");
    while(millis()- start <= forward){}
    digitalWrite(laser_pin, LOW);
    start = millis();
    while(millis()- start <= down){}
  }
  else if(!digitalRead(left_button_pin)){
    int start = millis();
    digitalWrite(laser_pin, HIGH);
    Serial.println("left");
    while(millis()- start <= left){}
    digitalWrite(laser_pin, LOW);
    start = millis();
    while(millis()- start <= down){}
  }
  else if(!digitalRead(right_button_pin)){
    int start = millis();
    digitalWrite(laser_pin, HIGH);
    Serial.println("right");
    while(millis()- start <= right){}
    digitalWrite(laser_pin, LOW);
    start = millis();
    while(millis()- start <= down){}
  }
}
