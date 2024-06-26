#include "frandom.h"

uint64_t get_fast_random_value(SMathRandomState *state) {
  state->v = (state->seed + 73) * (state->v & 0xFFFFFFFF) + (state->v >> 32);
  state->u = (state->seed + 29) * (state->u & 0xFFFFFFFF) + (state->u >> 32);
  if (state->u == 0 || state->v == 0) {
    state->u = 37;
    state->v = 631;
  }
  return (state->v << 32) + (state->u & 0xFFFFFFFF);
}
uint64_t get_fast_random_value_in_range(SMathRandomState *state, int64_t min,
                                        int64_t max) {

  return min + (get_fast_random_value(state) % (max - min + 1));
}
uint64_t random(SMathRandomState *state) {
  return get_fast_random_value(state);
}
uint64_t random_range(SMathRandomState *state, int64_t min, int64_t max) {
  return get_fast_random_value_in_range(state, min, max);
}