#ifndef SIGNAL_OPERATIONS_H
#define SIGNAL_OPERATIONS_H

// Function to calculate the signal mean 
double get_signal_mean(double *sig_src_arr, int sig_length);
// Function to calculate the signal variance
double get_signal_var(double *sig_src_arr, double sig_mean, int sig_length);
// Function to calculate the signal standard deviation
double get_signal_std(double signal_variance);
// Function to calculate the signal RMS (Root Mean Square)
double get_signal_rms(double *sig_src_arr, int sig_length);
// Function to calculate the signal energy
double get_signal_energy(double *sig_src_arr, int sig_length);
// Function to calculate the signal power
double get_signal_power(double *sig_src_arr, int sig_length);
// Function to find the max value in the signal
double get_signal_max(double *sig_src_arr, int sig_length);
// Function to find the min value in the signal
double get_signal_min(double *sig_src_arr, int sig_length);
// Function to normalize the signal
void normalize_signal(double *sig_src_arr, double *sig_dst_arr, int sig_length);
// Function to calculate the signal median
double get_signal_median(double *sig_src_arr, int sig_length);
// Function to calculate the signal skewness
double get_signal_skewness(double *sig_src_arr, double sig_mean, int sig_length);
// Function to calculate the signal kurtosis
double get_signal_kurtosis(double *sig_src_arr, double sig_mean, int sig_length);

#endif // SIGNAL_OPERATIONS_H
