#include <time.h>

#include <input.h>
#include <bank_sim.h>

int main(int argc, char** argv) {

    srand(time(NULL));

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

    printf("Iterations: %zu\n", params.iterations);
    printf("Cashier cnt: %zu\n", params.cashier_cnt);
    printf("Iterations per client: %zu\n", params.time_per_client);
    printf("Chance of client per iteration: %zu%%\n", params.client_chance);

    simulate_bank(params);

    return 0;
}