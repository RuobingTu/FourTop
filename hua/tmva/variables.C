// #include "/workfs2/cms/huahuil/4topCode/CMSSW_10_2_20_UL/src/FourTop/hua/tmva/tmvaglob.h"
#include "tmvaglob.h"

// this macro plots the distributions of the different input variables
// used in TMVA (e.g. running TMVAnalysis.C).  Signal and Background are overlayed.

// input: - Input file (result from TMVA),
//        - normal/decorrelated/PCA
//        - use of TMVA plotting TStyle
void variables( 
   //  TString fin = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v4modifiedMinDeltaR_fromV9/1tau2l_v1/1tau2lvaribleList_38.root",
   //  TString outDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v4modifiedMinDeltaR_fromV9/1tau2l_v1/results/variableDistribution/",
   //  TString fin = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v4modifiedMinDeltaR_fromV9/1tau2l_v2/1tau2l_variables.root",
   //  TString fin = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v2Add2Variables_fromV9/1tau1l_v3/1tau1l_variables.root",
   //  TString fin = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v2Add2Variables_fromV9/1tau1l_v3/1tau1lvaribleList_50.root",
    TString fin = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v2Add2Variables_fromV9/1tau1l_v3/1tau1lvaribleList_50.root",
	// TString outDir = "output/",
   // TString outDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v4modifiedMinDeltaR_fromV9/1tau2l_v2/results/65vars/",
   TString outDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v2Add2Variables_fromV9/1tau1l_v3/results/variablesDistribution/",
    TString title = "TMVA Input Variables",
        Bool_t isRegression = kFALSE, Bool_t useTMVAStyle = kTRUE )
{
        // TString dirName = "InputVariables_Id",
        TString dirName = "dataset/InputVariables_Id";
   TString outfname = dirName;
   outfname.ToLower(); 
//    outfname.ReplaceAll( "input", ""  );
   outfname.ReplaceAll( "dataset/", "" );

   // set style and remove existing canvas'
   TMVAGlob::Initialize( useTMVAStyle );

   // obtain shorter histogram title 
   TString htitle = title; 
   //?
   htitle.ReplaceAll("variables ","variable");
   htitle.ReplaceAll("and target(s)","");
   htitle.ReplaceAll("(training sample)","");

   // checks if file with name "fin" is already open, and if not opens one
   TFile* file = TMVAGlob::OpenFile( fin );

   TDirectory* dir = (TDirectory*)file->Get( dirName );//dirName is a dir in fin
   if (dir==0) {
      cout << "No information about " << title << " available in directory " << dirName << " of file " << fin << endl;
      return;
   }
   dir->cd();

   // how many plots are in the directory?
   Int_t noPlots = TMVAGlob::GetNumberOfInputVariables( dir ) +
      TMVAGlob::GetNumberOfTargets( dir );

   // define Canvas layout here!
   // default setting
   Int_t xPad;  // no of plots in x
   Int_t yPad;  // no of plots in y
   Int_t width; // size of canvas
   Int_t height;
   switch (noPlots) {
   case 1:
      xPad = 1; yPad = 1; width = 550; height = 0.90*width; break;
   case 2:
      xPad = 2; yPad = 1; width = 600; height = 0.50*width; break;
   case 3:
      xPad = 3; yPad = 1; width = 900; height = 0.4*width; break;
   case 4:
      xPad = 2; yPad = 2; width = 600; height = width; break;
   default:
      xPad = 3; yPad = 2; width = 800; height = 0.55*width; break;
   }

   Int_t noPadPerCanv = xPad * yPad ;

   // counter variables
   Int_t countCanvas = 0;
   Int_t countPad    = 0;

   // loop over all objects in directory
   TCanvas* canv = 0;
   TKey*    key  = 0;
   //?
   Bool_t   createNewFig = kFALSE;
   TIter next(dir->GetListOfKeys());
   while ((key = (TKey*)next())) {
      if (key->GetCycle() != 1) continue;

      if (!TString(key->GetName()).Contains("__Signal") && 
          !(isRegression && TString(key->GetName()).Contains("__Regression"))) continue;

      // make sure, that we only look at histograms
      TClass *cl = gROOT->GetClass(key->GetClassName());
      if (!cl->InheritsFrom("TH1")) continue;
      TH1 *sig = (TH1*)key->ReadObj();
      TString hname(sig->GetName());
      cout<<"hist entries: "<<sig->GetEntries()<<"\n";
      //hist entry is the training sample

      // create new canvas
      if (countPad%noPadPerCanv==0) {
         ++countCanvas;
         canv = new TCanvas( Form("canvas%d", countCanvas), title,
                             countCanvas*50+50, countCanvas*20, width, height );
         canv->Divide(xPad,yPad);
         canv->Draw();
      }

      TPad* cPad = (TPad*)canv->cd(countPad++%noPadPerCanv+1);
      
      // find the corredponding backgrouns histo
      TString bgname = hname;
      bgname.ReplaceAll("__Signal","__Background");
      TH1 *bgd = (TH1*)dir->Get(bgname);
      if (bgd == NULL) {
         cout << "ERROR!!! couldn't find background histo for" << hname << endl;
         return;
      }

      // this is set but not stored during plot creation in MVA_Factory
      TMVAGlob::SetSignalAndBackgroundStyle( sig, (isRegression ? 0 : bgd) );            

      sig->SetTitle( TString( htitle ) + ": " + sig->GetTitle() );
      TMVAGlob::SetFrameStyle( sig, 1.2 );

      // normalise both signal and background
      if (!isRegression) TMVAGlob::NormalizeHists( sig, bgd );
      else {
         // change histogram title for target
         TString nme = sig->GetName();
         if (nme.Contains( "_target" )) {
            TString tit = sig->GetTitle();
            sig->SetTitle( tit.ReplaceAll("Input variable", "Regression target" ) );
         }
      }

      // finally plot and overlay
      Float_t sc = 1.1;
      if (countPad == 1) sc = 1.3;
      sig->SetMaximum( TMath::Max( sig->GetMaximum(), bgd->GetMaximum() )*sc );
      sig->Draw( "hist" );
      cPad->SetLeftMargin( 0.17 );

      sig->GetYaxis()->SetTitleOffset( 1.70 );
      if (!isRegression) {
         bgd->Draw("histsame");
         TString ytit = TString("(1/N) ") + sig->GetYaxis()->GetTitle();
         sig->GetYaxis()->SetTitle( ytit ); // histograms are normalised
      }

      // Draw legend
      if (countPad == 1 && !isRegression) {
         TLegend *legend= new TLegend( cPad->GetLeftMargin(), 
                                       1-cPad->GetTopMargin()-.15, 
                                       cPad->GetLeftMargin()+.4, 
                                       1-cPad->GetTopMargin() );
         legend->SetFillStyle(1);
         legend->AddEntry(sig,"Signal","F");
         legend->AddEntry(bgd,"Background","F");
         legend->SetBorderSize(1);
         legend->SetMargin( 0.3 );
         legend->Draw("same");
      } 

      // redraw axes
      sig->Draw("sameaxis");

      // text for overflows
      Int_t    nbin = sig->GetNbinsX();
      Double_t dxu  = sig->GetBinWidth(0);
      Double_t dxo  = sig->GetBinWidth(nbin+1);
      TString uoflow = "";
      if (isRegression) {
         uoflow = Form( "U/O-flow: %.1f%% / %.1f%%", 
                        sig->GetBinContent(0)*dxu*100, sig->GetBinContent(nbin+1)*dxo*100 );
      }
      else {
         uoflow = Form( "U/O-flow (S,B): (%.1f, %.1f)%% / (%.1f, %.1f)%%", 
                        sig->GetBinContent(0)*dxu*100, bgd->GetBinContent(0)*dxu*100,
                        sig->GetBinContent(nbin+1)*dxo*100, bgd->GetBinContent(nbin+1)*dxo*100 );
      }
  
      TText* t = new TText( 0.98, 0.14, uoflow );
      t->SetNDC();
      t->SetTextSize( 0.040 );
      t->SetTextAngle( 90 );
      t->AppendPad();    

      // save canvas to file
      if (countPad%noPadPerCanv==0) {
         // TString fname = Form( "1tau0l_Allvariables/%s_c%i", outfname.Data(), countCanvas );
         TString fname = Form( "%s%s_c%i", outDir.Data(), outfname.Data(), countCanvas );
         TMVAGlob::plot_logo();
         TMVAGlob::imgconv( canv, fname );
         createNewFig = kFALSE;
      }
      else {
         createNewFig = kTRUE;
      }
   }
   
   if (createNewFig) {
    //   TString fname = Form( "1tau0l_Allvariables/%s_c%i", outfname.Data(), countCanvas );
         TString fname = Form( "%s%s_c%i", outDir.Data(), outfname.Data(), countCanvas );
      TMVAGlob::plot_logo();
      TMVAGlob::imgconv( canv, fname );
      createNewFig = kFALSE;
   }

   return;
}
