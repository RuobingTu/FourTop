#ifndef COMMENFUNCTION_H
#define COMMENFUNCTION_H

#include <TString.h>
#include <TH1D.h>
#include <TFile.h>
#include <iostream>

namespace TTTT{



Bool_t getIsData(TString inputDir);
TString getEra(TString inputDir);

Bool_t isRun3(TString era);
void fillHist(TH1D *&hist, Double_t value, Double_t weight, Bool_t isData);

    Double_t getGenSum(TString inputFile);


// TH1D *getHistogramFromFile(TString filename, const char *histname);
template <typename T>
T *getHistogramFromFile(TString filename, const char *histname)
{
    TFile *file = TFile::Open(filename);
    if (!file || file->IsZombie())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return nullptr;
    }
    TH1D *hist = (T *)(file->Get(histname));
    if (!hist)
    {
        std::cerr << "Error: could not retrieve histogram " << histname << " from file " << filename << std::endl;
        file->Close();
        return nullptr;
    }
    hist->SetDirectory(nullptr); // detach histogram from file to prevent it from being deleted
    file->Close();
    return hist;
}

};
#endif