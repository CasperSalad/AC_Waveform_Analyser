//
// Created by clt2-lamptey on 21/04/2026.
//

#ifndef WAVEFORM_ANALYSER_CODE_WAVEFORM_H
#define WAVEFORM_ANALYSER_CODE_WAVEFORM_H
#include "Common.h"


void RMS(Sample *data, int n, Calculations *Phase);
void RMS_Compliance(double nominal, double RMS, Calculations *Phase);
void Peak2Peak(Sample *data, int n, Calculations *Phase);
void Clippings(Sample *data, int n, double limit, Calculations *Phase);
void THD_Percent (Sample *data, int n);
void Power_Factor (Sample *data, int n);
void Frequency (Sample *data, int n);
#endif //WAVEFORM_ANALYSER_CODE_WAVEFORM_H

