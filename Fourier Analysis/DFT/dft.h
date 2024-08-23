#include "../utils.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_length);
void get_dft_output_mag(double *sig_dest_mag_arr, double *sig_src_rex_arr, double *sig_src_imx_arr, int sig_length);