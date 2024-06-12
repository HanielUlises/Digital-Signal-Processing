#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define SIGNAL_LEN 320
#define IMP_RSP_LEN 29

extern double InputSignal_f32_1kHz_15kHz [SIGNAL_LEN];
extern double Impulse_response [IMP_RSP_LEN];

void writeFile();
void convolution(double *sig_src_arr, double *sig_dest_arr, double *imp_resp_arr, int sig_src_len, int imp_resp_len);