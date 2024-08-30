#include <iostream>
#include <boost/lexical_cast.hpp>

#include "TStopwatch.h"
#include "TString.h"
#include "TChain.h"

#include "../include/makeVariablesMain.h"
#include "../../myLibrary/commenFunction.h"

void run_objectSelection(
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/V75NoHLTNoTauBjet2/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v75NoHLTNoTauHT400Jet6pt30/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v77ForHLT/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v76WithVLLSample/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v76WithVLLAllMass/mc/",
    TString inputBase = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/UL2018/v76WithVLLAllMassCROfficial/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2baselineHardro_FRweightSys_v76WithVLLAllMass/mc/", 

    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022postEE/v0for2022NoHLT/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022postEE/v0for2022baseline/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022postEE/v1for2022preSel/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022postEE/v2leptonsNameChange/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022postEE/v3EnergyScaleDone/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v3EnergyScaleDone/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v3EnergyScaleDone/data/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022postEE/v3NoHLTNoBtagButTauSel/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022postEE/v3NotHLTPre/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022postEE/v3HLTPre/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022postEE/v4HLTPreNoEnergyScale/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v4HLTPreNoEnergyScale/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v5HLTPreJetVetoMap/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v6AllEnergyScale/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v7tauSelFix/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v8OldTauIDNoTES/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v9addTauTT/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v10addBjetPTT/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v11overlapRemovalTausT/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2022preEE/v13BetterHLTSel/mc/",
    // TString inputDir = "tttt",
    //std::vector<TString> allProcesses = {
    //    //"VLL_EE_M500",
    //    //"VLL_EN_M500",
    //    //"VLL_NN_M500",
    //    //"VLL_EE_M550",
    //    //"VLL_EN_M550",
    //    //"VLL_NN_M550",
    //    "VLL_EE_M600",
    //    "VLL_EN_M600",
    //    "VLL_NN_M600",
    //    "VLL_EE_M650",
    //    "VLL_EN_M650",
    //    "VLL_NN_M650",
    //    "VLL_EE_M700",
    //    "VLL_EN_M700",
    //    "VLL_NN_M700",
    //    "VLL_EE_M750",
    //    "VLL_EN_M750",
    //    "VLL_NN_M750",
    //    "VLL_EE_M800",
    //    "VLL_EN_M800",
    //    "VLL_NN_M800",
    //    "VLL_EE_M850",
    //    "VLL_EN_M850",
    //    "VLL_NN_M850",
    //    "VLL_EE_M900",
    //    "VLL_EN_M900",
    //    "VLL_NN_M900",
    //    "VLL_EE_M950",
    //    "VLL_EN_M950",
    //    "VLL_NN_M950",
    //    "VLL_NN_M1000",
//
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
    //},
    // TString inputDir = "VLL_EE_M600",
    // TString inputDir = "VLL_EE_M800",
    // TString inputDir = "ttbar_0l",
    TString inputDir = "ttbar_1l",
    // TString inputDir = "jetHT_2017f",
    // TString inputDir = "BTagCSV_2017c",
    // TString inputDir = "JetMET2022D",
    // TString inputDir = "singleMu_2017b",
    // TString inputDir = "singleMu_2016F",
    // TString inputDir = "ttbar_1l",
    // TString inputBase = "/workfs2/cms/huahuil/4topCode/CMSSW_10_2_20_UL/src/FourTop/objectSelectionOptimized/",
    // TString inputDir = "TTto4Q",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/Prompt2022/v0Testing/data/",
    // TString inputDir = "JetMET_G",
    // TString inputDir = "output",
    TString outputDir = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v2cut1tau1lCR1TauF_v76WithVLLAllMassOfficial/mc/",
    // Int_t numEntries = 100000)
    // Int_t numEntries = 3000)
    // Int_t numEntries = 10000)
    Int_t numEntries = 0)
{   
    //for(std::vector<TString>::size_type i=0; i<allProcesses.size();i++){
        TStopwatch t;
        t.Start();
        //inputDir = allProcesses[i];
        TString inputDir1 = inputBase + inputDir + "/";
        TString processName = inputDir;
        Bool_t isData = TTTT::getIsData(inputDir1);
        TString era = TTTT::getEra2(inputDir1);
        Bool_t isRun3 = TTTT::isRun3(era);
        std::cout << "isRun3=" << isRun3 << " era=" << era << "\n";

        MakeVariablesMain mv(inputDir1, outputDir, processName, isData, era, isRun3);
        Bool_t baseline = kTRUE;
        // Bool_t baseline = kFALSE;
        mv.EventLoop(baseline, kTRUE, numEntries); //1tau1l cut 
        // mv.EventLoop(baseline, kFALSE, numEntries);
        mv.Terminate();

        t.Stop();
        t.Print();
    //}
    return;
}


int main(int argc, char const *argv[])
{
    TString inputDir;
    TString inputProcess;
    std::vector<TString> allProcesses;
    TString outputDir;
    Int_t numEntries = 0;
    if (argc < 4)
    {
        std::cout << "not enough input from command line\n";
        run_objectSelection();
    }
    else
    {
        std::cout << "using input from command line\n";
        inputDir = boost::lexical_cast<std::string>(argv[1]);
        inputProcess = boost::lexical_cast<std::string>(argv[2]);
        outputDir = boost::lexical_cast<std::string>(argv[3]);
        numEntries = boost::lexical_cast<Int_t>(argv[4]);
        run_objectSelection(inputDir, inputProcess, outputDir, numEntries);
        return 0;
    }

    return 0;
}