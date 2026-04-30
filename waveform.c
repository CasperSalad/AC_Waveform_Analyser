//
// Created by clt2-lamptey on 21/04/2026.
//
#include <math.h>
#include "waveform.h"

int CLIP_COUNT [3];

double THD_Average = 0;
double Pfactor_Average = 0;
double Frequency_Average = 0;

Calculations *RMS (Sample *data, int n) {



    double Va_SUM;
    double Vb_SUM;
    double Vc_SUM;

    double Va_SUM2;
    double Vb_SUM2;
    double Vc_SUM2;

    for (int i = 0; i < n; i++) {
        Va_SUM = Va_SUM + data[i]. Va;
        Vb_SUM = Vb_SUM + data[i]. Vb;
        Vc_SUM = Vc_SUM + data[i]. Vc;

        Va_SUM2 = Va_SUM2 + pow(data[i]. Va, 2);
        Vb_SUM2 = Vb_SUM2 + pow(data[i]. Vb, 2);
        Vc_SUM2 = Vc_SUM2 + pow(data[i]. Vc, 2);
    }

    Phase[0].MEAN = Va_SUM /n;
    Phase[1].MEAN = Vb_SUM /n;
    Phase[2].MEAN = Vc_SUM /n;
    Phase[0].RMS = sqrt(Va_SUM2 /n);
    Phase[1].RMS = sqrt(Vb_SUM2 /n);
    Phase[2].RMS = sqrt(Vc_SUM2 /n);

}

Calculations *RMS_Compliance (double nominal, double RMS) {

    Calculations Phase[3] = {
            {'a', 1},
            {'b', 1},
            {'c', 1}
    };

    double upper = RMS + RMS * (nominal/100);
    double lower = RMS - RMS * (nominal/100);

    if (Phase[0].RMS < lower) Phase[0].RMS_Status = 0;
    if (Phase[1].RMS < lower) Phase[1].RMS_Status = 0;
    if (Phase[2].RMS < lower) Phase[2].RMS_Status = 0;

    if (Phase[0].RMS > upper) Phase[0].RMS_Status = 2;
    if (Phase[1].RMS > upper) Phase[1].RMS_Status = 2;
    if (Phase[2].RMS > upper) Phase[2].RMS_Status = 2;

}

Calculations *Peak2Peak (Sample *data, int n) {

    double Va_MAX;
    double Va_MIN;
    double Vb_MAX;
    double Vb_MIN;
    double Vc_MAX;
    double Vc_MIN;

    for (int i = 0; i < n; i++) {
        if (data[i].Va > Va_MAX) Va_MAX = data[i].Va;
        if (data[i].Va < Va_MIN) Va_MIN = data[i].Va;

        if (data[i].Vb > Vb_MAX) Vb_MAX = data[i].Vb;
        if (data[i].Vb < Vb_MIN) Vb_MIN = data[i].Vb;

        if (data[i].Vc > Vc_MAX) Vc_MAX = data[i].Vc;
        if (data[i].Vc < Vc_MIN) Vc_MIN = data[i].Vc;
    }
    Phase[0].PEAK2PEAK = Va_MAX - Va_MIN;
    Phase[1].PEAK2PEAK = Vb_MAX - Vb_MIN;
    Phase[2].PEAK2PEAK = Vc_MAX - Vc_MIN;

}

Calculations *Clippings (Sample *data, int n, double limit) {

    for (int i = 0; i < n; i++) {
        if (data[i].Va >= limit) {

            Phase[0].CLIPPINGS_TS[CLIP_COUNT[0]] = data[i].timestamp;
            Phase[0].CLIPPINGS[CLIP_COUNT[0]] = data[i].Va;
            CLIP_COUNT[0]++;
        }
        if (data[i].Vb >= limit) {

            Phase[1].CLIPPINGS_TS[CLIP_COUNT[1]] = data[i].timestamp;
            Phase[1].CLIPPINGS[CLIP_COUNT[1]] = data[i].Vb;

            CLIP_COUNT[1]++;
        }
        if (data[i].Vc >= limit) {

            Phase[2].CLIPPINGS_TS[CLIP_COUNT[2]] = data[i].timestamp;
            Phase[2].CLIPPINGS[CLIP_COUNT[2]] = data[i].Vc;

            CLIP_COUNT[2]++;
        }

    }
}

void THD_Percent (Sample *data, int n) {

    double THD_SUM;
    for (int i = 0; i < n; i++) {
        THD_SUM = THD_SUM + data[i].THD;
    }
    THD_Average = THD_SUM / n;


}
void Power_Factor (Sample *data, int n) {

    double Pfactor_SUM;
    for (int i = 0; i < n; i++) {
        Pfactor_SUM = Pfactor_SUM + data[i].THD;
    }
    Pfactor_Average = Pfactor_SUM / n;


}
void Frequency (Sample *data, int n) {

    double Frequency_SUM;
    for (int i = 0; i < n; i++) {
        Frequency_SUM = Frequency_SUM + data[i].THD;
    }
    Frequency_Average = Frequency_SUM / n;


}