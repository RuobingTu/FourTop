#ifndef COPYBRANCHES_H
#define COPYBRANCHES_H

#include "eventReader_forMV.h"

class CopyBranches
{
public:
    CopyBranches(TTree *outTree);
    ~CopyBranches();
    void makeVariables(EventForMV *e);
    void clearBranch();
    void reportEntry(TString className);

private:
    ULong_t m_entry = 0;
    // output branches
    Int_t PV_npvsGood;
    //HLT
    Int_t HLT_PFHT450_SixJet40_BTagCSV_p056 = -99;
    Int_t HLT_PFHT400_SixJet30_DoubleBTagCSV_p056 = -99;
    Int_t HLT_PFJet450 = -99;
    Int_t HLT_IsoMu24 = -99;
    Int_t HLT_IsoMu27 = -99;
    Int_t HLT_PFJet500 = -99;
    Int_t HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5 = -99;
    Int_t HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2 = -99;
    Int_t HLT_PFHT430_SixPFJet40_PFBTagDeepCSV_1p5 = -99;
    Int_t HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59 = -99;
    Int_t HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94 = -99;
    // 2017
    Int_t HLT_PFHT430_SixJet40_BTagCSV_p080 = -99;
    Int_t HLT_PFHT380_SixJet32_DoubleBTagCSV_p075 = -99;
    Int_t HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2 = -99;
    //2022
    Int_t HLT_PFHT450_SixPFJet36_PFBTagDeepJet_1p59 = -99;
    Int_t HLT_PFHT400_SixPFJet32_DoublePFBTagDeepJet_2p94 = -99;

    //
    Double_t MET_pt = -99;
    Double_t MET_phi = -99;

    std::vector<Double_t> jets_pt_;
    std::vector<Double_t> jets_eta_;
    std::vector<Double_t> jets_btags_;
    std::vector<Int_t> jets_flavour_;
};

#endif