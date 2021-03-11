#include <map>

using namespace std;

double LUMI2016 = 35900.0;

string dir = "/publicfs/cms/user/fabioiemmi/TauOfTTTT/test_refTriggers/NoJEC/";

map<string, string> file = { //MAP OF INPUT FILES
    
//signal
{"tttt", dir + "TTTT_TuneCUETP8M2T4_13TeV-amcatnlo-pythia8.root"},

//ttbar background    
{"tt", dir + "TT_TuneCUETP8M2T4_13TeV-powheg-pythia8.root"},
  
//QCD background
//{"QCD_HT200to300", dir + "QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root"},
{"QCD_HT300to500", dir + "QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root"},
{"QCD_HT500to700", dir + "QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root"},
{"QCD_HT700to1000", dir + "QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root"},
{"QCD_HT1000to1500", dir + "QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root"},
{"QCD_HT1500to2000", dir + "QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root"},
{"QCD_HT2000toInf", dir + "QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root"},
  
//tt+X background
{"ttG+jets", dir + "TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8.root"},
{"ttW+jets", dir + "ttWJets_13TeV_madgraphMLM.root"},
{"ttZ+jets", dir + "ttZJets_13TeV_madgraphMLM-pythia8.root"},
{"ttH", dir + "ttH_4f_ctcvcp_TuneCP5_13TeV_madgraph_pythia8.root"},

//diboson background
{"WZ", dir + "WZ_TuneCUETP8M1_13TeV-pythia8.root"},
{"WWTo2L2Nu", dir + "WWTo2L2Nu_DoubleScattering_13TeV-pythia8.root"},
{"WpWpJJ", dir + "WpWpJJ_EWK-QCD_TuneCUETP8M1_13TeV-madgraph-pythia8.root"}, //WHAT'S THIS PROCESS?
{"ZZ", dir + "ZZ_TuneCUETP8M1_13TeV-pythia8.root"},
{"WG+jets", dir + "WGJets_MonoPhoton_PtG-40to130_TuneCUETP8M1_13TeV-madgraph.root"},
{"ZG+jets", dir + "ZGJetsToLLG_EW_LO_13TeV-sherpa.root"},

//triboson background
{"WWW", dir + "WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root"},
{"WWZ", dir + "WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root"},
{"WWG", dir + "WWG_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root"},
{"ZZZ", dir + "ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root"},
{"WZZ", dir + "WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root"},
{"WZG", dir + "WZG_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root"},
{"WGG", dir +"WGG_5f_TuneCUETP8M1_13TeV-amcatnlo-pythia8.root"},
{"ZGG+jets", dir + "ZGGJets_ZToHadOrNu_5f_LO_madgraph_pythia8.root"},

//W+jets background
{"W+jets", dir + "WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root"},

//DY background
{"DY", dir + "DYJetsToTauTau_ForcedMuEleDecay_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_ext1.root"},

//single-top background
{"tZq", dir + "tZq_ll_4f_ckm_NLO_TuneCP5_PSweights_13TeV-amcatnlo-pythia8.root"},
{"tW_antitop", dir + "ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M2T4.root"},
{"tW_top", dir + "ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M2T4.root"},
{"tG+jets", dir + "TGJets_TuneCUETP8M1_13TeV_amcatnlo_madspin_pythia8.root"},
{"tHW", dir + "THW_ctcvcp_HIncl_M125_TuneCP5_13TeV-madgraph-pythia8.root"},
{"THq", dir + "THQ_ctcvcp_Hincl_13TeV-madgraph-pythia8_TuneCUETP8M1.root"},

//Higgs background
{"VHToNonbb", dir + "VHToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8.root"},
{"ZHToTauTau", dir + "ZHToTauTau_M125_13TeV_powheg_pythia8.root"},
{"ZHTobb", dir + "ZH_HToBB_ZToLL_M125_13TeV_powheg_pythia8.root"},
{"GluGluHTo4L", dir + "GluGluHToZZTo4L_M125_13TeV_powheg2_JHUgenV6_pythia8.root"},
{"GluGluHTobb", dir + "GluGluHToBB_M125_13TeV_amcatnloFXFX_pythia8.root"},
{"GluGluHToGG", dir + "GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8.root"},
{"GluGluHToMuMu", dir + "GluGluHToMuMu_M-125_TuneCP5_PSweights_13TeV_powheg_pythia8.root"},
{"GluGluHToTauTau", dir + "GluGluHToTauTau_M125_13TeV_powheg_pythia8.root"},
{"GluGluHTo2L2Nu", dir + "GluGluHToWWTo2L2Nu_M125_13TeV_powheg_JHUgen_pythia8.root"},
{"GluGluHToLNuqq", dir + "GluGluHToWWToLNuQQ_M125_13TeV_powheg_JHUGenV628_pythia8.root"},
{"VBFHTo2L2Nu", dir + "VBFHToWWTo2L2Nu_M125_13TeV_powheg_JHUgenv628_pythia8.root"},
{"VBFHToMuMu", dir + "VBFHToMuMu_M-125_TuneCP5_PSweights_13TeV_powheg_pythia8.root"},
{"VBFHToGG", dir + "VBFHToGG_M125_13TeV_amcatnlo_pythia8_v2.root"},

};

map<string, float> xsec = { //MAP OF CROSS SECTIONS. TAKE HUILING'S, BUT WHERE DO THEY COME FROM?
    
//signal
{"tttt", 0.01197},

//ttbar background    
{"tt", 746.7},

//QCD background
{"QCD_HT200to300", 1751000.0},
{"QCD_HT300to500", 347700.0},
{"QCD_HT500to700", 32100.0},
{"QCD_HT700to1000", 6831.0},
{"QCD_HT1000to1500", 1207.0},
{"QCD_HT1500to2000", 119.9},
{"QCD_HT2000toInf", 25.24},

    
//tt+X background
{"ttG+jets", 3.773},
{"ttW+jets", 0.2014},
{"ttZ+jets", 0.6559},
{"ttH", 0.3372},

//diboson background
{"WZ", 2.343},
{"WWTo2L2Nu", 0.1697},
{"WpWpJJ", 0.05390}, //WHAT'S THIS PROCESS?
{"ZZ", 1.016},
{"WG+jets", 1.269},
{"ZG+jets", 0.1319},

//triboson background
{"WWW", 0.2086},
{"WWZ", 0.1651},
{"WWG", 0.2147},
{"ZZZ", 0.01398},
{"WZZ", 0.05565},
{"WZG", 0.04123},
{"WGG", 1.819},
{"ZGG+jets", 0.3717},

//W+jets background
{"W+jets", 50300.0},

//DY background
{"DY", 1983.0},

//single-top backgroun
{"tZq", 0.07358},
{"tW_antitop", 38.06},
{"tW_top", 38.09},
{"tG+jets", 2.967},
{"tHW", 0.1467},
{"THq", 0.8816},

//Higgs background
{"VHToNonbb", 2.137},
{"ZHToTauTau", 0.7524},
{"ZHTobb", 0.07523},
{"GluGluHTo4L", 2.999},
{"GluGluHTobb", 32.10},
{"GluGluHToGG", 31.98}, // cross section for ggH(bb) and ggH(gammgamma) comparable, how is this possible?
{"GluGluHToMuMu", 29.99}, // same holds for ggH(mumu)
{"GluGluHToTauTau", 30.52}, // same holds for ggH(tautau)
{"GluGluHTo2L2Nu", 30.52}, // same
{"GluGluHToLNuqq", 29.99},
{"VBFHTo2L2Nu", 3.769},
{"VBFHToMuMu", 0.000823}, //there's no such a big difference in xsec between ggH(mumu) and VBF(mumu) production mechanisms 
{"VBFHToGG", 3.992},

};

void writeTEfficiency(TH1F* hBef, TH1F* hAFt, TString name);
