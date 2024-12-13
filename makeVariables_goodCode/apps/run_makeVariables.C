#include <iostream>
#include <boost/lexical_cast.hpp>

#include "TStopwatch.h"
#include "TString.h"
#include "TChain.h"

#include "../include/makeVariablesMain.h"
#include "../../myLibrary/commenFunction.h"

void run_objectSelection(
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_postVFP/v77forBtagMeasurement/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2017/v77HadroPresel/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2017/v77HadroPresel/data/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2017/v79forHLT/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2017/v79forHLT/data/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2017/v79HadroPresel/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_postVFP/v79forHLT/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_postVFP/v79forHLT/data/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_postVFP/v79HadroPresel/tttt/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_preVFP/v79HadroPresel/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2017/v80addTauJetVar/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v80addTauJetVar/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_postVFP/v80addTauJetVar/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v80addTTExtra/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v81addSysSum/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v82for1tau2l/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v83for1tau2lEleEtaCut/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v84fakeLeptonUpdate/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v84fakeLeptonUpdateV2/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v84fakeLeptonUpdate/data/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v84Pre1tau2lNoLepCut/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v84Pre1tau2lLepF2/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2017/v84Pre1tau2lLepF2/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2017/v84Pre1tau2lNoLepCut/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2017/v84Pre1tau2lLepF2V2/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v84Pre1tau2lLepF2V2/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_postVFP/v84Pre1tau2lLepF2V2/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_preVFP/v84Pre1tau2lLepF2V2/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v84HadroPresel/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2017/v84HadroPresel/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_preVFP/v84HadroPresel/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v85HadroPreselTauOverlap0.5/mc/",
    // TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v86HadroPreSelWithGammaRemoval/mc/",
    TString inputBase = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2018/v86HadroPreSelWithTTWTTZNLO/mc/",
    TString inputDir = "tttt",
    // TString inputDir = "TTZToLLNuNu",
    // TString inputDir = "ttZ",
    // TString inputDir = "ZGToLLG",
    // TString inputDir = "WZTo3LNu",
    // TString inputDir = "wz",
    // TString inputDir = "DYJetsToLL_M-50",
    // TString inputDir = "VLL_EE_M600",
    // TString inputDir = "ttbar_0l",
    // TString inputDir = "ttbar_1l",
    // TString inputDir = "ttbar_2l",
    // TString inputDir = "jetHT_2017f",
    // TString inputDir = "BTagCSV_2017c",
    // TString inputDir = "singleMu_2018b",
    // TString inputDir = "TTToSemiLeptonic10", //extra ttbar for training
    // TString inputDir = "TTTo2L2Nu0",
    // TString inputDir = "doubleMu_2018b",
    TString outputDir = "output/",
    // Int_t numEntries = 100000)
    // Int_t numEntries = 3000)
    Int_t numEntries = 10000)
    // Int_t numEntries = 0)
{
    TStopwatch t;
    t.Start();

    TString inputDir1 = inputBase + inputDir + "/";
    TString processName = inputDir;
    Bool_t isData = TTTT::getIsData(inputDir1);
    TString era = TTTT::getEra2(inputDir1);
    Bool_t isRun3 = TTTT::isRun3(era);
    // Bool_t if1tau2l = kTRUE;
    Bool_t if1tau2l = kFALSE;
    std::cout << "isRun3=" << isRun3 << " era=" << era << "\n";

    MakeVariablesMain mv(inputDir1, outputDir, processName, isData, era, isRun3, if1tau2l);
    Bool_t baseline = kTRUE;
    mv.EventLoop(baseline, kFALSE, numEntries);
    // mv.EventLoop(baseline, kTRUE, numEntries); //!channel cut, for BDT training only 
    mv.Terminate();

    t.Stop();
    t.Print();
    return;
}


int main(int argc, char const *argv[])
{
    TString inputDir;
    TString inputProcess;
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
    }

    return 0;
}