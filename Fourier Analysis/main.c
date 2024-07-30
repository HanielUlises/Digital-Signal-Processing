#include "dft.h"

int main (){
    calc_sig_dft(InputSignal_f32_1kHz_15kHz, output_REX, output_IMX, SIGNAL_LEN);

    FILE *fout = fopen("dft_output.dat", "w");
    if (fout == NULL) {
        perror("Error opening file for writing");
        return -1;
    }

    fprintf(fout, "Frequency Bin, Real Part, Imaginary Part, Magnitude\n");

    for (size_t i = 0; i < SIGNAL_LEN/2; i++) {
        double magnitude = sqrt(output_REX[i] * output_REX[i] + output_IMX[i] * output_IMX[i]);
        fprintf(fout, "%zu, %f, %f, %f\n", i, output_REX[i], output_IMX[i], magnitude);
    }

    fclose(fout);
    return 0;
}
