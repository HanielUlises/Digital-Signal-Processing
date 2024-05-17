#include "signal_operations.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

// Function to calculate the signal mean
double get_signal_mean(double *sig_src_arr, int sig_length) {
    double mean = 0.0;
    for(int i = 0; i < sig_length; i++) {
        mean += sig_src_arr[i];
    }
    return mean / sig_length;
}

// Function to calculate the signal variance
double get_signal_var(double *sig_src_arr, double sig_mean, int sig_length) {
    double variance = 0.0;
    for(int i = 0; i < sig_length; i++) {
        variance += pow((sig_src_arr[i] - sig_mean), 2);
    }
    return variance / (sig_length - 1);
}

// Function to calculate the signal standard deviation
double get_signal_std(double signal_variance) {
    return sqrt(signal_variance);
}

// Function to calculate the signal RMS (Root Mean Square)
double get_signal_rms(double *sig_src_arr, int sig_length) {
    double rms = 0.0;
    for(int i = 0; i < sig_length; i++) {
        rms += pow(sig_src_arr[i], 2);
    }
    return sqrt(rms / sig_length);
}

// Function to calculate the signal energy
double get_signal_energy(double *sig_src_arr, int sig_length) {
    double energy = 0.0;
    for(int i = 0; i < sig_length; i++) {
        energy += pow(sig_src_arr[i], 2);
    }
    return energy;
}

// Function to calculate the signal power
double get_signal_power(double *sig_src_arr, int sig_length) {
    double energy = get_signal_energy(sig_src_arr, sig_length);
    return energy / sig_length;
}

// Function to find the max value in the signal
double get_signal_max(double *sig_src_arr, int sig_length) {
    double max_val = sig_src_arr[0];
    for(int i = 1; i < sig_length; i++) {
        if(sig_src_arr[i] > max_val) {
            max_val = sig_src_arr[i];
        }
    }
    return max_val;
}

// Function to find the min value in the signal
double get_signal_min(double *sig_src_arr, int sig_length) {
    double min_val = sig_src_arr[0];
    for(int i = 1; i < sig_length; i++) {
        if(sig_src_arr[i] < min_val) {
            min_val = sig_src_arr[i];
        }
    }
    return min_val;
}

// Function to normalize the signal
void normalize_signal(double *sig_src_arr, double *sig_dst_arr, int sig_length) {
    double max_val = get_signal_max(sig_src_arr, sig_length);
    double min_val = get_signal_min(sig_src_arr, sig_length);
    for(int i = 0; i < sig_length; i++) {
        sig_dst_arr[i] = (sig_src_arr[i] - min_val) / (max_val - min_val);
    }
}

// Comparison function for qsort
int cmpfunc(const void *a, const void *b) {
    double diff = (*(double*)a - *(double*)b);
    return (diff > 0) - (diff < 0);
}

// Function to calculate the signal median
double get_signal_median(double *sig_src_arr, int sig_length) {
    double *sorted_arr = (double*)malloc(sig_length * sizeof(double));
    if (sorted_arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(sorted_arr, sig_src_arr, sig_length * sizeof(double));
    qsort(sorted_arr, sig_length, sizeof(double), cmpfunc);
    double median;
    if (sig_length % 2 == 0) {
        median = (sorted_arr[sig_length / 2 - 1] + sorted_arr[sig_length / 2]) / 2;
    } else {
        median = sorted_arr[sig_length / 2];
    }
    free(sorted_arr);
    return median;
}

// Function to calculate the signal skewness
double get_signal_skewness(double *sig_src_arr, double sig_mean, int sig_length) {
    double skewness = 0.0;
    double variance = get_signal_var(sig_src_arr, sig_mean, sig_length);
    for(int i = 0; i < sig_length; i++) {
        skewness += pow((sig_src_arr[i] - sig_mean), 3);
    }
    skewness /= sig_length;
    return skewness / pow(sqrt(variance), 3);
}

// Function to calculate the signal kurtosis
double get_signal_kurtosis(double *sig_src_arr, double sig_mean, int sig_length) {
    double kurtosis = 0.0;
    double variance = get_signal_var(sig_src_arr, sig_mean, sig_length);
    for(int i = 0; i < sig_length; i++) {
        kurtosis += pow((sig_src_arr[i] - sig_mean), 4);
    }
    kurtosis /= sig_length;
    return kurtosis / pow(variance, 2) - 3;
}
