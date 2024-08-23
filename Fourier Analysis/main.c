#include "DFT/dft.h"
#include "IDFT/idft.h"

int main()
{
    FILE *fptr, *fptr2, *fptr3, *fptr4, *fptr5;

    // Compute the DFT of the input signal
    calc_sig_dft(InputSignal_f32_1kHz_15kHz, Output_REX, Output_IMX, SIG_LENGTH);

    // Calculate the magnitude of the DFT output
    get_dft_output_mag(Output_MAG, Output_REX, Output_IMX, SIG_LENGTH);

    // Compute the IDFT of the DFT output
    sig_calc_idft(Output_IDFT, Output_REX, Output_IMX, SIG_LENGTH);

    // Open files to write the results
    fptr = fopen("input_signal.dat", "w");
    fptr2 = fopen("output_rex.dat", "w");
    fptr3 = fopen("output_imx.dat", "w");
    fptr4 = fopen("output_mag.dat", "w");
    fptr5 = fopen("output_idft.dat", "w");

    if (fptr == NULL || fptr2 == NULL || fptr3 == NULL || fptr4 == NULL || fptr5 == NULL) {
        perror("Error opening file for writing");
        return -1;
    }

    for (int i = 0; i < SIG_LENGTH; i++) {
        fprintf(fptr, "%f\n", InputSignal_f32_1kHz_15kHz[i]);
    }

    for (int i = 0; i < SIG_LENGTH/2; i++) {
        fprintf(fptr2, "%f\n", Output_REX[i]);
        fprintf(fptr3, "%f\n", Output_IMX[i]);
        fprintf(fptr4, "%f\n", Output_MAG[i]);
    }

    for (int i = 0; i < SIG_LENGTH; i++) {
        fprintf(fptr5, "%f\n", Output_IDFT[i]);
    }

    fclose(fptr);
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr4);
    fclose(fptr5);

    return 0;
}
