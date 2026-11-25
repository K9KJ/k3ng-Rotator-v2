#pragma once

#include <stdint.h>

inline int32_t consume_encoder_delta(int32_t current, int32_t &previous) {
  // Subtract modulo 2^32 so crossing the hardware counter boundary is one step.
  const int32_t delta = static_cast<uint32_t>(current) - static_cast<uint32_t>(previous);
  previous = current;
  return delta;
}
