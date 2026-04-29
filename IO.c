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
    FILE *fptr = fopen("results.txt", "w");

    if (fptr == NULL) {
        printf("Unable to create Results File");
        return;
    }
    fprintf("           3 Phase AC waveform Analysis Program - Casper Lamptey"\n);
    fprintf("------------------------------------------------------------------------------\n");



}