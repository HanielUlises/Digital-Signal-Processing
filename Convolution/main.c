#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGNAL_LEN 320
#define IMP_RSP_LEN 29

extern double InputSignal_f32_1kHz_15kHz [SIGNAL_LEN];
extern double Impulse_response [IMP_RSP_LEN];

void writeFile(){
    FILE *input_sig_fptr, *imp_rsp_fptr;

    input_sig_fptr = fopen("input_signal.dat", "w");
    imp_rsp_fptr = fopen("impulse_response.dat", "w");

    for(size_t i = 0; i < SIGNAL_LEN; i++){
        fprintf(input_sig_fptr, "\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }

    fclose(input_sig_fptr);
}

int main (){
    void writeFile();
    return 0;
}