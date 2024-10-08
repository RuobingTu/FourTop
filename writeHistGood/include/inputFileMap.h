#ifndef INPUTFILEMAP_H
#define INPUTFILEMAP_H

#include "TString.h"
#include <map>

/// non-constant globals have external linkage by default
//const globals have internal linkage by default

namespace WH
{

inline const   std::map<TString, Int_t> channelMap = {//!!!this coding is bullshit
            {"1tau1l", 0},
            {"1tau0l", 1},
            {"1tau2l", 2},
        };

inline const std::map<TString, TString> triggerSF_map = {
    {"2016", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3baslineNoHLTMuonTriggerAdded_v52noHLTButPreSelection/mc/variableHists_v8add2DHist/results/baseline1Muon1b_triggerSF.root"},
    {"2017", ""},
    {"2018", ""},
};

inline const std::map<TString, TString> btagR_map = {
    // {"2016", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v2aadTopLepWeight_v49FixedPileUpJERAndTES/mc/variableHists_v6_btagRMeasure/results/btagR.root"}, //!!!to be updated!
    {"2016", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3HLTWeightUpdated_v55ojectRemovalwithTightNoHLT/mc/variableHists_v0btagRCal/results/btagR.root"},
    // {"2017", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v3HLTWeightUpdatedBugFixed_v56NoHLTButPre/mc/variableHists_v6_btagRMeasure/results/1tau1lNoBbtagR.root"},
    {"2017", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v3HLTWeightUpdatedBugFixed_v56NoHLTButPre/mc/variableHists_v6_btagRMeasure/results/1tau0lNoBbtagR.root"},
    {"2018", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v3HLTWeightUpdatedBugFixed_v56NoHLTButPre/mc/variableHists_v6_btagRMeasure/results/1tau0lNoBbtagR.root"},
    // {"2018", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v2aadTopLepWeight_v49FixedPileUpJERAndTES/mc/variableHists_v6_btagRMeasure/results/btagR.root"}, // //!!!to be updated!
};

inline const std::map<TString, std::array<TString, 2>> BDTTrainingMap = {
    // {"2016", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v5extra1tau1lCut_v56NoHLTButPre/1tau1l_v0/variableList/varibleList_16.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v5extra1tau1lCut_v56NoHLTButPre/1tau1l_v0/dataset/1tau1lvaribleList_16_weight/"}},
    // {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v5extra1tau1lCut_v56preselection/1tau1l_v0/variableList/varibleList_16.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v5extra1tau1lCut_v56preselection/1tau1l_v0/dataset/1tau1lvaribleList_16_weight/"}},
    // {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v5extra1tau1lCut_v56preselection/1tau1l_v3/variableList/varibleList_16.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v5extra1tau1lCut_v56preselection/1tau1l_v3/dataset/1tau1lvaribleList_16_weight/"}},
    // {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v7forBDT_v60fixeJetBtagBug/1tau1l_v0/variableList/varibleList_16.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v7forBDT_v60fixeJetBtagBug/1tau1l_v0/dataset/1tau1lvaribleList_16_weight/"}}, //b tag shape
    // {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v7forBDT_v60fixeJetBtagBug/1tau1l_v1/variableList/varibleList_16.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v7forBDT_v60fixeJetBtagBug/1tau1l_v1/dataset/1tau1lvaribleList_16_weight/"}}, //WP
    // {"2016", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/variableList/varibleList_15.csv","/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/dataset/1tau1lvaribleList_15_weight/"}},
    // {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/variableList/varibleList_15.csv","/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/dataset/1tau1lvaribleList_15_weight/"}},
    // {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v4/variableList/varibleList_16.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v4/dataset/1tau1lvaribleList_16_weight/"}}, //testing with btag Shape training
    // {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v3/variableList/varibleList_15.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v3/dataset/1tau1lvaribleList_15_weight/"}}, //testing with btag WP training
    // {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/mc/tmvaTraining/btagWP/variableList_15.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/mc/tmvaTraining/btagWP/dataset/weight/"}},
    // {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/mc/tmvaTraining/btagShape/variableList_16.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/mc/tmvaTraining/btagShape/dataset/weight/"}},

    // {"2018", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v5extra1tau1lCut_v56NoHLTButPre/1tau1l_v0/variableList/varibleList_16.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v5extra1tau1lCut_v56NoHLTButPre/1tau1l_v0/dataset/1tau1lvaribleList_16_weight/"}},
    // {"2018", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/variableList/varibleList_15.csv","/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/dataset/1tau1lvaribleList_15_weight/"}},
    {"2022", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/variableList/varibleList_15.csv","/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/dataset/1tau1lvaribleList_15_weight/"}},
    {"2022postEE", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/variableList/varibleList_15.csv","/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/dataset/1tau1lvaribleList_15_weight/"}},
    {"2022preEE", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/variableList/varibleList_15.csv","/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/dataset/1tau1lvaribleList_15_weight/"}},
    //new training
    // {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1NewHLTSF1tau1lCut_v64PreAndHLTSel/mc/BDTTrain/dataset/weight/"}},
    {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/variableList/varibleList_15.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1NewHLTSF1tau1lCut_v64PreAndHLTSel/mc/BDTTrain/dataset/weight/"}},
    // {"2018", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/variableList/varibleList_15.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2cut1tau1l_v64PreAndHLTSel/mc/BDTTrain/dataset/weight/"}},
    {"2016", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v4forBDT1tau1lCut_v61fixesLepRemovalBug/1tau1l_v1/variableList/varibleList_15.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1NewHLTSF1tau1lCut_v64PreAndHLTSel/mc/BDTTrain/dataset/weight/"}},
    {"2018", {"/workfs2/cms/huahuil/4topCode/CMSSW_10_2_20_UL/src/FourTop/hua/tmva/newCode/inputList/inputList_noTauTT.csv","/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2cut1tau1l_v74AddMETPhi/mc/BDTTrain/v1_noTauTT/dataset/weight/"}},
};

inline const    std::map<TString, std::array<TString, 2>> FRfileMap = {
        {"2018", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v4baselineBtagRUpdated_v57ovelapWithTausF/mc/variableHists_v0FR_measureVR_1prong/results/fakeRateInPtEta_sumGenBG_newBin.root", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v4baselineBtagRUpdated_v57ovelapWithTausF/mc/variableHists_v0FR_measureVR_3prong/results/fakeRateInPtEta_sumGenBG_newBin.root"}},
        {"2016", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v4baselineBtagRUpdated_v57ovelapWithTausF/mc/variableHists_v0FR_measureVR_1prong/results/fakeRateInPtEta_sumGenBG_newBin.root", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v4baselineBtagRUpdated_v57ovelapWithTausF/mc/variableHists_v0FR_measureVR_3prong/results/fakeRateInPtEta_sumGenBG_newBin.root"}},
        {"2017", {"/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baseline_v57ovelapWithTausF/mc/variableHists_v0FR_measureVR_1prong/results/fakeRateInPtEta_sumGenBG_newBin.root", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baseline_v57ovelapWithTausF/mc/variableHists_v0FR_measureVR_3prong/results/fakeRateInPtEta_sumGenBG_newBin.root"}},
};

inline const std::map<TString, std::array<TString, 2>> BDT1tau0l = {
    // {"2018", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau0l_final26.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2cut1tau0lSRTauF_v79HadroPresel/mc/BDTTrain/v1final26Var/inputList_1tau0l_final26.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}},
    // {"2017", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau0l_final26.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2cut1tau0lSRTauF_v76WithVLLAllMass/mc/BDTTrain/v1final26Var/inputList_1tau0l_final26.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}},
    // {"2016preVFP", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau0l_final26.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2cut1tau0lSRTauF_v76WithVLLAllMass/mc/BDTTrain/v1final26Var/inputList_1tau0l_final26.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}},
    // {"2016postVFP", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau0l_final26.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2cut1tau0lSRTauF_v76WithVLLAllMass/mc/BDTTrain/v1final26Var/inputList_1tau0l_final26.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}},
    // {"2017", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau0l_NoMET.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2cut1tau0lSRTauF_v79HadroPresel/mc/BDTTrain/v2NoMET/inputList_1tau0l_NoMET.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}}, //!testing
    // {"2017", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau0l_noTauF.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2cut1tau0lSRTauF_v79HadroPresel/mc/BDTTrain/v3NoTauF/inputList_1tau0l_noTauF.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}}, //!testing
    // {"2017", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau0l_finalFinal26.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2cut1tau0lSRTauF_v80addTauJetVar/mc/BDTTrain/v4finalFinal26Var/inputList_1tau0l_finalFinal26.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}}, //!testing
    // {"2017", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_finalFinal25.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2cut1tau0lSRTauF_v80addTauJetVar/mc/BDTTrain/v5finalFinal25Var/inputList_finalFinal25.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}}, //!testing
    {"2018", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_finalFinal25.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2cut1tau0lSRTauF_v80addTauJetVar/mc/BDTTrain/v5finalFinal25Var/inputList_finalFinal25.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}}, 
    {"2017", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_finalFinal25.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2cut1tau0lSRTauF_v80addTauJetVar/mc/BDTTrain/v5finalFinal25Var/inputList_finalFinal25.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}}, 
    {"2016preVFP", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_finalFinal25.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2cut1tau0lSRTauF_v80addTauJetVar/mc/BDTTrain/v5finalFinal25Var/inputList_finalFinal25.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}}, 
    {"2016postVFP", {"/workfs2/cms/huahuil/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_finalFinal25.csv", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2cut1tau0lSRTauF_v80addTauJetVar/mc/BDTTrain/v5finalFinal25Var/inputList_finalFinal25.csv/dataset/weight/TMVAClassification_BDT.weights.xml"}}, 
};


};
#endif