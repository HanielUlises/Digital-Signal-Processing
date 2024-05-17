#include <stdio.h>
#include <stdlib.h>

#include "signal_operations.h"
#include "tests.h"

int main() {
    double mean = 0.0;
    double var = 0.0;
    double std = 0.0;
    double rms = 0.0;
    double energy = 0.0;
    double power = 0.0;
    double max_val = 0.0;
    double min_val = 0.0;
    double median = 0.0;
    double skewness = 0.0;
    double kurtosis = 0.0;

    printf("======================================\n");
    printf("\tSignal computations\n");
    printf("======================================\n");

    compute_mean(&mean);
    compute_variance(mean, &var);
    compute_deviation(var, &std);
    compute_rms(&rms);
    compute_energy(&energy);
    compute_power(&power);
    compute_max(&max_val);
    compute_min(&min_val);
    compute_median(&median);
    compute_skewness(mean, &skewness);
    compute_kurtosis(mean, &kurtosis);

    return 0;
}
