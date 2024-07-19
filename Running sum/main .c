#include <stdio.h>
#include <stdlib.h>

extern double InputSignal_f32_1kHz_15kHz[320];

void running_sum(double *sig_src_arr, double *sig_dest_arr, int sig_len);
void process_running_sum();

int main() {
    process_running_sum();
    return 0;
}

void running_sum(double *sig_src_arr, double *sig_dest_arr, int sig_len) {
    sig_dest_arr[0] = sig_src_arr[0];
    for (int i = 1; i < sig_len; i++) {
        sig_dest_arr[i] = sig_src_arr[i] + sig_dest_arr[i - 1];
    }
}

void process_running_sum() {
    double OutputSignal[320];
    FILE *output_sig_fptr;

    running_sum(InputSignal_f32_1kHz_15kHz, OutputSignal, 320);

    output_sig_fptr = fopen("output_signal.dat", "w");
    if (output_sig_fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < 320; i++) {
        fprintf(output_sig_fptr, "%f\n", OutputSignal[i]);
    }
    fclose(output_sig_fptr);
}
