#define THERMISTOR A0
#define FAN 11    //Pin D13 of Uno r3 does'nt support PWM, So i used Pin D11 instead ;)
float Vo;
float R1 = 10000; // Resistance of my NTC at 25c
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07; //Steinhart-Hart Constants

void setup() {


  Serial.begin(9600);
  pinMode(FAN, OUTPUT);
  pinMode(THERMISTOR, INPUT);

}

void loop() {

  Vo = analogRead(THERMISTOR);                        //Read the values from NTC Voltage divider pin.
  R2 = R1 * (1023.0 / Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); //Steinhart-Hart Equation Implemented Here
  Tc = T - 273.15;                                    //Convertion from Kelvin to Celcius
  
  Serial.print("Temperature: "); 
  Serial.print(Tc);
  Serial.println(" C");   

  if(Tc < 25.0){

    Serial.print("Fan Status: OFF "); 
    Serial.println(" || Fan Speed: 0%");
    analogWrite(FAN, 0);

  }

  else if(Tc >= 25.0 && Tc < 30){

    Serial.print("Fan Status: ON");
    Serial.println(" || Fan Speed: 50%");
    analogWrite(FAN, 128);

  }

  else {

    Serial.print("Fan Status: ON");
    Serial.println(" || Fan Speed: 100%");
    analogWrite(FAN, 255);

  }

  delay(1000);
}
