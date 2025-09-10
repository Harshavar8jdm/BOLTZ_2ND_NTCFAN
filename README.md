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

## Outputs: 

  - Temperature < 25c:
  ![WhatsApp Image 2025-09-10 at 5 12 29 PM](https://github.com/user-attachments/assets/92186e2d-c4ae-428b-901a-38157f3cb2b1)
  <img width="481" height="509" alt="Screenshot From 2025-09-10 16-51-37" src="https://github.com/user-attachments/assets/ef9fc379-f78f-4e1a-81ec-4e09f177fcf8" />

  - 25c <= Temperature <30c :
    ![WhatsApp Image 2025-09-10 at 5 12 35 PM](https://github.com/user-attachments/assets/5c885bfe-3fcd-4122-9147-8fbc9df5541c)
    <img width="481" height="509" alt="Screenshot From 2025-09-10 16-51-49" src="https://github.com/user-attachments/assets/b91e176e-b6ef-4232-8e0a-473c9e5855b0" />

  - Temperature > 30c:
    <img width="481" height="509" alt="Screenshot From 2025-09-10 16-53-08" src="https://github.com/user-attachments/assets/dc9b8bfe-c446-45bc-a6e5-eb1f702c5f30" />


  
