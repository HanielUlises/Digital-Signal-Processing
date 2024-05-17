#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include "signal_operations.h"

#define SIGNAL_LEN 320

extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LEN];

// Compute functions
void compute_mean(double *_mean) {
    double mean = get_signal_mean(InputSignal_f32_1kHz_15kHz, SIGNAL_LEN);
    printf("Mean: %f\n", mean);
    *_mean = mean;
}

void compute_variance(double mean, double *_var) {
    double var = get_signal_var(InputSignal_f32_1kHz_15kHz, mean, SIGNAL_LEN);
    printf("Variance: %f\n", var);
    *_var = var;
}

void compute_deviation(double var, double *std) {
    *std = get_signal_std(var);
    printf("Standard deviation: %f\n", *std);
}

void compute_rms(double *rms) {
    *rms = get_signal_rms(InputSignal_f32_1kHz_15kHz, SIGNAL_LEN);
    printf("RMS: %f\n", *rms);
}

void compute_energy(double *energy) {
    *energy = get_signal_energy(InputSignal_f32_1kHz_15kHz, SIGNAL_LEN);
    printf("Energy: %f\n", *energy);
}

void compute_power(double *power) {
    *power = get_signal_power(InputSignal_f32_1kHz_15kHz, SIGNAL_LEN);
    printf("Power: %f\n", *power);
}

void compute_max(double *max_val) {
    *max_val = get_signal_max(InputSignal_f32_1kHz_15kHz, SIGNAL_LEN);
    printf("Max value: %f\n", *max_val);
}

void compute_min(double *min_val) {
    *min_val = get_signal_min(InputSignal_f32_1kHz_15kHz, SIGNAL_LEN);
    printf("Min value: %f\n", *min_val);
}

void compute_median(double *median) {
    *median = get_signal_median(InputSignal_f32_1kHz_15kHz, SIGNAL_LEN);
    printf("Median: %f\n", *median);
}

void compute_skewness(double mean, double *skewness) {
    *skewness = get_signal_skewness(InputSignal_f32_1kHz_15kHz, mean, SIGNAL_LEN);
    printf("Skewness: %f\n", *skewness);
}

void compute_kurtosis(double mean, double *kurtosis) {
    *kurtosis = get_signal_kurtosis(InputSignal_f32_1kHz_15kHz, mean, SIGNAL_LEN);
    printf("Kurtosis: %f\n", *kurtosis);
}

#endif // TEST_H
