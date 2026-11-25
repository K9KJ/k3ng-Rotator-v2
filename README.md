# K3NG Rotator V2

This repository contains the controller PCB design and ATmega2560 firmware used with the azimuth/elevation rotator from **W2HRO and his company, Sub-lunar Systems**. The physical rotator is unmodified. The PCB design is the [**brokebit K3NG Rotator V2**] (https://github.com/brokebit/k3ng-Rotator-v2), and the firmware is a K9KJ fork of the [K3NG Rotator Controller](https://github.com/k3ng/k3ng_rotator_controller) firmware.

## Firmware

The complete upstream source and bundled libraries were imported as a Git subtree at revision `3788ad5f6ef5f3b035c304bbec40a3f8782bb3d9`. See [firmware provenance](firmware/UPSTREAM.md) and the [upstream GPLv3 license](firmware/upstream/LICENSE).

The board-specific changes include:

- Arduino Mega 2560 pin assignments for the motor drivers, manual controls, and parallel 20×4 LCD.
- PJRC quadrature decoding for both Taiss E38S6-600-24G encoders, which are driven after the 60:1 reducers. The configured starting scale is 0.15° per count, assuming 1:1 coupling to the output shafts.
- Corrections to the motor and encoder direction mappings for this setup. The elevation decoder also stores the last count after applying each change so it cannot repeatedly apply the same delta.
- GS-232B serial control at 9600 baud, manual clock support, and Sun and Moon tracking.
- A four-line LCD layout with motion status on line 1, live azimuth on line 2, live elevation on line 3, and the clock plus Moon azimuth and signed elevation on line 4. Moon coordinates use the controller's time and station location.

Build from the repository root with PlatformIO:

```sh
pio run -d firmware
```

See the [hardware and bench notes](docs/HARDWARE.md) for the original hardware baseline.

## PCB design

![Schematic](https://github.com/brokebit/k3ng-Rotator-v2/blob/main/schematic.png?raw=true)
![3D Render](https://github.com/brokebit/k3ng-Rotator-v2/blob/main/k3ng-Rotator-v2.png?raw=true)

## LCD2004 Connection
**LCD Pin -> Rotator Pin**
1. 1 (GND) -> GND
2. 2 (VCC) -> +5V
3. 3 (Contrast) -> Center Pin (2) of Contrast Potentiometer
4. 4 (Register Select) -> LCD_RST
5. 5 (Read/Write) -> GND
6. 6 (Enable) -> LCD_EN
7. 7 (Data 0) -> NC
8. 8 (Data 1) -> NC
9. 9 (Data 2) -> NC
10. 10 (Data 3) -> NC
11. 11 (Data 4) -> LCD_D4
12. 12 (Data 5) -> LCD_D5
13. 13 (Data 6) -> LCD_D6
14. 14 (Data 7) -> LCD_D7
15. 15 (Backlight +) -> +5V + Contrast Potentiometer Pin 1
16. 16 (Backlight -) -> GND + Contrast Potentiometer Pin 3
