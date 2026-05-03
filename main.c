 #include <stdio.h>
#include <stdlib.h>
#include "IO.h"
#include "waveform.h"
#include "Common.h"
int main() {

    Calculations Phase[3] = {
            {'a', 1},
            {'b', 1},
            {'c', 1}
    };

    char FileName[50];

    printf("3 phase AC Waveform Power Analyser by Casper Lamptey\n\nEnter File Name:");
    scanf("%s", FileName);

    Sample *data = COLLECT(FileName);

    printf("\ntime : %.12lf", data[0].timestamp);
    printf("\nVa : %.12lf", data[0].Va);
    printf("\nVb : %.12lf", data[0].Vb);
    printf("\nVc : %.12lf", data[0].Vc);
    printf("\ncurrent : %.12lf", data[0].current);
    printf("\nf : %.12lf", data[0].frequency);
    printf("\np : %.12lf", data[0].pFactor);
    printf("\nTHD : %.12lf", data[0].THD);


        RMS(data, 1000, Phase);
        printf("\nRMS complete");
        RMS_Compliance(10, 230, Phase);
        printf("\nRMS Compliance complete");
        Peak2Peak(data, 1000, Phase);
        printf("\nP2P complete");
        Clippings(data, 1000, 324.9, Phase);
        printf("\nCLIPPINGS complete");


    printf("\nRMS : %.12lf ", Phase[0].RMS);
    printf("\np2p : %.12lf ", Phase[0].PEAK2PEAK);

    THD_Percent(data, 1000);
    Power_Factor(data, 1000);
    Frequency(data, 1000);
    RESULTS(Phase);


    free(data);
    return 0;
}
