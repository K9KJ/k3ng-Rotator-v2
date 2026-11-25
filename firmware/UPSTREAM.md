# Firmware source provenance

Upstream: https://github.com/k3ng/k3ng_rotator_controller

Selected source revision: `3788ad5f6ef5f3b035c304bbec40a3f8782bb3d9`.

Status: source import pending. This revision is a development reference, not a verified match for the installed firmware. Import the complete upstream tree under firmware/upstream, including original licenses, attribution and bundled libraries. Keep board-specific configuration changes identifiable in subsequent commits. Verify dependencies and compile before flashing.

A maintainer with Git installed can import the pinned revision from the repository root on the firmware-integration branch:

```sh
git remote add k3ng https://github.com/k3ng/k3ng_rotator_controller.git
git fetch k3ng master
git subtree add --prefix=firmware/upstream 3788ad5f6ef5f3b035c304bbec40a3f8782bb3d9
```

Do not flash the upstream defaults on the custom PCB before validating pin mapping and output polarity.
