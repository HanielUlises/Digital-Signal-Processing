#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

#define SIGNAL_LEN 320
#define IMP_RSP_LEN 29

extern double InputSignal_f32_1kHz_15kHz [SIGNAL_LEN];

double output_REX[SIGNAL_LEN/2];
double output_IMX[SIGNAL_LEN/2];

void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_length);