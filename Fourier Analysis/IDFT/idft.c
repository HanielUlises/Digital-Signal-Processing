#include "idft.h"

#include <stdio.h>
#include <math.h>

void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_length)
{
    int i, j, k;
    double PI = 3.14159265359;

    for(j = 0; j < sig_length / 2; j++) {
        sig_dest_rex_arr[j] = 0;
        sig_dest_imx_arr[j] = 0;
    }

    for(k = 0; k < (sig_length / 2); k++) {
        for(i = 0; i < sig_length; i++) {
            sig_dest_rex_arr[k] += sig_src_arr[i] * cos(2 * PI * k * i / sig_length);
            sig_dest_imx_arr[k] -= sig_src_arr[i] * sin(2 * PI * k * i / sig_length);
        }
    }
}

void get_dft_output_mag(double *sig_dest_mag_arr)
{
    int k;
    for(k = 0; k < SIG_LENGTH / 2; k++) {
        sig_dest_mag_arr[k] = sqrt(pow(Output_REX[k], 2) + pow(Output_IMX[k], 2));
    }
}

void sig_calc_idft(double *idft_out_arr, double *sig_src_rex_arr, double *sig_src_imx_arr, int idft_length)
{
    double PI = 3.14159265359;
    int i, k;

    for(k = 0; k < idft_length / 2; k++) {
        sig_src_rex_arr[k] /= (idft_length / 2);
        sig_src_imx_arr[k] = -sig_src_imx_arr[k] / (idft_length / 2);
    }

    sig_src_rex_arr[0] /= 2;
    sig_src_imx_arr[0] = -sig_src_imx_arr[0] / 2;

    for(i = 0; i < idft_length; i++) {
        idft_out_arr[i] = 0;
    }

    for(k = 0; k < idft_length / 2; k++) {
        for(i = 0; i < idft_length; i++) {
            idft_out_arr[i] += sig_src_rex_arr[k] * cos(2 * PI * k * i / idft_length);
            idft_out_arr[i] += sig_src_imx_arr[k] * sin(2 * PI * k * i / idft_length);
        }
    }
}
