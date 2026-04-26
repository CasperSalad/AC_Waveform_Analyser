 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "IO.h"
#include "waveform.h"
int main() {

Sample *data = COLLECT("power_quality_log.csv");

if (data != NULL) {

    printf("timestamp: %lf\n", data[0].timestamp);
    printf("Va: %lf\n", data[0].Va);
    printf("Vb: %lf\n", data[0].Vb);
    printf("Vc: %lf\n", data[0].Vc);
    printf("current: %lf\n", data[0].current);
    printf("frequency: %lf\n", data[0].frequency);
    printf("pFactor: %lf\n", data[0].pFactor);
    printf("THD : %lf\n", data[0].THD);
    free(data);
} else {
    printf("\nFAILED");
}
    return 0;
}
