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

        RMS(data, 1000, Phase);
        printf("\nRMS complete");
        RMS_Compliance(10, 230, Phase);
        printf("\nRMS Compliance complete");
        Peak2Peak(data, 1000, Phase);
        printf("\nP2P complete");
        Clippings(data, 1000, 324.9, Phase);
        printf("\nCLIPPINGS complete");


    THD_Percent(data, 1000);
    printf("\nTHD Average complete");
    Power_Factor(data, 1000);
    printf("\nPfactor Average complete");
    Frequency(data, 1000);
    printf("\nFrequency Average complete");

    RESULTS(Phase);
    printf("\nResults file creation complete");

    free(data);
    return 0;
}
