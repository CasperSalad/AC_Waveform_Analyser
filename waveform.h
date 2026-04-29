//
// Created by clt2-lamptey on 21/04/2026.
//

#ifndef WAVEFORM_ANALYSER_CODE_WAVEFORM_H
#define WAVEFORM_ANALYSER_CODE_WAVEFORM_H

double THD_Average;
double Pfactor_Average;
double Frequency_Average;

typedef struct {
    double timestamp;
    double Va;
    double Vb;
    double Vc;
    double current;
    double frequency;
    double pFactor;
    double THD;
} Sample;

typedef struct {

    char name;
    double MEAN;
    double RMS;
    int RMS_Status;
    double PEAK2PEAK;
    double CLIPPINGS_TS[20];
    double CLIPPINGS [20];

} Calculations;

Calculations Phase[3];



Calculations RMS(Sample *data, int n);
Calculations RMS_Compliance(double nominal, double RMS);
Calculations Peak2Peak(Sample *data, int n);
Calculations Clippings(Sample *data, int n, double limit);
Sample *THD_Percent (Sample *data, int n);
Sample *Power_Factor (Sample *data, int n);
Sample *Frequency (Sample *data, int n);
#endif //WAVEFORM_ANALYSER_CODE_WAVEFORM_H

