# NTC-Based Fan Control System

This Arduino project reads temperature from a 10k NTC thermistor and controls a fan based on temperature thresholds using PWM.

## Wiring:
- Thermistor connected in a voltage divider circuit with 10k resistor , analog input to A0.
- Fan connected to digital pin D11 (PWM capable).
- Fixed resistor: 10k.
  
## Logic:
- Temperature measurement using the Steinhart-Hart equation.
- Fan control logic:
  - < 25°C → Fan OFF
  - 25°C ≤ Temp < 30°C → Fan at 50% speed
  - ≥ 30°C → Fan at 100% speed

## License
GPL 3.0
