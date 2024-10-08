
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <vector>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TCut.h"
#include <TObjArray.h>

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"
#include "TMVA/Config.h"
#include <TMVA/HyperParameterOptimisation.h>
#include <TMVA/ROCCurve.h>

#include "processClass.h"
#include "../../../myLibrary/commenFunction.h"

void getProcessesVec(TString inputDir, std::vector<Process>& processVec, const TString channel = "1tau2l", const TString ifVLL=kFALSE)
{
    // TString signal = ifVLL ? "VLLm600" : "tttt";
    std::vector<TString> allProcesses = {
        "VLL_EE_M600",
        "VLL_EN_M600",
        "VLL_NN_M600",
        // "VLL_EE_M600",
        // "VLL_EN_M600",
        // "VLL_NN_M600",
        // "VLL_EE_M800",
        // "VLL_EN_M800",
        // "VLL_NN_M800",
        // "VLL_EE_M700",
        // "VLL_EN_M700",
        // "VLL_NN_M700",
    "tttt",
    "ttbar_0l",
    "ttbar_2l",
    "ttbar_1l",
    "ttG",
    "ttZ",  
    "ttW",
    "ttH_bb", 
    "ttH_nonbb", 

    "st_tZq",
    "st_tW_antitop",
    "st_tW_top",

    "WJetsToLNu_HT-200To400",
    "WJetsToLNu_HT-400To600",
    "WJetsToLNu_HT-600To800",
    "WJetsToLNu_HT-800To1200",
    "WJetsToLNu_HT-1200To2500",
    "WJetsToLNu_HT-2500ToInf",

    // "fakeTau_tauF",
    // "fakeTau_tauT",
    // "fakeTau_tauFGen",
    // "fakeTau_tauTGen",

    };

    // if(!ifVLL.IsNull()){
    //     allProcesses.push_back(ifVLL);
    // }

    processVec.clear();
    for(UInt_t i=0; i<allProcesses.size(); i++){
    // for(UInt_t i=0; i<allProcesses.at(channel).size(); i++){
        TString ifile = inputDir+allProcesses.at(i)+".root";
        // if(channel=="1tau0l"){
        //     if(!allProcesses.at(i).Contains("fakeTau")){
        //         ifile = inputDir+allProcesses.at(i)+"_tauGen.root";//!important
        //     }
        // }else{
        //     if(allProcesses.at(i).Contains("fakeTau")){
        //         continue;
        //     }
        // }

        Process iPro{ifile};
        processVec.push_back(iPro);
    }

}


int tmvaBDT_training(
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v2cut1tau1l_v64PreAndHLTSel/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v4cut1tau2l_v76For1tau2l/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v5cut1tau1lSR_v75OverlapRemovalFTau/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v3cut1tau1lSR6thJetpt34_v75OverlapRemovalFTau/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1cut1tau1lSR_v76WithVLLSample/mc/",
    // TString inputDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1cut1tau1lSR_v76WithVLLAllMass/mc/",
    TString inputDir = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAOD/forMVA/2018/v2baselineHardro_FRweightSys_v76WithVLLAllMass/mc/",
    TString outDir = "output/",
    Bool_t isTest = false,
    // TString variableListCsv = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v8tau1elCut_v60fixeJetBtagBug/1tau1l_v1/variableList/varibleList_16.csv",
    // TString variableListCsv = "/workfs2/cms/huahuil/4topCode/CMSSW_10_2_20_UL/src/FourTop/plotting/branch_names.csv",
    // TString variableListCsv = "/workfs2/cms/huahuil/4topCode/CMSSW_10_2_20_UL/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau0l.csv",
    // TString variableListCsv = "/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau0l.csv",
    // TString variableListCsv = "/workfs2/cms/huahuil/4topCode/CMSSW_10_2_20_UL/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau2l.csv",
    TString variableListCsv = "/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/inputList/inputList_1tau1l_M600_26var.csv",
// const TCut g_weight = "EVENT_genWeight *EVENT_prefireWeight *PUweight_*HLT_weight*tauT_IDSF_weight_new*elesTopMVAT_weight * musTopMVAT_weight * btagShape_weight * btagShapeR ";
    const TString g_weight = "global_weight*EVENT_genWeight *EVENT_prefireWeight *PUweight_*HLT_weight*tauT_IDSF_weight_new*elesTopMVAT_weight * musTopMVAT_weight * btagWPMedium_weight ", //for btag WP
    // const TString g_weight = "global_weight*EVENT_genWeight *EVENT_prefireWeight *PUweight_*tauT_IDSF_weight_new*elesTopMVAT_weight*musTopMVAT_weight*btagWPMedium_weight ",
    // const TString g_weight = "event_allWeight_1tau0l", //1tau0l
    // const TString channel = "1tau2l"
    const TString channel = "1tau1l",
    // const TString channel = "1tau0l",
    // const Bool_t ifVLL=kTRUE
    const TString ifVLL = ""
    ) //for btag WP
{
    std::cout<<"event weight="<<g_weight<<"\n";
    std::cout << "inputDir=" << inputDir << "\n";
    std::cout<<"channel="<<channel<<" ifVLL="<<ifVLL<<"\n\n";

    TObjArray *tokens = variableListCsv.Tokenize("/");
    TString csvListName = ((TObjString *)tokens->Last())->GetString();
    tokens->Delete();
    std::cout << "csvName=" << csvListName << "\n";

    TString outfileName = outDir + csvListName + ".root";
    TFile *outputFile = TFile::Open(outfileName, "RECREATE");

    //TMVA::Factory *factory = new TMVA::Factory("TMVAClassification", outputFile, "!V:!Silent:Color:DrawProgressBar:Transformations=I:AnalysisType=Classification");
    TMVA::DataLoader *dataloader = new TMVA::DataLoader("dataset");
    TMVA::Tools::Instance();
    // (TMVA::gConfig().GetVariablePlotting()).fNbins1D = 30;
    // TMVA::gConfig().GetVariablePlotting().fNbinsMVAoutput = 30;
    (TMVA::gConfig().GetIONames()).fWeightFileDir =  "weight/";
    // TMVA::gConfig().GetIONames().fWeightFileDirPrefix = outDir; // If a non-nul prefix is set in TMVA::gConfig().GetIONames().fWeightFileDirPrefix the weights will be stored in weightfile_prefix/dataset_name/weight_file_name
    TMVA::gConfig().GetIONames().fWeightFileDirPrefix = outDir+ csvListName; // If a non-nul prefix is set in TMVA::gConfig().GetIONames().fWeightFileDirPrefix the weights will be stored in weightfile_prefix/dataset_name/weight_file_name

    // read input variables from csv
    std::vector<TString> variableList;
    TTTT::getVarFromFile(variableListCsv, variableList);
    for (UInt_t i = 0; i < variableList.size(); i++)
    {
        TString ivar = variableList.at(i);
        std::cout << "adding input variable: " << ivar << "\n";
        if (ivar.Contains("num") || ivar.Contains("charge"))
        {
            dataloader->AddVariable(variableList.at(i), 'I');
        }
        else
        {
            dataloader->AddVariable(variableList.at(i), 'F');
        }
    }

    // add signal and bg trees
    Long64_t allBg = 2000;
    Long64_t allSignal = 2000;
    std::vector<Process> processVec;
    getProcessesVec(inputDir, processVec, channel, ifVLL);
    for (UInt_t i=0;i<processVec.size(); i++){
        if(processVec.at(i).getTree()->GetEntries()<=0) continue;
        // if(processVec.at(i).isbg(!ifVLL.IsNull())){
        if(i>=3){
            std::cout << "bg tree: " << processVec.at(i).getName() << "\n";
            dataloader->AddBackgroundTree(processVec.at(i).getTree());
            if(!isTest){
                allBg = allBg + processVec.at(i).getTree()->GetEntries();
            }
        }
        else{
            std::cout << "signal tree: " << processVec.at(i).getName() << "\n";
            dataloader->AddSignalTree(processVec.at(i).getTree()); //!use global_weight
            if(!isTest){
                allSignal = allSignal + processVec.at(i).getTree()->GetEntries();
            }
        }
    }
    std::cout << "signal and bg tree added \n";


    dataloader->SetSignalWeightExpression(g_weight);
    dataloader->SetBackgroundWeightExpression(g_weight);
    std::cout << "allSignal=" << allSignal << "  allBg=" << allBg << "\n";

    // std::string trainingSetup = "nTrain_Signal=" + std::to_string(allSignal * 0.6) + ":nTrain_Background=" + std::to_string(allBg * 0.6) + ":nTest_Signal=0:nTest_Background=0:SplitMode=Random:NormMode=EqualNumEvents:!V";
    std::string trainingSetup = "nTrain_Signal=" + std::to_string(allSignal * 0.6) + ":nTrain_Background=" + std::to_string(allBg * 0.6) + ":nTest_Signal=" + std::to_string(allSignal * 0.4)+":nTest_Background=" + std::to_string(allBg * 0.4) + ":SplitMode=Random:NormMode=EqualNumEvents:!V";

    std::cout << trainingSetup << "\n";
    dataloader->PrepareTrainingAndTestTree("", "", trainingSetup); // 60% goes to training, 1tau1l

    //factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDT",
    //                        // "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20");
    //                        // "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=30");
    //                        // "!H:!V:NTrees=850:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20");//trainA: increase MinNodeSize
    //                        "!H:!V:NTrees=1000:MinNodeSize=5%:MaxDepth=4:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=30:Shrinkage=0.1");//trainB: increase MinNodeSize
    
    // BDT Hyperparameter tuning
    std::vector<int> nTrees = {500, 750, 1000};
    std::vector<std::string> minNodeSize = {"2.5%", "5.0%", "7.5%"};
    std::vector<int> maxDepth = {3, 4, 5};
    std::vector<int> nCuts = {20, 30, 40};

    double bestROC = -1;
    TString bestParams;

    for (int nt : nTrees) {
        for (const std::string &mns : minNodeSize) {
            for (int md : maxDepth) {
                for (int nc : nCuts) {
                    TMVA::Factory *factory = new TMVA::Factory("TMVAClassification", outputFile, "!V:!Silent:Color:DrawProgressBar:Transformations=I:AnalysisType=Classification");
                    TString methodName = Form("BDT_%d_%s_%d_%d", nt, mns.c_str(), md, nc);
                    TString params = Form("NTrees=%d:MinNodeSize=%s:MaxDepth=%d:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=%d", nt, mns.c_str(), md, nc);
                    factory->BookMethod(dataloader, TMVA::Types::kBDT, methodName, params);

                    factory->TrainAllMethods();
                    factory->TestAllMethods();
                    factory->EvaluateAllMethods();

                    // Save the output and close the file
                    outputFile->Write();
                    outputFile->Close();

                    // Reopen the file to read the ROC curve
                    TFile *rocFile = TFile::Open(outfileName);
                    if (!rocFile || rocFile->IsZombie()) {
                        std::cerr << "Error opening ROC file: " << outfileName << std::endl;
                        return 1;
                    }

                    // Print the contents of the file for debugging
                    rocFile->ls();

                    // Get the ROC curve
                    TString rocPath = Form("dataset/Method_BDT/%s/MVA_%s_rejBvsS", methodName.Data(), methodName.Data());
                    TObject *obj = rocFile->Get(rocPath);
                    if (!obj) {
                        std::cerr << "Path does not exist: " << rocPath << std::endl;
                        rocFile->Close();
                        return 1;
                    }
                    TH1 *rocHist = dynamic_cast<TH1*>(obj);
                    if (!rocHist) {
                        std::cerr << "Error getting ROC graph at path: " << rocPath << std::endl;
                        rocFile->Close();
                        return 1;
                    }

                    // Calculate AUC from TGraph
                    double roc = 0.0;
                    int nBins = rocHist->GetNbinsX();
                    for (int i = 1; i <= nBins; ++i) {
                        double binWidth = rocHist->GetBinWidth(i);
                        double binContent = rocHist->GetBinContent(i);
                        roc += binContent * binWidth;
                    }
                    rocFile->Close();
                    std::cout << roc << std::endl;
                    if (roc > bestROC) {
                        bestROC = roc;
                        bestParams = params;
                    }
                    outputFile = TFile::Open(outfileName, "update");
                    SafeDelete(factory);
                }
            }
        }
    }

    std::cout << "Best BDT Parameters: " << bestParams << std::endl;
    TMVA::Factory *factory = new TMVA::Factory("TMVAClassification", outputFile, "!V:!Silent:Color:DrawProgressBar:Transformations=I:AnalysisType=Classification");
    factory->BookMethod(dataloader, TMVA::Types::kBDT, "BDT", bestParams);

    // if (Use["BDTB"]) // Bagging
    //   factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTB",
                        //    "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=20" );//default
                        //    "!H:!V:NTrees=400:BoostType=Bagging:SeparationType=GiniIndex:nCuts=30" );
 
//    if (Use["BDTD"]) // Decorrelation + Adaptive Boost
    //   factory->BookMethod( dataloader, TMVA::Types::kBDT, "BDTD",
                        //    "!H:!V:NTrees=400:MinNodeSize=5%:MaxDepth=3:BoostType=AdaBoost:SeparationType=GiniIndex:nCuts=20:VarTransform=Decorrelate" );//?strange running time bug

    //!DNN not working yet
      // General layout.
    //   TString layoutString ("Layout=TANH|128,TANH|128,TANH|128,LINEAR");
    //   // Define Training strategy. One could define multiple strategy string separated by the "|" delimiter
    //   TString trainingStrategyString = ("TrainingStrategy=LearningRate=1e-2,Momentum=0.9,"
    //                                     "ConvergenceSteps=20,BatchSize=100,TestRepetitions=1,"
    //                                     "WeightDecay=1e-4,Regularization=None,"
    //                                     "DropConfig=0.0+0.5+0.5+0.5");
    //   // General Options.
    //   TString dnnOptions ("!H:V:ErrorStrategy=CROSSENTROPY:VarTransform=N:"
    //                       "WeightInitialization=XAVIERUNIFORM");
    //   dnnOptions.Append (":"); dnnOptions.Append (layoutString);
    //   dnnOptions.Append (":"); dnnOptions.Append (trainingStrategyString);
    //    // Multi-core CPU implementation.
    // TString cpuOptions = dnnOptions + ":Architecture=CPU";
    // factory->BookMethod(dataloader, TMVA::Types::kDL, "DNN_CPU", cpuOptions);



    factory->TrainAllMethods();
    // Evaluate all MVAs using the set of test events
    factory->TestAllMethods();
    // Evaluate and compare performance of all configured MVAs
    factory->EvaluateAllMethods();
    // Save the output
    outputFile->Write();
    outputFile->Close();
    std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
    std::cout << "==> TMVAClassification is done!" << std::endl;

    delete factory;
    delete dataloader;

    return 0;
}

int main(int argc, char const *argv[])
{
    TString inputDir, outDir, variableList;
    TString weight;
    Bool_t isTest;
    if (argc < 3)
    {
        std::cout<<"not enough input\n";
        tmvaBDT_training();
    }
    else
    {
        inputDir = boost::lexical_cast<std::string>(argv[1]) ;
        outDir = boost::lexical_cast<std::string>(argv[2]);
        isTest = boost::lexical_cast<Bool_t>(argv[3]);
        variableList = boost::lexical_cast<std::string>(argv[4]);
        weight = boost::lexical_cast<std::string>(argv[5]);
        // tmvaBDT_training(inputDir, outDir, variableList, weight, isTest);
        tmvaBDT_training(inputDir, outDir, isTest, variableList, weight);
    }
}