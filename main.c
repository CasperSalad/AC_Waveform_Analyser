 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "IO.h"
#include "waveform.h"
int main() {

    char FileName[50];

    printf("3 phase AC Waveform Power Analyser by Casper Lamptey\n\nEnter File Name:");
    scanf("%s", FileName);

Sample *data = COLLECT(FileName);

if (data != NULL) {

    RMS(data, 1000);
    RMS_Compliance(10, 230);
    Peak2Peak(data, 1000);
    Clippings(data,  1000, 324.9);
    THD_Percent(data,  1000);
    Power_Factor(data,  1000);
    Frequency(data,  1000);





} else {
    printf("\nFAILED");
}
    return 0;
}
