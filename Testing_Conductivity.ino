
#include <conductivity.h>
int myCalibrationFunction(int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int conductivityReading = getConductivity();
  int salinity = myCalibrationFunction(conductivityReading);
  Serial.println("Salinity Reading:");
  Serial.println(salinity);
}

int myCalibrationFunction(int reading)
{
  return reading;
}
