#include "utils.h"

void writeFile(){
    FILE *input_sig_fptr, *imp_rsp_fptr;

    input_sig_fptr = fopen("input_signal.dat", "w");
    imp_rsp_fptr = fopen("impulse_response.dat", "w");

    for(size_t i = 0; i < SIGNAL_LEN; i++){
        fprintf(input_sig_fptr, "\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }

    fclose(input_sig_fptr);

    for(size_t i = 0; i < IMP_RSP_LEN; i++){
        fprintf(imp_rsp_fptr,"\n%f", Impulse_response[i]);
    }

    fclose(input_sig_fptr);
}

void convolution(double *sig_src_arr, double *sig_dest_arr, double *imp_resp_arr, int sig_src_len, int imp_resp_len){
    for(int i = 0; i < sig_src_len + imp_resp_len; i++){
        sig_dest_arr[i] = 0;
    }

    for(int i = 0; i < sig_src_len; i++){
        for(int j = 0; j < imp_resp_len; j++){
            sig_dest_arr[i + j] = sig_dest_arr[i + j] + sig_src_arr[i] * imp_resp_arr[j];
        }
    }
}