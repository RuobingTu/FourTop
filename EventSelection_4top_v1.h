//#include "CondFormats/BTauObjects/interface/BTagCalibration.h"
//#include "CondFormats/BTauObjects/interface/BTagCalibrationReader.h"
#include "TBranch.h"
#include "TTree.h"
#include "TFile.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TLorentzVector.h"
#include <iostream>


//BTagCalibration not working in 102
void branch(bool data, TTree *NewTree, TTree *NewTreeSB, string fileName);/*{{{*/
void SelectMet(bool &SelectedMet);
void SelectElectrons(vector<TLorentzVector> & SelectedElectrons, vector<int> & SelectedElectronsIndex, bool data);
void SelectMuons(vector<TLorentzVector> & SelectedMuons, vector<int> & SelectedMuonsIndex);
void SelectTaus(vector<TLorentzVector>& SelectedTaus, Int_t TauWP=1);
void SelectZBoson(bool electrons,bool muons ,bool &SelectedZBoson,TLorentzVector &ZBoson,TLorentzVector &Lep1,TLorentzVector &Lep2,vector<TLorentzVector> SelectedLeptons,vector<int> SelectedLeptonsIndex,float dRLep1Lep2,float Zpt,float leadLepPt);
void SelectJets(int jetType,vector<TLorentzVector> & SelectedJets, vector<float> & SelectedJetsCSV, vector<TLorentzVector> SelectedElectrons, vector<TLorentzVector> SelectedMuons, 
		int SysJes, int SysJer, bool data, bool &deltaPhiJetMet);
void SelectCA8Jets(int CA8jetType, vector<TLorentzVector> & SelectedWJets, vector<TLorentzVector> SelectedElectrons, vector<TLorentzVector> SelectedMuons, vector<int> & CA8Indices, 
		int SysJes, int SysJer, bool data, bool &deltaPhiJetMet);
void ResolvedRegionSelection(bool &ResolvedEvent,vector<TLorentzVector> SelectedJets,vector<float> SelectedJetsCSV,TLorentzVector &TopQuark,
			     TLorentzVector &Jet1,TLorentzVector &Jet2,TLorentzVector &Jet3,bool TopMassCut,bool btag);
void PartiallyMergedSelection(bool &PartiallyMerged,vector<TLorentzVector> SelectedWJets,vector<TLorentzVector> SelectedJets,vector<float> SelectedJetsCSV,TLorentzVector &TopQuark,
			      TLorentzVector &Jet1,TLorentzVector &Jet2,bool TopMassCut,bool btag,vector<int> CA8Indices,int & CA8Index,float &WMass_,float &WSubjet_, bool data);
void FullyMergedSelection(bool & FullyMerged, vector<TLorentzVector> SelectedTopJets, TLorentzVector &TopQuark,vector<int> CA8Indices,float &TopSoftMass_,float &TopSubjet_, bool data);
//void BTagSF(float JetPt, float JetEta, int flav, float &SF, float &SFerr);
void get_weight_btag(int selection, float &w_Btag, float &w_BtagUp, float &w_BtagDown, float &w_Btag1Up, float &w_Btag1Down, float &w_Btag2Up, float &w_Btag2Down, float &w_BtagLoose, float &w_BtagLooseUp, float &w_BtagLooseDown, string fileName);
void WSF(TLorentzVector WJet, bool PartiallyMerged, float &w_WJet_, float &w_WJetUp_, float &w_WJetDown_, int CA8Index, int SysJes, int SysJer);
void TopSF(TLorentzVector SelectedTopJets, bool FullyMerged, float &w_topJet_, float &w_topJetUp_, float &w_topJetDown_);
void ForwardJetSF(vector<TLorentzVector> SelectedForwardJets, float &w_for_, float &w_forUp_, float &w_forDown_);
void MuonSF(bool SelectedZBosonMuons, float pt, float eta, float &w_Muon_, float &w_MuonUp_, float &w_MuonDown_);
void ElectronSF(bool SelectedZBosonElectrons, float pt, float eta, float &w_Electron_, float &w_ElectronUp_, float &w_ElectronDown_);
void MuonTriggerSF(float pt, float eta);
void ElectronTriggerSF(float pt, float eta);
float DeltaR(float eta1, float eta2, float phi1, float phi2);
float DeltaPhi(float phi1, float phi2);
float HTcalculator(vector<TLorentzVector> SelectedJets);
float MHTcalculator(vector<TLorentzVector> SelectedJets);
//
//
float InvariantMassCalculator(vector<TLorentzVector> SelectedJets);
float AplanarityCalculator(vector<TLorentzVector> SelectedJets);
float LeadingJetPtCal(vector<TLorentzVector> SelectedJets);
float deltaRJetsCal(vector<TLorentzVector> SelectedJets);
void sort_jetPt(vector<TLorentzVector> SelectedJets,vector<int> &JetsPtSorted);
void give_value_JetPtSorted(vector<int> JetsPtSorted,float &LeadingJetPt,float &SecondJetPt, float &ThirdJetPt, float &FourthJetPt,  float          &FitthJetPt,float &SixthJetPt, float &SeventhJetPt, float &EighthJetPt, float &NighthJetPt, float &TenthJetPt);
void MinMaxdeltaRJetsCal(vector<TLorentzVector> SelectedJets,vector<float>& MinMaxDeltaR);
////
//
void branchGetEntry(bool data, Long64_t tentry, string fileName);
void HistoFill(float pileupReweight,TTree *NewTree);
void writeFile(TTree *NewTree,TTree *NewTreeSB);
void initializeVar();
void fillgenWeights();
void GenClassifier(float &GenZPt_,float &GenWPt_);
void GenWBoson(bool &matched, TLorentzVector Wjet);
void GenWeight(string fileName, float GenZPt_,float GenWPt_);
void newPUWeight(float &puweight,float &puweightUP,float &puweightDOWN);
void FillBranches(bool ResolvedEvent,TLorentzVector TopQuark,bool SelectedMet,TLorentzVector TopQuarkResolved,TLorentzVector Jet1Resolved,TLorentzVector Jet2Resolved,TLorentzVector Jet3Resolved,vector<TLorentzVector> SelectedForwardJets,vector<TLorentzVector> SelectedBJets);
void HTSF(string fileName, float HT, float Met_pt, float &w_SF1, float &w_SF1Up, float &w_SF1Down, float &w_SF2, float &w_SF2Up, float &w_SF2Down, float &w_SF3, float &w_SF3Up, float &w_SF3Down);
void TriggerSF(float HT, float MHT, float &w_Trig, float &w_TrigUp, float &w_TrigDown);
void QCDWeight(int imin,int imax,float &w_QCDUp ,float &w_QCDDown);
void PDFWeight(int imin,int imax,float &w_PDFUp ,float &w_PDFDown);
void MetCorrection(int SysJes, int SysJer, float &MET);/*}}}*/
//BTAG SF
//???what does this do?
/*
BTagCalibration calib("CSVv2", "SF_dineutrino/DeepCSV_94XSF_V2_B_F.csv");
  //BTagCalibration calib("DeepCSV", "SF_dineutrino/DeepCSV_94XSF_V2_B_F.csv");
BTagCalibrationReader readerTIncl(&calib,      BTagEntry::OP_TIGHT, "incl",   "central");
BTagCalibrationReader readerTIncl_up(&calib,   BTagEntry::OP_TIGHT, "incl",   "up");
BTagCalibrationReader readerTIncl_do(&calib,   BTagEntry::OP_TIGHT, "incl",   "down");
BTagCalibrationReader readerTComb(&calib,    BTagEntry::OP_TIGHT, "comb", "central");
BTagCalibrationReader readerTComb_up(&calib, BTagEntry::OP_TIGHT, "comb", "up");
BTagCalibrationReader readerTComb_do(&calib, BTagEntry::OP_TIGHT, "comb", "down");
BTagCalibrationReader readerMIncl(&calib,      BTagEntry::OP_MEDIUM, "incl",   "central");
BTagCalibrationReader readerMIncl_up(&calib,   BTagEntry::OP_MEDIUM, "incl",   "up");
BTagCalibrationReader readerMIncl_do(&calib,   BTagEntry::OP_MEDIUM, "incl",   "down");
BTagCalibrationReader readerMComb(&calib,    BTagEntry::OP_MEDIUM, "comb", "central");
BTagCalibrationReader readerMComb_up(&calib, BTagEntry::OP_MEDIUM, "comb", "up");
BTagCalibrationReader readerMComb_do(&calib, BTagEntry::OP_MEDIUM, "comb", "down");
BTagCalibrationReader readerLIncl(&calib,      BTagEntry::OP_LOOSE,  "incl",   "central");
BTagCalibrationReader readerLIncl_up(&calib,   BTagEntry::OP_LOOSE,  "incl",   "up");
BTagCalibrationReader readerLIncl_do(&calib,   BTagEntry::OP_LOOSE,  "incl",   "down");
BTagCalibrationReader readerLComb(&calib,    BTagEntry::OP_LOOSE,  "comb", "central");
BTagCalibrationReader readerLComb_up(&calib, BTagEntry::OP_LOOSE,  "comb", "up");
BTagCalibrationReader readerLComb_do(&calib, BTagEntry::OP_LOOSE,  "comb", "down");
*/
//Lepton SF
//???
TFile *fileForwardJet    = new TFile("SF_dineutrino/ForwardJetSFFinal.root");/*{{{*/
TFile *fileMuonTrig      = new TFile("SF_dineutrino/EfficienciesAndSF_RunBtoF_Nov17Nov2017.root");
TFile *fileElectron1     = new TFile("SF_dineutrino/egammaEffi.txt_EGM2D_runBCDEF_passingRECO.root");
TFile *fileElectron2     = new TFile("SF_dineutrino/egammaEffi.txt_EGM2D_runBCDEF_passingTight94X.root");
TFile *fileElectronTrig  = new TFile("SF_dineutrino/ElectronTriggerSF.root");
TFile *fileOldPU         = new TFile("SF_dineutrino/PileUpReweighting2017.root");
TFile *fileNewPU         = new TFile("SF_dineutrino/PileUpReweighting2017_v1.root");
TFile *fileNewPUUp       = new TFile("SF_dineutrino/PileUpReweighting2017Up.root");
TFile *fileNewPUDo       = new TFile("SF_dineutrino/PileUpReweighting2017Do.root");
TFile *fileZPt           = new TFile("SF_dineutrino/scalefactors_v4.root");/*}}}*/
//TFile *fileHT_SF         = new TFile("SF_dineutrino/SF_2D_veto.root");
TFile *fileHT_SF         = new TFile("SF_dineutrino/SF_2D.root");/*{{{*/
TFile *fileTrig          = new TFile("SF_dineutrino/2DTrigger_SingleElectron_2017.root");
TH2F  *histoForwardJet   = (TH2F*)fileForwardJet->Get("histo");
TH2F  *histoMuonTrig     = (TH2F*)fileMuonTrig->Get("Mu50_PtEtaBins/abseta_pt_ratio");
TH2F  *histoElectron1    = (TH2F*)fileElectron1->Get("EGamma_SF2D");
TH2F  *histoElectron2    = (TH2F*)fileElectron2->Get("EGamma_SF2D");
TH2F  *histoElectronTrig = (TH2F*)fileElectronTrig->Get("eta_pt");
TH1F  *histoOldPU        = (TH1F*)fileOldPU  ->Get("pileup");
TH1F  *histoNewPU        = (TH1F*)fileNewPU  ->Get("pileup");
TH1F  *histoNewPUUp      = (TH1F*)fileNewPUUp->Get("pileup");
TH1F  *histoNewPUDo      = (TH1F*)fileNewPUDo->Get("pileup");
TF1   *functZPt          = (TF1*) fileZPt->Get("z_ewkcorr/z_ewkcorr_func");
TF1   *functWPt          = (TF1*) fileZPt->Get("w_ewkcorr/w_ewkcorr_func");
TH2F   *histoSF1         = (TH2F*) fileHT_SF->Get("SF1_h");
TH2F   *histoSF2         = (TH2F*) fileHT_SF->Get("SF2_h");
TH2F   *histoSF3         = (TH2F*) fileHT_SF->Get("SF3_h");
TH2F   *histoTrig        = (TH2F*) fileTrig ->Get("h_METvsMHT_EFF");/*}}}*/

TTree *Tree;

//RECO INFO
vector <double> * Jet_pt_;   TBranch *b_Jet_pt;/*{{{*/
vector <double> * Jet_eta_;  TBranch *b_Jet_eta;
vector <double> * Jet_phi_;  TBranch *b_Jet_phi;
vector <double> * Jet_mass_; TBranch *b_Jet_mass;
vector <double> * Jet_JesSF_;TBranch *b_Jet_JesSF;
vector <double> * Jet_JesSFup_;TBranch *b_Jet_JesSFup;
vector <double> * Jet_JesSFdown_;TBranch *b_Jet_JesSFdown;
vector <double> * Jet_JerSF_;TBranch *b_Jet_JerSF;
vector <double> * Jet_JerSFup_;TBranch *b_Jet_JerSFup;
vector <double> * Jet_JerSFdown_;TBranch *b_Jet_JerSFdown;
vector <double> * Jet_Uncorr_pt_; TBranch *b_Jet_Uncorr_pt;
vector <double> * Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags_;              TBranch *b_Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags;
vector <double> * Jet_pfDeepCSVBJetTags_;           TBranch *b_Jet_pfDeepCSVBJetTags;
vector <double> * Jet_neutralHadEnergyFraction_;    TBranch *b_Jet_neutralHadEnergyFraction;
vector <double> * Jet_chargedEmEnergyFraction_;     TBranch *b_Jet_chargedEmEnergyFraction;
vector <double> * Jet_neutralEmEnergyFraction_;   TBranch *b_Jet_neutralEmEnergyFraction;
vector <double> * Jet_numberOfConstituents_;        TBranch *b_Jet_numberOfConstituents;
vector <double> * Jet_chargedHadronEnergyFraction_; TBranch *b_Jet_chargedHadronEnergyFraction;
vector <double> * Jet_chargedMultiplicity_;         TBranch *b_Jet_chargedMultiplicity;
vector <double> * Jet_hadronFlavour_; TBranch *b_Jet_hadronFlavour;
/*vector <double> * BoostedJet_pt_;        TBranch *b_BoostedJet_pt;
vector <double> * BoostedJet_Uncorr_pt_; TBranch *b_BoostedJet_Uncorr_pt;
vector <double> * BoostedJet_softdrop_mass_; TBranch *b_BoostedJet_softdrop_mass;
vector <double> * BoostedJet_puppi_softdrop_mass_; TBranch *b_BoostedJet_puppi_softdrop_mass;
vector <double> * BoostedJet_JesSF_;TBranch *b_BoostedJet_JesSF;
vector <double> * BoostedJet_JesSFup_;TBranch *b_BoostedJet_JesSFup;
vector <double> * BoostedJet_JesSFdown_;TBranch *b_BoostedJet_JesSFdown;
vector <double> * BoostedJet_JerSF_;TBranch *b_BoostedJet_JerSF;
vector <double> * BoostedJet_JerSFup_;TBranch *b_BoostedJet_JerSFup;
vector <double> * BoostedJet_JerSFdown_;TBranch *b_BoostedJet_JerSFdown;
vector <double> * BoostedJet_eta_;  TBranch *b_BoostedJet_eta;
vector <double> * BoostedJet_phi_;  TBranch *b_BoostedJet_phi;
vector <double> * BoostedJet_mass_; TBranch *b_BoostedJet_mass;
vector <double> * BoostedJet_tau1_; TBranch *b_BoostedJet_tau1;
vector <double> * BoostedJet_tau2_; TBranch *b_BoostedJet_tau2;
vector <double> * BoostedJet_tau3_; TBranch *b_BoostedJet_tau3;
vector <double> * BoostedJet_puppi_tau1_; TBranch *b_BoostedJet_puppi_tau1;
vector <double> * BoostedJet_puppi_tau2_; TBranch *b_BoostedJet_puppi_tau2;
vector <double> * BoostedJet_puppi_tau3_; TBranch *b_BoostedJet_puppi_tau3;
vector <double> * BoostedJet_pruned_mass_;  TBranch *b_BoostedJet_pruned_mass;
vector <double> * BoostedJet_neutralHadEnergyFraction_;    TBranch *b_BoostedJet_neutralHadEnergyFraction;
vector <double> * BoostedJet_neutralEmEnergyFraction_;    TBranch *b_BoostedJet_neutralEmEnergyFraction;
vector <double> * BoostedJet_chargedEmEnergyFraction_;     TBranch *b_BoostedJet_chargedEmEnergyFraction;
vector <double> * BoostedJet_neutralEmEmEnergyFraction_;     TBranch *b_BoostedJet_neutralEmEmEnergyFraction;
vector <double> * BoostedJet_numberOfConstituents_;        TBranch *b_BoostedJet_numberOfConstituents;
vector <double> * BoostedJet_chargedHadronEnergyFraction_; TBranch *b_BoostedJet_chargedHadronEnergyFraction;
vector <double> * BoostedJet_chargedMultiplicity_;         TBranch *b_BoostedJet_chargedMultiplicity;*/
vector <double> * TopTagging_topMass_;  TBranch *b_TopTagging_topMass;
vector <double> * TopTagging_minMass_;  TBranch *b_TopTagging_minMass;
vector <double> * TopTagging_wMass_; TBranch *b_TopTagging_wMass;
vector <double> * TopTagging_nSubJets_; TBranch *b_TopTagging_nSubJets;
vector <double> * patElectron_pt_; TBranch *b_patElectron_pt;
vector <double> * patElectron_eta_; TBranch *b_patElectron_eta;
vector <double> * patElectron_phi_; TBranch *b_patElectron_phi;
vector <double> * patElectron_energy_; TBranch *b_patElectron_energy; 
vector <double> * patElectron_energyCorr_; TBranch *b_patElectron_energyCorr;  
vector <double> * patElectron_SCeta_; TBranch *b_patElectron_SCeta;
vector <int> * patElectron_charge_; TBranch *b_patElectron_charge;
vector <double> * patElectron_Et_; TBranch *b_patElectron_Et;
vector <int>* patElectron_pdgId_; TBranch* b_patElectron_pdgId; 
vector <double>* patElectron_relIsoDeltaBeta_; TBranch* b_patElectron_relIsoDeltaBeta; 
vector <double>* patElectron_relIsoRhoEA_Update_; TBranch* b_patElectron_relIsoRhoEA_Update; 
vector <int>* patElectron_gen_pdgId_; TBranch* b_patElectron_gen_pdgId; 
vector <int>* patElectron_gen_isDirectPromptTauDecayProductFinalState_; TBranch* b_patElectron_gen_isDirectPromptTauDecayProductFinalState; 
vector <int>* patElectron_mvaEleID_Fall17_noIso_V2_wp80_; TBranch *b_patElectron_mvaEleID_Fall17_noIso_V2_wp80;
vector <int>* patElectron_mvaEleID_Fall17_iso_V2_wp80_; TBranch* b_patElectron_mvaEleID_Fall17_iso_V2_wp80;
vector <int>* patElectron_mvaEleID_Fall17_iso_V2_wp90_; TBranch* b_patElectron_mvaEleID_Fall17_iso_V2_wp90;
vector <int>* patElectron_mvaEleID_Fall17_noIso_V2_wp90_; TBranch* b_patElectron_mvaEleID_Fall17_noIso_V2_wp90;
vector <int>* patElectron_mvaEleID_Fall17_iso_V2_wpLoose_; TBranch* b_patElectron_mvaEleID_Fall17_iso_V2_wpLoose;
vector <int>* patElectron_mvaEleID_Fall17_noIso_V2_wpLoose_; TBranch* b_patElectron_mvaEleID_Fall17_noIso_V2_wpLoose;
vector <float>* patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Values_; TBranch* b_patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Values;
vector <float>* patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Categories_; TBranch* b_patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Categories; 
vector <float>* patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Values_; TBranch* b_patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Values; 
vector <float>* patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Categories_; TBranch* b_patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Categories; 
vector <float>* patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp80_; TBranch* b_patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp80; 
vector <int>* patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp90_; TBranch* b_patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp90; 
vector <float>* patElectron_MVAValue_ElectronMVAEstimatorRun2Spring16GeneralPurposeV1_; TBranch* b_patElectron_MVAValue_ElectronMVAEstimatorRun2Spring16GeneralPurposeV1; 
vector <int>* patElectron_cutBasedElectronID_Fall17_94X_V2_medium_; TBranch* b_patElectron_cutBasedElectronID_Fall17_94X_V2_medium; 
vector <int>* patElectron_cutBasedElectronID_Fall17_94X_V2_loose_; TBranch* b_patElectron_cutBasedElectronID_Fall17_94X_V2_loose; 
vector <int>* patElectron_cutBasedElectronID_Fall17_94X_V2_tight_; TBranch* b_patElectron_cutBasedElectronID_Fall17_94X_V2_tight; 
vector <int>* patElectron_cutBasedElectronID_Fall17_94X_V2_veto_; TBranch* b_patElectron_cutBasedElectronID_Fall17_94X_V2_veto;
vector <int>* patElectron_heepElectronID_HEEPV70_; TBranch* b_patElectron_heepElectronID_HEEPV70; 
/*vector <int> * patElectron_isPassVeto_; TBranch *b_patElectron_isPassVeto;
vector <int> * patElectron_isPassLoose_; TBranch *b_patElectron_isPassLoose;
vector <int> * patElectron_isPassMedium_; TBranch *b_patElectron_isPassMedium;
vector <int> * patElectron_isPassTight_; TBranch *b_patElectron_isPassTight;
vector <int> * patElectron_isPassHEEPId_; TBranch *b_patElectron_isPassHEEPId;*/
vector <double> * patElectron_d0_; TBranch *b_patElectron_d0;
vector <double> * patElectron_gsfTrack_dz_pv_; TBranch *b_patElectron_gsfTrack_dz_pv;
vector <int> * patElectron_expectedMissingInnerHits_; TBranch *b_patElectron_expectedMissingInnerHits;
vector <int> * patElectron_passConversionVeto_; TBranch *b_patElectron_passConversionVeto;
vector <double> * patElectron_isoChargedHadrons_; TBranch *b_patElectron_isoChargedHadrons;
vector <double> * patElectron_isoNeutralHadrons_; TBranch *b_patElectron_isoNeutralHadrons;
vector <double> * patElectron_isoPhotons_; TBranch *b_patElectron_isoPhotons;
vector <double> * patElectron_isoPU_; TBranch *b_patElectron_isoPU;
vector <double> * patElectron_dEtaIn_; TBranch *b_patElectron_dEtaIn;
vector <double> * patElectron_dPhiIn_; TBranch *b_patElectron_dPhiIn;
vector <double> * patElectron_full5x5_sigmaIetaIeta_; TBranch *b_patElectron_full5x5_sigmaIetaIeta;
vector <double> * patElectron_hOverE_; TBranch *b_patElectron_hOverE;
vector <double> * patElectron_ooEmooP_; TBranch *b_patElectron_ooEmooP;
vector <double> * patElectron_relIsoRhoEA_; TBranch *b_patElectron_relIsoRhoEA;
vector <double> * patElectron_inCrack_; TBranch *b_patElectron_inCrack;
vector <int> * patElectron_isMatchedToTrigger_; TBranch *b_patElectron_isMatchedToTrigger;
vector <double> * Muon_pt_; TBranch *b_Muon_pt;
vector <double> * Muon_eta_; TBranch *b_Muon_eta;
vector <double> * Muon_phi_; TBranch *b_Muon_phi;
vector <double> * Muon_energy_; TBranch *b_Muon_energy;  
vector <int> * Muon_charge_; TBranch *b_Muon_charge;
vector <int> * Muon_tight_; TBranch *b_Muon_tight;
vector <int> * Muon_medium_; TBranch *b_Muon_medium;
vector <int> * Muon_loose_; TBranch *b_Muon_loose;
vector <int> * Muon_soft_; TBranch *b_Muon_soft;
vector <int> * Muon_isHighPt_; TBranch *b_Muon_isHighPt;
vector <int> * Muon_pf_; TBranch *b_Muon_pf;
vector <double> * Muon_dxy_pv_; TBranch *b_Muon_dxy_pv;
vector <double> * Muon_dz_pv_; TBranch *b_Muon_dz_pv;
vector <int> * Muon_isGlobal_; TBranch *b_Muon_isGlobal;
vector <double> * Muon_isoCharged_; TBranch *b_Muon_isoCharged;
vector <double> * Muon_isoSum_; TBranch *b_Muon_isoSum;
vector <double> * Muon_isoCharParPt_; TBranch *b_Muon_isoCharParPt;
vector <double> * Muon_relIsoDeltaBetaR04_; TBranch *b_Muon_relIsoDeltaBetaR04;
vector <int> * Muon_isMatchedToTrigger_; TBranch *b_Muon_isMatchedToTrigger;
vector <int> * Muon_pdgId_; TBranch *b_Muon_pdgId;
vector <double>* Tau_pt_; TBranch* b_Tau_pt;
vector <double>* Tau_eta_; TBranch* b_Tau_eta;
vector <double>* Tau_phi_; TBranch* b_Tau_phi;
vector <double>* Tau_energy_; TBranch* b_Tau_energy;
vector <double>* Tau_px_; TBranch* b_Tau_px;
vector <double>* Tau_py_; TBranch* b_Tau_py;
vector <double>* Tau_pz_; TBranch* b_Tau_pz;
vector <double>* Tau_p_; TBranch* b_Tau_p;
vector <double>* Tau_charge_; TBranch* b_Tau_charge;
vector <int>* Tau_decayModeFinding_; TBranch* b_Tau_decayModeFinding;
vector <int>* Tau_decayModeFindingNewDMs_; TBranch* b_Tau_decayModeFindingNewDMs;
vector <int>* Tau_againstMuonLoose3_; TBranch* b_Tau_againstMuonLoose3;
vector <int>* Tau_againstMuonTight3_; TBranch* b_Tau_againstMuonTight3;
vector <int>* Tau_byDeepTau2017v2p1VSjetraw_; TBranch* b_Tau_byDeepTau2017v2p1VSjetraw;
vector <int>* Tau_byVVVLooseDeepTau2017v2p1VSjet_; TBranch* b_Tau_byVVVLooseDeepTau2017v2p1VSjet;
vector <int>* Tau_byVVLooseDeepTau2017v2p1VSjet_; TBranch* b_Tau_byVVLooseDeepTau2017v2p1VSjet;
vector <int>* Tau_byVLooseDeepTau2017v2p1VSjet_; TBranch* b_Tau_byVLooseDeepTau2017v2p1VSjet;
vector <int>* Tau_byLooseDeepTau2017v2p1VSjet_; TBranch* b_Tau_byLooseDeepTau2017v2p1VSjet;
vector <int>* Tau_byMediumDeepTau2017v2p1VSjet_; TBranch* b_Tau_byMediumDeepTau2017v2p1VSjet;
vector <int>* Tau_byTightDeepTau2017v2p1VSjet_; TBranch* b_Tau_byTightDeepTau2017v2p1VSjet;
vector <int>* Tau_byVTightDeepTau2017v2p1VSjet_; TBranch* b_Tau_byVTightDeepTau2017v2p1VSjet;
vector <int>* Tau_byVVTightDeepTau2017v2p1VSjet_; TBranch* b_Tau_byVVTightDeepTau2017v2p1VSjet;
vector <int>* Tau_byDeepTau2017v2p1VSmuraw_; TBranch* b_Tau_byDeepTau2017v2p1VSmuraw;
vector <int>* Tau_byVLooseDeepTau2017v2p1VSmu_; TBranch* b_Tau_byVLooseDeepTau2017v2p1VSmu;
vector <int>* Tau_byLooseDeepTau2017v2p1VSmu_; TBranch* b_Tau_byLooseDeepTau2017v2p1VSmu;
vector <int>* Tau_byMediumDeepTau2017v2p1VSmu_; TBranch* b_Tau_byMediumDeepTau2017v2p1VSmu;
vector <int>* Tau_byTightDeepTau2017v2p1VSmu_; TBranch* b_Tau_byTightDeepTau2017v2p1VSmu;
vector <int>* Tau_byDeepTau2017v2p1VSeraw_; TBranch* b_Tau_byDeepTau2017v2p1VSeraw;
vector <int>* Tau_byVVVLooseDeepTau2017v2p1VSe_; TBranch* b_Tau_byVVVLooseDeepTau2017v2p1VSe;
vector <int>* Tau_byVVLooseDeepTau2017v2p1VSe_; TBranch* b_Tau_byVVLooseDeepTau2017v2p1VSe;
vector <int>* Tau_byVLooseDeepTau2017v2p1VSe_; TBranch* b_Tau_byVLooseDeepTau2017v2p1VSe;
vector <int>* Tau_byLooseDeepTau2017v2p1VSe_; TBranch* b_Tau_byLooseDeepTau2017v2p1VSe;
vector <int>* Tau_byMediumDeepTau2017v2p1VSe_; TBranch* b_Tau_byMediumDeepTau2017v2p1VSe;
vector <int>* Tau_byTightDeepTau2017v2p1VSe_; TBranch* b_Tau_byTightDeepTau2017v2p1VSe;
vector <int>* Tau_byVTightDeepTau2017v2p1VSe_; TBranch* b_Tau_byVTightDeepTau2017v2p1VSe;
vector <int>* Tau_byVVTightDeepTau2017v2p1VSe_; TBranch* b_Tau_byVVTightDeepTau2017v2p1VSe;
//vector <>* _; TBranch* ;
//vector <>* _; TBranch* ;

  int HLT_DoubleEle33_CaloIdL_MW_; TBranch *b_HLT_DoubleEle33_CaloIdL_MW;
  int HLT_Ele27_eta2p1_WP75_Gsf_; TBranch *b_HLT_Ele27_eta2p1_WP75_Gsf;
  int HLT_Ele27_eta2p1_WPLoose_Gsf_; TBranch *b_HLT_Ele27_eta2p1_WPLoose_Gsf;
  int HLT_TkMu50_; TBranch *b_HLT_TkMu50;
  int HLT_Mu50_; TBranch *b_HLT_Mu50;
  int HLT_IsoMu24_; TBranch *b_HLT_IsoMu24;
  int HLT_IsoTkMu24_; TBranch *b_HLT_IsoTkMu24;
//
//add
int HLT_PFHT900_; TBranch *b_HLT_PFHT900;
int HLT_PFHT450_SixJet40_BTagCSV_p056_; TBranch *b_HLT_PFHT450_SixJet40_BTagCSV_p056;
int HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_; TBranch *b_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056;
//
//
int Flag_goodVertices_; TBranch *b_Flag_goodVertices;
int Flag_globalSuperTightHalo2016Filter_; TBranch *b_Flag_globalSuperTightHalo2016Filter;
int Flag_CSCTightHalo2015Filter_; TBranch *b_Flag_CSCTightHalo2015Filter;
int Flag_HBHENoiseFilter_; TBranch *b_Flag_HBHENoiseFilter;
int Flag_HBHENoiseIsoFilter_; TBranch *b_Flag_HBHENoiseIsoFilter;
int Flag_EcalDeadCellTriggerPrimitiveFilter_; TBranch *b_Flag_EcalDeadCellTriggerPrimitiveFilter;
int Flag_BadPFMuonFilter_; TBranch *b_Flag_BadPFMuonFilter;
int Flag_BadChargedCandidateFilter_; TBranch *b_Flag_BadChargedCandidateFilter;
//int Flag_ecalBadCalibReducedMINIAODFilter_; TBranch *b_Flag_ecalBadCalibReducedMINIAODFilter;
int Flag_eeBadScFilter_; TBranch *b_Flag_eeBadScFilter;
int Flag_METFilters_; TBranch *b_Flag_METFilters;
int nBestVtx_; TBranch *b_nBestVtx;
double PUWeight_; TBranch *b_PUWeight;
double PUWeightUP_; TBranch *b_PUWeightUP;
double PUWeightDOWN_; TBranch *b_PUWeightDOWN;
int HLT_PFHT500_PFMET100_PFMHT100_IDTight_;        TBranch * b_HLT_PFHT500_PFMET100_PFMHT100_IDTight;  
int HLT_PFHT700_PFMET85_PFMHT85_IDTight_;          TBranch * b_HLT_PFHT700_PFMET85_PFMHT85_IDTight;
int HLT_PFHT800_PFMET75_PFMHT75_IDTight_;          TBranch * b_HLT_PFHT800_PFMET75_PFMHT75_IDTight;
//int HLT_PFMET120_PFMHT120_IDTight_;                TBranch * b_HLT_PFMET120_PFMHT120_IDTight;
//int HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_;        TBranch * b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;
int HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_;     TBranch * b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight;
int HLT_CaloJet500_NoJetID_;                       TBranch * b_HLT_CaloJet500_NoJetID;
int HLT_AK8PFJet500_;                              TBranch * b_HLT_AK8PFJet500;
int HLT_PFJet500_;                                 TBranch * b_HLT_PFJet500;
int HLT_PFHT1050_;                                 TBranch * b_HLT_PFHT1050;
double Met_type1PF_pt_;  TBranch * b_Met_type1PF_pt;
double Met_type1PF_phi_; TBranch * b_Met_type1PF_phi;
double Met_type1PF_sumEt_; TBranch * b_Met_type1PF_sumEt;
vector<double> * genWeights_ = new std::vector<double>; TBranch *b_genWeights;
double genWeight_; TBranch *b_genWeight;
double bWeight_; TBranch *b_bWeight;
vector <double> * Gen_pt_; TBranch *b_Gen_pt;
vector <double> * Gen_eta_; TBranch *b_Gen_eta;
vector <double> * Gen_phi_; TBranch *b_Gen_phi;
vector <double> * Gen_pdg_id_; TBranch *b_Gen_pdg_id;
vector <double> * Gen_motherpdg_id_; TBranch *b_Gen_motherpdg_id;
//int EVENT_event_; TBranch *b_EVENT_event;
ULong64_t EVENT_event_; TBranch *b_EVENT_event;
int EVENT_run_; TBranch *b_EVENT_run;
int EVENT_lumiBlock_; TBranch *b_EVENT_lumiBlock;
double EVENT_genHT_; TBranch *b_EVENT_genHT;
double EVENT_prefireWeight_; TBranch *b_EVENT_prefireWeight;
double EVENT_prefireWeightUp_; TBranch *b_EVENT_prefireWeightUp;
double EVENT_prefireWeightDown_; TBranch *b_EVENT_prefireWeightDown;/*}}}*/

//for new tree
int category0=0;/*{{{*/
int category1=0;
int category2=0;
int category3=0;
int category4=0;
int category5=0;
int category6=0;
int category7=0;
float TopMass=-99;
float TopMassMerged=-99;
float TopMassPartial=-99;
float TopMassResolved=-99;
float TopPt=-99;
float TopPtMerged=-99;
float TopPtPartial=-99;
float TopPtResolved=-99;
float TopEta=-99;
float TopEtaMerged=-99;
float TopEtaPartial=-99;
float TopEtaResolved=-99;
float TopPhi=-99;
float TopPhiMerged=-99;
float TopPhiPartial=-99;
float TopPhiResolved=-99;
float WMassResolved1=-99;
float WMassResolved2=-99;
float WMassResolved3=-99;
float BMass=-99;
float BCSV=-99;
float BPt=-99;
float BEta=-99;
float BPhi=-99;
float ZMass=-99;
float ZPt=-99;
float ZEta=-99;
float ZPhi=-99;
float TprimeMass=-99;
float TprimePt=-99;
float TprimeEta=-99;
float TprimePhi=-99;
float TprimeResolvedMass=-99;
float TprimeResolvedPt=-99;
float TprimeResolvedEta=-99;
float TprimeResolvedPhi=-99;
float TprimePartialMass=-99;
float TprimePartialPt=-99;
float TprimePartialEta=-99;
float TprimePartialPhi=-99;
float TprimeMergedMass=-99;
float TprimeMergedPt=-99;
float TprimeMergedEta=-99;
float TprimeMergedPhi=-99;
float Electron1Pt=-99;
float Electron2Pt=-99;
float Electron1E=-99;
float Electron2E=-99;
float Muon1Iso=-99;
float Muon2Iso=-99;
float Muon1Pt=-99;
float Muon2Pt=-99;
float Jet1ForwardPt=-99;
float Jet2ForwardPt=-99;
float Jet3ForwardPt=-99;
float Jet1ResolvedPt=-99;
float Jet2ResolvedPt=-99;
float Jet3ResolvedPt=-99;
float Jet1PartialPt=-99;
float Jet2PartialPt=-99;
float Jet1MergedPt=-99;
float Electron1Eta=-99;
float Electron2Eta=-99;
float Muon1Eta=-99;
float Muon2Eta=-99;
float Jet1ForwardEta=-99;
float Jet2ForwardEta=-99;
float Jet3ForwardEta=-99;
float Jet1ResolvedEta=-99;
float Jet2ResolvedEta=-99;
float Jet3ResolvedEta=-99;
float Jet1PartialEta=-99;
float Jet2PartialEta=-99;
float Jet1MergedEta=-99;
float MostForwardJetEta=-99;
float MostForwardJetPt=-99;
float Electron1Phi=-99;
float Electron2Phi=-99;
float Muon1Phi=-99;
float Muon2Phi=-99;
float deltaPhiZB=-99;
float deltaRZB=-99;
float deltaPhiZTop=-99;
float deltaRZTop=-99;
float deltaPhiZTopResolved=-99;
float deltaRZTopResolved=-99;
float deltaPhiZTopPartial=-99;
float deltaRZTopPartial=-99;
float deltaPhiZTopMerged=-99;
float deltaRZTopMerged=-99;
float deltaRbTop=-99;
float deltaREle1Ele2=-99;
float deltaRMuo1Muo2=-99;
float deltaREle1Ele2M=-99;
float deltaRMuo1Muo2M=-99;
float Massb1b2=-99;
float deltaRb1b2=-99;
float deltaRb1Lep1=-99;
float deltaRb1Lep2=-99;
float deltaRb2Lep1=-99;
float deltaRb2Lep2=-99;
float deltaPhiMetTop=-99.;
float MinDeltaPhiJetMet=99.;
float MinDeltaPhiBoostedJetMet=99.;
int   NumSelLeps=-99;
//
//
int   NumSeEle=-99;
int   NumSeMu=-99;
float   InvariantMassJets=-99;
float   Centrality=-99;
float   Aplanarity=-99;
float   LeadingJetPt=-99;
//float   MaxdeltaRJets=-99;
float   Sphericity=-99;
//float MindeltaRJets=-99;
float SecondJetPt=-99;
float ThirdJetPt=-99;
float FourthJetPt=-99;
float FifthJetPt=-99;
float SixthJetPt=-99;
float SeventhJetPt=-99;
float EighthJetPt=-99;
float LeadingBJetPt=-99;
float SecondBJetPt=-99;
float HTDividedByMET=-99;
float MHTDividedByMET=-99;
float NighthJetPt=-99;
float TenthJetPt=-99;
float ThirdBJetPt=-99;
float FourthBJetPt=-99;
float FifthBJetPt=-99;
float SixthBJetPt=-99;
float SeventhBJetPt=-99;
float EighthBJetPt=-99;
float NighthBJetPt=-99;
float TenthBJetPt=-99;

float MinDeltaRJets=-99;
float MaxDeltaRJets=-99;
float MinDeltaRBJets=-99;
float MaxDeltaRBJets=-99;
int NumOfTausL=-99;
//
//
int   NumSelJets=-99;
int   NumSelForwardJets=-99;
int   NumSelBJetsL=-99;
int   NumSelBJetsM=-99;
int   NumSelBJetsT=-99;
int   NumSelWJets=-99;
int   NumSelTopJets=-99;
int   NVertices=-99;
float HT=-99;
float MHT=-99;
float PUWeight=1; 
float PUWeightUP=1; 
float PUWeightDOWN=1; 
int EVENT_event=-99;
int EVENT_run=-99;
int EVENT_lumiBlock=-99;
float EVENT_genHT=-99;
float Met_pt = -99.;
float Met_phi = -99.;
int getTrueNumInteractions=-99;
float w_for = 1;
float w_forUp = 1;
float w_forDown = 1;
float w_topJet = 1;
float w_topJetUp = 1;
float w_topJetDown = 1;
float w_WJet   = 1;
float w_WJetUp = 1;
float w_WJetDown = 1;
float w_Muon1  = 1;
float w_Muon2  = 1;
float w_Muon1Up  = 1;
float w_Muon2Up  = 1;
float w_Muon1Down  = 1;
float w_Muon2Down  = 1;
float w_Electron1  = 1;
float w_Electron2  = 1;
float w_Electron1Up  = 1;
float w_Electron2Up  = 1;
float w_Electron1Down  = 1;
float w_Electron2Down  = 1;
float w_TrigMuon=1;
float w_TrigMuonUp=1;
float w_TrigMuonDown=1;
float w_TrigElec=1;
float w_TrigElecUp=1;
float w_TrigElecDown=1;
float w_ZToNuNu=1;
float w_ZToNuNuUp=1;
float w_ZToNuNuDown=1;
float w_WToLNu=1;
float w_WToLNuUp=1;
float w_WToLNuDown=1;
float w_ttbar=1;
float w_ttbarUp=1;
float w_ttbarDown=1;
float w_Trig=1;
float w_TrigUp=1;
float w_TrigDown=1;
float WMass = -99;
float WSubjet = -99;
float TopSoftMass = -99;
float TopSubjet = -99;
float w_Btag=1;
float w_BtagUp=1;
float w_BtagDown=1;
float w_Btag1Up=1;
float w_Btag1Down=1;
float w_Btag2Up=1;
float w_Btag2Down=1;
float w_BtagLoose=1;
float w_BtagLooseUp=1;
float w_BtagLooseDown=1;
float prefiringweight = 1;
float prefiringweightup = 1;
float prefiringweightdown = 1;
float GenZPt=-99.;
float GenWPt=-99.;
float genWeight=1;
float w_QCDUp = 1;
float w_QCDDown = 1;
float w_PDFUp = 1;
float w_PDFDown = 1;
int dQuark=0;
int uQuark=0;
int sQuark=0;
int cQuark=0;
int bQuark=0;
int tQuark=0;
float TriggeringElePt  = -1.;
float TriggeringMuoPt  = -1.;
float TriggeringEleEta = -1.;
float TriggeringMuoEta = -1.;
float TransverseMassMetTop = -99;/*}}}*/
