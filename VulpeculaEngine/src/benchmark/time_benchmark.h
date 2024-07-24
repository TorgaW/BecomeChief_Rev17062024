#ifndef TIME_BENCHMARK
#define TIME_BENCHMARK

#define BC_START_BENCHMARK                                                     \
  uint64_t bc_benchmark_macro_start_time = SDL_GetPerformanceCounter();        \
  uint64_t bc_benchmark_macro_frequency = SDL_GetPerformanceFrequency();

#define BC_STOP_BENCHMARK                                                      \
  uint64_t bc_benchmark_macro_end_time = SDL_GetPerformanceCounter();          \
  uint64_t bc_benchmark_macro_elapsed_time_value =                             \
      bc_benchmark_macro_end_time - bc_benchmark_macro_start_time;

#define BC_PRINT_RESULTS_BENCHMARK                                             \
  printf("[BC_BENCHMARK] Time: %.2f ns; %.2f us; %.2f ms;\n",                  \
         (double)(bc_benchmark_macro_elapsed_time_value) * 1000000000.0 /      \
             (double)bc_benchmark_macro_frequency,                             \
         (double)(bc_benchmark_macro_elapsed_time_value) * 1000000.0 /         \
             (double)bc_benchmark_macro_frequency,                             \
         (double)(bc_benchmark_macro_elapsed_time_value) * 1000.0 /            \
             (double)bc_benchmark_macro_frequency);

#endif /* TIME_BENCHMARK */
