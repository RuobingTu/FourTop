#ifndef WH_FORDATAMC_H
#define WH_FORDATAMC_H

#include <iostream>
#include <vector>
#include <variant>
#include <memory>

#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH1D.h"

#include "histsForRegionsMap_class.h"
#include "functions.h"
#include "../../myLibrary/commenFunction.h"

#include "myEventClass.h"

class WH_forDataMC
{
public:
    WH_forDataMC(const TString inputDir, const TString process, const Bool_t ifFakeTau = kFALSE, TString outVersion = "v0", Bool_t isTest = kTRUE) : m_inputDir{inputDir}, m_processName{process}, m_ifFakeTau{ifFakeTau},  m_isTest{isTest} 
    {
        m_file = new TFile(m_inputDir + m_processName + ".root", "READ"); //???what is this initialization
        if (!m_file || m_file->IsZombie())
        {
            std::cout << "Error: could not open file!" << m_file->GetName() << std::endl;
        }
        else
        {
            std::cout << "input file: " << m_file->GetName() << "\n";
            m_tree = (TTree *)m_file->Get("newtree");
        }

        m_era = TTTT::getEra2(m_inputDir);
        m_isData = TTTT::getIsData(m_inputDir);
        m_isRun3 = TTTT::isRun3(m_era);
        std::cout << "m_era=" << m_era << " m_isData=" << m_isData << "  m_isTest=" << m_isTest <<"  m_isRun3="<<m_isRun3<< "\n";
        std::cout << "m_ifFakeTau="<<m_ifFakeTau<<"\n";
        m_isFakeTau = m_processName.Contains("fakeTau");
        std::cout<<"m_isFakeTau="<<m_isFakeTau<<"\n";

        m_isFakeLepton = m_processName.Contains("fakeLepton");
        std::cout<<"m_isFakeLepton="<<m_isFakeLepton<<"\n";

        std::cout << "m_processName: " << m_processName  << "\n";
        m_outFile = new TFile(m_inputDir + "variableHists" + "_" + outVersion + "/" + m_processName + ".root", "RECREATE");

        e = new event(m_tree);
    };
    ~WH_forDataMC();

    void Init();
    void LoopTree(UInt_t entry =0);
    void Terminate();

private:
    TString m_inputDir;
    TString m_processName;
    const Bool_t m_ifFakeTau;
    Bool_t m_isFakeTau;
    Bool_t m_isFakeLepton = kFALSE;
    Bool_t m_isTest = kTRUE;
    TTree *m_tree;
    TFile *m_file;
    TString m_era = "2016";
    Bool_t m_isRun3 = kFALSE;
    Bool_t m_isData = kFALSE;
    TString m_outputFolder;
    TFile *m_outFile;
    event *e;

    //
    // hists regions
    histsForRegionsMap<Double_t> jets_HT_class; // calls for default constructor
    // std::vector<histsForRegionsMap>
    std::vector<std::shared_ptr<histForRegionsBase>> histsForRegion_vec;


};

#endif