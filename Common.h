//
// Created by clt2-lamptey on 30/04/2026.
//

#ifndef WAVEFORM_ANALYSER_CODE_COMMON_H
#define WAVEFORM_ANALYSER_CODE_COMMON_H
//Variables for calculations across all 3 Phases:
extern double THD_Average;
extern double Pfactor_Average;
extern double Frequency_Average;
//Integer to store the amount of clippings per phase:
extern int CLIP_COUNT [3];

//Structure for each sample, size 64 bytes:
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

//Structure for Calculations
typedef struct {

    char name;
    int RMS_Status; // Indicator for whether RMS is compliant with the nominal percentage. 0 = below 1 = within 2 = above
    double CLIPPINGS [20]; //Array to store the voltage value for the clippings
    double MEAN;
    double RMS;
    double PEAK2PEAK;
    double CLIPPINGS_TS[20]; //Clippings array for timestamp of each clipping

} Calculations;


#endif //WAVEFORM_ANALYSER_CODE_COMMON_H
