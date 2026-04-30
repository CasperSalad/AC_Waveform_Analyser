//
// Created by clt2-lamptey on 21/04/2026.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

    fgets(line, 100, fptr);

    printf("1\n");
    while (count <= 999) {

        fgets(line, 100, fptr );

        sscanf(line, "%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf",
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

void RESULTS(char *File_Name, phase[3])  {

    int count = 0;

    FILE *fptr = fopen("results.txt", "w");

    if (fptr == NULL) {
        printf("Unable to create Results File");
        return;
    }
    fprintf("           3 Phase AC waveform Analysis Program - Casper Lamptey"\n);
    fprintf("------------------------------------------------------------------------------\n");
    for (int i = 0; i < 3; i++) {

        fprintf("Calculations for V%c\n", Phase[i].name);
        fprintf("RMS : %lf      ", Phase[i].name);

        if (Phase[i].RMS_Status == 0) fprintf("RMS is below the nominal interval.\n");
        if (Phase[i].RMS_Status == 1) fprintf("RMS is within the nominal interval.\n");
        if (Phase[i].RMS_Status == 2) fprintf("RMS is above the nominal interval.\n");

        fprintf("Peak to Peak Value : %lf\n", Phase[i].PEAK2PEAK);


        fprintf("V%c Voltage Clippings list:\n\n ")

        while (Phase[i].CLIPPINGS != 0) {
            fprintf("%lf     ------->      %lf\n", Phase[i].CLIPPINGS, Phase[i].CLIPPINGS_TS);
            count ++;
        }
    }











}