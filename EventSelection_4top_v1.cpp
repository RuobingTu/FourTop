#include "EventSelection_4top_v1.h" 
#include "math.h"
#include <algorithm>

//void EventSelection_4top_v1(const char * Input = ""){
//void EventSelection_4top_v1(const bool istest = true, const string input = "TauOfTTTT_Toptagger_oldEID.root", const string outputDir = "/publicfs/cms/user/huahuil/TauOfTTTT/2016v1/NewNtupleAfterEventSelection_test/"){
void EventSelection_4top_v1(const bool istest = true, const string input = "TTTT_TuneCUETP8M2T4_13TeV-amcatnlo-pythia8.root", const string outputDir = "/publicfs/cms/user/huahuil/TauOfTTTT/2016v1/NewNtupleAfterEventSelection_test/"){
  gStyle->SetCanvasColor(0);
  gStyle->SetFrameBorderMode(0);//?
  gStyle->SetOptStat("rme");
  gStyle->SetPalette(1,0);
  gStyle->SetTitleX(0.50);
  gStyle->SetTitleY(0.96);
  gStyle->SetPaintTextFormat(".2f");

  bool preselection = true;//associate with selection 
  bool sideband     = false;//associate with selection
//?what's sideband and signal ?
  bool signal       = false;
	//?signal occur nowhere else

	//what does these mean?
  //SYSTEMATICS: 0 is standard, 1 is UP, 2 is down
	//appear in 95
  int SysJes = 0;//jet enenrgy scale 
  int SysJer = 0;//jet  energy resolution 
  
  using namespace std;
  char openTree[500];   sprintf(openTree, "TNT/BOOM");//117 
  vector<string> fileName;
//  fileName.push_back("TTTT_TuneCUETP8M2T4_13TeV-amcatnlo-pythia8.root");   //17
  fileName.push_back(input);    
  for(unsigned int Nfiles=0; Nfiles<fileName.size(); Nfiles++){
//  for(unsigned int Nfiles=0; Nfiles<1; Nfiles++){
    string NewFileprov;
		//do these files already exist or not?what does the number 1 or 2 mean ?
		//file already exist, new file is what we want build.
		//?it seems Jes and Jer can not aplly together?
/*    if ((SysJes==0)&&(SysJer==0)) NewFileprov = "/publicfs/cms/user/huahuil/TauOfTTTT/2016v1/NewNtupleAfterEventSelection_test/NoJEC/test"+fileName[Nfiles];
    if ((SysJes==1)&&(SysJer==0)) NewFileprov = "/publicfs/cms/user/huahuil/TauOfTTTT/2016v1/NewNtupleAfterEventSelection_test/JESup/"+fileName[Nfiles];
    if ((SysJes==2)&&(SysJer==0)) NewFileprov = "/publicfs/cms/user/huahuil/TauOfTTTT/2016v1/NewNtupleAfterEventSelection_test/JESdo/"+fileName[Nfiles];
    if ((SysJes==0)&&(SysJer==1)) NewFileprov = "/publicfs/cms/user/huahuil/TauOfTTTT/2016v1/NewNtupleAfterEventSelection_test/JERup/"+fileName[Nfiles];
    if ((SysJes==0)&&(SysJer==2)) NewFileprov = "/publicfs/cms/user/huahuil/TauOfTTTT/2016v1/NewNtupleAfterEventSelection_test/JERdo/"+fileName[Nfiles];*/
    if ((SysJes==0)&&(SysJer==0)) NewFileprov = outputDir+"NoJEC/"+fileName[Nfiles];
    if ((SysJes==1)&&(SysJer==0)) NewFileprov = outputDir+"JESup/"+fileName[Nfiles];
    if ((SysJes==2)&&(SysJer==0)) NewFileprov = outputDir+"JESdo/"+fileName[Nfiles];
    if ((SysJes==0)&&(SysJer==1)) NewFileprov = outputDir+"JERdo/"+fileName[Nfiles];
    if ((SysJes==0)&&(SysJer==2)) NewFileprov = outputDir+"JERup/"+fileName[Nfiles];
    //const char *NewFileName = fileName[Nfiles].c_str();
    const char *NewFileName = NewFileprov.c_str();
//    cout<<"file here"<<NewFileName<<endl;
	//c_str()Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
//    TFile f(NewFileName,"new");//Create a new file and open it for writing, if the file already exists the file is not opened.
    TFile f(NewFileName,"RECREATE");//Create a new file, if the file already exists it will be overwritten.
    TTree *NewTree = new TTree("tree","tree");
    TTree *NewTreeSB = new TTree("treeSB","treeSB");
		//?why 2 trees? what's the different?
		//treeSB has something todo with sideband
   //guessing file already exist ?
	 //data and sample is data or MC? where do we get these files ?
    string FILEprov;
    // FILEprov = "/publicfs/cms/user/huahuil/TauOfTTTT/2016v1/data_and_sample/"+fileName[Nfiles];
    FILEprov = "/publicfs/cms/data/TopQuark/FourTop/v002/mc/2016/"+fileName[Nfiles];
    const char *FILE = FILEprov.c_str();
    TFile *file = TFile::Open(FILE);
    Tree = (TTree*)file->Get(openTree);



	//what do you mean get open tree from file ?	//in 26 openTree=
    bool data = true;
	//what does "may..." mean?   guess they are data file name.
//    if(fileName.size()==0) break;
    if(!(fileName[Nfiles].find("Tau_data")!=string::npos )) data = false;
	//find():The position of the first character of the first match.
	//If no matches were found, the function returns string::npos.
	//find May18V1_MET,data=true.
	//what is data?	//if filename is data, data=true. data and MC files have different tree .
 //   branch(data,NewTree,NewTreeSB,fileName[Nfiles]);//
		//Tree->SetBranchAddress;NewTree and SB->Branch
		//every file have the same tree ?yes
//    Int_t nentries = (Int_t)Tree->GetEntries();
    Long64_t nentries = (Int_t)Tree->GetEntries();
		//how do we know the entries of Tree?//Read all branches of entry and return total number of bytes read.
    for(int selection=0; selection<3; selection++){
			//? it seems when pre = false, sideband=true,both 1 and 2 will go in the loop.signal=false
      //selection = 0 -> preselection=true; line 19, true
      //selection = 1 -> signal selection; preselection=false and, not continue , that means go to the next line of the loop.
      //selection = 2 -> sideband=true and pre=false; line 14 sideband=false 
    	if(!((preselection  && selection==0) || (!preselection && sideband && (selection==1 || selection==2)) || (!preselection && !sideband && selection==1))) continue;
		//preselection=true ,sideband=false,in this case selection=0
			//?what does sideband and signal do?

//        TTree *NewTree = new TTree("tree","tree");
//        if(selection == 2) TTree *NewTreeSB = new TTree("treeSB","treeSB");
        branch(data,selection,NewTree,NewTreeSB,fileName[Nfiles]);//
        Long64_t NumOfEvents;
        if (istest){   NumOfEvents = 10000; }
        else{ NumOfEvents = nentries;}
//     for (Int_t i=0; i<nentries; i++) {
       for (Long64_t i=0; i<NumOfEvents; i++) {
			Long64_t tentry = Tree->LoadTree(i);//Set current entry.
			//?why file name not in the function?	//what does data do here?
			branchGetEntry(data, tentry,fileName[Nfiles]);// every branch in Tree, Getentry.  b_Jet_pt->GetEntry(tentry);//is a branch in tree, setadress.
			initializeVar();//line1822  initialize for new tree. category0=0;
			//
//			if(!(HLT_PFHT900_==1 || HLT_PFHT450_SixJet40_BTagCSV_p056_==1||HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_ ==1))  continue;//a branch in tree, trigger we choose
			//what are these Flag_branches?//?what choice should we make for our analysis?//?how many kinds of these filters are in MiniAOD//what is the ppossibility of there filter to out signal events?
			if(!(Flag_goodVertices_==1))  continue;//a branch in tree.
			if(!(Flag_globalSuperTightHalo2016Filter_==1))  continue;  
		    if(!(Flag_HBHENoiseFilter_==1))  continue;  
			if(!(Flag_HBHENoiseIsoFilter_==1))  continue;
			if(!(Flag_EcalDeadCellTriggerPrimitiveFilter_==1))  continue;  //a branch in Tree
		    if(!(Flag_BadPFMuonFilter_==1))  continue;  
//			if(!(Flag_ecalBadCalibReducedMINIAODFilter_==1))  continue;  
//			why this filter not work?//applied only in 2017 and 2018
			if(data) {if (!(Flag_eeBadScFilter_==1))  continue;}  

			if(!data) GenClassifier(GenZPt,GenWPt);//line2590
			//?according to pdg ID generate usdc quark and GenZPt GenWPt.

			//met
            //?need to check met
//			bool SelectedMet = false;
			//?how does SysJes impact Met_pt ?
            //?do we still have to correct Met?
			MetCorrection(SysJes,SysJer,Met_pt);//270 Met_pt in newtree branch.
            //?why have to do this MetCorrection
//            if( Met_pt > 200)  SelectedMet = true;//228;parameter in Fillbranches
            //we don't care about Met so much
			//SelectMet(SelectedMet);
			//Met_pt            = Met_type1PF_pt_;
			Met_phi           = Met_type1PF_phi_;//Met_phi branch in newtree and SB
//            cout<<__LINE__<<"  ";

			//Leptonic reject
            //
			vector<TLorentzVector> SelectedElectronsL; vector<int> SelectedElectronsLIndex;
			vector<TLorentzVector> SelectedElectronsM; vector<int> SelectedElectronsMIndex;
			vector<TLorentzVector> SelectedElectronsT; vector<int> SelectedElectronsTIndex;
			vector<TLorentzVector> SelectedElectronsVeto; vector<int> SelectedElectronsVetoIndex;
			SelectElectrons(SelectedElectronsL, SelectedElectronsLIndex, 0);//304
			SelectElectrons(SelectedElectronsM, SelectedElectronsMIndex, 1);//304
			SelectElectrons(SelectedElectronsT, SelectedElectronsTIndex, 2);
			SelectElectrons(SelectedElectronsVeto, SelectedElectronsVetoIndex, 3);//304

			vector<TLorentzVector> SelectedMuonsL;     vector<int> SelectedMuonsLIndex;
			vector<TLorentzVector> SelectedMuonsT;     vector<int> SelectedMuonsTIndex;
			SelectMuons(SelectedMuonsL, SelectedMuonsLIndex,0);
			SelectMuons(SelectedMuonsT, SelectedMuonsTIndex,2);
            NumSeEle          = SelectedElectronsL.size();
			NumSeMu           =  SelectedMuonsL.size();  
			NumSelLeps        = SelectedElectronsL.size()+SelectedMuonsL.size();//branch in newtree and SB
//            vector<TLorentzVector> LeptonsT = SelectedMuonsT + SelectedElectronsL;
//            v1.insert(v1.end(), v2.begin(), v2.end());
            vector<TLorentzVector> LeptonsT = SelectedMuonsT;
         //   vector<TLorentzVector> LeptonsTIndex = SelectedMuonsTIndex;
            LeptonsT.insert(LeptonsT.end(),SelectedElectronsT.begin(),SelectedElectronsT.end());
       //     LeptonsTIndex.insert(LeptonsTIndex.end(),SelectedElectronsTIndex.begin(),SelectedElectronsTIndex.end());
            NumOfLeptonsT = SelectedElectronsT.size()+SelectedMuonsT.size();
            NumOfLeptonsT_v2 = LeptonsT.size();
            NumOfMuonsT = SelectedMuonsT.size();
            NumOfElectronsT = SelectedElectronsT.size();
            vector<double> LeptonsTPtSorted; sort_jetPt(LeptonsT,LeptonsTPtSorted);
            if(NumOfLeptonsT_v2>0) LeadingLeptonPt = LeptonsTPtSorted[0];
            if(NumOfLeptonsT_v2>1) SecondLeptonPt = LeptonsTPtSorted[1];
            if(NumOfLeptonsT_v2>2) ThirdLeptonPt = LeptonsTPtSorted[2];


            //hadronic tau selection
            vector<TLorentzVector> SelectedTausL;
            vector<TLorentzVector> SelectedTausM;
            vector<TLorentzVector> SelectedTausT;
            SelectTaus(SelectedTausL,1);
            SelectTaus(SelectedTausM,2);
            SelectTaus(SelectedTausT,3);
            NumOfTausL = SelectedTausL.size();
            NumOfTausM = SelectedTausM.size();
            NumOfTausT = SelectedTausT.size();
            if(!(NumOfTausL>0)) continue;
            vector<double> TauPtSorted; sort_jetPt(SelectedTausL,TauPtSorted);
            if(NumOfTausL>0)  LeadingTauPt = TauPtSorted[0];
            if(NumOfTausL>1)  SecondTauPt = TauPtSorted[1];
//          

            //subchannel
            if(NumOfTausM==1 && NumOfLeptonsT_v2==0) channel_1Tau0L = 1;  
            if(NumOfTausM==1 && NumOfLeptonsT_v2==1) channel_1Tau1L = 1;
            if(NumOfTausM==1 && NumOfLeptonsT_v2==2){
                if(NumOfElectronsT==2){
                    if( patElectron_charge_->at(SelectedElectronsTIndex[0])*patElectron_charge_->at(SelectedElectronsTIndex[1]) == -1)  channel_1Tau2OS = 1;
                }
                if(NumOfElectronsT==1){
                    if( patElectron_charge_->at(SelectedElectronsTIndex[0])*Muon_charge_->at(SelectedMuonsTIndex[0]) == -1)  channel_1Tau2OS = 1;
                }
                if(NumOfElectronsT==0){
                    if( Muon_charge_->at(SelectedMuonsTIndex[1])*Muon_charge_->at(SelectedMuonsTIndex[0]) == -1)  channel_1Tau2OS = 1;
                }
            }
            if(NumOfTausM==1 && NumOfLeptonsT_v2==2){
                if(NumOfElectronsT==2){
                    if( patElectron_charge_->at(SelectedElectronsTIndex[0])*patElectron_charge_->at(SelectedElectronsTIndex[1]) == 1)  channel_1Tau2SS = 1;
                }
                if(NumOfElectronsT==1){
                    if( patElectron_charge_->at(SelectedElectronsTIndex[0])*Muon_charge_->at(SelectedMuonsTIndex[0]) == 1)  channel_1Tau2SS = 1;
                }
                if(NumOfElectronsT==0){
                    if( Muon_charge_->at(SelectedMuonsTIndex[1])*Muon_charge_->at(SelectedMuonsTIndex[0]) == 1)  channel_1Tau2SS = 1;
                }
            }
            if(NumOfTausM==1 && NumOfLeptonsT_v2==3) channel_1Tau3L = 1;
            if(NumOfTausM==2 && NumOfLeptonsT_v2==0) channel_2Tau0L = 1;
            if(NumOfTausM==2 && NumOfLeptonsT_v2==1) channel_2Tau1L = 1;
            if(NumOfTausM==2 && NumOfLeptonsT_v2==2) {
                if(NumOfElectronsT==2){
                    if( patElectron_charge_->at(SelectedElectronsTIndex[0])*patElectron_charge_->at(SelectedElectronsTIndex[1]) == -1)  channel_2Tau2OS = 1;
                    else channel_2Tau2SS = 1;
                }
                if(NumOfElectronsT==1){
                    if( patElectron_charge_->at(SelectedElectronsTIndex[0])*Muon_charge_->at(SelectedMuonsTIndex[0]) == -1)  channel_2Tau2OS = 1;
                    else channel_2Tau2SS = 1;
                }
                if(NumOfElectronsT==0){
                    if( Muon_charge_->at(SelectedMuonsTIndex[1])*Muon_charge_->at(SelectedMuonsTIndex[0]) == -1)  channel_2Tau2OS = 1;
                    else channel_2Tau2SS = 1;
                }
           } 
//           if(NumOfTausM==3 && NumOfLeptonsT_v2==3) channel_2Tau3L = 1;




            //jet and B jet selection
			vector<double> SeclectedJetsBTags;
			vector<double> SelectedBJetsMBTtags, SelectedBJetsLBTags, SelectedBJetsTBTags,SelectedForwardJetsBTags; /*{{{*/
//			vector<int>   CA8Indices;
			int CA8Index = -1;
            //?what does CA8Index do?
			//?not used in the macro
			bool deltaPhiJetMet=true;//used in SelectedJets
		   // vector<TLorentzVector> SelectedWJets;       SelectCA8Jets(0,SelectedWJets,  SelectedElectrons,SelectedMuons,CA8Indices, SysJes, SysJer, data, deltaPhiJetMet);   //if(!deltaPhiJetMet)  continue;
			//vector<TLorentzVector> SelectedTopJets;     SelectCA8Jets(1,SelectedTopJets,SelectedElectrons,SelectedMuons,CA8Indices, SysJes, SysJer, data, deltaPhiJetMet);   //if(!deltaPhiJetMet)  continue;
			//if (SelectedWJets.size()>0) continue;
			//if (SelectedTopJets.size()>0) continue;
			//330; return vector of SelectedJets and selectedJetsCSV//0,11,12 range for Jet_pfDeepCSVBJetTags is different
            bool deepJet = true;
			vector<TLorentzVector> SelectedJets;        SelectJets(0,deepJet,SelectedJets, SeclectedJetsBTags, SysJes, SysJer, deltaPhiJetMet);  //if(!deltaPhiJetMet)  continue;
			vector<TLorentzVector> SelectedBJetsL;    SelectJets(11,deepJet, SelectedBJetsL, SelectedBJetsLBTags, SysJes, SysJer, deltaPhiJetMet);  //if(!deltaPhiJetMet)  continue;
			vector<TLorentzVector> SelectedBJetsM;    SelectJets(12,deepJet, SelectedBJetsM, SelectedBJetsMBTtags, SysJes, SysJer, deltaPhiJetMet);  //if(!deltaPhiJetMet)  continue;
			vector<TLorentzVector> SelectedBJetsT;   SelectJets(13, deepJet, SelectedBJetsT, SelectedBJetsTBTags, SysJes, SysJer,  deltaPhiJetMet);  //if(!deltaPhiJetMet)  continue;
			vector<TLorentzVector> SelectedForwardJets; SelectJets(2,deepJet, SelectedForwardJets,SelectedForwardJetsBTags, SysJes, SysJer,deltaPhiJetMet);  //if(!deltaPhiJetMet)  continue;
			NumSelJets        = SelectedJets.size();
			NumSelForwardJets = SelectedForwardJets.size();//185
			NumSelBJetsL      = SelectedBJetsL.size();
			NumSelBJetsM      = SelectedBJetsM.size();//
			NumSelBJetsT      = SelectedBJetsT.size();
			MHT               = MHTcalculator(SelectedJets);//900;return the pt sum of,vetctor sum
			HT                = HTcalculator(SelectedJets);
			InvariantMassJets = InvariantMassCalculator(SelectedJets);
			Centrality        = InvariantMassJets/HT;
//			Aplanarity        = 
//			LeadingJetPt      = LeadingJetPtCal(SelectedJets);
//			MaxdeltaRJets     = deltaRJetsCal(SelectedJets);
//          Sphericity = 
            if(Met_pt== 0){ HTDividedByMET    = 0;}  else{HTDividedByMET    = HT/Met_pt;}
            MetDividedByHT = Met_pt/HT;
            MHTDividedByMET   = MHT/Met_pt;
            vector<double> JetsPtSorted; sort_jetPt(SelectedJets,JetsPtSorted);
            give_value_JetPtSorted(JetsPtSorted,LeadingJetPt,SecondJetPt, ThirdJetPt,FourthJetPt,FifthJetPt,SixthJetPt,SeventhJetPt,EighthJetPt,NighthJetPt,TenthJetPt );
            vector<double> BJetsPtSorted; sort_jetPt(SelectedBJetsM,BJetsPtSorted);
            give_value_JetPtSorted(BJetsPtSorted,LeadingBJetPt,SecondBJetPt, ThirdBJetPt,FourthBJetPt,FifthBJetPt,SixthBJetPt,SeventhBJetPt,EighthBJetPt,  NighthBJetPt,TenthBJetPt);
            vector<double> MinMaxDeltaRBJets; MinMaxdeltaRJetsCal(SelectedBJetsM, MinMaxDeltaRBJets);
            MinDeltaRBJets = MinMaxDeltaRBJets[0];
            MaxDeltaRBJets = MinMaxDeltaRBJets[1];
//            MinDeltaRBJets = MinMaxDeltaRBJets.at(0);
//            MaxDeltaRBJets = MinMaxDeltaRBJets.at(1);
            vector<double> MinMaxDeltaRJets;  MinMaxdeltaRJetsCal(SelectedJets, MinMaxDeltaRJets);
            MinDeltaRJets = MinMaxDeltaRJets[0];
            MaxDeltaRJets = MinMaxDeltaRJets[1];
//      	if(!(HT>200)) continue;/*}}}*/
            if(!(NumSelJets>0)) continue;
            if(!(NumSelBJetsL>0)) continue;
//
//
			//Hadronic Top selection
            //using resuts of SUSY toptagger here
            vector<TLorentzVector> SelectedTops;
            SelectTops(SelectedTops);
            NumofTops = SelectedTops.size();            
            vector<double> TopPtSorted; sort_jetPt(SelectedTops,TopPtSorted);
            if(NumofTops>0)  LeadingTopPt = TopPtSorted[0];
            if(NumofTops>1)  SecondTopPt = TopPtSorted[1];

 
            //only top that decay into 3 jets
/*			TLorentzVector Jet1Resolved;     Jet1Resolved.SetPtEtaPhiE(0, 0, 0, 0);
			TLorentzVector Jet2Resolved;     Jet2Resolved.SetPtEtaPhiE(0, 0, 0, 0);
			TLorentzVector Jet3Resolved;     Jet3Resolved.SetPtEtaPhiE(0, 0, 0, 0);
			TLorentzVector HadronicTopQuark;         HadronicTopQuark.SetPtEtaPhiE(0, 0, 0, 0);
			TLorentzVector HadronicTopQuarkResolved; HadronicTopQuarkResolved.SetPtEtaPhiE(0, 0, 0, 0);
			bool ResolvedEvent   = false;//parameter in function FillBranch
				//466; give Jet1,2,3,Toppt etc				//last 2 parameter are TopMassCut and btag
                //ResolvedRegionSelection need modification because it only have 1 top
//			if(selection==0) ResolvedRegionSelection(ResolvedEvent, SelectedJets, SeclectedJetsBTags, HadronicTopQuarkResolved, Jet1Resolved, Jet2Resolved, Jet3Resolved, false, false);
			if(selection==0) ResolvedRegionSelection(ResolvedEvent, SelectedJets, SeclectedJetsBTags, HadronicTopQuarkResolved, Jet1Resolved, Jet2Resolved, Jet3Resolved, true, true);
			if(selection==1) ResolvedRegionSelection(ResolvedEvent, SelectedJets, SeclectedJetsBTags, HadronicTopQuarkResolved, Jet1Resolved, Jet2Resolved, Jet3Resolved, false, true );
			if(selection==2) ResolvedRegionSelection(ResolvedEvent, SelectedJets, SeclectedJetsBTags, HadronicTopQuarkResolved, Jet1Resolved, Jet2Resolved, Jet3Resolved, false, false);
			if(ResolvedEvent)   HadronicTopQuark = HadronicTopQuarkResolved;//parameter in Fillbranch
            //HadronicTopQuark and HadronicTopQuarkResolved are identical
//			if(!ResolvedEvent) continue;
//			//?use funtion to give value, wouldn't it be useless?
		    WriteTopRelatedBranches(ResolvedEvent,HadronicTopQuark,SelectedMet,HadronicTopQuarkResolved,Jet1Resolved,Jet2Resolved,Jet3Resolved,SelectedForwardJets,SelectedBJetsM);
*/
            //event cut

			NVertices         = nBestVtx_;
			EVENT_run         = EVENT_run_;
			EVENT_event       = EVENT_event_;
			EVENT_lumiBlock   = EVENT_lumiBlock_;
			EVENT_genHT       = EVENT_genHT_;
			prefiringweight   = EVENT_prefireWeight_;
			prefiringweightup = EVENT_prefireWeightUp_;
			prefiringweightdown = EVENT_prefireWeightDown_;

	        	
			//categorization
            //?need modification because we do not care about ResolvdEvent and Met that much to categorize event according to them.
/*			if(selection==0){ //PRESELECTION
				if(ResolvedEvent  && SelectedMet)  category0=1; //branch in NewTree and SB 
			}
			else if(selection==1){ //SELECTION
				if(ResolvedEvent && NumSelBJetsM>0 && SelectedMet)     category0=1; 
	      	}    */
			//then what does category1,2 do?
//      	if(!(category0==1)) continue;// this is for calculating the events have passed certain critiaria
			 
				//WEIGHT
//			if(!data){
//					get_weight_btag(selection,w_Btag, w_BtagUp, w_BtagDown,w_Btag1Up, w_Btag1Down,w_Btag2Up, w_Btag2Down,w_BtagLoose, w_BtagLooseUp, w_BtagLooseDown, fileName[Nfiles]);//606 w_Btagall in NewTree
//					newPUWeight(PUWeight, PUWeightUP, PUWeightDOWN);//2729PUWeigh is a branch in Tree and newTree,PU and UP and DOWN are in New
//					GenWeight(fileName[Nfiles], GenZPt, GenWPt);2681
//					HTSF(fileName[Nfiles],HT,Met_pt,w_ZToNuNu,w_ZToNuNuUp,w_ZToNuNuDown,w_WToLNu,w_WToLNuUp,w_WToLNuDown,w_ttbar,w_ttbarUp,w_ttbarDown);//778
//					TriggerSF(Met_pt, MHT, w_Trig, w_TrigUp, w_TrigDown );
//  	  			QCDWeight(0,8,w_QCDUp,w_QCDDown);//240
//					PDFWeight(10,111,w_PDFUp,w_PDFDown);
//			}
	//it seems we don't fill NewTree here.	
//			if(selection==0 || selection==1) HistoFill(PUWeight,NewTree);
			if(selection==0 || selection==1)  NewTree->Fill();
			else if(selection==2)            HistoFill(PUWeight,NewTreeSB);
		}
	}

    f.cd();
//    writeFile(NewTree,NewTreeSB);//
    NewTree->Write();
    f.Close();
    cout<<"File "<<fileName[Nfiles]<<" ready!"<<endl;
  }
}









void QCDWeight(int imin,int imax,double &w_QCDUp ,double &w_QCDDown){/*{{{*/
     TH1F *RMS = new TH1F("", "", 100,-0.5,0.5);
     for(int i=imin; i<imax; i++){
        if(i==5) continue;
        if(i==7) continue;
        int I = 0;
        I=i;
        double ratio = (*genWeights_)[I]/(*genWeights_)[0];
        RMS->Fill(ratio-1);
     }
     w_QCDUp = 1+RMS->GetRMS();
     w_QCDDown = TMath::Max(0.,(1 - RMS->GetRMS()));
     delete RMS;
}/*}}}*/

void PDFWeight(int imin,int imax,double &w_PDFUp ,double &w_PDFDown){/*{{{*/
     TH1F *RMS = new TH1F("", "", 100,-0.5,0.5);
     for(int i=imin; i<imax; i++){
        int I = 0;
        if(i==10) I=0;
        else       I=i;
        double ratio = (*genWeights_)[I]/(*genWeights_)[0];
        RMS->Fill(ratio-1);
     }
     w_PDFUp = 1+RMS->GetRMS();
     w_PDFDown = TMath::Max(0.,(1 - RMS->GetRMS()));
     delete RMS;
}/*}}}*/
//?why do this?
void MetCorrection(int SysJes, int SysJer, double &MET){/*{{{*/
     double METx = Met_type1PF_pt_*TMath::Cos(Met_type1PF_phi_);//in tree branch.
     double METy = Met_type1PF_pt_*TMath::Sin(Met_type1PF_phi_);
     for (UInt_t j = 0; j < Jet_pt_->size(); ++j){ 
	     if(!(Jet_Uncorr_pt_->at(j)>15)) continue;
			 //?Jet_Uncorr_pt in Tbrowser seems not a string ?
	     double jetpt = 0.;
			 ///?what does Jes Jer mean?
			 //?the difference of Jet_pt and Jet_Uncorr_pt?
	     if(SysJes==0 && SysJer==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j) *Jet_JerSF_->at(j) ;}
	     if(SysJes==1 && SysJer==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSFup_->at(j) *Jet_JerSF_->at(j) ;}
	     if(SysJes==2 && SysJer==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSFdown_->at(j)*Jet_JerSF_->at(j) ;}
	     if(SysJes==0 && SysJer==1){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j) *Jet_JerSFup_->at(j) ;}
	     if(SysJes==0 && SysJer==2){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j) *Jet_JerSFdown_->at(j);}
	     METx = METx + Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)*TMath::Cos(Jet_phi_->at(j)) - jetpt*TMath::Cos(Jet_phi_->at(j));
	     METy = METy + Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)*TMath::Sin(Jet_phi_->at(j)) - jetpt*TMath::Sin(Jet_phi_->at(j));
		 //??
     }
     MET = sqrt(METx*METx + METy*METy);
}/*}}}*/

/*void SelectMet(bool &SelectedMet){ 
    if( Met_type1PF_pt_ > 200)  SelectedMet = true;
}
*/
//void SelectElectrons(vector<TLorentzVector> & SelectedElectrons, vector<int> & SelectedElectronsIndex, bool data){/*{{{*/
//	//?data does not occur.
//  for (UInt_t j = 0; j < patElectron_pt_->size(); ++j){//banch in tree line945
//		//what is patElectron_pt?
//    if(!(patElectron_pt_->at(j)>20))                 continue;//A continue skips the rest of the body of an iteration-statement.
//    if(!(fabs(patElectron_eta_->at(j))<2.4))	     continue;//std::string::at can be used to extract characters by characters from a given string.
//    if(!(fabs(patElectron_SCeta_->at(j))<2.5))	     continue;
//		//SCeta?//super cluster
//    if(!(patElectron_inCrack_->at(j)==0))	         continue;
////    if(!(patElectron_isPassLoose_->at(j)==1))	     continue;
//    if(!(patElectron_passConversionVeto_->at(j)==1)) continue;
//		//?
//    //TLorentzVector electron; electron.SetPtEtaPhiE(patElectron_pt_->at(j),patElectron_eta_->at(j),patElectron_phi_->at(j),patElectron_energy_->at(j)*patElectron_energyCorr_->at(j));
//    TLorentzVector electron; electron.SetPtEtaPhiE(patElectron_pt_->at(j),patElectron_eta_->at(j),patElectron_phi_->at(j),patElectron_energy_->at(j));
//    SelectedElectrons.push_back(electron);
//    SelectedElectronsIndex.push_back(j);
//  }
//}/*}}}*/
void SelectElectrons(vector<TLorentzVector> & SelectedElectrons, vector<int> & SelectedElectronsIndex, int type ){/*{{{*/
	//?data does not occur.
    //0; loose
    //1;medium
    //2;tight
    //3;veto
  for (UInt_t j = 0; j < patElectron_pt_->size(); ++j){//banch in tree line945
		//what is patElectron_pt?
    if(!(patElectron_pt_->at(j)>20))                 continue;//A continue skips the rest of the body of an iteration-statement.
    if(!(fabs(patElectron_eta_->at(j))<2.4))	     continue;//std::string::at can be used to extract characters by characters from a given string.
//    if(!(fabs(patElectron_SCeta_->at(j))<2.5))	     continue;
		//SCeta?//super cluster
//    if(!(patElectron_inCrack_->at(j)==0))	         continue;
		//?//1.4442<fabs(EleSCeta) && fabs(EleSCeta)<1.5660
//    if(!(patElectron_isPassLoose_->at(j)==1))	     continue;
//    if(!(patElectron_passConversionVeto_->at(j)==1)) continue;//no need to do it because already implemented in VID
    if(type==0){
        if(!(patElectron_cutBasedElectronID_Fall17_94X_V2_loose_->at(j) == 1)) continue;
    }
    if(type==1){
        if(!(patElectron_cutBasedElectronID_Fall17_94X_V2_medium_->at(j) == 1)) continue;
    }
    if(type==2){
        if(!(patElectron_cutBasedElectronID_Fall17_94X_V2_tight_->at(j) == 1)) continue;
    }
    if(type==3){
        if(!(patElectron_cutBasedElectronID_Fall17_94X_V2_veto_->at(j) == 1)) continue;
    }
    //TLorentzVector electron; electron.SetPtEtaPhiE(patElectron_pt_->at(j),patElectron_eta_->at(j),patElectron_phi_->at(j),patElectron_energy_->at(j)*patElectron_energyCorr_->at(j));
    TLorentzVector electron; electron.SetPtEtaPhiE(patElectron_pt_->at(j),patElectron_eta_->at(j),patElectron_phi_->at(j),patElectron_energy_->at(j));
    SelectedElectrons.push_back(electron);
    SelectedElectronsIndex.push_back(j);
  }
}/*}}}*/

void SelectMuons(vector<TLorentzVector> & SelectedMuons, vector<int> & SelectedMuonsIndex, int type){/*{{{*/
    //changed ISO to ss of TTTT
    //0:loose; 1:medium; 2 :tight
  for (UInt_t j = 0; j < Muon_pt_->size(); ++j){
    if(!(Muon_pt_->at(j)>20))                     continue;
    if(!(fabs(Muon_eta_->at(j))<2.4))             continue;
    if(type==0){
        if(!(Muon_loose_->at(j)==1))                  continue;
    }
    if(type==1){
        if(!(Muon_medium_->at(j)==1))    continue;
    }
    if(type==2){
        if(!(Muon_tight_->at(j)==1))     continue;
    }
//    if(!(Muon_relIsoDeltaBetaR04_->at(j)<0.15))   continue;  //loose iso->change to 0.15(tight) from 0.25
		//Muon_relIsoDeltaBetaR04?_
    double I1 = 0.4, I2 = 0, I3 = 0;//looseWP from ss of TTTT
    if(!((Muon_miniIsoRel_->at(j)<I1)|((Muon_jetptratio_->at(j)>I2)&&(Muon_ptrel_->at(j)>I3))))  continue;
    //?Muon_jetptratioV2?
    TLorentzVector muon; muon.SetPtEtaPhiE(Muon_pt_->at(j),Muon_eta_->at(j),Muon_phi_->at(j),Muon_energy_->at(j));
    SelectedMuons.push_back(muon);
    SelectedMuonsIndex.push_back(j);
  }
}/*}}}*/
void SelectTaus(vector<TLorentzVector>& SelectedTaus, Int_t TauWP){
    //this is tau ID in ttH
    //1:loose;2:medium;3:tight
    for (UInt_t j = 0; j < Tau_pt_->size(); ++j){
        if(!(Tau_pt_->at(j)>20))    continue;
        if(!(Tau_eta_->at(j)<2.3))  continue;
//       if(!(Tau_leadChargedCandDz_pv_->at(j)<0.2)) continue;
        if(!(Tau_packedLeadTauCand_dz_->at(j)<0.2))  continue;//missing dz
        //?use which dz still need more thinking
        if(!(Tau_decayModeFindingNewDMs_->at(j)==1)) continue;
        //???not sure why all taus is 1? if so no point in this requirement. //?not sure, is seem all are 1; 
        if(Tau_decayMode_->at(j)==5 or Tau_decayMode_->at(j)==6)    continue;//for decay mode
        if(TauWP==1) {
            if(!(Tau_byVVLooseDeepTau2017v2p1VSjet_->at(j)>0.5)) continue;
        }
        if(TauWP==2) {
            if(!(Tau_byVVLooseDeepTau2017v2p1VSjet_->at(j)>0.5&& Tau_byVLooseDeepTau2017v2p1VSmu_->at(j)>0.5 && Tau_byVVVLooseDeepTau2017v2p1VSe_->at(j)>0.5)) continue;
        }
//        if(TauWP==3){//channel specific
//            if(!(Tau_byVVLooseDeepTau2017v2p1VSjet_ && Tau_byVLooseDeepTau2017v2p1VSmu_->at(j)>0.5 && Tau_byVVVLooseDeepTau2017v2p1VSe_->at(j)>0.5)) continue;
 //       }
        //?need err handling
        TLorentzVector tau; tau.SetPtEtaPhiE(Tau_pt_->at(j),Tau_eta_->at(j),Tau_phi_->at(j),Tau_energy_->at(j));
        SelectedTaus.push_back(tau);
    }

}


//?Selectedelectron and muon not appear in the function body
//void SelectJets(int jetType,bool deepJet,  vector<TLorentzVector> & SelectedJets, vector<double> & SeclectedJetsBTags, vector<TLorentzVector> SelectedElectrons, vector<TLorentzVector> SelectedMuons, int SysJes, int SysJer, bool data, bool &deltaPhiJetMet){
void SelectJets(int jetType,bool deepJet,  vector<TLorentzVector> & SelectedJets, vector<double> & SeclectedJetsBTags,  int SysJes, int SysJer,  bool &deltaPhiJetMet){
    //this is for 2016data
  //jetType=0  -> usual jets; we use loose ID here.https://twiki.cern.ch/twiki/bin/view/CMS/JetID13TeVRun2016
  //jetType=11 -> b-jets L
  //jetType=12 -> b-jets M
  //jetType=13 -> b-jets T
  //jetType=2  -> forward jets
  //MinDeltaPhiJetMet = 99.0;
  double MaxMostForwardJetEta = -99;/*{{{*/
	//?is Jet_pt_a string?
	//maybe j means j th jet?
  for (UInt_t j = 0; j < Jet_pt_->size(); ++j){
        double jetpt = 0.;
        if(SysJes==0 && SysJer==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)    *Jet_JerSF_->at(j)    ;}
        if(SysJes==1 && SysJer==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSFup_->at(j)  *Jet_JerSF_->at(j)    ;}
        if(SysJes==2 && SysJer==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSFdown_->at(j)*Jet_JerSF_->at(j)    ;}
        if(SysJes==0 && SysJer==1){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)    *Jet_JerSFup_->at(j)  ;}
        if(SysJes==0 && SysJer==2){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)    *Jet_JerSFdown_->at(j);}
    //    if(fabs(Jet_eta_->at(j))>2.65&&fabs(Jet_eta_->at(j))<3.139&&jetpt>50)    continue;
    //    ?what does this do?
        if(!(jetpt>25))                                        continue;
        double NHF = Jet_neutralHadEnergyFraction_->at(j);
        double NEMF = Jet_neutralEmEnergyFraction_->at(j);
        double CHF = Jet_chargedHadronEnergyFraction_->at(j);
        double MUF = Jet_muonEnergyFraction_->at(j);
        double CEMF = Jet_chargedEmEnergyFraction_->at(j);
        double NumConst = Jet_numberOfConstituents_->at(j);
        double NumNeutralParticles = Jet_numberOfConstituents_->at(j)-Jet_chargedMultiplicity_->at(j);
        double CHM = Jet_chargedMultiplicity_->at(j);
        if(!(fabs(Jet_eta_->at(j))<5.0))                                        continue;
        //it seems that b jet also have to meet below requirements?
        //yes
        if(fabs(Jet_eta_->at(j))<2.4){
            if(!(NHF<0.99)) continue;
            if(!(NEMF<0.99)) continue;
            if(!(NumConst>1)) continue;
    //        if(!(MUF<0.8)) continue;
            if(!(CHF>0))  continue;
            if(!(CHM>0))  continue;
            if(!(CEMF<0.99)) continue;
        }
        else if(fabs(Jet_eta_->at(j))>2.4 && fabs(Jet_eta_->at(j))<2.7){
            if(!(NHF<0.99)) continue;
            if(!(NEMF<0.99)) continue;
            if(!(NumConst>1)) continue;
         //   if(!(MUF<0.8)) continue;
        }
        else if(fabs(Jet_eta_->at(j))>2.7 && fabs(Jet_eta_->at(j))<3.0){
            if(!(NEMF>0.01))  continue;
            if(!(NHF<0.98))   continue;
            if(!(NumNeutralParticles>2)) continue;
        }
        else if(fabs(Jet_eta_->at(j))>3.0){
            if(!(NEMF<0.90))              continue;
            if(!(NumNeutralParticles>10)) continue;
        }

        if(deepJet){
            if(jetType==11){
                if(!(Jet_pfDeepFlavourBJetTags_->at(j)>0.0614))continue;
            }
            if(jetType==12){
                if(!(Jet_pfDeepFlavourBJetTags_->at(j)>0.3093)) continue;
            }
            if(jetType==13){
                if(!(Jet_pfDeepFlavourBJetTags_->at(j)>0.7221)) continue;
            }
        }else{
            if(jetType==11){if(!(Jet_pfDeepCSVBJetTags_->at(j)>0.2217)) continue;}
            if(jetType==12){if(!(Jet_pfDeepCSVBJetTags_->at(j)>0.6321)) continue;}
            if(jetType==13){if(!(Jet_pfDeepCSVBJetTags_->at(j)>0.8953)) continue;}
        }
            //find mostforwardjeteta
        if(jetType==0){//normal jet
            if (fabs(Jet_eta_->at(j))>MaxMostForwardJetEta) {
               MaxMostForwardJetEta = fabs(Jet_eta_->at(j)); MostForwardJetEta = Jet_eta_->at(j); MostForwardJetPt = jetpt;
            }//MostForwardJetEta branch in new tree and SB.
            if(!(fabs(Jet_eta_->at(j))<2.4)) continue;
        }
        if(jetType==2) {//forwardjet
            if(!(fabs(Jet_eta_->at(j))>=2.4))      continue;
            if(!(jetpt>30)) continue;
        }
    //    else {
    //        if(!(fabs(Jet_eta_->at(j))<2.4)) continue;
    //    }
        if(DeltaPhi(Jet_phi_->at(j),Met_type1PF_phi_)<MinDeltaPhiJetMet) MinDeltaPhiJetMet = DeltaPhi(Jet_phi_->at(j),Met_type1PF_phi_);//MinDeltaPhiJetMe a branch in newtree and SB
        double SF = jetpt/Jet_pt_->at(j);
        TLorentzVector jet_prov; jet_prov.SetPtEtaPhiM(Jet_pt_->at(j),Jet_eta_->at(j),Jet_phi_->at(j),Jet_mass_->at(j));
        TLorentzVector jet; jet.SetPxPyPzE(SF*jet_prov.Px(),SF*jet_prov.Py(),SF*jet_prov.Pz(),SF*jet_prov.E());
        SelectedJets.push_back(jet);
        if(deepJet) {
            SeclectedJetsBTags.push_back(Jet_pfDeepFlavourBJetTags_->at(j));
        }else{
            SeclectedJetsBTags.push_back(Jet_pfDeepCSVBJetTags_->at(j));
        }
  }
  if(!(MinDeltaPhiJetMet>0.6)) deltaPhiJetMet=false;//used in Selectjets and SelectCA8Jets
}/*}}}*/

void SelectTops(vector<TLorentzVector> & SelectedTops){
    for (UInt_t j = 0; j < TopTagger_type_->size(); ++j){
        if(!(TopTagger_type_->at(j)==3)) continue;//resolved 
//        if(!(TopTagger_discriminator_->at(j)>0.6)) continue;
//        ??not sure of the effect of discriminator
        TLorentzVector jet1; jet1.SetPtEtaPhiM(Jet_pt_->at(TopTagger_jet1Idx_->at(j)),Jet_eta_->at(TopTagger_jet1Idx_->at(j)),Jet_phi_->at(j),Jet_mass_->at(TopTagger_jet1Idx_->at(j)));
        TLorentzVector jet2; jet2.SetPtEtaPhiM(Jet_pt_->at(TopTagger_jet2Idx_->at(j)),Jet_eta_->at(TopTagger_jet2Idx_->at(j)),Jet_phi_->at(j),Jet_mass_->at(TopTagger_jet2Idx_->at(j)));
        TLorentzVector jet3; jet3.SetPtEtaPhiM(Jet_pt_->at(TopTagger_jet3Idx_->at(j)),Jet_eta_->at(TopTagger_jet3Idx_->at(j)),Jet_phi_->at(j),Jet_mass_->at(TopTagger_jet3Idx_->at(j)));

/*        double top_pt = Jet_pt_->at(TopTagger_jet1Idx_->at(j))+Jet_pt_->at(TopTagger_jet2Idx_->at(j))+Jet_pt_->at(TopTagger_jet3Idx_->at(j));//this top_pt calculation is wrong
//         TopPtMin = (SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt();//refresh in the loop
       // top_eta and phi need modification
        double top_eta = Jet_eta_->at(TopTagger_jet1Idx_->at(j))+Jet_eta_->at(TopTagger_jet2Idx_->at(j))+Jet_eta_->at(TopTagger_jet3Idx_->at(j));
        double top_phi = Jet_phi_->at(TopTagger_jet1Idx_->at(j))+Jet_phi_->at(TopTagger_jet2Idx_->at(j))+Jet_phi_->at(TopTagger_jet3Idx_->at(j));
        double top_m = Jet_mass_->at(TopTagger_jet1Idx_->at(j))+Jet_mass_->at(TopTagger_jet2Idx_->at(j))+Jet_mass_->at(TopTagger_jet3Idx_->at(j));*/
//        TLorentzVector top; top.SetPtEtaPhiM(top_pt,top_eta,top_phi,top_m);
        TLorentzVector top; 
        top = jet1 + jet2 + jet3;
        SelectedTops.push_back(top);
    }

}
/*
void SelectCA8Jets(int CA8jetType,vector<TLorentzVector> & SelectedCA8Jets,vector<TLorentzVector> SelectedElectrons,vector<TLorentzVector> SelectedMuons, vector<int> & CA8Indices, 
		   int SysJes, int SysJer, bool data, bool &deltaPhiJetMet){
  //CA8jetType=0 -> W-jets
  //CA8jetType=1 -> top-jets
  for (UInt_t j = 0; j < BoostedJet_pt_->size(); ++j){
    double jetpt = 0.;
    if(SysJes==0 && SysJer==0){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSF_->at(j)    *BoostedJet_JerSF_->at(j)    ;}
    if(SysJes==1 && SysJer==0){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSFup_->at(j)  *BoostedJet_JerSF_->at(j)    ;}
    if(SysJes==2 && SysJer==0){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSFdown_->at(j)*BoostedJet_JerSF_->at(j)    ;}
    if(SysJes==0 && SysJer==1){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSF_->at(j)    *BoostedJet_JerSFup_->at(j)  ;}
    if(SysJes==0 && SysJer==2){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSF_->at(j)    *BoostedJet_JerSFdown_->at(j);}
    double SF = jetpt/BoostedJet_pt_->at(j);
    if(!(jetpt>200)) continue;
    if(!(fabs(BoostedJet_eta_->at(j))<2.4))               continue;
    if(!(BoostedJet_neutralHadEnergyFraction_->at(j)<0.90)) continue;
    if(!(BoostedJet_neutralEmEnergyFraction_->at(j)<0.90)) continue;
    if(!(BoostedJet_numberOfConstituents_->at(j)>1)) continue;
    if(!(BoostedJet_chargedHadronEnergyFraction_->at(j)>0.0)) continue;
    if(!(BoostedJet_chargedMultiplicity_->at(j)>0.0)) continue;
    if(CA8jetType==0){
      if(!(SF*BoostedJet_puppi_softdrop_mass_->at(j)>65 && SF*BoostedJet_puppi_softdrop_mass_->at(j)<105)) continue;//wmass = 80
      if(!(BoostedJet_puppi_tau2_->at(j)/BoostedJet_puppi_tau1_->at(j)<0.45)) continue;
      //????what is softdrop and tau?
    } 
    else if(CA8jetType==1) {
      if(!(jetpt>400))                                                                           continue;
      if(!(SF*BoostedJet_puppi_softdrop_mass_->at(j)>105 && SF*BoostedJet_puppi_softdrop_mass_->at(j)<220)) continue;
      if(!(BoostedJet_puppi_tau3_->at(j)/BoostedJet_puppi_tau2_->at(j)<0.80)) continue;
    }

    TLorentzVector jet_prov; jet_prov.SetPtEtaPhiM(BoostedJet_pt_->at(j),BoostedJet_eta_->at(j),BoostedJet_phi_->at(j),BoostedJet_mass_->at(j));
    TLorentzVector jet; jet.SetPxPyPzE(SF*jet_prov.Px(),SF*jet_prov.Py(),SF*jet_prov.Pz(),SF*jet_prov.E());
    SelectedCA8Jets.push_back(jet);
    CA8Indices.push_back(j);
  }
}
*/
/*
void ResolvedRegionSelection(bool &ResolvedEvent,vector<TLorentzVector> SelectedJets,vector<double> SeclectedJetsBTags,TLorentzVector &HadronicTopQuark,
			     TLorentzVector &Jet1,TLorentzVector &Jet2,TLorentzVector &Jet3,bool TopMassCut,bool btag){
  double TopPtMin=250;
  double TopMassInitial=99999;
  for(unsigned int i=0; i<SelectedJets.size(); i++){
    for(unsigned int j=i+1; j<SelectedJets.size(); j++){
      for(unsigned int k=j+1; k<SelectedJets.size(); k++){
		  if(!((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt()>TopPtMin))   continue;
	//if(!(fabs((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()-173.1)<TopMassInitial))                                                    continue;
	if(TopMassCut){if(!((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()>100 && (SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()<300)) continue;}
	if(btag){if(!(SeclectedJetsBTags[i]>0.4941 || SeclectedJetsBTags[j]>0.4941 || SeclectedJetsBTags[k]>0.4941))                                          continue;}
	if(SeclectedJetsBTags[i]>SeclectedJetsBTags[j] && SeclectedJetsBTags[i]>SeclectedJetsBTags[k]){
	  Jet1.SetPtEtaPhiE(SelectedJets[i].Pt(),SelectedJets[i].Eta(),SelectedJets[i].Phi(),SelectedJets[i].E());
	  Jet2.SetPtEtaPhiE(SelectedJets[j].Pt(),SelectedJets[j].Eta(),SelectedJets[j].Phi(),SelectedJets[j].E());
	  Jet3.SetPtEtaPhiE(SelectedJets[k].Pt(),SelectedJets[k].Eta(),SelectedJets[k].Phi(),SelectedJets[k].E());
	}
	if(SeclectedJetsBTags[j]>SeclectedJetsBTags[i] && SeclectedJetsBTags[j]>SeclectedJetsBTags[k]){
	  Jet1.SetPtEtaPhiE(SelectedJets[j].Pt(),SelectedJets[j].Eta(),SelectedJets[j].Phi(),SelectedJets[j].E());
	  Jet2.SetPtEtaPhiE(SelectedJets[i].Pt(),SelectedJets[i].Eta(),SelectedJets[i].Phi(),SelectedJets[i].E());
	  Jet3.SetPtEtaPhiE(SelectedJets[k].Pt(),SelectedJets[k].Eta(),SelectedJets[k].Phi(),SelectedJets[k].E());
	}
	if(SeclectedJetsBTags[k]>SeclectedJetsBTags[i] && SeclectedJetsBTags[k]>SeclectedJetsBTags[j]){
	  Jet1.SetPtEtaPhiE(SelectedJets[k].Pt(),SelectedJets[k].Eta(),SelectedJets[k].Phi(),SelectedJets[k].E());
	  Jet2.SetPtEtaPhiE(SelectedJets[i].Pt(),SelectedJets[i].Eta(),SelectedJets[i].Phi(),SelectedJets[i].E());
	  Jet3.SetPtEtaPhiE(SelectedJets[j].Pt(),SelectedJets[j].Eta(),SelectedJets[j].Phi(),SelectedJets[j].E());
	}
	TopPtMin = (SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt();
	TopMassInitial=fabs((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()-173.1);
	HadronicTopQuark=(SelectedJets[i]+SelectedJets[j]+SelectedJets[k]);//argument in WriteTopRelatedBranches
//	deltaPhiMetTop = DeltaPhi(HadronicTopQuark.Phi(),Met_phi);//in NewTree
//	TransverseMassMetTop = sqrt(2*HadronicTopQuark.Pt()*Met_pt*(1-cos(deltaPhiMetTop)));
	if(!(TransverseMassMetTop>500)) continue;
	ResolvedEvent=true;//argument in WriteTopRelatedBranches
      }
    }
  }
}
*/

//I think this function only works for top decay to 3 jets
void ResolvedRegionSelection(bool &ResolvedEvent,vector<TLorentzVector> SelectedJets,vector<double> SeclectedJetsBTags,TLorentzVector &HadronicTopQuark,
                            TLorentzVector &Jet1,TLorentzVector &Jet2,TLorentzVector &Jet3,bool TopMassCut,bool btag){/*{{{*/
  double TopPtMin=250; //refresh in the loop
  //how do we set this number?
  double TopMassInitial=99999;
  for(unsigned int i=0; i<SelectedJets.size(); i++){
    for(unsigned int j=i+1; j<SelectedJets.size(); j++){
      for(unsigned int k=j+1; k<SelectedJets.size(); k++){
         if(!((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt()>TopPtMin)) continue;
         //if(!(fabs((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()-173.1)<TopMassInitial)) continue;
         if(TopMassCut){if(!((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()>100 && (SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()<300)) continue;}
         if(btag){if(!(SeclectedJetsBTags[i]>0.6321 || SeclectedJetsBTags[j]>0.6321 || SeclectedJetsBTags[k]>0.6321)) continue;}//require a least 1  medium b jet
        // double TM = sqrt(2*(SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt()*Met_pt*(1-cos(DeltaPhi((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Phi(),Met_phi))));
		 //?what is TM?
        // if(!(TM>500)) continue;
         //???why make this cut?
				 //?what if we have more than one pair of three jet?
         Jet1.SetPtEtaPhiE(SelectedJets[i].Pt(),SelectedJets[i].Eta(),SelectedJets[i].Phi(),SelectedJets[i].E());
         Jet2.SetPtEtaPhiE(SelectedJets[j].Pt(),SelectedJets[j].Eta(),SelectedJets[j].Phi(),SelectedJets[j].E());
         Jet3.SetPtEtaPhiE(SelectedJets[k].Pt(),SelectedJets[k].Eta(),SelectedJets[k].Phi(),SelectedJets[k].E());
         TopPtMin = (SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt();//refresh in the loop
         TopMassInitial=fabs((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()-173.1);
         HadronicTopQuark=(SelectedJets[i]+SelectedJets[j]+SelectedJets[k]);
		 //???will not work if we have more than 1 HadronicTopQuark
         deltaPhiMetTop = DeltaPhi(HadronicTopQuark.Phi(),Met_phi);//branch in new tree
         TransverseMassMetTop = sqrt(2*HadronicTopQuark.Pt()*Met_pt*(1-cos(deltaPhiMetTop)));//branch in NewTree and SB
         ResolvedEvent=true;
      }
    }
  }
}
/*}}}*/
/*
void PartiallyMergedSelection(bool &PartiallyMerged,vector<TLorentzVector> SelectedWJets,vector<TLorentzVector> SelectedJets,vector<double> SeclectedJetsBTags,TLorentzVector &HadronicTopQuark,TLorentzVector &Jet1,TLorentzVector &Jet2,bool TopMassCut,bool btag,vector<int> CA8Indices,int & CA8Index,double &WMass_,double &WSubjet_, bool data){
  double TopPtMin=20;
  double TopMassInitial=99999;
  for(unsigned int i=0; i<SelectedWJets.size(); i++){
    for(unsigned int k=0; k<SelectedJets.size(); k++){
      if(!((SelectedWJets[i]+SelectedJets[k]).Pt()>TopPtMin))                                                        continue;
      //if(!(fabs((SelectedWJets[i]+SelectedJets[k]).M()-173.1)<TopMassInitial))                                     continue;
      if(!(DeltaR(SelectedWJets[i].Eta(),SelectedJets[k].Eta(),SelectedWJets[i].Phi(),SelectedJets[k].Phi())>0.8))   continue;
      if(btag){if(!(SeclectedJetsBTags[k]>0.4941))                                                                       continue;}
      if(TopMassCut){if(!((SelectedWJets[i]+SelectedJets[k]).M()>100 && (SelectedWJets[i]+SelectedJets[k]).M()<300)) continue;}
      Jet1.SetPtEtaPhiE(SelectedWJets[i].Pt(),SelectedWJets[i].Eta(),SelectedWJets[i].Phi(),SelectedWJets[i].E());
      Jet2.SetPtEtaPhiE(SelectedJets[k].Pt(),SelectedJets[k].Eta(),SelectedJets[k].Phi(),SelectedJets[k].E());
      TopPtMin = (SelectedWJets[i]+SelectedJets[k]).Pt();
      PartiallyMerged=true;
      TopMassInitial=fabs((SelectedWJets[i]+SelectedJets[k]).M()-173.1);
      HadronicTopQuark=(SelectedWJets[i]+SelectedJets[k]);
      CA8Index=CA8Indices[i];
	 
      double SF = (BoostedJet_Uncorr_pt_->at(CA8Indices[i])/BoostedJet_pt_->at(CA8Indices[i]))*BoostedJet_JesSF_->at(CA8Indices[i])*BoostedJet_JerSF_->at(CA8Indices[i]);
      WMass_   = SF*BoostedJet_pruned_mass_->at(CA8Indices[i]);
      WSubjet_ = BoostedJet_tau2_->at(CA8Indices[i])/BoostedJet_tau1_->at(CA8Indices[i]);
    }
  }
}

void FullyMergedSelection(bool & FullyMerged, vector<TLorentzVector> SelectedTopJets, TLorentzVector &HadronicTopQuark,vector<int> CA8Indices,double &TopSoftMass_,double &TopSubjet_, bool data){
  double TopPtMin=400;
  for(unsigned int i=0; i<SelectedTopJets.size(); i++){
    if(!(SelectedTopJets[i].Pt()>TopPtMin)) continue;
    FullyMerged=true;
    TopPtMin=SelectedTopJets[i].Pt();
    HadronicTopQuark=SelectedTopJets[i];
    double SF = (BoostedJet_Uncorr_pt_->at(CA8Indices[i])/BoostedJet_pt_->at(CA8Indices[i]))*BoostedJet_JesSF_->at(CA8Indices[i])*BoostedJet_JerSF_->at(CA8Indices[i]);
    TopSoftMass_  = SF*BoostedJet_softdrop_mass_->at(CA8Indices[i]);
    TopSubjet_    = BoostedJet_tau3_->at(CA8Indices[i])/BoostedJet_tau2_->at(CA8Indices[i]);
  }
}
*/

/*
void BTagSF(int selection, double JetPt, double JetEta, int flav, double &SF, double &SFerr){
  bool DoubleUncertainty = false;
  double MinBJetPt = 20.;
  double MaxBJetPt = 1000.;
  double MaxLJetPt = 1000.;
  if((flav==5 || flav==4) && JetPt<=MinBJetPt){
    JetPt = MinBJetPt+0.1; 
    DoubleUncertainty = true;
  }  
  if((flav==5 || flav==4) && JetPt>=MaxBJetPt){
    JetPt = MaxBJetPt-0.1; 
    DoubleUncertainty = true;
  }  
  if(flav==0 && JetPt>=MaxLJetPt){
    JetPt = MaxLJetPt-0.1; 
    DoubleUncertainty = true;
  }
  auto btagentry_flav = flav == 5 ? BTagEntry::FLAV_B : (flav == 4 ? BTagEntry::FLAV_C : BTagEntry::FLAV_UDSG);
  double jet_scalefactor = 1;
  double jet_scalefactor_up = 0;
  double jet_scalefactor_do = 0;
  if(selection==0 || selection==1){
    if(flav==5 || flav==4){
      jet_scalefactor    = readerMComb.eval(btagentry_flav, JetEta, JetPt);
      jet_scalefactor_up = readerMComb_up.eval(btagentry_flav, JetEta, JetPt); 
      jet_scalefactor_do = readerMComb_do.eval(btagentry_flav, JetEta, JetPt);
    } else {
      jet_scalefactor    = readerMIncl.eval(btagentry_flav, JetEta, JetPt);
      jet_scalefactor_up = readerMIncl_up.eval(btagentry_flav, JetEta, JetPt); 
      jet_scalefactor_do = readerMIncl_do.eval(btagentry_flav, JetEta, JetPt);
    }
  } else if(selection==2){
    if(flav==5 || flav==4){
      jet_scalefactor    = readerLComb.eval(btagentry_flav, JetEta, JetPt);
      jet_scalefactor_up = readerLComb_up.eval(btagentry_flav, JetEta, JetPt); 
      jet_scalefactor_do = readerLComb_do.eval(btagentry_flav, JetEta, JetPt);
    } else {
      jet_scalefactor    = readerLIncl.eval(btagentry_flav, JetEta, JetPt);
      jet_scalefactor_up = readerLIncl_up.eval(btagentry_flav, JetEta, JetPt); 
      jet_scalefactor_do = readerLIncl_do.eval(btagentry_flav, JetEta, JetPt);
    }
  }
  if(DoubleUncertainty) {
    jet_scalefactor_up = 2*(jet_scalefactor_up - jet_scalefactor) + jet_scalefactor; 
    jet_scalefactor_do = 2*(jet_scalefactor_do - jet_scalefactor) + jet_scalefactor; 
  }
  if(jet_scalefactor==0){
    jet_scalefactor=1;
    jet_scalefactor_up=1;
    jet_scalefactor_do=1;
  }
  SF=jet_scalefactor;
  SFerr=max(fabs(jet_scalefactor-jet_scalefactor_up),fabs(jet_scalefactor-jet_scalefactor_do));
  //cout<<JetPt<<" "<<JetEta<<" "<<flav<<" ("<<btagentry_flav<<") "<<jet_scalefactor<<" "<<jet_scalefactor_up<<" "<<jet_scalefactor_do<<endl;
}

*/
//w_Btag branch in NewTree and SB
//?what is this doing exactly?
/*
void get_weight_btag(int selection, double &w_Btag, double &w_BtagUp, double &w_BtagDown, double &w_Btag1Up, double &w_Btag1Down, double &w_Btag2Up, double &w_Btag2Down, double &w_BtagLoose, double &w_BtagLooseUp, double &w_BtagLooseDown, string fileName){
  string FILEprov = "/publicfs/cms/user/yutz/Tprime/2017_dineutrino/BtagEfficiency_new_v3/"+fileName;
  const char *FILE = FILEprov.c_str();
  TFile *fileBTagEfficiency = TFile::Open(FILE);
  double mcTagMedium = 1.;     double mcTagLoose = 1.;
  double mcNoTagMedium = 1.;   double mcNoTagLoose = 1.;
  double dataTagMedium = 1.;   double dataTagLoose = 1.;
  double dataNoTagMedium = 1.; double dataNoTagLoose = 1.;
  double err1Medium = 0.;      double err1Loose = 0.;
  double err2Medium = 0.;      double err2Loose = 0.;
  double err3Medium = 0.;      double err3Loose = 0.;
  double err4Medium = 0.;      double err4Loose = 0.;
  for (UInt_t j = 0; j < Jet_pt_->size(); ++j){
    if(!((Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)*Jet_JerSF_->at(j))>20)) continue;
    if(!(fabs(Jet_eta_->at(j))<2.4))                                      continue;
    if(!(Jet_neutralHadEnergyFraction_->at(j)<0.90))                      continue;
    if(!(Jet_neutralEmEnergyFraction_->at(j)<0.90))                       continue;
    if(!(Jet_numberOfConstituents_->at(j)>1))                             continue;
    if(!(Jet_chargedHadronEnergyFraction_->at(j)>0.0))                    continue;
    if(!(Jet_chargedMultiplicity_->at(j)>0.0))                            continue;
    //if(!(Jet_chargedEmEnergyFraction_->at(j)<0.99))                       continue;
    double JetPt  = (Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)*Jet_JerSF_->at(j)); 
    double JetEta = fabs(Jet_eta_->at(j)); 
    int flav = Jet_hadronFlavour_->at(j);
    double MinBJetPt = 20.;
    double MaxBJetPt = 1000.;
    double MaxLJetPt = 1000.;
    if((flav==5 || flav==4) && JetPt<MinBJetPt){
      JetPt = MinBJetPt; 
    }  
    if((flav==5 || flav==4) && JetPt>MaxBJetPt){
      JetPt = MaxBJetPt; 
    }  
    if(flav==0 && JetPt>MaxLJetPt){
      JetPt = MaxLJetPt; 
    }  
    TH2F *NUM = (TH2F*)fileBTagEfficiency->Get("histM_b_passing_"); 
    TH2F *DEN = (TH2F*)fileBTagEfficiency->Get("histM_b_total_");
    if(selection==0 || selection==1){
      if(flav == 5) {
	NUM = (TH2F*)fileBTagEfficiency->Get("histM_b_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histM_b_total_");
      }else if( flav==4){
	NUM = (TH2F*)fileBTagEfficiency->Get("histM_c_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histM_c_total_");
      }else{
	NUM = (TH2F*)fileBTagEfficiency->Get("histM_udsg_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histM_udsg_total_");
      }
    } else if(selection==2){
      if(flav == 5) {
	NUM = (TH2F*)fileBTagEfficiency->Get("histL_b_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histL_b_total_");
      }else if( flav==4){
	NUM = (TH2F*)fileBTagEfficiency->Get("histL_c_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histL_c_total_");
      }else{
	NUM = (TH2F*)fileBTagEfficiency->Get("histL_udsg_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histL_udsg_total_");
      }
    }
    NUM->Divide(DEN);
    int etaBin = 1;
    int ptBin = 1;
    if(JetPt>19  && JetPt<=30)   ptBin = 1;
    if(JetPt>30  && JetPt<=50)   ptBin = 2;
    if(JetPt>50  && JetPt<=70)   ptBin = 3;
    if(JetPt>70  && JetPt<=100)  ptBin = 4;
    if(JetPt>100 && JetPt<=140)  ptBin = 5;
    if(JetPt>140 && JetPt<=200)  ptBin = 6;
    if(JetPt>200 && JetPt<=300)  ptBin = 7;
    if(JetPt>300 && JetPt<=600)  ptBin = 8;
    if(JetPt>600 && JetPt<=1000) ptBin = 9;
    if(flav!=5 && flav!=4)       ptBin = 1;
    double eff   = NUM->GetBinContent(ptBin,etaBin);
    double SF    = 1.0;
    double SFerr = 0.0;
    BTagSF(selection, JetPt, JetEta, flav, SF, SFerr);
    if(Jet_pfDeepCSVBJetTags_->at(j)>0.4941){
      mcTagMedium *= eff;
      dataTagMedium *= eff*SF;
      if(flav==5 || flav ==4)  err1Medium += SFerr/SF; //correlated for b/c
      else err3Medium += SFerr/SF;                     //correlated for light
    }else{
      mcNoTagMedium *= (1- eff);
      dataNoTagMedium *= (1- eff*SF);
      if(flav==5 || flav ==4 ) err2Medium += (-eff*SFerr)/(1-eff*SF); //correlated for b/c
      else err4Medium +=  (-eff*SFerr)/(1-eff*SF);                    //correlated for light
    }
    if(Jet_pfDeepCSVBJetTags_->at(j)>0.1522){
      mcTagLoose *= eff;
      dataTagLoose *= eff*SF;
      if(flav==5 || flav ==4)  err1Loose += SFerr/SF;
      else err3Loose += SFerr/SF;
    }else{
      mcNoTagLoose *= (1- eff);
      dataNoTagLoose *= (1- eff*SF);
      if(flav==5 || flav ==4 ) err2Loose += (-eff*SFerr)/(1-eff*SF);
      else err4Loose +=  (-eff*SFerr)/(1-eff*SF);
    }
    delete NUM; delete DEN;
    //cout<<JetPt<<" "<<flav<<" "<<ptBin<<" "<<etaBin<<" "<<eff<<" "<<SF<<" "<<SFerr<<endl;
  }
  double wtbtagMedium        = 1; double wtbtagLoose        = 1;
  double wtbtagErrBCMedium   = 0; double wtbtagErrBCLoose   = 0;
  double wtbtagErrUDSGMedium = 0; double wtbtagErrUDSGLoose = 0;
  if((mcNoTagMedium*mcTagMedium)!=0) wtbtagMedium        = (dataNoTagMedium * dataTagMedium ) / ( mcNoTagMedium * mcTagMedium ); 
  if((mcNoTagMedium*mcTagMedium)!=0) wtbtagErrBCMedium   = fabs(err1Medium+err2Medium) * wtbtagMedium;
  if((mcNoTagMedium*mcTagMedium)!=0) wtbtagErrUDSGMedium = fabs(err3Medium+err4Medium) * wtbtagMedium;
  if((mcNoTagLoose*mcTagLoose)!=0) wtbtagLoose        = (dataNoTagLoose * dataTagLoose ) / ( mcNoTagLoose * mcTagLoose ); 
  if((mcNoTagLoose*mcTagLoose)!=0) wtbtagErrBCLoose   = fabs(err1Loose+err2Loose) * wtbtagLoose;
  if((mcNoTagLoose*mcTagLoose)!=0) wtbtagErrUDSGLoose = fabs(err3Loose+err4Loose) * wtbtagLoose;
  w_Btag     = wtbtagMedium; 
  w_BtagUp   = wtbtagMedium+sqrt(wtbtagErrBCMedium*wtbtagErrBCMedium+wtbtagErrUDSGMedium*wtbtagErrUDSGMedium);
  w_BtagDown = wtbtagMedium-sqrt(wtbtagErrBCMedium*wtbtagErrBCMedium+wtbtagErrUDSGMedium*wtbtagErrUDSGMedium);
  w_Btag1Up   = wtbtagMedium+sqrt(wtbtagErrBCMedium*wtbtagErrBCMedium);
  w_Btag1Down = wtbtagMedium-sqrt(wtbtagErrBCMedium*wtbtagErrBCMedium);
  w_Btag2Up   = wtbtagMedium+sqrt(wtbtagErrUDSGMedium*wtbtagErrUDSGMedium);
  w_Btag2Down = wtbtagMedium-sqrt(wtbtagErrUDSGMedium*wtbtagErrUDSGMedium);
  w_BtagLoose     = wtbtagLoose; 
  w_BtagLooseUp   = wtbtagLoose+sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose+wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
  w_BtagLooseDown = wtbtagLoose-sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose+wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
  if(selection==2){
    w_Btag     = wtbtagLoose; 
    w_BtagUp   = wtbtagLoose+sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose+wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
    w_BtagDown = wtbtagLoose-sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose+wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
    w_Btag1Up   = wtbtagLoose+sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose);
    w_Btag1Down = wtbtagLoose-sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose);
    w_Btag2Up   = wtbtagLoose+sqrt(wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
    w_Btag2Down = wtbtagLoose-sqrt(wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
  }
  //cout<<"BTAG WEIGHT  "<<wtbtagErrBC<<" "<<wtbtagErrUDSG<<" "<<w_Btag<<" "<<w_BtagUp<<" "<<endl;
  delete fileBTagEfficiency;
}
*/

/*void ForwardJetSF(vector<TLorentzVector> SelectedForwardJets, double &w_for_, double &w_forUp_, double &w_forDown_){
  if(SelectedForwardJets.size()>0){
    double eta = eta = SelectedForwardJets[0].Eta(); double pt = SelectedForwardJets[0].Pt();
    int X1=-99; int Y1=-99;
    for(int i=1; i<histoForwardJet->GetXaxis()->GetNbins()+2; i++){
      if(eta<histoForwardJet->GetXaxis()->GetBinLowEdge(i)){ X1=i-1; break; }
    }
    for(int i=1; i<histoForwardJet->GetYaxis()->GetNbins()+2; i++){
      if(pt <histoForwardJet->GetYaxis()->GetBinLowEdge(i)){ Y1=i-1; break; }
    }
    if(pt>=histoForwardJet->GetYaxis()->GetBinLowEdge(histoForwardJet->GetYaxis()->GetNbins()+1)) {Y1=(histoForwardJet->GetYaxis()->GetNbins()+1)-1;}
    double SF = histoForwardJet->GetBinContent(X1,Y1);
    w_for_     = SF;
    w_forUp_   = SF + histoForwardJet->GetBinError(X1,Y1); //w_forUp_   = 1.0;
    w_forDown_ = SF - histoForwardJet->GetBinError(X1,Y1); //w_forDown_ = 1.0;
  }
}*/

void TopSF(TLorentzVector SelectedTopJets, bool FullyMerged, double &w_topJet_, double &w_topJetUp_, double &w_topJetDown_){/*{{{*/
  if(FullyMerged){
    if(SelectedTopJets.Pt()< 550) w_topJet_     = 1.06;
    if(SelectedTopJets.Pt()>=550) w_topJet_     = 1.06;
    if(SelectedTopJets.Pt()< 550) w_topJetUp_   = 1.06+0.09;
    if(SelectedTopJets.Pt()>=550) w_topJetUp_   = 1.06+0.09;
    if(SelectedTopJets.Pt()< 550) w_topJetDown_ = 1.06-0.04;
    if(SelectedTopJets.Pt()>=550) w_topJetDown_ = 1.06-0.04;
  }
}/*}}}*/

void WSF(TLorentzVector WJet, bool PartiallyMerged, double &w_WJet_, double &w_WJetUp_, double &w_WJetDown_, int CA8Index, int SysJes, int SysJer){/*{{{*/
  if(PartiallyMerged){
    bool matched = false;
    GenWBoson(matched, WJet);
    if(matched){
      w_WJet_     = 1.00*1.23*1.11;
      if(SysJes==1) w_WJet_ = 1.00*1.23*1.11 + sqrt(pow(Jet_JesSFup_->at(CA8Index)/Jet_JesSF_->at(CA8Index)-1  ,2) + 0.023*0.023);
      if(SysJes==2) w_WJet_ = 1.00*1.23*1.11 - sqrt(pow(1-Jet_JesSFdown_->at(CA8Index)/Jet_JesSF_->at(CA8Index),2) + 0.023*0.023);
      if(SysJer==1) w_WJet_ = 1.00*1.23*1.11 + sqrt(pow(Jet_JerSFup_->at(CA8Index)/Jet_JerSF_->at(CA8Index)-1  ,2) + 0.018*0.018);
      if(SysJer==2) w_WJet_ = 1.00*1.23*1.11 - sqrt(pow(1-Jet_JerSFdown_->at(CA8Index)/Jet_JerSF_->at(CA8Index),2) + 0.018*0.018);
      w_WJetUp_   = 1.00*1.23*1.11 + (0.08);
      w_WJetDown_ = 1.00*1.23*1.11 - (0.08);
      if(WJet.Pt()>200){
        w_WJetUp_   = 1.00*1.23*1.11 + (0.08 + 0.054*log(WJet.Pt()/200));
        w_WJetDown_ = 1.00*1.23*1.11 - (0.08 + 0.054*log(WJet.Pt()/200));
      }
    }
  }
}/*}}}*/

//?what's the purpose of thisi?
/*
void HTSF(string fileName, double HT, double Met_pt, double &w_SF1, double &w_SF1Up, double &w_SF1Down, double &w_SF2, double &w_SF2Up, double &w_SF2Down, double &w_SF3, double &w_SF3Up, double &w_SF3Down){
  if(fileName.find("ZToNuNu")!=string::npos ){	
        int htBin = 0;   int metBin = 0;
        if (HT>200 && HT<400) htBin = 1;
        if (HT>400 && HT<600) htBin = 2;
        if (HT>600 && HT<800) htBin = 3; 
        if (HT>800 && HT<1200) htBin = 4; 
        if (HT>1200 && HT<3000) htBin = 5; 
        if (Met_pt>200 && Met_pt<400) metBin = 1; 
        if (Met_pt>400 && Met_pt<700) metBin = 2; 
        if (Met_pt>700 && Met_pt<1600) metBin = 3; 
        if (htBin==0 || metBin==0){ 
           w_SF1=1; w_SF1Up=1; w_SF1Down=1;
        }  else {  
					//?what is histoSF1
					//in .h file, from SF_dineutrino/SF_2D.root
           w_SF1 = histoSF1->GetBinContent(htBin,metBin);
           w_SF1Up = histoSF1->GetBinContent(htBin,metBin)+ //778histoSF1->GetBinError(htBin,metBin);
           w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(htBin,metBin)- histoSF1->GetBinError(htBin,metBin)); 
        }
  }
  if(fileName.find("WToLNu")!=string::npos ){	
        int htBin = 0;   int metBin = 0;
        if (HT>200 && HT<400) htBin = 1;
        if (HT>400 && HT<600) htBin = 2;
        if (HT>600 && HT<800) htBin = 3; 
        if (HT>800 && HT<1200) htBin = 4; 
        if (HT>1200 && HT<3000) htBin = 5; 
        if (Met_pt>200 && Met_pt<400) metBin = 1; 
        if (Met_pt>400 && Met_pt<700) metBin = 2; 
        if (Met_pt>700 && Met_pt<1600) metBin = 3; 
        if (htBin==0 || metBin==0){ 
           w_SF2=1; w_SF2Up=1; w_SF2Down=1;
        }  else {  
           w_SF2 = histoSF2->GetBinContent(htBin,metBin);
           w_SF2Up = histoSF2->GetBinContent(htBin,metBin)+ histoSF2->GetBinError(htBin,metBin);
           w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(htBin,metBin)- histoSF2->GetBinError(htBin,metBin)); 
        }
  }
   if(fileName.find("TT")!=string::npos||fileName.find("tZq")!=string::npos||fileName.find("ST")!=string::npos ){	
        int htBin = 0;   int metBin = 0;
        if (HT>200 && HT<400) htBin = 1;
        if (HT>400 && HT<600) htBin = 2;
        if (HT>600 && HT<800) htBin = 3; 
        if (HT>800 && HT<1200) htBin = 4; 
        if (HT>1200 && HT<3000) htBin = 5; 
        if (Met_pt>200 && Met_pt<400) metBin = 1; 
        if (Met_pt>400 && Met_pt<700) metBin = 2; 
        if (Met_pt>700 && Met_pt<1600) metBin = 3; 
        if (htBin==0 || metBin==0){ 
           w_SF3=1; w_SF3Up=1; w_SF3Down=1;
        }  else {  
           w_SF3 = histoSF3->GetBinContent(htBin,metBin);
           w_SF3Up = histoSF3->GetBinContent(htBin,metBin)+ histoSF3->GetBinError(htBin,metBin);
           w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(htBin,metBin)- histoSF3->GetBinError(htBin,metBin)); 
        }
  }

}
*/

void TriggerSF(double Met_pt, double MHT, double &w_Trig, double &w_TrigUp, double &w_TrigDown){/*{{{*/
  int metBin = 0; int mhtBin = 0;
  if (Met_pt>0 && Met_pt<25)    metBin = 1;
  if (Met_pt>25 && Met_pt<50)   metBin = 2;
  if (Met_pt>50 && Met_pt<75)   metBin = 3;
  if (Met_pt>75 && Met_pt<100)  metBin = 4;
  if (Met_pt>100 && Met_pt<125) metBin = 5;
  if (Met_pt>125 && Met_pt<150) metBin = 6;
  if (Met_pt>150 && Met_pt<175) metBin = 7;
  if (Met_pt>175 && Met_pt<200) metBin = 8;
  if (Met_pt>200 && Met_pt<225) metBin = 9;
  if (Met_pt>225 && Met_pt<250) metBin = 10;
  if (Met_pt>250 && Met_pt<300) metBin = 11;
  if (Met_pt>300 && Met_pt<400) metBin = 12;
  if (Met_pt>400 && Met_pt<500) metBin = 13;
  if (Met_pt>500 && Met_pt<1000) metBin = 14;

  if (MHT>0 && MHT<25)    mhtBin = 1;
  if (MHT>25 && MHT<50)   mhtBin = 2;
  if (MHT>50 && MHT<75)   mhtBin = 3;
  if (MHT>75 && MHT<100)  mhtBin = 4;
  if (MHT>100 && MHT<125) mhtBin = 5;
  if (MHT>125 && MHT<150) mhtBin = 6;
  if (MHT>150 && MHT<175) mhtBin = 7;
  if (MHT>175 && MHT<200) mhtBin = 8;
  if (MHT>200 && MHT<225) mhtBin = 9;
  if (MHT>225 && MHT<250) mhtBin = 10;
  if (MHT>250 && MHT<300) mhtBin = 11;
  if (MHT>300 && MHT<400) mhtBin = 12;
  if (MHT>400 && MHT<500) mhtBin = 13;
  if (MHT>500 && MHT<1000) mhtBin = 14;

  if (metBin==0 || mhtBin==0){
     w_Trig = 1; w_TrigUp = 1; w_TrigDown = 1;
  }
   else {
     w_Trig     = histoTrig->GetBinContent(metBin,mhtBin);
     w_TrigUp   = histoTrig->GetBinContent(metBin,mhtBin)+ histoTrig->GetBinError(metBin,mhtBin);
     w_TrigDown = TMath::Max(0.,histoTrig->GetBinContent(metBin,mhtBin)- histoTrig->GetBinError(metBin,mhtBin));
  }
}/*}}}*/

double DeltaR(double eta1, double eta2, double phi1, double phi2){
  double deltaPhi = TMath::Abs(phi1-phi2);
  double deltaEta = eta1-eta2;
  if(deltaPhi > TMath::Pi()) deltaPhi = TMath::TwoPi() - deltaPhi;
  return TMath::Sqrt(deltaEta*deltaEta + deltaPhi*deltaPhi);
}

double DeltaPhi(double phi1, double phi2){/*{{{*/
  double deltaPhi = TMath::Abs(phi1-phi2);
  if(deltaPhi > TMath::Pi()) deltaPhi = TMath::TwoPi() - deltaPhi;
  return deltaPhi;
}/*}}}*/

double HTcalculator(vector<TLorentzVector> SelectedJets){/*{{{*/
  double HTprov=0;
  for (UInt_t j = 0; j < SelectedJets.size(); ++j){
    HTprov=HTprov+SelectedJets[j].Pt();//.Pt: the 3 vertor component, scalar
  }
  return HTprov;
}/*}}}*/

double MHTcalculator(vector<TLorentzVector> SelectedJets){/*{{{*/
  TLorentzVector SumJets;     SumJets.SetPtEtaPhiE(0, 0, 0, 0);
  double MHTprov=0;
  for (UInt_t j = 0; j < SelectedJets.size(); ++j){
    SumJets=SumJets+SelectedJets[j];
  }
  MHTprov= SumJets.Pt();
  return MHTprov;
}/*}}}*/

//
//
double InvariantMassCalculator(vector<TLorentzVector> SelectedJets){/*{{{*/
	double InM = 0;
	double SumE = 0;
	double MHT = MHTcalculator(SelectedJets);
    for (UInt_t j = 0; j < SelectedJets.size(); ++j){
		SumE = SumE+SelectedJets[j].E();
	}	
	InM = sqrt(SumE*SumE-MHT*MHT);
	return InM;
}/*}}}*/

/*double AplanarityCalcullator(vector<TLorentzVector> SelectedJets){
	double PtSquare = 0;
	double PtPt = -1;
	 for (UInt_t j = 0; j < SelectedJets.size(); ++j){
		PtSquare = PtSquare+SelcctedJets.Pt()*SelectedJets.Pt();

        for (UInt_t k = j+1; k < SelectedJets.size(); ++j){
				
		}

	 }	 
}	*/

double LeadingJetPtCal(vector<TLorentzVector> SelectedJets){/*{{{*/
    double Initial = -1;//assuming Pt all positive
    for (UInt_t j = 0; j < SelectedJets.size(); ++j){
	UInt_t k=j+1;
	if (SelectedJets[k].Pt()>Initial) Initial = SelectedJets[k].Pt();
    }
    return Initial;
}/*}}}*/

//double deltaRJetsCal(vector<TLorentzVector> SelectedJets){/*{{{*/
    //double init = 0;
    //double init2 = 0;
    //double deltaR = 0;
//    double Eta = 0;
//    double Eta2 = 0;
//    double Phi = 0;
//    double Phi2 = 0;
//    for (UInt_t j = 0; j < SelectedJets.size(); ++j){
//        for(UInt_t k = j+1; k< SelectedJets.size();++k){
//            Eta = SelectedJets[j].Eta();
//            Eta2 = SelectedJets[k].Eta();
//            Phi = SelectedJets[j].Phi();
//            Phi2 = SelectedJets[k].Phi();
//            deltaR = DeltaR(Eta,Eta2,Phi,Phi2);
//            if(deltaR > init) init = deltaR;
//        }
//        if (init>init2) init2 = init;
//    }
//    return init2;
//}/*}}}*/


void MinMaxdeltaRJetsCal(vector<TLorentzVector> SelectedJets,vector<double> &MinMaxDeltaR){/*{{{*/
    double init = 0;
    double init2 = 0;
    double initMin1 = 1000000;
    double initMin2 = 1000000;
    double deltaR = 0;
    double Eta = 0;
    double Eta2 = 0;
    double Phi = 0;
    double Phi2 = 0;
    if (SelectedJets.size() > 1){
        for (UInt_t j = 0; j < SelectedJets.size(); ++j){
            Eta = SelectedJets[j].Eta();
            Phi = SelectedJets[j].Phi();
            for(UInt_t k = j+1; k < SelectedJets.size();++k){
                Eta2 = SelectedJets[k].Eta();
                Phi2 = SelectedJets[k].Phi();
                deltaR = DeltaR(Eta,Eta2,Phi,Phi2);
                if(deltaR > init) init = deltaR;
                if(deltaR < initMin1) initMin1 = deltaR;
            }
            if (init>init2) init2 = init; 
            if (initMin1 < initMin2) initMin2 = initMin1;
        }
    }
    else {
        initMin2 = -1;//means have less than 2 jets
        init2 = -1;
    }
    MinMaxDeltaR.push_back(initMin2);// cout<<initMin2<<"  ";
    MinMaxDeltaR.push_back(init2);
   // cout<<MinMaxDeltaR[0];
}/*}}}*/

//void sort_jetPt(vector<TLorentzVector> SelectedJets,vector<int> &JetsPtSorted){/*{{{*/
void sort_jetPt(const vector<TLorentzVector> SelectedJets,vector<double> &JetsPtSorted){/*{{{*/
    UInt_t size = 0;
    size = SelectedJets.size();
    int k = 0;
    double JetsPt[size] ; 
    for (UInt_t j = 0; j < size; ++j){
        JetsPt[j] = SelectedJets[j].Pt();
    }
    sort(JetsPt, JetsPt+size);
    for (UInt_t i =0; i < size;++i){
        k = size-i-1;//-1 because starts with 0
        JetsPtSorted.push_back(JetsPt[k]);
    }
}/*}}}*/
//?what is the poit of this function when you can just give value?
void give_value_JetPtSorted(vector<double> JetsPtSorted,double &LeadingJetPt,double &SecondJetPt, double &ThirdJetPt, double &FourthJetPt, double &FitthJetPt,double &SixthJetPt, double &SeventhJetPt, double &EighthJetPt, double &NighthJetPt, double &TenthJetPt){/*{{{*/
    for(UInt_t i = 0; i < JetsPtSorted.size();++i){
        if(i == 0) LeadingJetPt = JetsPtSorted[i];
        if(i == 1) SecondJetPt = JetsPtSorted[i];
        if(i == 2) ThirdJetPt = JetsPtSorted[i];
        if(i == 3) FourthJetPt = JetsPtSorted[i];
        if(i == 4) FifthJetPt = JetsPtSorted[i];
        if(i == 5) SixthJetPt = JetsPtSorted[i];
        if(i == 6) SeventhJetPt = JetsPtSorted[i];
        if(i == 7) EighthJetPt = JetsPtSorted[i];
        if(i == 8) NighthJetPt = JetsPtSorted[i];
        if(i == 9) TenthJetPt = JetsPtSorted[i];
        
    }

}/*}}}*/

//?it seems that fileName doesn't occur in the function .
//
void branch(bool data,int selection, TTree *NewTree,TTree *NewTreeSB, string fileName){/*{{{*/
	//Change branch address, dealing with clone trees properly.	//copy the branch Jet_pt to b_Jet_pt
  Tree->SetBranchAddress("Jet_pt",   &Jet_pt_,   &b_Jet_pt);
  Tree->SetBranchAddress("Jet_eta",  &Jet_eta_,  &b_Jet_eta);
  Tree->SetBranchAddress("Jet_phi",  &Jet_phi_,  &b_Jet_phi);
  Tree->SetBranchAddress("Jet_mass", &Jet_mass_, &b_Jet_mass);
  Tree->SetBranchAddress("Jet_JesSF",&Jet_JesSF_,&b_Jet_JesSF);
  Tree->SetBranchAddress("Jet_JesSFup",&Jet_JesSFup_,&b_Jet_JesSFup);
  Tree->SetBranchAddress("Jet_JesSFdown",&Jet_JesSFdown_,&b_Jet_JesSFdown);
  Tree->SetBranchAddress("Jet_JerSF",&Jet_JerSF_,&b_Jet_JerSF);
  Tree->SetBranchAddress("Jet_JerSFup",&Jet_JerSFup_,&b_Jet_JerSFup);
  Tree->SetBranchAddress("Jet_JerSFdown",&Jet_JerSFdown_,&b_Jet_JerSFdown);
  Tree->SetBranchAddress("Jet_Uncorr_pt",   &Jet_Uncorr_pt_,   &b_Jet_Uncorr_pt);
  Tree->SetBranchAddress("Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags", &Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags_, &b_Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags);
  Tree->SetBranchAddress("Jet_pfDeepCSVBJetTags", &Jet_pfDeepCSVBJetTags_, &b_Jet_pfDeepCSVBJetTags);
  Tree->SetBranchAddress("Jet_pfDeepFlavourBJetTags", &Jet_pfDeepFlavourBJetTags_, &b_Jet_pfDeepFlavourBJetTags);
  Tree->SetBranchAddress("Jet_neutralHadEnergyFraction", &Jet_neutralHadEnergyFraction_, &b_Jet_neutralHadEnergyFraction);
  Tree->SetBranchAddress("Jet_chargedEmEnergyFraction", &Jet_chargedEmEnergyFraction_, &b_Jet_chargedEmEnergyFraction);
  Tree->SetBranchAddress("Jet_neutralEmEnergyFraction", &Jet_neutralEmEnergyFraction_, &b_Jet_neutralEmEnergyFraction);
  Tree->SetBranchAddress("Jet_numberOfConstituents", &Jet_numberOfConstituents_, &b_Jet_numberOfConstituents);
  Tree->SetBranchAddress("Jet_chargedHadronEnergyFraction", &Jet_chargedHadronEnergyFraction_, &b_Jet_chargedHadronEnergyFraction);
  Tree->SetBranchAddress("Jet_chargedMultiplicity", &Jet_chargedMultiplicity_, &b_Jet_chargedMultiplicity);
  if(!data) Tree->SetBranchAddress("Jet_hadronFlavour", &Jet_hadronFlavour_, &b_Jet_hadronFlavour);
  Tree->SetBranchAddress("Jet_muonEnergyFraction", &Jet_muonEnergyFraction_, &b_Jet_muonEnergyFraction);
/*
  Tree->SetBranchAddress("BoostedJet_pt",   &BoostedJet_pt_,   &b_BoostedJet_pt);
  Tree->SetBranchAddress("BoostedJet_Uncorr_pt",   &BoostedJet_Uncorr_pt_,   &b_BoostedJet_Uncorr_pt);
  Tree->SetBranchAddress("BoostedJet_softdrop_mass",   &BoostedJet_softdrop_mass_,   &b_BoostedJet_softdrop_mass);
  Tree->SetBranchAddress("BoostedJet_puppi_softdrop_mass",   &BoostedJet_puppi_softdrop_mass_,   &b_BoostedJet_puppi_softdrop_mass);
  Tree->SetBranchAddress("BoostedJet_JesSF",&BoostedJet_JesSF_,&b_BoostedJet_JesSF);
  Tree->SetBranchAddress("BoostedJet_JesSFup",&BoostedJet_JesSFup_,&b_BoostedJet_JesSFup);
  Tree->SetBranchAddress("BoostedJet_JesSFdown",&BoostedJet_JesSFdown_,&b_BoostedJet_JesSFdown);
  Tree->SetBranchAddress("BoostedJet_JerSF",&BoostedJet_JerSF_,&b_BoostedJet_JerSF);
  Tree->SetBranchAddress("BoostedJet_JerSFup",&BoostedJet_JerSFup_,&b_BoostedJet_JerSFup);
  Tree->SetBranchAddress("BoostedJet_JerSFdown",&BoostedJet_JerSFdown_,&b_BoostedJet_JerSFdown);
  Tree->SetBranchAddress("BoostedJet_eta",  &BoostedJet_eta_,  &b_BoostedJet_eta);
  Tree->SetBranchAddress("BoostedJet_phi",  &BoostedJet_phi_,  &b_BoostedJet_phi);
  Tree->SetBranchAddress("BoostedJet_mass", &BoostedJet_mass_, &b_BoostedJet_mass);
  Tree->SetBranchAddress("BoostedJet_neutralHadEnergyFraction", &BoostedJet_neutralHadEnergyFraction_, &b_BoostedJet_neutralHadEnergyFraction);
  Tree->SetBranchAddress("BoostedJet_neutralEmEnergyFraction", &BoostedJet_neutralEmEnergyFraction_, &b_BoostedJet_neutralEmEnergyFraction);
  Tree->SetBranchAddress("BoostedJet_chargedEmEnergyFraction", &BoostedJet_chargedEmEnergyFraction_, &b_BoostedJet_chargedEmEnergyFraction);
  Tree->SetBranchAddress("BoostedJet_numberOfConstituents", &BoostedJet_numberOfConstituents_, &b_BoostedJet_numberOfConstituents);
  Tree->SetBranchAddress("BoostedJet_chargedHadronEnergyFraction", &BoostedJet_chargedHadronEnergyFraction_, &b_BoostedJet_chargedHadronEnergyFraction);
  Tree->SetBranchAddress("BoostedJet_chargedMultiplicity", &BoostedJet_chargedMultiplicity_, &b_BoostedJet_chargedMultiplicity);
  Tree->SetBranchAddress("BoostedJet_puppi_tau1",         &BoostedJet_puppi_tau1_,         &b_BoostedJet_puppi_tau1);
  Tree->SetBranchAddress("BoostedJet_puppi_tau2",         &BoostedJet_puppi_tau2_,         &b_BoostedJet_puppi_tau2);
  Tree->SetBranchAddress("BoostedJet_puppi_tau3",         &BoostedJet_puppi_tau3_,         &b_BoostedJet_puppi_tau3);
  Tree->SetBranchAddress("BoostedJet_tau1",         &BoostedJet_tau1_,         &b_BoostedJet_tau1);
  Tree->SetBranchAddress("BoostedJet_tau2",         &BoostedJet_tau2_,         &b_BoostedJet_tau2);
  Tree->SetBranchAddress("BoostedJet_tau3",         &BoostedJet_tau3_,         &b_BoostedJet_tau3);
  Tree->SetBranchAddress("BoostedJet_pruned_mass",  &BoostedJet_pruned_mass_,  &b_BoostedJet_pruned_mass);
  */
  Tree->SetBranchAddress("patElectron_pt",&patElectron_pt_,&b_patElectron_pt);
  Tree->SetBranchAddress("patElectron_eta",&patElectron_eta_,&b_patElectron_eta);
  Tree->SetBranchAddress("patElectron_phi",&patElectron_phi_,&b_patElectron_phi);
  Tree->SetBranchAddress("patElectron_energy",&patElectron_energy_,&b_patElectron_energy);
  Tree->SetBranchAddress("patElectron_SCeta",&patElectron_SCeta_,&b_patElectron_SCeta);
  Tree->SetBranchAddress("patElectron_charge",&patElectron_charge_,&b_patElectron_charge);
  Tree->SetBranchAddress("patElectron_Et",&patElectron_Et_,&b_patElectron_Et);
  Tree->SetBranchAddress("patElectron_pdgId",&patElectron_pdgId_,&b_patElectron_pdgId);
  Tree->SetBranchAddress("patElectron_relIsoDeltaBeta",&patElectron_relIsoDeltaBeta_,&b_patElectron_relIsoDeltaBeta);
  Tree->SetBranchAddress("patElectron_relIsoRhoEA_Update",&patElectron_relIsoRhoEA_Update_,&b_patElectron_relIsoRhoEA_Update);
  if(!data) Tree->SetBranchAddress("patElectron_gen_pdgId", &patElectron_gen_pdgId_, &b_patElectron_gen_pdgId);
  if(!data) Tree->SetBranchAddress("patElectron_gen_isDirectPromptTauDecayProductFinalState", &patElectron_gen_isDirectPromptTauDecayProductFinalState_, &b_patElectron_gen_isDirectPromptTauDecayProductFinalState);
//  Tree->SetBranchAddress("",&_,&b_);
  Tree->SetBranchAddress("patElectron_mvaEleID_Fall17_noIso_V2_wp80",&patElectron_mvaEleID_Fall17_noIso_V2_wp80_, &b_patElectron_mvaEleID_Fall17_noIso_V2_wp80);
  Tree->SetBranchAddress("patElectron_mvaEleID_Fall17_iso_V2_wp80",&patElectron_mvaEleID_Fall17_iso_V2_wp80_,&b_patElectron_mvaEleID_Fall17_iso_V2_wp80);
  Tree->SetBranchAddress("patElectron_mvaEleID_Fall17_iso_V2_wp90",&patElectron_mvaEleID_Fall17_iso_V2_wp90_,&b_patElectron_mvaEleID_Fall17_iso_V2_wp90);
  Tree->SetBranchAddress("patElectron_mvaEleID_Fall17_noIso_V2_wp90",&patElectron_mvaEleID_Fall17_noIso_V2_wp90_,&b_patElectron_mvaEleID_Fall17_noIso_V2_wp90);
  Tree->SetBranchAddress("patElectron_mvaEleID_Fall17_iso_V2_wpLoose",&patElectron_mvaEleID_Fall17_iso_V2_wpLoose_,&b_patElectron_mvaEleID_Fall17_iso_V2_wpLoose);
  Tree->SetBranchAddress("patElectron_mvaEleID_Fall17_noIso_V2_wpLoose",&patElectron_mvaEleID_Fall17_noIso_V2_wpLoose_,&b_patElectron_mvaEleID_Fall17_noIso_V2_wpLoose);
  Tree->SetBranchAddress("patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Values",&patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Values_,&b_patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Values);
  Tree->SetBranchAddress("patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Categories",&patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Categories_,&b_patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Categories);
  Tree->SetBranchAddress("patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Values",&patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Values_,&b_patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Values);
  Tree->SetBranchAddress("patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Categories",&patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Categories_,&b_patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Categories);
  Tree->SetBranchAddress("patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp80",&patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp80_,&b_patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp80);
  Tree->SetBranchAddress("patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp90",&patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp90_,&b_patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp90);
  Tree->SetBranchAddress("patElectron_MVAValue_ElectronMVAEstimatorRun2Spring16GeneralPurposeV1",&patElectron_MVAValue_ElectronMVAEstimatorRun2Spring16GeneralPurposeV1_,&b_patElectron_MVAValue_ElectronMVAEstimatorRun2Spring16GeneralPurposeV1);
  Tree->SetBranchAddress("patElectron_cutBasedElectronID_Fall17_94X_V2_loose",&patElectron_cutBasedElectronID_Fall17_94X_V2_loose_,&b_patElectron_cutBasedElectronID_Fall17_94X_V2_loose);
  Tree->SetBranchAddress("patElectron_cutBasedElectronID_Fall17_94X_V2_medium",&patElectron_cutBasedElectronID_Fall17_94X_V2_medium_,&b_patElectron_cutBasedElectronID_Fall17_94X_V2_medium);
  Tree->SetBranchAddress("patElectron_cutBasedElectronID_Fall17_94X_V2_tight",&patElectron_cutBasedElectronID_Fall17_94X_V2_tight_,&b_patElectron_cutBasedElectronID_Fall17_94X_V2_tight);
  Tree->SetBranchAddress("patElectron_cutBasedElectronID_Fall17_94X_V2_veto",&patElectron_cutBasedElectronID_Fall17_94X_V2_veto_,&b_patElectron_cutBasedElectronID_Fall17_94X_V2_veto);
  Tree->SetBranchAddress("patElectron_heepElectronID_HEEPV70",&patElectron_heepElectronID_HEEPV70_,&b_patElectron_heepElectronID_HEEPV70);
 // Tree->SetBranchAddress("",&_,&b_);
 /* Tree->SetBranchAddress("patElectron_isPassVeto",&patElectron_isPassVeto_,&b_patElectron_isPassVeto);          
  Tree->SetBranchAddress("patElectron_isPassLoose",&patElectron_isPassLoose_,&b_patElectron_isPassLoose);
  Tree->SetBranchAddress("patElectron_isPassMedium",&patElectron_isPassMedium_,&b_patElectron_isPassMedium);
  Tree->SetBranchAddress("patElectron_isPassTight",&patElectron_isPassTight_,&b_patElectron_isPassTight);
  Tree->SetBranchAddress("patElectron_isPassHEEPId",&patElectron_isPassHEEPId_,&b_patElectron_isPassHEEPId);*/
  Tree->SetBranchAddress("patElectron_passConversionVeto",&patElectron_passConversionVeto_,&b_patElectron_passConversionVeto); 
  Tree->SetBranchAddress("patElectron_inCrack",&patElectron_inCrack_,&b_patElectron_inCrack);
  Tree->SetBranchAddress("patElectron_isMatchedToTrigger",&patElectron_isMatchedToTrigger_,&b_patElectron_isMatchedToTrigger);
  Tree->SetBranchAddress("Muon_pt",&Muon_pt_,&b_Muon_pt);
  Tree->SetBranchAddress("Muon_eta",&Muon_eta_,&b_Muon_eta);
  Tree->SetBranchAddress("Muon_phi",&Muon_phi_,&b_Muon_phi);
  Tree->SetBranchAddress("Muon_energy",&Muon_energy_,&b_Muon_energy);
  Tree->SetBranchAddress("Muon_charge",&Muon_charge_,&b_Muon_charge);
  Tree->SetBranchAddress("Muon_tight",&Muon_tight_,&b_Muon_tight);
  Tree->SetBranchAddress("Muon_medium",&Muon_medium_,&b_Muon_medium);
  Tree->SetBranchAddress("Muon_loose",&Muon_loose_,&b_Muon_loose);
  Tree->SetBranchAddress("Met_type1PF_pt",          &Met_type1PF_pt_,          &b_Met_type1PF_pt);
  Tree->SetBranchAddress("Met_type1PF_phi",         &Met_type1PF_phi_,         &b_Met_type1PF_phi);
  Tree->SetBranchAddress("Met_type1PF_sumEt",         &Met_type1PF_sumEt_,         &b_Met_type1PF_sumEt);
  Tree->SetBranchAddress("Muon_relIsoDeltaBetaR04",&Muon_relIsoDeltaBetaR04_,&b_Muon_relIsoDeltaBetaR04);
  Tree->SetBranchAddress("Muon_miniIsoRel",         &Muon_miniIsoRel_,         &b_Muon_miniIsoRel);
  Tree->SetBranchAddress("Muon_ptrel",         &Muon_ptrel_,         &b_Muon_ptrel);
  Tree->SetBranchAddress("Muon_jetptratio",         &Muon_jetptratio_,         &b_Muon_jetptratio);
  Tree->SetBranchAddress("Muon_jetptratioV2",         &Muon_jetptratioV2_,         &b_Muon_jetptratioV2);
  Tree->SetBranchAddress("Muon_isMatchedToTrigger",&Muon_isMatchedToTrigger_,&b_Muon_isMatchedToTrigger);

  Tree->SetBranchAddress("TopTagger_type",&TopTagger_type_,&b_TopTagger_type);
  Tree->SetBranchAddress("TopTagger_discriminator",&TopTagger_discriminator_,&b_TopTagger_discriminator);
  Tree->SetBranchAddress("TopTagger_jet1Idx",&TopTagger_jet1Idx_,&b_TopTagger_jet1Idx);
  Tree->SetBranchAddress("TopTagger_jet2Idx",&TopTagger_jet2Idx_,&b_TopTagger_jet2Idx);
  Tree->SetBranchAddress("TopTagger_jet3Idx",&TopTagger_jet3Idx_,&b_TopTagger_jet3Idx);

  Tree->SetBranchAddress("Tau_pt",&Tau_pt_,&b_Tau_pt);
  Tree->SetBranchAddress("Tau_eta",&Tau_eta_,&b_Tau_eta);
  Tree->SetBranchAddress("Tau_leadChargedCandDz_pv",&Tau_leadChargedCandDz_pv_,&b_Tau_leadChargedCandDz_pv);
  Tree->SetBranchAddress("Tau_packedLeadTauCand_dz",&Tau_packedLeadTauCand_dz_,&b_Tau_packedLeadTauCand_dz);
  Tree->SetBranchAddress("Tau_phi",&Tau_phi_,&b_Tau_phi);
  Tree->SetBranchAddress("Tau_energy",&Tau_energy_,&b_Tau_energy);
  Tree->SetBranchAddress("Tau_px",&Tau_px_,&b_Tau_px);
  Tree->SetBranchAddress("Tau_py",&Tau_py_,&b_Tau_py);
  Tree->SetBranchAddress("Tau_pz",&Tau_pz_,&b_Tau_pz);
  Tree->SetBranchAddress("Tau_p",&Tau_p_,&b_Tau_p);
/*  Tree->SetBranchAddress("Tau_leadChargedCandPt",&Tau_leadChargedCandPt_,&b_Tau_leadChargedCandPt);
  Tree->SetBranchAddress("Tau_leadChargedCandEta",&Tau_leadChargedCandEta_,&b_Tau_leadChargedCandEta);
  Tree->SetBranchAddress("Tau_leadChargedCandPhi",&Tau_leadChargedCandPhi_,&b_Tau_leadChargedCandPhi);
  Tree->SetBranchAddress("Tau_leadChargedCandE",&Tau_leadChargedCandE_,&b_Tau_leadChargedCandE);*/
  Tree->SetBranchAddress("Tau_charge",&Tau_charge_,&b_Tau_charge);
  Tree->SetBranchAddress("Tau_decayModeFinding",&Tau_decayModeFinding_,&b_Tau_decayModeFinding);
  Tree->SetBranchAddress("Tau_decayModeFindingNewDMs",&Tau_decayModeFindingNewDMs_,&b_Tau_decayModeFindingNewDMs);
  Tree->SetBranchAddress("Tau_decayMode",&Tau_decayMode_,&b_Tau_decayMode);
  Tree->SetBranchAddress("Tau_againstMuonLoose3",&Tau_againstMuonLoose3_,&b_Tau_againstMuonLoose3);
  Tree->SetBranchAddress("Tau_againstMuonTight3",&Tau_againstMuonTight3_,&b_Tau_againstMuonTight3);
/*  Tree->SetBranchAddress("Tau_againstElectronVLooseMVA6",&Tau_againstElectronVLooseMVA6_,&b_Tau_againstElectronVLooseMVA6);
  Tree->SetBranchAddress("Tau_againstElectronLooseMVA6",&Tau_againstElectronLooseMVA6_,&b_Tau_againstElectronLooseMVA6);
  Tree->SetBranchAddress("Tau_againstElectronMediumMVA6",&Tau_againstElectronMediumMVA6_,&b_Tau_againstElectronMediumMVA6);
  Tree->SetBranchAddress("Tau_againstElectronTightMVA6",&Tau_againstElectronTightMVA6_,&b_Tau_againstElectronTightMVA6);
  Tree->SetBranchAddress("Tau_chargedIsoPtSum",&Tau_chargedIsoPtSum_,&b_Tau_chargedIsoPtSum);
  Tree->SetBranchAddress("Tau_neutralIsoPtSum",&Tau_neutralIsoPtSum_,&b_Tau_neutralIsoPtSum);
  Tree->SetBranchAddress("Tau_puCorrPtSum",&Tau_puCorrPtSum_,&b_Tau_puCorrPtSum);*/
/*  Tree->SetBranchAddress("Tau_byLooseIsolationMVArun2v1DBdR03oldDMwLT",&Tau_byLooseIsolationMVArun2v1DBdR03oldDMwLT_,&b_Tau_byLooseIsolationMVArun2v1DBdR03oldDMwLT);
  Tree->SetBranchAddress("Tau_byMediumIsolationMVArun2v1DBdR03oldDMwLT",&Tau_byMediumIsolationMVArun2v1DBdR03oldDMwLT_,&b_Tau_byMediumIsolationMVArun2v1DBdR03oldDMwLT);
  Tree->SetBranchAddress("Tau_byIsolationMVArun2017v2DBoldDMdR0p3wLTraw2017",&Tau_byIsolationMVArun2017v2DBoldDMdR0p3wLTraw2017_,&b_Tau_byIsolationMVArun2017v2DBoldDMdR0p3wLTraw2017);
  Tree->SetBranchAddress("Tau_byVVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017",&Tau_byVVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_,&b_Tau_byVVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017);
  Tree->SetBranchAddress("Tau_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017",&Tau_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017_,&b_Tau_byVLooseIsolationMVArun2017v2DBoldDMdR0p3wLT2017);*/
  Tree->SetBranchAddress("Tau_byDeepTau2017v2p1VSjetraw",&Tau_byDeepTau2017v2p1VSjetraw_,&b_Tau_byDeepTau2017v2p1VSjetraw);
  Tree->SetBranchAddress("Tau_byVVVLooseDeepTau2017v2p1VSjet",&Tau_byVVVLooseDeepTau2017v2p1VSjet_,&b_Tau_byVVVLooseDeepTau2017v2p1VSjet);
  Tree->SetBranchAddress("Tau_byVVLooseDeepTau2017v2p1VSjet",&Tau_byVVLooseDeepTau2017v2p1VSjet_,&b_Tau_byVVLooseDeepTau2017v2p1VSjet);
  Tree->SetBranchAddress("Tau_byVLooseDeepTau2017v2p1VSjet",&Tau_byVLooseDeepTau2017v2p1VSjet_,&b_Tau_byVLooseDeepTau2017v2p1VSjet);
  Tree->SetBranchAddress("Tau_byLooseDeepTau2017v2p1VSjet",&Tau_byLooseDeepTau2017v2p1VSjet_,&b_Tau_byLooseDeepTau2017v2p1VSjet);
  Tree->SetBranchAddress("Tau_byMediumDeepTau2017v2p1VSjet",&Tau_byMediumDeepTau2017v2p1VSjet_,&b_Tau_byMediumDeepTau2017v2p1VSjet);
  Tree->SetBranchAddress("Tau_byTightDeepTau2017v2p1VSjet",&Tau_byTightDeepTau2017v2p1VSjet_,&b_Tau_byTightDeepTau2017v2p1VSjet);
  Tree->SetBranchAddress("Tau_byVTightDeepTau2017v2p1VSjet",&Tau_byVTightDeepTau2017v2p1VSjet_,&b_Tau_byVTightDeepTau2017v2p1VSjet);
  Tree->SetBranchAddress("Tau_byVVTightDeepTau2017v2p1VSjet",&Tau_byVVTightDeepTau2017v2p1VSjet_,&b_Tau_byVVTightDeepTau2017v2p1VSjet);
  Tree->SetBranchAddress("Tau_byDeepTau2017v2p1VSmuraw",&Tau_byDeepTau2017v2p1VSmuraw_,&b_Tau_byDeepTau2017v2p1VSmuraw);
  Tree->SetBranchAddress("Tau_byVLooseDeepTau2017v2p1VSmu",&Tau_byVLooseDeepTau2017v2p1VSmu_,&b_Tau_byVLooseDeepTau2017v2p1VSmu);
  Tree->SetBranchAddress("Tau_byLooseDeepTau2017v2p1VSmu",&Tau_byLooseDeepTau2017v2p1VSmu_,&b_Tau_byLooseDeepTau2017v2p1VSmu);
  Tree->SetBranchAddress("Tau_byMediumDeepTau2017v2p1VSmu",&Tau_byMediumDeepTau2017v2p1VSmu_,&b_Tau_byMediumDeepTau2017v2p1VSmu);
  Tree->SetBranchAddress("Tau_byTightDeepTau2017v2p1VSmu",&Tau_byTightDeepTau2017v2p1VSmu_,&b_Tau_byTightDeepTau2017v2p1VSmu);
  Tree->SetBranchAddress("Tau_byDeepTau2017v2p1VSeraw",&Tau_byDeepTau2017v2p1VSeraw_,&b_Tau_byDeepTau2017v2p1VSeraw);
  Tree->SetBranchAddress("Tau_byVVVLooseDeepTau2017v2p1VSe",&Tau_byVVVLooseDeepTau2017v2p1VSe_,&b_Tau_byVVVLooseDeepTau2017v2p1VSe);
  Tree->SetBranchAddress("Tau_byVVLooseDeepTau2017v2p1VSe",&Tau_byVVLooseDeepTau2017v2p1VSe_,&b_Tau_byVVLooseDeepTau2017v2p1VSe);
  Tree->SetBranchAddress("Tau_byVLooseDeepTau2017v2p1VSe",&Tau_byVLooseDeepTau2017v2p1VSe_,&b_Tau_byVLooseDeepTau2017v2p1VSe);
  Tree->SetBranchAddress("Tau_byLooseDeepTau2017v2p1VSe",&Tau_byLooseDeepTau2017v2p1VSe_,&b_Tau_byLooseDeepTau2017v2p1VSe);
  Tree->SetBranchAddress("Tau_byMediumDeepTau2017v2p1VSe",&Tau_byMediumDeepTau2017v2p1VSe_,&b_Tau_byMediumDeepTau2017v2p1VSe);
  Tree->SetBranchAddress("Tau_byTightDeepTau2017v2p1VSe",&Tau_byTightDeepTau2017v2p1VSe_,&b_Tau_byTightDeepTau2017v2p1VSe);
  Tree->SetBranchAddress("Tau_byVTightDeepTau2017v2p1VSe",&Tau_byVTightDeepTau2017v2p1VSe_,&b_Tau_byVTightDeepTau2017v2p1VSe);
  Tree->SetBranchAddress("Tau_byVVTightDeepTau2017v2p1VSe",&Tau_byVVTightDeepTau2017v2p1VSe_,&b_Tau_byVVTightDeepTau2017v2p1VSe);
//  Tree->SetBranchAddress("",&_,&b_);

  Tree->SetBranchAddress("Flag_goodVertices",&Flag_goodVertices_,&b_Flag_goodVertices);
  Tree->SetBranchAddress("Flag_globalSuperTightHalo2016Filter",&Flag_globalSuperTightHalo2016Filter_,&b_Flag_globalSuperTightHalo2016Filter);
  //Tree->SetBranchAddress("Flag_CSCTightHalo2015Filter",&Flag_CSCTightHalo2015Filter_,&b_Flag_CSCTightHalo2015Filter);
  Tree->SetBranchAddress("Flag_HBHENoiseFilter",&Flag_HBHENoiseFilter_,&b_Flag_HBHENoiseFilter);
  Tree->SetBranchAddress("Flag_HBHENoiseIsoFilter",&Flag_HBHENoiseIsoFilter_,&b_Flag_HBHENoiseIsoFilter);
  Tree->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter",&Flag_EcalDeadCellTriggerPrimitiveFilter_,&b_Flag_EcalDeadCellTriggerPrimitiveFilter);
  Tree->SetBranchAddress("Flag_BadPFMuonFilter",&Flag_BadPFMuonFilter_,&b_Flag_BadPFMuonFilter);
  Tree->SetBranchAddress("Flag_BadChargedCandidateFilter",&Flag_BadChargedCandidateFilter_,&b_Flag_BadChargedCandidateFilter);
//  Tree->SetBranchAddress("Flag_ecalBadCalibReducedMINIAODFilter",&Flag_ecalBadCalibReducedMINIAODFilter_,&b_Flag_ecalBadCalibReducedMINIAODFilter);
  Tree->SetBranchAddress("Flag_eeBadScFilter",&Flag_eeBadScFilter_,&b_Flag_eeBadScFilter);
  Tree->SetBranchAddress("Flag_METFilters",&Flag_METFilters_,&b_Flag_METFilters);

  Tree->SetBranchAddress("HLT_DoubleEle33_CaloIdL_MW",&HLT_DoubleEle33_CaloIdL_MW_,&b_HLT_DoubleEle33_CaloIdL_MW);
   Tree->SetBranchAddress("HLT_Mu50",&HLT_Mu50_,&b_HLT_Mu50);
   Tree->SetBranchAddress("HLT_TkMu50",&HLT_TkMu50_,&b_HLT_TkMu50);
  //Tree->SetBranchAddress("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight_, &b_HLT_PFHT500_PFMET100_PFMHT100_IDTight);
  //Tree->SetBranchAddress("HLT_PFHT700_PFMET85_PFMHT85_IDTight", &HLT_PFHT700_PFMET85_PFMHT85_IDTight_, &b_HLT_PFHT700_PFMET85_PFMHT85_IDTight);
  //Tree->SetBranchAddress("HLT_PFHT800_PFMET75_PFMHT75_IDTight", &HLT_PFHT800_PFMET75_PFMHT75_IDTight_, &b_HLT_PFHT800_PFMET75_PFMHT75_IDTight);
//	Tree->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight_, &b_HLT_PFMET120_PFMHT120_IDTight);
//	Tree->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_, &b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
  //Tree->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_,  &b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight);
  //Tree->SetBranchAddress("HLT_CaloJet500_NoJetID", &HLT_CaloJet500_NoJetID_, &b_HLT_CaloJet500_NoJetID);
  //Tree->SetBranchAddress("HLT_AK8PFJet500", &HLT_AK8PFJet500_,   &b_HLT_AK8PFJet500);
  // Tree->SetBranchAddress("HLT_PFJet500", &HLT_PFJet500_,         &b_HLT_PFJet500);
//
//                                 add.
  Tree->SetBranchAddress("HLT_PFHT900", &HLT_PFHT900_,         &b_HLT_PFHT900);
  Tree->SetBranchAddress("HLT_PFHT450_SixJet40_BTagCSV_p056", &HLT_PFHT450_SixJet40_BTagCSV_p056_,         &b_HLT_PFHT450_SixJet40_BTagCSV_p056);
  Tree->SetBranchAddress("HLT_PFHT400_SixJet30_DoubleBTagCSV_p056", &HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_,         &b_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056);
//
//
  Tree->SetBranchAddress("nBestVtx",&nBestVtx_,&b_nBestVtx);
  Tree->SetBranchAddress("PUWeight",&PUWeight_,&b_PUWeight);
  //Tree->SetBranchAddress("PUWeightUP",&PUWeightUP_,&b_PUWeightUP);
  //Tree->SetBranchAddress("PUWeightDOWN",&PUWeightDOWN_,&b_PUWeightDOWN);
  Tree->SetBranchAddress("EVENT_event",&EVENT_event_,&b_EVENT_event);
  Tree->SetBranchAddress("EVENT_run",&EVENT_run_,&b_EVENT_run);
  Tree->SetBranchAddress("EVENT_lumiBlock",&EVENT_lumiBlock_,&b_EVENT_lumiBlock);
  Tree->SetBranchAddress("EVENT_genHT",&EVENT_genHT_,&b_EVENT_genHT);
	//what is Gen? what does data do?
  if(!data) Tree->SetBranchAddress("Gen_pt",&Gen_pt_,&b_Gen_pt);
  if(!data) Tree->SetBranchAddress("Gen_eta",&Gen_eta_,&b_Gen_eta);
  if(!data) Tree->SetBranchAddress("Gen_phi",&Gen_phi_,&b_Gen_phi);
  if(!data) Tree->SetBranchAddress("Gen_pdg_id",&Gen_pdg_id_,&b_Gen_pdg_id);
  if(!data) Tree->SetBranchAddress("Gen_motherpdg_id",&Gen_motherpdg_id_,&b_Gen_motherpdg_id);
//  if(!data) Tree->SetBranchAddress("Gen_charge",&Gen_charge_,&b_Gen_charge);
//  if(!data) Tree->SetBranchAddress("",&,&);
//  if(!data) Tree->SetBranchAddress("",&,&);
	//?what is these?
  Tree->SetBranchAddress("EVENT_genWeight",&genWeight_,&b_genWeight);
  Tree->SetBranchAddress("EVENT_genWeights",&genWeights_,&b_genWeights);
  Tree->SetBranchAddress("EVENT_prefireWeight",&EVENT_prefireWeight_,&b_EVENT_prefireWeight);
  Tree->SetBranchAddress("EVENT_prefireWeightUp",&EVENT_prefireWeightUp_,&b_EVENT_prefireWeightUp);
  Tree->SetBranchAddress("EVENT_prefireWeightDown",&EVENT_prefireWeightDown_,&b_EVENT_prefireWeightDown);
  NewTree->Branch("channel_1Tau0L",         &channel_1Tau0L,         "channel_1Tau0L/I"         );
  NewTree->Branch("channel_1Tau1L",         &channel_1Tau1L,         "channel_1Tau1L/I"         );
  NewTree->Branch("channel_1Tau2OS",         &channel_1Tau2OS,         "channel_1Tau2OS/I"         );
  NewTree->Branch("channel_1Tau2SS",         &channel_1Tau2SS,         "channel_1Tau2SS/I"         );
  NewTree->Branch("channel_1Tau3L",         &channel_1Tau3L,         "channel_1Tau3L/I"         );
  NewTree->Branch("channel_2Tau0L",         &channel_2Tau0L,         "channel_2Tau0L/I"         );
  NewTree->Branch("channel_2Tau1L",         &channel_2Tau1L,         "channel_2Tau1L/I"         );
  NewTree->Branch("channel_2Tau2SS",         &channel_2Tau2SS,         "channel_2Tau2SS/I"         );
  NewTree->Branch("channel_2Tau2OS",         &channel_2Tau2OS,         "channel_2Tau2OS/I"         );

  NewTree->Branch("TopMass",           &TopMass,           "TopMass/D"           );
  NewTree->Branch("TopMassMerged",     &TopMassMerged,     "TopMassMerged/D"     );
  NewTree->Branch("TopMassPartial",    &TopMassPartial,    "TopMassPartial/D"    );
  NewTree->Branch("TopMassResolved",   &TopMassResolved,   "TopMassResolved/D"   );
  NewTree->Branch("TopPt",             &TopPt,             "TopPt/D"             );
  NewTree->Branch("TopPtMerged",       &TopPtMerged,       "TopPtMerged/D"       );
  NewTree->Branch("TopPtPartial",      &TopPtPartial,      "TopPtPartial/D"      );
  NewTree->Branch("TopPtResolved",     &TopPtResolved,     "TopPtResolved/D"     );
  NewTree->Branch("TopEta",            &TopEta,            "TopEta/D"            );
  NewTree->Branch("TopEtaMerged",      &TopEtaMerged,      "TopEtaMerged/D"      );
  NewTree->Branch("TopEtaPartial",     &TopEtaPartial,     "TopEtaPartial/D"     );
  NewTree->Branch("TopEtaResolved",    &TopEtaResolved,    "TopEtaResolved/D"    );
  NewTree->Branch("TopPhi",            &TopPhi,            "TopPhi/D"            );
  NewTree->Branch("TopPhiMerged",      &TopPhiMerged,      "TopPhiMerged/D"      );
  NewTree->Branch("TopPhiPartial",     &TopPhiPartial,     "TopPhiPartial/D"     );
  NewTree->Branch("TopPhiResolved",    &TopPhiResolved,    "TopPhiResolved/D"    );
  NewTree->Branch("WMassResolved1",    &WMassResolved1,    "WMassResolved1/D"    );
  NewTree->Branch("WMassResolved2",    &WMassResolved2,    "WMassResolved2/D"    );
  NewTree->Branch("WMassResolved3",    &WMassResolved3,    "WMassResolved3/D"    );
  NewTree->Branch("BMass",             &BMass,             "BMass/D"             );
  NewTree->Branch("BCSV",              &BCSV,              "BCSV/D"              );
  NewTree->Branch("BPt",               &BPt,               "BPt/D"               );
  NewTree->Branch("BEta",              &BEta,              "BEta/D"              );
  NewTree->Branch("BPhi",              &BPhi,              "BPhi/D"              );
  NewTree->Branch("ZMass",             &ZMass,             "ZMass/D"             );
  NewTree->Branch("ZPt",               &ZPt,               "ZPt/D"               );
  NewTree->Branch("ZEta",              &ZEta,              "ZEta/D"              );
  NewTree->Branch("ZPhi",              &ZPhi,              "ZPhi/D"              );
/*   NewTree->Branch("TprimeMass",        &TprimeMass,        "TprimeMass/D"        );
   NewTree->Branch("TprimePt",          &TprimePt,          "TprimePt/D"          );
   NewTree->Branch("TprimeEta",         &TprimeEta,         "TprimeEta/D"         );
   NewTree->Branch("TprimePhi",         &TprimePhi,         "TprimePhi/D"         );
   NewTree->Branch("TprimeResolvedMass",&TprimeResolvedMass,"TprimeResolvedMass/D");
   NewTree->Branch("TprimeResolvedPt",  &TprimeResolvedPt,  "TprimeResolvedPt/D"  );
   NewTree->Branch("TprimeResolvedEta", &TprimeResolvedEta, "TprimeResolvedEta/D" );
   NewTree->Branch("TprimeResolvedPhi", &TprimeResolvedPhi, "TprimeResolvedPhi/D" );
   NewTree->Branch("TprimePartialMass", &TprimePartialMass, "TprimePartialMass/D" );
   NewTree->Branch("TprimePartialPt",   &TprimePartialPt,   "TprimePartialPt/D"   );
   NewTree->Branch("TprimePartialEta",  &TprimePartialEta,  "TprimePartialEta/D"  );
   NewTree->Branch("TprimePartialPhi",  &TprimePartialPhi,  "TprimePartialPhi/D"  );
   NewTree->Branch("TprimeMergedMass",  &TprimeMergedMass,  "TprimeMergedMass/D"  );
   NewTree->Branch("TprimeMergedPt",    &TprimeMergedPt,    "TprimeMergedPt/D"    );
   NewTree->Branch("TprimeMergedEta",   &TprimeMergedEta,   "TprimeMergedEta/D"   );
 NewTree->Branch("TprimeMergedPhi",   &TprimeMergedPhi,   "TprimeMergedPhi/D"   );*/
 NewTree->Branch("Electron1Pt",       &Electron1Pt,       "Electron1Pt/D"       );
  //give no value of Electron1Pt other than -99
  NewTree->Branch("Electron2Pt",       &Electron2Pt,       "Electron2Pt/D"       );
  NewTree->Branch("Electron1E",        &Electron1E,        "Electron1E/D"        );
  NewTree->Branch("Electron2E",        &Electron2E,        "Electron2E/D"        );
  NewTree->Branch("Muon1Iso",          &Muon1Iso,          "Muon1Iso/D"          );
  NewTree->Branch("Muon2Iso",          &Muon2Iso,          "Muon2Iso/D"          );
  NewTree->Branch("Muon1Pt",           &Muon1Pt,           "Muon1Pt/D"           );
  NewTree->Branch("Muon2Pt",           &Muon2Pt,           "Muon2Pt/D"           );
  NewTree->Branch("Jet1ForwardEta",    &Jet1ForwardEta,    "Jet1ForwardEta/D"    );
  NewTree->Branch("Jet2ForwardEta",    &Jet2ForwardEta,    "Jet2ForwardEta/D"    );
  NewTree->Branch("Jet3ForwardEta",    &Jet3ForwardEta,    "Jet3ForwardEta/D"    );
  NewTree->Branch("Jet1ForwardPt",     &Jet1ForwardPt,     "Jet1ForwardPt/D"     );
  NewTree->Branch("Jet2ForwardPt",     &Jet2ForwardPt,     "Jet2ForwardPt/D"     );
  NewTree->Branch("Jet3ForwardPt",     &Jet3ForwardPt,     "Jet3ForwardPt/D"     );
  NewTree->Branch("Jet1ResolvedPt",    &Jet1ResolvedPt,    "Jet1ResolvedPt/D"    );
 NewTree->Branch("Jet2ResolvedPt",    &Jet2ResolvedPt,    "Jet2ResolvedPt/D"    );
 NewTree->Branch("Jet3ResolvedPt",    &Jet3ResolvedPt,    "Jet3ResolvedPt/D"    );
 NewTree->Branch("Jet1PartialPt",     &Jet1PartialPt,     "Jet1PartialPt/D"     );
  NewTree->Branch("Jet2PartialPt",     &Jet2PartialPt,     "Jet2PartialPt/D"     );
  NewTree->Branch("Jet1MergedPt",      &Jet1MergedPt,      "Jet1MergedPt/D"      );
  NewTree->Branch("Electron1Eta",      &Electron1Eta,      "Electron1Eta/D"      );
  NewTree->Branch("Electron2Eta",      &Electron2Eta,      "Electron2Eta/D"      );
  NewTree->Branch("Muon1Eta",          &Muon1Eta,          "Muon1Eta/D"          );
  NewTree->Branch("Muon2Eta",          &Muon2Eta,          "Muon2Eta/D"          );
  NewTree->Branch("Jet1ResolvedEta",   &Jet1ResolvedEta,   "Jet1ResolvedEta/D"   );
  NewTree->Branch("Jet2ResolvedEta",   &Jet2ResolvedEta,   "Jet2ResolvedEta/D"   );
  NewTree->Branch("Jet3ResolvedEta",   &Jet3ResolvedEta,   "Jet3ResolvedEta/D"   );
  NewTree->Branch("Jet1PartialEta",    &Jet1PartialEta,    "Jet1PartialEta/D"    );
  NewTree->Branch("Jet2PartialEta",    &Jet2PartialEta,    "Jet2PartialEta/D"    );
  NewTree->Branch("Jet1MergedEta",     &Jet1MergedEta,     "Jet1MergedEta/D"     );
  NewTree->Branch("MostForwardJetEta", &MostForwardJetEta, "MostForwardJetEta/D" );
  NewTree->Branch("MostForwardJetPt",  &MostForwardJetPt,  "MostForwardJetPt/D"  );
  NewTree->Branch("Electron1Phi",      &Electron1Phi,      "Electron1Phi/D"      );
  NewTree->Branch("Electron2Phi",      &Electron2Phi,      "Electron2Phi/D"      );
  NewTree->Branch("Muon1Phi",          &Muon1Phi,          "Muon1Phi/D"          );
  NewTree->Branch("Muon2Phi",          &Muon2Phi,          "Muon2Phi/D"          );
  NewTree->Branch("deltaPhiZTop",      &deltaPhiZTop,      "deltaPhiZTop/D"      );
  NewTree->Branch("deltaRZTop",        &deltaRZTop,        "deltaRZTop/D"        );
  NewTree->Branch("deltaPhiZB",        &deltaPhiZB,        "deltaPhiZB/D"        );
  NewTree->Branch("deltaRZB",          &deltaRZB,          "deltaRZB/D"          );
  NewTree->Branch("deltaREle1Ele2",    &deltaREle1Ele2,    "deltaREle1Ele2/D"    );
  NewTree->Branch("deltaRMuo1Muo2",    &deltaRMuo1Muo2,    "deltaRMuo1Muo2/D"    );
  NewTree->Branch("Massb1b2",          &Massb1b2,          "Massb1b2/D"          );
  NewTree->Branch("MinDeltaPhiJetMet", &MinDeltaPhiJetMet, "MinDeltaPhiJetMet/D" );
  NewTree->Branch("MinDeltaPhiBoostedJetMet", &MinDeltaPhiBoostedJetMet, "MinDeltaPhiBoostedJetMet/D" );
  NewTree->Branch("deltaRb1b2",        &deltaRb1b2,        "deltaRb1b2/D"        );
  NewTree->Branch("deltaRb1Lep1",      &deltaRb1Lep1,      "deltaRb1Lep1/D"      );
  NewTree->Branch("deltaRb1Lep2",      &deltaRb1Lep2,      "deltaRb1Lep2/D"      );
  NewTree->Branch("deltaRb2Lep1",      &deltaRb2Lep1,      "deltaRb2Lep1/D"      );
  NewTree->Branch("deltaRb2Lep2",      &deltaRb2Lep2,      "deltaRb2Lep2/D"      );
  NewTree->Branch("NumSelLeps",        &NumSelLeps,        "NumSelLeps/I"        );
  NewTree->Branch("NumOfLeptonsT",        &NumOfLeptonsT,        "NumOfLeptonsT/I"        );
  NewTree->Branch("NumOfLeptonsT_v2",        &NumOfLeptonsT_v2,        "NumOfLeptonsT_v2/I"        );
  NewTree->Branch("NumOfMuonsT",        &NumOfMuonsT,        "NumOfMuonsT/I"        );
  NewTree->Branch("NumOfElectronsT",        &NumOfElectronsT,        "NumOfElectronsT/I"        );
  NewTree->Branch("LeadingLeptonPt",          &LeadingLeptonPt,          "LeadingLeptonPt/D");
  NewTree->Branch("SecondLeptonPt",          &SecondLeptonPt,          "SecondLeptonPt/D");
  NewTree->Branch("ThirdLeptonPt",          &ThirdLeptonPt,          "ThirdLeptonPt/D");
//
//
  NewTree->Branch("NumSeEle",          &NumSeEle,          "NumSeEle/I");
  NewTree->Branch("NumSeMu",           &NumSeMu,            "NumSeMu/I");
  NewTree->Branch("InvariantMassJets",  &InvariantMassJets,   "InvariantMassJets/D");
  NewTree->Branch("Centrality",        &Centrality,       "Centrality/D");
  NewTree->Branch("Aplanarity",        &Aplanarity,        "Aplanarity/D");
  NewTree->Branch("LeadingJetPt",      &LeadingJetPt,      "LeadingJetPt/D");
  //NewTree->Branch("MaxdeltaRJets",        &MaxdeltaRJets,        "MaxdeltaRJets/D");
  NewTree->Branch("Sphericity",        &Sphericity,        "Sphericity/D");
 // NewTree->Branch("MindeltaRJets",     &MindeltaRJets,     "MindeltaRJets/D");
  NewTree->Branch("SecondJetPt",       &SecondJetPt,       "SecondJetPt/D");
  NewTree->Branch("ThirdJetPt",        &ThirdJetPt,        "ThirdJetPt/D");
  NewTree->Branch("FourthJetPt",       &FourthJetPt,       "FourthJetPt/D");
  NewTree->Branch("FifthJetPt",        &FifthJetPt,        "FifthJetPt/D");
  NewTree->Branch("SixthJetPt",        &SixthJetPt,        "SixthJetPt/D");
  NewTree->Branch("SeventhJetPt",        &SeventhJetPt,        "SeventhJetPt/D");
  NewTree->Branch("EighthJetPt",        &EighthJetPt,        "EighthJetPt/D");
  NewTree->Branch("LeadingBJetPt",        &LeadingBJetPt,        "LeadingBJetPt/D");
  NewTree->Branch("SecondBJetPt",        &SecondBJetPt,        "SecondBJetPt/D");
  NewTree->Branch("HTDividedByMET",        &HTDividedByMET,        "HTDividedByMET/D");
  NewTree->Branch("MetDividedByHT",        &MetDividedByHT,        "MetDividedByHT/D");
  NewTree->Branch("MHTDividedByMET",        &MHTDividedByMET,        "MHTDividedByMET/D");
  NewTree->Branch("NighthJetPt",        &NighthJetPt,        "NighthJetPt/D");
  NewTree->Branch("TenthJetPt",        &TenthJetPt,        "TenthJetPt/D");
  NewTree->Branch("ThirdBJetPt",        &ThirdBJetPt,        "ThirdBJetPt/D");
  NewTree->Branch("FourthBJetPt",        &FourthBJetPt,        "FourthBJetPt/D");
  NewTree->Branch("FifthBJetPt",        &FifthBJetPt,        "FifthBJetPt/D");
  NewTree->Branch("SixthBJetPt",        &SixthBJetPt,        "SixthBJetPt/D");
  NewTree->Branch("SeventhBJetPt",        &SeventhBJetPt,        "SeventhBJetPt/D");
  NewTree->Branch("EighthBJetPt",        &EighthBJetPt,        "EighthBJetPt/D");
  NewTree->Branch("NighthBJetPt",        &NighthBJetPt,        "NighthBJetPt/D");
  NewTree->Branch("TenthBJetPt",        &TenthBJetPt,        "TenthBJetPt/D");
  NewTree->Branch("MinDeltaRJets",        &MinDeltaRJets,        "MinDeltaRJets/D");
  NewTree->Branch("MaxDeltaRJets",        &MaxDeltaRJets,        "MaxDeltaRJets/D");
  NewTree->Branch("MinDeltaRBJets",        &MinDeltaRBJets,        "MinDeltaRBJets/D");
  NewTree->Branch("MaxDeltaRBJets",        &MaxDeltaRBJets,        "MaxDeltaRBJets/D");
  NewTree->Branch("NumOfTausL",        &NumOfTausL,        "NumOfTausL/I");
  NewTree->Branch("NumOfTausM",        &NumOfTausM,        "NumOfTausM/I");
  NewTree->Branch("NumOfTausT",        &NumOfTausT,        "NumOfTausT/I");
  NewTree->Branch("LeadingTauPt",        &LeadingTauPt,        "LeadingTauPt/D");
  NewTree->Branch("SecondTauPt",        &SecondTauPt,        "SecondTauPt/D");
  NewTree->Branch("NumofTops",        &NumofTops,        "NumofTops/I");
  NewTree->Branch("LeadingTopPt",        &LeadingTopPt,        "LeadingTopPt/D");
  NewTree->Branch("SecondTopPt",        &SecondTopPt,        "SecondTopPt/D");
//
//
  NewTree->Branch("NumSelJets",        &NumSelJets,        "NumSelJets/I"        );
  NewTree->Branch("NumSelForwardJets", &NumSelForwardJets, "NumSelForwardJets/I" );
  NewTree->Branch("NumSelBJetsL",      &NumSelBJetsL,      "NumSelBJetsL/I"      );
  NewTree->Branch("NumSelBJetsM",      &NumSelBJetsM,      "NumSelBJetsM/I"      );
  NewTree->Branch("NumSelBJetsT",      &NumSelBJetsT,      "NumSelBJetsT/I"      );
  NewTree->Branch("NumSelWJets",       &NumSelWJets,       "NumSelWJets/I"       );
  NewTree->Branch("NumSelTopJets",     &NumSelTopJets,     "NumSelTopJets/I"     );
  NewTree->Branch("NVertices",         &NVertices,         "NVertices/I"         );
  NewTree->Branch("HT",                &HT,                "HT/D"                );
  NewTree->Branch("MHT",                &MHT,                "MHT/D"             );
  NewTree->Branch("PUWeight",          &PUWeight,          "PUWeight/D"          );
  NewTree->Branch("PUWeightUP",        &PUWeightUP,        "PUWeightUP/D"        );
  NewTree->Branch("PUWeightDOWN",      &PUWeightDOWN,      "PUWeightDOWN/D"      );
  NewTree->Branch("getTrueNumInteractions",&getTrueNumInteractions,"getTrueNumInteractions/I");
  NewTree->Branch("w_for",             &w_for,             "w_for/D"             );
  NewTree->Branch("w_forUp",           &w_forUp,           "w_forUp/D"           );
  NewTree->Branch("w_forDown",         &w_forDown,         "w_forDown/D"         );
  NewTree->Branch("w_topJet",          &w_topJet,          "w_topJet/D"          );
  NewTree->Branch("w_topJetUp",        &w_topJetUp,        "w_topJetUp/D"        );
  NewTree->Branch("w_topJetDown",      &w_topJetDown,      "w_topJetDown/D"      );
  NewTree->Branch("w_WJet",            &w_WJet,            "w_WJet/D"            );
  NewTree->Branch("w_WJetUp",          &w_WJetUp,          "w_WJetUp/D"          );
  NewTree->Branch("w_WJetDown",        &w_WJetDown,        "w_WJetDown/D"        );
  NewTree->Branch("w_Muon1",           &w_Muon1,           "w_Muon1/D"           );
  NewTree->Branch("w_Muon2",           &w_Muon2,           "w_Muon2/D"           );
  NewTree->Branch("w_Muon1Up",         &w_Muon1Up,         "w_Muon1Up/D"         );
  NewTree->Branch("w_Muon2Up",         &w_Muon2Up,         "w_Muon2Up/D"         );
  NewTree->Branch("w_Muon1Down",       &w_Muon1Down,       "w_Muon1Down/D"       );
  NewTree->Branch("w_Muon2Down",       &w_Muon2Down,       "w_Muon2Down/D"       );
  NewTree->Branch("w_TrigMuon",        &w_TrigMuon,        "w_TrigMuon/D"        );
  NewTree->Branch("w_TrigMuonUp",      &w_TrigMuonUp,      "w_TrigMuonUp/D"      );
  NewTree->Branch("w_TrigMuonDown",    &w_TrigMuonDown,    "w_TrigMuonDown/D"    );
  NewTree->Branch("w_Electron1",       &w_Electron1,       "w_Electron1/D"       );
  NewTree->Branch("w_Electron2",       &w_Electron2,       "w_Electron2/D"       );
  NewTree->Branch("w_Electron1Up",     &w_Electron1Up,     "w_Electron1Up/D"     );
  NewTree->Branch("w_Electron2Up",     &w_Electron2Up,     "w_Electron2Up/D"     );
  NewTree->Branch("w_Electron1Down",   &w_Electron1Down,   "w_Electron1Down/D"   );
  NewTree->Branch("w_Electron2Down",   &w_Electron2Down,   "w_Electron2Down/D"   );
  NewTree->Branch("w_TrigElec",        &w_TrigElec,        "w_TrigElec/D"        );
  NewTree->Branch("w_TrigElecUp",      &w_TrigElecUp,      "w_TrigElecUp/D"      );
  NewTree->Branch("w_TrigElecDown",    &w_TrigElecDown,    "w_TrigElecDown/D"    );
  NewTree->Branch("w_ZToNuNu",         &w_ZToNuNu,         "w_ZToNuNu/D"         );
  NewTree->Branch("w_ZToNuNuUp",       &w_ZToNuNuUp,       "w_ZToNuNuUp/D"       );
  NewTree->Branch("w_ZToNuNuDown",     &w_ZToNuNuDown,     "w_ZToNuNuDown/D"     );
  NewTree->Branch("w_WToLNu",          &w_WToLNu,          "w_WToLNu/D"          );
  NewTree->Branch("w_WToLNuUp",        &w_WToLNuUp,        "w_WToLNuUp/D"        );
  NewTree->Branch("w_WToLNuDown",      &w_WToLNuDown,      "w_WToLNuDown/D"      );
  NewTree->Branch("w_ttbar",           &w_ttbar,           "w_ttbar/D"           );
  NewTree->Branch("w_ttbarUp",         &w_ttbarUp,         "w_ttbarUp/D"         );
  NewTree->Branch("w_ttbarDown",       &w_ttbarDown,       "w_ttbarDown/D"       );
  NewTree->Branch("w_Trig",            &w_Trig,            "w_Trig/D"            );
  NewTree->Branch("w_TrigUp",          &w_TrigUp,          "w_TrigUp/D"          );
  NewTree->Branch("w_TrigDown",        &w_TrigDown,        "w_TrigDown/D"        );
  NewTree->Branch("WMass",             &WMass,             "WMass/D"             );
  NewTree->Branch("WSubjet",           &WSubjet,           "WSubjet/D"           );
  NewTree->Branch("TopSoftMass",       &TopSoftMass,       "TopSoftMass/D"       );
  NewTree->Branch("TopSubjet",         &TopSubjet,         "TopSubjet/D"         );
  NewTree->Branch("w_Btag",            &w_Btag,            "w_Btag/D"            );
  NewTree->Branch("w_BtagUp",          &w_BtagUp,          "w_BtagUp/D"          );
  NewTree->Branch("w_BtagDown",        &w_BtagDown,        "w_BtagDown/D"        );
  NewTree->Branch("w_Btag1Up",         &w_Btag1Up,         "w_Btag1Up/D"         );
  NewTree->Branch("w_Btag1Down",       &w_Btag1Down,       "w_Btag1Down/D"       );
  NewTree->Branch("w_Btag2Up",         &w_Btag2Up,         "w_Btag2Up/D"         );
  NewTree->Branch("w_Btag2Down",       &w_Btag2Down,       "w_Btag2Down/D"       );
  NewTree->Branch("w_BtagLoose",       &w_BtagLoose,       "w_BtagLoose/D"       );
  NewTree->Branch("w_BtagLooseUp",     &w_BtagLooseUp,     "w_BtagLooseUp/D"     );
  NewTree->Branch("w_BtagLooseDown",   &w_BtagLooseDown,   "w_BtagLooseDown/D"   );
  NewTree->Branch("w_QCDUp",           &w_QCDUp,           "w_QCDUp/D"           );
  NewTree->Branch("w_QCDDown",         &w_QCDDown,         "w_QCDDown/D"         );
  NewTree->Branch("w_PDFUp",           &w_PDFUp,           "w_PDFUp/D"           );
  NewTree->Branch("w_PDFDown",         &w_PDFDown,         "w_PDFDown/D"         );
  NewTree->Branch("deltaPhiZTopResolved", &deltaPhiZTopResolved, "deltaPhiZTopResolved/D");
  NewTree->Branch("deltaRZTopResolved",   &deltaRZTopResolved,   "deltaRZTopResolved/D"  );
  NewTree->Branch("deltaPhiZTopPartial",  &deltaPhiZTopPartial,  "deltaPhiZTopPartial/D" );
  NewTree->Branch("deltaRZTopPartial",    &deltaRZTopPartial,    "deltaRZTopPartial/D"   );
  NewTree->Branch("deltaPhiZTopMerged",   &deltaPhiZTopMerged,   "deltaPhiZTopMerged/D"  );
  NewTree->Branch("deltaRZTopMerged",     &deltaRZTopMerged,     "deltaRZTopMerged/D"    );
  NewTree->Branch("deltaRbTop",           &deltaRbTop,           "deltaRbTop/D"          );
  NewTree->Branch("deltaPhiMetTop",       &deltaPhiMetTop,       "deltaPhiMetTop/D"      );
  NewTree->Branch("genWeight",            &genWeight,            "genWeight/D"           );
  NewTree->Branch("dQuark",&dQuark,"dQuark/I");
  NewTree->Branch("uQuark",&uQuark,"uQuark/I");
  NewTree->Branch("sQuark",&sQuark,"sQuark/I");
  NewTree->Branch("cQuark",&cQuark,"cQuark/I");
  NewTree->Branch("bQuark",&bQuark,"bQuark/I");
  NewTree->Branch("tQuark",&tQuark,"tQuark/I");
  NewTree->Branch("EVENT_event",&EVENT_event,"EVENT_event/I");
  NewTree->Branch("EVENT_run",&EVENT_run,"EVENT_run/I");
  NewTree->Branch("EVENT_lumiBlock",&EVENT_lumiBlock,"EVENT_lumiBlock/I");
  NewTree->Branch("EVENT_genHT",&EVENT_genHT,"EVENT_genHT/D");
  NewTree->Branch("prefiringweight",&prefiringweight,"prefiringweight/D");
  NewTree->Branch("prefiringweightup",&prefiringweightup,"prefiringweightup/D");
  NewTree->Branch("prefiringweightdown",&prefiringweightdown,"prefiringweightdown/D");
  NewTree->Branch("Met_pt",&Met_pt,"Met_pt/D");
  NewTree->Branch("Met_phi",&Met_phi,"Met_phi/D");
  NewTree->Branch("TransverseMassMetTop",&TransverseMassMetTop,"TransverseMassMetTop/D");

  if(selection==2){
      NewTreeSB->Branch("TopMass",           &TopMass,           "TopMass/D"           );
      NewTreeSB->Branch("TopMassMerged",     &TopMassMerged,     "TopMassMerged/D"     );
      NewTreeSB->Branch("TopMassPartial",    &TopMassPartial,    "TopMassPartial/D"    );
      NewTreeSB->Branch("TopMassResolved",   &TopMassResolved,   "TopMassResolved/D"   );
      NewTreeSB->Branch("TopPt",             &TopPt,             "TopPt/D"             );
      NewTreeSB->Branch("TopPtMerged",       &TopPtMerged,       "TopPtMerged/D"       );
      NewTreeSB->Branch("TopPtPartial",      &TopPtPartial,      "TopPtPartial/D"      );
      NewTreeSB->Branch("TopPtResolved",     &TopPtResolved,     "TopPtResolved/D"     );
      NewTreeSB->Branch("TopEta",            &TopEta,            "TopEta/D"            );
      NewTreeSB->Branch("TopEtaMerged",      &TopEtaMerged,      "TopEtaMerged/D"      );
      NewTreeSB->Branch("TopEtaPartial",     &TopEtaPartial,     "TopEtaPartial/D"     );
      NewTreeSB->Branch("TopEtaResolved",    &TopEtaResolved,    "TopEtaResolved/D"    );
      NewTreeSB->Branch("TopPhi",            &TopPhi,            "TopPhi/D"            );
      NewTreeSB->Branch("TopPhiMerged",      &TopPhiMerged,      "TopPhiMerged/D"      );
      NewTreeSB->Branch("TopPhiPartial",     &TopPhiPartial,     "TopPhiPartial/D"     );
      NewTreeSB->Branch("TopPhiResolved",    &TopPhiResolved,    "TopPhiResolved/D"    );
      NewTreeSB->Branch("WMassResolved1",    &WMassResolved1,    "WMassResolved1/D"    );
      NewTreeSB->Branch("WMassResolved2",    &WMassResolved2,    "WMassResolved2/D"    );
      NewTreeSB->Branch("WMassResolved3",    &WMassResolved3,    "WMassResolved3/D"    );
      NewTreeSB->Branch("BMass",             &BMass,             "BMass/D"             );
      NewTreeSB->Branch("BCSV",              &BCSV,              "BCSV/D"              );
      NewTreeSB->Branch("BPt",               &BPt,               "BPt/D"               );
      NewTreeSB->Branch("BEta",              &BEta,              "BEta/D"              );
      NewTreeSB->Branch("BPhi",              &BPhi,              "BPhi/D"              );
      NewTreeSB->Branch("ZMass",             &ZMass,             "ZMass/D"             );
      NewTreeSB->Branch("ZPt",               &ZPt,               "ZPt/D"               );
      NewTreeSB->Branch("ZEta",              &ZEta,              "ZEta/D"              );
      NewTreeSB->Branch("ZPhi",              &ZPhi,              "ZPhi/D"              );
/*      NewTreeSB->Branch("TprimeMass",        &TprimeMass,        "TprimeMass/D"        );
      NewTreeSB->Branch("TprimePt",          &TprimePt,          "TprimePt/D"          );
      NewTreeSB->Branch("TprimeEta",         &TprimeEta,         "TprimeEta/D"         );
      NewTreeSB->Branch("TprimePhi",         &TprimePhi,         "TprimePhi/D"         );
      NewTreeSB->Branch("TprimeResolvedMass",&TprimeResolvedMass,"TprimeResolvedMass/D");
      NewTreeSB->Branch("TprimeResolvedPt",  &TprimeResolvedPt,  "TprimeResolvedPt/D"  );
      NewTreeSB->Branch("TprimeResolvedEta", &TprimeResolvedEta, "TprimeResolvedEta/D" );
      NewTreeSB->Branch("TprimeResolvedPhi", &TprimeResolvedPhi, "TprimeResolvedPhi/D" );
      NewTreeSB->Branch("TprimePartialMass", &TprimePartialMass, "TprimePartialMass/D" );
      NewTreeSB->Branch("TprimePartialPt",   &TprimePartialPt,   "TprimePartialPt/D"   );
      NewTreeSB->Branch("TprimePartialEta",  &TprimePartialEta,  "TprimePartialEta/D"  );
      NewTreeSB->Branch("TprimePartialPhi",  &TprimePartialPhi,  "TprimePartialPhi/D"  );
      NewTreeSB->Branch("TprimeMergedMass",  &TprimeMergedMass,  "TprimeMergedMass/D"  );
      NewTreeSB->Branch("TprimeMergedPt",    &TprimeMergedPt,    "TprimeMergedPt/D"    );
      NewTreeSB->Branch("TprimeMergedEta",   &TprimeMergedEta,   "TprimeMergedEta/D"   );
      NewTreeSB->Branch("TprimeMergedPhi",   &TprimeMergedPhi,   "TprimeMergedPhi/D"   );*/
      NewTreeSB->Branch("Electron1Pt",       &Electron1Pt,       "Electron1Pt/D"       );
      NewTreeSB->Branch("Electron2Pt",       &Electron2Pt,       "Electron2Pt/D"       );
      NewTreeSB->Branch("Electron1E",        &Electron1E,        "Electron1E/D"        );
      NewTreeSB->Branch("Electron2E",        &Electron2E,        "Electron2E/D"        );
      NewTreeSB->Branch("Muon1Iso",          &Muon1Iso,          "Muon1Iso/D"          );
      NewTreeSB->Branch("Muon2Iso",          &Muon2Iso,          "Muon2Iso/D"          );
      NewTreeSB->Branch("Muon1Pt",           &Muon1Pt,           "Muon1Pt/D"           );
      NewTreeSB->Branch("Muon2Pt",           &Muon2Pt,           "Muon2Pt/D"           );
      NewTreeSB->Branch("Jet1ForwardEta",    &Jet1ForwardEta,    "Jet1ForwardEta/D"    );
      NewTreeSB->Branch("Jet2ForwardEta",    &Jet2ForwardEta,    "Jet2ForwardEta/D"    );
      NewTreeSB->Branch("Jet3ForwardEta",    &Jet3ForwardEta,    "Jet3ForwardEta/D"    );
      NewTreeSB->Branch("Jet1ForwardPt",     &Jet1ForwardPt,     "Jet1ForwardPt/D"     );
      NewTreeSB->Branch("Jet2ForwardPt",     &Jet2ForwardPt,     "Jet2ForwardPt/D"     );
      NewTreeSB->Branch("Jet3ForwardPt",     &Jet3ForwardPt,     "Jet3ForwardPt/D"     );
      NewTreeSB->Branch("Jet1ResolvedPt",    &Jet1ResolvedPt,    "Jet1ResolvedPt/D"    );
      NewTreeSB->Branch("Jet2ResolvedPt",    &Jet2ResolvedPt,    "Jet2ResolvedPt/D"    );
      NewTreeSB->Branch("Jet3ResolvedPt",    &Jet3ResolvedPt,    "Jet3ResolvedPt/D"    );
      NewTreeSB->Branch("Jet1PartialPt",     &Jet1PartialPt,     "Jet1PartialPt/D"     );
      NewTreeSB->Branch("Jet2PartialPt",     &Jet2PartialPt,     "Jet2PartialPt/D"     );
      NewTreeSB->Branch("Jet1MergedPt",      &Jet1MergedPt,      "Jet1MergedPt/D"      );
      NewTreeSB->Branch("MostForwardJetEta", &MostForwardJetEta, "MostForwardJetEta/D" );
      NewTreeSB->Branch("MostForwardJetPt",  &MostForwardJetPt,  "MostForwardJetPt/D"  );
      NewTreeSB->Branch("Electron1Eta",      &Electron1Eta,      "Electron1Eta/D"      );
      NewTreeSB->Branch("Electron2Eta",      &Electron2Eta,      "Electron2Eta/D"      );
      NewTreeSB->Branch("Muon1Eta",          &Muon1Eta,          "Muon1Eta/D"          );
      NewTreeSB->Branch("Muon2Eta",          &Muon2Eta,          "Muon2Eta/D"          );
     NewTreeSB->Branch("Jet1ResolvedEta",   &Jet1ResolvedEta,   "Jet1ResolvedEta/D"   );
      NewTreeSB->Branch("Jet2ResolvedEta",   &Jet2ResolvedEta,   "Jet2ResolvedEta/D"   );
      NewTreeSB->Branch("Jet3ResolvedEta",   &Jet3ResolvedEta,   "Jet3ResolvedEta/D"   );
      NewTreeSB->Branch("Jet1PartialEta",    &Jet1PartialEta,    "Jet1PartialEta/D"    );
      NewTreeSB->Branch("Jet2PartialEta",    &Jet2PartialEta,    "Jet2PartialEta/D"    );
      NewTreeSB->Branch("Jet1MergedEta",     &Jet1MergedEta,     "Jet1MergedEta/D"     );
      NewTreeSB->Branch("Electron1Phi",      &Electron1Phi,      "Electron1Phi/D"      );
      NewTreeSB->Branch("Electron2Phi",      &Electron2Phi,      "Electron2Phi/D"      );
      NewTreeSB->Branch("Muon1Phi",          &Muon1Phi,          "Muon1Phi/D"          );
      NewTreeSB->Branch("Muon2Phi",          &Muon2Phi,          "Muon2Phi/D"          );
      NewTreeSB->Branch("deltaPhiZTop",      &deltaPhiZTop,      "deltaPhiZTop/D"      );
      NewTreeSB->Branch("deltaRZTop",        &deltaRZTop,        "deltaRZTop/D"        );
      NewTreeSB->Branch("deltaREle1Ele2",    &deltaREle1Ele2,    "deltaREle1Ele2/D"    );
      NewTreeSB->Branch("deltaRMuo1Muo2",    &deltaRMuo1Muo2,    "deltaRMuo1Muo2/D"    );
      NewTreeSB->Branch("Massb1b2",          &Massb1b2,          "Massb1b2/D"          );
      NewTreeSB->Branch("MinDeltaPhiJetMet", &MinDeltaPhiJetMet, "MinDeltaPhiJetMet/D" );
      NewTreeSB->Branch("MinDeltaPhiBoostedJetMet", &MinDeltaPhiBoostedJetMet, "MinDeltaPhiBoostedJetMet/D" );
      NewTreeSB->Branch("deltaRb1b2",        &deltaRb1b2,        "deltaRb1b2/D"        );
      NewTreeSB->Branch("deltaRb1Lep1",      &deltaRb1Lep1,      "deltaRb1Lep1/D"      );
      NewTreeSB->Branch("deltaRb1Lep2",      &deltaRb1Lep2,      "deltaRb1Lep2/D"      );
      NewTreeSB->Branch("deltaRb2Lep1",      &deltaRb2Lep1,      "deltaRb2Lep1/D"      );
      NewTreeSB->Branch("deltaRb2Lep2",      &deltaRb2Lep2,      "deltaRb2Lep2/D"      );
      NewTreeSB->Branch("NumSelLeps",        &NumSelLeps,        "NumSelLeps/I"        );
    // 
    //
     NewTreeSB->Branch("NumSeEle",      &NumSeEle,                "NumSeEle");
     NewTreeSB->Branch("NumSeMu",       &NumSeMu,                 "NumSeMu");
      NewTreeSB->Branch("InvariantMassJets",  &InvariantMassJets,   "InvariantMassJets/D");
      NewTreeSB->Branch("Centrality",        &Centrality,       "Centrality/D");
      NewTreeSB->Branch("Aplanarity",        &Aplanarity,        "Aplanarity/D");
    //
    //
      NewTreeSB->Branch("NumSelJets",        &NumSelJets,        "NumSelJets/I"        );
      NewTreeSB->Branch("NumSelForwardJets", &NumSelForwardJets, "NumSelForwardJets/I" );
      NewTreeSB->Branch("NumSelBJetsL",      &NumSelBJetsL,      "NumSelBJetsL/I"      );
      NewTreeSB->Branch("NumSelBJetsM",      &NumSelBJetsM,      "NumSelBJetsM/I"      );
      NewTreeSB->Branch("NumSelBJetsT",      &NumSelBJetsT,      "NumSelBJetsT/I"      );
      NewTreeSB->Branch("NumSelWJets",       &NumSelWJets,       "NumSelWJets/I"       );
      NewTreeSB->Branch("NumSelTopJets",     &NumSelTopJets,     "NumSelTopJets/I"     );
      NewTreeSB->Branch("NVertices",         &NVertices,         "NVertices/I"         );
      NewTreeSB->Branch("HT",                &HT,                "HT/D"                );
      NewTreeSB->Branch("MHT",                &MHT,                "MHT/D"                );
      NewTreeSB->Branch("PUWeight",          &PUWeight,          "PUWeight/D"          );
      NewTreeSB->Branch("PUWeightUP",        &PUWeightUP,        "PUWeightUP/D"        );
      NewTreeSB->Branch("PUWeightDOWN",      &PUWeightDOWN,      "PUWeightDOWN/D"      );
      NewTreeSB->Branch("getTrueNumInteractions",&getTrueNumInteractions,"getTrueNumInteractions/I");
      NewTreeSB->Branch("w_for",             &w_for,             "w_for/D"             );
      NewTreeSB->Branch("w_forUp",           &w_forUp,           "w_forUp/D"           );
      NewTreeSB->Branch("w_forDown",         &w_forDown,         "w_forDown/D"         );
      NewTreeSB->Branch("w_topJet",          &w_topJet,          "w_topJet/D"          );
      NewTreeSB->Branch("w_topJetUp",        &w_topJetUp,        "w_topJetUp/D"        );
      NewTreeSB->Branch("w_topJetDown",      &w_topJetDown,      "w_topJetDown/D"      );
      NewTreeSB->Branch("w_WJet",            &w_WJet,            "w_WJet/D"            );
      NewTreeSB->Branch("w_WJetUp",          &w_WJetUp,          "w_WJetUp/D"          );
      NewTreeSB->Branch("w_WJetDown",        &w_WJetDown,        "w_WJetDown/D"        );
      NewTreeSB->Branch("w_Muon1",           &w_Muon1,           "w_Muon1/D"           );
      NewTreeSB->Branch("w_Muon2",           &w_Muon2,           "w_Muon2/D"           );
      NewTreeSB->Branch("w_Muon1Up",         &w_Muon1Up,         "w_Muon1Up/D"         );
      NewTreeSB->Branch("w_Muon2Up",         &w_Muon2Up,         "w_Muon2Up/D"         );
      NewTreeSB->Branch("w_Muon1Down",       &w_Muon1Down,       "w_Muon1Down/D"       );
      NewTreeSB->Branch("w_Muon2Down",       &w_Muon2Down,       "w_Muon2Down/D"       );
      NewTreeSB->Branch("w_TrigMuon",        &w_TrigMuon,        "w_TrigMuon/D"        );
      NewTreeSB->Branch("w_TrigMuonUp",      &w_TrigMuonUp,      "w_TrigMuonUp/D"      );
      NewTreeSB->Branch("w_TrigMuonDown",    &w_TrigMuonDown,    "w_TrigMuonDown/D"    );
      NewTreeSB->Branch("w_Electron1",       &w_Electron1,       "w_Electron1/D"       );
      NewTreeSB->Branch("w_Electron2",       &w_Electron2,       "w_Electron2/D"       );
      NewTreeSB->Branch("w_Electron1Up",     &w_Electron1Up,     "w_Electron1Up/D"     );
      NewTreeSB->Branch("w_Electron2Up",     &w_Electron2Up,     "w_Electron2Up/D"     );
      NewTreeSB->Branch("w_Electron1Down",   &w_Electron1Down,   "w_Electron1Down/D"   );
      NewTreeSB->Branch("w_Electron2Down",   &w_Electron2Down,   "w_Electron2Down/D"   );
      NewTreeSB->Branch("w_TrigElec",        &w_TrigElec,        "w_TrigElec/D"        );
      NewTreeSB->Branch("w_TrigElecUp",      &w_TrigElecUp,      "w_TrigElecUp/D"      );
      NewTreeSB->Branch("w_TrigElecDown",    &w_TrigElecDown,    "w_TrigElecDown/D"    );
      NewTreeSB->Branch("w_ZToNuNu",         &w_ZToNuNu,         "w_ZToNuNu/D"         );
      NewTreeSB->Branch("w_ZToNuNuUp",       &w_ZToNuNuUp,       "w_ZToNuNuUp/D"       );
      NewTreeSB->Branch("w_ZToNuNuDown",     &w_ZToNuNuDown,     "w_ZToNuNuDown/D"     );
      NewTreeSB->Branch("w_WToLNu",          &w_WToLNu,          "w_WToLNu/D"          );
      NewTreeSB->Branch("w_WToLNuUp",        &w_WToLNuUp,        "w_WToLNuUp/D"        );
      NewTreeSB->Branch("w_WToLNuDown",      &w_WToLNuDown,      "w_WToLNuDown/D"      );
      NewTreeSB->Branch("w_ttbar",           &w_ttbar,           "w_ttbar/D"           );
      NewTreeSB->Branch("w_ttbarUp",         &w_ttbarUp,         "w_ttbarUp/D"         );
      NewTreeSB->Branch("w_ttbarDown",       &w_ttbarDown,       "w_ttbarDown/D"       );
      NewTreeSB->Branch("w_Trig",            &w_Trig,            "w_Trig/D"            );
      NewTreeSB->Branch("w_TrigUp",          &w_TrigUp,          "w_TrigUp/D"          );
      NewTreeSB->Branch("w_TrigDown",        &w_TrigDown,        "w_TrigDown/D"        );
      NewTreeSB->Branch("WMass",             &WMass,             "WMass/D"             );
      NewTreeSB->Branch("WSubjet",           &WSubjet,           "WSubjet/D"           );
      NewTreeSB->Branch("TopSoftMass",       &TopSoftMass,       "TopSoftMass/D"       );
      NewTreeSB->Branch("TopSubjet",         &TopSubjet,         "TopSubjet/D"         );
      NewTreeSB->Branch("w_Btag",            &w_Btag,            "w_Btag/D"            );
      NewTreeSB->Branch("w_BtagUp",          &w_BtagUp,          "w_BtagUp/D"          );
      NewTreeSB->Branch("w_BtagDown",        &w_BtagDown,        "w_BtagDown/D"        );
      NewTreeSB->Branch("w_Btag1Up",         &w_Btag1Up,         "w_Btag1Up/D"         );
      NewTreeSB->Branch("w_Btag1Down",       &w_Btag1Down,       "w_Btag1Down/D"       );
      NewTreeSB->Branch("w_Btag2Up",         &w_Btag2Up,         "w_Btag2Up/D"         );
      NewTreeSB->Branch("w_Btag2Down",       &w_Btag2Down,       "w_Btag2Down/D"       );
      NewTreeSB->Branch("w_BtagLoose",       &w_BtagLoose,       "w_BtagLoose/D"       );
      NewTreeSB->Branch("w_BtagLooseUp",     &w_BtagLooseUp,     "w_BtagLooseUp/D"     );
      NewTreeSB->Branch("w_BtagLooseDown",   &w_BtagLooseDown,   "w_BtagLooseDown/D"   );
      NewTreeSB->Branch("w_QCDUp",           &w_QCDUp,           "w_QCDUp/D"           );
      NewTreeSB->Branch("w_QCDDown",         &w_QCDDown,         "w_QCDDown/D"         );
      NewTreeSB->Branch("w_PDFUp",           &w_PDFUp,           "w_PDFUp/D"           );
      NewTreeSB->Branch("w_PDFDown",         &w_PDFDown,         "w_PDFDown/D"         );
      NewTreeSB->Branch("deltaPhiZTopResolved", &deltaPhiZTopResolved, "deltaPhiZTopResolved/D");
      NewTreeSB->Branch("deltaRZTopResolved",   &deltaRZTopResolved,   "deltaRZTopResolved/D"  );
      NewTreeSB->Branch("deltaPhiZTopPartial",  &deltaPhiZTopPartial,  "deltaPhiZTopPartial/D" );
      NewTreeSB->Branch("deltaRZTopPartial",    &deltaRZTopPartial,    "deltaRZTopPartial/D"   );
      NewTreeSB->Branch("deltaPhiZTopMerged",   &deltaPhiZTopMerged,   "deltaPhiZTopMerged/D"  );
      NewTreeSB->Branch("deltaRZTopMerged",     &deltaRZTopMerged,     "deltaRZTopMerged/D"    );
      NewTreeSB->Branch("deltaRbTop",           &deltaRbTop,           "deltaRbTop/D"          );
      NewTreeSB->Branch("deltaPhiMetTop",       &deltaPhiMetTop,       "deltaPhiMetTop/D"      );
      NewTreeSB->Branch("genWeight",            &genWeight,            "genWeight/D"           );
      NewTreeSB->Branch("dQuark",&dQuark,"dQuark/I");
      NewTreeSB->Branch("uQuark",&uQuark,"uQuark/I");
      NewTreeSB->Branch("sQuark",&sQuark,"sQuark/I");
      NewTreeSB->Branch("cQuark",&cQuark,"cQuark/I");
      NewTreeSB->Branch("bQuark",&bQuark,"bQuark/I");
      NewTreeSB->Branch("tQuark",&tQuark,"tQuark/I");
      NewTreeSB->Branch("EVENT_event",&EVENT_event,"EVENT_event/I");
      NewTreeSB->Branch("EVENT_run",&EVENT_run,"EVENT_run/I");
      NewTreeSB->Branch("EVENT_lumiBlock",&EVENT_lumiBlock,"EVENT_lumiBlock/I");
      NewTreeSB->Branch("EVENT_genHT",&EVENT_genHT,"EVENT_genHT/D");
      NewTreeSB->Branch("prefiringweight",&prefiringweight,"prefiringweight/D");
      NewTreeSB->Branch("prefiringweightup",&prefiringweightup,"prefiringweightup/D");
      NewTreeSB->Branch("prefiringweightdown",&prefiringweightdown,"prefiringweightdown/D");
      NewTreeSB->Branch("Met_pt",&Met_pt,"Met_pt/D");
      NewTreeSB->Branch("Met_phi",&Met_phi,"Met_phi/D");
      NewTreeSB->Branch("TransverseMassMetTop",&TransverseMassMetTop,"TransverseMassMetTop/D");
  }
}/*}}}*/

void initializeVar(){/*{{{*/
 channel_1Tau0L=0;
channel_1Tau1L=0;
channel_1Tau2OS=0;
channel_1Tau2SS=0;
channel_1Tau3L=0;
channel_2Tau0L=0;
channel_2Tau1L=0;
channel_2Tau2SS=0;
channel_2Tau2OS=0;
  BMass=-99;
  BCSV=-99;
  BPt=-99;
  BEta=-99;
  BPhi=-99;
  TopMass=-99;
  TopMassMerged=-99;
  TopMassPartial=-99;
  TopMassResolved=-99;
  TopPt=-99;
  TopPtMerged=-99;
  TopPtPartial=-99;
  TopPtResolved=-99;
  TopEta=-99;
  TopEtaMerged=-99;
  TopEtaPartial=-99;
  TopEtaResolved=-99;
  TopPhi=-99;
  TopPhiMerged=-99;
  TopPhiPartial=-99;
  TopPhiResolved=-99;
  WMassResolved1=-99;
  WMassResolved2=-99;
  WMassResolved3=-99;
  ZMass=-99;
  ZPt=-99;
  ZEta=-99;
  ZPhi=-99;
  /*
  TprimeMass=-99;
  TprimePt=-99;
  TprimeEta=-99;
  TprimePhi=-99;
  TprimeResolvedMass=-99;
  TprimeResolvedPt=-99;
  TprimeResolvedEta=-99;
  TprimeResolvedPhi=-99;
  TprimePartialMass=-99;
  TprimePartialPt=-99;
  TprimePartialEta=-99;
  TprimePartialPhi=-99;
  TprimeMergedMass=-99;
  TprimeMergedPt=-99;
  TprimeMergedEta=-99;
  TprimeMergedPhi=-99;
  */
  Electron1Pt=-99;
  Electron2Pt=-99;
  Electron1E=-99;
  Electron2E=-99;
  Muon1Iso=-99;
  Muon2Iso=-99;
  Muon1Pt=-99;
  Muon2Pt=-99;
 Electron1Eta=-99;
  Electron2Eta=-99;
  Muon1Eta=-99;
  Muon2Eta=-99;
  Electron1Phi=-99;
  Electron2Phi=-99;
  Muon1Phi=-99;
  Muon2Phi=-99;
  deltaPhiZTop=-99;
  deltaRZTop=-99;
  deltaPhiZTopResolved=-99;
  deltaRZTopResolved=-99;
  deltaPhiZTopPartial=-99;
  deltaRZTopPartial=-99;
  deltaPhiZTopMerged=-99;
  deltaRZTopMerged=-99;
  deltaRbTop=-99;
  deltaREle1Ele2=-99;
  deltaRMuo1Muo2=-99;
  deltaPhiMetTop=-99.;
  Massb1b2=-99;
  MinDeltaPhiJetMet=99.;
  MinDeltaPhiBoostedJetMet=99.;
  deltaRb1b2=-99;
  deltaRb1Lep1=-99;
  deltaRb1Lep2=-99;
  deltaRb2Lep1=-99;
  deltaRb2Lep2=-99;
  Jet1ForwardEta=-99;
  Jet2ForwardEta=-99;
  Jet3ForwardEta=-99;
  Jet1ForwardPt=-99;
  Jet2ForwardPt=-99;
  Jet3ForwardPt=-99;
  Jet1ResolvedPt=-99;
  Jet2ResolvedPt=-99;
  Jet3ResolvedPt=-99;
  Jet1PartialPt=-99;
  Jet2PartialPt=-99;
  Jet1MergedPt=-99;
  Jet1ResolvedEta=-99;
  Jet2ResolvedEta=-99;
  Jet3ResolvedEta=-99;
  Jet1PartialEta=-99;
  Jet2PartialEta=-99;
  Jet1MergedEta=-99;
  MostForwardJetEta=-99;
  MostForwardJetPt=-99;
  NumSelLeps=-99;
  NumOfLeptonsT=-99;
  NumOfLeptonsT_v2=-99;
 NumOfMuonsT=-99;
 NumOfElectronsT=-99;
LeadingLeptonPt=-99;
SecondLeptonPt=-99;
ThirdLeptonPt=-99;
//
//
  NumSeEle=-99;
  NumSeMu=-99;
  InvariantMassJets=-99;
  Centrality=-99;
  Aplanarity=-99;
  LeadingJetPt=-99;
 // MaxdeltaRJets=-99;
  Sphericity=-99;
//MindeltaRJets=-99;
SecondJetPt=-99;
ThirdJetPt=-99;
FourthJetPt=-99;
FifthJetPt=-99;
SixthJetPt=-99;
SeventhJetPt=-99;
EighthJetPt=-99;
LeadingBJetPt=-99;
SecondBJetPt=-99;
HTDividedByMET=-99;
MetDividedByHT=-99;
MHTDividedByMET=-99;
NighthJetPt=-99;
TenthJetPt=-99;
ThirdBJetPt=-99;
FourthBJetPt=-99;
FifthBJetPt=-99;
SixthBJetPt=-99;
SeventhBJetPt=-99;
EighthBJetPt=-99;
NighthBJetPt=-99;
TenthBJetPt=-99;
MinDeltaRJets=-99;
MaxDeltaRJets=-99;
MinDeltaRBJets=-99;
MaxDeltaRBJets=-99;
NumOfTausL=-99;
NumOfTausM=-99;
NumOfTausT=-99;
LeadingTauPt=-99;
SecondTauPt=-99;
NumofTops=-99;
LeadingTopPt=-99;
SecondTopPt=-99;

//
//
  NumSelJets=-99;
  NumSelForwardJets=-99;
  NumSelBJetsL=-99;
  NumSelBJetsM=-99;
  NumSelBJetsT=-99;
  NumSelWJets=-99;
  NumSelTopJets=-99;
  NVertices=-99;
  HT=-99;
  MHT=-99;
  PUWeight=1;
  PUWeightUP=1;
  PUWeightDOWN=1;
  EVENT_event=-99;
  EVENT_run=-99;
  EVENT_lumiBlock=-99;
  EVENT_genHT=-99;
  prefiringweight = 1;
  prefiringweightup = 1;
  prefiringweightdown = 1;
  Met_pt = -99.;
  Met_phi = -99.;
  getTrueNumInteractions=-99;
  w_for = 1;
  w_forUp = 1;
  w_forDown = 1;
  w_topJet = 1;
  w_topJetUp = 1;
  w_topJetDown = 1;
  w_WJet   = 1;
  w_WJetUp   = 1;
  w_WJetDown   = 1;
  w_Muon1  = 1;
  w_Muon2  = 1;
  w_Muon1Up  = 1;
  w_Muon2Up  = 1;
  w_Muon1Down  = 1;
  w_Muon2Down  = 1;
  w_TrigMuon  = 1;
  w_TrigMuonUp  = 1;
  w_TrigMuonDown  = 1;
  w_Electron1  = 1;
  w_Electron2  = 1;
  w_Electron1Up  = 1;
  w_Electron2Up  = 1;
  w_Electron1Down  = 1;
  w_Electron2Down  = 1;
  w_TrigElec  = 1;
  w_TrigElecUp  = 1;
  w_TrigElecDown  = 1;
  w_ZToNuNu=1;
  w_ZToNuNuUp=1;
  w_ZToNuNuDown=1;
  w_WToLNu=1;
  w_WToLNuUp=1;
  w_WToLNuDown=1;
  w_ttbar=1;
  w_ttbarUp=1;
  w_ttbarDown=1;
  w_Trig  = 1;
  w_TrigUp  = 1;
  w_TrigDown  = 1;
  WMass = -99;
  WSubjet = -99;
  TopSoftMass = -99;
  TopSubjet = -99;
  w_Btag=1;
  w_BtagUp=1;
  w_BtagDown=1;
  w_Btag1Up=1;
  w_Btag1Down=1;
  w_Btag2Up=1;
  w_Btag2Down=1;
  w_BtagLoose=1;
  w_BtagLooseUp=1;
  w_BtagLooseDown=1;
  w_QCDUp=1;
  w_QCDDown=1;
  w_PDFUp=1;
  w_PDFDown=1;
  genWeight=1;
  GenZPt=-99.;
  GenWPt=-99.;
  dQuark=0;
  uQuark=0;
  sQuark=0;
  cQuark=0;
  bQuark=0;
  tQuark=0;
  TriggeringElePt  = -1.;
  TriggeringMuoPt  = -1.;
  TriggeringEleEta = -1.;
  TriggeringMuoEta = -1.;
  TransverseMassMetTop = -99;
}/*}}}*/
//?filename not occur
//
void branchGetEntry(bool data, Long64_t tentry, string fileName){/*{{{*/
 //GetEntry?
 //?is that OK fileName not in the function?
  b_Jet_pt->GetEntry(tentry);//is a branch in tree, setadress.
  b_Jet_eta->GetEntry(tentry);
  b_Jet_phi->GetEntry(tentry);
  b_Jet_mass->GetEntry(tentry);
  b_Jet_JesSF->GetEntry(tentry);
  b_Jet_JesSFup->GetEntry(tentry);
  b_Jet_JesSFdown->GetEntry(tentry);
  b_Jet_JerSF->GetEntry(tentry);
  b_Jet_JerSFup->GetEntry(tentry);
  b_Jet_JerSFdown->GetEntry(tentry);
  b_Jet_Uncorr_pt->GetEntry(tentry);
  b_Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags->GetEntry(tentry);
  b_Jet_pfDeepCSVBJetTags->GetEntry(tentry);
  b_Jet_pfDeepFlavourBJetTags->GetEntry(tentry);
  b_Jet_neutralHadEnergyFraction->GetEntry(tentry);
  b_Jet_chargedEmEnergyFraction->GetEntry(tentry);
  b_Jet_neutralEmEnergyFraction->GetEntry(tentry);
  b_Jet_numberOfConstituents->GetEntry(tentry);
  b_Jet_chargedHadronEnergyFraction->GetEntry(tentry);
  b_Jet_chargedMultiplicity->GetEntry(tentry);
  if(!data) b_Jet_hadronFlavour->GetEntry(tentry);
  b_Jet_muonEnergyFraction->GetEntry(tentry);
/*  b_BoostedJet_pt->GetEntry(tentry);
  b_BoostedJet_Uncorr_pt->GetEntry(tentry);
  b_BoostedJet_softdrop_mass->GetEntry(tentry);
  b_BoostedJet_puppi_softdrop_mass->GetEntry(tentry);
  b_BoostedJet_JesSF->GetEntry(tentry);
  b_BoostedJet_JesSFup->GetEntry(tentry);
  b_BoostedJet_JesSFdown->GetEntry(tentry);
  b_BoostedJet_JerSF->GetEntry(tentry);
  b_BoostedJet_JerSFup->GetEntry(tentry);
  b_BoostedJet_JerSFdown->GetEntry(tentry);
  b_BoostedJet_eta->GetEntry(tentry);
  b_BoostedJet_phi->GetEntry(tentry);
  b_BoostedJet_mass->GetEntry(tentry);
  b_BoostedJet_tau1->GetEntry(tentry);
  b_BoostedJet_tau2->GetEntry(tentry);
  b_BoostedJet_tau3->GetEntry(tentry);
  b_BoostedJet_puppi_tau1->GetEntry(tentry);
  b_BoostedJet_puppi_tau2->GetEntry(tentry);
  b_BoostedJet_puppi_tau3->GetEntry(tentry);
  b_BoostedJet_pruned_mass->GetEntry(tentry);
  b_BoostedJet_neutralHadEnergyFraction->GetEntry(tentry);
  b_BoostedJet_neutralEmEnergyFraction->GetEntry(tentry);
  b_BoostedJet_chargedEmEnergyFraction->GetEntry(tentry);
  //b_BoostedJet_neutralEmEmEnergyFraction->GetEntry(tentry);
  b_BoostedJet_numberOfConstituents->GetEntry(tentry);
  b_BoostedJet_chargedHadronEnergyFraction->GetEntry(tentry);
  b_BoostedJet_chargedMultiplicity->GetEntry(tentry);*/
  //b_TopTagging_topMass->GetEntry(tentry);
  //b_TopTagging_minMass->GetEntry(tentry);
  //b_TopTagging_nSubJets->GetEntry(tentry);
  b_patElectron_pt->GetEntry(tentry);
  b_patElectron_eta->GetEntry(tentry);
  b_patElectron_phi->GetEntry(tentry);
  b_patElectron_energy->GetEntry(tentry);
  //b_patElectron_energyCorr->GetEntry(tentry);
  b_patElectron_SCeta->GetEntry(tentry);
  b_patElectron_charge->GetEntry(tentry);
  b_patElectron_Et->GetEntry(tentry);
  b_patElectron_pdgId->GetEntry(tentry);
  b_patElectron_relIsoDeltaBeta->GetEntry(tentry);
  b_patElectron_relIsoRhoEA_Update->GetEntry(tentry);
  b_patElectron_gen_pdgId->GetEntry(tentry);
  b_patElectron_gen_isDirectPromptTauDecayProductFinalState->GetEntry(tentry);
  //->GetEntry(tentry);
  b_patElectron_mvaEleID_Fall17_noIso_V2_wp80->GetEntry(tentry);
  b_patElectron_mvaEleID_Fall17_iso_V2_wp80->GetEntry(tentry);
  b_patElectron_mvaEleID_Fall17_iso_V2_wp90->GetEntry(tentry);
  b_patElectron_mvaEleID_Fall17_noIso_V2_wp90->GetEntry(tentry);
  b_patElectron_mvaEleID_Fall17_iso_V2_wpLoose->GetEntry(tentry);
  b_patElectron_mvaEleID_Fall17_noIso_V2_wpLoose->GetEntry(tentry);
  b_patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Values->GetEntry(tentry);
  b_patElectron_ElectronMVAEstimatorRun2Fall17NoIsoV2Categories->GetEntry(tentry);
  b_patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Values->GetEntry(tentry);
  b_patElectron_ElectronMVAEstimatorRun2Fall17IsoV2Categories->GetEntry(tentry);
  b_patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp80->GetEntry(tentry);
  b_patElectron_mvaEleID_Spring16_GeneralPurpose_V1_wp90->GetEntry(tentry);
  b_patElectron_MVAValue_ElectronMVAEstimatorRun2Spring16GeneralPurposeV1->GetEntry(tentry);
  b_patElectron_cutBasedElectronID_Fall17_94X_V2_loose->GetEntry(tentry);
  b_patElectron_cutBasedElectronID_Fall17_94X_V2_medium->GetEntry(tentry);
  b_patElectron_cutBasedElectronID_Fall17_94X_V2_tight->GetEntry(tentry);
  b_patElectron_cutBasedElectronID_Fall17_94X_V2_veto->GetEntry(tentry);
  b_patElectron_heepElectronID_HEEPV70->GetEntry(tentry);
//  ->GetEntry(tentry);
/*  b_patElectron_isPassVeto->GetEntry(tentry);          
  b_patElectron_isPassLoose->GetEntry(tentry);
  b_patElectron_isPassMedium->GetEntry(tentry);
  b_patElectron_isPassTight->GetEntry(tentry);
  b_patElectron_isPassHEEPId->GetEntry(tentry);*/
  b_patElectron_passConversionVeto->GetEntry(tentry); 
  b_patElectron_inCrack->GetEntry(tentry);
  b_patElectron_isMatchedToTrigger->GetEntry(tentry);
  b_Muon_pt->GetEntry(tentry);
  b_Muon_eta->GetEntry(tentry);
  b_Muon_phi->GetEntry(tentry);
  b_Muon_energy->GetEntry(tentry);
  b_Muon_charge->GetEntry(tentry);
  b_Muon_tight->GetEntry(tentry);
  b_Muon_loose->GetEntry(tentry);
  b_Muon_medium->GetEntry(tentry);       
  b_Muon_relIsoDeltaBetaR04->GetEntry(tentry);
  b_Muon_miniIsoRel->GetEntry(tentry);
  b_Muon_ptrel->GetEntry(tentry);
  b_Muon_jetptratio->GetEntry(tentry);
  b_Muon_jetptratioV2->GetEntry(tentry);

  b_Muon_isMatchedToTrigger->GetEntry(tentry);

  b_TopTagger_type->GetEntry(tentry);
  b_TopTagger_discriminator->GetEntry(tentry);
  b_TopTagger_jet1Idx->GetEntry(tentry);
  b_TopTagger_jet2Idx->GetEntry(tentry);
  b_TopTagger_jet3Idx->GetEntry(tentry);

  b_Tau_pt->GetEntry(tentry);
  b_Tau_eta->GetEntry(tentry);
  b_Tau_leadChargedCandDz_pv->GetEntry(tentry);
  b_Tau_packedLeadTauCand_dz->GetEntry(tentry);
  b_Tau_phi->GetEntry(tentry);
  b_Tau_energy->GetEntry(tentry);
  b_Tau_px->GetEntry(tentry);
  b_Tau_pz->GetEntry(tentry);
  b_Tau_p->GetEntry(tentry);
  b_Tau_charge->GetEntry(tentry);
  b_Tau_decayModeFinding->GetEntry(tentry);
  b_Tau_decayModeFindingNewDMs->GetEntry(tentry);
  b_Tau_decayMode->GetEntry(tentry);
  b_Tau_againstMuonLoose3->GetEntry(tentry);
  b_Tau_againstMuonTight3->GetEntry(tentry);
  b_Tau_byDeepTau2017v2p1VSjetraw->GetEntry(tentry);
  b_Tau_byVVVLooseDeepTau2017v2p1VSjet->GetEntry(tentry);
  b_Tau_byVVLooseDeepTau2017v2p1VSjet->GetEntry(tentry);
  b_Tau_byVLooseDeepTau2017v2p1VSjet->GetEntry(tentry);
  b_Tau_byLooseDeepTau2017v2p1VSjet->GetEntry(tentry);
  b_Tau_byMediumDeepTau2017v2p1VSjet->GetEntry(tentry);
  b_Tau_byTightDeepTau2017v2p1VSjet->GetEntry(tentry);
  b_Tau_byVTightDeepTau2017v2p1VSjet->GetEntry(tentry);
  b_Tau_byVVTightDeepTau2017v2p1VSjet->GetEntry(tentry);
  b_Tau_byDeepTau2017v2p1VSmuraw->GetEntry(tentry);
  b_Tau_byVLooseDeepTau2017v2p1VSmu->GetEntry(tentry);
  b_Tau_byLooseDeepTau2017v2p1VSmu->GetEntry(tentry);
  b_Tau_byMediumDeepTau2017v2p1VSmu->GetEntry(tentry);
  b_Tau_byTightDeepTau2017v2p1VSmu->GetEntry(tentry);
  b_Tau_byDeepTau2017v2p1VSeraw->GetEntry(tentry);
  b_Tau_byVVVLooseDeepTau2017v2p1VSe->GetEntry(tentry);
  b_Tau_byVVLooseDeepTau2017v2p1VSe->GetEntry(tentry);
  b_Tau_byVLooseDeepTau2017v2p1VSe->GetEntry(tentry);
  b_Tau_byLooseDeepTau2017v2p1VSe->GetEntry(tentry);
  b_Tau_byMediumDeepTau2017v2p1VSe->GetEntry(tentry);
  b_Tau_byTightDeepTau2017v2p1VSe->GetEntry(tentry);
  b_Tau_byVTightDeepTau2017v2p1VSe->GetEntry(tentry);
  b_Tau_byVVTightDeepTau2017v2p1VSe->GetEntry(tentry);
//  ->GetEntry(tentry);
  b_Met_type1PF_pt->GetEntry(tentry);
  b_Met_type1PF_phi->GetEntry(tentry);
  b_Met_type1PF_sumEt->GetEntry(tentry);
  b_HLT_DoubleEle33_CaloIdL_MW->GetEntry(tentry);
   b_HLT_Mu50->GetEntry(tentry);
   b_HLT_TkMu50->GetEntry(tentry);
   // b_HLT_PFHT500_PFMET100_PFMHT100_IDTight->GetEntry(tentry);
   // b_HLT_PFHT700_PFMET85_PFMHT85_IDTight->GetEntry(tentry);
   // b_HLT_PFHT800_PFMET75_PFMHT75_IDTight->GetEntry(tentry);
// b_HLT_PFMET120_PFMHT120_IDTight->GetEntry(tentry);
//  b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight->GetEntry(tentry);
  // b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight->GetEntry(tentry);
  // b_HLT_CaloJet500_NoJetID->GetEntry(tentry);
  // b_HLT_AK8PFJet500->GetEntry(tentry);
  // b_HLT_PFJet500->GetEntry(tentry);
  // b_HLT_PFHT1050->GetEntry(tentry);
  //
  //
  b_HLT_PFHT900->GetEntry(tentry);
  b_HLT_PFHT450_SixJet40_BTagCSV_p056->GetEntry(tentry);
  b_HLT_PFHT400_SixJet30_DoubleBTagCSV_p056 ->GetEntry(tentry);
 //
 //
  b_Flag_goodVertices->GetEntry(tentry);
  //b_Flag_CSCTightHalo2015Filter->GetEntry(tentry);
  b_Flag_HBHENoiseFilter->GetEntry(tentry);
  b_Flag_HBHENoiseIsoFilter->GetEntry(tentry);
  b_Flag_EcalDeadCellTriggerPrimitiveFilter->GetEntry(tentry);
  b_Flag_BadPFMuonFilter->GetEntry(tentry);
  b_Flag_BadChargedCandidateFilter->GetEntry(tentry);
//  b_Flag_ecalBadCalibReducedMINIAODFilter->GetEntry(tentry);
  b_Flag_eeBadScFilter->GetEntry(tentry);
  b_Flag_METFilters->GetEntry(tentry);//add
  b_Flag_globalSuperTightHalo2016Filter->GetEntry(tentry);
  b_nBestVtx->GetEntry(tentry);
  b_PUWeight->GetEntry(tentry);
  //b_PUWeightUP->GetEntry(tentry);
  //b_PUWeightDOWN->GetEntry(tentry);
  b_EVENT_run->GetEntry(tentry);
  b_EVENT_event->GetEntry(tentry);
  b_EVENT_lumiBlock->GetEntry(tentry);
  b_EVENT_genHT->GetEntry(tentry);
  b_EVENT_prefireWeight->GetEntry(tentry);
  b_EVENT_prefireWeightUp->GetEntry(tentry);
  b_EVENT_prefireWeightDown->GetEntry(tentry);
  b_genWeight->GetEntry(tentry);
  if(!data) b_Gen_pt->GetEntry(tentry);
  if(!data) b_Gen_eta->GetEntry(tentry);
  if(!data) b_Gen_phi->GetEntry(tentry);
  if(!data) b_Gen_pdg_id->GetEntry(tentry);
  if(!data) b_Gen_motherpdg_id->GetEntry(tentry);
  b_genWeights->GetEntry(tentry);
}/*}}}*/

void HistoFill(double puweight,TTree *NewTree){
	//?has nothing to do with puweigh,why use puweight then?
  NewTree->Fill();
}
/*
void writeFile(TTree *NewTree,TTree *NewTreeSB){
  NewTree->Write();
  NewTreeSB->Write();
}*/

void GenClassifier(double &GenZPt_,double &GenWPt_){/*{{{*/
    for (UInt_t j = 0; j < Gen_pt_->size(); ++j) {
    //cout<<j<<" "<<Gen_pdg_id_->at(j)<<" "<<Gen_motherpdg_id_->at(j)<<" "<<Gen_pt_->at(j)<<endl;
	//std::string::at can be used to extract characters by characters from a given string.
	//?what is Gen_pt? is Gen_pt of the final state? if so, how can we have Z and W ?
    if(abs(Gen_pdg_id_->at(j))==1 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) dQuark = dQuark + 1;//dQuark a branch in newtree and newtreeSB
    if(abs(Gen_pdg_id_->at(j))==2 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) uQuark = uQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==3 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) sQuark = sQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==4 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) cQuark = cQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==5 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) bQuark = bQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==6 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) tQuark = tQuark + 1;
	if(abs(Gen_pdg_id_->at(j))==23) GenZPt_ = Gen_pt_->at(j);// in function GenWeight
	if(abs(Gen_pdg_id_->at(j))==24) GenWPt_ = Gen_pt_->at(j);
  }
}/*}}}*/


void GenWBoson(bool &matched, TLorentzVector Wjet){/*{{{*/
  double dr1=99;  double dr2=99;  double dr3=99;  double dr4=99;  double dr5=99;  double dr6=99; 
  double dr7=99;  double dr8=99;  double dr9=99;  double dr10=99; double dr11=99; double dr12=99; 
  double dr13=99; double dr14=99; double dr15=99; double dr16=99; double dr17=99; double dr18=99; 
  for (UInt_t j = 0; j < Gen_pt_->size(); ++j) {
    //cout<<j<<" "<<Gen_pdg_id_->at(j)<<" "<<Gen_motherpdg_id_->at(j)<<" "<<Gen_pt_->at(j)<<endl;
    if(abs(Gen_pdg_id_->at(j))==1 && abs(Gen_motherpdg_id_->at(j))==24) dr1 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(abs(Gen_pdg_id_->at(j))==2 && abs(Gen_motherpdg_id_->at(j))==24) dr2 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(abs(Gen_pdg_id_->at(j))==3 && abs(Gen_motherpdg_id_->at(j))==24) dr3 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(abs(Gen_pdg_id_->at(j))==4 && abs(Gen_motherpdg_id_->at(j))==24) dr4 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(abs(Gen_pdg_id_->at(j))==5 && abs(Gen_motherpdg_id_->at(j))==24) dr5 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(abs(Gen_pdg_id_->at(j))==6 && abs(Gen_motherpdg_id_->at(j))==24) dr6 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==1 && abs(Gen_motherpdg_id_->at(j))==23) dr7 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==2 && abs(Gen_motherpdg_id_->at(j))==23) dr8 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==3 && abs(Gen_motherpdg_id_->at(j))==23) dr9 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==4 && abs(Gen_motherpdg_id_->at(j))==23) dr10= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==5 && abs(Gen_motherpdg_id_->at(j))==23) dr11= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==6 && abs(Gen_motherpdg_id_->at(j))==23) dr12= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-1&& abs(Gen_motherpdg_id_->at(j))==23) dr13= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-2&& abs(Gen_motherpdg_id_->at(j))==23) dr14= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-3&& abs(Gen_motherpdg_id_->at(j))==23) dr15= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-4&& abs(Gen_motherpdg_id_->at(j))==23) dr16= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-5&& abs(Gen_motherpdg_id_->at(j))==23) dr17= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-6&& abs(Gen_motherpdg_id_->at(j))==23) dr18= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
  }
  if((dr2 <0.8 && dr1 <0.8) || (dr2 <0.8 && dr3 <0.8) || (dr2 <0.8 && dr5 <0.8)) matched=true; //W -> ud/us/ub
  if((dr4 <0.8 && dr1 <0.8) || (dr4 <0.8 && dr3 <0.8) || (dr4 <0.8 && dr5 <0.8)) matched=true; //W -> cd/cs/cb
  //if((dr7 <0.8 && dr13<0.8) || (dr8 <0.8 && dr14<0.8) || (dr9 <0.8 && dr15<0.8)) matched=true; //Z -> dd/uu/ss
  //if((dr10<0.8 && dr16<0.8) || (dr11<0.8 && dr17<0.8) || (dr12<0.8 && dr18<0.8)) matched=true; //Z -> cc/bb/tt
}/*}}}*/

//?what is GenWeight doing?
/*
void GenWeight(string fileName, double GenZPt_,double GenWPt_){
  genWeight=(genWeight_)/abs(genWeight_);// genWeight_ in Tree, genWeight in NewTree
  //?what is genWeight? what does it do?
  if(fileName.find("DY")!=string::npos || fileName.find("ZToNuNu")!=string::npos) {
    if(GenZPt_>0) genWeight = functZPt->Eval(GenZPt_);//functZPt TF1 in .h 102
	//Eval, evaluation of Chebyshev polynomials
    else genWeight = 1;
    }
  if(fileName.find("WToLNu")!=string::npos) {
    if(GenWPt_>0) genWeight = functWPt->Eval(GenWPt_);
    else genWeight = 1;
    }

}
*/
/*
void newPUWeight(double &puweight,double &puweightUP,double &puweightDOWN){
  double *npuProbs = 0;
  double *npuProbsNEW = 0;
  unsigned int nPUMax = 99;
	//?whatis these?
  double npu_Moriond18Scenario[99] =  {3.39597497605e-05,6.63688402133e-06,1.39533611284e-05,3.64963078209e-05,6.00872171664e-05,9.33932578027e-05,0.000120591524486,0.000128694546198,0.000361697233219,0.000361796847553,0.000702474896113,0.00133766053707,0.00237817050805,0.00389825605651,0.00594546732588,0.00856825906255,0.0116627396044,0.0148793350787,0.0179897368379,0.0208723871946,0.0232564170641,0.0249826433945,0.0262245860346,0.0272704617569,0.0283301107549,0.0294006137386,0.0303026836965,0.0309692426278,0.0308818046328,0.0310566806228,0.0309692426278,0.0310566806228,0.0310566806228,0.0310566806228,0.0307696426944,0.0300103336052,0.0288355370103,0.0273233309106,0.0264343533951,0.0255453758796,0.0235877272306,0.0215627588047,0.0195825559393,0.0177296309658,0.0160560731931,0.0146022004183,0.0134080690078,0.0129586991411,0.0125093292745,0.0124360740539,0.0123547104433,0.0123953922486,0.0124360740539,0.0124360740539,0.0123547104433,0.0124360740539,0.0123387597772,0.0122414455005,0.011705203844,0.0108187105305,0.00963985508986,0.00827210065136,0.00683770076341,0.00545237697118,0.00420456901556,0.00367513566191,0.00314570230825,0.0022917978982,0.00163221454973,0.00114065309494,0.000784838366118,0.000533204105387,0.000358474034915,0.000238881117601,0.0001984254989,0.000157969880198,0.00010375646169,6.77366175538e-05,4.39850477645e-05,2.84298066026e-05,1.83041729561e-05,1.17473542058e-05,7.51982735129e-06,6.16160108867e-06,4.80337482605e-06,3.06235473369e-06,1.94863396999e-06,1.23726800704e-06,7.83538083774e-07,4.94602064224e-07,3.10989480331e-07,1.94628487765e-07,1.57888581037e-07,1.2114867431e-07,7.49518929908e-08,4.6060444984e-08,2.81008884326e-08,1.70121486128e-08,1.02159894812e-08};
  double npu_Moriond18ScenarioNEW[99] =  {0.0164731,0.000829522,0.000939881,0.000589732,0.000665918,0.00111637,0.00125813,0.000933965,0.00145441,0.00184519,0.00159332,0.00242139,0.00314767,0.00548591,0.00684822,0.010836,0.0130551,0.0144512,0.0182305,0.0212894,0.0216204,0.0229435,0.0243586,0.0243769,0.0249553,0.0269723,0.0255303,0.0269896,0.0277803,0.0279493,0.0271844,0.0273721,0.0293261,0.0282731,0.0287164,0.0283037,0.0265103,0.0255473,0.0240064,0.0233137,0.0232938,0.0224567,0.0196284,0.0156212,0.0137627,0.0136596,0.0128352,0.0120469,0.0128242,0.0121217,0.0136477,0.0136083,0.0134189,0.0129351,0.0141632,0.0136156,0.0141845,0.0124658,0.0128498,0.0125589,0.0102669,0.0092894,0.00807026,0.00702602,0.0047661,0.00401915,0.00351898,0.00288564,0.00166122,0.0015046,0.000773104,0.000499557,0.000796673,0.0006105,0.000630528,0.000145819,0.000191135,0.000340493,0.000193567,0.000678164,0.000393724,0.000442431,0.000641926,0.000615461,0.000139089,0.000793345,0.000240982,0.00049623,0.00010741,0.000147015,0.0002128,1.14866e-05,1.75821e-05,9.66776e-05,3.37481e-05,0.000457706,2.37272e-07,4.74544e-07,9.06185e-05};
  npuProbs = npu_Moriond18Scenario;
  npuProbsNEW = npu_Moriond18ScenarioNEW;
  std::vector<double> result(nPUMax,0.);
  std::vector<double> resultNEW(nPUMax,0.);
  std::vector<double> resultNEWUp(nPUMax,0.);
  std::vector<double> resultNEWDo(nPUMax,0.);
  double s = 0.;
  double sNEW   = 0.;
  double sNEWUp = 0.;
  double sNEWDo = 0.;
  for(unsigned int npu = 0; npu < nPUMax; ++npu) {
    const double npu_estimated = histoOldPU ->GetBinContent(histoOldPU ->GetXaxis()->FindBin(npu));//histoOldPU in header 98
    result[npu] = npu_estimated / npuProbs[npu];
    s += npu_estimated;
    const double npu_estimatedNEW   = histoNewPU  ->GetBinContent(histoNewPU  ->GetXaxis()->FindBin(npu));
    const double npu_estimatedNEWUp = histoNewPUUp->GetBinContent(histoNewPUUp->GetXaxis()->FindBin(npu));
    const double npu_estimatedNEWDo = histoNewPUDo->GetBinContent(histoNewPUDo->GetXaxis()->FindBin(npu));
    resultNEW[npu]   = npu_estimatedNEW   / npuProbsNEW[npu];
    resultNEWUp[npu] = npu_estimatedNEWUp / npuProbsNEW[npu];
    resultNEWDo[npu] = npu_estimatedNEWDo / npuProbsNEW[npu];
    sNEW   += npu_estimatedNEW;
    sNEWUp += npu_estimatedNEWUp;
    sNEWDo += npu_estimatedNEWDo;
  }
  unsigned int NPU = -1;              
  for(unsigned int npu = 0; npu < nPUMax; ++npu) {
    result[npu] /= s;
    resultNEW[npu]   /= sNEW;
    resultNEWUp[npu] /= sNEWUp;
    resultNEWDo[npu] /= sNEWDo;
    //if(result[npu]==PUWeight_) NPU = npu;
    if(result[npu]<PUWeight_*1.0001 && result[npu]>PUWeight_*0.9999) NPU = npu;
  }
  if (NPU==-1) return;
  //cout<<NPU<<" "<<PUWeight_<<" "<<resultNEW[NPU]<<" "<<resultNEWUp[NPU]<<endl;
  if(resultNEW[NPU]<9999)   puweight     = resultNEW[NPU];
  if(resultNEWUp[NPU]<9999) puweightUP   = resultNEWUp[NPU];
  if(resultNEWDo[NPU]<9999) puweightDOWN = resultNEWDo[NPU];
  getTrueNumInteractions=NPU;
}
*/
void WriteTopRelatedBranches(bool ResolvedEvent,TLorentzVector HadronicTopQuark,bool SelectedMet,TLorentzVector HadronicTopQuarkResolved,TLorentzVector Jet1Resolved,TLorentzVector Jet2Resolved,TLorentzVector Jet3Resolved,vector<TLorentzVector> SelectedForwardJets,vector<TLorentzVector> SelectedBJets){/*{{{*/
  int NumSelBJets = SelectedBJets.size();
  if(ResolvedEvent){
    TopMass=HadronicTopQuark.M();
    TopPt  =HadronicTopQuark.Pt();
    TopEta =HadronicTopQuark.Eta();
    TopPhi =HadronicTopQuark.Phi();
  }
	//?why the same condition in two parts?
  if(ResolvedEvent){
    TopMassResolved=HadronicTopQuarkResolved.M();//branch in NewTree and SB
    TopPtResolved=HadronicTopQuarkResolved.Pt();
    TopEtaResolved=HadronicTopQuarkResolved.Eta();
    TopPhiResolved=HadronicTopQuarkResolved.Phi();
    Jet1ResolvedPt = Jet1Resolved.Pt();
    Jet2ResolvedPt = Jet2Resolved.Pt(); 
    Jet3ResolvedPt = Jet3Resolved.Pt();
    Jet1ResolvedEta = Jet1Resolved.Eta();
    Jet2ResolvedEta = Jet2Resolved.Eta(); 
    Jet3ResolvedEta = Jet3Resolved.Eta();
    WMassResolved1 = (Jet1Resolved+Jet2Resolved).M();
    WMassResolved2 = (Jet1Resolved+Jet3Resolved).M();
    WMassResolved3 = (Jet2Resolved+Jet3Resolved).M();
  }
  if(SelectedForwardJets.size()>0) Jet1ForwardPt=SelectedForwardJets[0].Pt();
  if(SelectedForwardJets.size()>1) Jet2ForwardPt=SelectedForwardJets[1].Pt();
  if(SelectedForwardJets.size()>2) Jet3ForwardPt=SelectedForwardJets[2].Pt();
  if(SelectedForwardJets.size()>0) Jet1ForwardEta=SelectedForwardJets[0].Eta();
  if(SelectedForwardJets.size()>1) Jet2ForwardEta=SelectedForwardJets[1].Eta();
  if(SelectedForwardJets.size()>2) Jet3ForwardEta=SelectedForwardJets[2].Eta();
}/*}}}*/
