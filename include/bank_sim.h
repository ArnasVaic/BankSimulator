#ifndef BANK_SIM_H
#define BANK_SIM_H

#include <string.h>
#include <stdlib.h>

#include <input.h>
#include <queue.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

results_t simulate_bank(params_t p);

#endif /* BANK_SIM_H */