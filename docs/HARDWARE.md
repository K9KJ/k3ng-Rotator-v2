# K9KJ Rotator V2 hardware baseline

This station uses the unmodified W2HRO / Sub-lunar Systems rotator and the brokebit K3NG Rotator V2 controller PCB with an Arduino Mega 2560. The last firmware confirmed on this controller was [da77630](https://github.com/K9KJ/k3ng-Rotator-v2/commit/da77630e2a7662d96d0f577b4e4f02869687f63a). The operator confirmed the 20×4 LCD showed the clock and Moon coordinates together on line 4.

## Wiring and configuration

| Function | PCB connection | Mega pin or firmware setting |
|---|---|---|
| Azimuth encoder A / B | J2-04 / J2-05 | D18 / D19. The PJRC decoder takes D19 first, then D18. |
| Elevation encoder A / B | J2-09 / J2-08 | D2 / D3. The PJRC decoder takes D2 first, then D3. |
| Azimuth motor commands | CW / CCW | D6 / D7 |
| Elevation motor commands | Up / Down | D9 / D8 |
| Manual buttons | CW / CCW / Up / Down | A0 / A1 / A2 / A3 |
| 20×4 parallel LCD | RS / Enable / data D4–D7 | D41 / D39 / D43, D45, D47, D49 |
| Serial control | GS-232B over USB | 9600 baud |

Both Taiss E38S6-600-24G encoders are driven after the 60:1 reducers. At 600 pulses per encoder revolution and 4× decoding, the configured 0.15° per count assumes one encoder turn per output-shaft turn. Confirm scale and direction on each axis against a known physical displacement.

The firmware initializes azimuth travel to 450° starting at 0°. Mechanical travel and end stops still need verification. Elevation feedback is clamped at 0–180°. The bench-tested build has manual elevation motor limits disabled, so a 0° display reading can coexist with a running motor.

The firmware supports manual UTC entry and Sun/Moon tracking. Moon coordinates depend on the configured time and station location. Outdoor GPS testing was deferred.

## Build and bench verification

From the repository root, run `pio run -d firmware` to compile the ATmega2560 image and check encoder count deltas for forward motion, repeated stationary counts, reverse motion, and rollover. GitHub Actions uses the same command. For bench checks, establish the physical reference, verify motor and encoder direction, and measure travel before enabling tracking.
