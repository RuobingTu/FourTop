#ifndef INPUTMAP_MV_H
#define INPUTMAP_MV_H

namespace MV{


// top lepton mva
inline const std::map<TString, std::array<TString, 2>> topLeptonSF_files = {
    {"2016preVFP", {"./input/topMVASF/ele/2016APV/egammaEffi.txt_EGM2D.root", "./input/topMVASF/mu/2016HIPM/NUM_LeptonMvaMedium_DEN_TrackerMuons_abseta_pt.root"}},
    {"2016postVFP", {"./input/topMVASF/ele/2016/egammaEffi.txt_EGM2D.root", "./input/topMVASF/mu/2016/NUM_LeptonMvaMedium_DEN_TrackerMuons_abseta_pt.root"}},
    {"2017", {"./input/topMVASF/ele/2017/egammaEffi.txt_EGM2D.root", "./input/topMVASF/mu/2017/NUM_LeptonMvaMedium_DEN_TrackerMuons_abseta_pt.root"}},
    {"2018", {"./input/topMVASF/ele/2018/egammaEffi.txt_EGM2D.root", "./input/topMVASF/mu/2018/NUM_LeptonMvaMedium_DEN_TrackerMuons_abseta_pt.root"}},
};


inline const std::map<TString, TString> triggerSF_map = {
    // {"2016preVFP", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3baslineNoHLTMuonTriggerAdded_v52noHLTButPreSelection/mc/variableHists_v8add2DHist/results/baseline1Muon1b_triggerSF.root"},
    // {"2016postVFP", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3baslineNoHLTMuonTriggerAdded_v52noHLTButPreSelection/mc/variableHists_v8add2DHist/results/baseline1Muon1b_triggerSF.root"},
    // {"2017", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3baslineNoHLTMuonTriggerAdded_v52noHLTButPreSelection/mc/variableHists_v8add2DHist/results/baseline1Muon1b_triggerSF.root"}, // to be updated!!!
    // {"2018", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2baslineNoHLT_v54noHLTButPre/mc/variableHists_v0triggerEff/results/baseline1Muon1b_triggerSF.root"},
    // {"2016preVFP", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v2baslineNoHLT_v55ojectRemovalwithTightNoHLT/mc/variableHists_v1triigerEff_btagShapeWeight/results/baseline1Muon1b_triggerSF.root"},
    // {"2016postVFP", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v2baslineNoHLT_v55ojectRemovalwithTightNoHLT/mc/variableHists_v1triigerEff_btagShapeWeight/results/baseline1Muon1b_triggerSF.root"},
    {"2016preVFP", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v2baslineNoHLT_v57ovelapWithTausF/mc/variableHists_v0_HLTSFMeasure/results/baseline1Muon1b_triggerSF.root"},
    {"2016postVFP", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v2baslineNoHLT_v57ovelapWithTausF/mc/variableHists_v0_HLTSFMeasure/results/baseline1Muon1b_triggerSF.root"},
    // {"2017", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2baslineNoHLTBugFixed_v56NoHLTButPre/mc/variableHists_v1triigerEff_btagShapeWeight/results/baseline1Muon1b_triggerSF.root"},
    // {"2017", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2baslineNoHLTBugFixed_v56NoHLTButPre/mc/variableHists_v0_triggerSFNewRange/results/baseline1Muon1b_triggerSF.root"},
    {"2017", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2baslineNoHLT_v57ovelapWithTausF/mc/variableHists_v0_HLTSFMeasure/results/baseline1Muon1b_triggerSF.root"},
    {"2018", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v2baslineNoHLT_v57ovelapWithTausF/mc/variableHists_v0_HLTSFMeasure/results/baseline1Muon1b_triggerSF.root"},
};

inline const std::map<TString, std::array<TString, 3>> json_map = {
    {"2016preVFP", {"JME/2016preVFP_UL/jet_jerc.json", "TAU/2016preVFP_UL/tau.json", "BTV/2016preVFP_UL/btagging.json"}},
    {"2016postVFP", {"JME/2016postVFP_UL/jet_jerc.json", "TAU/2016postVFP_UL/tau.json", "BTV/2016postVFP_UL/btagging.json"}},
    {"2017", {"JME/2017_UL/jet_jerc.json", "TAU/2017_UL/tau.json", "BTV/2017_UL/btagging.json"}},
    {"2018", {"JME/2018_UL/jet_jerc.json", "TAU/2018_UL/tau.json", "BTV/2018_UL/btagging.json"}},
};

inline const std::map<TString, TString> btagR_map = {
    // {"2016", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3HLTWeightUpdated_v55ojectRemovalwithTightNoHLT/mc/variableHists_v0btagRCal/results/btagR.root"},
    // {"2016postVFP", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3HLTWeightUpdated_v55ojectRemovalwithTightNoHLT/mc/variableHists_v0btagRCal/results/btagR.root"},
    // {"2016preVFP", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3HLTWeightUpdated_v55ojectRemovalwithTightNoHLT/mc/variableHists_v0btagRCal/results/btagR.root"},
    // {"2017", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v3HLTWeightUpdatedBugFixed_v56NoHLTButPre/mc/variableHists_v6_btagRMeasure/results/1tau0lNoBbtagR.root"},
    // {"2018", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v3HLTWeightUpdatedBugFixed_v56NoHLTButPre/mc/variableHists_v6_btagRMeasure/results/1tau0lNoBbtagR.root"}, //!!! to be updated!!!
    {"2016", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3baselineNoBCutHLTWeightUpdated_v57ovelapWithTausF/mc/variableHists_v1_btagRMeasure/results/1tauNoBbtagR.root"},
    {"2016postVFP", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3baselineNoBCutHLTWeightUpdated_v57ovelapWithTausF/mc/variableHists_v1_btagRMeasure/results/1tauNoBbtagR.root"},
    {"2016preVFP", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3baselineNoBCutHLTWeightUpdated_v57ovelapWithTausF/mc/variableHists_v1_btagRMeasure/results/1tauNoBbtagR.root"},
    {"2017", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v3baselineNoBCutHLTWeightUpdated_v57ovelapWithTausF/mc/variableHists_v1_btagRMeasure/results/1tauNoBbtagR.root"},
    {"2018", "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v3baselineNoBCutHLTWeightUpdated_v57ovelapWithTausF/mc/variableHists_v1_btagRMeasure/results/1tauNoBbtagR.root"},
};



};
#endif