#include "dft.h"

void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_length){
    // Destination arrays
    for(size_t j = 0; j < sig_length/2; j++){
        sig_dest_rex_arr[j] = 0;
        sig_dest_imx_arr[j] = 0;
    }

    // Discrete Fourier Transform for each frequency k
    for(size_t k = 0; k < sig_length/2; k++){
        // For each frequency bin, we sum up the contributions from each time sample
        for(size_t i = 0; i < sig_length; i++){
            // Real part
            sig_dest_rex_arr[k] = sig_dest_rex_arr[k] + sig_src_arr[i] * cos(2 * M_PI * k * i / sig_length);
            // Imaginary part
            sig_dest_imx_arr[k] = sig_dest_imx_arr[k] - sig_src_arr[i] * sin(2 * M_PI * k * i / sig_length);
        }
    }
}