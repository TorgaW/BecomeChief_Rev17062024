// #include "common.h"

// #include <stdlib.h>
// #include <stdio.h>

// size_t get_cache_line_size() {
//     size_t line_size = 0;
//     size_t sizeof_line_size = sizeof(line_size);

// #if defined(__APPLE__)
//     int name[2] = {CTL_HW, HW_CACHELINE};
//     sysctl(name, 2, &line_size, &sizeof_line_size, NULL, 0);
// #elif defined(_SC_LEVEL1_DCACHE_LINESIZE)
//     line_size = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
// #elif defined(__linux__)
//     FILE *p = NULL;
//     if ((p = fopen("/sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size", "r")) != NULL) {
//         fscanf(p, "%zu", &line_size);
//         fclose(p);
//     }
// #endif

//     if (line_size == 0) {
//         printf("Unable to determine cache line size\n");
//         exit(1);
//     }

//     return line_size;
// }