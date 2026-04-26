//
// Created by clt2-lamptey on 21/04/2026.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "waveform.h"
Calculations RMS(Sample *data) {

    double Va_SUM2;
    double Vb_SUM2;
    double Vc_SUM2;
    int count;
    for (int i = 0; i < count; i++) {
        Va_SUM2 = Va_SUM2 + pow(data[i]. Va, 2);
        Vb_SUM2 = Vb_SUM2 + pow(data[i]. Vb, 2);
        Vc_SUM2 = Vc_SUM2 + pow(data[i]. Vc, 2);
    }
    Data_Set.Va_RMS = sqrt(Va_SUM2 /1000);
    Data_Set.Vb_RMS = sqrt(Vb_SUM2 /1000);
    Data_Set.Vc_RMS = sqrt(Vc_SUM2 /1000);

    return Data_Set;
}
