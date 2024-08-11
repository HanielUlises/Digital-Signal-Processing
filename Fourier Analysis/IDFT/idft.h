#include <stdio.h>
#include <math.h>

#define SIG_LENGTH 320
#define M_PI 3.14159265358979323846

extern double InputSignal_f32_1kHz_15kHz [SIG_LENGTH];

extern double Output_REX[SIG_LENGTH/2];
extern double Output_IMX[SIG_LENGTH/2];
extern double Output_MAG[SIG_LENGTH/2];

void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_length);
void get_dft_output_mag(double *sig_dest_mag_arr);
void sig_calc_idft(double *idft_out_arr, double *sig_src_rex_arr, double *sig_src_imx_arr, int idft_length);