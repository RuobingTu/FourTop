#include <iostream>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TTree.h>
#include <TBenchmark.h>
#include <TEfficiency.h>
#include "trigEff.h"
#include <TChain.h>
#include <TLorentzVector.h>
#include <TROOT.h> //for gROOT
#include <TSystem.h> // for gSystem
//tools for b tagging SFs implementation
#include "../tools/BTagCalibrationStandalone.cpp"
#include "../tools/evalEventSF_fixedWP.C"
#include "../tools/debug.cpp"
//tools for DeepTau SFs implementation
#include "../../../TauPOG/TauIDSFs/src/TauIDSFTool.cc"
#define NBINSX 9
#define NBINSY 8
//using namespace std;

void trigEff(string year, string analyzer, string dir) {

 gBenchmark->Start("running time");
 gROOT->ProcessLine(".L Loader.C+");

 cout << "////////////////////////////////////////////////////////" << endl;
 cout << "////////////////////////////////////////////////////////" << endl;
 cout << "////////////////////////////////////////////////////////" << endl;
 cout << "////////////////////////////////////////////////////////" << endl;
 cout << "///////// REMEMBER TO UPDATE TRIGGER NAMES!!! //////////" << endl;
 cout << "////////////////////////////////////////////////////////" << endl;
 cout << "////////////////////////////////////////////////////////" << endl;
 cout << "////////////////////////////////////////////////////////" << endl;
 cout << "////////////////////////////////////////////////////////" << endl;


 //////////////////////////////////////////////////
 /////////// SET UP MUON SCALE FACTORS ////////////
 //////////////////////////////////////////////////
 TFile* input_MuonIDSF = new TFile( TString(MUOSF_files[year]), "READ" );
 TH2F * MuonIDSF = (TH2F*)input_MuonIDSF->Get("NUM_MediumID_DEN_TrackerMuons_abseta_pt");
 MuonIDSF->SetDirectory(nullptr);
 input_MuonIDSF->Close();
 delete input_MuonIDSF;

 //////////////////////////////////////////////////
 /////////// SET UP TAU SCALE FACTORS /////////////
 //////////////////////////////////////////////////
 TauIDSFTool VSjetIDTool = TauIDSFTool(year,"DeepTau2017v2p1VSjet","Medium", false, false, true);
 TauIDSFTool VSeIDTool = TauIDSFTool(year,"DeepTau2017v2p1VSe","VVLoose", false, false, true); //no VVVLoose histogram in file, use VVLoose and add +3% uncertainty (recommended by TAU POG conveners)
 TauIDSFTool VSmuIDTool = TauIDSFTool(fromULtoReReco(year),"DeepTau2017v2p1VSmu","VLoose", false, false, false); //No UL measurement for these SFs? UL file is not present! Also, set otherVSlepWP to false, VLoose histogram is available

 //////////////////////////////////////////////////
 ////////// LOAD B TAGGING EFFICIENCIES ///////////
 //////////////////////////////////////////////////
 TFile* input_btagEff = new TFile( TString(btagEff_files[year]), "READ" );
 TEfficiency * btagEff_b_tttt = (TEfficiency*)input_btagEff->Get("btagEff_b_tttt");
 TEfficiency * btagEff_c_tttt = (TEfficiency*)input_btagEff->Get("btagEff_c_tttt");
 TEfficiency * btagEff_udsg_tttt = (TEfficiency*)input_btagEff->Get("btagEff_udsg_tttt");
 TEfficiency * btagEff_b_ttbar = (TEfficiency*)input_btagEff->Get("btagEff_b_ttbar");
 TEfficiency * btagEff_c_ttbar = (TEfficiency*)input_btagEff->Get("btagEff_c_ttbar");
 TEfficiency * btagEff_udsg_ttbar = (TEfficiency*)input_btagEff->Get("btagEff_udsg_ttbar");
 TEfficiency * btagEff_b_QCD = (TEfficiency*)input_btagEff->Get("btagEff_b_QCD");
 TEfficiency * btagEff_c_QCD = (TEfficiency*)input_btagEff->Get("btagEff_c_QCD");
 TEfficiency * btagEff_udsg_QCD = (TEfficiency*)input_btagEff->Get("btagEff_udsg_QCD");
 TEfficiency * btagEff_b_ttX = (TEfficiency*)input_btagEff->Get("btagEff_b_ttX");
 TEfficiency * btagEff_c_ttX = (TEfficiency*)input_btagEff->Get("btagEff_c_ttX");
 TEfficiency * btagEff_udsg_ttX = (TEfficiency*)input_btagEff->Get("btagEff_udsg_ttX");
 TEfficiency * btagEff_b_ST = (TEfficiency*)input_btagEff->Get("btagEff_b_ST");
 TEfficiency * btagEff_c_ST = (TEfficiency*)input_btagEff->Get("btagEff_c_ST");
 TEfficiency * btagEff_udsg_ST = (TEfficiency*)input_btagEff->Get("btagEff_udsg_ST");
 btagEff_b_tttt->SetDirectory(nullptr);
 btagEff_c_tttt->SetDirectory(nullptr);
 btagEff_udsg_tttt->SetDirectory(nullptr);
 btagEff_b_ttbar->SetDirectory(nullptr);
 btagEff_c_ttbar->SetDirectory(nullptr);
 btagEff_udsg_ttbar->SetDirectory(nullptr);
 btagEff_b_QCD->SetDirectory(nullptr);
 btagEff_c_QCD->SetDirectory(nullptr);
 btagEff_udsg_QCD->SetDirectory(nullptr);
 btagEff_b_ttX->SetDirectory(nullptr);
 btagEff_c_ttX->SetDirectory(nullptr);
 btagEff_udsg_ttX->SetDirectory(nullptr);
 btagEff_b_ST->SetDirectory(nullptr);
 btagEff_c_ST->SetDirectory(nullptr);
 btagEff_udsg_ST->SetDirectory(nullptr);
 input_btagEff->Close();
 delete input_btagEff;
 //////////////////////////////////////////////////
 ///////// SET UP B-TAGGING SCALE FACTORS /////////
 //////////////////////////////////////////////////
  
 // set up calibration + reader
 cout << "Loading the .csv file..." << endl;

 std::string inputCSVfile = BTVSF_files_fixedWP[year];
 const std::string tagger = "DeepJet";
 std::string measType = "iterativefit";
 std::string measTypeIncl = "incl";
 std::string measTypeComb = "comb";
 std::string sysType = "central";
 std::string sysTypecorrelatedUp = "up_correlated";
 std::string sysTypecorrelatedDown = "down_correlated";
 std::string sysTypeuncorrelatedUp = "up_uncorrelated";
 std::string sysTypeuncorrelatedDown = "down_uncorrelated";
 
 BTagCalibration calib(tagger, inputCSVfile);
 BTagCalibrationReader CSVreader(BTagEntry::OP_MEDIUM, sysType, {sysTypecorrelatedUp, sysTypecorrelatedDown, sysTypeuncorrelatedUp, sysTypeuncorrelatedDown});
 CSVreader.load(calib, BTagEntry::FLAV_B, measTypeComb);
 CSVreader.load(calib, BTagEntry::FLAV_C, measTypeComb);
 CSVreader.load(calib, BTagEntry::FLAV_UDSG, measTypeIncl);
 
 cout << "Input CSV weight file = " << inputCSVfile << "; measurementType = " << measTypeComb << "/" << measTypeIncl << ";" << endl;
	
 //Float_t binsX[NB  INSX+1] = {0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1200, 1400, 1800, 2100, 3000};
 Float_t binsX[NBINSX+1] = {0, 100, 200, 300, 400, 500, 600, 800, 1100, 1500};
 Float_t binsY[NBINSY+1] = {2, 4, 5, 6, 7, 8, 9, 11, 13};

 TFile *outputfile = new TFile( "trigEff_output_" + TString(year) + ".root", "RECREATE" ); 

 map<string, string>::iterator file_it = file[year].begin();

while (file_it != file[year].end()) { //////////////////////// LOOP OVER FILES ///////////////////////

	//LOOP ONLY ON SIGNAL 
    //std::string tttt = "tttt";
    //if (!(file_it->first.find(tttt) !=std::string::npos)) continue;
    string data = "data";
    TString input_dir;
    TString base_dir;
    if (analyzer == "fabio") base_dir = TString("/publicfs/cms/user/fabioiemmi/TauOfTTTT_NanoAOD/");
    else if (analyzer == "huiling") base_dir = TString("/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/");
    else {

        std::cout << "*** ERROR: The analyzer name is invalid. Exiting. ***" << endl;
        return;

    }
    if (!(file_it->first.find(data) !=std::string::npos)) input_dir = base_dir + TString(year) + "/" + TString(dir) + "/mc/" + TString(file_it->second) + "/";
    else input_dir = base_dir + TString(year) + "/" + TString(dir) + "/data/" + TString(file_it->second) + "/";
    cout << "Reading process " << input_dir << "..." << endl;
    if (gSystem->AccessPathName(input_dir + "outTree_0.root")) {

        std::cout << "*** ERROR: file you are trying to read does not exist. Exiting. ***" << endl;
        return;
    }
    
    TH1::AddDirectory(kFALSE); 
    // HT distribution for signal
    TH1F * h_HT_signal = new TH1F("h_HT_signal", "h_HT_signal; H_{T} [GeV]", 60, 0, 3000);
    //Njets distribution for signal
    TH1F * h_njets_signal = new TH1F("h_njets_signal", "h_njets_signal; Jet multiplicity", 15, 0, 15);
    //histograms: for "gen" categories
    TH1F * h_gen1tau3L_bef = new TH1F("h_gen1tau3L_bef", "h_gen1tau3L_bef; Jet multiplicity;", 15, 0, 15);
    TH1F * h_gen1tau3L_aft = new TH1F("h_gen1tau3L_aft", "h_gen1tau3L_aft; Jet multiplicity;", 15, 0, 15);
    TH1F * h_gen2tau2L_bef = new TH1F("h_gen2tau2L_bef", "h_gen2tau2L_bef; Jet multiplicity;", 15, 0, 15);
    TH1F * h_gen2tau2L_aft = new TH1F("h_gen2tau2L_aft", "h_gen2tau2L_aft; Jet multiplicity;", 15, 0, 15);
    //histograms: wrt reference
    //before signal trigger
    //vs HT
    TH1F * h_HT_nocat = new TH1F("h_HT_nocat", "h_HT_nocat; H_{T} [GeV];", NBINSX, binsX);
    //same as line before, but asking for njets requirement
    TH1F * h_HT_nocat_njets = new TH1F("h_HT_nocat_njets", "h_HT_nocat_njets; H_{T} [GeV];", NBINSX, binsX);
    //same line as before, but asking for mu pt requirement
    TH1F * h_HT_nocat_njets_mupt25 = new TH1F("h_HT_nocat_njets_mupt25", "h_HT_nocat_njets_mupt25; H_{T} [GeV];", NBINSX, binsX);
    //same line as before, but asking for jet pt requirement
    TH1F * h_HT_nocat_njets_mupt25_jetpt35 = new TH1F("h_HT_nocat_njets_mupt25_jetpt35", "h_HT_nocat_njets_mupt25_jetpt35; H_{T} [GeV];", NBINSX, binsX);
    //vs Njets  
    TH1F * h_njets_nocat = new TH1F("h_njets_nocat", "h_njets_nocat; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for HT requirement
    TH1F * h_njets_nocat_HT = new TH1F("h_njets_nocat_HT", "h_njets_nocat_HT; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for mu pt requirement
    TH1F * h_njets_nocat_HT_mupt25 = new TH1F("h_njets_nocat_HT_mupt25", "h_njets_nocat_HT_mupt25; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for jet pt requirement
    TH1F * h_njets_nocat_HT_mupt25_jetpt35 = new TH1F("h_njets_nocat_HT_mupt25_jetpt35", "h_njets_nocat_HT_mupt25_jetpt35; Jet multiplicity;", 15, 0, 15);
    //2D distribution njets vs HT
    TH2F * h_njetsvsHT_nocat = new TH2F ("h_njetsvsHT_nocat", "h_njetsvsHT_nocat; H_{T} [GeV]; Jet multiplicity", NBINSX, binsX, NBINSY, binsY );
    //after signal trigger
    //vs HT
    TH1F * h_HT_nocat_aft = new TH1F("h_HT_nocat_aft", "h_HT_nocat; H_{T} [GeV];", NBINSX, binsX);
    //same as line before, but asking for njets requirement
    TH1F * h_HT_nocat_njets_aft = new TH1F("h_HT_nocat_njets_aft", "h_HT_nocat_njets_aft; H_{T} [GeV];", NBINSX, binsX);
    //same line as before, but asking for mu pt requirement
    TH1F * h_HT_nocat_njets_mupt25_aft = new TH1F("h_HT_nocat_njets_mupt25_aft", "h_HT_nocat_njets_mupt25_aft; H_{T} [GeV];", NBINSX, binsX);
    //same line as before, but asking for jet pt requirement
    TH1F * h_HT_nocat_njets_mupt25_jetpt35_aft = new TH1F("h_HT_nocat_njets_mupt25_jetpt35_aft", "h_HT_nocat_njets_mupt25_jetpt35_aft; H_{T} [GeV];", NBINSX, binsX);
    //vs Njets
    TH1F * h_njets_nocat_aft = new TH1F("h_njets_nocat_aft", "h_njets_nocat_aft; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for HT requirement
    TH1F * h_njets_nocat_HT_aft = new TH1F("h_njets_nocat_HT_aft", "h_njets_nocat_HT_aft; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for mu pt requirement
    TH1F * h_njets_nocat_HT_mupt25_aft = new TH1F("h_njets_nocat_HT_mupt25_aft", "h_njets_nocat_HT_mupt25_aft; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for jet pt requirement
    TH1F * h_njets_nocat_HT_mupt25_jetpt35_aft = new TH1F("h_njets_nocat_HT_mupt25_jetpt35_aft", "h_njets_nocat_HT_mupt25_jetpt35_aft; Jet multiplicity;", 15, 0, 15);
    //2D distribution njets vs HT
    TH2F * h_njetsvsHT_nocat_aft = new TH2F ("h_njetsvsHT_nocat_aft", "h_njetsvsHT_nocat_aft; H_{T} [GeV]; Jet multiplicity", NBINSX, binsX, NBINSY, binsY );

    //histograms: truth
    //before signal trigger
    //vs HT
    TH1F * h_HT_nocat_truth = new TH1F("h_HT_nocat_truth", "h_HT_nocat; H_{T} [GeV];", NBINSX, binsX);
    //same as line before, but asking for njets requirement
    TH1F * h_HT_nocat_njets_truth = new TH1F("h_HT_nocat_njets_truth", "h_HT_nocat_njets_truth; H_{T} [GeV];", NBINSX, binsX);
    //same as line before, but asking for mu pt requirement
    TH1F * h_HT_nocat_njets_mupt25_truth = new TH1F("h_HT_nocat_njets_mupt25_truth", "h_HT_nocat_njets_mupt25_truth; H_{T} [GeV];", NBINSX, binsX);
    //same as line before, but asking for jet pt requirement
    TH1F * h_HT_nocat_njets_mupt25_jetpt35_truth = new TH1F("h_HT_nocat_njets_mupt25_jetpt35_truth", "h_HT_nocat_njets_mupt25_jetpt35_truth; H_{T} [GeV];", NBINSX, binsX);
    //vs Njets
    TH1F * h_njets_nocat_truth = new TH1F("h_njets_nocat_truth", "h_njets_nocat; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for HT requirement
    TH1F * h_njets_nocat_HT_truth = new TH1F("h_njets_nocat_HT_truth", "h_njets_nocat_HT_truth; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for mu pt requirement
    TH1F * h_njets_nocat_HT_mupt25_truth = new TH1F("h_njets_nocat_HT_mupt25_truth", "h_njets_nocat_HT_mupt25_truth; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for jet pt requirement
    TH1F * h_njets_nocat_HT_mupt25_jetpt35_truth = new TH1F("h_njets_nocat_HT_mupt25_jetpt35_truth", "h_njets_nocat_HT_mupt25_jetpt35_truth; Jet multiplicity;", 15, 0, 15);
    //2D distribution njets vs HT
    TH2F * h_njetsvsHT_nocat_truth = new TH2F ("h_njetsvsHT_nocat_truth", "h_njetsvsHT_nocat_truth; H_{T} [GeV]; Jet multiplicity", NBINSX, binsX, NBINSY, binsY );
    //after signal trigger
    //vs HT
    TH1F * h_HT_nocat_truth_aft = new TH1F("h_HT_nocat_truth_aft", "h_HT_nocat; H_{T} [GeV];", NBINSX, binsX);
    //same as line before, but asking for njets requirement
    TH1F * h_HT_nocat_njets_truth_aft = new TH1F("h_HT_nocat_njets_truth_aft", "h_HT_nocat_njets_truth_aft; H_{T} [GeV];", NBINSX, binsX);
    //same as line before, but asking for mu pt requirement
    TH1F * h_HT_nocat_njets_mupt25_truth_aft = new TH1F("h_HT_nocat_njets_mupt25_truth_aft", "h_HT_nocat_njets_mupt25_truth_aft; H_{T} [GeV];", NBINSX, binsX);
    //same as line before, but asking for jet pt requirement
    TH1F * h_HT_nocat_njets_mupt25_jetpt35_truth_aft = new TH1F("h_HT_nocat_njets_mupt25_jetpt35_truth_aft", "h_HT_nocat_njets_mupt25_jetpt35_truth_aft; H_{T} [GeV];", NBINSX, binsX);
    //vs Njets
    TH1F * h_njets_nocat_truth_aft = new TH1F("h_njets_nocat_truth_aft", "h_njets_nocat_aft; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for HT requirement
    TH1F * h_njets_nocat_HT_truth_aft = new TH1F("h_njets_nocat_HT_truth_aft", "h_njets_nocat_HT_truth_aft; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for mu pt requirement
    TH1F * h_njets_nocat_HT_mupt25_truth_aft = new TH1F("h_njets_nocat_HT_mupt25_truth_aft", "h_njets_nocat_HT_mupt25_truth_aft; Jet multiplicity;", 15, 0, 15);
    //same as line before, but asking for jet pt requirement
    TH1F * h_njets_nocat_HT_mupt25_jetpt35_truth_aft = new TH1F("h_njets_nocat_HT_mupt25_jetpt35_truth_aft", "h_njets_nocat_HT_mupt25_jetpt35_truth_aft; Jet multiplicity;", 15, 0, 15);
    //2D distribution njets vs HT
    TH2F * h_njetsvsHT_nocat_truth_aft = new TH2F ("h_njetsvsHT_nocat_truth_aft", "h_njetsvsHT_nocat_truth_aft; H_{T} [GeV]; Jet multiplicity", NBINSX, binsX, NBINSY, binsY );
    TH1::AddDirectory(kTRUE); 

    TChain mychain("tree");
    if (!(file_it->first.find(data) !=std::string::npos)) mychain.Add(input_dir + "outTree*.root"); 
    else mychain.Add(input_dir + "outTree*.root");
    TChain mychain2("allevents");
    if (!(file_it->first.find(data) !=std::string::npos)) mychain2.Add(input_dir + "outTree*.root");

    cout << "Computing the sum of gen event weights..." << endl;
    TH1::StatOverflows(kTRUE);
    TH1D * genEvtWeights = new TH1D("genEvtWeights", "genEvtWeights", 10, -10, 10 );
    double gen_sum_of_weights = 0.0;
    if (!(file_it->first.find(data) !=std::string::npos)) {
    mychain2.Project(genEvtWeights->GetName(), "genWeight_allEvents");
    cout << "genEvtWeights->GetMean(): " << genEvtWeights->GetMean() << endl;
    cout << "genEvtWeights->GetEntries(): " << genEvtWeights->GetEntries() << endl; 
    gen_sum_of_weights = genEvtWeights->GetMean()*genEvtWeights->GetEntries();
    cout << gen_sum_of_weights << endl;
    }
    TH1::StatOverflows(kFALSE);

    double mygenEvtWeight = 1;
    double myPUWeight = 1;
    double myprefireWeight = 1;;
    vector<TLorentzVector> * mygenTaus = {};
    vector<TLorentzVector> * mygenEles = {};
    vector<TLorentzVector> * mygenMuons = {};

    //if running on data, do not set the gen event weight address
    if (!(file_it->first.find(data) !=std::string::npos)) {

        mychain.SetBranchAddress( "EVENT_genWeight_", &mygenEvtWeight );
        mychain.SetBranchAddress( "PUWeight_", &myPUWeight );
        mychain.SetBranchAddress( "EVENT_prefireWeight_", &myprefireWeight );
        mychain.SetBranchAddress("genTaus", &mygenTaus);
        mychain.SetBranchAddress("genEles", &mygenEles);
        mychain.SetBranchAddress("genMuons", &mygenMuons);

    }
    
    vector<TLorentzVector> *myjetsL = {}; 
    mychain.SetBranchAddress("jets", &myjetsL);
    
    vector<int> *myjets_flavor = {};
    mychain.SetBranchAddress("jets_flavour", &myjets_flavor);

    vector<double> *myjets_btags = {};
    mychain.SetBranchAddress("jets_btags", &myjets_btags);

    vector<TLorentzVector> *mybjetsM = {}; 
    mychain.SetBranchAddress("bjetsM", &mybjetsM);

    vector<TLorentzVector> *myelesMVAT = {}; 
    mychain.SetBranchAddress("eleMVAT", &myelesMVAT);

    vector<TLorentzVector> *mymuonsT = {}; 
    mychain.SetBranchAddress("muonsT", &mymuonsT);

    vector<TLorentzVector> *mytausT = {}; 
    mychain.SetBranchAddress("tausT", &mytausT);

    vector<int> *mytausT_genPartFlav = {};
    mychain.SetBranchAddress("tausT_genPartFlav", &mytausT_genPartFlav);
    
    vector<TLorentzVector> *myleptonsMVAT = {}; 
    mychain.SetBranchAddress("leptonsMVAT", &myleptonsMVAT);

    // multijet triggers
    int myHLT_PFHT450_SixJet40_BTagCSV_p056 = 0;
    mychain.SetBranchAddress("HLT_PFHT450_SixJet40_BTagCSV_p056_", &myHLT_PFHT450_SixJet40_BTagCSV_p056);

    int myHLT_PFHT400_SixJet30_DoubleBTagCSV_p056 = 0;
    mychain.SetBranchAddress("HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_", &myHLT_PFHT400_SixJet30_DoubleBTagCSV_p056);

    //reference triggers
    int myHLT_IsoMu24 = 0;
    mychain.SetBranchAddress("HLT_IsoMu24_", &myHLT_IsoMu24);

    int myHLT_IsoMu27 = 0;
    mychain.SetBranchAddress("HLT_IsoMu27_", &myHLT_IsoMu27);

    //HLT_PFJet450 to recover eff in data
    int myHLT_PFJet450 = 0;
    mychain.SetBranchAddress("HLT_PFJet450_", &myHLT_PFJet450);

    Long64_t nevents = mychain.GetEntries();

    for ( Long64_t ievent = 0; ievent < nevents; ++ievent ) {
        //if (ievent > 100) break;
        if ( !(ievent % 100000 ) ) cout << "ievent  =  " << ievent << endl;
        //get i-th entry in tree
        mychain.GetEntry( ievent );
        if (!(mygenEvtWeight > 0)) continue; //ignore negative-weighted events when dealing with TEfficiencies
        
        /////////////////////////////////////////////////////////////////////
        ///////////////////// DEFINE TRIGGER CUTS ///////////////////////////
        /////////////////////////////////////////////////////////////////////

        bool isSignalTrig = (myHLT_PFHT450_SixJet40_BTagCSV_p056 == 1 || myHLT_PFHT400_SixJet30_DoubleBTagCSV_p056 == 1 || myHLT_PFJet450 == 1);
        bool isReferenceTrig = (myHLT_IsoMu24 == 1 || myHLT_IsoMu27 == 1);

        std::string sig = "tttt";
        if (file_it->first.find(sig) !=std::string::npos) {

            bool isgen1tau3L = (mygenTaus->size()==1 && (mygenEles->size() + mygenMuons->size())==3);
            bool isgen2tau2L = (mygenTaus->size()==2 && (mygenEles->size() + mygenMuons->size())==2);
            
            if (isgen1tau3L) {
	 
                bool passed = true;

                for (int e = 0; e < mygenEles->size(); e++) {
		 
                    if (!(mygenEles->at(e).Pt() > 10)) passed = false;
                    if (!(fabs(mygenEles->at(e).Eta()) < 2.4)) passed = false;
	 
                }

                for (int m = 0; m < mygenMuons->size(); m++) {
		 
                    if (!(mygenMuons->at(m).Pt() > 10)) passed = false;
                    if (!(fabs(mygenMuons->at(m).Eta()) < 2.4)) passed = false;
	 
                }

                for (int t = 0; t < mygenTaus->size(); t++) {
                    
                    if (!(mygenTaus->at(t).Pt() > 20)) passed = false;
                    if (!(fabs(mygenTaus->at(t).Eta()) < 2.4)) passed = false;
	 
                }

                if (passed) {

                    h_gen1tau3L_bef->Fill(myjetsL->size(), mygenEvtWeight);
                    if (isSignalTrig) h_gen1tau3L_aft->Fill(myjetsL->size(), mygenEvtWeight);
                    
                }

            }

            if (isgen2tau2L) {
                
                bool passed = true;
     
                for (int e = 0; e < mygenEles->size(); e++) {
		 
                    if (!(mygenEles->at(e).Pt() > 10)) passed = false;
                    if (!(fabs(mygenEles->at(e).Eta()) < 2.4)) passed = false;
	 
                }

                for (int m = 0; m < mygenMuons->size(); m++) {
                    
                    if (!(mygenMuons->at(m).Pt() > 10)) passed = false;
                    if (!(fabs(mygenMuons->at(m).Eta()) < 2.4)) passed = false;
                    
                }

                for (int t = 0; t < mygenTaus->size(); t++) {
		 
                    if (!(mygenTaus->at(t).Pt() > 20)) passed = false;
                    if (!(fabs(mygenTaus->at(t).Eta()) < 2.4)) passed = false;
	 
                }

                if (passed) {

                    h_gen2tau2L_bef->Fill(myjetsL->size(), mygenEvtWeight);
                    if (isSignalTrig) h_gen2tau2L_aft->Fill(myjetsL->size(), mygenEvtWeight);
	 
                }

            }//end is gen2tau2L

        }//end is tttt MC

        //compute HT   
        float HT = 0.0;
        bool jetptcut = false;
        int countjetpt = 0;
        for (unsigned int i = 0; i < myjetsL->size(); i ++)  {
   
            if (myjetsL->at(i).Pt() > 35) countjetpt++;
            HT += myjetsL->at(i).Pt();

        }
        
        if (countjetpt == myjetsL->size()) jetptcut = true;

        //compute HT(j et+lepton)
        float HT_jl = HT;

        for (unsigned int i = 0; i < myleptonsMVAT->size(); i++) {
            
            HT_jl += myleptonsMVAT->at(i).Pt();
            
        }

        //compute trigger efficiency in preselection asking for exactly 1 muon (a la ttH(bb))

        if (myleptonsMVAT->size() == 1 && mymuonsT->size()==1) { //ask for exactly 1 muon

            //Get Muon ID scale factor
            float muonIDSF = 1.0;
            if (!(file_it->first.find(data) !=std::string::npos)) { //read SFs only if MC process
                
                for (int i = 0; i < mymuonsT->size(); i++) {
                    Int_t binx = MuonIDSF->GetXaxis()->FindBin(fabs(mymuonsT->at(i).Eta()));
                    Int_t biny = MuonIDSF->GetYaxis()->FindBin(mymuonsT->at(i).Pt());
                    muonIDSF *= MuonIDSF->GetBinContent(binx, biny);
                }
                if (muonIDSF == 0) muonIDSF = 1.0;

            }
            
            //Get Tau ID scale factors
            float tauIDSF = 1.0;
            if (!(file_it->first.find(data) !=std::string::npos)) { //read SFs only if MC process
            
                for (int i = 0; i < mytausT->size(); i ++) {
                
                    double VSjetSF = VSjetIDTool.getSFvsPT(mytausT->at(i).Pt(), mytausT_genPartFlav->at(i), "");
                    double VSeSF = VSeIDTool.getSFvsEta(fabs(mytausT->at(i).Eta()), mytausT_genPartFlav->at(i), "");
                    double VSmuSF = VSmuIDTool.getSFvsEta(fabs(mytausT->at(i).Eta()), mytausT_genPartFlav->at(i), "");

                    tauIDSF *= VSjetSF;
                    tauIDSF *= VSeSF;
                    tauIDSF *= VSmuSF;

                }
                if (tauIDSF == 0) tauIDSF = 1.0;
            
            }             
            
            //Get b tagging scale factor
            Double_t mybtagWeight;
            if ( file_it->first.find("tttt") !=std::string::npos ) mybtagWeight = evalEventSF_fixedWP(sysType, myjetsL, myjets_flavor, myjets_btags, DeepJetM[year], CSVreader, btagEff_b_tttt, btagEff_c_tttt, btagEff_udsg_tttt);
            if ( file_it->first.find("ttbar") !=std::string::npos ) mybtagWeight = evalEventSF_fixedWP(sysType, myjetsL, myjets_flavor, myjets_btags, DeepJetM[year], CSVreader, btagEff_b_ttbar, btagEff_c_ttbar, btagEff_udsg_ttbar);
            if ( file_it->first.find("QCD") !=std::string::npos ) mybtagWeight = evalEventSF_fixedWP(sysType, myjetsL, myjets_flavor, myjets_btags, DeepJetM[year], CSVreader, btagEff_b_QCD, btagEff_c_QCD, btagEff_udsg_QCD);
            if ( file_it->first.find("+jets") !=std::string::npos || file_it->first.find("ttH") !=std::string::npos ) mybtagWeight = evalEventSF_fixedWP(sysType, myjetsL, myjets_flavor, myjets_btags, DeepJetM[year], CSVreader, btagEff_b_ttX, btagEff_c_ttX, btagEff_udsg_ttX);
            if ( file_it->first.find("st_") !=std::string::npos ) mybtagWeight = evalEventSF_fixedWP(sysType, myjetsL, myjets_flavor, myjets_btags, DeepJetM[year], CSVreader, btagEff_b_ST, btagEff_c_ST, btagEff_udsg_ST);
            if ( file_it->first.find(data) !=std::string::npos ) mybtagWeight = 1.0; // if reading data, set b tagging SF to 1

            std::string tttt = "tttt";
            if (file_it->first.find(tttt) !=std::string::npos) {
             
                if (isSignalTrig) h_HT_signal->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                if (isSignalTrig) h_njets_signal->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
	 
            }

            if (isReferenceTrig) {

                h_HT_nocat->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                h_njets_nocat->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                h_njetsvsHT_nocat->Fill(HT, myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);

                if (myjetsL->size() >= 6) {
   
                    h_HT_nocat_njets->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
     
                    if(mymuonsT->at(0).Pt() > 25) {

                        h_HT_nocat_njets_mupt25->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                        if (jetptcut) h_HT_nocat_njets_mupt25_jetpt35->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);

                    }

                }

                if (HT > 500) {

                    h_njets_nocat_HT->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                    if(mymuonsT->at(0).Pt() > 25) {

                        h_njets_nocat_HT_mupt25->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                        if (jetptcut) h_njets_nocat_HT_mupt25_jetpt35->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
	   
                    }
                    
                }

                if(isSignalTrig) {

                    h_HT_nocat_aft->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                    h_njets_nocat_aft->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                    h_njetsvsHT_nocat_aft->Fill(HT, myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);

                    if (myjetsL->size() >= 6) {

                        h_HT_nocat_njets_aft->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                        if (mymuonsT->at(0).Pt() > 25) {
           
                            h_HT_nocat_njets_mupt25_aft->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                            if (jetptcut) h_HT_nocat_njets_mupt25_jetpt35_aft->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);

                        }

                    }
     
                    if (HT > 500) {

                        h_njets_nocat_HT_aft->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                        if (mymuonsT->at(0).Pt() > 25) {

                            h_njets_nocat_HT_mupt25_aft->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                            if (jetptcut) h_njets_nocat_HT_mupt25_jetpt35_aft->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight); 

                        }

                    }

                }

            }//end if reference trigger

        }// end if exactly 1 muon

        ////////////////////////////////////////////////////////////////////////////
        ////////////////////// MC TRUTH /////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////
  
        if (myleptonsMVAT->size() == 1 && mymuonsT->size()==1) { //ask for exaclty 1 muon

            //Get Muon ID scale factor
            float muonIDSF = 1.0;
            if (!(file_it->first.find(data) !=std::string::npos)) { //read SFs only if MC process
                
                for (int i = 0; i < mymuonsT->size(); i++) {
                    Int_t binx = MuonIDSF->GetXaxis()->FindBin(fabs(mymuonsT->at(i).Eta()));
                    Int_t biny = MuonIDSF->GetYaxis()->FindBin(mymuonsT->at(i).Pt());
                    muonIDSF *= MuonIDSF->GetBinContent(binx, biny);
                }
                if (muonIDSF == 0) muonIDSF = 1.0;

            }
            
            //Get Tau ID scale factors
            float tauIDSF = 1.0;
            if (!(file_it->first.find(data) !=std::string::npos)) { //read SFs only if MC process
            
                for (int i = 0; i < mytausT->size(); i ++) {
                
                    double VSjetSF = VSjetIDTool.getSFvsPT(mytausT->at(i).Pt(), mytausT_genPartFlav->at(i), "");
                    double VSeSF = VSeIDTool.getSFvsEta(fabs(mytausT->at(i).Eta()), mytausT_genPartFlav->at(i), "");
                    double VSmuSF = VSmuIDTool.getSFvsEta(fabs(mytausT->at(i).Eta()), mytausT_genPartFlav->at(i), "");

                    tauIDSF *= VSjetSF;
                    tauIDSF *= VSeSF;
                    tauIDSF *= VSmuSF;

                }
                if (tauIDSF == 0) tauIDSF = 1.0;
            
            }
            
            //Get b tagging scale factor
            Double_t mybtagWeight;
            if ( file_it->first.find("tttt") !=std::string::npos ) mybtagWeight = evalEventSF_fixedWP(sysType, myjetsL, myjets_flavor, myjets_btags, DeepJetM[year], CSVreader, btagEff_b_tttt, btagEff_c_tttt, btagEff_udsg_tttt);
            if ( file_it->first.find("ttbar") !=std::string::npos ) mybtagWeight = evalEventSF_fixedWP(sysType, myjetsL, myjets_flavor, myjets_btags, DeepJetM[year], CSVreader, btagEff_b_ttbar, btagEff_c_ttbar, btagEff_udsg_ttbar);
            if ( file_it->first.find("QCD") !=std::string::npos ) mybtagWeight = evalEventSF_fixedWP(sysType, myjetsL, myjets_flavor, myjets_btags, DeepJetM[year], CSVreader, btagEff_b_QCD, btagEff_c_QCD, btagEff_udsg_QCD);
            if ( file_it->first.find("+jets") !=std::string::npos || file_it->first.find("ttH") !=std::string::npos ) mybtagWeight = evalEventSF_fixedWP(sysType, myjetsL, myjets_flavor, myjets_btags, DeepJetM[year], CSVreader, btagEff_b_ttX, btagEff_c_ttX, btagEff_udsg_ttX);
            if ( file_it->first.find("st_") !=std::string::npos ) mybtagWeight = evalEventSF_fixedWP(sysType, myjetsL, myjets_flavor, myjets_btags, DeepJetM[year], CSVreader, btagEff_b_ST, btagEff_c_ST, btagEff_udsg_ST);
            if ( file_it->first.find(data) !=std::string::npos ) mybtagWeight = 1.0; // if reading data, set b tagging SF to 1
            
            h_HT_nocat_truth->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
            h_njets_nocat_truth->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
            h_njetsvsHT_nocat_truth->Fill(HT, myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
   
            if (myjetsL->size() >= 6) {
                
                h_HT_nocat_njets_truth->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                if (mymuonsT->at(0).Pt() > 25) {

                    h_HT_nocat_njets_mupt25_truth->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                    if(jetptcut) h_HT_nocat_njets_mupt25_jetpt35_truth->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                    
                }
                
            }

            if (HT > 500) {

                h_njets_nocat_HT_truth->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                if (mymuonsT->at(0).Pt() > 25) {

                    h_njets_nocat_HT_mupt25_truth->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                    if (jetptcut) h_njets_nocat_HT_mupt25_jetpt35_truth->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
       
                }
                
            }

  

            if(isSignalTrig) {

                h_HT_nocat_truth_aft->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                h_njets_nocat_truth_aft->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                h_njetsvsHT_nocat_truth_aft->Fill(HT, myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);

                if (myjetsL->size() >= 6){

                    h_HT_nocat_njets_truth_aft->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                    if (mymuonsT->at(0).Pt() > 25) {

                        h_HT_nocat_njets_mupt25_truth_aft->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                        if (jetptcut) h_HT_nocat_njets_mupt25_jetpt35_truth_aft->Fill(HT, mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);

                    }
                    
                }
     
                if (HT > 500) {

                    h_njets_nocat_HT_truth_aft->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                    if (mymuonsT->at(0).Pt() > 25) {

                        h_njets_nocat_HT_mupt25_truth_aft->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
                        if (jetptcut) h_njets_nocat_HT_mupt25_jetpt35_truth_aft->Fill(myjetsL->size(), mygenEvtWeight*myPUWeight*myprefireWeight*muonIDSF*tauIDSF*mybtagWeight);
         
                    }

                }

            } // end if signal trigger
  
        } // end if exactly 1 muon 

    }//end loop over events

    TH1D * totalWeight = new TH1D("totalWeight", "totalWeight", 1, -0.5, 0.5);
    TH1::AddDirectory(kFALSE);
    if (!(file_it->first.find(data) !=std::string::npos)) {  
        totalWeight->Fill(0.0, gen_sum_of_weights);
    }
    TH1::AddDirectory(kTRUE);
 
    outputfile->cd();

    writeTEfficiency(h_HT_nocat, h_HT_nocat_aft, file_it, "e_HT_nocat_");
    if (!(file_it->first.find(data) !=std::string::npos)) writeTEfficiency(h_HT_nocat_truth, h_HT_nocat_truth_aft, file_it, "e_HT_nocat_truth_");

    writeTEfficiency(h_njets_nocat, h_njets_nocat_aft, file_it, "e_njets_nocat_");
    if (!(file_it->first.find(data) !=std::string::npos)) writeTEfficiency(h_njets_nocat_truth, h_njets_nocat_truth_aft, file_it, "e_njets_nocat_truth_");

    writeTEfficiency(h_HT_nocat_njets, h_HT_nocat_njets_aft, file_it, "e_HT_nocat_njets_");
    if (!(file_it->first.find(data) !=std::string::npos)) writeTEfficiency(h_HT_nocat_njets_truth, h_HT_nocat_njets_truth_aft, file_it, "e_HT_nocat_njets_truth_");

    writeTEfficiency(h_njets_nocat_HT, h_njets_nocat_HT_aft, file_it, "e_njets_nocat_HT_");
    if (!(file_it->first.find(data) !=std::string::npos)) writeTEfficiency(h_njets_nocat_HT_truth, h_njets_nocat_HT_truth_aft, file_it, "e_njets_nocat_HT_truth_");

    writeTEfficiency(h_HT_nocat_njets_mupt25, h_HT_nocat_njets_mupt25_aft, file_it, "e_HT_nocat_njets_mupt25_");
    if (!(file_it->first.find(data) !=std::string::npos)) writeTEfficiency(h_HT_nocat_njets_mupt25_truth, h_HT_nocat_njets_mupt25_truth_aft, file_it, "e_HT_nocat_njets_mupt25_truth_");

    writeTEfficiency(h_njets_nocat_HT_mupt25, h_njets_nocat_HT_mupt25_aft, file_it, "e_njets_nocat_HT_mupt25_");
    if (!(file_it->first.find(data) !=std::string::npos)) writeTEfficiency(h_njets_nocat_HT_mupt25_truth, h_njets_nocat_HT_mupt25_truth_aft, file_it, "e_njets_nocat_HT_mupt25_truth_");

    writeTEfficiency(h_HT_nocat_njets_mupt25_jetpt35, h_HT_nocat_njets_mupt25_jetpt35_aft, file_it, "e_HT_nocat_njets_mupt25_jetpt35_");
    if (!(file_it->first.find(data) !=std::string::npos)) writeTEfficiency(h_HT_nocat_njets_mupt25_jetpt35_truth, h_HT_nocat_njets_mupt25_jetpt35_truth_aft, file_it, "e_HT_nocat_njets_mupt25_jetpt35_truth_");

    writeTEfficiency(h_njets_nocat_HT_mupt25_jetpt35, h_njets_nocat_HT_mupt25_jetpt35_aft, file_it, "e_njets_nocat_HT_mupt25_jetpt35_");
    if (!(file_it->first.find(data) !=std::string::npos)) writeTEfficiency(h_njets_nocat_HT_mupt25_jetpt35_truth, h_njets_nocat_HT_mupt25_jetpt35_truth_aft, file_it, "e_njets_nocat_HT_mupt25_jetpt35_truth_");

    writeTEfficiency2D(h_njetsvsHT_nocat, h_njetsvsHT_nocat_aft, file_it, "e_njetsvsHT_nocat_");
    if (!(file_it->first.find(data) !=std::string::npos)) writeTEfficiency2D(h_njetsvsHT_nocat_truth, h_njetsvsHT_nocat_truth_aft, file_it, "e_njetsvsHT_nocat_truth_");

    if (!(file_it->first.find(data) !=std::string::npos)) {
    
        std::string hTotalWeightName(totalWeight->GetName());
        hTotalWeightName.append("_");
        hTotalWeightName.append(file_it->first);
        totalWeight->Write(hTotalWeightName.c_str());
    
    }

    std::string tttt = "tttt";
    if (file_it->first.find(tttt) !=std::string::npos) {
    
        h_HT_signal->Write();
        h_njets_signal->Write();
        h_gen1tau3L_bef->Write();
        h_gen1tau3L_aft->Write();
        h_gen2tau2L_bef->Write();
        h_gen2tau2L_aft->Write();
    
    }

    delete h_HT_nocat;
    delete h_njets_nocat;
    delete h_HT_nocat_njets;
    delete h_njets_nocat_HT;
    delete h_HT_nocat_njets_mupt25;
    delete h_njets_nocat_HT_mupt25;
    delete h_HT_nocat_njets_mupt25_jetpt35;
    delete h_njets_nocat_HT_mupt25_jetpt35;
    delete h_njetsvsHT_nocat;
    delete h_HT_nocat_aft;
    delete h_njets_nocat_aft;
    delete h_HT_nocat_njets_aft;
    delete h_njets_nocat_HT_aft;
    delete h_HT_nocat_njets_mupt25_aft;
    delete h_njets_nocat_HT_mupt25_aft;
    delete h_HT_nocat_njets_mupt25_jetpt35_aft;
    delete h_njets_nocat_HT_mupt25_jetpt35_aft;
    delete h_njetsvsHT_nocat_aft;
    delete h_HT_nocat_truth;
    delete h_njets_nocat_truth;
    delete h_HT_nocat_njets_truth;
    delete h_njets_nocat_HT_truth;
    delete h_HT_nocat_njets_mupt25_truth;
    delete h_njets_nocat_HT_mupt25_truth;
    delete h_HT_nocat_njets_mupt25_jetpt35_truth;
    delete h_njets_nocat_HT_mupt25_jetpt35_truth;
    delete h_njetsvsHT_nocat_truth;
    delete h_HT_nocat_truth_aft;
    delete h_njets_nocat_truth_aft;
    delete h_HT_nocat_njets_truth_aft;
    delete h_njets_nocat_HT_truth_aft;
    delete h_HT_nocat_njets_mupt25_truth_aft;
    delete h_njets_nocat_HT_mupt25_truth_aft;
    delete h_HT_nocat_njets_mupt25_jetpt35_truth_aft;
    delete h_njets_nocat_HT_mupt25_jetpt35_truth_aft;
    delete h_njetsvsHT_nocat_truth_aft;
    delete genEvtWeights;
    delete totalWeight;
    delete h_HT_signal;
    delete h_njets_signal;
    delete h_gen1tau3L_bef;
    delete h_gen1tau3L_aft;
    delete h_gen2tau2L_bef;
    delete h_gen2tau2L_aft;

    delete mygenTaus;
    delete mygenEles;
    delete mygenMuons;
    delete myjetsL;
    delete myjets_flavor;
    delete myjets_btags;
    delete mybjetsM;
    delete myelesMVAT;
    delete mymuonsT;
    delete mytausT;
    delete mytausT_genPartFlav;
    delete myleptonsMVAT;
    
    mychain.Reset();
    mychain2.Reset();

    file_it++;

    }//end loop over files

 delete MuonIDSF; 
 delete btagEff_b_tttt;
 delete btagEff_c_tttt;
 delete btagEff_udsg_tttt;
 delete btagEff_b_ttbar;
 delete btagEff_c_ttbar;
 delete btagEff_udsg_ttbar;
 delete btagEff_b_QCD;
 delete btagEff_c_QCD;
 delete btagEff_udsg_QCD;
 delete btagEff_b_ttX;
 delete btagEff_c_ttX;
 delete btagEff_udsg_ttX;
 delete btagEff_b_ST;
 delete btagEff_c_ST;
 delete btagEff_udsg_ST;
 outputfile->Close();
 delete outputfile;

 gBenchmark->Show("running time");

}//end



void writeTEfficiency(TH1F* hBef, TH1F* hAft, map<string, string>::iterator file_it, TString name) {

    std::string hBefName(hBef->GetName());
    hBefName.append("_");
    hBefName.append(file_it->first);
    std::string hAftName(hAft->GetName());
    hAftName.append("_");
    hAftName.append(file_it->first);
    hBef->Write(hBefName.c_str());
    hAft->Write(hAftName.c_str());
    //TH1F *hRatio =   (TH1F*)hAft->Clone("");
    //hRatio->Divide(hBef);
    //hRatio->Write(name);    
  
    TEfficiency *TEff = 0;
    if(TEfficiency::CheckConsistency(*hAft, *hBef)){
        
        TEff = new TEfficiency(*hAft, *hBef);
        TEff->Write(name+file_it->first);
        delete TEff;
    
    }

}

void writeTEfficiency2D(TH2F* hBef, TH2F* hAft, map<string, string>::iterator file_it, TString name) {

    std::string hBefName(hBef->GetName());
    hBefName.append("_");
    hBefName.append(file_it->first);
    std::string hAftName(hAft->GetName());
    hAftName.append("_");
    hAftName.append(file_it->first);
    hBef->Write(hBefName.c_str());
    hAft->Write(hAftName.c_str());
    //TH1F *hRatio = (TH1F*)hAft->Clone("");
    //hRatio->Divide(hBef);
    //hRatio->Write(name);
  
    TEfficiency *TEff = 0;
    if(TEfficiency::CheckConsistency(*hAft, *hBef)){
            
        TEff = new TEfficiency(*hAft, *hBef);
        TEff->Write(name+file_it->first);
        delete TEff;

    }
    
}
