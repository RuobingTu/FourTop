#include <iostream>
#include <boost/lexical_cast.hpp>

#include "TStopwatch.h"

#include "../include/treeAnalyzer.h"
#include "../include/functions.h"

void run_treeAnalyzer(
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baseline_v76For1tau2l/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_v75OverlapRemovalFTau/mc/",
    // TString inputDir = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v2cut1tau1lCR1TauF_v76WithVLLAllMassOfficial/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2baselineHardro_FRweightSys_v76WithVLLSample/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_newTriSFBinD_v76WithVLLSample/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2baselineHardro_FRweightSys_v76WithVLLAllMass/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v1baselineHardro_FRweightSys_v79HadroPresel/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1baselineHardro_btagMTWeight_v76WithVLLAllMass/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1baselineHardro_btagMTWeight_v76WithVLLAllMass/data/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v1baselineHardro_FRweightSys_v79HadroPresel/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baselineHardro_v80addTauJetVar/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_v80addTauJetVar/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0baselineHardro_v80addTauJetVar/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_v81addSysSum/mc/",
    TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineLep_v84Pre1tau2lLepF2/mc/",
    // TString process = "tttt",
    // TString process = "st_tZq",
    // TString process = "fakeTau_tauF",
    // TString process = "ttbar_0l",
    // TString process = "ttbar_2l",
    // TString process = "jetHT_2016E",
    TString process = "ttZ",
    //std::vector<TString> allProcesses = {
    //    "VLL_EE_M600",
    //    "VLL_EN_M600",
    //    "VLL_NN_M600",
    //    // "VLL_EE_M600",
    //    // "VLL_EN_M600",
    //    // "VLL_NN_M600",
    //    // "VLL_EE_M800",
    //    // "VLL_EN_M800",
    //    // "VLL_NN_M800",
    //    // "VLL_EE_M700",
    //    // "VLL_EN_M700",
    //    // "VLL_NN_M700",
    //    "tttt",
    //    "ttbar_0l",
    //    "ttbar_2l",
    //    "ttbar_1l",
    //    "ttG",
    //    "ttZ",  
    //    "ttW",
    //    "ttH_bb", 
    //    "ttH_nonbb", 
//
    //    "st_tZq",
    //    "st_tW_antitop",
    //    "st_tW_top",
//
    //    "WJetsToLNu_HT-200To400",
    //    "WJetsToLNu_HT-400To600",
    //    "WJetsToLNu_HT-600To800",
    //    "WJetsToLNu_HT-800To1200",
    //    "WJetsToLNu_HT-1200To2500",
    //    "WJetsToLNu_HT-2500ToInf",
//
    //    // "fakeTau_tauF",
    //    // "fakeTau_tauT",
    //    // "fakeTau_tauFGen",
    //    // "fakeTau_tauTGen",
    //},
    // TString process = "TTto4Q",
    // TString process = "TTto2L2Nu",
    TString histVersion = "v0BasicBDTtraining1tau1l_VLLm600",
    // Int_t channel = 0,//0: 1tau1l
    // TString channel = "1tau1l",//0: 1tau1l
    TString channel = "1tau1l",//
    // TString channel = "1tau2l",//
    // Bool_t isTest = kTRUE)
    Bool_t isTest = kFALSE)
{
    //for(std::vector<TString>::size_type i=0; i<allProcesses.size();i++){
    //    process = allProcesses[i];
    TStopwatch t;
    t.Start();
    treeAnalyzer writeBDTHist(inputDir, process, histVersion, channel, isTest);
    writeBDTHist.Init();
    writeBDTHist.LoopTree(); //!!!maybe provide cut and weight as parameter here
    writeBDTHist.Terminate();

    t.Stop();
    t.Print();
    //}
}

int main(int argc, char const *argv[])
{
    TString inputDir;
    TString inputProcess;
    TString version;
    TString channel;
    Bool_t isTest = kFALSE;
    if (argc < 4)
    {
        std::cout << "not enough input from command line\n";
        run_treeAnalyzer();
    }
    else
    {
        std::cout << "using input from command line\n";
        inputDir = boost::lexical_cast<std::string>(argv[1]);
        inputProcess = boost::lexical_cast<std::string>(argv[2]);
        version = boost::lexical_cast<std::string>(argv[3]);
        channel = boost::lexical_cast<std::string>(argv[4]);
        isTest = boost::lexical_cast<Bool_t>(argv[5]);
        run_treeAnalyzer(inputDir, inputProcess, version, channel, isTest);
    }

    return 0;
}
