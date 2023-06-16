#ifndef MAKEVARIABLESMAIN_H
#define MAKEVARIABLESMAIN_H
// #include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"
#include <TTreeReaderValue.h>
#include <TH1D.h>
#include <TChain.h>

#include "eventReader_forMV.h" //use ttreeReader to construct event

class MakeVariablesMain
{
public:
    // MakeVariablesMain(TString inputDir, TString singleFileName, TString outputDir, const Bool_t isData, const TString era, Bool_t m_isTest) : m_isData{isData}, m_era{era}
    MakeVariablesMain(TString inputDir)
    {
        std::cout << "Initialize MakeVariablesMain class..................................\n";
        // m_input = new TFile(inputDir + singleFileName, "READ");
        // if (!m_input->IsZombie())
        // {
        // set up input and event object
        TChain chain("tree");
        chain.Add(inputDir + "outTree*.root");
        std::cout<<"all entries in chain: "<<chain.GetEntries()<<"\n";
        // m_reader.SetChain(&chain);
        // e = new EventForMV(m_reader);

        // set up output
        // TString outName = outputDir + singleFileName;
        // m_output = new TFile(outName, "RECREATE");
        // m_outTree->SetDirectory(m_output);

        // set up
        // m_isData = getIsData(inputDir);
        // m_era = getEra(inputDir);
        // std::cout << "m_isData: " << m_isData << ";    m_era: " << m_era << "\n";
        // }
        // else
        // {
        //     std::cout << "BAD!!! file not correctly open\n";
        // }
        std::cout << "Done initializing MakeVariablesMain class................................\n";
        std::cout << "\n";
    };
    ~MakeVariablesMain();

    void Init();

    void EventLoop(Bool_t preSelection = kTRUE, ULong_t numEntries = 1000);
    void Terminate();
    void getLepEtaPhi(std::vector<Double_t> &lepEtaVec, std::vector<Double_t> &lepPhiVec);

private:
    TTreeReader m_reader;
    EventForMV *e;
    TFile *m_output;
    TTree *m_outTree = new TTree("tree", "tree after object selection");
    Bool_t m_isData;
    TString m_era;
};

#endif