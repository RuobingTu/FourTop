#include <iostream>
#include <boost/lexical_cast.hpp>

#include "TStopwatch.h"

#include "../include/writeHist_forDataMC.h"
#include "../include/functions.h"
#include "../../myLibrary/commenFunction.h"
#include "../include/writeHist_btagEff.h"
#include "../include/writeHist_btagShapeR.h"
#include "../include/writeHist_fakeRate.h"
#include "../include/writeHist_HLTeff.h"

void run_treeAnalyzer(
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1fixedTauProng_v64noHLTSel/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1fixedTauProng_v63smallFixJER/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0NewHLTSFBinA_v64PreAndHLTSel/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baseline_v64noHLTSel/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0NewHLTSFHT550BinF_v64PreAndHLTSel/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baseline_v67TheoryWeightAdded/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHT350_v75NotHLTNoBJetTauT/mc/",//!!!for btag efficiency
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v3baselineAddFRWeight_v75OverlapRemovalFTau/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baseline_v76For1tau2l/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_v75OverlapRemovalFTau/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHT450Jet6pt32_v75NoHLTNoTauHT400Jet6pt30/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_newTriSFBinD_v75OverlapRemovalFTau/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_v77ForHLT/mc/", //!!!for HLT
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_newTriSFBinD_v76WithVLLSample/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1baselineHardro_btagMTWeight_v76WithVLLAllMass/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baselineHardro_v77forBtagMeasurement/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/v0baselineHardro_v77forBtagMeasurement/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baselineHardro_v77ForHLT/mc/", //!!!for HLT
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baselineHardro_v77HadroPresel/mc/", 
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baselineHardro_v77HadroPresel/data/", 
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baselineHardro_v79forHLT/mc/", //!for HLT
    TString inputDir = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v2cut1tau1lCR1TauF_v76WithVLLAllMassOfficial/data/", 

    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2022preEE/v1TauSFNew_v9addTauTT/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2022preEE/v0baseline_v10addBjetPTT/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2022preEE/v0baseline6thJet30_v11overlapRemovalTausT/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2022preEE/v0NoSel_v13BetterHLTSel/mc/",

    TString process = "jetHT_2018a",
    // std::vector<TString> allProcesses = {
    //     "VLL_EE_M600",
    //     "VLL_EN_M600",
    //     "VLL_NN_M600",
    //     // "VLL_EE_M600",
    //     // "VLL_EN_M600",
    //     // "VLL_NN_M600",
    //     // "VLL_EE_M800",
    //     // "VLL_EN_M800",
    //     // "VLL_NN_M800",
    //     // "VLL_EE_M700",
    //     // "VLL_EN_M700",
    //     // "VLL_NN_M700",
    //     "tttt",
    //     "ttbar_0l",
    //     "ttbar_2l",
    //     "ttbar_1l",
    //     "ttG",
    //     "ttZ",  
    //     "ttW",
    //     "ttH_bb", 
    //     "ttH_nonbb", 
// 
    //     "st_tZq",
    //     "st_tW_antitop",
    //     "st_tW_top",
// 
    //     "WJetsToLNu_HT-200To400",
    //     "WJetsToLNu_HT-400To600",
    //     "WJetsToLNu_HT-600To800",
    //     "WJetsToLNu_HT-800To1200",
    //     "WJetsToLNu_HT-1200To2500",
    //     "WJetsToLNu_HT-2500ToInf",
// 
    //     // "fakeTau_tauF",
    //     // "fakeTau_tauT",
    //     // "fakeTau_tauFGen",
    //     // "fakeTau_tauTGen",
    // },
    // std::vector<TString> allProcesses = { "jetHT_2018a", "jetHT_2018b", "jetHT_2018c", "jetHT_2018d" },

    // TString process = "VLL_EN_M600",
    // TString process = "fakeTau_tauF",
    // TString process = "jetHT_2018d",
    // TString process = "singleMu_2016E_v2",
    // TString process = "BTagCSV_2017f",
    // TString process = "ttbar_0l",
    // TString process = "ttbar_1l",
    TString histVersion = "plot_VLL_M600",
    Bool_t isTest = kFALSE)
// Bool_t isTest = kFALSE)
{
    //for(std::vector<TString>::size_type i=0; i<allProcesses.size();i++){
    //process = allProcesses[i];
    TStopwatch t;
    t.Start();

    WH_forDataMC writeHist(inputDir, process, kFALSE, histVersion, isTest);//
    // WH_forDataMC writeHist(inputDir, process, kTRUE, histVersion, isTest);//!faketau
    // WriteHist_btagEff writeHist(inputDir, process, histVersion, isTest);
    // WriteHist_btagShapeR writeHist(inputDir, process, histVersion, isTest);
    // WH_fakeRate writeHist(inputDir, process, histVersion, isTest);
    // WH_HLTeff writeHist(inputDir, process, histVersion, isTest);

    writeHist.Init();
    UInt_t entry = 0;
    if (isTest)
    {
        entry = 5000;
    }
    writeHist.LoopTree(entry); //!!!maybe provide cut and weight as parameter here
    writeHist.Terminate();

    t.Stop();
    t.Print();
    //}
}

int main(int argc, char const *argv[])
{
    TString inputDir;
    TString inputProcess;
    TString version;
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
        isTest = boost::lexical_cast<Bool_t>(argv[4]);
        run_treeAnalyzer(inputDir, inputProcess, version, isTest);
    }

    return 0;
}