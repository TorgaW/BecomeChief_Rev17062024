#ifndef FRANDOM
#define FRANDOM

/**
 * @file frandom.h
 * @brief 64 bit random function based on MWC algorithm
 */

#include <stdint.h>

// max seed IS NOT 0xFFFFFFFF it is 0xFFFFFFFF - 73. see implementation of
// get_fast_random_value function!
typedef struct SMathRandomState {
  uint64_t u;
  uint64_t v;
  uint32_t seed;
} SMathRandomState;

uint64_t get_fast_random_value(SMathRandomState *state);
uint64_t get_fast_random_value_in_range(SMathRandomState *state, int64_t min,
                                        int64_t max);

//just QoL simplified call for function get_fast_random_value
uint64_t random(SMathRandomState *state);
//just QoL simplified call for function get_fast_random_value_in_range
uint64_t random_range(SMathRandomState *state, int64_t min,
                                        int64_t max);

#endif /* FRANDOM */
