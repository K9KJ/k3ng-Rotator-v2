#include "../upstream/k3ng_rotator_controller/encoder_delta.h"

// Compile with avr-g++ -Os -c. A failing check leaves a call to this function.
extern void encoder_delta_failed() __attribute__((error("Incorrect encoder delta")));

void verify_encoder_delta() {
  int32_t previous = 100;
  if (consume_encoder_delta(104, previous) != 4 ||
      consume_encoder_delta(104, previous) != 0 ||
      consume_encoder_delta(101, previous) != -3 || previous != 101) {
    encoder_delta_failed();
  }

  previous = INT32_MAX;
  if (consume_encoder_delta(INT32_MIN, previous) != 1 ||
      consume_encoder_delta(INT32_MAX, previous) != -1) {
    encoder_delta_failed();
  }
}
