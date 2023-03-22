#define error_factor1 25
#define error_factor2 25

int up = 50; 
int down = 100;  
int back = 150;  
int forward = 200;  
int left = 250;  
int right = 300;  

#define debug_mode 1

int PhotoDPin = 5;
int dark_point = 0;
uint32_t start;
uint32_t width;

/*
int normal_pulsein(int PIN, int treshold, int error){
  while (true) {
    int sig = analogRead(PIN);
    if (sig > treshold - error && sig > treshold + error) {
    start = millis();
    break;
    }
  }
  while(true) {
    int sig  =  analogRead(PIN);
    if (sig < treshold - error && sig < treshold + error) {
      long width = millis() - start;
      Serial.println(width);
      return(width);
    }
  }
}
*/

int midArifm(int PIN, int NUM_READ){
  float sum = 0;
  for(int i = 0;i < NUM_READ; i++){
    sum += analogRead(0);
  }
  return(sum / NUM_READ);
}

int DmidArifm(int PIN, int NUM_READ){
  float sum = 0;
  for(int i = 0;i < NUM_READ; i++){
    sum += digitalRead(PIN);
  }
  if (sum / NUM_READ < 1){
    return(0);
  }
  else{
    return(1);
  }
}

void   setup() {
  delay(300);
  dark_point = midArifm(A0, 20);
  pinMode(PhotoDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(debug_mode){
    Serial.print(dark_point);
    Serial.print(",");
    Serial.print(dark_point + error_factor1);
    Serial.print(",");
    Serial.print(dark_point - error_factor1);
    Serial.print(",");  
    Serial.print(midArifm(A0, 10));
    Serial.print(",");
    Serial.println(analogRead(A0));
  }


  //Serial.println(width);

  if(!debug_mode){
    width = 0;
    start = millis();
    int sensorValue = midArifm(A0, 10);
    
    while(sensorValue > dark_point - error_factor1 && sensorValue > dark_point + error_factor1){sensorValue = analogRead(A0);}
    width = millis() - start;
    //Serial.println(width);
    if( width < error_factor2){
      //Serial.println('0');
    }
    if (up - error_factor2 <= width && width < up + error_factor2){
      //Serial.print(width);
      Serial.println("u");
    }
    if (down - error_factor2 <= width && width < down + error_factor2){
      
      Serial.println("d");
    }
    if (back - error_factor2 <= width && width < back + error_factor2){
      
      Serial.println("b");
    }
    if (forward - error_factor2 <= width && width < forward + error_factor2){
      
      Serial.println("f");
    }
    if (left - error_factor2 <= width && width < left + error_factor2){
      
      Serial.println("l");
    }
    if (right - error_factor2 <= width && width < right + error_factor2){
      
      Serial.println("r");
    }
  }
}
