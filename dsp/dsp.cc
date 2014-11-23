/*
 * ==============================================================================
 *
 *       Filename:  dsp.cc
 *
 *    Description:  DSP processing on vector of data.
 *
 *        Version:  1.0
 *        Created:  11/18/2014 10:04:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dilawar Singh (), dilawars@ncbs.res.in
 *   Organization:  
 *
 * ==============================================================================
 */


#include "dsp.h"
#include "global.h"
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
#include <functional>
#include <memory>
#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_fft_halfcomplex.h>

using namespace std;

/**
 * @brief A bandpass filter to remove the noise.
 * 
 * @param  Vector of data.
 * @param  Cutoff A.
 * @param  Cutoff B.
 * @param  Sampling frequency.
 */
int bandpass(
        vector<double>& data
        , vector<double>& outData
        , unsigned int cutoffA
        , unsigned int cutoffB
        , const size_t samplingFrequency
        )
{
    size_t SIZE = data.size();
    double timePeriod = 1.0 / samplingFrequency;

    double* arrayData, filter;
    arrayData = new double[SIZE];
    filter = new double[SIZE];

    unsigned int i = 0;
    for(auto it = data.begin(); it != data.end(); it++)
    {
        arrayData[i] = *it;
        i++;
    }

    /* Compute FFT here */
    gsl_fft_real_wavetable* real;
    gsl_fft_halfcomplex_wavetable * hc;
    gsl_fft_real_workspace * work;

    work = gsl_fft_real_workspace_alloc(SIZE);
    real = gsl_fft_real_wavetable_alloc(SIZE);
    gsl_fft_real_transform(arrayData, 1, SIZE , real, work);

    /* Multiply the fft of signal with filter. This multiplication in frequency
     * domain is equal to convolution in frequency domain.
     */


    /* Transform the singal back to time domain */
    hc = gsl_fft_halfcomplex_wavetable_alloc(SIZE);
    gsl_fft_halfcomplex_inverse(arrayData, 1, SIZE, hc, work);
    gsl_fft_halfcomplex_wavetable_free(hc);

    for(int i = 0; i < 100; i++)
        cerr << arrayData[i] << "," << data[i] << ";";

    return EXIT_SUCCESS;
}
