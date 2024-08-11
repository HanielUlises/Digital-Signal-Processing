#include "../utils.h"

#include <stdio.h>
#include <math.h>

void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_length);
void get_dft_output_mag(double *sig_dest_mag_arr);
void sig_calc_idft(double *idft_out_arr, double *sig_src_rex_arr, double *sig_src_imx_arr, int idft_length);