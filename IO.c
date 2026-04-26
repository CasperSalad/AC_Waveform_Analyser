//
// Created by clt2-lamptey on 21/04/2026.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "waveform.h"
Sample *COLLECT(char *CSVFILE) {

    //Variables
    char line [1001];
    int count = 0;
    char* string;
    char s;
    char header_checker = "f";



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

    while (fgets(line, sizeof(line), fptr)) {

        sscanf(line,"%c", &s);
        if (strstr(s, header_checker) != NULL) {
            fgets(line, 100, fptr);
            count = 0;
            while (fgets(line, sizeof(line), fptr)) {

                sscanf(line, "%lf, %lf, %lf",
                       &data[count].frequency,
                       &data[count].pFactor,
                       &data[count].THD);
                count++;
            }
            fclose(fptr);
        }

        sscanf(line, "%lf, %lf, %lf, %lf, %lf",
        &data[count].timestamp,
        &data[count].Va,
        &data[count].Vb,
        &data[count].Vc,
        &data[count].current
        );

        count++;

    }


    fclose(fptr);


}