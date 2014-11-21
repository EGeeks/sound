/*
 * ==============================================================================
 *
 *       Filename:  dsp.h
 *
 *    Description:  Header file
 *
 *        Version:  1.0
 *        Created:  11/18/2014 10:18:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dilawar Singh (), dilawars@ncbs.res.in
 *   Organization:  
 *
 * ==============================================================================
 */

#ifndef  DSP_INC
#define  DSP_INC

#include <vector>

using namespace std;

void bandpass(vector<double>& data
        , vector<double>& outData
        , unsigned int cutoffA, unsigned int cutoffB
        , const size_t samplingFrequency
        );

#endif   /* ----- #ifndef DSP_INC  ----- */
