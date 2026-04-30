//
// Created by clt2-lamptey on 21/04/2026.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "IO.h"

char FileName[50];

Calculations Phase[3] = {
        {'a', 1},
        {'b', 1},
        {'c', 1}
};

Sample *COLLECT(char *FileName) {

    //Variables
    char line [1000];
    int count = 0;

    FILE *fptr = fopen(FileName, "r");

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
    printf("1\n");
}

void RESULTS(Calculations *Phase)  {

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
        fprintf(fptr, "RMS : %lf      ", Phase[i].name);

        if (Phase[i].RMS_Status == 0) fprintf(fptr, "RMS is below the nominal interval.\n");
        if (Phase[i].RMS_Status == 1) fprintf(fptr, "RMS is within the nominal interval.\n");
        if (Phase[i].RMS_Status == 2) fprintf(fptr, "RMS is above the nominal interval.\n");

        fprintf(fptr, "Peak to Peak Value : %lf\n", Phase[i].PEAK2PEAK);


        fprintf(fptr, "V%c Voltage Clippings list:\n\n ");

        while (Phase[i].CLIPPINGS != 0) {
            fprintf(fptr, "%lf     ------->      %lf\n", Phase[i].CLIPPINGS, Phase[i].CLIPPINGS_TS);
            count ++;
        }
    }
    fprintf(fptr, "THD average : %lf\n", THD_Average);
    fprintf(fptr, "Power Factor Average : %lf\n", Pfactor_Average);
    fprintf(fptr, "Frequency Average : %lf\n", Frequency_Average);

    fclose(fptr);
}