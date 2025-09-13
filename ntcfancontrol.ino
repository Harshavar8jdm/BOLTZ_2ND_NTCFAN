//By Akasam Harsha Vardhana Ganesh


#define THERMISTOR A0
#define FAN 13    

float Vo;
float R1 = 10000; 
float logR2, R2, T, Tc;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07; // Constants for Steinhart-Hart Equation

int dutyCycle = 0;            //Duty Cycle according to the temperature.
const int pwmPeriod = 1000;   //1KHz signal is sufficient for Led to not flicker.
unsigned long lastPWM = 0;

void setup() {
  Serial.begin(9600);
  pinMode(FAN, OUTPUT);
  pinMode(THERMISTOR, INPUT);
}

void loop() {
  
  static unsigned long lastRead = 0;
  if (millis() - lastRead > 200) {
    lastRead = millis();             //Reads the analog value from the NTC every 200ms and update the Serial Monitor Values.

    Vo = analogRead(THERMISTOR);
    R2 = R1 * (1023.0 / Vo - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); //Steinhart-Hart Formula
    Tc = T - 273.15;          //Kelvin to Celcius Conversion.

    if (Tc < 25.0){

            dutyCycle = 0;
    }
    else if (Tc < 30.0){
       
            dutyCycle = 50;

    }
    
    else {
      
            dutyCycle = 100;
    
    }

    Serial.print("Temperature: ");
    Serial.print(Tc);
    Serial.print(" °C || Fan: ");
    Serial.print(dutyCycle);
    Serial.println("%");
  }
                                              //Micros() is a non blocking approach, As long as the loop runs, Serial prints every 200ms and 
                                              //PWM doesnt wait for Serial Prints to complete, so the signal is stable at 1khz.
  int onTime = (dutyCycle * pwmPeriod) / 100; // Ex: if duty cycle is 50, onTime = (50 * 1000)/100 = 500us.
  int offTime = pwmPeriod - onTime;           // offTime = 1000 - 500 = 500us
  unsigned long currentTime = micros();       // Lets say micros() now = 10000us 
  int cycleTime = currentTime % pwmPeriod;    // then cycleTime = 10000%1000 = 0 us 
                                              // here cycleTime < onTime, pin 13 == LOW

  if (cycleTime < onTime) {
    digitalWrite(FAN, HIGH);
  } else {                                    // if micros() = 12520us, cycleTime = 520us, cycleTime>ontime, pin 13 == HIGH
    digitalWrite(FAN, LOW);
  }
}
