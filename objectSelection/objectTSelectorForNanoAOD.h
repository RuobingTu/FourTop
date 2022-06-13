/**
 * @author Huiling Hua
 * @email huahl@ihep.ac.cn
 * @create date 2021-12-08 02:36:18
 * @modify date 2022-02-18 03:13:23
 * @desc [description]
 */
//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Dec  8 02:32:26 2021 by ROOT version 6.22/00
// from TChain Events/
//////////////////////////////////////////////////////////

#ifndef objectTSelectorForNanoAOD_h
#define objectTSelectorForNanoAOD_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>
#include <fstream>
// Headers needed by this particular selector
#include <vector>
#include <TRandom3.h>
#include <map>
#include "TFormula.h"
#include "TLorentzVector.h"
#include "TH1D.h"
#include "../TauPOG/TauIDSFs/interface/TauIDSFTool.h"
//seem enough to only include the header

#include "correction.h"

class objectTSelectorForNanoAOD : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

/////////////////////////
//our own members
////////////////////////
    TFile *outputfile;
    TFile *inputPUFile_data;
    TFile *inputPUFile_dataUp;
    TFile *inputPUFile_dataDown;
    TFile *inputPUFile_mc;
    TTree *tree;
    TTree *allEvents;
    TH1D  *h_genWeight ;
    TH1F  *dataPileupProfile;
    TH1F  *dataPileupProfileUp;
    TH1F  *dataPileupProfileDown;
    TH1F  *MCPileupProfile;
    TRandom3 jet_jer_myran;
    std::vector<std::vector<std::string>> resolution;
    std::string resFormula;
    std::vector<std::vector<std::string>> resSFs;
    std::string toyResFormula;
   //CHANGE HERE TO RUN ON DATA
   Bool_t isdata = false;
   TString dataSet;
   Double_t runRange[2];

   TauESTool TESTool = TauESTool("UL2016_postVFP","DeepTau2017v2p1VSjet");
   TauFESTool FESTool = TauFESTool("2016Legacy","DeepTau2017v2p1VSe"); //no measurement for 2016 UL, use ReReco instead
   // Uchar_t era = 0;//0 for 2016PPV, 2 for 2016APV, 4 for 2017, 6 for 2018
   TString era = "2016postVFP";
   std::map<TString, double> DeepJetL = { //std::map of loose WPs for DeepJet

       {"2016postVFP", 0.0480},
       {"2016preVFP", 0.0508},
       {"2017", 0.0532},
       {"2018", 0.0490},

   };

   std::map<TString, double> DeepJetM = { //std::map of medium WPs for DeepJet

       {"2016postVFP", 0.2489},
       {"2016preVFP", 0.2598},
       {"2017", 0.3040},
       {"2018", 0.2783},

   };

   std::map<TString, double> DeepJetT = { //std::map of tight WPs for DeepJet

       {"2016postVFP", 0.6377},
       {"2016preVFP", 0.6502},
       {"2017", 0.7476},
       {"2018", 0.7100},

   };

   std::map<TString, double> DeepCSVL = { //std::map of loose WPs for DeepCSV

       {"2016postVFP",  0.1918},
       {"2016preVFP",  0.2027},
       {"2017", 0.1355},
       {"2018", 0.1208},

   };

   std::map<TString, double> DeepCSVM = { //std::map of medium WPs for DeepCSV

       {"2016postVFP",   0.5847},
       {"2016preVFP",  0.6001},
       {"2017", 0.4506},
       {"2018", 0.4168},

   };

   std::map<TString, double> DeepCSVT = { //std::map of tight WPs for DeepCSV

       {"2016postVFP",  0.8767},
       {"2016preVFP", 0.8819},
       {"2017",  0.7738},
       {"2018", 0.7665},

   };

   std::map<TString, TString> GoldenJSONs = { //std::map of golden JSONs

       {"2016postVFP", "../golden_JSONs/Cert_271036-284044_13TeV_Legacy2016_Collisions16_JSON.txt"},
       {"2016preVFP", "../golden_JSONs/Cert_271036-284044_13TeV_Legacy2016_Collisions16_JSON.txt"},
       {"2017", "../golden_JSONs/Cert_294927-306462_13TeV_UL2017_Collisions17_GoldenJSON.txt"},
       {"2018", "../golden_JSONs/Cert_314472-325175_13TeV_Legacy2018_Collisions18_JSON.txt"},

   };

   std::map<Int_t,std::vector<Int_t> > _goodLumis;

   // 1 for MetFilters, 2 for HLTSelection, 4 for preSelection. so 7 if all selection; 0 if no selection 
   Bool_t MetFilters = false;
   Bool_t HLTSelection = false;
   Bool_t preSelection = false;


   Long64_t   fProcessed = 0;
   Long64_t eventsPassed = 0;
   Long64_t eventsPassedHLT = 0;
   Long64_t eventsPassedJSON = 0;
   Long64_t eventsPassedMETFilters = 0;
   Long64_t tausT_total = 0;
   Long64_t tausL_total = 0;
   Long64_t tausF_total = 0;
   Long64_t elesT_total =0;
   Long64_t elesL_total =0;
   Long64_t elesF_total =0;
    Long64_t mounsT_total = 0;
    Long64_t mounsF_total = 0;
    Long64_t mounsL_total = 0;
    Long64_t jets_total = 0;
    Long64_t bjetsM_total =0;


   //branches in output trees
   Int_t PV_npvs_;
   Int_t PV_npvsGood_;
   Int_t genTtbarId_;
   Double_t genWeight_allEvents;

   Int_t    Flag_goodVertices_ ;
   Int_t    Flag_globalSuperTightHalo2016Filter_ ;
   Int_t    Flag_HBHENoiseFilter_ ;
   Int_t    Flag_HBHENoiseIsoFilter_ ;
   Int_t    Flag_EcalDeadCellTriggerPrimitiveFilter_ ;
   Int_t    Flag_BadPFMuonFilter_ ;
   Int_t    Flag_eeBadScFilter_ ;

   UInt_t run_;
   //HLT   
   //2016   
    Int_t HLT_PFHT450_SixJet40_BTagCSV_p056_ ;
    Int_t HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_ ;
	 Int_t HLT_PFJet450_;
    Int_t HLT_IsoMu24_ ;
    Int_t HLT_IsoMu27_ ;

   //2018
   // Bool_t HLT_PFHT1050_ ;
   Int_t HLT_PFHT1050_ ;//not using bool because we need default -99 value to indicat a filling
   Int_t HLT_PFJet500_;
   Int_t HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5_;
   Int_t HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5_;
   Int_t HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2_;
   Int_t HLT_PFHT430_SixPFJet40_PFBTagDeepCSV_1p5_;
   Int_t HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59_;
   Int_t HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94_;



    
    std::vector<TLorentzVector> muonsL; std::vector<Int_t> muonsL_index;
    std::vector<TLorentzVector> muonsF; std::vector<Int_t> muonsF_index;
    std::vector<TLorentzVector> muonsT; std::vector<Int_t> muonsT_index;
    std::vector<TLorentzVector> eleMVAL; std::vector<Int_t> eleMVAL_index;
    std::vector<TLorentzVector> eleMVAF; std::vector<Int_t> eleMVAF_index;
    std::vector<TLorentzVector> eleMVAT; std::vector<Int_t> eleMVAT_index;
    // vector<TLorentzVector> eleMVAL_IsoT; vector<Int_t> eleMVAL_IsoT_index;
    // vector<TLorentzVector> eleMVAF_IsoT; vector<Int_t> eleMVAF_IsoT_index;
    // vector<TLorentzVector> eleMVAT_IsoT; vector<Int_t> eleMVAT_IsoT_index;
    std::vector<TLorentzVector> leptonsMVAF; 
    std::vector<TLorentzVector> leptonsMVAT; 
    std::vector<TLorentzVector> leptonsMVAL; 
    std::vector<TLorentzVector> tausL; std::vector<Int_t> tausL_index; std::vector<Int_t> tausL_decayMode; std::vector<Int_t> tausL_genPartFlav;
    std::vector<TLorentzVector> tausF; std::vector<Int_t> tausF_index; std::vector<Int_t> tausF_decayMode;std::vector<Int_t> tausF_genPartFlav;
    std::vector<TLorentzVector> tausT; std::vector<Int_t> tausT_index; std::vector<Int_t> tausT_decayMode; std::vector<Int_t> tausT_genPartFlav;
    std::vector<TLorentzVector> tausL_TESUp; std::vector<Int_t> tausL_TESUp_index; std::vector<Int_t> tausL_TESUp_decayMode; std::vector<Int_t> tausL_TESUp_genPartFlav;
    std::vector<TLorentzVector> tausF_TESUp; std::vector<Int_t> tausF_TESUp_index; std::vector<Int_t> tausF_TESUp_decayMode; std::vector<Int_t> tausF_TESUp_genPartFlav;
    std::vector<TLorentzVector> tausT_TESUp; std::vector<Int_t> tausT_TESUp_index; std::vector<Int_t> tausT_TESUp_decayMode; std::vector<Int_t> tausT_TESUp_genPartFlav;
    std::vector<TLorentzVector> tausL_TESDown; std::vector<Int_t> tausL_TESDown_index; std::vector<Int_t> tausL_TESDown_decayMode; std::vector<Int_t> tausL_TESDown_genPartFlav;
    std::vector<TLorentzVector> tausF_TESDown; std::vector<Int_t> tausF_TESDown_index; std::vector<Int_t> tausF_TESDown_decayMode; std::vector<Int_t> tausF_TESDown_genPartFlav;
    std::vector<TLorentzVector> tausT_TESDown; std::vector<Int_t> tausT_TESDown_index; std::vector<Int_t> tausT_TESDown_decayMode; std::vector<Int_t> tausT_TESDown_genPartFlav;
    std::vector<TLorentzVector> tausL_FESUp; std::vector<Int_t> tausL_FESUp_index; std::vector<Int_t> tausL_FESUp_decayMode; std::vector<Int_t> tausL_FESUp_genPartFlav;
    std::vector<TLorentzVector> tausF_FESUp; std::vector<Int_t> tausF_FESUp_index; std::vector<Int_t> tausF_FESUp_decayMode; std::vector<Int_t> tausF_FESUp_genPartFlav;
    std::vector<TLorentzVector> tausT_FESUp; std::vector<Int_t> tausT_FESUp_index; std::vector<Int_t> tausT_FESUp_decayMode; std::vector<Int_t> tausT_FESUp_genPartFlav;
    std::vector<TLorentzVector> tausL_FESDown; std::vector<Int_t> tausL_FESDown_index; std::vector<Int_t> tausL_FESDown_decayMode; std::vector<Int_t> tausL_FESDown_genPartFlav;
    std::vector<TLorentzVector> tausF_FESDown; std::vector<Int_t> tausF_FESDown_index; std::vector<Int_t> tausF_FESDown_decayMode; std::vector<Int_t> tausF_FESDown_genPartFlav;
    std::vector<TLorentzVector> tausT_FESDown; std::vector<Int_t> tausT_FESDown_index; std::vector<Int_t> tausT_FESDown_decayMode; std::vector<Int_t> tausT_FESDown_genPartFlav;
    std::vector<TLorentzVector> jets; std::vector<Int_t> jets_index; std::vector<Int_t> jets_flavour;  std::vector<Double_t> jets_btags;
    std::vector<TLorentzVector> jets_smearedUp; std::vector<Int_t> jets_index_smearedUp; std::vector<Int_t> jets_flavour_smearedUp;  std::vector<Double_t> jets_btags_smearedUp;
    std::vector<TLorentzVector> jets_smearedDown; std::vector<Int_t> jets_index_smearedDown; std::vector<Int_t> jets_flavour_smearedDown;  std::vector<Double_t> jets_btags_smearedDown;
    std::vector<TLorentzVector> bjetsL; std::vector<Int_t> bjetsL_index; std::vector<Int_t> bjetsL_flavour; std::vector<Double_t> bjetsL_btags;
    std::vector<TLorentzVector> bjetsL_smearedUp; std::vector<Int_t> bjetsL_index_smearedUp; std::vector<Int_t> bjetsL_flavour_smearedUp; std::vector<Double_t> bjetsL_btags_smearedUp;
    std::vector<TLorentzVector> bjetsL_smearedDown; std::vector<Int_t> bjetsL_index_smearedDown; std::vector<Int_t> bjetsL_flavour_smearedDown; std::vector<Double_t> bjetsL_btags_smearedDown;
    std::vector<TLorentzVector> bjetsM; std::vector<Int_t> bjetsM_index; std::vector<Int_t> bjetsM_flavour; std::vector<Double_t> bjetsM_btags;
    std::vector<TLorentzVector> bjetsM_smearedUp; std::vector<Int_t> bjetsM_index_smearedUp; std::vector<Int_t> bjetsM_flavour_smearedUp; std::vector<Double_t> bjetsM_btags_smearedUp;
    std::vector<TLorentzVector> bjetsM_smearedDown; std::vector<Int_t> bjetsM_index_smearedDown; std::vector<Int_t> bjetsM_flavour_smearedDown; std::vector<Double_t> bjetsM_btags_smearedDown;
    std::vector<TLorentzVector> bjetsT; std::vector<Int_t> bjetsT_index; std::vector<Int_t> bjetsT_flavour; std::vector<Double_t> bjetsT_btags;
    std::vector<TLorentzVector> bjetsT_smearedUp; std::vector<Int_t> bjetsT_index_smearedUp; std::vector<Int_t> bjetsT_flavour_smearedUp; std::vector<Double_t> bjetsT_btags_smearedUp;
    std::vector<TLorentzVector> bjetsT_smearedDown; std::vector<Int_t> bjetsT_index_smearedDown; std::vector<Int_t> bjetsT_flavour_smearedDown; std::vector<Double_t> bjetsT_btags_smearedDown;
    std::vector<TLorentzVector> forwardJets; std::vector<Int_t> forwardJets_index; std::vector<Int_t> forwardJets_flavour; std::vector<Double_t> forwardJets_btags;
    std::vector<TLorentzVector>  nonbjetsL;
    std::vector<TLorentzVector>  nonbjetsM;
    std::vector<TLorentzVector>  nonbjetsT;
    // std::vector<TLorentzVector> ; std::vector<Int_t> ;
    // std::vector<TLorentzVector> ; std::vector<Int_t> ;
    // std::vector<TLorentzVector> ; std::vector<Int_t> ;
    // std::vector<TLorentzVector> ; std::vector<Int_t> ;
    std::vector<Double_t> patElectron_charge_;
    // std::vector<Double_t> patElectron_charge_;
    std::vector<Double_t> Tau_charge_;
    std::vector<Double_t> Muon_charge_;
    Double_t Met_pt;
    Double_t Met_phi;
    std::vector<TLorentzVector> tops_toptagger;

    std::vector<TLorentzVector> genTaus; 
    std::vector<TLorentzVector> genEles;
    std::vector<TLorentzVector> genMuons;
    std::vector<Float_t> jetSmearingFactors;
    std::vector<Float_t> jetSmearingFactorsUp;
    std::vector<Float_t> jetSmearingFactorsDown;
    std::vector<Float_t> tauESFactors;
    std::vector<Float_t> tauESFactorsUp;
    std::vector<Float_t> tauESFactorsDown;
    std::vector<Float_t> tauFESFactors;
    std::vector<Float_t> tauFESFactorsUp;
    std::vector<Float_t> tauFESFactorsDown;

    //weight
    Double_t EVENT_prefireWeight_;
    Double_t PUWeight_;
    Double_t PUWeight_Up;
    Double_t PUWeight_Down;
    Double_t EVENT_genWeight_;

    //functions I added
     void SelectMuons(std::vector<TLorentzVector> &SelectedMuons, std::vector<Int_t> &SelectedMuonsIndex, const Int_t type);
     void SelectTaus(std::vector<TLorentzVector> &SelectedTaus, std::vector<Float_t> tauTESFactors, std::vector<Float_t> tauFESFactors, std::vector<Int_t> &SelectedTausIndex, std::vector<Int_t> &SelectedTausDecayMode, std::vector<Int_t> &SelectedTausGenPartFlav, const Int_t TauWP, const std::vector<TLorentzVector> LeptonsMVAL);
     void SelectTops(std::vector<TLorentzVector> &SelectedTops);
     void SelectJets(const Int_t jetType, const bool deepJet, std::vector<Float_t> jetSmearingFactors, std::vector<TLorentzVector> &SelectedJets, std::vector<Double_t> &SelectedJetsBTags, std::vector<Int_t>  &SelectedJetsIndex, std::vector<Int_t>  &SelectedJetsFlavour, const Int_t SysJes, const Int_t SysJer, const std::vector<TLorentzVector> LeptonsMVAF, const std::vector<TLorentzVector> SelectedTausL );
     void MetCorrection(Int_t SysJes, Int_t SysJer, Double_t &MET);
     void selectGenTaus( std::vector<TLorentzVector> &genTaus );
     void selectGenEles( std::vector<TLorentzVector> &genEles );
     void selectGenMuons( std::vector<TLorentzVector> &genMuons );
     void SelectElectronsMVA(std::vector<TLorentzVector> &SelectedElectrons, std::vector<Int_t> &SelectedElectronsIndex,const Int_t type);

     void makeBranch( TTree*  tree );
     void getRunRange( TTree* fChain );
     void intializaTreeBranches( const Bool_t isdata, const TString dataset );

     void copyHLT_new( const Bool_t isdata, const TString dataset );
	 void copyFlags();
	 void initializeBrancheValues();
    void setupInputFile( const Bool_t isdata );
    void getOptionFromRunMacro( const TString option ); 
    void calJetSmearFactors( const Bool_t isdata );
    void setupTauSFTool( const Bool_t isdata);
   void calTauSF( const Bool_t isdata );










   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<UInt_t> run = {fReader, "run"};
   TTreeReaderValue<UInt_t> luminosityBlock = {fReader, "luminosityBlock"};
   TTreeReaderValue<ULong64_t> event = {fReader, "event"};
   /*
   TTreeReaderValue<Float_t> HTXS_Higgs_pt = {fReader, "HTXS_Higgs_pt"};
   TTreeReaderValue<Float_t> HTXS_Higgs_y = {fReader, "HTXS_Higgs_y"};
   TTreeReaderValue<Int_t> HTXS_stage1_1_cat_pTjet25GeV = {fReader, "HTXS_stage1_1_cat_pTjet25GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_1_cat_pTjet30GeV = {fReader, "HTXS_stage1_1_cat_pTjet30GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_1_fine_cat_pTjet25GeV = {fReader, "HTXS_stage1_1_fine_cat_pTjet25GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_1_fine_cat_pTjet30GeV = {fReader, "HTXS_stage1_1_fine_cat_pTjet30GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_2_cat_pTjet25GeV = {fReader, "HTXS_stage1_2_cat_pTjet25GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_2_cat_pTjet30GeV = {fReader, "HTXS_stage1_2_cat_pTjet30GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_2_fine_cat_pTjet25GeV = {fReader, "HTXS_stage1_2_fine_cat_pTjet25GeV"};
   TTreeReaderValue<Int_t> HTXS_stage1_2_fine_cat_pTjet30GeV = {fReader, "HTXS_stage1_2_fine_cat_pTjet30GeV"};
   TTreeReaderValue<Int_t> HTXS_stage_0 = {fReader, "HTXS_stage_0"};
   TTreeReaderValue<Int_t> HTXS_stage_1_pTjet25 = {fReader, "HTXS_stage_1_pTjet25"};
   TTreeReaderValue<Int_t> HTXS_stage_1_pTjet30 = {fReader, "HTXS_stage_1_pTjet30"};
   TTreeReaderValue<UChar_t> HTXS_njets25 = {fReader, "HTXS_njets25"};
   TTreeReaderValue<UChar_t> HTXS_njets30 = {fReader, "HTXS_njets30"};
   // TTreeReaderValue<UInt_t> nboostedTau = {fReader, "nboostedTau"};
   */
   //???2016preVFP has not this branch
   // TTreeReaderArray<Float_t> boostedTau_chargedIso = {fReader, "boostedTau_chargedIso"};
   // TTreeReaderArray<Float_t> boostedTau_eta = {fReader, "boostedTau_eta"};
   // TTreeReaderArray<Float_t> boostedTau_leadTkDeltaEta = {fReader, "boostedTau_leadTkDeltaEta"};
   // TTreeReaderArray<Float_t> boostedTau_leadTkDeltaPhi = {fReader, "boostedTau_leadTkDeltaPhi"};
   // TTreeReaderArray<Float_t> boostedTau_leadTkPtOverTauPt = {fReader, "boostedTau_leadTkPtOverTauPt"};
   // TTreeReaderArray<Float_t> boostedTau_mass = {fReader, "boostedTau_mass"};
   // TTreeReaderArray<Float_t> boostedTau_neutralIso = {fReader, "boostedTau_neutralIso"};
   // TTreeReaderArray<Float_t> boostedTau_phi = {fReader, "boostedTau_phi"};
   // TTreeReaderArray<Float_t> boostedTau_photonsOutsideSignalCone = {fReader, "boostedTau_photonsOutsideSignalCone"};
   // TTreeReaderArray<Float_t> boostedTau_pt = {fReader, "boostedTau_pt"};
   // TTreeReaderArray<Float_t> boostedTau_puCorr = {fReader, "boostedTau_puCorr"};
   // TTreeReaderArray<Float_t> boostedTau_rawAntiEle2018 = {fReader, "boostedTau_rawAntiEle2018"};
   // TTreeReaderArray<Float_t> boostedTau_rawIso = {fReader, "boostedTau_rawIso"};
   // TTreeReaderArray<Float_t> boostedTau_rawIsodR03 = {fReader, "boostedTau_rawIsodR03"};
   // TTreeReaderArray<Float_t> boostedTau_rawMVAnewDM2017v2 = {fReader, "boostedTau_rawMVAnewDM2017v2"};
   // TTreeReaderArray<Float_t> boostedTau_rawMVAoldDM2017v2 = {fReader, "boostedTau_rawMVAoldDM2017v2"};
   // TTreeReaderArray<Float_t> boostedTau_rawMVAoldDMdR032017v2 = {fReader, "boostedTau_rawMVAoldDMdR032017v2"};
   // TTreeReaderArray<Int_t> boostedTau_charge = {fReader, "boostedTau_charge"};
   // TTreeReaderArray<Int_t> boostedTau_decayMode = {fReader, "boostedTau_decayMode"};
   // TTreeReaderArray<Int_t> boostedTau_jetIdx = {fReader, "boostedTau_jetIdx"};
   // TTreeReaderArray<Int_t> boostedTau_rawAntiEleCat2018 = {fReader, "boostedTau_rawAntiEleCat2018"};
   // TTreeReaderArray<UChar_t> boostedTau_idAntiEle2018 = {fReader, "boostedTau_idAntiEle2018"};
   // TTreeReaderArray<UChar_t> boostedTau_idAntiMu = {fReader, "boostedTau_idAntiMu"};
   // TTreeReaderArray<UChar_t> boostedTau_idMVAnewDM2017v2 = {fReader, "boostedTau_idMVAnewDM2017v2"};
   // TTreeReaderArray<UChar_t> boostedTau_idMVAoldDM2017v2 = {fReader, "boostedTau_idMVAoldDM2017v2"};
   // TTreeReaderArray<UChar_t> boostedTau_idMVAoldDMdR032017v2 = {fReader, "boostedTau_idMVAoldDMdR032017v2"};
//    TTreeReaderValue<Float_t> btagWeight_CSVV2 = {fReader, "btagWeight_CSVV2"};//???not in data
//    TTreeReaderValue<Float_t> btagWeight_DeepCSVB = {fReader, "btagWeight_DeepCSVB"};//???not in data?
   /*
   TTreeReaderValue<Float_t> CaloMET_phi = {fReader, "CaloMET_phi"};
   TTreeReaderValue<Float_t> CaloMET_pt = {fReader, "CaloMET_pt"};
   TTreeReaderValue<Float_t> CaloMET_sumEt = {fReader, "CaloMET_sumEt"};
   TTreeReaderValue<Float_t> ChsMET_phi = {fReader, "ChsMET_phi"};
   TTreeReaderValue<Float_t> ChsMET_pt = {fReader, "ChsMET_pt"};
   TTreeReaderValue<Float_t> ChsMET_sumEt = {fReader, "ChsMET_sumEt"};
   TTreeReaderValue<UInt_t> nCorrT1METJet = {fReader, "nCorrT1METJet"};
   TTreeReaderArray<Float_t> CorrT1METJet_area = {fReader, "CorrT1METJet_area"};
   TTreeReaderArray<Float_t> CorrT1METJet_eta = {fReader, "CorrT1METJet_eta"};
   TTreeReaderArray<Float_t> CorrT1METJet_muonSubtrFactor = {fReader, "CorrT1METJet_muonSubtrFactor"};
   TTreeReaderArray<Float_t> CorrT1METJet_phi = {fReader, "CorrT1METJet_phi"};
   TTreeReaderArray<Float_t> CorrT1METJet_rawPt = {fReader, "CorrT1METJet_rawPt"};
   TTreeReaderValue<Float_t> DeepMETResolutionTune_phi = {fReader, "DeepMETResolutionTune_phi"};
   TTreeReaderValue<Float_t> DeepMETResolutionTune_pt = {fReader, "DeepMETResolutionTune_pt"};
   TTreeReaderValue<Float_t> DeepMETResponseTune_phi = {fReader, "DeepMETResponseTune_phi"};
   TTreeReaderValue<Float_t> DeepMETResponseTune_pt = {fReader, "DeepMETResponseTune_pt"};
   */
   TTreeReaderValue<UInt_t> nElectron = {fReader, "nElectron"};
   TTreeReaderArray<Float_t> Electron_dEscaleDown = {fReader, "Electron_dEscaleDown"};
   TTreeReaderArray<Float_t> Electron_dEscaleUp = {fReader, "Electron_dEscaleUp"};
   TTreeReaderArray<Float_t> Electron_dEsigmaDown = {fReader, "Electron_dEsigmaDown"};
   TTreeReaderArray<Float_t> Electron_dEsigmaUp = {fReader, "Electron_dEsigmaUp"};
   TTreeReaderArray<Float_t> Electron_deltaEtaSC = {fReader, "Electron_deltaEtaSC"};
   TTreeReaderArray<Float_t> Electron_dr03EcalRecHitSumEt = {fReader, "Electron_dr03EcalRecHitSumEt"};
   TTreeReaderArray<Float_t> Electron_dr03HcalDepth1TowerSumEt = {fReader, "Electron_dr03HcalDepth1TowerSumEt"};
   TTreeReaderArray<Float_t> Electron_dr03TkSumPt = {fReader, "Electron_dr03TkSumPt"};
   TTreeReaderArray<Float_t> Electron_dr03TkSumPtHEEP = {fReader, "Electron_dr03TkSumPtHEEP"};
   TTreeReaderArray<Float_t> Electron_dxy = {fReader, "Electron_dxy"};
   TTreeReaderArray<Float_t> Electron_dxyErr = {fReader, "Electron_dxyErr"};
   TTreeReaderArray<Float_t> Electron_dz = {fReader, "Electron_dz"};
   TTreeReaderArray<Float_t> Electron_dzErr = {fReader, "Electron_dzErr"};
   TTreeReaderArray<Float_t> Electron_eCorr = {fReader, "Electron_eCorr"};
   TTreeReaderArray<Float_t> Electron_eInvMinusPInv = {fReader, "Electron_eInvMinusPInv"};
   TTreeReaderArray<Float_t> Electron_energyErr = {fReader, "Electron_energyErr"};
   TTreeReaderArray<Float_t> Electron_eta = {fReader, "Electron_eta"};
   TTreeReaderArray<Float_t> Electron_hoe = {fReader, "Electron_hoe"};
   TTreeReaderArray<Float_t> Electron_ip3d = {fReader, "Electron_ip3d"};
   TTreeReaderArray<Float_t> Electron_jetPtRelv2 = {fReader, "Electron_jetPtRelv2"};
   TTreeReaderArray<Float_t> Electron_jetRelIso = {fReader, "Electron_jetRelIso"};
   TTreeReaderArray<Float_t> Electron_mass = {fReader, "Electron_mass"};
   TTreeReaderArray<Float_t> Electron_miniPFRelIso_all = {fReader, "Electron_miniPFRelIso_all"};
   TTreeReaderArray<Float_t> Electron_miniPFRelIso_chg = {fReader, "Electron_miniPFRelIso_chg"};
   TTreeReaderArray<Float_t> Electron_mvaFall17V2Iso = {fReader, "Electron_mvaFall17V2Iso"};
   TTreeReaderArray<Float_t> Electron_mvaFall17V2noIso = {fReader, "Electron_mvaFall17V2noIso"};
   TTreeReaderArray<Float_t> Electron_pfRelIso03_all = {fReader, "Electron_pfRelIso03_all"};
   TTreeReaderArray<Float_t> Electron_pfRelIso03_chg = {fReader, "Electron_pfRelIso03_chg"};
   TTreeReaderArray<Float_t> Electron_phi = {fReader, "Electron_phi"};
   TTreeReaderArray<Float_t> Electron_pt = {fReader, "Electron_pt"};
   TTreeReaderArray<Float_t> Electron_r9 = {fReader, "Electron_r9"};
   TTreeReaderArray<Float_t> Electron_scEtOverPt = {fReader, "Electron_scEtOverPt"};
   TTreeReaderArray<Float_t> Electron_sieie = {fReader, "Electron_sieie"};
   TTreeReaderArray<Float_t> Electron_sip3d = {fReader, "Electron_sip3d"};
   TTreeReaderArray<Float_t> Electron_mvaTTH = {fReader, "Electron_mvaTTH"};
   TTreeReaderArray<Int_t> Electron_charge = {fReader, "Electron_charge"};
   TTreeReaderArray<Int_t> Electron_cutBased = {fReader, "Electron_cutBased"};
   TTreeReaderArray<Int_t> Electron_jetIdx = {fReader, "Electron_jetIdx"};
   TTreeReaderArray<Int_t> Electron_pdgId = {fReader, "Electron_pdgId"};
   TTreeReaderArray<Int_t> Electron_photonIdx = {fReader, "Electron_photonIdx"};
   TTreeReaderArray<Int_t> Electron_tightCharge = {fReader, "Electron_tightCharge"};
   TTreeReaderArray<Int_t> Electron_vidNestedWPBitmap = {fReader, "Electron_vidNestedWPBitmap"};
   TTreeReaderArray<Int_t> Electron_vidNestedWPBitmapHEEP = {fReader, "Electron_vidNestedWPBitmapHEEP"};
   TTreeReaderArray<Bool_t> Electron_convVeto = {fReader, "Electron_convVeto"};
   TTreeReaderArray<Bool_t> Electron_cutBased_HEEP = {fReader, "Electron_cutBased_HEEP"};
   TTreeReaderArray<Bool_t> Electron_isPFcand = {fReader, "Electron_isPFcand"};
   TTreeReaderArray<UChar_t> Electron_jetNDauCharged = {fReader, "Electron_jetNDauCharged"};
   TTreeReaderArray<UChar_t> Electron_lostHits = {fReader, "Electron_lostHits"};
   TTreeReaderArray<Bool_t> Electron_mvaFall17V2Iso_WP80 = {fReader, "Electron_mvaFall17V2Iso_WP80"};
   TTreeReaderArray<Bool_t> Electron_mvaFall17V2Iso_WP90 = {fReader, "Electron_mvaFall17V2Iso_WP90"};
   TTreeReaderArray<Bool_t> Electron_mvaFall17V2Iso_WPL = {fReader, "Electron_mvaFall17V2Iso_WPL"};
   TTreeReaderArray<Bool_t> Electron_mvaFall17V2noIso_WP80 = {fReader, "Electron_mvaFall17V2noIso_WP80"};
   TTreeReaderArray<Bool_t> Electron_mvaFall17V2noIso_WP90 = {fReader, "Electron_mvaFall17V2noIso_WP90"};
   TTreeReaderArray<Bool_t> Electron_mvaFall17V2noIso_WPL = {fReader, "Electron_mvaFall17V2noIso_WPL"};
   TTreeReaderArray<UChar_t> Electron_seedGain = {fReader, "Electron_seedGain"};
   /*
   TTreeReaderValue<UInt_t> nFatJet = {fReader, "nFatJet"};
   TTreeReaderArray<Float_t> FatJet_area = {fReader, "FatJet_area"};
   TTreeReaderArray<Float_t> FatJet_btagCSVV2 = {fReader, "FatJet_btagCSVV2"};
   TTreeReaderArray<Float_t> FatJet_btagDDBvLV2 = {fReader, "FatJet_btagDDBvLV2"};
   TTreeReaderArray<Float_t> FatJet_btagDDCvBV2 = {fReader, "FatJet_btagDDCvBV2"};
   TTreeReaderArray<Float_t> FatJet_btagDDCvLV2 = {fReader, "FatJet_btagDDCvLV2"};
   TTreeReaderArray<Float_t> FatJet_btagDeepB = {fReader, "FatJet_btagDeepB"};
   TTreeReaderArray<Float_t> FatJet_btagHbb = {fReader, "FatJet_btagHbb"};
   TTreeReaderArray<Float_t> FatJet_deepTagMD_H4qvsQCD = {fReader, "FatJet_deepTagMD_H4qvsQCD"};
   TTreeReaderArray<Float_t> FatJet_deepTagMD_HbbvsQCD = {fReader, "FatJet_deepTagMD_HbbvsQCD"};
   TTreeReaderArray<Float_t> FatJet_deepTagMD_TvsQCD = {fReader, "FatJet_deepTagMD_TvsQCD"};
   TTreeReaderArray<Float_t> FatJet_deepTagMD_WvsQCD = {fReader, "FatJet_deepTagMD_WvsQCD"};
   TTreeReaderArray<Float_t> FatJet_deepTagMD_ZHbbvsQCD = {fReader, "FatJet_deepTagMD_ZHbbvsQCD"};
   TTreeReaderArray<Float_t> FatJet_deepTagMD_ZHccvsQCD = {fReader, "FatJet_deepTagMD_ZHccvsQCD"};
   TTreeReaderArray<Float_t> FatJet_deepTagMD_ZbbvsQCD = {fReader, "FatJet_deepTagMD_ZbbvsQCD"};
   TTreeReaderArray<Float_t> FatJet_deepTagMD_ZvsQCD = {fReader, "FatJet_deepTagMD_ZvsQCD"};
   TTreeReaderArray<Float_t> FatJet_deepTagMD_bbvsLight = {fReader, "FatJet_deepTagMD_bbvsLight"};
   TTreeReaderArray<Float_t> FatJet_deepTagMD_ccvsLight = {fReader, "FatJet_deepTagMD_ccvsLight"};
   TTreeReaderArray<Float_t> FatJet_deepTag_H = {fReader, "FatJet_deepTag_H"};
   TTreeReaderArray<Float_t> FatJet_deepTag_QCD = {fReader, "FatJet_deepTag_QCD"};
   TTreeReaderArray<Float_t> FatJet_deepTag_QCDothers = {fReader, "FatJet_deepTag_QCDothers"};
   TTreeReaderArray<Float_t> FatJet_deepTag_TvsQCD = {fReader, "FatJet_deepTag_TvsQCD"};
   TTreeReaderArray<Float_t> FatJet_deepTag_WvsQCD = {fReader, "FatJet_deepTag_WvsQCD"};
   TTreeReaderArray<Float_t> FatJet_deepTag_ZvsQCD = {fReader, "FatJet_deepTag_ZvsQCD"};
   TTreeReaderArray<Float_t> FatJet_eta = {fReader, "FatJet_eta"};
   TTreeReaderArray<Float_t> FatJet_mass = {fReader, "FatJet_mass"};
   TTreeReaderArray<Float_t> FatJet_msoftdrop = {fReader, "FatJet_msoftdrop"};
   TTreeReaderArray<Float_t> FatJet_n2b1 = {fReader, "FatJet_n2b1"};
   TTreeReaderArray<Float_t> FatJet_n3b1 = {fReader, "FatJet_n3b1"};
   TTreeReaderArray<Float_t> FatJet_particleNetMD_QCD = {fReader, "FatJet_particleNetMD_QCD"};
   TTreeReaderArray<Float_t> FatJet_particleNetMD_Xbb = {fReader, "FatJet_particleNetMD_Xbb"};
   TTreeReaderArray<Float_t> FatJet_particleNetMD_Xcc = {fReader, "FatJet_particleNetMD_Xcc"};
   TTreeReaderArray<Float_t> FatJet_particleNetMD_Xqq = {fReader, "FatJet_particleNetMD_Xqq"};
   TTreeReaderArray<Float_t> FatJet_particleNet_H4qvsQCD = {fReader, "FatJet_particleNet_H4qvsQCD"};
   TTreeReaderArray<Float_t> FatJet_particleNet_HbbvsQCD = {fReader, "FatJet_particleNet_HbbvsQCD"};
   TTreeReaderArray<Float_t> FatJet_particleNet_HccvsQCD = {fReader, "FatJet_particleNet_HccvsQCD"};
   TTreeReaderArray<Float_t> FatJet_particleNet_QCD = {fReader, "FatJet_particleNet_QCD"};
   TTreeReaderArray<Float_t> FatJet_particleNet_TvsQCD = {fReader, "FatJet_particleNet_TvsQCD"};
   TTreeReaderArray<Float_t> FatJet_particleNet_WvsQCD = {fReader, "FatJet_particleNet_WvsQCD"};
   TTreeReaderArray<Float_t> FatJet_particleNet_ZvsQCD = {fReader, "FatJet_particleNet_ZvsQCD"};
   TTreeReaderArray<Float_t> FatJet_particleNet_mass = {fReader, "FatJet_particleNet_mass"};
   TTreeReaderArray<Float_t> FatJet_phi = {fReader, "FatJet_phi"};
   TTreeReaderArray<Float_t> FatJet_pt = {fReader, "FatJet_pt"};
   TTreeReaderArray<Float_t> FatJet_rawFactor = {fReader, "FatJet_rawFactor"};
   TTreeReaderArray<Float_t> FatJet_tau1 = {fReader, "FatJet_tau1"};
   TTreeReaderArray<Float_t> FatJet_tau2 = {fReader, "FatJet_tau2"};
   TTreeReaderArray<Float_t> FatJet_tau3 = {fReader, "FatJet_tau3"};
   TTreeReaderArray<Float_t> FatJet_tau4 = {fReader, "FatJet_tau4"};
   TTreeReaderArray<Float_t> FatJet_lsf3 = {fReader, "FatJet_lsf3"};
   TTreeReaderArray<Int_t> FatJet_jetId = {fReader, "FatJet_jetId"};
   TTreeReaderArray<Int_t> FatJet_subJetIdx1 = {fReader, "FatJet_subJetIdx1"};
   TTreeReaderArray<Int_t> FatJet_subJetIdx2 = {fReader, "FatJet_subJetIdx2"};
   TTreeReaderArray<Int_t> FatJet_electronIdx3SJ = {fReader, "FatJet_electronIdx3SJ"};
   TTreeReaderArray<Int_t> FatJet_muonIdx3SJ = {fReader, "FatJet_muonIdx3SJ"};
   TTreeReaderArray<UChar_t> FatJet_nConstituents = {fReader, "FatJet_nConstituents"};
   TTreeReaderValue<UInt_t> nFsrPhoton = {fReader, "nFsrPhoton"};
   TTreeReaderArray<Float_t> FsrPhoton_dROverEt2 = {fReader, "FsrPhoton_dROverEt2"};
   TTreeReaderArray<Float_t> FsrPhoton_eta = {fReader, "FsrPhoton_eta"};
   TTreeReaderArray<Float_t> FsrPhoton_phi = {fReader, "FsrPhoton_phi"};
   TTreeReaderArray<Float_t> FsrPhoton_pt = {fReader, "FsrPhoton_pt"};
   TTreeReaderArray<Float_t> FsrPhoton_relIso03 = {fReader, "FsrPhoton_relIso03"};
   TTreeReaderArray<Int_t> FsrPhoton_muonIdx = {fReader, "FsrPhoton_muonIdx"};
   */
//    TTreeReaderValue<UInt_t> nGenJetAK8 = {fReader, "nGenJetAK8"};
//    TTreeReaderArray<Float_t> GenJetAK8_eta = {fReader, "GenJetAK8_eta"};
//    TTreeReaderArray<Float_t> GenJetAK8_mass = {fReader, "GenJetAK8_mass"};
//    TTreeReaderArray<Float_t> GenJetAK8_phi = {fReader, "GenJetAK8_phi"};
//    TTreeReaderArray<Float_t> GenJetAK8_pt = {fReader, "GenJetAK8_pt"};
//    TTreeReaderValue<UInt_t> nGenJet = {fReader, "nGenJet"};
//    TTreeReaderArray<Float_t> GenJet_eta = {fReader, "GenJet_eta"};
   TTreeReaderArray<Float_t> GenJet_eta = { fReader, "Electron_dz" } ;//!!!need to overwrite for MC!!!
   //protential problem of overloading!!! tested that no overloading.
//    TTreeReaderArray<Float_t> GenJet_mass = {fReader, "GenJet_mass"};

   TTreeReaderArray<Float_t> GenJet_phi = {fReader, "Electron_dz"};
   TTreeReaderArray<Float_t> GenJet_pt = {fReader, "Electron_dz"};
   TTreeReaderValue<UInt_t> nGenPart = {fReader, "nElectron"};
   TTreeReaderArray<Float_t> GenPart_eta = {fReader, "Electron_dz"};
   TTreeReaderArray<Float_t> GenPart_mass = {fReader, "Electron_dz"};
   TTreeReaderArray<Float_t> GenPart_phi = {fReader, "Electron_dz"};
   TTreeReaderArray<Float_t> GenPart_pt = {fReader, "Electron_dz"};
   TTreeReaderArray<Int_t> GenPart_genPartIdxMother = {fReader, "Electron_charge"};
   TTreeReaderArray<Int_t> GenPart_pdgId = {fReader, "Electron_charge"};
   
//    TTreeReaderArray<Int_t> GenPart_status = {fReader, "GenPart_status"};
//    TTreeReaderArray<Int_t> GenPart_statusFlags = {fReader, "GenPart_statusFlags"};
//    TTreeReaderValue<UInt_t> nSubGenJetAK8 = {fReader, "nSubGenJetAK8"};
//    TTreeReaderArray<Float_t> SubGenJetAK8_eta = {fReader, "SubGenJetAK8_eta"};
//    TTreeReaderArray<Float_t> SubGenJetAK8_mass = {fReader, "SubGenJetAK8_mass"};
//    TTreeReaderArray<Float_t> SubGenJetAK8_phi = {fReader, "SubGenJetAK8_phi"};
//    TTreeReaderArray<Float_t> SubGenJetAK8_pt = {fReader, "SubGenJetAK8_pt"};
//    TTreeReaderValue<Float_t> Generator_binvar = {fReader, "Generator_binvar"};
//    TTreeReaderValue<Float_t> Generator_scalePDF = {fReader, "Generator_scalePDF"};
   TTreeReaderValue<Float_t> Generator_weight = {fReader, "L1PreFiringWeight_Nom"};
//    TTreeReaderValue<Float_t> Generator_x1 = {fReader, "Generator_x1"};
//    TTreeReaderValue<Float_t> Generator_x2 = {fReader, "Generator_x2"};
//    TTreeReaderValue<Float_t> Generator_xpdf1 = {fReader, "Generator_xpdf1"};
//    TTreeReaderValue<Float_t> Generator_xpdf2 = {fReader, "Generator_xpdf2"};
//    TTreeReaderValue<Int_t> Generator_id1 = {fReader, "Generator_id1"};
//    TTreeReaderValue<Int_t> Generator_id2 = {fReader, "Generator_id2"};
//    TTreeReaderValue<Float_t> GenVtx_x = {fReader, "GenVtx_x"};:
//    TTreeReaderValue<Float_t> GenVtx_y = {fReader, "GenVtx_y"};
//    TTreeReaderValue<Float_t> GenVtx_z = {fReader, "GenVtx_z"};
//    TTreeReaderValue<UInt_t> nGenVisTau = {fReader, "nGenVisTau"};
//    TTreeReaderArray<Float_t> GenVisTau_eta = {fReader, "GenVisTau_eta"};
//    TTreeReaderArray<Float_t> GenVisTau_mass = {fReader, "GenVisTau_mass"};
//    TTreeReaderArray<Float_t> GenVisTau_phi = {fReader, "GenVisTau_phi"};
//    TTreeReaderArray<Float_t> GenVisTau_pt = {fReader, "GenVisTau_pt"};
//    TTreeReaderArray<Int_t> GenVisTau_charge = {fReader, "GenVisTau_charge"};
//    TTreeReaderArray<Int_t> GenVisTau_genPartIdxMother = {fReader, "GenVisTau_genPartIdxMother"};
//    TTreeReaderArray<Int_t> GenVisTau_status = {fReader, "GenVisTau_status"};
   TTreeReaderValue<Float_t> genWeight = {fReader, "L1PreFiringWeight_Nom"};
//    TTreeReaderValue<Float_t> LHEWeight_originalXWGTUP = {fReader, "LHEWeight_originalXWGTUP"};
//    TTreeReaderValue<UInt_t> nLHEPdfWeight = {fReader, "nLHEPdfWeight"};
//    TTreeReaderArray<Float_t> LHEPdfWeight = {fReader, "LHEPdfWeight"};
//    TTreeReaderValue<UInt_t> nLHEReweightingWeight = {fReader, "nLHEReweightingWeight"};
//    TTreeReaderArray<Float_t> LHEReweightingWeight = {fReader, "LHEReweightingWeight"};
//    TTreeReaderValue<UInt_t> nLHEScaleWeight = {fReader, "nLHEScaleWeight"};
//    TTreeReaderArray<Float_t> LHEScaleWeight = {fReader, "LHEScaleWeight"};
//    TTreeReaderValue<UInt_t> nPSWeight = {fReader, "nPSWeight"};
//    TTreeReaderArray<Float_t> PSWeight = {fReader, "PSWeight"};
//    TTreeReaderValue<UInt_t> nIsoTrack = {fReader, "nIsoTrack"};
//    TTreeReaderArray<Float_t> IsoTrack_dxy = {fReader, "IsoTrack_dxy"};
//    TTreeReaderArray<Float_t> IsoTrack_dz = {fReader, "IsoTrack_dz"};
//    TTreeReaderArray<Float_t> IsoTrack_eta = {fReader, "IsoTrack_eta"};
//    TTreeReaderArray<Float_t> IsoTrack_pfRelIso03_all = {fReader, "IsoTrack_pfRelIso03_all"};
//    TTreeReaderArray<Float_t> IsoTrack_pfRelIso03_chg = {fReader, "IsoTrack_pfRelIso03_chg"};
//    TTreeReaderArray<Float_t> IsoTrack_phi = {fReader, "IsoTrack_phi"};
//    TTreeReaderArray<Float_t> IsoTrack_pt = {fReader, "IsoTrack_pt"};
//    TTreeReaderArray<Float_t> IsoTrack_miniPFRelIso_all = {fReader, "IsoTrack_miniPFRelIso_all"};
//    TTreeReaderArray<Float_t> IsoTrack_miniPFRelIso_chg = {fReader, "IsoTrack_miniPFRelIso_chg"};
//    TTreeReaderArray<Int_t> IsoTrack_charge = {fReader, "IsoTrack_charge"};
//    TTreeReaderArray<Int_t> IsoTrack_fromPV = {fReader, "IsoTrack_fromPV"};
//    TTreeReaderArray<Int_t> IsoTrack_pdgId = {fReader, "IsoTrack_pdgId"};
//    TTreeReaderArray<Bool_t> IsoTrack_isHighPurityTrack = {fReader, "IsoTrack_isHighPurityTrack"};
//    TTreeReaderArray<Bool_t> IsoTrack_isPFcand = {fReader, "IsoTrack_isPFcand"};
//    TTreeReaderArray<Bool_t> IsoTrack_isFromLostTrack = {fReader, "IsoTrack_isFromLostTrack"};
   TTreeReaderValue<UInt_t> nJet = {fReader, "nJet"};
   TTreeReaderArray<Float_t> Jet_area = {fReader, "Jet_area"};
   TTreeReaderArray<Float_t> Jet_btagCSVV2 = {fReader, "Jet_btagCSVV2"};
   TTreeReaderArray<Float_t> Jet_btagDeepB = {fReader, "Jet_btagDeepB"};
   TTreeReaderArray<Float_t> Jet_btagDeepCvB = {fReader, "Jet_btagDeepCvB"};
   TTreeReaderArray<Float_t> Jet_btagDeepCvL = {fReader, "Jet_btagDeepCvL"};
   TTreeReaderArray<Float_t> Jet_btagDeepFlavB = {fReader, "Jet_btagDeepFlavB"};
   TTreeReaderArray<Float_t> Jet_btagDeepFlavCvB = {fReader, "Jet_btagDeepFlavCvB"};
   TTreeReaderArray<Float_t> Jet_btagDeepFlavCvL = {fReader, "Jet_btagDeepFlavCvL"};
   TTreeReaderArray<Float_t> Jet_btagDeepFlavQG = {fReader, "Jet_btagDeepFlavQG"};
   TTreeReaderArray<Float_t> Jet_chEmEF = {fReader, "Jet_chEmEF"};
   TTreeReaderArray<Float_t> Jet_chFPV0EF = {fReader, "Jet_chFPV0EF"};
   TTreeReaderArray<Float_t> Jet_chHEF = {fReader, "Jet_chHEF"};
   TTreeReaderArray<Float_t> Jet_eta = {fReader, "Jet_eta"};
   TTreeReaderArray<Float_t> Jet_hfsigmaEtaEta = {fReader, "Jet_hfsigmaEtaEta"};
   TTreeReaderArray<Float_t> Jet_hfsigmaPhiPhi = {fReader, "Jet_hfsigmaPhiPhi"};
   TTreeReaderArray<Float_t> Jet_mass = {fReader, "Jet_mass"};
   TTreeReaderArray<Float_t> Jet_muEF = {fReader, "Jet_muEF"};
   TTreeReaderArray<Float_t> Jet_muonSubtrFactor = {fReader, "Jet_muonSubtrFactor"};
   TTreeReaderArray<Float_t> Jet_neEmEF = {fReader, "Jet_neEmEF"};
   TTreeReaderArray<Float_t> Jet_neHEF = {fReader, "Jet_neHEF"};
   TTreeReaderArray<Float_t> Jet_phi = {fReader, "Jet_phi"};
   TTreeReaderArray<Float_t> Jet_pt = {fReader, "Jet_pt"};
   TTreeReaderArray<Float_t> Jet_puIdDisc = {fReader, "Jet_puIdDisc"};
   TTreeReaderArray<Float_t> Jet_qgl = {fReader, "Jet_qgl"};
   TTreeReaderArray<Float_t> Jet_rawFactor = {fReader, "Jet_rawFactor"};
   TTreeReaderArray<Float_t> Jet_bRegCorr = {fReader, "Jet_bRegCorr"};
   TTreeReaderArray<Float_t> Jet_bRegRes = {fReader, "Jet_bRegRes"};
   TTreeReaderArray<Float_t> Jet_cRegCorr = {fReader, "Jet_cRegCorr"};
   TTreeReaderArray<Float_t> Jet_cRegRes = {fReader, "Jet_cRegRes"};
   TTreeReaderArray<Int_t> Jet_electronIdx1 = {fReader, "Jet_electronIdx1"};
   TTreeReaderArray<Int_t> Jet_electronIdx2 = {fReader, "Jet_electronIdx2"};
   TTreeReaderArray<Int_t> Jet_hfadjacentEtaStripsSize = {fReader, "Jet_hfadjacentEtaStripsSize"};
   TTreeReaderArray<Int_t> Jet_hfcentralEtaStripSize = {fReader, "Jet_hfcentralEtaStripSize"};
   TTreeReaderArray<Int_t> Jet_jetId = {fReader, "Jet_jetId"};
   TTreeReaderArray<Int_t> Jet_muonIdx1 = {fReader, "Jet_muonIdx1"};
   TTreeReaderArray<Int_t> Jet_muonIdx2 = {fReader, "Jet_muonIdx2"};
   TTreeReaderArray<Int_t> Jet_nElectrons = {fReader, "Jet_nElectrons"};
   TTreeReaderArray<Int_t> Jet_nMuons = {fReader, "Jet_nMuons"};
   TTreeReaderArray<Int_t> Jet_puId = {fReader, "Jet_puId"};
   TTreeReaderArray<UChar_t> Jet_nConstituents = {fReader, "Jet_nConstituents"};
//    TTreeReaderValue<Float_t> L1PreFiringWeight_Dn = {fReader, "L1PreFiringWeight_Dn"};
//    TTreeReaderValue<Float_t> L1PreFiringWeight_ECAL_Dn = {fReader, "L1PreFiringWeight_ECAL_Dn"};
//    TTreeReaderValue<Float_t> L1PreFiringWeight_ECAL_Nom = {fReader, "L1PreFiringWeight_ECAL_Nom"};
//    TTreeReaderValue<Float_t> L1PreFiringWeight_ECAL_Up = {fReader, "L1PreFiringWeight_ECAL_Up"};
//    TTreeReaderValue<Float_t> L1PreFiringWeight_Muon_Nom = {fReader, "L1PreFiringWeight_Muon_Nom"};
//    TTreeReaderValue<Float_t> L1PreFiringWeight_Muon_StatDn = {fReader, "L1PreFiringWeight_Muon_StatDn"};
//    TTreeReaderValue<Float_t> L1PreFiringWeight_Muon_StatUp = {fReader, "L1PreFiringWeight_Muon_StatUp"};
//    TTreeReaderValue<Float_t> L1PreFiringWeight_Muon_SystDn = {fReader, "L1PreFiringWeight_Muon_SystDn"};
//    TTreeReaderValue<Float_t> L1PreFiringWeight_Muon_SystUp = {fReader, "L1PreFiringWeight_Muon_SystUp"};
   TTreeReaderValue<Float_t> L1PreFiringWeight_Nom = {fReader, "L1PreFiringWeight_Nom"};
//    TTreeReaderValue<Float_t> L1PreFiringWeight_Up = {fReader, "L1PreFiringWeight_Up"};
//    TTreeReaderValue<Float_t> LHE_HT = {fReader, "LHE_HT"};
//    TTreeReaderValue<Float_t> LHE_HTIncoming = {fReader, "LHE_HTIncoming"};
//    TTreeReaderValue<Float_t> LHE_Vpt = {fReader, "LHE_Vpt"};
//    TTreeReaderValue<Float_t> LHE_AlphaS = {fReader, "LHE_AlphaS"};
//    TTreeReaderValue<UChar_t> LHE_Njets = {fReader, "LHE_Njets"};
//    TTreeReaderValue<UChar_t> LHE_Nb = {fReader, "LHE_Nb"};
//    TTreeReaderValue<UChar_t> LHE_Nc = {fReader, "LHE_Nc"};
//    TTreeReaderValue<UChar_t> LHE_Nuds = {fReader, "LHE_Nuds"};
//    TTreeReaderValue<UChar_t> LHE_Nglu = {fReader, "LHE_Nglu"};
//    TTreeReaderValue<UChar_t> LHE_NpNLO = {fReader, "LHE_NpNLO"};
//    TTreeReaderValue<UChar_t> LHE_NpLO = {fReader, "LHE_NpLO"};
//    TTreeReaderValue<UInt_t> nLHEPart = {fReader, "nLHEPart"};
//    TTreeReaderArray<Float_t> LHEPart_pt = {fReader, "LHEPart_pt"};
//    TTreeReaderArray<Float_t> LHEPart_eta = {fReader, "LHEPart_eta"};
//    TTreeReaderArray<Float_t> LHEPart_phi = {fReader, "LHEPart_phi"};
//    TTreeReaderArray<Float_t> LHEPart_mass = {fReader, "LHEPart_mass"};
//    TTreeReaderArray<Float_t> LHEPart_incomingpz = {fReader, "LHEPart_incomingpz"};
//    TTreeReaderArray<Int_t> LHEPart_pdgId = {fReader, "LHEPart_pdgId"};
//    TTreeReaderArray<Int_t> LHEPart_status = {fReader, "LHEPart_status"};
//    TTreeReaderArray<Int_t> LHEPart_spin = {fReader, "LHEPart_spin"};
//    TTreeReaderValue<UInt_t> nLowPtElectron = {fReader, "nLowPtElectron"};
//    TTreeReaderArray<Float_t> LowPtElectron_ID = {fReader, "LowPtElectron_ID"};
//    TTreeReaderArray<Float_t> LowPtElectron_convVtxRadius = {fReader, "LowPtElectron_convVtxRadius"};
//    TTreeReaderArray<Float_t> LowPtElectron_deltaEtaSC = {fReader, "LowPtElectron_deltaEtaSC"};
//    TTreeReaderArray<Float_t> LowPtElectron_dxy = {fReader, "LowPtElectron_dxy"};
//    TTreeReaderArray<Float_t> LowPtElectron_dxyErr = {fReader, "LowPtElectron_dxyErr"};
//    TTreeReaderArray<Float_t> LowPtElectron_dz = {fReader, "LowPtElectron_dz"};
//    TTreeReaderArray<Float_t> LowPtElectron_dzErr = {fReader, "LowPtElectron_dzErr"};
//    TTreeReaderArray<Float_t> LowPtElectron_eInvMinusPInv = {fReader, "LowPtElectron_eInvMinusPInv"};
//    TTreeReaderArray<Float_t> LowPtElectron_embeddedID = {fReader, "LowPtElectron_embeddedID"};
//    TTreeReaderArray<Float_t> LowPtElectron_energyErr = {fReader, "LowPtElectron_energyErr"};
//    TTreeReaderArray<Float_t> LowPtElectron_eta = {fReader, "LowPtElectron_eta"};
//    TTreeReaderArray<Float_t> LowPtElectron_hoe = {fReader, "LowPtElectron_hoe"};
//    TTreeReaderArray<Float_t> LowPtElectron_mass = {fReader, "LowPtElectron_mass"};
//    TTreeReaderArray<Float_t> LowPtElectron_miniPFRelIso_all = {fReader, "LowPtElectron_miniPFRelIso_all"};
//    TTreeReaderArray<Float_t> LowPtElectron_miniPFRelIso_chg = {fReader, "LowPtElectron_miniPFRelIso_chg"};
//    TTreeReaderArray<Float_t> LowPtElectron_phi = {fReader, "LowPtElectron_phi"};
//    TTreeReaderArray<Float_t> LowPtElectron_pt = {fReader, "LowPtElectron_pt"};
//    TTreeReaderArray<Float_t> LowPtElectron_ptbiased = {fReader, "LowPtElectron_ptbiased"};
//    TTreeReaderArray<Float_t> LowPtElectron_r9 = {fReader, "LowPtElectron_r9"};
//    TTreeReaderArray<Float_t> LowPtElectron_scEtOverPt = {fReader, "LowPtElectron_scEtOverPt"};
//    TTreeReaderArray<Float_t> LowPtElectron_sieie = {fReader, "LowPtElectron_sieie"};
//    TTreeReaderArray<Float_t> LowPtElectron_unbiased = {fReader, "LowPtElectron_unbiased"};
//    TTreeReaderArray<Int_t> LowPtElectron_charge = {fReader, "LowPtElectron_charge"};
//    TTreeReaderArray<Int_t> LowPtElectron_convWP = {fReader, "LowPtElectron_convWP"};
//    TTreeReaderArray<Int_t> LowPtElectron_pdgId = {fReader, "LowPtElectron_pdgId"};
//    TTreeReaderArray<Bool_t> LowPtElectron_convVeto = {fReader, "LowPtElectron_convVeto"};
//    TTreeReaderArray<UChar_t> LowPtElectron_lostHits = {fReader, "LowPtElectron_lostHits"};
//    TTreeReaderValue<Float_t> GenMET_phi = {fReader, "GenMET_phi"};
//    TTreeReaderValue<Float_t> GenMET_pt = {fReader, "GenMET_pt"};
//    TTreeReaderValue<Float_t> MET_MetUnclustEnUpDeltaX = {fReader, "MET_MetUnclustEnUpDeltaX"};
//    TTreeReaderValue<Float_t> MET_MetUnclustEnUpDeltaY = {fReader, "MET_MetUnclustEnUpDeltaY"};
//    TTreeReaderValue<Float_t> MET_covXX = {fReader, "MET_covXX"};
//    TTreeReaderValue<Float_t> MET_covXY = {fReader, "MET_covXY"};
//    TTreeReaderValue<Float_t> MET_covYY = {fReader, "MET_covYY"};
//    TTreeReaderValue<Float_t> MET_phi = {fReader, "MET_phi"};
//    TTreeReaderValue<Float_t> MET_pt = {fReader, "MET_pt"};
//    TTreeReaderValue<Float_t> MET_significance = {fReader, "MET_significance"};
//    TTreeReaderValue<Float_t> MET_sumEt = {fReader, "MET_sumEt"};
//    TTreeReaderValue<Float_t> MET_sumPtUnclustered = {fReader, "MET_sumPtUnclustered"};
   TTreeReaderValue<UInt_t> nMuon = {fReader, "nMuon"};
   TTreeReaderArray<Float_t> Muon_dxy = {fReader, "Muon_dxy"};
   TTreeReaderArray<Float_t> Muon_dxyErr = {fReader, "Muon_dxyErr"};
   TTreeReaderArray<Float_t> Muon_dxybs = {fReader, "Muon_dxybs"};
   TTreeReaderArray<Float_t> Muon_dz = {fReader, "Muon_dz"};
   TTreeReaderArray<Float_t> Muon_dzErr = {fReader, "Muon_dzErr"};
   TTreeReaderArray<Float_t> Muon_eta = {fReader, "Muon_eta"};
   TTreeReaderArray<Float_t> Muon_ip3d = {fReader, "Muon_ip3d"};
   TTreeReaderArray<Float_t> Muon_jetPtRelv2 = {fReader, "Muon_jetPtRelv2"};
   TTreeReaderArray<Float_t> Muon_jetRelIso = {fReader, "Muon_jetRelIso"};
   TTreeReaderArray<Float_t> Muon_mass = {fReader, "Muon_mass"};
   TTreeReaderArray<Float_t> Muon_miniPFRelIso_all = {fReader, "Muon_miniPFRelIso_all"};
   TTreeReaderArray<Float_t> Muon_miniPFRelIso_chg = {fReader, "Muon_miniPFRelIso_chg"};
   TTreeReaderArray<Float_t> Muon_pfRelIso03_all = {fReader, "Muon_pfRelIso03_all"};
   TTreeReaderArray<Float_t> Muon_pfRelIso03_chg = {fReader, "Muon_pfRelIso03_chg"};
   TTreeReaderArray<Float_t> Muon_pfRelIso04_all = {fReader, "Muon_pfRelIso04_all"};
   TTreeReaderArray<Float_t> Muon_phi = {fReader, "Muon_phi"};
   TTreeReaderArray<Float_t> Muon_pt = {fReader, "Muon_pt"};
   TTreeReaderArray<Float_t> Muon_ptErr = {fReader, "Muon_ptErr"};
   TTreeReaderArray<Float_t> Muon_segmentComp = {fReader, "Muon_segmentComp"};
   TTreeReaderArray<Float_t> Muon_sip3d = {fReader, "Muon_sip3d"};
   TTreeReaderArray<Float_t> Muon_softMva = {fReader, "Muon_softMva"};
   TTreeReaderArray<Float_t> Muon_tkRelIso = {fReader, "Muon_tkRelIso"};
   TTreeReaderArray<Float_t> Muon_tunepRelPt = {fReader, "Muon_tunepRelPt"};
   TTreeReaderArray<Float_t> Muon_mvaLowPt = {fReader, "Muon_mvaLowPt"};
   TTreeReaderArray<Float_t> Muon_mvaTTH = {fReader, "Muon_mvaTTH"};
   TTreeReaderArray<Int_t> Muon_charge = {fReader, "Muon_charge"};
   TTreeReaderArray<Int_t> Muon_jetIdx = {fReader, "Muon_jetIdx"};
   TTreeReaderArray<Int_t> Muon_nStations = {fReader, "Muon_nStations"};
   TTreeReaderArray<Int_t> Muon_nTrackerLayers = {fReader, "Muon_nTrackerLayers"};
   TTreeReaderArray<Int_t> Muon_pdgId = {fReader, "Muon_pdgId"};
   TTreeReaderArray<Int_t> Muon_tightCharge = {fReader, "Muon_tightCharge"};
   TTreeReaderArray<Int_t> Muon_fsrPhotonIdx = {fReader, "Muon_fsrPhotonIdx"};
   TTreeReaderArray<UChar_t> Muon_highPtId = {fReader, "Muon_highPtId"};
   TTreeReaderArray<Bool_t> Muon_highPurity = {fReader, "Muon_highPurity"};
   TTreeReaderArray<Bool_t> Muon_inTimeMuon = {fReader, "Muon_inTimeMuon"};
   TTreeReaderArray<Bool_t> Muon_isGlobal = {fReader, "Muon_isGlobal"};
   TTreeReaderArray<Bool_t> Muon_isPFcand = {fReader, "Muon_isPFcand"};
   TTreeReaderArray<Bool_t> Muon_isStandalone = {fReader, "Muon_isStandalone"};
   TTreeReaderArray<Bool_t> Muon_isTracker = {fReader, "Muon_isTracker"};
   TTreeReaderArray<UChar_t> Muon_jetNDauCharged = {fReader, "Muon_jetNDauCharged"};
   TTreeReaderArray<Bool_t> Muon_looseId = {fReader, "Muon_looseId"};
   TTreeReaderArray<Bool_t> Muon_mediumId = {fReader, "Muon_mediumId"};
   TTreeReaderArray<Bool_t> Muon_mediumPromptId = {fReader, "Muon_mediumPromptId"};
   TTreeReaderArray<UChar_t> Muon_miniIsoId = {fReader, "Muon_miniIsoId"};
   TTreeReaderArray<UChar_t> Muon_multiIsoId = {fReader, "Muon_multiIsoId"};
   TTreeReaderArray<UChar_t> Muon_mvaId = {fReader, "Muon_mvaId"};
   TTreeReaderArray<UChar_t> Muon_mvaLowPtId = {fReader, "Muon_mvaLowPtId"};
   TTreeReaderArray<UChar_t> Muon_pfIsoId = {fReader, "Muon_pfIsoId"};
   TTreeReaderArray<UChar_t> Muon_puppiIsoId = {fReader, "Muon_puppiIsoId"};
   TTreeReaderArray<Bool_t> Muon_softId = {fReader, "Muon_softId"};
   TTreeReaderArray<Bool_t> Muon_softMvaId = {fReader, "Muon_softMvaId"};
   TTreeReaderArray<Bool_t> Muon_tightId = {fReader, "Muon_tightId"};
   TTreeReaderArray<UChar_t> Muon_tkIsoId = {fReader, "Muon_tkIsoId"};
   TTreeReaderArray<Bool_t> Muon_triggerIdLoose = {fReader, "Muon_triggerIdLoose"};
//    TTreeReaderValue<UInt_t> nPhoton = {fReader, "nPhoton"};
//    TTreeReaderArray<Float_t> Photon_dEscaleDown = {fReader, "Photon_dEscaleDown"};
//    TTreeReaderArray<Float_t> Photon_dEscaleUp = {fReader, "Photon_dEscaleUp"};
//    TTreeReaderArray<Float_t> Photon_dEsigmaDown = {fReader, "Photon_dEsigmaDown"};
//    TTreeReaderArray<Float_t> Photon_dEsigmaUp = {fReader, "Photon_dEsigmaUp"};
//    TTreeReaderArray<Float_t> Photon_eCorr = {fReader, "Photon_eCorr"};
//    TTreeReaderArray<Float_t> Photon_energyErr = {fReader, "Photon_energyErr"};
//    TTreeReaderArray<Float_t> Photon_eta = {fReader, "Photon_eta"};
//    TTreeReaderArray<Float_t> Photon_hoe = {fReader, "Photon_hoe"};
//    TTreeReaderArray<Float_t> Photon_mass = {fReader, "Photon_mass"};
//    TTreeReaderArray<Float_t> Photon_mvaID = {fReader, "Photon_mvaID"};
//    TTreeReaderArray<Float_t> Photon_mvaID_Fall17V1p1 = {fReader, "Photon_mvaID_Fall17V1p1"};
//    TTreeReaderArray<Float_t> Photon_pfRelIso03_all = {fReader, "Photon_pfRelIso03_all"};
//    TTreeReaderArray<Float_t> Photon_pfRelIso03_chg = {fReader, "Photon_pfRelIso03_chg"};
//    TTreeReaderArray<Float_t> Photon_phi = {fReader, "Photon_phi"};
//    TTreeReaderArray<Float_t> Photon_pt = {fReader, "Photon_pt"};
//    TTreeReaderArray<Float_t> Photon_r9 = {fReader, "Photon_r9"};
//    TTreeReaderArray<Float_t> Photon_sieie = {fReader, "Photon_sieie"};
//    TTreeReaderArray<Int_t> Photon_charge = {fReader, "Photon_charge"};
//    TTreeReaderArray<Int_t> Photon_cutBased = {fReader, "Photon_cutBased"};
//    TTreeReaderArray<Int_t> Photon_cutBased_Fall17V1Bitmap = {fReader, "Photon_cutBased_Fall17V1Bitmap"};
//    TTreeReaderArray<Int_t> Photon_electronIdx = {fReader, "Photon_electronIdx"};
//    TTreeReaderArray<Int_t> Photon_jetIdx = {fReader, "Photon_jetIdx"};
//    TTreeReaderArray<Int_t> Photon_pdgId = {fReader, "Photon_pdgId"};
//    TTreeReaderArray<Int_t> Photon_vidNestedWPBitmap = {fReader, "Photon_vidNestedWPBitmap"};
//    TTreeReaderArray<Bool_t> Photon_electronVeto = {fReader, "Photon_electronVeto"};
//    TTreeReaderArray<Bool_t> Photon_isScEtaEB = {fReader, "Photon_isScEtaEB"};
//    TTreeReaderArray<Bool_t> Photon_isScEtaEE = {fReader, "Photon_isScEtaEE"};
//    TTreeReaderArray<Bool_t> Photon_mvaID_WP80 = {fReader, "Photon_mvaID_WP80"};
//    TTreeReaderArray<Bool_t> Photon_mvaID_WP90 = {fReader, "Photon_mvaID_WP90"};
//    TTreeReaderArray<Bool_t> Photon_pixelSeed = {fReader, "Photon_pixelSeed"};
//    TTreeReaderArray<UChar_t> Photon_seedGain = {fReader, "Photon_seedGain"};
   TTreeReaderValue<Float_t> Pileup_nTrueInt = {fReader, "L1PreFiringWeight_Nom"};
//    TTreeReaderValue<Float_t> Pileup_pudensity = {fReader, "Pileup_pudensity"};
//    TTreeReaderValue<Float_t> Pileup_gpudensity = {fReader, "Pileup_gpudensity"};
//    TTreeReaderValue<Int_t> Pileup_nPU = {fReader, "Pileup_nPU"};
//    TTreeReaderValue<Int_t> Pileup_sumEOOT = {fReader, "Pileup_sumEOOT"};
//    TTreeReaderValue<Int_t> Pileup_sumLOOT = {fReader, "Pileup_sumLOOT"};
//    TTreeReaderValue<Float_t> PuppiMET_phi = {fReader, "PuppiMET_phi"};
//    TTreeReaderValue<Float_t> PuppiMET_phiJERDown = {fReader, "PuppiMET_phiJERDown"};
//    TTreeReaderValue<Float_t> PuppiMET_phiJERUp = {fReader, "PuppiMET_phiJERUp"};
//    TTreeReaderValue<Float_t> PuppiMET_phiJESDown = {fReader, "PuppiMET_phiJESDown"};
//    TTreeReaderValue<Float_t> PuppiMET_phiJESUp = {fReader, "PuppiMET_phiJESUp"};
//    TTreeReaderValue<Float_t> PuppiMET_phiUnclusteredDown = {fReader, "PuppiMET_phiUnclusteredDown"};
//    TTreeReaderValue<Float_t> PuppiMET_phiUnclusteredUp = {fReader, "PuppiMET_phiUnclusteredUp"};
//    TTreeReaderValue<Float_t> PuppiMET_pt = {fReader, "PuppiMET_pt"};
//    TTreeReaderValue<Float_t> PuppiMET_ptJERDown = {fReader, "PuppiMET_ptJERDown"};
//    TTreeReaderValue<Float_t> PuppiMET_ptJERUp = {fReader, "PuppiMET_ptJERUp"};
//    TTreeReaderValue<Float_t> PuppiMET_ptJESDown = {fReader, "PuppiMET_ptJESDown"};
//    TTreeReaderValue<Float_t> PuppiMET_ptJESUp = {fReader, "PuppiMET_ptJESUp"};
//    TTreeReaderValue<Float_t> PuppiMET_ptUnclusteredDown = {fReader, "PuppiMET_ptUnclusteredDown"};
//    TTreeReaderValue<Float_t> PuppiMET_ptUnclusteredUp = {fReader, "PuppiMET_ptUnclusteredUp"};
//    TTreeReaderValue<Float_t> PuppiMET_sumEt = {fReader, "PuppiMET_sumEt"};
//    TTreeReaderValue<Float_t> RawMET_phi = {fReader, "RawMET_phi"};
//    TTreeReaderValue<Float_t> RawMET_pt = {fReader, "RawMET_pt"};
//    TTreeReaderValue<Float_t> RawMET_sumEt = {fReader, "RawMET_sumEt"};
//    TTreeReaderValue<Float_t> RawPuppiMET_phi = {fReader, "RawPuppiMET_phi"};
//    TTreeReaderValue<Float_t> RawPuppiMET_pt = {fReader, "RawPuppiMET_pt"};
//    TTreeReaderValue<Float_t> RawPuppiMET_sumEt = {fReader, "RawPuppiMET_sumEt"};
   TTreeReaderValue<Float_t> fixedGridRhoFastjetAll = {fReader, "fixedGridRhoFastjetAll"};
//    TTreeReaderValue<Float_t> fixedGridRhoFastjetCentral = {fReader, "fixedGridRhoFastjetCentral"};
//    TTreeReaderValue<Float_t> fixedGridRhoFastjetCentralCalo = {fReader, "fixedGridRhoFastjetCentralCalo"};
//    TTreeReaderValue<Float_t> fixedGridRhoFastjetCentralChargedPileUp = {fReader, "fixedGridRhoFastjetCentralChargedPileUp"};
//    TTreeReaderValue<Float_t> fixedGridRhoFastjetCentralNeutral = {fReader, "fixedGridRhoFastjetCentralNeutral"};
//    TTreeReaderValue<UInt_t> nGenDressedLepton = {fReader, "nGenDressedLepton"};
//    TTreeReaderArray<Float_t> GenDressedLepton_eta = {fReader, "GenDressedLepton_eta"};
//    TTreeReaderArray<Float_t> GenDressedLepton_mass = {fReader, "GenDressedLepton_mass"};
//    TTreeReaderArray<Float_t> GenDressedLepton_phi = {fReader, "GenDressedLepton_phi"};
//    TTreeReaderArray<Float_t> GenDressedLepton_pt = {fReader, "GenDressedLepton_pt"};
//    TTreeReaderArray<Int_t> GenDressedLepton_pdgId = {fReader, "GenDressedLepton_pdgId"};
//    TTreeReaderArray<Bool_t> GenDressedLepton_hasTauAnc = {fReader, "GenDressedLepton_hasTauAnc"};
//    TTreeReaderValue<UInt_t> nGenIsolatedPhoton = {fReader, "nGenIsolatedPhoton"};
//    TTreeReaderArray<Float_t> GenIsolatedPhoton_eta = {fReader, "GenIsolatedPhoton_eta"};
//    TTreeReaderArray<Float_t> GenIsolatedPhoton_mass = {fReader, "GenIsolatedPhoton_mass"};
//    TTreeReaderArray<Float_t> GenIsolatedPhoton_phi = {fReader, "GenIsolatedPhoton_phi"};
//    TTreeReaderArray<Float_t> GenIsolatedPhoton_pt = {fReader, "GenIsolatedPhoton_pt"};
//    TTreeReaderValue<UInt_t> nSoftActivityJet = {fReader, "nSoftActivityJet"};
//    TTreeReaderArray<Float_t> SoftActivityJet_eta = {fReader, "SoftActivityJet_eta"};
//    TTreeReaderArray<Float_t> SoftActivityJet_phi = {fReader, "SoftActivityJet_phi"};
//    TTreeReaderArray<Float_t> SoftActivityJet_pt = {fReader, "SoftActivityJet_pt"};
//    TTreeReaderValue<Float_t> SoftActivityJetHT = {fReader, "SoftActivityJetHT"};
//    TTreeReaderValue<Float_t> SoftActivityJetHT10 = {fReader, "SoftActivityJetHT10"};
//    TTreeReaderValue<Float_t> SoftActivityJetHT2 = {fReader, "SoftActivityJetHT2"};
//    TTreeReaderValue<Float_t> SoftActivityJetHT5 = {fReader, "SoftActivityJetHT5"};
//    TTreeReaderValue<Int_t> SoftActivityJetNjets10 = {fReader, "SoftActivityJetNjets10"};
//    TTreeReaderValue<Int_t> SoftActivityJetNjets2 = {fReader, "SoftActivityJetNjets2"};
//    TTreeReaderValue<Int_t> SoftActivityJetNjets5 = {fReader, "SoftActivityJetNjets5"};
//    TTreeReaderValue<UInt_t> nSubJet = {fReader, "nSubJet"};
//    TTreeReaderArray<Float_t> SubJet_btagCSVV2 = {fReader, "SubJet_btagCSVV2"};
//    TTreeReaderArray<Float_t> SubJet_btagDeepB = {fReader, "SubJet_btagDeepB"};
//    TTreeReaderArray<Float_t> SubJet_eta = {fReader, "SubJet_eta"};
//    TTreeReaderArray<Float_t> SubJet_mass = {fReader, "SubJet_mass"};
//    TTreeReaderArray<Float_t> SubJet_n2b1 = {fReader, "SubJet_n2b1"};
//    TTreeReaderArray<Float_t> SubJet_n3b1 = {fReader, "SubJet_n3b1"};
//    TTreeReaderArray<Float_t> SubJet_phi = {fReader, "SubJet_phi"};
//    TTreeReaderArray<Float_t> SubJet_pt = {fReader, "SubJet_pt"};
//    TTreeReaderArray<Float_t> SubJet_rawFactor = {fReader, "SubJet_rawFactor"};
//    TTreeReaderArray<Float_t> SubJet_tau1 = {fReader, "SubJet_tau1"};
//    TTreeReaderArray<Float_t> SubJet_tau2 = {fReader, "SubJet_tau2"};
//    TTreeReaderArray<Float_t> SubJet_tau3 = {fReader, "SubJet_tau3"};
//    TTreeReaderArray<Float_t> SubJet_tau4 = {fReader, "SubJet_tau4"};
   TTreeReaderValue<UInt_t> nTau = {fReader, "nTau"};
   TTreeReaderArray<Float_t> Tau_chargedIso = {fReader, "Tau_chargedIso"};
   TTreeReaderArray<Float_t> Tau_dxy = {fReader, "Tau_dxy"};
   TTreeReaderArray<Float_t> Tau_dz = {fReader, "Tau_dz"};
   TTreeReaderArray<Float_t> Tau_eta = {fReader, "Tau_eta"};
   TTreeReaderArray<Float_t> Tau_leadTkDeltaEta = {fReader, "Tau_leadTkDeltaEta"};
   TTreeReaderArray<Float_t> Tau_leadTkDeltaPhi = {fReader, "Tau_leadTkDeltaPhi"};
   TTreeReaderArray<Float_t> Tau_leadTkPtOverTauPt = {fReader, "Tau_leadTkPtOverTauPt"};
   TTreeReaderArray<Float_t> Tau_mass = {fReader, "Tau_mass"};
   TTreeReaderArray<Float_t> Tau_neutralIso = {fReader, "Tau_neutralIso"};
   TTreeReaderArray<Float_t> Tau_phi = {fReader, "Tau_phi"};
   TTreeReaderArray<Float_t> Tau_photonsOutsideSignalCone = {fReader, "Tau_photonsOutsideSignalCone"};
   TTreeReaderArray<Float_t> Tau_pt = {fReader, "Tau_pt"};
   TTreeReaderArray<Float_t> Tau_puCorr = {fReader, "Tau_puCorr"};
   TTreeReaderArray<Float_t> Tau_rawDeepTau2017v2p1VSe = {fReader, "Tau_rawDeepTau2017v2p1VSe"};
   TTreeReaderArray<Float_t> Tau_rawDeepTau2017v2p1VSjet = {fReader, "Tau_rawDeepTau2017v2p1VSjet"};
   TTreeReaderArray<Float_t> Tau_rawDeepTau2017v2p1VSmu = {fReader, "Tau_rawDeepTau2017v2p1VSmu"};
   TTreeReaderArray<Float_t> Tau_rawIso = {fReader, "Tau_rawIso"};
   TTreeReaderArray<Float_t> Tau_rawIsodR03 = {fReader, "Tau_rawIsodR03"};
   TTreeReaderArray<Int_t> Tau_charge = {fReader, "Tau_charge"};
   TTreeReaderArray<Int_t> Tau_decayMode = {fReader, "Tau_decayMode"};
   TTreeReaderArray<Int_t> Tau_jetIdx = {fReader, "Tau_jetIdx"};
   TTreeReaderArray<Bool_t> Tau_idAntiEleDeadECal = {fReader, "Tau_idAntiEleDeadECal"};
   TTreeReaderArray<UChar_t> Tau_idAntiMu = {fReader, "Tau_idAntiMu"};
   TTreeReaderArray<Bool_t> Tau_idDecayModeOldDMs = {fReader, "Tau_idDecayModeOldDMs"};
   TTreeReaderArray<UChar_t> Tau_idDeepTau2017v2p1VSe = {fReader, "Tau_idDeepTau2017v2p1VSe"};
   TTreeReaderArray<UChar_t> Tau_idDeepTau2017v2p1VSjet = {fReader, "Tau_idDeepTau2017v2p1VSjet"};
   TTreeReaderArray<UChar_t> Tau_idDeepTau2017v2p1VSmu = {fReader, "Tau_idDeepTau2017v2p1VSmu"};
//    TTreeReaderValue<Float_t> TkMET_phi = {fReader, "TkMET_phi"};
//    TTreeReaderValue<Float_t> TkMET_pt = {fReader, "TkMET_pt"};
//    TTreeReaderValue<Float_t> TkMET_sumEt = {fReader, "TkMET_sumEt"};
//    TTreeReaderValue<UInt_t> nTrigObj = {fReader, "nTrigObj"};
//    TTreeReaderArray<Float_t> TrigObj_pt = {fReader, "TrigObj_pt"};
//    TTreeReaderArray<Float_t> TrigObj_eta = {fReader, "TrigObj_eta"};
//    TTreeReaderArray<Float_t> TrigObj_phi = {fReader, "TrigObj_phi"};
//    TTreeReaderArray<Float_t> TrigObj_l1pt = {fReader, "TrigObj_l1pt"};
//    TTreeReaderArray<Float_t> TrigObj_l1pt_2 = {fReader, "TrigObj_l1pt_2"};
//    TTreeReaderArray<Float_t> TrigObj_l2pt = {fReader, "TrigObj_l2pt"};
//    TTreeReaderArray<Int_t> TrigObj_id = {fReader, "TrigObj_id"};
//    TTreeReaderArray<Int_t> TrigObj_l1iso = {fReader, "TrigObj_l1iso"};
//    TTreeReaderArray<Int_t> TrigObj_l1charge = {fReader, "TrigObj_l1charge"};
//    TTreeReaderArray<Int_t> TrigObj_filterBits = {fReader, "TrigObj_filterBits"};
   TTreeReaderValue<Int_t> genTtbarId = {fReader, "PV_npvs"};
//    TTreeReaderValue<UInt_t> nOtherPV = {fReader, "nOtherPV"};
//    TTreeReaderArray<Float_t> OtherPV_z = {fReader, "OtherPV_z"};
//    TTreeReaderValue<Float_t> PV_ndof = {fReader, "PV_ndof"};
//    TTreeReaderValue<Float_t> PV_x = {fReader, "PV_x"};
//    TTreeReaderValue<Float_t> PV_y = {fReader, "PV_y"};
//    TTreeReaderValue<Float_t> PV_z = {fReader, "PV_z"};
//    TTreeReaderValue<Float_t> PV_chi2 = {fReader, "PV_chi2"};
//    TTreeReaderValue<Float_t> PV_score = {fReader, "PV_score"};
   TTreeReaderValue<Int_t> PV_npvs = {fReader, "PV_npvs"};
   TTreeReaderValue<Int_t> PV_npvsGood = {fReader, "PV_npvsGood"};
//    TTreeReaderValue<UInt_t> nSV = {fReader, "nSV"};
//    TTreeReaderArray<Float_t> SV_dlen = {fReader, "SV_dlen"};
//    TTreeReaderArray<Float_t> SV_dlenSig = {fReader, "SV_dlenSig"};
//    TTreeReaderArray<Float_t> SV_dxy = {fReader, "SV_dxy"};
//    TTreeReaderArray<Float_t> SV_dxySig = {fReader, "SV_dxySig"};
//    TTreeReaderArray<Float_t> SV_pAngle = {fReader, "SV_pAngle"};
//    TTreeReaderArray<Int_t> SV_charge = {fReader, "SV_charge"};
//    TTreeReaderArray<Int_t> boostedTau_genPartIdx = {fReader, "boostedTau_genPartIdx"};
//    TTreeReaderArray<UChar_t> boostedTau_genPartFlav = {fReader, "boostedTau_genPartFlav"};
//    TTreeReaderArray<Int_t> Electron_genPartIdx = {fReader, "Electron_genPartIdx"};
//    TTreeReaderArray<UChar_t> Electron_genPartFlav = {fReader, "Electron_genPartFlav"};
//    TTreeReaderArray<Int_t> FatJet_genJetAK8Idx = {fReader, "FatJet_genJetAK8Idx"};
//    TTreeReaderArray<Int_t> FatJet_hadronFlavour = {fReader, "FatJet_hadronFlavour"};
//    TTreeReaderArray<UChar_t> FatJet_nBHadrons = {fReader, "FatJet_nBHadrons"};
//    TTreeReaderArray<UChar_t> FatJet_nCHadrons = {fReader, "FatJet_nCHadrons"};
//    TTreeReaderArray<Int_t> GenJetAK8_partonFlavour = {fReader, "GenJetAK8_partonFlavour"};
//    TTreeReaderArray<UChar_t> GenJetAK8_hadronFlavour = {fReader, "GenJetAK8_hadronFlavour"};
//    TTreeReaderArray<Int_t> GenJet_partonFlavour = {fReader, "GenJet_partonFlavour"};
//    TTreeReaderArray<UChar_t> GenJet_hadronFlavour = {fReader, "GenJet_hadronFlavour"};
//    TTreeReaderValue<Float_t> GenVtx_t0 = {fReader, "GenVtx_t0"};
//    TTreeReaderArray<Int_t> Jet_genJetIdx = {fReader, "Jet_genJetIdx"};
//    TTreeReaderArray<Int_t> Jet_hadronFlavour = {fReader, "Jet_hadronFlavour"};
   TTreeReaderArray<Int_t> Jet_hadronFlavour = {fReader, "Electron_charge"};
//    TTreeReaderArray<Int_t> Jet_partonFlavour = {fReader, "Jet_partonFlavour"};
//    TTreeReaderArray<Int_t> LowPtElectron_genPartIdx = {fReader, "LowPtElectron_genPartIdx"};
//    TTreeReaderArray<UChar_t> LowPtElectron_genPartFlav = {fReader, "LowPtElectron_genPartFlav"};
//    TTreeReaderArray<Int_t> Muon_genPartIdx = {fReader, "Muon_genPartIdx"};
//    TTreeReaderArray<UChar_t> Muon_genPartFlav = {fReader, "Muon_genPartFlav"};
//    TTreeReaderArray<Int_t> Photon_genPartIdx = {fReader, "Photon_genPartIdx"};
//    TTreeReaderArray<UChar_t> Photon_genPartFlav = {fReader, "Photon_genPartFlav"};
//    TTreeReaderValue<Float_t> MET_fiducialGenPhi = {fReader, "MET_fiducialGenPhi"};
//    TTreeReaderValue<Float_t> MET_fiducialGenPt = {fReader, "MET_fiducialGenPt"};
//    TTreeReaderArray<UChar_t> Electron_cleanmask = {fReader, "Electron_cleanmask"};
//    TTreeReaderArray<UChar_t> Jet_cleanmask = {fReader, "Jet_cleanmask"};
//    TTreeReaderArray<UChar_t> Muon_cleanmask = {fReader, "Muon_cleanmask"};
//    TTreeReaderArray<UChar_t> Photon_cleanmask = {fReader, "Photon_cleanmask"};
//    TTreeReaderArray<UChar_t> Tau_cleanmask = {fReader, "Tau_cleanmask"};
//    TTreeReaderArray<Int_t> SubJet_hadronFlavour = {fReader, "SubJet_hadronFlavour"};
//    TTreeReaderArray<UChar_t> SubJet_nBHadrons = {fReader, "SubJet_nBHadrons"};
//    TTreeReaderArray<UChar_t> SubJet_nCHadrons = {fReader, "SubJet_nCHadrons"};
//    TTreeReaderArray<Float_t> SV_chi2 = {fReader, "SV_chi2"};
//    TTreeReaderArray<Float_t> SV_eta = {fReader, "SV_eta"};
//    TTreeReaderArray<Float_t> SV_mass = {fReader, "SV_mass"};
//    TTreeReaderArray<Float_t> SV_ndof = {fReader, "SV_ndof"};
//    TTreeReaderArray<Float_t> SV_phi = {fReader, "SV_phi"};
//    TTreeReaderArray<Float_t> SV_pt = {fReader, "SV_pt"};
//    TTreeReaderArray<Float_t> SV_x = {fReader, "SV_x"};
//    TTreeReaderArray<Float_t> SV_y = {fReader, "SV_y"};
//    TTreeReaderArray<Float_t> SV_z = {fReader, "SV_z"};
//    TTreeReaderArray<UChar_t> SV_ntracks = {fReader, "SV_ntracks"};
//    TTreeReaderArray<Int_t> Tau_genPartIdx = {fReader, "Tau_genPartIdx"};
//    TTreeReaderArray<UChar_t> Tau_genPartFlav = {fReader, "Tau_genPartFlav"};
   TTreeReaderArray<UChar_t> Tau_genPartFlav = {fReader, "Electron_jetNDauCharged"};
//    TTreeReaderValue<Bool_t> L1_AlwaysTrue = {fReader, "L1_AlwaysTrue"};
//    TTreeReaderValue<Bool_t> L1_BRIL_TRIG0_AND = {fReader, "L1_BRIL_TRIG0_AND"};
//    TTreeReaderValue<Bool_t> L1_BRIL_TRIG0_FstBunchInTrain = {fReader, "L1_BRIL_TRIG0_FstBunchInTrain"};
//    TTreeReaderValue<Bool_t> L1_BRIL_TRIG0_OR = {fReader, "L1_BRIL_TRIG0_OR"};
//    TTreeReaderValue<Bool_t> L1_BRIL_TRIG0_delayedAND = {fReader, "L1_BRIL_TRIG0_delayedAND"};
//    TTreeReaderValue<Bool_t> L1_BeamGasB1 = {fReader, "L1_BeamGasB1"};
//    TTreeReaderValue<Bool_t> L1_BeamGasB2 = {fReader, "L1_BeamGasB2"};
//    TTreeReaderValue<Bool_t> L1_BeamGasMinus = {fReader, "L1_BeamGasMinus"};
//    TTreeReaderValue<Bool_t> L1_BeamGasPlus = {fReader, "L1_BeamGasPlus"};
//    TTreeReaderValue<Bool_t> L1_BptxMinus = {fReader, "L1_BptxMinus"};
//    TTreeReaderValue<Bool_t> L1_BptxOR = {fReader, "L1_BptxOR"};
//    TTreeReaderValue<Bool_t> L1_BptxPlus = {fReader, "L1_BptxPlus"};
//    TTreeReaderValue<Bool_t> L1_BptxXOR = {fReader, "L1_BptxXOR"};
//    TTreeReaderValue<Bool_t> L1_DoubleEG6_HTT255 = {fReader, "L1_DoubleEG6_HTT255"};
//    TTreeReaderValue<Bool_t> L1_DoubleEG_15_10 = {fReader, "L1_DoubleEG_15_10"};
//    TTreeReaderValue<Bool_t> L1_DoubleEG_18_17 = {fReader, "L1_DoubleEG_18_17"};
//    TTreeReaderValue<Bool_t> L1_DoubleEG_20_18 = {fReader, "L1_DoubleEG_20_18"};
//    TTreeReaderValue<Bool_t> L1_DoubleEG_22_10 = {fReader, "L1_DoubleEG_22_10"};
//    TTreeReaderValue<Bool_t> L1_DoubleEG_22_12 = {fReader, "L1_DoubleEG_22_12"};
//    TTreeReaderValue<Bool_t> L1_DoubleEG_22_15 = {fReader, "L1_DoubleEG_22_15"};
//    TTreeReaderValue<Bool_t> L1_DoubleEG_23_10 = {fReader, "L1_DoubleEG_23_10"};
//    TTreeReaderValue<Bool_t> L1_DoubleEG_24_17 = {fReader, "L1_DoubleEG_24_17"};
//    TTreeReaderValue<Bool_t> L1_DoubleEG_25_12 = {fReader, "L1_DoubleEG_25_12"};
//    TTreeReaderValue<Bool_t> L1_DoubleIsoTau28er = {fReader, "L1_DoubleIsoTau28er"};
//    TTreeReaderValue<Bool_t> L1_DoubleIsoTau30er = {fReader, "L1_DoubleIsoTau30er"};
//    TTreeReaderValue<Bool_t> L1_DoubleIsoTau32er = {fReader, "L1_DoubleIsoTau32er"};
//    TTreeReaderValue<Bool_t> L1_DoubleIsoTau33er = {fReader, "L1_DoubleIsoTau33er"};
//    TTreeReaderValue<Bool_t> L1_DoubleIsoTau34er = {fReader, "L1_DoubleIsoTau34er"};
//    TTreeReaderValue<Bool_t> L1_DoubleIsoTau35er = {fReader, "L1_DoubleIsoTau35er"};
//    TTreeReaderValue<Bool_t> L1_DoubleIsoTau36er = {fReader, "L1_DoubleIsoTau36er"};
//    TTreeReaderValue<Bool_t> L1_DoubleJet12_ForwardBackward = {fReader, "L1_DoubleJet12_ForwardBackward"};
//    TTreeReaderValue<Bool_t> L1_DoubleJet16_ForwardBackward = {fReader, "L1_DoubleJet16_ForwardBackward"};
//    TTreeReaderValue<Bool_t> L1_DoubleJet8_ForwardBackward = {fReader, "L1_DoubleJet8_ForwardBackward"};
//    TTreeReaderValue<Bool_t> L1_DoubleJetC100 = {fReader, "L1_DoubleJetC100"};
//    TTreeReaderValue<Bool_t> L1_DoubleJetC112 = {fReader, "L1_DoubleJetC112"};
//    TTreeReaderValue<Bool_t> L1_DoubleJetC120 = {fReader, "L1_DoubleJetC120"};
//    TTreeReaderValue<Bool_t> L1_DoubleJetC40 = {fReader, "L1_DoubleJetC40"};
//    TTreeReaderValue<Bool_t> L1_DoubleJetC50 = {fReader, "L1_DoubleJetC50"};
//    TTreeReaderValue<Bool_t> L1_DoubleJetC60 = {fReader, "L1_DoubleJetC60"};
//    TTreeReaderValue<Bool_t> L1_DoubleJetC60_ETM60 = {fReader, "L1_DoubleJetC60_ETM60"};
//    TTreeReaderValue<Bool_t> L1_DoubleJetC80 = {fReader, "L1_DoubleJetC80"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu0 = {fReader, "L1_DoubleMu0"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu0_ETM40 = {fReader, "L1_DoubleMu0_ETM40"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu0_ETM55 = {fReader, "L1_DoubleMu0_ETM55"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu0er1p4_dEta_Max1p8_OS = {fReader, "L1_DoubleMu0er1p4_dEta_Max1p8_OS"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu0er1p6_dEta_Max1p8 = {fReader, "L1_DoubleMu0er1p6_dEta_Max1p8"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu0er1p6_dEta_Max1p8_OS = {fReader, "L1_DoubleMu0er1p6_dEta_Max1p8_OS"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu7_EG14 = {fReader, "L1_DoubleMu7_EG14"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu7_EG7 = {fReader, "L1_DoubleMu7_EG7"};
//    TTreeReaderValue<Bool_t> L1_DoubleMuOpen = {fReader, "L1_DoubleMuOpen"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu_10_0_dEta_Max1p8 = {fReader, "L1_DoubleMu_10_0_dEta_Max1p8"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu_10_3p5 = {fReader, "L1_DoubleMu_10_3p5"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu_10_Open = {fReader, "L1_DoubleMu_10_Open"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu_11_4 = {fReader, "L1_DoubleMu_11_4"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu_12_5 = {fReader, "L1_DoubleMu_12_5"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu_12_8 = {fReader, "L1_DoubleMu_12_8"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu_13_6 = {fReader, "L1_DoubleMu_13_6"};
//    TTreeReaderValue<Bool_t> L1_DoubleMu_15_5 = {fReader, "L1_DoubleMu_15_5"};
//    TTreeReaderValue<Bool_t> L1_DoubleTau50er = {fReader, "L1_DoubleTau50er"};
//    TTreeReaderValue<Bool_t> L1_EG25er_HTT125 = {fReader, "L1_EG25er_HTT125"};
//    TTreeReaderValue<Bool_t> L1_EG27er_HTT200 = {fReader, "L1_EG27er_HTT200"};
//    TTreeReaderValue<Bool_t> L1_ETM100 = {fReader, "L1_ETM100"};
//    TTreeReaderValue<Bool_t> L1_ETM120 = {fReader, "L1_ETM120"};
//    TTreeReaderValue<Bool_t> L1_ETM30 = {fReader, "L1_ETM30"};
//    TTreeReaderValue<Bool_t> L1_ETM40 = {fReader, "L1_ETM40"};
//    TTreeReaderValue<Bool_t> L1_ETM50 = {fReader, "L1_ETM50"};
//    TTreeReaderValue<Bool_t> L1_ETM60 = {fReader, "L1_ETM60"};
//    TTreeReaderValue<Bool_t> L1_ETM70 = {fReader, "L1_ETM70"};
//    TTreeReaderValue<Bool_t> L1_ETM75 = {fReader, "L1_ETM75"};
//    TTreeReaderValue<Bool_t> L1_ETM75_Jet60_dPhi_Min0p4 = {fReader, "L1_ETM75_Jet60_dPhi_Min0p4"};
//    TTreeReaderValue<Bool_t> L1_ETM80 = {fReader, "L1_ETM80"};
//    TTreeReaderValue<Bool_t> L1_ETM85 = {fReader, "L1_ETM85"};
//    TTreeReaderValue<Bool_t> L1_ETM90 = {fReader, "L1_ETM90"};
//    TTreeReaderValue<Bool_t> L1_ETM95 = {fReader, "L1_ETM95"};
//    TTreeReaderValue<Bool_t> L1_ETT25 = {fReader, "L1_ETT25"};
//    TTreeReaderValue<Bool_t> L1_ETT35_BptxAND = {fReader, "L1_ETT35_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_ETT40_BptxAND = {fReader, "L1_ETT40_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_ETT50_BptxAND = {fReader, "L1_ETT50_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_ETT60_BptxAND = {fReader, "L1_ETT60_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_FirstBunchAfterTrain = {fReader, "L1_FirstBunchAfterTrain"};
//    TTreeReaderValue<Bool_t> L1_FirstBunchInTrain = {fReader, "L1_FirstBunchInTrain"};
//    TTreeReaderValue<Bool_t> L1_HTM100 = {fReader, "L1_HTM100"};
//    TTreeReaderValue<Bool_t> L1_HTM120 = {fReader, "L1_HTM120"};
//    TTreeReaderValue<Bool_t> L1_HTM130 = {fReader, "L1_HTM130"};
//    TTreeReaderValue<Bool_t> L1_HTM140 = {fReader, "L1_HTM140"};
//    TTreeReaderValue<Bool_t> L1_HTM150 = {fReader, "L1_HTM150"};
//    TTreeReaderValue<Bool_t> L1_HTM50 = {fReader, "L1_HTM50"};
//    TTreeReaderValue<Bool_t> L1_HTM60_HTT260 = {fReader, "L1_HTM60_HTT260"};
//    TTreeReaderValue<Bool_t> L1_HTM70 = {fReader, "L1_HTM70"};
//    TTreeReaderValue<Bool_t> L1_HTM80 = {fReader, "L1_HTM80"};
//    TTreeReaderValue<Bool_t> L1_HTM80_HTT220 = {fReader, "L1_HTM80_HTT220"};
//    TTreeReaderValue<Bool_t> L1_HTT120 = {fReader, "L1_HTT120"};
//    TTreeReaderValue<Bool_t> L1_HTT160 = {fReader, "L1_HTT160"};
//    TTreeReaderValue<Bool_t> L1_HTT200 = {fReader, "L1_HTT200"};
//    TTreeReaderValue<Bool_t> L1_HTT220 = {fReader, "L1_HTT220"};
//    TTreeReaderValue<Bool_t> L1_HTT240 = {fReader, "L1_HTT240"};
//    TTreeReaderValue<Bool_t> L1_HTT255 = {fReader, "L1_HTT255"};
//    TTreeReaderValue<Bool_t> L1_HTT270 = {fReader, "L1_HTT270"};
//    TTreeReaderValue<Bool_t> L1_HTT280 = {fReader, "L1_HTT280"};
//    TTreeReaderValue<Bool_t> L1_HTT300 = {fReader, "L1_HTT300"};
//    TTreeReaderValue<Bool_t> L1_HTT320 = {fReader, "L1_HTT320"};
//    TTreeReaderValue<Bool_t> L1_IsoEG18er_IsoTau24er_dEta_Min0p2 = {fReader, "L1_IsoEG18er_IsoTau24er_dEta_Min0p2"};
//    TTreeReaderValue<Bool_t> L1_IsoEG20er_IsoTau25er_dEta_Min0p2 = {fReader, "L1_IsoEG20er_IsoTau25er_dEta_Min0p2"};
//    TTreeReaderValue<Bool_t> L1_IsoEG22er_IsoTau26er_dEta_Min0p2 = {fReader, "L1_IsoEG22er_IsoTau26er_dEta_Min0p2"};
//    TTreeReaderValue<Bool_t> L1_IsoEG22er_Tau20er_dEta_Min0p2 = {fReader, "L1_IsoEG22er_Tau20er_dEta_Min0p2"};
//    TTreeReaderValue<Bool_t> L1_IsolatedBunch = {fReader, "L1_IsolatedBunch"};
//    TTreeReaderValue<Bool_t> L1_Jet32_DoubleMu_10_0_dPhi_Jet_Mu0_Max0p4_dPhi_Mu_Mu_Min1p0 = {fReader, "L1_Jet32_DoubleMu_10_0_dPhi_Jet_Mu0_Max0p4_dPhi_Mu_Mu_Min1p0"};
//    TTreeReaderValue<Bool_t> L1_Jet32_Mu0_EG10_dPhi_Jet_Mu_Max0p4_dPhi_Mu_EG_Min1p0 = {fReader, "L1_Jet32_Mu0_EG10_dPhi_Jet_Mu_Max0p4_dPhi_Mu_EG_Min1p0"};
//    TTreeReaderValue<Bool_t> L1_MU20_EG15 = {fReader, "L1_MU20_EG15"};
//    TTreeReaderValue<Bool_t> L1_MinimumBiasHF0_AND = {fReader, "L1_MinimumBiasHF0_AND"};
//    TTreeReaderValue<Bool_t> L1_MinimumBiasHF0_AND_BptxAND = {fReader, "L1_MinimumBiasHF0_AND_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_MinimumBiasHF0_OR = {fReader, "L1_MinimumBiasHF0_OR"};
//    TTreeReaderValue<Bool_t> L1_MinimumBiasHF0_OR_BptxAND = {fReader, "L1_MinimumBiasHF0_OR_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_MinimumBiasHF1_AND = {fReader, "L1_MinimumBiasHF1_AND"};
//    TTreeReaderValue<Bool_t> L1_MinimumBiasHF1_AND_BptxAND = {fReader, "L1_MinimumBiasHF1_AND_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_MinimumBiasHF1_OR = {fReader, "L1_MinimumBiasHF1_OR"};
//    TTreeReaderValue<Bool_t> L1_MinimumBiasHF1_OR_BptxAND = {fReader, "L1_MinimumBiasHF1_OR_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_Mu0er_ETM40 = {fReader, "L1_Mu0er_ETM40"};
//    TTreeReaderValue<Bool_t> L1_Mu0er_ETM55 = {fReader, "L1_Mu0er_ETM55"};
//    TTreeReaderValue<Bool_t> L1_Mu10er_ETM30 = {fReader, "L1_Mu10er_ETM30"};
//    TTreeReaderValue<Bool_t> L1_Mu10er_ETM50 = {fReader, "L1_Mu10er_ETM50"};
//    TTreeReaderValue<Bool_t> L1_Mu12_EG10 = {fReader, "L1_Mu12_EG10"};
//    TTreeReaderValue<Bool_t> L1_Mu14er_ETM30 = {fReader, "L1_Mu14er_ETM30"};
//    TTreeReaderValue<Bool_t> L1_Mu16er_Tau20er = {fReader, "L1_Mu16er_Tau20er"};
//    TTreeReaderValue<Bool_t> L1_Mu16er_Tau24er = {fReader, "L1_Mu16er_Tau24er"};
//    TTreeReaderValue<Bool_t> L1_Mu18er_IsoTau26er = {fReader, "L1_Mu18er_IsoTau26er"};
//    TTreeReaderValue<Bool_t> L1_Mu18er_Tau20er = {fReader, "L1_Mu18er_Tau20er"};
//    TTreeReaderValue<Bool_t> L1_Mu18er_Tau24er = {fReader, "L1_Mu18er_Tau24er"};
//    TTreeReaderValue<Bool_t> L1_Mu20_EG10 = {fReader, "L1_Mu20_EG10"};
//    TTreeReaderValue<Bool_t> L1_Mu20_EG17 = {fReader, "L1_Mu20_EG17"};
//    TTreeReaderValue<Bool_t> L1_Mu20_IsoEG6 = {fReader, "L1_Mu20_IsoEG6"};
//    TTreeReaderValue<Bool_t> L1_Mu20er_IsoTau26er = {fReader, "L1_Mu20er_IsoTau26er"};
//    TTreeReaderValue<Bool_t> L1_Mu22er_IsoTau26er = {fReader, "L1_Mu22er_IsoTau26er"};
//    TTreeReaderValue<Bool_t> L1_Mu23_EG10 = {fReader, "L1_Mu23_EG10"};
//    TTreeReaderValue<Bool_t> L1_Mu23_IsoEG10 = {fReader, "L1_Mu23_IsoEG10"};
//    TTreeReaderValue<Bool_t> L1_Mu25er_IsoTau26er = {fReader, "L1_Mu25er_IsoTau26er"};
//    TTreeReaderValue<Bool_t> L1_Mu3_JetC120 = {fReader, "L1_Mu3_JetC120"};
//    TTreeReaderValue<Bool_t> L1_Mu3_JetC120_dEta_Max0p4_dPhi_Max0p4 = {fReader, "L1_Mu3_JetC120_dEta_Max0p4_dPhi_Max0p4"};
//    TTreeReaderValue<Bool_t> L1_Mu3_JetC16 = {fReader, "L1_Mu3_JetC16"};
//    TTreeReaderValue<Bool_t> L1_Mu3_JetC16_dEta_Max0p4_dPhi_Max0p4 = {fReader, "L1_Mu3_JetC16_dEta_Max0p4_dPhi_Max0p4"};
//    TTreeReaderValue<Bool_t> L1_Mu3_JetC60 = {fReader, "L1_Mu3_JetC60"};
//    TTreeReaderValue<Bool_t> L1_Mu3_JetC60_dEta_Max0p4_dPhi_Max0p4 = {fReader, "L1_Mu3_JetC60_dEta_Max0p4_dPhi_Max0p4"};
//    TTreeReaderValue<Bool_t> L1_Mu5_EG15 = {fReader, "L1_Mu5_EG15"};
//    TTreeReaderValue<Bool_t> L1_Mu5_EG20 = {fReader, "L1_Mu5_EG20"};
//    TTreeReaderValue<Bool_t> L1_Mu5_EG23 = {fReader, "L1_Mu5_EG23"};
//    TTreeReaderValue<Bool_t> L1_Mu5_IsoEG18 = {fReader, "L1_Mu5_IsoEG18"};
//    TTreeReaderValue<Bool_t> L1_Mu5_IsoEG20 = {fReader, "L1_Mu5_IsoEG20"};
//    TTreeReaderValue<Bool_t> L1_Mu6_DoubleEG10 = {fReader, "L1_Mu6_DoubleEG10"};
//    TTreeReaderValue<Bool_t> L1_Mu6_DoubleEG17 = {fReader, "L1_Mu6_DoubleEG17"};
//    TTreeReaderValue<Bool_t> L1_Mu6_HTT200 = {fReader, "L1_Mu6_HTT200"};
//    TTreeReaderValue<Bool_t> L1_Mu8_HTT150 = {fReader, "L1_Mu8_HTT150"};
//    TTreeReaderValue<Bool_t> L1_NotBptxOR = {fReader, "L1_NotBptxOR"};
//    TTreeReaderValue<Bool_t> L1_QuadJetC36_Tau52 = {fReader, "L1_QuadJetC36_Tau52"};
//    TTreeReaderValue<Bool_t> L1_QuadJetC40 = {fReader, "L1_QuadJetC40"};
//    TTreeReaderValue<Bool_t> L1_QuadJetC50 = {fReader, "L1_QuadJetC50"};
//    TTreeReaderValue<Bool_t> L1_QuadJetC60 = {fReader, "L1_QuadJetC60"};
//    TTreeReaderValue<Bool_t> L1_QuadMu0 = {fReader, "L1_QuadMu0"};
//    TTreeReaderValue<Bool_t> L1_SingleEG10 = {fReader, "L1_SingleEG10"};
//    TTreeReaderValue<Bool_t> L1_SingleEG15 = {fReader, "L1_SingleEG15"};
//    TTreeReaderValue<Bool_t> L1_SingleEG18 = {fReader, "L1_SingleEG18"};
//    TTreeReaderValue<Bool_t> L1_SingleEG24 = {fReader, "L1_SingleEG24"};
//    TTreeReaderValue<Bool_t> L1_SingleEG26 = {fReader, "L1_SingleEG26"};
//    TTreeReaderValue<Bool_t> L1_SingleEG28 = {fReader, "L1_SingleEG28"};
//    TTreeReaderValue<Bool_t> L1_SingleEG2_BptxAND = {fReader, "L1_SingleEG2_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_SingleEG30 = {fReader, "L1_SingleEG30"};
//    TTreeReaderValue<Bool_t> L1_SingleEG32 = {fReader, "L1_SingleEG32"};
//    TTreeReaderValue<Bool_t> L1_SingleEG34 = {fReader, "L1_SingleEG34"};
//    TTreeReaderValue<Bool_t> L1_SingleEG36 = {fReader, "L1_SingleEG36"};
//    TTreeReaderValue<Bool_t> L1_SingleEG38 = {fReader, "L1_SingleEG38"};
//    TTreeReaderValue<Bool_t> L1_SingleEG40 = {fReader, "L1_SingleEG40"};
//    TTreeReaderValue<Bool_t> L1_SingleEG45 = {fReader, "L1_SingleEG45"};
//    TTreeReaderValue<Bool_t> L1_SingleEG5 = {fReader, "L1_SingleEG5"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG18 = {fReader, "L1_SingleIsoEG18"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG18er = {fReader, "L1_SingleIsoEG18er"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG20 = {fReader, "L1_SingleIsoEG20"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG20er = {fReader, "L1_SingleIsoEG20er"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG22 = {fReader, "L1_SingleIsoEG22"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG22er = {fReader, "L1_SingleIsoEG22er"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG24 = {fReader, "L1_SingleIsoEG24"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG24er = {fReader, "L1_SingleIsoEG24er"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG26 = {fReader, "L1_SingleIsoEG26"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG26er = {fReader, "L1_SingleIsoEG26er"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG28 = {fReader, "L1_SingleIsoEG28"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG28er = {fReader, "L1_SingleIsoEG28er"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG30 = {fReader, "L1_SingleIsoEG30"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG30er = {fReader, "L1_SingleIsoEG30er"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG32 = {fReader, "L1_SingleIsoEG32"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG32er = {fReader, "L1_SingleIsoEG32er"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG34 = {fReader, "L1_SingleIsoEG34"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG34er = {fReader, "L1_SingleIsoEG34er"};
//    TTreeReaderValue<Bool_t> L1_SingleIsoEG36 = {fReader, "L1_SingleIsoEG36"};
//    TTreeReaderValue<Bool_t> L1_SingleJet120 = {fReader, "L1_SingleJet120"};
//    TTreeReaderValue<Bool_t> L1_SingleJet12_BptxAND = {fReader, "L1_SingleJet12_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_SingleJet140 = {fReader, "L1_SingleJet140"};
//    TTreeReaderValue<Bool_t> L1_SingleJet150 = {fReader, "L1_SingleJet150"};
//    TTreeReaderValue<Bool_t> L1_SingleJet16 = {fReader, "L1_SingleJet16"};
//    TTreeReaderValue<Bool_t> L1_SingleJet160 = {fReader, "L1_SingleJet160"};
//    TTreeReaderValue<Bool_t> L1_SingleJet170 = {fReader, "L1_SingleJet170"};
//    TTreeReaderValue<Bool_t> L1_SingleJet180 = {fReader, "L1_SingleJet180"};
//    TTreeReaderValue<Bool_t> L1_SingleJet20 = {fReader, "L1_SingleJet20"};
//    TTreeReaderValue<Bool_t> L1_SingleJet200 = {fReader, "L1_SingleJet200"};
//    TTreeReaderValue<Bool_t> L1_SingleJet35 = {fReader, "L1_SingleJet35"};
//    TTreeReaderValue<Bool_t> L1_SingleJet60 = {fReader, "L1_SingleJet60"};
//    TTreeReaderValue<Bool_t> L1_SingleJet8_BptxAND = {fReader, "L1_SingleJet8_BptxAND"};
//    TTreeReaderValue<Bool_t> L1_SingleJet90 = {fReader, "L1_SingleJet90"};
//    TTreeReaderValue<Bool_t> L1_SingleJetC20_NotBptxOR = {fReader, "L1_SingleJetC20_NotBptxOR"};
//    TTreeReaderValue<Bool_t> L1_SingleJetC20_NotBptxOR_3BX = {fReader, "L1_SingleJetC20_NotBptxOR_3BX"};
//    TTreeReaderValue<Bool_t> L1_SingleJetC32_NotBptxOR = {fReader, "L1_SingleJetC32_NotBptxOR"};
//    TTreeReaderValue<Bool_t> L1_SingleJetC32_NotBptxOR_3BX = {fReader, "L1_SingleJetC32_NotBptxOR_3BX"};
//    TTreeReaderValue<Bool_t> L1_SingleJetC36_NotBptxOR_3BX = {fReader, "L1_SingleJetC36_NotBptxOR_3BX"};
//    TTreeReaderValue<Bool_t> L1_SingleMu10_LowQ = {fReader, "L1_SingleMu10_LowQ"};
//    TTreeReaderValue<Bool_t> L1_SingleMu12 = {fReader, "L1_SingleMu12"};
//    TTreeReaderValue<Bool_t> L1_SingleMu14 = {fReader, "L1_SingleMu14"};
//    TTreeReaderValue<Bool_t> L1_SingleMu14er = {fReader, "L1_SingleMu14er"};
//    TTreeReaderValue<Bool_t> L1_SingleMu16 = {fReader, "L1_SingleMu16"};
//    TTreeReaderValue<Bool_t> L1_SingleMu16er = {fReader, "L1_SingleMu16er"};
//    TTreeReaderValue<Bool_t> L1_SingleMu18 = {fReader, "L1_SingleMu18"};
//    TTreeReaderValue<Bool_t> L1_SingleMu18er = {fReader, "L1_SingleMu18er"};
//    TTreeReaderValue<Bool_t> L1_SingleMu20 = {fReader, "L1_SingleMu20"};
//    TTreeReaderValue<Bool_t> L1_SingleMu20er = {fReader, "L1_SingleMu20er"};
//    TTreeReaderValue<Bool_t> L1_SingleMu22 = {fReader, "L1_SingleMu22"};
//    TTreeReaderValue<Bool_t> L1_SingleMu22er = {fReader, "L1_SingleMu22er"};
//    TTreeReaderValue<Bool_t> L1_SingleMu25 = {fReader, "L1_SingleMu25"};
//    TTreeReaderValue<Bool_t> L1_SingleMu25er = {fReader, "L1_SingleMu25er"};
//    TTreeReaderValue<Bool_t> L1_SingleMu3 = {fReader, "L1_SingleMu3"};
//    TTreeReaderValue<Bool_t> L1_SingleMu30 = {fReader, "L1_SingleMu30"};
//    TTreeReaderValue<Bool_t> L1_SingleMu30er = {fReader, "L1_SingleMu30er"};
//    TTreeReaderValue<Bool_t> L1_SingleMu5 = {fReader, "L1_SingleMu5"};
//    TTreeReaderValue<Bool_t> L1_SingleMu7 = {fReader, "L1_SingleMu7"};
//    TTreeReaderValue<Bool_t> L1_SingleMuCosmics = {fReader, "L1_SingleMuCosmics"};
//    TTreeReaderValue<Bool_t> L1_SingleMuOpen = {fReader, "L1_SingleMuOpen"};
//    TTreeReaderValue<Bool_t> L1_SingleMuOpen_NotBptxOR = {fReader, "L1_SingleMuOpen_NotBptxOR"};
//    TTreeReaderValue<Bool_t> L1_SingleMuOpen_NotBptxOR_3BX = {fReader, "L1_SingleMuOpen_NotBptxOR_3BX"};
//    TTreeReaderValue<Bool_t> L1_SingleTau100er = {fReader, "L1_SingleTau100er"};
//    TTreeReaderValue<Bool_t> L1_SingleTau120er = {fReader, "L1_SingleTau120er"};
//    TTreeReaderValue<Bool_t> L1_SingleTau80er = {fReader, "L1_SingleTau80er"};
//    TTreeReaderValue<Bool_t> L1_TripleEG_14_10_8 = {fReader, "L1_TripleEG_14_10_8"};
//    TTreeReaderValue<Bool_t> L1_TripleEG_18_17_8 = {fReader, "L1_TripleEG_18_17_8"};
//    TTreeReaderValue<Bool_t> L1_TripleJet_84_68_48_VBF = {fReader, "L1_TripleJet_84_68_48_VBF"};
//    TTreeReaderValue<Bool_t> L1_TripleJet_88_72_56_VBF = {fReader, "L1_TripleJet_88_72_56_VBF"};
//    TTreeReaderValue<Bool_t> L1_TripleJet_92_76_64_VBF = {fReader, "L1_TripleJet_92_76_64_VBF"};
//    TTreeReaderValue<Bool_t> L1_TripleMu0 = {fReader, "L1_TripleMu0"};
//    TTreeReaderValue<Bool_t> L1_TripleMu_5_0_0 = {fReader, "L1_TripleMu_5_0_0"};
//    TTreeReaderValue<Bool_t> L1_TripleMu_5_5_3 = {fReader, "L1_TripleMu_5_5_3"};
//    TTreeReaderValue<Bool_t> L1_ZeroBias = {fReader, "L1_ZeroBias"};
//    TTreeReaderValue<Bool_t> L1_ZeroBias_FirstCollidingBunch = {fReader, "L1_ZeroBias_FirstCollidingBunch"};
//    TTreeReaderValue<Bool_t> L1_ZeroBias_copy = {fReader, "L1_ZeroBias_copy"};
//    TTreeReaderValue<Bool_t> L1_UnprefireableEvent = {fReader, "L1_UnprefireableEvent"};
   TTreeReaderValue<Bool_t> Flag_HBHENoiseFilter = {fReader, "Flag_HBHENoiseFilter"};
   TTreeReaderValue<Bool_t> Flag_HBHENoiseIsoFilter = {fReader, "Flag_HBHENoiseIsoFilter"};
   TTreeReaderValue<Bool_t> Flag_CSCTightHaloFilter = {fReader, "Flag_CSCTightHaloFilter"};
   TTreeReaderValue<Bool_t> Flag_CSCTightHaloTrkMuUnvetoFilter = {fReader, "Flag_CSCTightHaloTrkMuUnvetoFilter"};
   TTreeReaderValue<Bool_t> Flag_CSCTightHalo2015Filter = {fReader, "Flag_CSCTightHalo2015Filter"};
   TTreeReaderValue<Bool_t> Flag_globalTightHalo2016Filter = {fReader, "Flag_globalTightHalo2016Filter"};
   TTreeReaderValue<Bool_t> Flag_globalSuperTightHalo2016Filter = {fReader, "Flag_globalSuperTightHalo2016Filter"};
   TTreeReaderValue<Bool_t> Flag_HcalStripHaloFilter = {fReader, "Flag_HcalStripHaloFilter"};
   TTreeReaderValue<Bool_t> Flag_hcalLaserEventFilter = {fReader, "Flag_hcalLaserEventFilter"};
   TTreeReaderValue<Bool_t> Flag_EcalDeadCellTriggerPrimitiveFilter = {fReader, "Flag_EcalDeadCellTriggerPrimitiveFilter"};
   TTreeReaderValue<Bool_t> Flag_EcalDeadCellBoundaryEnergyFilter = {fReader, "Flag_EcalDeadCellBoundaryEnergyFilter"};
   TTreeReaderValue<Bool_t> Flag_ecalBadCalibFilter = {fReader, "Flag_ecalBadCalibFilter"};
   TTreeReaderValue<Bool_t> Flag_goodVertices = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> Flag_eeBadScFilter = {fReader, "Flag_eeBadScFilter"};
   TTreeReaderValue<Bool_t> Flag_ecalLaserCorrFilter = {fReader, "Flag_ecalLaserCorrFilter"};
   TTreeReaderValue<Bool_t> Flag_trkPOGFilters = {fReader, "Flag_trkPOGFilters"};
   TTreeReaderValue<Bool_t> Flag_chargedHadronTrackResolutionFilter = {fReader, "Flag_chargedHadronTrackResolutionFilter"};
   TTreeReaderValue<Bool_t> Flag_muonBadTrackFilter = {fReader, "Flag_muonBadTrackFilter"};
   TTreeReaderValue<Bool_t> Flag_BadChargedCandidateFilter = {fReader, "Flag_BadChargedCandidateFilter"};
   TTreeReaderValue<Bool_t> Flag_BadPFMuonFilter = {fReader, "Flag_BadPFMuonFilter"};
   TTreeReaderValue<Bool_t> Flag_BadPFMuonDzFilter = {fReader, "Flag_BadPFMuonDzFilter"};
   TTreeReaderValue<Bool_t> Flag_hfNoisyHitsFilter = {fReader, "Flag_hfNoisyHitsFilter"};
   TTreeReaderValue<Bool_t> Flag_BadChargedCandidateSummer16Filter = {fReader, "Flag_BadChargedCandidateSummer16Filter"};
   TTreeReaderValue<Bool_t> Flag_BadPFMuonSummer16Filter = {fReader, "Flag_BadPFMuonSummer16Filter"};
   TTreeReaderValue<Bool_t> Flag_trkPOG_manystripclus53X = {fReader, "Flag_trkPOG_manystripclus53X"};
   TTreeReaderValue<Bool_t> Flag_trkPOG_toomanystripclus53X = {fReader, "Flag_trkPOG_toomanystripclus53X"};
   TTreeReaderValue<Bool_t> Flag_trkPOG_logErrorTooManyClusters = {fReader, "Flag_trkPOG_logErrorTooManyClusters"};
   TTreeReaderValue<Bool_t> Flag_METFilters = {fReader, "Flag_METFilters"};
   TTreeReaderValue<Bool_t> L1Reco_step = {fReader, "L1Reco_step"};

   //TRIGGERS FOR 2016
   TTreeReaderValue<Bool_t> HLT_PFHT400_SixJet30_DoubleBTagCSV_p056 = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> HLT_PFHT450_SixJet40_BTagCSV_p056 = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> HLT_PFJet450 = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> HLT_IsoMu24 = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> HLT_IsoMu27 = {fReader, "Flag_goodVertices"}; //read fake branches in header
   
   //TRIGGERS FOR 2018 MC and data B, C, D  
   TTreeReaderValue<Bool_t> HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94 = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59 = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> HLT_PFHT400_SixPFJet32 = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> HLT_PFHT450_SixPFJet36 = {fReader, "Flag_goodVertices"};
   //TRIGGERS FOR 2018 data A
   TTreeReaderValue<Bool_t> HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2 = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> HLT_PFHT430_SixPFJet40_PFBTagDeepCSV_1p5 = {fReader, "Flag_goodVertices"};
   //2018 for only some small slices of 2018 A (CSV b tag instead of DeepCSV btag)
   TTreeReaderValue<Bool_t> HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5 = {fReader, "Flag_goodVertices"};

   TTreeReaderValue<Bool_t> HLT_PFHT1050 = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> HLT_PFJet500 = {fReader, "Flag_goodVertices"};
   // TTreeReaderValue<Bool_t>  = {fReader, "Flag_goodVertices"};
   TTreeReaderValue<Bool_t> HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5 = {fReader, "Flag_goodVertices"};


//    TTreeReaderValue<Bool_t> HLTriggerFirstPath = {fReader, "HLTriggerFirstPath"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet360_TrimMass30 = {fReader, "HLT_AK8PFJet360_TrimMass30"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet400_TrimMass30 = {fReader, "HLT_AK8PFJet400_TrimMass30"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFHT750_TrimMass50 = {fReader, "HLT_AK8PFHT750_TrimMass50"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFHT800_TrimMass50 = {fReader, "HLT_AK8PFHT800_TrimMass50"};
//    TTreeReaderValue<Bool_t> HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p20 = {fReader, "HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p20"};
//    TTreeReaderValue<Bool_t> HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p087 = {fReader, "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p087"};
//    TTreeReaderValue<Bool_t> HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p087 = {fReader, "HLT_AK8DiPFJet300_200_TrimMass30_BTagCSV_p087"};
//    TTreeReaderValue<Bool_t> HLT_AK8DiPFJet300_200_TrimMass30 = {fReader, "HLT_AK8DiPFJet300_200_TrimMass30"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFHT700_TrimR0p1PT0p03Mass50 = {fReader, "HLT_AK8PFHT700_TrimR0p1PT0p03Mass50"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFHT650_TrimR0p1PT0p03Mass50 = {fReader, "HLT_AK8PFHT650_TrimR0p1PT0p03Mass50"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20 = {fReader, "HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20"};
//    TTreeReaderValue<Bool_t> HLT_AK8DiPFJet280_200_TrimMass30 = {fReader, "HLT_AK8DiPFJet280_200_TrimMass30"};
//    TTreeReaderValue<Bool_t> HLT_AK8DiPFJet250_200_TrimMass30 = {fReader, "HLT_AK8DiPFJet250_200_TrimMass30"};
//    TTreeReaderValue<Bool_t> HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20 = {fReader, "HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20"};
//    TTreeReaderValue<Bool_t> HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20 = {fReader, "HLT_AK8DiPFJet250_200_TrimMass30_BTagCSV_p20"};
//    TTreeReaderValue<Bool_t> HLT_CaloJet260 = {fReader, "HLT_CaloJet260"};
//    TTreeReaderValue<Bool_t> HLT_CaloJet500_NoJetID = {fReader, "HLT_CaloJet500_NoJetID"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon13_PsiPrime = {fReader, "HLT_Dimuon13_PsiPrime"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon13_Upsilon = {fReader, "HLT_Dimuon13_Upsilon"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon20_Jpsi = {fReader, "HLT_Dimuon20_Jpsi"};
   // TTreeReaderValue<Bool_t> HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf = {fReader, "HLT_DoubleEle24_22_eta2p1_WPLoose_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_DoubleEle25_CaloIdL_GsfTrkIdVL = {fReader, "HLT_DoubleEle25_CaloIdL_GsfTrkIdVL"};
//    TTreeReaderValue<Bool_t> HLT_DoubleEle33_CaloIdL = {fReader, "HLT_DoubleEle33_CaloIdL"};
   // TTreeReaderValue<Bool_t> HLT_DoubleEle33_CaloIdL_MW = {fReader, "HLT_DoubleEle33_CaloIdL_MW"};
   // TTreeReaderValue<Bool_t> HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW = {fReader, "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW"};
//    TTreeReaderValue<Bool_t> HLT_DoubleEle33_CaloIdL_GsfTrkIdVL = {fReader, "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL"};
   //TTreeReaderValue<Bool_t> HLT_DoubleMediumCombinedIsoPFTau35_Trk1_eta2p1_Reg = {fReader, "Flag_goodVertices"};//tau dataset
//    TTreeReaderValue<Bool_t> HLT_DoubleTightCombinedIsoPFTau35_Trk1_eta2p1_Reg = {fReader, "HLT_DoubleTightCombinedIsoPFTau35_Trk1_eta2p1_Reg"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMediumCombinedIsoPFTau40_Trk1_eta2p1_Reg = {fReader, "HLT_DoubleMediumCombinedIsoPFTau40_Trk1_eta2p1_Reg"};
//    TTreeReaderValue<Bool_t> HLT_DoubleTightCombinedIsoPFTau40_Trk1_eta2p1_Reg = {fReader, "HLT_DoubleTightCombinedIsoPFTau40_Trk1_eta2p1_Reg"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMediumCombinedIsoPFTau40_Trk1_eta2p1 = {fReader, "HLT_DoubleMediumCombinedIsoPFTau40_Trk1_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_DoubleTightCombinedIsoPFTau40_Trk1_eta2p1 = {fReader, "HLT_DoubleTightCombinedIsoPFTau40_Trk1_eta2p1"};
   //TTreeReaderValue<Bool_t> HLT_DoubleMediumIsoPFTau35_Trk1_eta2p1_Reg = {fReader, "Flag_goodVertices"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg = {fReader, "HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1 = {fReader, "HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL = {fReader, "HLT_DoubleEle37_Ele27_CaloIdL_GsfTrkIdVL"};
   //TTreeReaderValue<Bool_t> HLT_DoubleMu33NoFiltersNoVtx = {fReader, "Flag_goodVertices"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu38NoFiltersNoVtx = {fReader, "HLT_DoubleMu38NoFiltersNoVtx"};
   //TTreeReaderValue<Bool_t> HLT_DoubleMu23NoFiltersNoVtxDisplaced = {fReader, "Flag_goodVertices"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu28NoFiltersNoVtxDisplaced = {fReader, "HLT_DoubleMu28NoFiltersNoVtxDisplaced"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu0 = {fReader, "HLT_DoubleMu0"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu4_3_Bs = {fReader, "HLT_DoubleMu4_3_Bs"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu4_3_Jpsi_Displaced = {fReader, "HLT_DoubleMu4_3_Jpsi_Displaced"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu4_JpsiTrk_Displaced = {fReader, "HLT_DoubleMu4_JpsiTrk_Displaced"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu4_LowMassNonResonantTrk_Displaced = {fReader, "HLT_DoubleMu4_LowMassNonResonantTrk_Displaced"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu3_Trk_Tau3mu = {fReader, "HLT_DoubleMu3_Trk_Tau3mu"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu4_PsiPrimeTrk_Displaced = {fReader, "HLT_DoubleMu4_PsiPrimeTrk_Displaced"};
//    TTreeReaderValue<Bool_t> HLT_Mu7p5_L2Mu2_Jpsi = {fReader, "HLT_Mu7p5_L2Mu2_Jpsi"};
//    TTreeReaderValue<Bool_t> HLT_Mu7p5_L2Mu2_Upsilon = {fReader, "HLT_Mu7p5_L2Mu2_Upsilon"};
//    TTreeReaderValue<Bool_t> HLT_Mu7p5_Track2_Jpsi = {fReader, "HLT_Mu7p5_Track2_Jpsi"};
//    TTreeReaderValue<Bool_t> HLT_Mu7p5_Track3p5_Jpsi = {fReader, "HLT_Mu7p5_Track3p5_Jpsi"};
//    TTreeReaderValue<Bool_t> HLT_Mu7p5_Track7_Jpsi = {fReader, "HLT_Mu7p5_Track7_Jpsi"};
//    TTreeReaderValue<Bool_t> HLT_Mu7p5_Track2_Upsilon = {fReader, "HLT_Mu7p5_Track2_Upsilon"};
//    TTreeReaderValue<Bool_t> HLT_Mu7p5_Track3p5_Upsilon = {fReader, "HLT_Mu7p5_Track3p5_Upsilon"};
//    TTreeReaderValue<Bool_t> HLT_Mu7p5_Track7_Upsilon = {fReader, "HLT_Mu7p5_Track7_Upsilon"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing = {fReader, "HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon0er16_Jpsi_NoVertexing = {fReader, "HLT_Dimuon0er16_Jpsi_NoVertexing"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon6_Jpsi_NoVertexing = {fReader, "HLT_Dimuon6_Jpsi_NoVertexing"};
//    TTreeReaderValue<Bool_t> HLT_Photon150 = {fReader, "HLT_Photon150"};
//    TTreeReaderValue<Bool_t> HLT_Photon90_CaloIdL_HT300 = {fReader, "HLT_Photon90_CaloIdL_HT300"};
//    TTreeReaderValue<Bool_t> HLT_HT250_CaloMET70 = {fReader, "HLT_HT250_CaloMET70"};
//    TTreeReaderValue<Bool_t> HLT_DoublePhoton60 = {fReader, "HLT_DoublePhoton60"};
//    TTreeReaderValue<Bool_t> HLT_DoublePhoton85 = {fReader, "HLT_DoublePhoton85"};
//    TTreeReaderValue<Bool_t> HLT_Ele17_Ele8_Gsf = {fReader, "HLT_Ele17_Ele8_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele20_eta2p1_WPLoose_Gsf_LooseIsoPFTau28 = {fReader, "HLT_Ele20_eta2p1_WPLoose_Gsf_LooseIsoPFTau28"};
//    TTreeReaderValue<Bool_t> HLT_Ele22_eta2p1_WPLoose_Gsf_LooseIsoPFTau29 = {fReader, "HLT_Ele22_eta2p1_WPLoose_Gsf_LooseIsoPFTau29"};
//    TTreeReaderValue<Bool_t> HLT_Ele22_eta2p1_WPLoose_Gsf = {fReader, "HLT_Ele22_eta2p1_WPLoose_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele22_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1 = {fReader, "HLT_Ele22_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1"};
//    TTreeReaderValue<Bool_t> HLT_Ele23_WPLoose_Gsf = {fReader, "HLT_Ele23_WPLoose_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele23_WPLoose_Gsf_WHbbBoost = {fReader, "HLT_Ele23_WPLoose_Gsf_WHbbBoost"};
//    TTreeReaderValue<Bool_t> HLT_Ele24_eta2p1_WPLoose_Gsf = {fReader, "HLT_Ele24_eta2p1_WPLoose_Gsf"};
   //TTreeReaderValue<Bool_t> HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20 = {fReader, "Flag_goodVertices"};
   //TTreeReaderValue<Bool_t> HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1 = {fReader, "Flag_goodVertices"};
   //TTreeReaderValue<Bool_t> HLT_Ele24_eta2p1_WPLoose_Gsf_LooseIsoPFTau30 = {fReader, "Flag_goodVertices"};
//    TTreeReaderValue<Bool_t> HLT_Ele25_WPTight_Gsf = {fReader, "HLT_Ele25_WPTight_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele25_eta2p1_WPLoose_Gsf = {fReader, "HLT_Ele25_eta2p1_WPLoose_Gsf"};
   // TTreeReaderValue<Bool_t> HLT_Ele25_eta2p1_WPTight_Gsf = {fReader, "HLT_Ele25_eta2p1_WPTight_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele27_WPLoose_Gsf = {fReader, "HLT_Ele27_WPLoose_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele27_WPLoose_Gsf_WHbbBoost = {fReader, "HLT_Ele27_WPLoose_Gsf_WHbbBoost"};
   // TTreeReaderValue<Bool_t> HLT_Ele27_WPTight_Gsf = {fReader, "HLT_Ele27_WPTight_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele27_WPTight_Gsf_L1JetTauSeeded = {fReader, "HLT_Ele27_WPTight_Gsf_L1JetTauSeeded"};
   // TTreeReaderValue<Bool_t> HLT_Ele27_eta2p1_WPLoose_Gsf = {fReader, "HLT_Ele27_eta2p1_WPLoose_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele27_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1 = {fReader, "HLT_Ele27_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1"};
   // TTreeReaderValue<Bool_t> HLT_Ele27_eta2p1_WPTight_Gsf = {fReader, "HLT_Ele27_eta2p1_WPTight_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele30_WPTight_Gsf = {fReader, "HLT_Ele30_WPTight_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele30_eta2p1_WPLoose_Gsf = {fReader, "HLT_Ele30_eta2p1_WPLoose_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele30_eta2p1_WPTight_Gsf = {fReader, "HLT_Ele30_eta2p1_WPTight_Gsf"};
   // TTreeReaderValue<Bool_t> HLT_Ele32_WPTight_Gsf = {fReader, "HLT_Ele32_WPTight_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele32_eta2p1_WPLoose_Gsf = {fReader, "HLT_Ele32_eta2p1_WPLoose_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele32_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1 = {fReader, "HLT_Ele32_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1"};
//    TTreeReaderValue<Bool_t> HLT_Ele32_eta2p1_WPTight_Gsf = {fReader, "HLT_Ele32_eta2p1_WPTight_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele35_WPLoose_Gsf = {fReader, "HLT_Ele35_WPLoose_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele35_CaloIdVT_GsfTrkIdT_PFJet150_PFJet50 = {fReader, "HLT_Ele35_CaloIdVT_GsfTrkIdT_PFJet150_PFJet50"};
//    TTreeReaderValue<Bool_t> HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1 = {fReader, "HLT_Ele36_eta2p1_WPLoose_Gsf_LooseIsoPFTau20_SingleL1"};
//    TTreeReaderValue<Bool_t> HLT_Ele45_WPLoose_Gsf = {fReader, "HLT_Ele45_WPLoose_Gsf"};
//    TTreeReaderValue<Bool_t> HLT_Ele45_WPLoose_Gsf_L1JetTauSeeded = {fReader, "HLT_Ele45_WPLoose_Gsf_L1JetTauSeeded"};
//    TTreeReaderValue<Bool_t> HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50 = {fReader, "HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50"};
//    TTreeReaderValue<Bool_t> HLT_Ele105_CaloIdVT_GsfTrkIdT = {fReader, "HLT_Ele105_CaloIdVT_GsfTrkIdT"};
//    TTreeReaderValue<Bool_t> HLT_Ele30WP60_SC4_Mass55 = {fReader, "HLT_Ele30WP60_SC4_Mass55"};
//    TTreeReaderValue<Bool_t> HLT_Ele30WP60_Ele8_Mass55 = {fReader, "HLT_Ele30WP60_Ele8_Mass55"};
//    TTreeReaderValue<Bool_t> HLT_HT200 = {fReader, "HLT_HT200"};
//    TTreeReaderValue<Bool_t> HLT_HT275 = {fReader, "HLT_HT275"};
//    TTreeReaderValue<Bool_t> HLT_HT325 = {fReader, "HLT_HT325"};
//    TTreeReaderValue<Bool_t> HLT_HT425 = {fReader, "HLT_HT425"};
//    TTreeReaderValue<Bool_t> HLT_HT575 = {fReader, "HLT_HT575"};
//    TTreeReaderValue<Bool_t> HLT_HT410to430 = {fReader, "HLT_HT410to430"};
//    TTreeReaderValue<Bool_t> HLT_HT430to450 = {fReader, "HLT_HT430to450"};
//    TTreeReaderValue<Bool_t> HLT_HT450to470 = {fReader, "HLT_HT450to470"};
//    TTreeReaderValue<Bool_t> HLT_HT470to500 = {fReader, "HLT_HT470to500"};
//    TTreeReaderValue<Bool_t> HLT_HT500to550 = {fReader, "HLT_HT500to550"};
//    TTreeReaderValue<Bool_t> HLT_HT550to650 = {fReader, "HLT_HT550to650"};
//    TTreeReaderValue<Bool_t> HLT_HT650 = {fReader, "HLT_HT650"};
//    TTreeReaderValue<Bool_t> HLT_Mu16_eta2p1_MET30 = {fReader, "HLT_Mu16_eta2p1_MET30"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu16_eta2p1_MET30 = {fReader, "HLT_IsoMu16_eta2p1_MET30"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1 = {fReader, "HLT_IsoMu16_eta2p1_MET30_LooseIsoPFTau50_Trk30_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu17_eta2p1 = {fReader, "HLT_IsoMu17_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu17_eta2p1_LooseIsoPFTau20 = {fReader, "HLT_IsoMu17_eta2p1_LooseIsoPFTau20"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1 = {fReader, "HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1"};
//    TTreeReaderValue<Bool_t> HLT_DoubleIsoMu17_eta2p1 = {fReader, "HLT_DoubleIsoMu17_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_DoubleIsoMu17_eta2p1_noDzCut = {fReader, "HLT_DoubleIsoMu17_eta2p1_noDzCut"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu18 = {fReader, "HLT_IsoMu18"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu19_eta2p1_LooseIsoPFTau20 = {fReader, "HLT_IsoMu19_eta2p1_LooseIsoPFTau20"};
   //TTreeReaderValue<Bool_t> HLT_IsoMu19_eta2p1_LooseIsoPFTau20_SingleL1 = {fReader, "Flag_goodVertices"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu19_eta2p1_MediumIsoPFTau32_Trk1_eta2p1_Reg = {fReader, "HLT_IsoMu19_eta2p1_MediumIsoPFTau32_Trk1_eta2p1_Reg"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu19_eta2p1_LooseCombinedIsoPFTau20 = {fReader, "HLT_IsoMu19_eta2p1_LooseCombinedIsoPFTau20"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu19_eta2p1_MediumCombinedIsoPFTau32_Trk1_eta2p1_Reg = {fReader, "HLT_IsoMu19_eta2p1_MediumCombinedIsoPFTau32_Trk1_eta2p1_Reg"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu19_eta2p1_TightCombinedIsoPFTau32_Trk1_eta2p1_Reg = {fReader, "HLT_IsoMu19_eta2p1_TightCombinedIsoPFTau32_Trk1_eta2p1_Reg"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu21_eta2p1_MediumCombinedIsoPFTau32_Trk1_eta2p1_Reg = {fReader, "HLT_IsoMu21_eta2p1_MediumCombinedIsoPFTau32_Trk1_eta2p1_Reg"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu21_eta2p1_TightCombinedIsoPFTau32_Trk1_eta2p1_Reg = {fReader, "HLT_IsoMu21_eta2p1_TightCombinedIsoPFTau32_Trk1_eta2p1_Reg"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu20 = {fReader, "HLT_IsoMu20"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu21_eta2p1_LooseIsoPFTau20_SingleL1 = {fReader, "HLT_IsoMu21_eta2p1_LooseIsoPFTau20_SingleL1"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu21_eta2p1_LooseIsoPFTau50_Trk30_eta2p1_SingleL1 = {fReader, "HLT_IsoMu21_eta2p1_LooseIsoPFTau50_Trk30_eta2p1_SingleL1"};
//    TTreeReaderValue<Bool_t> HLT_IsoMu21_eta2p1_MediumIsoPFTau32_Trk1_eta2p1_Reg = {fReader, "HLT_IsoMu21_eta2p1_MediumIsoPFTau32_Trk1_eta2p1_Reg"};
   //TTreeReaderValue<Bool_t> HLT_IsoMu22 = {fReader, "Flag_goodVertices"};
   //TTreeReaderValue<Bool_t> HLT_IsoMu22_eta2p1 = {fReader, "Flag_goodVertices"};
//    TTreeReaderValue<Bool_t> HLT_IsoTkMu18 = {fReader, "HLT_IsoTkMu18"};
//    TTreeReaderValue<Bool_t> HLT_IsoTkMu20 = {fReader, "HLT_IsoTkMu20"};
   //TTreeReaderValue<Bool_t> HLT_IsoTkMu22 = {fReader, "Flag_goodVertices"};
   //TTreeReaderValue<Bool_t> HLT_IsoTkMu22_eta2p1 = {fReader, "Flag_goodVertices"};
   //TTreeReaderValue<Bool_t> HLT_IsoTkMu24 = {fReader, "Flag_goodVertices"};
//    TTreeReaderValue<Bool_t> HLT_IsoTkMu27 = {fReader, "HLT_IsoTkMu27"};
//    TTreeReaderValue<Bool_t> HLT_JetE30_NoBPTX3BX = {fReader, "HLT_JetE30_NoBPTX3BX"};
//    TTreeReaderValue<Bool_t> HLT_JetE30_NoBPTX = {fReader, "HLT_JetE30_NoBPTX"};
//    TTreeReaderValue<Bool_t> HLT_JetE50_NoBPTX3BX = {fReader, "HLT_JetE50_NoBPTX3BX"};
//    TTreeReaderValue<Bool_t> HLT_JetE70_NoBPTX3BX = {fReader, "HLT_JetE70_NoBPTX3BX"};
//    TTreeReaderValue<Bool_t> HLT_L1SingleMu18 = {fReader, "HLT_L1SingleMu18"};
//    TTreeReaderValue<Bool_t> HLT_L2Mu10 = {fReader, "HLT_L2Mu10"};
//    TTreeReaderValue<Bool_t> HLT_L1SingleMuOpen = {fReader, "HLT_L1SingleMuOpen"};
//    TTreeReaderValue<Bool_t> HLT_L1SingleMuOpen_DT = {fReader, "HLT_L1SingleMuOpen_DT"};
//    TTreeReaderValue<Bool_t> HLT_L2DoubleMu23_NoVertex = {fReader, "HLT_L2DoubleMu23_NoVertex"};
//    TTreeReaderValue<Bool_t> HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10 = {fReader, "HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10"};
//    TTreeReaderValue<Bool_t> HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10 = {fReader, "HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10"};
//    TTreeReaderValue<Bool_t> HLT_L2Mu10_NoVertex_NoBPTX3BX = {fReader, "HLT_L2Mu10_NoVertex_NoBPTX3BX"};
//    TTreeReaderValue<Bool_t> HLT_L2Mu10_NoVertex_NoBPTX = {fReader, "HLT_L2Mu10_NoVertex_NoBPTX"};
//    TTreeReaderValue<Bool_t> HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX = {fReader, "HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX"};
//    TTreeReaderValue<Bool_t> HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX = {fReader, "HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX"};
//    TTreeReaderValue<Bool_t> HLT_LooseIsoPFTau50_Trk30_eta2p1 = {fReader, "HLT_LooseIsoPFTau50_Trk30_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80 = {fReader, "HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80"};
//    TTreeReaderValue<Bool_t> HLT_LooseIsoPFTau50_Trk30_eta2p1_MET90 = {fReader, "HLT_LooseIsoPFTau50_Trk30_eta2p1_MET90"};
//    TTreeReaderValue<Bool_t> HLT_LooseIsoPFTau50_Trk30_eta2p1_MET110 = {fReader, "HLT_LooseIsoPFTau50_Trk30_eta2p1_MET110"};
//    TTreeReaderValue<Bool_t> HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120 = {fReader, "HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120"};
//    TTreeReaderValue<Bool_t> HLT_PFTau120_eta2p1 = {fReader, "HLT_PFTau120_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_PFTau140_eta2p1 = {fReader, "HLT_PFTau140_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_VLooseIsoPFTau120_Trk50_eta2p1 = {fReader, "HLT_VLooseIsoPFTau120_Trk50_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_VLooseIsoPFTau140_Trk50_eta2p1 = {fReader, "HLT_VLooseIsoPFTau140_Trk50_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_Mu17_Mu8 = {fReader, "HLT_Mu17_Mu8"};
//    TTreeReaderValue<Bool_t> HLT_Mu17_Mu8_DZ = {fReader, "HLT_Mu17_Mu8_DZ"};
//    TTreeReaderValue<Bool_t> HLT_Mu17_Mu8_SameSign = {fReader, "HLT_Mu17_Mu8_SameSign"};
//    TTreeReaderValue<Bool_t> HLT_Mu17_Mu8_SameSign_DZ = {fReader, "HLT_Mu17_Mu8_SameSign_DZ"};
//    TTreeReaderValue<Bool_t> HLT_Mu20_Mu10 = {fReader, "HLT_Mu20_Mu10"};
//    TTreeReaderValue<Bool_t> HLT_Mu20_Mu10_DZ = {fReader, "HLT_Mu20_Mu10_DZ"};
//    TTreeReaderValue<Bool_t> HLT_Mu20_Mu10_SameSign = {fReader, "HLT_Mu20_Mu10_SameSign"};
//    TTreeReaderValue<Bool_t> HLT_Mu20_Mu10_SameSign_DZ = {fReader, "HLT_Mu20_Mu10_SameSign_DZ"};
//    TTreeReaderValue<Bool_t> HLT_Mu17_TkMu8_DZ = {fReader, "HLT_Mu17_TkMu8_DZ"};
   //TTreeReaderValue<Bool_t> HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = {fReader, "Flag_goodVertices"};
   //TTreeReaderValue<Bool_t> HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ = {fReader, "Flag_goodVertices"};
   //TTreeReaderValue<Bool_t> HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL = {fReader, "Flag_goodVertices"};
   //TTreeReaderValue<Bool_t> HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ = {fReader, "Flag_goodVertices"};
//    TTreeReaderValue<Bool_t> HLT_Mu25_TkMu0_dEta18_Onia = {fReader, "HLT_Mu25_TkMu0_dEta18_Onia"};
//    TTreeReaderValue<Bool_t> HLT_Mu27_TkMu8 = {fReader, "HLT_Mu27_TkMu8"};
//    TTreeReaderValue<Bool_t> HLT_Mu30_TkMu11 = {fReader, "HLT_Mu30_TkMu11"};
//    TTreeReaderValue<Bool_t> HLT_Mu30_eta2p1_PFJet150_PFJet50 = {fReader, "HLT_Mu30_eta2p1_PFJet150_PFJet50"};
//    TTreeReaderValue<Bool_t> HLT_Mu40_TkMu11 = {fReader, "HLT_Mu40_TkMu11"};
//    TTreeReaderValue<Bool_t> HLT_Mu40_eta2p1_PFJet200_PFJet50 = {fReader, "HLT_Mu40_eta2p1_PFJet200_PFJet50"};
//    TTreeReaderValue<Bool_t> HLT_Mu20 = {fReader, "HLT_Mu20"};
//    TTreeReaderValue<Bool_t> HLT_TkMu17 = {fReader, "HLT_TkMu17"};
//    TTreeReaderValue<Bool_t> HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL = {fReader, "HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL"};
//    TTreeReaderValue<Bool_t> HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ = {fReader, "HLT_TkMu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ"};
//    TTreeReaderValue<Bool_t> HLT_TkMu20 = {fReader, "HLT_TkMu20"};
//    TTreeReaderValue<Bool_t> HLT_Mu24_eta2p1 = {fReader, "HLT_Mu24_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_TkMu24_eta2p1 = {fReader, "HLT_TkMu24_eta2p1"};
//    TTreeReaderValue<Bool_t> HLT_Mu27 = {fReader, "HLT_Mu27"};
//    TTreeReaderValue<Bool_t> HLT_TkMu27 = {fReader, "HLT_TkMu27"};
//    TTreeReaderValue<Bool_t> HLT_Mu45_eta2p1 = {fReader, "HLT_Mu45_eta2p1"};
   //TTreeReaderValue<Bool_t> HLT_Mu50 = {fReader, "Flag_goodVertices"};
   //TTreeReaderValue<Bool_t> HLT_TkMu50 = {fReader, "Flag_goodVertices"};
//    TTreeReaderValue<Bool_t> HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL = {fReader, "HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL"};
//    TTreeReaderValue<Bool_t> HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL = {fReader, "HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL"};
//    TTreeReaderValue<Bool_t> HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL = {fReader, "HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL"};
//    TTreeReaderValue<Bool_t> HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL = {fReader, "HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL"};
//    TTreeReaderValue<Bool_t> HLT_Mu23NoFiltersNoVtx_Photon23_CaloIdL = {fReader, "HLT_Mu23NoFiltersNoVtx_Photon23_CaloIdL"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu18NoFiltersNoVtx = {fReader, "HLT_DoubleMu18NoFiltersNoVtx"};
//    TTreeReaderValue<Bool_t> HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight = {fReader, "HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Tight"};
//    TTreeReaderValue<Bool_t> HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose = {fReader, "HLT_Mu33NoFiltersNoVtxDisplaced_DisplacedJet50_Loose"};
//    TTreeReaderValue<Bool_t> HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose = {fReader, "HLT_Mu28NoFiltersNoVtx_DisplacedJet40_Loose"};
//    TTreeReaderValue<Bool_t> HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight = {fReader, "HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Tight"};
//    TTreeReaderValue<Bool_t> HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose = {fReader, "HLT_Mu38NoFiltersNoVtxDisplaced_DisplacedJet60_Loose"};
//    TTreeReaderValue<Bool_t> HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose = {fReader, "HLT_Mu38NoFiltersNoVtx_DisplacedJet60_Loose"};
//    TTreeReaderValue<Bool_t> HLT_Mu28NoFiltersNoVtx_CentralCaloJet40 = {fReader, "HLT_Mu28NoFiltersNoVtx_CentralCaloJet40"};
//    TTreeReaderValue<Bool_t> HLT_PFHT300_PFMET100 = {fReader, "HLT_PFHT300_PFMET100"};
//    TTreeReaderValue<Bool_t> HLT_PFHT300_PFMET110 = {fReader, "HLT_PFHT300_PFMET110"};
//    TTreeReaderValue<Bool_t> HLT_PFHT550_4JetPt50 = {fReader, "HLT_PFHT550_4JetPt50"};
//    TTreeReaderValue<Bool_t> HLT_PFHT650_4JetPt50 = {fReader, "HLT_PFHT650_4JetPt50"};
//    TTreeReaderValue<Bool_t> HLT_PFHT750_4JetPt50 = {fReader, "HLT_PFHT750_4JetPt50"};
//    TTreeReaderValue<Bool_t> HLT_PFHT750_4JetPt70 = {fReader, "HLT_PFHT750_4JetPt70"};
//    TTreeReaderValue<Bool_t> HLT_PFHT750_4JetPt80 = {fReader, "HLT_PFHT750_4JetPt80"};
//    TTreeReaderValue<Bool_t> HLT_PFHT800_4JetPt50 = {fReader, "HLT_PFHT800_4JetPt50"};
//    TTreeReaderValue<Bool_t> HLT_PFHT850_4JetPt50 = {fReader, "HLT_PFHT850_4JetPt50"};
//    TTreeReaderValue<Bool_t> HLT_PFJet15_NoCaloMatched = {fReader, "HLT_PFJet15_NoCaloMatched"};
//    TTreeReaderValue<Bool_t> HLT_PFJet25_NoCaloMatched = {fReader, "HLT_PFJet25_NoCaloMatched"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJet15_NoCaloMatched = {fReader, "HLT_DiPFJet15_NoCaloMatched"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJet25_NoCaloMatched = {fReader, "HLT_DiPFJet25_NoCaloMatched"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJet15_FBEta3_NoCaloMatched = {fReader, "HLT_DiPFJet15_FBEta3_NoCaloMatched"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJet25_FBEta3_NoCaloMatched = {fReader, "HLT_DiPFJet25_FBEta3_NoCaloMatched"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve15_HFJEC = {fReader, "HLT_DiPFJetAve15_HFJEC"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve25_HFJEC = {fReader, "HLT_DiPFJetAve25_HFJEC"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve35_HFJEC = {fReader, "HLT_DiPFJetAve35_HFJEC"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet40 = {fReader, "HLT_AK8PFJet40"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet60 = {fReader, "HLT_AK8PFJet60"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet80 = {fReader, "HLT_AK8PFJet80"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet140 = {fReader, "HLT_AK8PFJet140"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet200 = {fReader, "HLT_AK8PFJet200"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet260 = {fReader, "HLT_AK8PFJet260"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet320 = {fReader, "HLT_AK8PFJet320"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet400 = {fReader, "HLT_AK8PFJet400"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet450 = {fReader, "HLT_AK8PFJet450"};
//    TTreeReaderValue<Bool_t> HLT_AK8PFJet500 = {fReader, "HLT_AK8PFJet500"};
//    TTreeReaderValue<Bool_t> HLT_PFJet40 = {fReader, "HLT_PFJet40"};
//    TTreeReaderValue<Bool_t> HLT_PFJet60 = {fReader, "HLT_PFJet60"};
//    TTreeReaderValue<Bool_t> HLT_PFJet80 = {fReader, "HLT_PFJet80"};
//    TTreeReaderValue<Bool_t> HLT_PFJet140 = {fReader, "HLT_PFJet140"};
//    TTreeReaderValue<Bool_t> HLT_PFJet200 = {fReader, "HLT_PFJet200"};
//    TTreeReaderValue<Bool_t> HLT_PFJet260 = {fReader, "HLT_PFJet260"};
//    TTreeReaderValue<Bool_t> HLT_PFJet320 = {fReader, "HLT_PFJet320"};
//    TTreeReaderValue<Bool_t> HLT_PFJet400 = {fReader, "HLT_PFJet400"};
//    TTreeReaderValue<Bool_t> HLT_PFJet500 = {fReader, "HLT_PFJet500"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve40 = {fReader, "HLT_DiPFJetAve40"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve60 = {fReader, "HLT_DiPFJetAve60"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve80 = {fReader, "HLT_DiPFJetAve80"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve140 = {fReader, "HLT_DiPFJetAve140"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve200 = {fReader, "HLT_DiPFJetAve200"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve260 = {fReader, "HLT_DiPFJetAve260"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve320 = {fReader, "HLT_DiPFJetAve320"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve400 = {fReader, "HLT_DiPFJetAve400"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve500 = {fReader, "HLT_DiPFJetAve500"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve60_HFJEC = {fReader, "HLT_DiPFJetAve60_HFJEC"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve80_HFJEC = {fReader, "HLT_DiPFJetAve80_HFJEC"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve100_HFJEC = {fReader, "HLT_DiPFJetAve100_HFJEC"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve160_HFJEC = {fReader, "HLT_DiPFJetAve160_HFJEC"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve220_HFJEC = {fReader, "HLT_DiPFJetAve220_HFJEC"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJetAve300_HFJEC = {fReader, "HLT_DiPFJetAve300_HFJEC"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140 = {fReader, "HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140"};
//    TTreeReaderValue<Bool_t> HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80 = {fReader, "HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80"};
//    TTreeReaderValue<Bool_t> HLT_DiCentralPFJet170 = {fReader, "HLT_DiCentralPFJet170"};
//    TTreeReaderValue<Bool_t> HLT_SingleCentralPFJet170_CFMax0p1 = {fReader, "HLT_SingleCentralPFJet170_CFMax0p1"};
//    TTreeReaderValue<Bool_t> HLT_DiCentralPFJet170_CFMax0p1 = {fReader, "HLT_DiCentralPFJet170_CFMax0p1"};
//    TTreeReaderValue<Bool_t> HLT_DiCentralPFJet220_CFMax0p3 = {fReader, "HLT_DiCentralPFJet220_CFMax0p3"};
//    TTreeReaderValue<Bool_t> HLT_DiCentralPFJet330_CFMax0p5 = {fReader, "HLT_DiCentralPFJet330_CFMax0p5"};
//    TTreeReaderValue<Bool_t> HLT_DiCentralPFJet430 = {fReader, "HLT_DiCentralPFJet430"};
//    TTreeReaderValue<Bool_t> HLT_PFHT125 = {fReader, "HLT_PFHT125"};
//    TTreeReaderValue<Bool_t> HLT_PFHT200 = {fReader, "HLT_PFHT200"};
//    TTreeReaderValue<Bool_t> HLT_PFHT250 = {fReader, "HLT_PFHT250"};
//    TTreeReaderValue<Bool_t> HLT_PFHT300 = {fReader, "HLT_PFHT300"};
//    TTreeReaderValue<Bool_t> HLT_PFHT350 = {fReader, "HLT_PFHT350"};
//    TTreeReaderValue<Bool_t> HLT_PFHT400 = {fReader, "HLT_PFHT400"};
//    TTreeReaderValue<Bool_t> HLT_PFHT475 = {fReader, "HLT_PFHT475"};
//    TTreeReaderValue<Bool_t> HLT_PFHT600 = {fReader, "HLT_PFHT600"};
//    TTreeReaderValue<Bool_t> HLT_PFHT650 = {fReader, "HLT_PFHT650"};
//    TTreeReaderValue<Bool_t> HLT_PFHT800 = {fReader, "HLT_PFHT800"};
//    TTreeReaderValue<Bool_t> HLT_PFHT900 = {fReader, "HLT_PFHT900"};
//    TTreeReaderValue<Bool_t> HLT_PFHT200_PFAlphaT0p51 = {fReader, "HLT_PFHT200_PFAlphaT0p51"};
//    TTreeReaderValue<Bool_t> HLT_PFHT200_DiPFJetAve90_PFAlphaT0p57 = {fReader, "HLT_PFHT200_DiPFJetAve90_PFAlphaT0p57"};
//    TTreeReaderValue<Bool_t> HLT_PFHT200_DiPFJetAve90_PFAlphaT0p63 = {fReader, "HLT_PFHT200_DiPFJetAve90_PFAlphaT0p63"};
//    TTreeReaderValue<Bool_t> HLT_PFHT250_DiPFJetAve90_PFAlphaT0p55 = {fReader, "HLT_PFHT250_DiPFJetAve90_PFAlphaT0p55"};
//    TTreeReaderValue<Bool_t> HLT_PFHT250_DiPFJetAve90_PFAlphaT0p58 = {fReader, "HLT_PFHT250_DiPFJetAve90_PFAlphaT0p58"};
//    TTreeReaderValue<Bool_t> HLT_PFHT300_DiPFJetAve90_PFAlphaT0p53 = {fReader, "HLT_PFHT300_DiPFJetAve90_PFAlphaT0p53"};
//    TTreeReaderValue<Bool_t> HLT_PFHT300_DiPFJetAve90_PFAlphaT0p54 = {fReader, "HLT_PFHT300_DiPFJetAve90_PFAlphaT0p54"};
//    TTreeReaderValue<Bool_t> HLT_PFHT350_DiPFJetAve90_PFAlphaT0p52 = {fReader, "HLT_PFHT350_DiPFJetAve90_PFAlphaT0p52"};
//    TTreeReaderValue<Bool_t> HLT_PFHT350_DiPFJetAve90_PFAlphaT0p53 = {fReader, "HLT_PFHT350_DiPFJetAve90_PFAlphaT0p53"};
//    TTreeReaderValue<Bool_t> HLT_PFHT400_DiPFJetAve90_PFAlphaT0p51 = {fReader, "HLT_PFHT400_DiPFJetAve90_PFAlphaT0p51"};
//    TTreeReaderValue<Bool_t> HLT_PFHT400_DiPFJetAve90_PFAlphaT0p52 = {fReader, "HLT_PFHT400_DiPFJetAve90_PFAlphaT0p52"};
//    TTreeReaderValue<Bool_t> HLT_MET60_IsoTrk35_Loose = {fReader, "HLT_MET60_IsoTrk35_Loose"};
//    TTreeReaderValue<Bool_t> HLT_MET75_IsoTrk50 = {fReader, "HLT_MET75_IsoTrk50"};
//    TTreeReaderValue<Bool_t> HLT_MET90_IsoTrk50 = {fReader, "HLT_MET90_IsoTrk50"};
//    TTreeReaderValue<Bool_t> HLT_PFMET120_BTagCSV_p067 = {fReader, "HLT_PFMET120_BTagCSV_p067"};
//    TTreeReaderValue<Bool_t> HLT_PFMET120_Mu5 = {fReader, "HLT_PFMET120_Mu5"};
//    TTreeReaderValue<Bool_t> HLT_PFMET170_NotCleaned = {fReader, "HLT_PFMET170_NotCleaned"};
//    TTreeReaderValue<Bool_t> HLT_PFMET170_NoiseCleaned = {fReader, "HLT_PFMET170_NoiseCleaned"};
//    TTreeReaderValue<Bool_t> HLT_PFMET170_HBHECleaned = {fReader, "HLT_PFMET170_HBHECleaned"};
//    TTreeReaderValue<Bool_t> HLT_PFMET170_JetIdCleaned = {fReader, "HLT_PFMET170_JetIdCleaned"};
//    TTreeReaderValue<Bool_t> HLT_PFMET170_BeamHaloCleaned = {fReader, "HLT_PFMET170_BeamHaloCleaned"};
//    TTreeReaderValue<Bool_t> HLT_PFMET170_HBHE_BeamHaloCleaned = {fReader, "HLT_PFMET170_HBHE_BeamHaloCleaned"};
//    TTreeReaderValue<Bool_t> HLT_PFMETTypeOne190_HBHE_BeamHaloCleaned = {fReader, "HLT_PFMETTypeOne190_HBHE_BeamHaloCleaned"};
//    TTreeReaderValue<Bool_t> HLT_PFMET90_PFMHT90_IDTight = {fReader, "HLT_PFMET90_PFMHT90_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_PFMET100_PFMHT100_IDTight = {fReader, "HLT_PFMET100_PFMHT100_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_PFMET100_PFMHT100_IDTight_BeamHaloCleaned = {fReader, "HLT_PFMET100_PFMHT100_IDTight_BeamHaloCleaned"};
//    TTreeReaderValue<Bool_t> HLT_PFMET110_PFMHT110_IDTight = {fReader, "HLT_PFMET110_PFMHT110_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_PFMET120_PFMHT120_IDTight = {fReader, "HLT_PFMET120_PFMHT120_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067 = {fReader, "HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight_BTagCSV_p067"};
//    TTreeReaderValue<Bool_t> HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight = {fReader, "HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200 = {fReader, "HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq200"};
//    TTreeReaderValue<Bool_t> HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460 = {fReader, "HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq460"};
//    TTreeReaderValue<Bool_t> HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240 = {fReader, "HLT_QuadPFJet_BTagCSV_p016_p11_VBF_Mqq240"};
//    TTreeReaderValue<Bool_t> HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500 = {fReader, "HLT_QuadPFJet_BTagCSV_p016_VBF_Mqq500"};
//    TTreeReaderValue<Bool_t> HLT_QuadPFJet_VBF = {fReader, "HLT_QuadPFJet_VBF"};
//    TTreeReaderValue<Bool_t> HLT_L1_TripleJet_VBF = {fReader, "HLT_L1_TripleJet_VBF"};
//    TTreeReaderValue<Bool_t> HLT_QuadJet45_TripleBTagCSV_p087 = {fReader, "HLT_QuadJet45_TripleBTagCSV_p087"};
//    TTreeReaderValue<Bool_t> HLT_QuadJet45_DoubleBTagCSV_p087 = {fReader, "HLT_QuadJet45_DoubleBTagCSV_p087"};
//    TTreeReaderValue<Bool_t> HLT_DoubleJet90_Double30_TripleBTagCSV_p087 = {fReader, "HLT_DoubleJet90_Double30_TripleBTagCSV_p087"};
//    TTreeReaderValue<Bool_t> HLT_DoubleJet90_Double30_DoubleBTagCSV_p087 = {fReader, "HLT_DoubleJet90_Double30_DoubleBTagCSV_p087"};
//    TTreeReaderValue<Bool_t> HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160 = {fReader, "HLT_DoubleJetsC100_DoubleBTagCSV_p026_DoublePFJetsC160"};
//    TTreeReaderValue<Bool_t> HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6 = {fReader, "HLT_DoubleJetsC100_DoubleBTagCSV_p014_DoublePFJetsC100MaxDeta1p6"};
//    TTreeReaderValue<Bool_t> HLT_DoubleJetsC112_DoubleBTagCSV_p026_DoublePFJetsC172 = {fReader, "HLT_DoubleJetsC112_DoubleBTagCSV_p026_DoublePFJetsC172"};
//    TTreeReaderValue<Bool_t> HLT_DoubleJetsC112_DoubleBTagCSV_p014_DoublePFJetsC112MaxDeta1p6 = {fReader, "HLT_DoubleJetsC112_DoubleBTagCSV_p014_DoublePFJetsC112MaxDeta1p6"};
//    TTreeReaderValue<Bool_t> HLT_DoubleJetsC100_SingleBTagCSV_p026 = {fReader, "HLT_DoubleJetsC100_SingleBTagCSV_p026"};
//    TTreeReaderValue<Bool_t> HLT_DoubleJetsC100_SingleBTagCSV_p014 = {fReader, "HLT_DoubleJetsC100_SingleBTagCSV_p014"};
//    TTreeReaderValue<Bool_t> HLT_DoubleJetsC100_SingleBTagCSV_p026_SinglePFJetC350 = {fReader, "HLT_DoubleJetsC100_SingleBTagCSV_p026_SinglePFJetC350"};
//    TTreeReaderValue<Bool_t> HLT_DoubleJetsC100_SingleBTagCSV_p014_SinglePFJetC350 = {fReader, "HLT_DoubleJetsC100_SingleBTagCSV_p014_SinglePFJetC350"};
//    TTreeReaderValue<Bool_t> HLT_Photon135_PFMET100 = {fReader, "HLT_Photon135_PFMET100"};
//    TTreeReaderValue<Bool_t> HLT_Photon20_CaloIdVL_IsoL = {fReader, "HLT_Photon20_CaloIdVL_IsoL"};
//    TTreeReaderValue<Bool_t> HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40 = {fReader, "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40"};
//    TTreeReaderValue<Bool_t> HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF = {fReader, "HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF"};
//    TTreeReaderValue<Bool_t> HLT_Photon250_NoHE = {fReader, "HLT_Photon250_NoHE"};
//    TTreeReaderValue<Bool_t> HLT_Photon300_NoHE = {fReader, "HLT_Photon300_NoHE"};
//    TTreeReaderValue<Bool_t> HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60 = {fReader, "HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60"};
//    TTreeReaderValue<Bool_t> HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15 = {fReader, "HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15"};
//    TTreeReaderValue<Bool_t> HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40 = {fReader, "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40"};
//    TTreeReaderValue<Bool_t> HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF = {fReader, "HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF"};
//    TTreeReaderValue<Bool_t> HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40 = {fReader, "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40"};
//    TTreeReaderValue<Bool_t> HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF = {fReader, "HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF"};
//    TTreeReaderValue<Bool_t> HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40 = {fReader, "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40"};
//    TTreeReaderValue<Bool_t> HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF = {fReader, "HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF"};
//    TTreeReaderValue<Bool_t> HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40 = {fReader, "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40"};
//    TTreeReaderValue<Bool_t> HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF = {fReader, "HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF"};
//    TTreeReaderValue<Bool_t> HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40 = {fReader, "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40"};
//    TTreeReaderValue<Bool_t> HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF = {fReader, "HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF"};
//    TTreeReaderValue<Bool_t> HLT_Mu8_TrkIsoVVL = {fReader, "HLT_Mu8_TrkIsoVVL"};
//    TTreeReaderValue<Bool_t> HLT_Mu17_TrkIsoVVL = {fReader, "HLT_Mu17_TrkIsoVVL"};
//    TTreeReaderValue<Bool_t> HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 = {fReader, "HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30"};
//    TTreeReaderValue<Bool_t> HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 = {fReader, "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30"};
//    TTreeReaderValue<Bool_t> HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30 = {fReader, "HLT_Ele17_CaloIdL_TrackIdL_IsoVL_PFJet30"};
//    TTreeReaderValue<Bool_t> HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 = {fReader, "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30"};
//    TTreeReaderValue<Bool_t> HLT_BTagMu_DiJet20_Mu5 = {fReader, "HLT_BTagMu_DiJet20_Mu5"};
//    TTreeReaderValue<Bool_t> HLT_BTagMu_DiJet40_Mu5 = {fReader, "HLT_BTagMu_DiJet40_Mu5"};
//    TTreeReaderValue<Bool_t> HLT_BTagMu_DiJet70_Mu5 = {fReader, "HLT_BTagMu_DiJet70_Mu5"};
//    TTreeReaderValue<Bool_t> HLT_BTagMu_DiJet110_Mu5 = {fReader, "HLT_BTagMu_DiJet110_Mu5"};
//    TTreeReaderValue<Bool_t> HLT_BTagMu_DiJet170_Mu5 = {fReader, "HLT_BTagMu_DiJet170_Mu5"};
//    TTreeReaderValue<Bool_t> HLT_BTagMu_Jet300_Mu5 = {fReader, "HLT_BTagMu_Jet300_Mu5"};
//    TTreeReaderValue<Bool_t> HLT_BTagMu_AK8Jet300_Mu5 = {fReader, "HLT_BTagMu_AK8Jet300_Mu5"};
   // TTreeReaderValue<Bool_t> HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = {fReader, "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"};
//    TTreeReaderValue<Bool_t> HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded = {fReader, "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_L1JetTauSeeded"};
//    TTreeReaderValue<Bool_t> HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = {fReader, "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"};
   // TTreeReaderValue<Bool_t> HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL = {fReader, "HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL"};
//    TTreeReaderValue<Bool_t> HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL"};
   // TTreeReaderValue<Bool_t> HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"};//MuonEG
   // TTreeReaderValue<Bool_t> HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ = {fReader, "HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"};
//    TTreeReaderValue<Bool_t> HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"};
   // TTreeReaderValue<Bool_t> HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ = {fReader, "HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"};
//    TTreeReaderValue<Bool_t> HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL"};
   // TTreeReaderValue<Bool_t> HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL"};
   // TTreeReaderValue<Bool_t> HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ = {fReader, "HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ"};
   // TTreeReaderValue<Bool_t> HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL"};
   // TTreeReaderValue<Bool_t> HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = {fReader, "HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"};
//    TTreeReaderValue<Bool_t> HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL = {fReader, "HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL"};
//    TTreeReaderValue<Bool_t> HLT_Mu33_Ele33_CaloIdL_GsfTrkIdVL = {fReader, "HLT_Mu33_Ele33_CaloIdL_GsfTrkIdVL"};
//    TTreeReaderValue<Bool_t> HLT_Mu37_Ele27_CaloIdL_GsfTrkIdVL = {fReader, "HLT_Mu37_Ele27_CaloIdL_GsfTrkIdVL"};
//    TTreeReaderValue<Bool_t> HLT_Mu27_Ele37_CaloIdL_GsfTrkIdVL = {fReader, "HLT_Mu27_Ele37_CaloIdL_GsfTrkIdVL"};
   // TTreeReaderValue<Bool_t> HLT_Mu8_DiEle12_CaloIdL_TrackIdL = {fReader, "HLT_Mu8_DiEle12_CaloIdL_TrackIdL"};
//    TTreeReaderValue<Bool_t> HLT_Mu12_Photon25_CaloIdL = {fReader, "HLT_Mu12_Photon25_CaloIdL"};
//    TTreeReaderValue<Bool_t> HLT_Mu12_Photon25_CaloIdL_L1ISO = {fReader, "HLT_Mu12_Photon25_CaloIdL_L1ISO"};
//    TTreeReaderValue<Bool_t> HLT_Mu12_Photon25_CaloIdL_L1OR = {fReader, "HLT_Mu12_Photon25_CaloIdL_L1OR"};
//    TTreeReaderValue<Bool_t> HLT_Mu17_Photon22_CaloIdL_L1ISO = {fReader, "HLT_Mu17_Photon22_CaloIdL_L1ISO"};
//    TTreeReaderValue<Bool_t> HLT_Mu17_Photon30_CaloIdL_L1ISO = {fReader, "HLT_Mu17_Photon30_CaloIdL_L1ISO"};
//    TTreeReaderValue<Bool_t> HLT_Mu17_Photon35_CaloIdL_L1ISO = {fReader, "HLT_Mu17_Photon35_CaloIdL_L1ISO"};
   // TTreeReaderValue<Bool_t> HLT_DiMu9_Ele9_CaloIdL_TrackIdL = {fReader, "HLT_DiMu9_Ele9_CaloIdL_TrackIdL"};
//    TTreeReaderValue<Bool_t> HLT_TripleMu_5_3_3 = {fReader, "HLT_TripleMu_5_3_3"};
   //TTreeReaderValue<Bool_t> HLT_TripleMu_12_10_5 = {fReader, "Flag_goodVertices"};
//    TTreeReaderValue<Bool_t> HLT_Mu3er_PFHT140_PFMET125 = {fReader, "HLT_Mu3er_PFHT140_PFMET125"};
//    TTreeReaderValue<Bool_t> HLT_Mu6_PFHT200_PFMET80_BTagCSV_p067 = {fReader, "HLT_Mu6_PFHT200_PFMET80_BTagCSV_p067"};
//    TTreeReaderValue<Bool_t> HLT_Mu6_PFHT200_PFMET100 = {fReader, "HLT_Mu6_PFHT200_PFMET100"};
//    TTreeReaderValue<Bool_t> HLT_Mu14er_PFMET100 = {fReader, "HLT_Mu14er_PFMET100"};
//    TTreeReaderValue<Bool_t> HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL"};
   // TTreeReaderValue<Bool_t> HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL"};
//    TTreeReaderValue<Bool_t> HLT_Ele12_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Ele12_CaloIdL_TrackIdL_IsoVL"};
//    TTreeReaderValue<Bool_t> HLT_Ele17_CaloIdL_GsfTrkIdVL = {fReader, "HLT_Ele17_CaloIdL_GsfTrkIdVL"};
//    TTreeReaderValue<Bool_t> HLT_Ele17_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Ele17_CaloIdL_TrackIdL_IsoVL"};
//    TTreeReaderValue<Bool_t> HLT_Ele23_CaloIdL_TrackIdL_IsoVL = {fReader, "HLT_Ele23_CaloIdL_TrackIdL_IsoVL"};
//    TTreeReaderValue<Bool_t> HLT_PFHT650_WideJetMJJ900DEtaJJ1p5 = {fReader, "HLT_PFHT650_WideJetMJJ900DEtaJJ1p5"};
//    TTreeReaderValue<Bool_t> HLT_PFHT650_WideJetMJJ950DEtaJJ1p5 = {fReader, "HLT_PFHT650_WideJetMJJ950DEtaJJ1p5"};
//    TTreeReaderValue<Bool_t> HLT_Photon22 = {fReader, "HLT_Photon22"};
//    TTreeReaderValue<Bool_t> HLT_Photon30 = {fReader, "HLT_Photon30"};
//    TTreeReaderValue<Bool_t> HLT_Photon36 = {fReader, "HLT_Photon36"};
//    TTreeReaderValue<Bool_t> HLT_Photon50 = {fReader, "HLT_Photon50"};
//    TTreeReaderValue<Bool_t> HLT_Photon75 = {fReader, "HLT_Photon75"};
//    TTreeReaderValue<Bool_t> HLT_Photon90 = {fReader, "HLT_Photon90"};
//    TTreeReaderValue<Bool_t> HLT_Photon120 = {fReader, "HLT_Photon120"};
//    TTreeReaderValue<Bool_t> HLT_Photon175 = {fReader, "HLT_Photon175"};
//    TTreeReaderValue<Bool_t> HLT_Photon165_HE10 = {fReader, "HLT_Photon165_HE10"};
//    TTreeReaderValue<Bool_t> HLT_Photon22_R9Id90_HE10_IsoM = {fReader, "HLT_Photon22_R9Id90_HE10_IsoM"};
//    TTreeReaderValue<Bool_t> HLT_Photon30_R9Id90_HE10_IsoM = {fReader, "HLT_Photon30_R9Id90_HE10_IsoM"};
//    TTreeReaderValue<Bool_t> HLT_Photon36_R9Id90_HE10_IsoM = {fReader, "HLT_Photon36_R9Id90_HE10_IsoM"};
//    TTreeReaderValue<Bool_t> HLT_Photon50_R9Id90_HE10_IsoM = {fReader, "HLT_Photon50_R9Id90_HE10_IsoM"};
//    TTreeReaderValue<Bool_t> HLT_Photon75_R9Id90_HE10_IsoM = {fReader, "HLT_Photon75_R9Id90_HE10_IsoM"};
//    TTreeReaderValue<Bool_t> HLT_Photon90_R9Id90_HE10_IsoM = {fReader, "HLT_Photon90_R9Id90_HE10_IsoM"};
//    TTreeReaderValue<Bool_t> HLT_Photon120_R9Id90_HE10_IsoM = {fReader, "HLT_Photon120_R9Id90_HE10_IsoM"};
//    TTreeReaderValue<Bool_t> HLT_Photon165_R9Id90_HE10_IsoM = {fReader, "HLT_Photon165_R9Id90_HE10_IsoM"};
//    TTreeReaderValue<Bool_t> HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90 = {fReader, "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90"};
//    TTreeReaderValue<Bool_t> HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70 = {fReader, "HLT_Diphoton30_18_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelSeedMatch_Mass70"};
//    TTreeReaderValue<Bool_t> HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = {fReader, "HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55"};
//    TTreeReaderValue<Bool_t> HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55 = {fReader, "HLT_Diphoton30_18_Solid_R9Id_AND_IsoCaloId_AND_HE_R9Id_Mass55"};
//    TTreeReaderValue<Bool_t> HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55 = {fReader, "HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_DoublePixelVeto_Mass55"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon0_Jpsi_Muon = {fReader, "HLT_Dimuon0_Jpsi_Muon"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon0_Upsilon_Muon = {fReader, "HLT_Dimuon0_Upsilon_Muon"};
//    TTreeReaderValue<Bool_t> HLT_QuadMuon0_Dimuon0_Jpsi = {fReader, "HLT_QuadMuon0_Dimuon0_Jpsi"};
//    TTreeReaderValue<Bool_t> HLT_QuadMuon0_Dimuon0_Upsilon = {fReader, "HLT_QuadMuon0_Dimuon0_Upsilon"};
//    TTreeReaderValue<Bool_t> HLT_Rsq0p25_Calo = {fReader, "HLT_Rsq0p25_Calo"};
//    TTreeReaderValue<Bool_t> HLT_RsqMR240_Rsq0p09_MR200_4jet_Calo = {fReader, "HLT_RsqMR240_Rsq0p09_MR200_4jet_Calo"};
//    TTreeReaderValue<Bool_t> HLT_RsqMR240_Rsq0p09_MR200_Calo = {fReader, "HLT_RsqMR240_Rsq0p09_MR200_Calo"};
//    TTreeReaderValue<Bool_t> HLT_Rsq0p25 = {fReader, "HLT_Rsq0p25"};
//    TTreeReaderValue<Bool_t> HLT_Rsq0p30 = {fReader, "HLT_Rsq0p30"};
//    TTreeReaderValue<Bool_t> HLT_RsqMR240_Rsq0p09_MR200 = {fReader, "HLT_RsqMR240_Rsq0p09_MR200"};
//    TTreeReaderValue<Bool_t> HLT_RsqMR240_Rsq0p09_MR200_4jet = {fReader, "HLT_RsqMR240_Rsq0p09_MR200_4jet"};
//    TTreeReaderValue<Bool_t> HLT_RsqMR270_Rsq0p09_MR200 = {fReader, "HLT_RsqMR270_Rsq0p09_MR200"};
//    TTreeReaderValue<Bool_t> HLT_RsqMR270_Rsq0p09_MR200_4jet = {fReader, "HLT_RsqMR270_Rsq0p09_MR200_4jet"};
//    TTreeReaderValue<Bool_t> HLT_Rsq0p02_MR300_TriPFJet80_60_40_BTagCSV_p063_p20_Mbb60_200 = {fReader, "HLT_Rsq0p02_MR300_TriPFJet80_60_40_BTagCSV_p063_p20_Mbb60_200"};
//    TTreeReaderValue<Bool_t> HLT_Rsq0p02_MR400_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200 = {fReader, "HLT_Rsq0p02_MR400_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200"};
//    TTreeReaderValue<Bool_t> HLT_Rsq0p02_MR450_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200 = {fReader, "HLT_Rsq0p02_MR450_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200"};
//    TTreeReaderValue<Bool_t> HLT_Rsq0p02_MR500_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200 = {fReader, "HLT_Rsq0p02_MR500_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200"};
//    TTreeReaderValue<Bool_t> HLT_Rsq0p02_MR550_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200 = {fReader, "HLT_Rsq0p02_MR550_TriPFJet80_60_40_DoubleBTagCSV_p063_Mbb60_200"};
//    TTreeReaderValue<Bool_t> HLT_HT200_DisplacedDijet40_DisplacedTrack = {fReader, "HLT_HT200_DisplacedDijet40_DisplacedTrack"};
//    TTreeReaderValue<Bool_t> HLT_HT250_DisplacedDijet40_DisplacedTrack = {fReader, "HLT_HT250_DisplacedDijet40_DisplacedTrack"};
//    TTreeReaderValue<Bool_t> HLT_HT350_DisplacedDijet40_DisplacedTrack = {fReader, "HLT_HT350_DisplacedDijet40_DisplacedTrack"};
//    TTreeReaderValue<Bool_t> HLT_HT350_DisplacedDijet80_DisplacedTrack = {fReader, "HLT_HT350_DisplacedDijet80_DisplacedTrack"};
//    TTreeReaderValue<Bool_t> HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack = {fReader, "HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack"};
//    TTreeReaderValue<Bool_t> HLT_HT350_DisplacedDijet40_Inclusive = {fReader, "HLT_HT350_DisplacedDijet40_Inclusive"};
//    TTreeReaderValue<Bool_t> HLT_HT400_DisplacedDijet40_Inclusive = {fReader, "HLT_HT400_DisplacedDijet40_Inclusive"};
//    TTreeReaderValue<Bool_t> HLT_HT500_DisplacedDijet40_Inclusive = {fReader, "HLT_HT500_DisplacedDijet40_Inclusive"};
//    TTreeReaderValue<Bool_t> HLT_HT550_DisplacedDijet40_Inclusive = {fReader, "HLT_HT550_DisplacedDijet40_Inclusive"};
//    TTreeReaderValue<Bool_t> HLT_HT550_DisplacedDijet80_Inclusive = {fReader, "HLT_HT550_DisplacedDijet80_Inclusive"};
//    TTreeReaderValue<Bool_t> HLT_HT650_DisplacedDijet80_Inclusive = {fReader, "HLT_HT650_DisplacedDijet80_Inclusive"};
//    TTreeReaderValue<Bool_t> HLT_HT750_DisplacedDijet80_Inclusive = {fReader, "HLT_HT750_DisplacedDijet80_Inclusive"};
//    TTreeReaderValue<Bool_t> HLT_VBF_DisplacedJet40_DisplacedTrack = {fReader, "HLT_VBF_DisplacedJet40_DisplacedTrack"};
//    TTreeReaderValue<Bool_t> HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5 = {fReader, "HLT_VBF_DisplacedJet40_DisplacedTrack_2TrackIP2DSig5"};
//    TTreeReaderValue<Bool_t> HLT_VBF_DisplacedJet40_TightID_DisplacedTrack = {fReader, "HLT_VBF_DisplacedJet40_TightID_DisplacedTrack"};
//    TTreeReaderValue<Bool_t> HLT_VBF_DisplacedJet40_Hadronic = {fReader, "HLT_VBF_DisplacedJet40_Hadronic"};
//    TTreeReaderValue<Bool_t> HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack = {fReader, "HLT_VBF_DisplacedJet40_Hadronic_2PromptTrack"};
//    TTreeReaderValue<Bool_t> HLT_VBF_DisplacedJet40_TightID_Hadronic = {fReader, "HLT_VBF_DisplacedJet40_TightID_Hadronic"};
//    TTreeReaderValue<Bool_t> HLT_VBF_DisplacedJet40_VTightID_Hadronic = {fReader, "HLT_VBF_DisplacedJet40_VTightID_Hadronic"};
//    TTreeReaderValue<Bool_t> HLT_VBF_DisplacedJet40_VVTightID_Hadronic = {fReader, "HLT_VBF_DisplacedJet40_VVTightID_Hadronic"};
//    TTreeReaderValue<Bool_t> HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack = {fReader, "HLT_VBF_DisplacedJet40_VTightID_DisplacedTrack"};
//    TTreeReaderValue<Bool_t> HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack = {fReader, "HLT_VBF_DisplacedJet40_VVTightID_DisplacedTrack"};
//    TTreeReaderValue<Bool_t> HLT_PFMETNoMu90_PFMHTNoMu90_IDTight = {fReader, "HLT_PFMETNoMu90_PFMHTNoMu90_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_PFMETNoMu100_PFMHTNoMu100_IDTight = {fReader, "HLT_PFMETNoMu100_PFMHTNoMu100_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_PFMETNoMu110_PFMHTNoMu110_IDTight = {fReader, "HLT_PFMETNoMu110_PFMHTNoMu110_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_PFMETNoMu120_PFMHTNoMu120_IDTight = {fReader, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight = {fReader, "HLT_MonoCentralPFJet80_PFMETNoMu90_PFMHTNoMu90_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_MonoCentralPFJet80_PFMETNoMu100_PFMHTNoMu100_IDTight = {fReader, "HLT_MonoCentralPFJet80_PFMETNoMu100_PFMHTNoMu100_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight = {fReader, "HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight = {fReader, "HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight"};
//    TTreeReaderValue<Bool_t> HLT_Ele27_eta2p1_WPLoose_Gsf_HT200 = {fReader, "HLT_Ele27_eta2p1_WPLoose_Gsf_HT200"};
//    TTreeReaderValue<Bool_t> HLT_Photon90_CaloIdL_PFHT500 = {fReader, "HLT_Photon90_CaloIdL_PFHT500"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu8_Mass8_PFHT250 = {fReader, "HLT_DoubleMu8_Mass8_PFHT250"};
//    TTreeReaderValue<Bool_t> HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT250 = {fReader, "HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT250"};
//    TTreeReaderValue<Bool_t> HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250 = {fReader, "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT250"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu8_Mass8_PFHT300 = {fReader, "HLT_DoubleMu8_Mass8_PFHT300"};
//    TTreeReaderValue<Bool_t> HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300 = {fReader, "HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT300"};
//    TTreeReaderValue<Bool_t> HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300 = {fReader, "HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300"};
//    TTreeReaderValue<Bool_t> HLT_Mu10_CentralPFJet30_BTagCSV_p13 = {fReader, "HLT_Mu10_CentralPFJet30_BTagCSV_p13"};
//    TTreeReaderValue<Bool_t> HLT_DoubleMu3_PFMET50 = {fReader, "HLT_DoubleMu3_PFMET50"};
//    TTreeReaderValue<Bool_t> HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13 = {fReader, "HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13"};
//    TTreeReaderValue<Bool_t> HLT_Ele15_IsoVVVL_BTagCSV_p067_PFHT400 = {fReader, "HLT_Ele15_IsoVVVL_BTagCSV_p067_PFHT400"};
//    TTreeReaderValue<Bool_t> HLT_Ele15_IsoVVVL_PFHT350_PFMET50 = {fReader, "HLT_Ele15_IsoVVVL_PFHT350_PFMET50"};
//    TTreeReaderValue<Bool_t> HLT_Ele15_IsoVVVL_PFHT600 = {fReader, "HLT_Ele15_IsoVVVL_PFHT600"};
//    TTreeReaderValue<Bool_t> HLT_Ele15_IsoVVVL_PFHT350 = {fReader, "HLT_Ele15_IsoVVVL_PFHT350"};
//    TTreeReaderValue<Bool_t> HLT_Ele15_IsoVVVL_PFHT400_PFMET50 = {fReader, "HLT_Ele15_IsoVVVL_PFHT400_PFMET50"};
//    TTreeReaderValue<Bool_t> HLT_Ele15_IsoVVVL_PFHT400 = {fReader, "HLT_Ele15_IsoVVVL_PFHT400"};
//    TTreeReaderValue<Bool_t> HLT_Ele50_IsoVVVL_PFHT400 = {fReader, "HLT_Ele50_IsoVVVL_PFHT400"};
//    TTreeReaderValue<Bool_t> HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60 = {fReader, "HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60"};
//    TTreeReaderValue<Bool_t> HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60 = {fReader, "HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60"};
//    TTreeReaderValue<Bool_t> HLT_Mu15_IsoVVVL_BTagCSV_p067_PFHT400 = {fReader, "HLT_Mu15_IsoVVVL_BTagCSV_p067_PFHT400"};
//    TTreeReaderValue<Bool_t> HLT_Mu15_IsoVVVL_PFHT350_PFMET50 = {fReader, "HLT_Mu15_IsoVVVL_PFHT350_PFMET50"};
//    TTreeReaderValue<Bool_t> HLT_Mu15_IsoVVVL_PFHT600 = {fReader, "HLT_Mu15_IsoVVVL_PFHT600"};
//    TTreeReaderValue<Bool_t> HLT_Mu15_IsoVVVL_PFHT350 = {fReader, "HLT_Mu15_IsoVVVL_PFHT350"};
//    TTreeReaderValue<Bool_t> HLT_Mu15_IsoVVVL_PFHT400_PFMET50 = {fReader, "HLT_Mu15_IsoVVVL_PFHT400_PFMET50"};
//    TTreeReaderValue<Bool_t> HLT_Mu15_IsoVVVL_PFHT400 = {fReader, "HLT_Mu15_IsoVVVL_PFHT400"};
//    TTreeReaderValue<Bool_t> HLT_Mu50_IsoVVVL_PFHT400 = {fReader, "HLT_Mu50_IsoVVVL_PFHT400"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon16_Jpsi = {fReader, "HLT_Dimuon16_Jpsi"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon10_Jpsi_Barrel = {fReader, "HLT_Dimuon10_Jpsi_Barrel"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon8_PsiPrime_Barrel = {fReader, "HLT_Dimuon8_PsiPrime_Barrel"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon8_Upsilon_Barrel = {fReader, "HLT_Dimuon8_Upsilon_Barrel"};
//    TTreeReaderValue<Bool_t> HLT_Dimuon0_Phi_Barrel = {fReader, "HLT_Dimuon0_Phi_Barrel"};
//    TTreeReaderValue<Bool_t> HLT_Mu16_TkMu0_dEta18_Onia = {fReader, "HLT_Mu16_TkMu0_dEta18_Onia"};
//    TTreeReaderValue<Bool_t> HLT_Mu16_TkMu0_dEta18_Phi = {fReader, "HLT_Mu16_TkMu0_dEta18_Phi"};
//    TTreeReaderValue<Bool_t> HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx = {fReader, "HLT_TrkMu15_DoubleTrkMu5NoFiltersNoVtx"};
//    TTreeReaderValue<Bool_t> HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx = {fReader, "HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx"};
//    TTreeReaderValue<Bool_t> HLT_Mu8 = {fReader, "HLT_Mu8"};
//    TTreeReaderValue<Bool_t> HLT_Mu17 = {fReader, "HLT_Mu17"};
//    TTreeReaderValue<Bool_t> HLT_Mu3_PFJet40 = {fReader, "HLT_Mu3_PFJet40"};
//    TTreeReaderValue<Bool_t> HLT_Ele8_CaloIdM_TrackIdM_PFJet30 = {fReader, "HLT_Ele8_CaloIdM_TrackIdM_PFJet30"};
//    TTreeReaderValue<Bool_t> HLT_Ele12_CaloIdM_TrackIdM_PFJet30 = {fReader, "HLT_Ele12_CaloIdM_TrackIdM_PFJet30"};
//    TTreeReaderValue<Bool_t> HLT_Ele17_CaloIdM_TrackIdM_PFJet30 = {fReader, "HLT_Ele17_CaloIdM_TrackIdM_PFJet30"};
//    TTreeReaderValue<Bool_t> HLT_Ele23_CaloIdM_TrackIdM_PFJet30 = {fReader, "HLT_Ele23_CaloIdM_TrackIdM_PFJet30"};
//    TTreeReaderValue<Bool_t> HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet140 = {fReader, "HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet140"};
//    TTreeReaderValue<Bool_t> HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165 = {fReader, "HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165"};
   
   
//    TTreeReaderValue<Bool_t> HLT_PFHT400_SixJet30 = {fReader, "HLT_PFHT400_SixJet30"};
//    TTreeReaderValue<Bool_t> HLT_PFHT450_SixJet40 = {fReader, "HLT_PFHT450_SixJet40"};
//    TTreeReaderValue<Bool_t> HLT_Ele115_CaloIdVT_GsfTrkIdT = {fReader, "HLT_Ele115_CaloIdVT_GsfTrkIdT"};
//    TTreeReaderValue<Bool_t> HLT_Mu55 = {fReader, "HLT_Mu55"};
//    TTreeReaderValue<Bool_t> HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15 = {fReader, "HLT_Photon42_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon25_AND_HE10_R9Id65_Eta2_Mass15"};
//    TTreeReaderValue<Bool_t> HLT_Photon90_CaloIdL_PFHT600 = {fReader, "HLT_Photon90_CaloIdL_PFHT600"};
//    TTreeReaderValue<Bool_t> HLT_PixelTracks_Multiplicity60ForEndOfFill = {fReader, "HLT_PixelTracks_Multiplicity60ForEndOfFill"};
//    TTreeReaderValue<Bool_t> HLT_PixelTracks_Multiplicity85ForEndOfFill = {fReader, "HLT_PixelTracks_Multiplicity85ForEndOfFill"};
//    TTreeReaderValue<Bool_t> HLT_PixelTracks_Multiplicity110ForEndOfFill = {fReader, "HLT_PixelTracks_Multiplicity110ForEndOfFill"};
//    TTreeReaderValue<Bool_t> HLT_PixelTracks_Multiplicity135ForEndOfFill = {fReader, "HLT_PixelTracks_Multiplicity135ForEndOfFill"};
//    TTreeReaderValue<Bool_t> HLT_PixelTracks_Multiplicity160ForEndOfFill = {fReader, "HLT_PixelTracks_Multiplicity160ForEndOfFill"};
//    TTreeReaderValue<Bool_t> HLT_FullTracks_Multiplicity80 = {fReader, "HLT_FullTracks_Multiplicity80"};
//    TTreeReaderValue<Bool_t> HLT_FullTracks_Multiplicity100 = {fReader, "HLT_FullTracks_Multiplicity100"};
//    TTreeReaderValue<Bool_t> HLT_FullTracks_Multiplicity130 = {fReader, "HLT_FullTracks_Multiplicity130"};
//    TTreeReaderValue<Bool_t> HLT_FullTracks_Multiplicity150 = {fReader, "HLT_FullTracks_Multiplicity150"};
//    TTreeReaderValue<Bool_t> HLT_ECALHT800 = {fReader, "HLT_ECALHT800"};
//    TTreeReaderValue<Bool_t> HLT_DiSC30_18_EIso_AND_HE_Mass70 = {fReader, "HLT_DiSC30_18_EIso_AND_HE_Mass70"};
//    TTreeReaderValue<Bool_t> HLT_Photon125 = {fReader, "HLT_Photon125"};
//    TTreeReaderValue<Bool_t> HLT_MET100 = {fReader, "HLT_MET100"};
//    TTreeReaderValue<Bool_t> HLT_MET150 = {fReader, "HLT_MET150"};
//    TTreeReaderValue<Bool_t> HLT_MET200 = {fReader, "HLT_MET200"};
//    TTreeReaderValue<Bool_t> HLT_Ele27_HighEta_Ele20_Mass55 = {fReader, "HLT_Ele27_HighEta_Ele20_Mass55"};
//    TTreeReaderValue<Bool_t> HLT_L1FatEvents = {fReader, "HLT_L1FatEvents"};
//    TTreeReaderValue<Bool_t> HLT_Physics = {fReader, "HLT_Physics"};
//    TTreeReaderValue<Bool_t> HLT_L1FatEvents_part0 = {fReader, "HLT_L1FatEvents_part0"};
//    TTreeReaderValue<Bool_t> HLT_L1FatEvents_part1 = {fReader, "HLT_L1FatEvents_part1"};
//    TTreeReaderValue<Bool_t> HLT_L1FatEvents_part2 = {fReader, "HLT_L1FatEvents_part2"};
//    TTreeReaderValue<Bool_t> HLT_L1FatEvents_part3 = {fReader, "HLT_L1FatEvents_part3"};
//    TTreeReaderValue<Bool_t> HLT_Random = {fReader, "HLT_Random"};
//    TTreeReaderValue<Bool_t> HLT_ZeroBias = {fReader, "HLT_ZeroBias"};
//    TTreeReaderValue<Bool_t> HLT_AK4CaloJet30 = {fReader, "HLT_AK4CaloJet30"};
//    TTreeReaderValue<Bool_t> HLT_AK4CaloJet40 = {fReader, "HLT_AK4CaloJet40"};
//    TTreeReaderValue<Bool_t> HLT_AK4CaloJet50 = {fReader, "HLT_AK4CaloJet50"};
//    TTreeReaderValue<Bool_t> HLT_AK4CaloJet80 = {fReader, "HLT_AK4CaloJet80"};
//    TTreeReaderValue<Bool_t> HLT_AK4CaloJet100 = {fReader, "HLT_AK4CaloJet100"};
//    TTreeReaderValue<Bool_t> HLT_AK4PFJet30 = {fReader, "HLT_AK4PFJet30"};
//    TTreeReaderValue<Bool_t> HLT_AK4PFJet50 = {fReader, "HLT_AK4PFJet50"};
//    TTreeReaderValue<Bool_t> HLT_AK4PFJet80 = {fReader, "HLT_AK4PFJet80"};
//    TTreeReaderValue<Bool_t> HLT_AK4PFJet100 = {fReader, "HLT_AK4PFJet100"};
//    TTreeReaderValue<Bool_t> HLT_HISinglePhoton10 = {fReader, "HLT_HISinglePhoton10"};
//    TTreeReaderValue<Bool_t> HLT_HISinglePhoton15 = {fReader, "HLT_HISinglePhoton15"};
//    TTreeReaderValue<Bool_t> HLT_HISinglePhoton20 = {fReader, "HLT_HISinglePhoton20"};
//    TTreeReaderValue<Bool_t> HLT_HISinglePhoton40 = {fReader, "HLT_HISinglePhoton40"};
//    TTreeReaderValue<Bool_t> HLT_HISinglePhoton60 = {fReader, "HLT_HISinglePhoton60"};
//    TTreeReaderValue<Bool_t> HLT_EcalCalibration = {fReader, "HLT_EcalCalibration"};
//    TTreeReaderValue<Bool_t> HLT_HcalCalibration = {fReader, "HLT_HcalCalibration"};
//    TTreeReaderValue<Bool_t> HLT_GlobalRunHPDNoise = {fReader, "HLT_GlobalRunHPDNoise"};
//    TTreeReaderValue<Bool_t> HLT_L1BptxMinus = {fReader, "HLT_L1BptxMinus"};
//    TTreeReaderValue<Bool_t> HLT_L1BptxPlus = {fReader, "HLT_L1BptxPlus"};
//    TTreeReaderValue<Bool_t> HLT_L1NotBptxOR = {fReader, "HLT_L1NotBptxOR"};
//    TTreeReaderValue<Bool_t> HLT_L1BeamGasMinus = {fReader, "HLT_L1BeamGasMinus"};
//    TTreeReaderValue<Bool_t> HLT_L1BeamGasPlus = {fReader, "HLT_L1BeamGasPlus"};
//    TTreeReaderValue<Bool_t> HLT_L1BptxXOR = {fReader, "HLT_L1BptxXOR"};
//    TTreeReaderValue<Bool_t> HLT_L1MinimumBiasHF_OR = {fReader, "HLT_L1MinimumBiasHF_OR"};
//    TTreeReaderValue<Bool_t> HLT_L1MinimumBiasHF_AND = {fReader, "HLT_L1MinimumBiasHF_AND"};
//    TTreeReaderValue<Bool_t> HLT_HcalNZS = {fReader, "HLT_HcalNZS"};
//    TTreeReaderValue<Bool_t> HLT_HcalPhiSym = {fReader, "HLT_HcalPhiSym"};
//    TTreeReaderValue<Bool_t> HLT_HcalIsolatedbunch = {fReader, "HLT_HcalIsolatedbunch"};
//    TTreeReaderValue<Bool_t> HLT_ZeroBias_FirstCollisionAfterAbortGap = {fReader, "HLT_ZeroBias_FirstCollisionAfterAbortGap"};
//    TTreeReaderValue<Bool_t> HLT_ZeroBias_FirstCollisionAfterAbortGap_copy = {fReader, "HLT_ZeroBias_FirstCollisionAfterAbortGap_copy"};
//    TTreeReaderValue<Bool_t> HLT_ZeroBias_FirstCollisionAfterAbortGap_TCDS = {fReader, "HLT_ZeroBias_FirstCollisionAfterAbortGap_TCDS"};
//    TTreeReaderValue<Bool_t> HLT_ZeroBias_IsolatedBunches = {fReader, "HLT_ZeroBias_IsolatedBunches"};
//    TTreeReaderValue<Bool_t> HLT_ZeroBias_FirstCollisionInTrain = {fReader, "HLT_ZeroBias_FirstCollisionInTrain"};
//    TTreeReaderValue<Bool_t> HLT_ZeroBias_FirstBXAfterTrain = {fReader, "HLT_ZeroBias_FirstBXAfterTrain"};
//    TTreeReaderValue<Bool_t> HLT_Photon500 = {fReader, "HLT_Photon500"};
//    TTreeReaderValue<Bool_t> HLT_Photon600 = {fReader, "HLT_Photon600"};
//    TTreeReaderValue<Bool_t> HLT_Mu300 = {fReader, "HLT_Mu300"};
//    TTreeReaderValue<Bool_t> HLT_Mu350 = {fReader, "HLT_Mu350"};
//    TTreeReaderValue<Bool_t> HLT_MET250 = {fReader, "HLT_MET250"};
//    TTreeReaderValue<Bool_t> HLT_MET300 = {fReader, "HLT_MET300"};
//    TTreeReaderValue<Bool_t> HLT_MET600 = {fReader, "HLT_MET600"};
//    TTreeReaderValue<Bool_t> HLT_MET700 = {fReader, "HLT_MET700"};
//    TTreeReaderValue<Bool_t> HLT_PFMET300 = {fReader, "HLT_PFMET300"};
//    TTreeReaderValue<Bool_t> HLT_PFMET400 = {fReader, "HLT_PFMET400"};
//    TTreeReaderValue<Bool_t> HLT_PFMET500 = {fReader, "HLT_PFMET500"};
//    TTreeReaderValue<Bool_t> HLT_PFMET600 = {fReader, "HLT_PFMET600"};
//    TTreeReaderValue<Bool_t> HLT_Ele250_CaloIdVT_GsfTrkIdT = {fReader, "HLT_Ele250_CaloIdVT_GsfTrkIdT"};
//    TTreeReaderValue<Bool_t> HLT_Ele300_CaloIdVT_GsfTrkIdT = {fReader, "HLT_Ele300_CaloIdVT_GsfTrkIdT"};
//    TTreeReaderValue<Bool_t> HLT_HT2000 = {fReader, "HLT_HT2000"};
//    TTreeReaderValue<Bool_t> HLT_HT2500 = {fReader, "HLT_HT2500"};
//    TTreeReaderValue<Bool_t> HLT_IsoTrackHE = {fReader, "HLT_IsoTrackHE"};
//    TTreeReaderValue<Bool_t> HLT_IsoTrackHB = {fReader, "HLT_IsoTrackHB"};
//    TTreeReaderValue<Bool_t> HLTriggerFinalPath = {fReader, "HLTriggerFinalPath"};
//    TTreeReaderValue<Bool_t> L1simulation_step = {fReader, "L1simulation_step"};


   objectTSelectorForNanoAOD(TTree * /*tree*/ =0) { }
   virtual ~objectTSelectorForNanoAOD() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(objectTSelectorForNanoAOD,0);

};

#endif

#ifdef objectTSelectorForNanoAOD_cxx
void objectTSelectorForNanoAOD::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t objectTSelectorForNanoAOD::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef objectTSelectorForNanoAOD_cxx
