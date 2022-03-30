#include <input.h>
// started at 10:20
int main(int argc, char** argv) {

    if(argc == 1) {
        printf("Usage: %s filename\n", argv[0]);
        return 0;
    }

    char *filename; 
    int c0 = parse_args(argc, argv, &filename);
    printf("%s", get_error(c0));

    params_t params; 
    int c1 = get_input_params(filename, &params);
    printf("%s", get_error(c1));

    printf("%s\n", filename);
    printf("%zu\n%f\n%f\n", params.cashier_cnt, params.time_per_client, params.client_chance);
    return 0;
}