//
// Created by clt2-lamptey on 21/04/2026.
//

#include <stdlib.h>
#include <stdio.h>
#include "IO.h"
#include "waveform.h"
Sample *COLLECT(char *CSVFILE) {

    //Variables
    char line [1000];
    int count = 0;

    FILE *fptr = fopen(CSVFILE, "r");

    if (fptr == NULL) {
        printf("The file could not be opened");
        return NULL;
    }

    Sample* data = malloc(64000);
    if (data == NULL) {
        printf("Not enough memory to analyse file");
        fclose(fptr);
        return NULL;
    }

    fgets(line, 1000, fptr);

    while (count < 1000) {

        if (fgets(line, 1000, fptr) == NULL)
            break;

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

    int count = 0;

    FILE *fptr = fopen("results.txt", "w");
    printf("2");

    if (fptr == NULL) {
        printf("Unable to create Results File");
        return;
    }

    fprintf(fptr,"           3 Phase AC waveform Analysis Program - Casper Lamptey\n");
    fprintf(fptr, "------------------------------------------------------------------------------\n");
    for (int i = 0; i < 3; i++) {

        fprintf(fptr, "Calculations for V%c\n", Phase[i].name);
        fprintf(fptr, "RMS : %.12lf      ", Phase[i].RMS);

        if (Phase[i].RMS_Status == 0) fprintf(fptr, "RMS is below the nominal interval.\n");
        if (Phase[i].RMS_Status == 1) fprintf(fptr, "RMS is within the nominal interval.\n");
        if (Phase[i].RMS_Status == 2) fprintf(fptr, "RMS is above the nominal interval.\n");

        fprintf(fptr, "Peak to Peak Value : %.12lf\n", Phase[i].PEAK2PEAK);
        fprintf(fptr, "V%c Voltage Clippings list:\n\n", Phase[i].name);

        for (int n = 0; n < CLIP_COUNT[i]; n ++) {
            fprintf(fptr, "%.12lf     ------->      %.12lf\n", Phase[i].CLIPPINGS[n], Phase[i].CLIPPINGS_TS[n]);
        }

        fprintf(fptr, "Number of Clipping in Phase: %d\n", CLIP_COUNT[i]);
        count = 0;
    }

    fprintf(fptr, "THD average : %.12lf\n", THD_Average);
    fprintf(fptr, "Power Factor Average : %.12lf\n", Pfactor_Average);
    fprintf(fptr, "Frequency Average : %.12lf\n", Frequency_Average);
    fclose(fptr);
    printf("\n1");
}



