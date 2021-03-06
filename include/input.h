#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>
#include <assert.h>
#include <stdio.h>

enum input_error_codes {
    INPUT_GOOD,
    INPUT_INVALID_ARG_COUNT,
    INPUT_INVALID_FILE_NAME,
    INPUT_INVALID_FILE
};

typedef struct params_t {
    size_t iterations;
    size_t cashier_cnt;
    size_t time_per_client;
    size_t client_chance;
} params_t;

typedef struct results_t {
    size_t min_wait_time;
    size_t max_wait_time;
    size_t max_queue_length;
    size_t avg_cashier_busyness;
} results_t;

/// Parse command line arguments
/// @param argc arg count (in)
/// @param argv arg values (in)
/// @param filename filename where input parameters are stored (out)
/// @return error code
int parse_args(int argc, char ** argv, char ** filename);

/// Reads input parameters from a file
/// @param filename file where input parameters are stored (in)
/// @param params extracted parameters (out)
/// @return error code
int get_input_params(const char * filename, params_t *params);

/// Retrieve error message
/// @param error_code code of the error
/// @return message string
const char * get_error(int error_code);

#endif /* INPUT_H */