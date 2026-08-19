# Task 1 - Part 1: 4 DC Motors Control with L293D

## Overview
Control 4 DC motors using two L293D motor driver ICs on an Arduino Uno, simulated in Tinkercad.

## Components
- Arduino Uno
- 2x L293D Motor Driver IC
- 4x DC Motor
- 9V battery (external power for motors)
- Breadboard + jumper wires

## Wiring Summary

**L293D #1** (Motors 1 & 2)
| Signal | Arduino Pin |
|--------|-------------|
| EN1    | D5 (PWM)    |
| IN1    | D2          |
| IN2    | D3          |
| EN2    | D6 (PWM)    |
| IN3    | D4          |
| IN4    | D7          |

**L293D #2** (Motors 3 & 4)
| Signal | Arduino Pin |
|--------|-------------|
| EN3    | D9 (PWM)    |
| IN5    | D8          |
| IN6    | D10         |
| EN4    | D11 (PWM)   |
| IN7    | D12         |
| IN8    | D13         |

**Power**
- VCC1 (logic, pin 16) on both L293D → Arduino 5V
- VCC2 (motor power, pin 8) on both L293D → 9V battery (+)
- GND: Arduino GND, both L293D GND pins, and battery (−) all connected to a common ground rail

## Behavior
1. Forward — all 4 motors for 30 seconds
2. Backward — all 4 motors for 60 seconds
3. Alternating right/left turns for 60 seconds (direction switches every 5s)
4. Motors stop automatically after the sequence completes

## Files
- `four_dc_motors_L293D_v2.ino` — Arduino sketch

## Upload to GitHub
```bash
git init
git add four_dc_motors_L293D_v2.ino README.md
git commit -m "Task 1: 4 DC motors control with L293D"
git branch -M main
git remote add origin https://github.com/<username>/<repo-name>.git
git push -u origin main
```
