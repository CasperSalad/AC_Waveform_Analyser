//
// Created by clt2-lamptey on 21/04/2026.
//

#include <stdlib.h>
#include <stdio.h>
#include "IO.h"
Sample *COLLECT(char *CSVFILE) {

    // Local Variables:
    char line [1000];      //Buffer for f(gets)
    int count = 0;

    FILE *fptr = fopen(CSVFILE, "r");

    //error message if file is not opened, also ends entire program:
    if (fptr == NULL) {
        printf("The file could not be opened, reason could include:\n-Incorrect file name\n-invalid or missing data");
        exit(1);
    }

    Sample* data = malloc(64000);   //Alocating memory to data array

    //error message if not enough memory, also ends entire program:
    if (data == NULL) {
        printf("Not enough memory to analyse file");
        fclose(fptr);
        exit(1);
    }

    fgets(line, 1000, fptr);            //parses header row

    while (count < 1000) {

        fgets(line, 1000, fptr);

        sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
        &data[count].timestamp,
        &data[count].Va,
        &data[count].Vb,
        &data[count].Vc,
        &data[count].current,
        &data[count].frequency,
        &data[count].pFactor,
        &data[count].THD
        );
        count++;
    }

    fclose(fptr);

    return data;
}

void RESULTS(Calculations Phase[3])  {

    FILE *fptr = fopen("results.txt", "w");

    if (fptr == NULL) {
        printf("Unable to create Results File");
        exit(1);
    }

    fprintf(fptr,"           3 Phase AC waveform Analysis Program - Casper Lamptey\n");
    fprintf(fptr, "------------------------------------------------------------------------------\n\n");
    for (int i = 0; i < 3; i++) {

        fprintf(fptr, "Calculations for V%c :\n------------------------------------\n\n", Phase[i].name);
        fprintf(fptr, "RMS : %.12lf\n\n", Phase[i].RMS);

        if (Phase[i].RMS_Status == 0) fprintf(fptr, "RMS is below the nominal interval.\n\n");
        if (Phase[i].RMS_Status == 1) fprintf(fptr, "RMS is within the nominal interval.\n\n");
        if (Phase[i].RMS_Status == 2) fprintf(fptr, "RMS is above the nominal interval.\n\n");

        fprintf(fptr, "DC Offset : %.12lf\n", Phase[i].MEAN);
        fprintf(fptr, "Peak to Peak Value : %.12lf\n\n", Phase[i].PEAK2PEAK);
        fprintf(fptr, "V%c Voltage Clippings list:\n\n", Phase[i].name);

        for (int n = 0; n < CLIP_COUNT[i]; n ++) {
            fprintf(fptr, "%.12lf     ------->      %.12lf\n", Phase[i].CLIPPINGS[n], Phase[i].CLIPPINGS_TS[n]);
        }

        fprintf(fptr, "Number of Clipping in Phase: %d\n\n", CLIP_COUNT[i]);
    }

    fprintf(fptr, "THD average : %.12lf\n", THD_Average);
    fprintf(fptr, "Power Factor Average : %.12lf\n", Pfactor_Average);
    fprintf(fptr, "Frequency Average : %.12lf\n", Frequency_Average);
    fclose(fptr);

}



