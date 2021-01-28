#include <iostream>
#include <TH1F.h>
#include <TFile.h>
#include <TTree.h>
#include <TBenchmark.h>
#include "trigEff.h"

//using namespace std;

void trigEff() {

gBenchmark->Start("running time");

map<string, string>::iterator file_it = file.begin();

while (file_it != file.end()) { //////////////////////// LOOP OVER FILES ///////////////////////

cout << "Opening file " << file_it->second << "..." << endl;
TFile *inputfile  = new TFile( file_it->second.c_str(), "READ" );

//addressing branches
TTree *evt = (TTree*)inputfile->Get( "tree" );

int  mytausT_number = 0;
evt->SetBranchAddress( "tausT_number", &mytausT_number );

int  myleptonsMVAT_number = 0;
evt->SetBranchAddress( "leptonsMVAT_number", &myleptonsMVAT_number );

int  myjetsL_number = 0;
evt->SetBranchAddress( "jetsL_number", &myjetsL_number );

int  mybjetsM_number = 0;
evt->SetBranchAddress( "bjetsM_num", &mybjetsM_number );

int  myelesMVAT_number = 0;
evt->SetBranchAddress( "elesMVAT_number", &myelesMVAT_number );

int  mymuonsT_number = 0;
evt->SetBranchAddress( "muonsT_number", &mymuonsT_number );

int  myleptonsMVAT_2OS = 0;
evt->SetBranchAddress( "leptonsMVAT_2OS", &myleptonsMVAT_2OS );

int  myleptonsMVAT_2SS = 0;
evt->SetBranchAddress( "leptonsMVAT_2SS", &myleptonsMVAT_2SS );

double mygenEvtWeight = 0;
evt->SetBranchAddress( "EVENT_genWeight", &mygenEvtWeight );

vector<double> * myeleMVAT_pt = 0;
evt->SetBranchAddress( "eleMVAT_pt", &myeleMVAT_pt );

vector<double> * mymuonT_pt = 0;
evt->SetBranchAddress( "muonT_pt", &mymuonT_pt );

int myHLT_PFHT450_SixJet40_BTagCSV_p056 = 0;
evt->SetBranchAddress("HLT_PFHT450_SixJet40_BTagCSV_p056", &myHLT_PFHT450_SixJet40_BTagCSV_p056);

int myHLT_PFHT400_SixJet30_DoubleBTagCSV_p056 = 0;
evt->SetBranchAddress("HLT_PFHT400_SixJet30_DoubleBTagCSV_p056", &myHLT_PFHT400_SixJet30_DoubleBTagCSV_p056);

 double num = 0;
 double den = 0;

Long64_t nevents = evt->GetEntries();

for ( Long64_t ievent = 0; ievent < nevents; ++ievent ) {
  //if (ievent > 100) break;
  if ( !(ievent % 100000 ) ) cout << "ievent  =  " << ievent << endl;
   //get i-th entry in tree
   evt->GetEntry( ievent );

   /////////////////////////////////////////////////////////////////////
   ///////////////////// DEFINE CATEGORY CUTS //////////////////////////
   /////////////////////////////////////////////////////////////////////

 bool is1tau0L = (mytausT_number==1 && myleptonsMVAT_number==0 &&  myjetsL_number>=8 && mybjetsM_number>=2);
 bool is1tau0Ltrig = (myHLT_PFHT450_SixJet40_BTagCSV_p056 == 1 || myHLT_PFHT400_SixJet30_DoubleBTagCSV_p056 == 1);

 if (is1tau0L) {

   den += mygenEvtWeight;
   
   if (is1tau0Ltrig) num += mygenEvtWeight;

 }

 }//end loop over events
 
 cout << "trigger efficiency = " << num/den << endl;
 inputfile->Close();
 delete inputfile;
 file_it++;

 }//end loop over files

 gBenchmark->Show("running time");

}//end
