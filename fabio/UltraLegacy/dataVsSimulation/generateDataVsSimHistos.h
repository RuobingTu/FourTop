#include <map>
#include <TMatrixDSym.h>
#include <TVectorD.h>
#include <TMatrixDSymEigen.h>
#include <TLorentzVector.h>

using namespace std;

string MUOSF_dir = "/publicfs/cms/user/fabioiemmi/CMSSW_10_2_20_UL/src/FourTop/fabio/UltraLegacy/scale_factors/muons/";
map<string, string> MUOSF_files = { //MAP OF INPUT MUO SCALE FACTOR FILES                                                                                                                                                            

    {"UL2016_preVFP", MUOSF_dir + "Efficiencies_muon_generalTracks_Z_Run2016_UL_preVFP_ID.root"},
    {"UL2016_postVFP", MUOSF_dir + "Efficiencies_muon_generalTracks_Z_Run2016_UL_postVFP_ID.root"},
    {"UL2017", MUOSF_dir + "Efficiencies_muon_generalTracks_Z_Run2017_UL_ID.root"},
    {"UL2018", MUOSF_dir + "Efficiencies_muon_generalTracks_Z_Run2018_UL_ID.root"},

};

string EGammaSF_dir = "/publicfs/cms/user/fabioiemmi/CMSSW_10_2_20_UL/src/FourTop/fabio/UltraLegacy/scale_factors/electrons/";
map<string, string> EGammaSF_files = { //MAP OF INPUT EGamma SCALE FACTOR FILES                                                                                                                                                            

    {"UL2016_preVFP", EGammaSF_dir + "egammaEffi.txt_Ele_wp90noiso_preVFP_EGM2D.root"},
    {"UL2016_postVFP", EGammaSF_dir + "egammaEffi.txt_Ele_wp90noiso_postVFP_EGM2D.root"},
    {"UL2017", EGammaSF_dir + "egammaEffi.txt_EGM2D_MVA90noIso_UL17.root"},
    {"UL2018", EGammaSF_dir + "egammaEffi.txt_Ele_wp90noiso_EGM2D.root"},

};

string BTVSF_dir = "/publicfs/cms/user/fabioiemmi/CMSSW_10_2_20_UL/src/FourTop/fabio/UltraLegacy/scale_factors/btagging/";
map<string, string> BTVSF_files = { //MAP OF INPUT BTV SCALE FACTOR FILES

    {"UL2016_preVFP", BTVSF_dir + "reshaping_deepJet_106XUL16preVFP_v2_dropLines.csv"},
    {"UL2016_postVFP", BTVSF_dir + "reshaping_deepJet_106XUL16postVFP_v3_dropLines.csv"},
    {"UL2017", BTVSF_dir + "reshaping_deepJet_106XUL17_v3_dropLines.csv"},
    {"UL2018", BTVSF_dir + "reshaping_deepJet_106XUL18_v2_dropLines.csv"},

};

std::map<TString, double> DeepJetM = { //std::map of medium WPs for DeepJet

    {"UL2016_postVFP", 0.2489},
    {"UL2016_preVFP", 0.2598},
    {"UL2017", 0.3040},
    {"UL2018", 0.2783},

};

map<string, map<string, string>> file = { //MAP OF INPUT FILES

    {"UL2016_preVFP", 
     {   //signal
         
         {"tttt", "tttt"},

         //ttbar background    
         {"ttbar-FH", "ttbar_0l"},//broken
         {"ttbar-SL", "ttbar_1l"},
         {"ttbar-DL", "ttbar_2l"},

         //QCD background    
         {"QCD_HT200to300", "qcd_200to300"},
         {"QCD_HT300to500", "qcd_300to500"},
         {"QCD_HT500to700", "qcd_500to700"},
         {"QCD_HT700to1000", "qcd_700to1000"},
         {"QCD_HT1000to1500", "qcd_1000to1500"},
         {"QCD_HT1500to2000", "qcd_1500to2000"},
         {"QCD_HT2000toInf", "qcd_2000toInf"},

         //tt+X background   
         {"ttW+jets", "ttW"},   
         {"ttZ+jets", "ttZ"},   
         {"ttG+jets", "ttG"},   
         {"ttH_bb", "ttH_bb"},  
         {"ttH_nonbb", "ttH_nonbb"},    

         //single-top background 
         {"st_tchan", "st_tchan"},
         {"st_antitchan", "st_antitchan"},
         {"st_tW_top", "st_tW_top"},
         {"st_tW_antitop", "st_tW_antitop"},
         {"st_tZq", "st_tZq"},
         
         {"data_JetHT_eraB_v1", "jetHT_2016B_v1"},
         {"data_JetHT_eraB_v2", "jetHT_2016B_v2"},
         {"data_JetHT_eraC", "jetHT_2016C"},    
         {"data_JetHT_eraD", "jetHT_2016D"},
         {"data_JetHT_eraE", "jetHT_2016E"},
         {"data_JetHT_eraF_hipm", "jetHT_2016F_hipm"},
         
     }
    }, //UL2016_preVFP

    {"UL2016_postVFP", 
     {   //signal
         
         {"tttt", "tttt"},

         //ttbar background    
         {"ttbar-FH", "ttbar_0l"},//broken
         {"ttbar-SL", "ttbar_1l"},
         {"ttbar-DL", "ttbar_2l"},

         //QCD background    
         {"QCD_HT200to300", "qcd_200to300"},
         {"QCD_HT300to500", "qcd_300to500"},
         {"QCD_HT500to700", "qcd_500to700"},
         {"QCD_HT700to1000", "qcd_700to1000"},
         {"QCD_HT1000to1500", "qcd_1000to1500"},
         {"QCD_HT1500to2000", "qcd_1500to2000"},
         {"QCD_HT2000toInf", "qcd_2000toInf"},

         //tt+X background   
         {"ttW+jets", "ttW"},   
         {"ttZ+jets", "ttZ"},   
         {"ttG+jets", "ttG"},   
         {"ttH_bb", "ttH_bb"},  
         {"ttH_nonbb", "ttH_nonbb"},    

         //single-top background 
         {"st_tchan", "st_tchan"},
         {"st_antitchan", "st_antitchan"},
         {"st_tW_top", "st_tW_top"},
         {"st_tW_antitop", "st_tW_antitop"},
         {"st_tZq", "st_tZq"},

         {"data_JetHT_eraF", "jetHT_2016F"},    
         {"data_JetHT_eraG", "jetHT_2016G"},    
         {"data_JetHT_eraH", "jetHT_2016H"},    
        
     }
    }, //UL2016_postVFP

};

void writeHisto(TH1F* histo, map<string, string>::iterator file_it);
 
float HTCalculator ( vector<TLorentzVector> * jets );

double bTagScoreAllJetsCalculator ( vector<double> * btag_scores );

double InvariantMassCalculator(vector<TLorentzVector> * jets);

double SysPtCalculator(vector<TLorentzVector> * jets);

double MTCalculator(vector<TLorentzVector> * jets);

double TransEnergyCalculator(TLorentzVector jet);

double TransEnergySysCalculator(vector<TLorentzVector> * jets);

double ratioHT_4toRestCalculator(vector<TLorentzVector> * jets);

double MinDeltaRSingleCalculator(vector<TLorentzVector> * jets);

double energyCal( vector<TLorentzVector> * jets );

double pzCal( vector<TLorentzVector> * jets );

void SphericityAplanarityCal( vector<TLorentzVector> * jets, double& Spher, double& Apla );

double MinDeltaRCal(vector<TLorentzVector> * jets, vector<TLorentzVector> * leptons);

double DeltaR(double eta1, double eta2, double phi1, double phi2);

double AverageDeltaRCal(vector<TLorentzVector> * jets);

double bscoreSumOf4largestCal(vector<double> * btag_scores);

double TransMassCal(vector<TLorentzVector> * jets);

double InvariantMass2SysCal(vector<TLorentzVector> * a, vector<TLorentzVector> * b);
