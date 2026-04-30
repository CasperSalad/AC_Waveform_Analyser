//
// Created by clt2-lamptey on 30/04/2026.
//

#ifndef WAVEFORM_ANALYSER_CODE_COMMON_H
#define WAVEFORM_ANALYSER_CODE_COMMON_H

extern double THD_Average;
extern double Pfactor_Average;
extern double Frequency_Average;


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
    int RMS_Status;
    double MEAN;
    double RMS;
    double PEAK2PEAK;
    double CLIPPINGS_TS[20];
    double CLIPPINGS [20];

} Calculations;

extern Calculations Phase[3];
#endif //WAVEFORM_ANALYSER_CODE_COMMON_H
