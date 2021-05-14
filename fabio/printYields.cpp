#include "printYields.h"

void printYields(string cat) {

  TFile *inputfile  = new TFile( "Histograms_chain_v40.root", "READ" );
  
  //scale the histograms for all the processes to the 2016 luminosity
  map<string, float>::iterator xsec_it = xsec.begin();
  while (xsec_it != xsec.end()) {
    TH1D* genEvts = (TH1D*)inputfile->Get( (xsec_it->first + "_GenEventWeight").c_str() );
    TH1F* h = (TH1F*)inputfile->Get( (xsec_it->first + "_" + cat).c_str() );
    h->Scale(xsec_it->second * LUMI2016 / genEvts->GetSumOfWeights());
    scaledYield.insert( {xsec_it->first, *h} );
    //cout << xsec_it->first << endl;
    delete h;
    xsec_it++;
  }

  tttt = scaledYield["tttt"];

  ttbar = scaledYield["ttbar-FH"];
  ttbar.Add(&scaledYield["ttbar-SL"]);
  ttbar.Add(&scaledYield["ttbar-DL"]);
  ttbar_FH = scaledYield["ttbar-FH"];
  ttbar_SL = scaledYield["ttbar-SL"];
  ttbar_DL = scaledYield["ttbar-DL"];

  ttbar_incl = scaledYield["ttbar-incl"];

  ttGjets = scaledYield["ttG+jets"];
  ttWjets = scaledYield["ttW+jets"];
  ttZjets = scaledYield["ttZ+jets"];
  ttH = scaledYield["ttH"];

  QCD_HT200to300 = scaledYield["QCD_HT200to300"];
  QCD_HT300to500 = scaledYield["QCD_HT300to500"];
  QCD_HT500to700 = scaledYield["QCD_HT500to700"];
  QCD_HT700to1000 = scaledYield["QCD_HT700to1000"];
  QCD_HT1000to1500 = scaledYield["QCD_HT1000to1500"];
  QCD_HT1500to2000 = scaledYield["QCD_HT1500to2000"];
  QCD_HT2000toInf = scaledYield["QCD_HT2000toInf"];


/*
  ttX = scaledYield["ttG-SL"];
  ttX.Add(&scaledYield["ttG-DL"]);
  ttX.Add(&scaledYield["ttW+jets"]);
  //ttX.Add(&scaledYield["ttZ+jets"]);
  ttX.Add(&scaledYield["ttH"]);

  VV = scaledYield["WZ"];
  //VV.Add(&scaledYield["WWTo2L2Nu"]);
  VV.Add(&scaledYield["WW"]);
  VV.Add(&scaledYield["ZZ"]);
  VV.Add(&scaledYield["WG+jets"]);
  VV.Add(&scaledYield["ZG+jets"]);

  VVV = scaledYield["WWW"];
  VVV.Add(&scaledYield["WWZ"]);
  //VVV.Add(&scaledYield["WWG"]);
  VVV.Add(&scaledYield["ZZZ"]);
  VVV.Add(&scaledYield["WZG"]);
  VVV.Add(&scaledYield["WGG"]);
  VVV.Add(&scaledYield["ZGG+jets"]);
  
  //WJets = scaledYield["W+jets"];

  DY = scaledYield["DY"];

  ST = scaledYield["tZq"];
  ST.Add(&scaledYield["tW_antitop"]);
  ST.Add(&scaledYield["tW_top"]);
  //ST.Add(&scaledYield["tG+jets"]);
  ST.Add(&scaledYield["tHW"]);
  ST.Add(&scaledYield["THq"]);

  H = scaledYield["VHToNonbb"];
  //H.Add(&scaledYield["ZHToTauTau"]);
  H.Add(&scaledYield["ZHTobb"]);
  //H.Add(&scaledYield["GluGluHTo4L"]);
  H.Add(&scaledYield["GluGluHTobb"]);
  H.Add(&scaledYield["GluGluHToGG"]);
  H.Add(&scaledYield["GluGluHToMuMu"]);
  H.Add(&scaledYield["GluGluHToTauTau"]);
  H.Add(&scaledYield["GluGluHTo2L2Nu"]);
  H.Add(&scaledYield["GluGluHToLNuqq"]);
  H.Add(&scaledYield["VBFHTo2L2Nu"]);
  H.Add(&scaledYield["VBFHToMuMu"]);
  H.Add(&scaledYield["VBFHToGG"]);
  */
  //total_bkg = ttbar;
  //cout << "0" << endl;
  //total_bkg.Add(&ttX);
  //cout << "1" << endl;
  //total_bkg.Add(&VV);
  //cout << "2" << endl;
  //total_bkg.Add(&VVV);
  //cout << "3" << endl;
  //total_bkg.Add(&WJets);
  //cout << "4" << endl;
  //total_bkg.Add(&DY);
  //cout << "5" << endl;
  //total_bkg.Add(&ST);
  //cout << "6" << endl;
  //total_bkg.Add(&H);
  //cout << "7" << endl;

  cout << " " << endl << " ~~~ 2016 expected yields for category " + cat +" ~~~" << endl << " " << endl;
  cout << setw(12) << left << "tttt =" << setw(12) << left << tttt.Integral() << endl;
  cout << setw(12) << left << "ttbar =" << setw(12) << left << ttbar.Integral() << endl;
  cout << setw(12) << left << "ttbar_FH =" << setw(12) << left << ttbar_FH.Integral() << endl;
  cout << setw(12) << left << "ttbar_SL =" << setw(12) << left << ttbar_SL.Integral() << endl;
  cout << setw(12) << left << "ttbar_DL =" << setw(12) << left << ttbar_DL.Integral() << endl;
  cout << setw(12) << left << "ttbar_incl =" << setw(12) << left << ttbar_incl.Integral() << endl;
  cout << setw(12) << left << "ttG+jets =" << setw(12) << left << ttGjets.Integral() << endl;
  cout << setw(12) << left << "ttW+jets =" << setw(12) << left << ttWjets.Integral() << endl;
  cout << setw(12) << left << "ttZ+jets =" << setw(12) << left << ttZjets.Integral() << endl;
  cout << setw(12) << left << "ttH =" << setw(12) << left << ttH.Integral() << endl;

  cout << setw(12) << left << "QCD_HT200to300 =" << setw(12) << left << QCD_HT200to300.Integral() << endl;
  cout << setw(12) << left << "QCD_HT300to500 =" << setw(12) << left << QCD_HT300to500.Integral() << endl;
  cout << setw(12) << left << "QCD_HT500to700 =" << setw(12) << left << QCD_HT500to700.Integral() << endl;
  cout << setw(12) << left << "QCD_HT700to1000 =" << setw(12) << left << QCD_HT700to1000.Integral() << endl;
  cout << setw(12) << left << "QCD_HT700to1500 =" << setw(12) << left << QCD_HT1000to1500.Integral() << endl;
  cout << setw(12) << left << "QCD_H1500to2000 =" << setw(12) << left << QCD_HT1500to2000.Integral() << endl;
  cout << setw(12) << left << "QCD_HT2000toInf =" << setw(12) << left << QCD_HT2000toInf.Integral() << endl;


  /*cout << setw(12) << left << "ttX =" << setw(12) << left << ttX.Integral() << endl;
  cout << setw(12) << left << "VV =" << setw(12) << left << VV.Integral() << endl;
  cout << setw(12) << left << "VVV =" << setw(12) << left << VVV.Integral() << endl;
  cout << setw(12) << left << "WJets =" << setw(12) << left << WJets.Integral() << endl;
  cout << setw(12) << left << "DY =" << setw(12) << left << DY.Integral() << endl;
  cout << setw(12) << left << "ST =" << setw(12) << left << ST.Integral() << endl;
  cout << setw(12) << left << "H =" << setw(12) << left << H.Integral() << endl;
  cout << setw(12) << left << "total bkg =" << setw(12) << left << total_bkg.Integral() << endl;
  cout << setw(12) << left << "S/(S+B) =" << setw(12) << left << tttt.Integral()/(tttt.Integral()+total_bkg.Integral()) << endl;*/
  cout << " " << endl;

  cout << " " << endl << " ~~~ 2016 expected statistics for category " + cat +" ~~~" << endl << " " << endl;
  cout << setw(12) << left << "tttt =" << setw(12) << left << tttt.GetEntries() << endl;
  cout << setw(12) << left << "ttbar =" << setw(12) << left << ttbar.GetEntries() << endl;
  cout << setw(12) << left << "ttbar_FH =" << setw(12) << left << ttbar_FH.GetEntries() << endl;
  cout << setw(12) << left << "ttbar_SL =" << setw(12) << left << ttbar_SL.GetEntries() << endl;
  cout << setw(12) << left << "ttbar_DL =" << setw(12) << left << ttbar_DL.GetEntries() << endl;
  cout << setw(12) << left << "ttbar_incl =" << setw(12) << left << ttbar_incl.GetEntries() << endl;
    cout << setw(12) << left << "ttG+jets =" << setw(12) << left << ttGjets.GetEntries() << endl;
  cout << setw(12) << left << "ttW+jets =" << setw(12) << left << ttWjets.GetEntries() << endl;
  cout << setw(12) << left << "ttZ+jets =" << setw(12) << left << ttZjets.GetEntries() << endl;
  cout << setw(12) << left << "ttH =" << setw(12) << left << ttH.GetEntries() << endl;

  cout << setw(12) << left << "QCD_HT200to300 =" << setw(12) << left << QCD_HT200to300.GetEntries() << endl;
  cout << setw(12) << left << "QCD_HT300to500 =" << setw(12) << left << QCD_HT300to500.GetEntries() << endl;
  cout << setw(12) << left << "QCD_HT500to700 =" << setw(12) << left << QCD_HT500to700.GetEntries() << endl;
  cout << setw(12) << left << "QCD_HT700to1000 =" << setw(12) << left << QCD_HT700to1000.GetEntries() << endl;
  cout << setw(12) << left << "QCD_HT700to1500 =" << setw(12) << left << QCD_HT1000to1500.GetEntries() << endl;
  cout << setw(12) << left << "QCD_H1500to2000 =" << setw(12) << left << QCD_HT1500to2000.GetEntries() << endl;
  cout << setw(12) << left << "QCD_HT2000toInf =" << setw(12) << left << QCD_HT2000toInf.GetEntries() << endl;
  /*cout << setw(12) << left << "ttX =" << setw(12) << left << ttX.GetEntries() << endl;
  cout << setw(12) << left << "VV =" << setw(12) << left << VV.GetEntries() << endl;
  cout << setw(12) << left << "VVV =" << setw(12) << left << VVV.GetEntries() << endl;
  cout << setw(12) << left << "WJets =" << setw(12) << left << WJets.GetEntries() << endl;
  cout << setw(12) << left << "DY =" << setw(12) << left << DY.GetEntries() << endl;
  cout << setw(12) << left << "ST =" << setw(12) << left << ST.GetEntries() << endl;
  cout << setw(12) << left << "H =" << setw(12) << left << H.GetEntries() << endl;
  cout << setw(12) << left << "total bkg =" << setw(12) << left << total_bkg.GetEntries() << endl;
  cout << " " << endl;*/
}

 
