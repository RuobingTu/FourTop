#include <map>

#include "../include/copyBranches.h"

CopyBranches::CopyBranches(TTree *outTree)
{
    //!!!maybe make these basic variables for all object as base class
    std::cout << "Initializing CopyBranches.....\n";

    outTree->Branch("PV_npvsGood", &PV_npvsGood);

    outTree->Branch("HLT_PFHT450_SixJet40_BTagCSV_p056", &HLT_PFHT450_SixJet40_BTagCSV_p056);
    outTree->Branch("HLT_PFHT400_SixJet30_DoubleBTagCSV_p056", &HLT_PFHT400_SixJet30_DoubleBTagCSV_p056);
    outTree->Branch("HLT_PFJet450", &HLT_PFJet450);
    outTree->Branch("HLT_IsoMu24", &HLT_IsoMu24);
    outTree->Branch("HLT_IsoMu27", &HLT_IsoMu27);
    outTree->Branch("HLT_PFJet500", &HLT_PFJet500);
    outTree->Branch("HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5", &HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5);
    outTree->Branch("HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2", &HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2);
    outTree->Branch("HLT_PFHT430_SixPFJet40_PFBTagDeepCSV_1p5", &HLT_PFHT430_SixPFJet40_PFBTagDeepCSV_1p5);
    outTree->Branch("HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59", &HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59);
    outTree->Branch("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94", &HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94);
    // 2017
    outTree->Branch("HLT_PFHT430_SixJet40_BTagCSV_p080", &HLT_PFHT430_SixJet40_BTagCSV_p080);
    outTree->Branch("HLT_PFHT380_SixJet32_DoubleBTagCSV_p075", &HLT_PFHT380_SixJet32_DoubleBTagCSV_p075);
    outTree->Branch("HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2", &HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2);
    //2022
    outTree->Branch("HLT_PFHT450_SixPFJet36_PFBTagDeepJet_1p59", &HLT_PFHT450_SixPFJet36_PFBTagDeepJet_1p59);
    outTree->Branch("HLT_PFHT400_SixPFJet32_DoublePFBTagDeepJet_2p94", &HLT_PFHT400_SixPFJet32_DoublePFBTagDeepJet_2p94);

    outTree->Branch("MET_pt", &MET_pt);
    outTree->Branch("MET_phi", &MET_phi);

    std::cout << "Done initializing ............\n";
    std::cout << "\n";
};

void CopyBranches::makeVariables(EventForMV *e)
{
    // clearBranch();
    PV_npvsGood = *e->PV_npvsGood_;

};


void CopyBranches::clearBranch()
{ //??? derived class should also have a clearBranch()
};


CopyBranches::~CopyBranches(){};