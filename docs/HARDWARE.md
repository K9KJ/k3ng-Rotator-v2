# K9KJ Rotator V2 hardware baseline

Based on the brokebit K3NG Rotator V2 PCB in this repository.

| Item | Baseline |
|---|---|
| MCU | ATmega2560 |
| Azimuth feedback | Rotary encoder; exact mode, pins and scaling unverified |
| Elevation feedback | Rotary encoder; exact mode, pins and scaling unverified |
| Azimuth travel | 450 degrees |
| Azimuth start | Proposed 0 degrees; verify mechanical limit |
| Serial protocol | GS-232B |
| Clock | Manual UTC required for bench testing |
| GPS | Outdoor testing deferred |
| Moon/Sun tracking | Required for new baseline |

## Existing firmware observations
Installed firmware reports 2025.08.07.6900; original source is unavailable. Debug showed AZ 8, raw AZ 368, Start -7, EL 359, both offsets zero. Setting azimuth to 180 did not change readings. GPS received characters but no valid sentences. Do not assume the new firmware matches the installed build.

## Before flashing
Verify schematic pin assignments, encoder interface and scaling, motor output polarity, mechanical travel limits, EEPROM compatibility and display wiring. Preserve installed firmware/EEPROM if readable. Compile for ATmega2560 and test with motor power disconnected before enabling movement or tracking.
