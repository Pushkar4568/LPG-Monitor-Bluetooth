# LPG-Monitor-Bluetooth

MQ-2 Gas Sensor Project with Bluetooth: Real-time LPG, CH₄, CO, and H₂ monitoring using MQ-2. Includes calibrated constants for accurate PPM calculation and wireless data transmission via Bluetooth. Uses STM32 HAL library.

## Features
- Measures LPG, Methane (CH₄), Carbon Monoxide (CO), and Hydrogen (H₂)
- Real-time PPM calculation with calibrated constants
- Wireless data transmission via Bluetooth
- Works with STM32 using HAL libraries

## Constants Used
| Gas | A | B |
|-----|---|---|
| LPG | 565 | -1.48 |
| CH₄ | 393 | -1.18 |
| CO  | 472 | -1.28 |
| H₂  | 575 | -1.26 |

> **Note:** RO must be calibrated in clean air for accurate readings.

## Wiring / Connections
- MQ-2 VCC → 3.3V / 5V (depending on your board)
- MQ-2 GND → GND
- MQ-2 analog output → STM32 ADC pin
- Bluetooth module TX/RX → STM32 UART pins
- Pins used PA9&PA10 - Usart1, PA0 - ADC0


# HC-05:
![WhatsApp Image 2025-08-27 at 00 10 09_1d2d37e1](https://github.com/user-attachments/assets/2123200e-0415-45ec-96f9-cf25a7e4e7e6)


# MQ-2:
![WhatsApp Image 2025-08-27 at 00 10 26_c2c8d9b5](https://github.com/user-attachments/assets/ea1942d9-1d7d-4a6e-9428-e850c7e675c9)

# OUTPUT :
![WhatsApp Image 2025-08-26 at 23 50 29_fa0971e1](https://github.com/user-attachments/assets/1f17016e-49bd-4d19-a3c5-878ed54dd041)

Conclusion : The output for Household is around 100-200ppm for contaminated it exceeds 2000+



## Usage
1. Connect MQ-2 sensor and Bluetooth module to STM32 as per wiring diagram.
2. Calibrate RO in clean air (take average ADC reading and compute RO).
3. Compile and flash the project using STM32CubeIDE.
4. Open Bluetooth terminal or app to view real-time gas concentrations.

## License
MIT License
