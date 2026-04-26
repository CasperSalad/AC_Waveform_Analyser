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
#endif //WAVEFORM_ANALYSER_CODE_WAVEFORM_H

