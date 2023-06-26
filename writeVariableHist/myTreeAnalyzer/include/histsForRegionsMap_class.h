#ifndef HISTFORREGIONSMAP_CLASS_H
#define HISTFORREGIONSMAP_CLASS_H

#include <iterator>
#include <map>
#include <iostream>

#include "TString.h"
#include "TH1D.h"
#include "TFile.h"
#include "myEventClass.h"

class histsForRegionsMap
{
private:
    TString m_variableName;
    TString m_histTitle;
    TString m_processName;
    Int_t m_binNum;
    Double_t m_binMin;
    Double_t m_binMax;
    std::map<TString, TH1D *> m_histsVector;
    myBranch<Double_t>* m_branch=nullptr;

public:
    // default constructor
    histsForRegionsMap(TString variableName = "", TString histTitle = "", TString processName = "", Int_t bin = 0, Double_t binMin = 0.0, Double_t binMax = 0.0) : m_variableName{variableName}, m_histTitle{histTitle}, m_processName{processName}, m_binNum{bin}, m_binMin{binMin}, m_binMax{binMax} {
        std::cout << "Initializing histsForRegionsMap constructor 0\n";
    };
    histsForRegionsMap(TString variableName, TString histTitle, TString processName, Int_t bin, Double_t binMin, Double_t binMax, const std::vector<TString> &regions) : m_variableName{variableName}, m_histTitle{histTitle}, m_processName{processName}, m_binNum{bin}, m_binMin{binMin}, m_binMax{binMax}
    {
        std::cout << "Initializing histsForRegionsMap constructor 1\n";
        for (UInt_t i = 0; i < regions.size(); i++)
        {
            // TString iHistName = regions[i] + "_" + m_processName + "_" + m_variableName;
            TString iHistName = m_processName + "_" + regions[i] + "_" + m_variableName;
            TH1D *temp;
            temp = new TH1D(iHistName.Data(), m_histTitle.Data(), m_binNum, m_binMin, m_binMax);
            temp->Sumw2();
            m_histsVector[regions[i]] = temp;
        }
    };
    //for connecting with tree branches
    histsForRegionsMap(TString variableName, TString histTitle, TString processName, Int_t bin, Double_t binMin, Double_t binMax, const std::vector<TString> &regions, myBranch<Double_t>* branch ) : m_variableName{variableName}, m_histTitle{histTitle}, m_processName{processName}, m_binNum{bin}, m_binMin{binMin}, m_binMax{binMax}, m_branch{branch}
    {
        std::cout << "Initializing histsForRegionsMap constructor 1\n";
        for (UInt_t i = 0; i < regions.size(); i++)
        {
            TString iHistName = m_processName + "_" + regions[i] + "_" + m_variableName;
            TH1D *temp;
            temp = new TH1D(iHistName.Data(), m_histTitle.Data(), m_binNum, m_binMin, m_binMax);
            temp->Sumw2();
            m_histsVector[regions[i]] = temp;
        }
        std::cout << "m_branch" << m_branch->n() << "\n";
    };

    ~histsForRegionsMap();

    void setHistsMap(const std::vector<TString> &regions);
    void fillHistVec(TString iRegion, Double_t value, Double_t weight, Bool_t ifFill = kTRUE, Bool_t isData = kFALSE);
    void fillHistVec(TString iRegion, Double_t weight, Bool_t ifFill, Bool_t isData);
    void print();
    void setDir(TFile *file);
    void scale(Double_t scale);
};

#endif