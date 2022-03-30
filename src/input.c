#include <input.h>

int parse_args(int argc, char ** argv, char ** filename) {
    if(argc != 2) return INPUT_INVALID_ARG_COUNT;
    *filename = argv[1];
    return INPUT_GOOD;
}

int get_input_params(const char * filename, params_t * params) {
    assert(params != NULL);
    assert(filename != NULL);

    FILE * is = fopen(filename, "rb");

    if(is == NULL) return INPUT_INVALID_FILE_NAME;

    fscanf(is, "%zu", &params->cashier_cnt);
    if(feof(is)) return INPUT_INVALID_FILE;
    fscanf(is, "%lf", &params->time_per_client);
    if(feof(is)) return INPUT_INVALID_FILE;
    fscanf(is, "%lf", &params->client_chance);
    
    fclose(is);

    return INPUT_GOOD;
}

const char * get_error(int error_code) {
    if(error_code != INPUT_GOOD) {
        return "Something went wrong";
    }
    return "";
}