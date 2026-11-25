# Firmware source provenance

- Upstream repository and local remote `k3ng` — https://github.com/k3ng/k3ng_rotator_controller
- Imported revision — `3788ad5f6ef5f3b035c304bbec40a3f8782bb3d9` (2023-10-06)
- Subtree location — [`firmware/upstream`](upstream/)
- Subtree import commit — `a9fe3b3abce6d16022fe1894c26cd0ba1b77f923`

The full upstream tree was imported with its Git history. At the import commit, the subtree tree ID matches the root tree ID of the pinned revision, covering all 122 tracked files, including the [controller source](upstream/k3ng_rotator_controller/), [bundled libraries](upstream/libraries/), original attribution, and [GNU GPL version 3 license](upstream/LICENSE).

The target hardware is the brokebit K3NG Rotator V2 PCB with an ATmega2560 and rotary encoders for azimuth and elevation. This revision serves as the development baseline. The board-specific changes on this branch were compiled and flashed to the ATmega2560. Build from the repository root with `pio run -d firmware`. The flashed configuration uses a 20×4 parallel LCD and Taiss A/B encoders on both axes. Encoder scaling and direction remain provisional pending bench verification.

To verify the imported tree, compare the two IDs printed from the repository root:

```sh
git rev-parse a9fe3b3abce6d16022fe1894c26cd0ba1b77f923:firmware/upstream
git rev-parse '3788ad5f6ef5f3b035c304bbec40a3f8782bb3d9^{tree}'
```
