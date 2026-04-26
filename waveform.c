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
    for (int i = 0; i < 999; i++) {
        Va_SUM2 = Va_SUM2 + pow(data[i]. Va, 2);
        Vb_SUM2 = Vb_SUM2 + pow(data[i]. Vb, 2);
        Vc_SUM2 = Vc_SUM2 + pow(data[i]. Vc, 2);
    }
    Data_Set.Va_RMS = sqrt(Va_SUM2 /1000);
    Data_Set.Vb_RMS = sqrt(Vb_SUM2 /1000);
    Data_Set.Vc_RMS = sqrt(Vc_SUM2 /1000);

    return Data_Set;
}

Calculations Peak2Peak(Sample *data) {

    double Va_MAX;
    double Va_MIN;
    double Vb_MAX;
    double Vb_MIN;
    double Vc_MAX;
    double Vc_MIN;

    for (int i = 0; i < 999; i++) {
        if (data[i].Va > Va_MAX) Va_MAX = data[i].Va;
        if (data[i].Va < Va_MIN) Va_MIN = data[i].Va;

        if (data[i].Vb > Vb_MAX) Vb_MAX = data[i].Vb;
        if (data[i].Vb < Vb_MIN) Vb_MIN = data[i].Vb;

        if (data[i].Vc > Vc_MAX) Vc_MAX = data[i].Vc;
        if (data[i].Vc < Vc_MIN) Vc_MIN = data[i].Vc;
    }
    Data_Set. Va_PEAK2PEAK = Va_MAX - Va_MIN;
    Data_Set. Vb_PEAK2PEAK = Vb_MAX - Vb_MIN;
    Data_Set. Vb_PEAK2PEAK = Vc_MAX - Vc_MIN;

    return Data_Set;
}
