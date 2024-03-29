# Arduino-ContinuousFlowRailer

Arduino Temperature Control for Apple Juice Preservation

## Project Description

This project involves building an Arduino-based system to regulate the temperature of an apple juice pump to 80°C to preserve the juice for a longer period. The system will include a temperature sensor, a pump, and an Arduino board to control the pump's speed based on the temperature reading.

The project will begin by wiring the temperature sensor to the Arduino board and the pump. The temperature sensor will be placed in the apple juice container to measure the temperature of the juice. The pump will be used to circulate the juice in the container and ensure that the temperature is consistent throughout.

Next, the Arduino board will be programmed to read the temperature sensor and control the speed of the pump accordingly. When the temperature of the juice falls below 80°C, the Arduino board will increase the speed of the pump to heat the juice. When the temperature of the juice reaches 80°C, the Arduino board will reduce the speed of the pump to maintain the temperature.

The project will require knowledge of Arduino programming, electronics, and temperature sensing. The goal of this project is to create a system that effectively regulates the temperature of the apple juice to 80°C, thereby preserving the juice for a longer period and reducing waste.


## Hardware

- Arduino (any type works)
- Dimmer Module
- 7x Resistor for LED
- 5x Pull-Down Resistor 10 KOhm
- 2x Switch
- 1x Pushbutton
- 3x Pote 1 KOhm
- 4x LED green
- 2x LED red
- 1x LED blue

##  Connection Diagram
<img src="https://github.com/MIRIPP/Arduino-ContinuousFlowControl/blob/main/Doc/Connection%20Diagram.png?raw=true"/>

### Triac
<img src="https://github.com/MIRIPP/Arduino-ContinuousFlowControl/blob/main/Doc/Connection%20Diagram%20Triac.JPG?raw=true" height=150 />

## Getting Started
1. Wire the Hardware
2. Upload the Arduino Software
3. Use the start switch to run the flwo control
