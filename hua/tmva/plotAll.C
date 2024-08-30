#include "variables.C"
// #include "correlations.C"
#include "efficiencies.C"
#include "mvas.C"
// #include "mutransform.C"
#include "correlations_less20Inputs.C"
#include "significance_usingPDF.C"

void plotAll(
    // TString fin = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v3cut1tau1lSR6thJetpt34_v75OverlapRemovalFTau/mc/BDTTrain/v1withBtag/inputList_1tau1l_btag.csv.root",
    // TString outDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v3cut1tau1lSR6thJetpt34_v75OverlapRemovalFTau/mc/BDTTrain/v1withBtag/results/",
    // TString fin = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v3cut1tau1lSR6thJetpt34_v75OverlapRemovalFTau/mc/BDTTrain/v0/inputList_1tau1l.csv.root",
    // TString outDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v3cut1tau1lSR6thJetpt34_v75OverlapRemovalFTau/mc/BDTTrain/v0/results/",
    // TString fin = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v3cut1tau1lSR6thJetpt34_v75OverlapRemovalFTau/mc/BDTTrain/v3TrainingB/inputList_1tau1l.csv.root",
    // TString outDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v3cut1tau1lSR6thJetpt34_v75OverlapRemovalFTau/mc/BDTTrain/v3TrainingB/results/",
    // TString fin = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1cut1tau1lSR_v76WithVLLSample/mc/BDTTrain/v0allVar/inputList_1tau1l.csv.root",
    // TString fin = "/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v2allVar/inputList_1tau1l_btag.csv.root",
    TString fin = "/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_Official_1tau1l_M600_25var.csv.root",
    TString outDir = "/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/resultsv1M600/",
    Bool_t plotSigOnly = false
)
{
  cout << "=== execute: variables()" << endl;
  cout << "\n";

  if (plotSigOnly == false)
  {
    cout << "=== execute: correlations()" << endl;
    correlations_less20Inputs(fin);
  cout<<"\n";

    cout << "=== execute: mvas()" << endl;
  cout<<"\n";
    mvas(fin);
  }

  cout << "=== execute: significance_usingPDF()" << endl;
  significance_usingPDF(fin);
  cout<<"\n";

  cout << "=== execute: efficiencies()" << endl;
  efficiencies(fin, outDir);
  cout<<"\n";
}
