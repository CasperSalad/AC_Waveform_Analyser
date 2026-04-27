//
// Created by clt2-lamptey on 21/04/2026.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "waveform.h"
Calculations RMS(Sample *data) {

    double Va_SUM;
    double Vb_SUM;
    double Vc_SUM;

    double Va_SUM2;
    double Vb_SUM2;
    double Vc_SUM2;
    int count;
    for (int i = 0; i < 999; i++) {
        Va_SUM = Va_SUM + data[i]. Va;
        Vb_SUM = Vb_SUM + data[i]. Vb;
        Vc_SUM = Vc_SUM + data[i]. Vc;

        Va_SUM2 = Va_SUM2 + pow(data[i]. Va, 2);
        Vb_SUM2 = Vb_SUM2 + pow(data[i]. Vb, 2);
        Vc_SUM2 = Vc_SUM2 + pow(data[i]. Vc, 2);
    }

    Va.MEAN = Va_SUM /1000;
    Vb.MEAN = Vb_SUM /1000;
    Vc.MEAN = Vc_SUM /1000;
    Va.RMS = sqrt(Va_SUM2 /1000);
    Vb.RMS = sqrt(Vb_SUM2 /1000);
    Vc.RMS = sqrt(Vc_SUM2 /1000);

    if (Va.RMS < 207) Va.RMS_Status = 0;
    if (Vb.RMS < 207) Vb.RMS_Status = 0;
    if (Vc.RMS < 207) Vc.RMS_Status = 0;

    if (Va.RMS > 253) Va.RMS_Status = 2;
    if (Vb.RMS > 253) Vb.RMS_Status = 2;
    if (Vc.RMS > 253) Vc.RMS_Status = 2;
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
    Va.PEAK2PEAK = Va_MAX - Va_MIN;
    Vb.PEAK2PEAK = Vb_MAX - Vb_MIN;
    Vc.PEAK2PEAK = Vc_MAX - Vc_MIN;

}

Calculations Clippings(Sample *data) {
    int count;
    for (int i = 0; i < 999; i++) {
        if (data[i].Va >= 324.9) {

            Va.CLIPPINGS_TS[count] = data[i].timestamp;
            Va.CLIPPINGS[count] = data[i].Va;
            count++;
        }
        if (data[i].Vb >= 324.9) {

            Vb.CLIPPINGS_TS[count] = data[i].timestamp;
            Vb.CLIPPINGS[count] = data[i].Vb;
            count++;
        }
        if (data[i].Vc >= 324.9) {

            Vc.CLIPPINGS_TS[count] = data[i].timestamp;
            Vc.CLIPPINGS[count] = data[i].Vc;
            count++;
        }
    }
}
