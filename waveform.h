//
// Created by clt2-lamptey on 21/04/2026.
//

#ifndef WAVEFORM_ANALYSER_CODE_WAVEFORM_H
#define WAVEFORM_ANALYSER_CODE_WAVEFORM_H
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
    double MEAN;
    double RMS;
    int RMS_Status;
    double PEAK2PEAK;
    double CLIPPINGS_TS[20];
    double CLIPPINGS [20];
} Calculations;

Calculations Va;
Calculations Vb;
Calculations Vc;
Calculations RMS(Sample *data);
#endif //WAVEFORM_ANALYSER_CODE_WAVEFORM_H

