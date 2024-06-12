#include "utils.h"

void convolution(double *sig_src_arr, double *sig_dest_arr, double *imp_resp_arr, int sig_src_len, int imp_resp_len){
    int output_len = sig_src_len + imp_resp_len - 1;

    for(int i = 0; i < output_len; i++){
        sig_dest_arr[i] = 0; 
    }

    for(int i = 0; i < sig_src_len; i++){
        for(int j = 0; j < imp_resp_len; j++){
            sig_dest_arr[i + j] += sig_src_arr[i] * imp_resp_arr[j];
        }
    }
}

void writeFile(){
    FILE *input_sig_fptr, *imp_rsp_fptr, *output_sig_fptr;

    double Output_signal[SIGNAL_LEN+IMP_RSP_LEN];

    input_sig_fptr = fopen("input_signal.dat", "w");
    imp_rsp_fptr = fopen("impulse_response.dat", "w");
    output_sig_fptr = fopen("output_signal.dat", "w");

    if (!input_sig_fptr || !imp_rsp_fptr) {
        if (input_sig_fptr) fclose(input_sig_fptr);
        if (imp_rsp_fptr) fclose(imp_rsp_fptr);
        fprintf(stderr, "Error opening files.\n");
        return;
    }

    convolution((double*) &InputSignal_f32_1kHz_15kHz[0], (double*) &Output_signal[0], (double*) &Impulse_response[0], (int) SIGNAL_LEN, (int) IMP_RSP_LEN);

    for(size_t i = 0; i < SIGNAL_LEN; i++){
        fprintf(input_sig_fptr, "%f\n", InputSignal_f32_1kHz_15kHz[i]); 
    }

    fclose(input_sig_fptr);

    for(size_t i = 0; i < IMP_RSP_LEN; i++){
        fprintf(imp_rsp_fptr, "%f\n", Impulse_response[i]); 
    }

    fclose(imp_rsp_fptr);

    for(size_t i = 0; i < SIGNAL_LEN + IMP_RSP_LEN; i++){
        fprintf(output_sig_fptr, "\n%f", Output_signal[i]);
    }

    fclose(output_sig_fptr);

}
