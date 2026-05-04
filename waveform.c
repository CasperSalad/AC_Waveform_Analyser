//
// Created by clt2-lamptey on 21/04/2026.
//
#include <math.h>
#include "waveform.h"

int CLIP_COUNT [3];

double THD_Average = 0;
double Pfactor_Average = 0;
double Frequency_Average = 0;

void RMS (Sample *data, int n, Calculations Phase[3]) {


// Variables for the sum and sum of squares for all voltages:
    double Va_SUM = 0;
    double Vb_SUM = 0;
    double Vc_SUM = 0;

    double Va_SUM2 = 0;
    double Vb_SUM2 = 0;
    double Vc_SUM2 = 0;
// Calculating RMS and Mean (DC_Offset:
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

void RMS_Compliance (double nominal, double RMS, Calculations Phase[3]) {

// nominal = percentage that would give the range of nominal
    double upper = RMS + RMS * (nominal/100);
    double lower = RMS - RMS * (nominal/100);
    for (int i = 0; i < 3; i++) {
        if (Phase[i].RMS < lower) Phase[i].RMS_Status = 0;
        if (Phase[i].RMS > upper) Phase[i].RMS_Status = 2;
    }

}

void Peak2Peak (Sample *data, int n, Calculations Phase[3]) {
// Variables for maximum and minimum values of all phase voltages:
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

void Clippings (Sample *data, int n, double limit, Calculations Phase[3]) {
// Checking whether every value is within the interval -limit < x < limit:
    for (int i = 0; i < n; i++) {
        if (-limit >= data[i].Va || data[i].Va >= limit) {

            Phase[0].CLIPPINGS_TS[Phase[0].CLIP_COUNT[0]] = data[i].timestamp;
            Phase[0].CLIPPINGS[Phase[0].CLIP_COUNT[0]] = data[i].Va;

            Phase[0].CLIP_COUNT[0]++;
        }
        if (-limit >= data[i].Vb || data[i].Vb >= limit) {

            Phase[1].CLIPPINGS_TS[Phase[1].CLIP_COUNT[1]] = data[i].timestamp;
            Phase[1].CLIPPINGS[Phase[1].CLIP_COUNT[1]] = data[i].Vb;

            Phase[1].CLIP_COUNT[1]++;
        }
        if (-limit >= data[i].Vc || data[i].Vc >= limit) {

            Phase[2].CLIPPINGS_TS[Phase[2].CLIP_COUNT[2]] = data[i].timestamp;
            Phase[2].CLIPPINGS[Phase[2].CLIP_COUNT[2]] = data[i].Vc;

            Phase[2].CLIP_COUNT[2]++;
        }

    }
}

void THD_Percent (Sample *data, int n) {
//Calculating Average THD
    double THD_SUM = 0;
    for (int i = 0; i < n; i++) {
        THD_SUM = THD_SUM + data[i].THD;
    }
    THD_Average = THD_SUM / n;


}
void Power_Factor (Sample *data, int n) {
//Calculating Average Power Factor
    double Pfactor_SUM = 0;
    for (int i = 0; i < n; i++) {
        Pfactor_SUM = Pfactor_SUM + data[i].pFactor;
    }
    Pfactor_Average = Pfactor_SUM / n;


}
void Frequency (Sample *data, int n) {
//Calculating Average Frequency
    double Frequency_SUM = 0;
    for (int i = 0; i < n; i++) {
        Frequency_SUM = Frequency_SUM + data[i].frequency;
    }
    Frequency_Average = Frequency_SUM / n;


}