#include "../include/objectSelectionNano.h"
#include "../include/usefulFunc.h"
#include "../../src_cpp/lumiAndCrossSection.h"

void objectSelection::EventLoop(const Bool_t iftauSel, const Bool_t preSelection, const Bool_t ifHLT, ULong_t numEntries)
{
    ULong_t entryCount = 0;
    if (numEntries <= 0)
    {
        numEntries = m_reader.GetEntries();
    }
    std::cout << "Start event loop for " << numEntries << " ................................\n";
    while (m_reader.Next() && entryCount < numEntries)
    {
        entryCount++;
        if(entryCount==1){
            std::cout <<"ifTauSel="<<iftauSel<< " preSelection="<< preSelection << "; ifHLT="<<ifHLT<< "\n";
        }

        Double_t genWeight = 1.0;
        if(!m_isData){
            genWeight = **e->genWeight;
        }
        m_cutflow->Fill(0);
        CF_initial->Fill(0., genWeight);

        // good lumi and good PV selection
        if (!(lumiAndPVSelection.Select(m_isData, e)))//!!!turn off temperorilly
        {
            continue;
        };

        // MET filters
        if (!(metFilter.Select(m_era, e)))
        {
            continue;
        }

        m_cutflow->Fill(1);
        CF_met->Fill(0., genWeight);

        // HLT selection and HLT branch filling
        Bool_t passHLT = HLTselection.Select(e,  ifHLT);
        Bool_t passLepTri = HLTselection.SelectLepTri(e);//!!!for 1tau2l
        Bool_t ifPassHLT = m_if1tau2l? passLepTri: passHLT;
        if(!(OS::ifEventPass(ifHLT, ifPassHLT, m_cutflow, 2))){
            continue;
        }

        CF_HLT->Fill(0., genWeight);

        muSel.Select(e); //muons tight for run 3
        eleMVASel.Select(e);

        // TOPMVA lepton selection
        muTopMVATSel.Select(e);
        muTopMVAFSel.Select(e);
        eleTopMVATSel.Select(e, muTopMVAFSel.getEtaVec(), muTopMVAFSel.getPhiVec());
        eleTopMVAFSel.Select(e, muTopMVAFSel.getEtaVec(), muTopMVAFSel.getPhiVec());//!need overlap removal with fakeable muon

        //leptons for overlap removal
        std::vector<Double_t> muEtaVec = m_isRun3 ? muSel.getEtaVec(): muTopMVAFSel.getEtaVec();
        std::vector<Double_t> muPhiVec = m_isRun3 ? muSel.getPhiVec(): muTopMVAFSel.getPhiVec();
        std::vector<Double_t> eleEtaVec = m_isRun3 ? eleMVASel.getEtaVec(): eleTopMVAFSel.getEtaVec();
        std::vector<Double_t> elePhiVec = m_isRun3 ? eleMVASel.getPhiVec(): eleTopMVAFSel.getPhiVec();

        // tau selection
        tauSel.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec);
        tauSelF.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec);
        tauSelL.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec);
        tauSelTT.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec);
        tauSelTTT.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec);
        tauSelM.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec);
        tauSelTTTT.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec);

        const std::vector<Double_t> tausFEtaVec = tauSelF.getEtaVec();
        const std::vector<Double_t> tausFPhiVec = tauSelF.getPhiVec();
        m_tausTotal += tauSel.getSize();
        m_tausFTotal += tauSelF.getSize();
        m_tausLTotal += tauSelL.getSize();

        // jet and bjet selection
        jetSel.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec, tausFEtaVec, tausFPhiVec, kTRUE);
        bjetMSel.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec, tausFEtaVec, tausFPhiVec, kTRUE);
        bjetLSel.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec, tausFEtaVec, tausFPhiVec, kTRUE);
        bjetTSel.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec, tausFEtaVec, tausFPhiVec, kTRUE);
        bjetPNMSel.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec, tausFEtaVec, tausFPhiVec, kTRUE);
        bjetPTMSel.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec, tausFEtaVec, tausFPhiVec, kTRUE);
        bjetPTTSel.Select(e, m_isData, muEtaVec, muPhiVec, eleEtaVec, elePhiVec, tausFEtaVec, tausFPhiVec, kTRUE);
        m_jetsTotal += jetSel.getSize();
        m_bjetsM += bjetMSel.getSize();

        // copy some nanoAOD branches
        copyBranch.Select(e, m_isData);

        // pile up weight cal
        puWeightCal.Select(e, m_isData);

        //systematic Weight cal
        systWeightCal.Select(e, m_isData);

        // if(!(OS::ifEventPass(iftauSel, tauSel.getSize()>0, m_cutflow, 3))){ //!for b-tag efficiency measurement
        const Bool_t tauLepCut = m_if1tau2l? (eleTopMVAFSel.getSize()+muTopMVAFSel.getSize())==2 && tauSelF.getSize()>0: tauSelF.getSize()>0;
        if(!(OS::ifEventPass(iftauSel, tauLepCut, m_cutflow, 3))){//!use tauF so that fakeTau bg can be estimated later
            continue;
        }

        Bool_t jetCut = m_if1tau2l? jetSel.getSize()>1: jetSel.getSize()>5;
        if(!(OS::ifEventPass(preSelection, jetCut, m_cutflow, 4))){
            continue;
        }
        Bool_t bjetCut = m_if1tau2l? bjetMSel.getSize()>0: bjetMSel.getSize()>1;
        if(!(OS::ifEventPass(preSelection, bjetCut, m_cutflow, 5))){//baseline for 1tau2l
            continue;
        }//!No b-tag ,for b-tag efficiency measurement!
        Bool_t HTCut = m_if1tau2l? jetSel.getHT()>200.: (jetSel.getHT()>480.&& jetSel.get6thPt()>38.);
        if(!OS::ifEventPass(preSelection, HTCut , m_cutflow, 6)){
            continue;
        }

        
        CF_pre->Fill(0., genWeight);
        m_outTree->Fill();
    };
    std::cout << "End of event loop...................................................\n\n";
};

void objectSelection::Terminate()
{
    std::cout << "Terminate phase.......................................................\n";
    std::cout << "outFile here: " << m_output->GetName() << "\n";
    std::cout << "initial events:" << m_cutflow->GetBinContent(1) << ";   HLT: " << m_cutflow->GetBinContent(3) <<"; >=tauF:"<<m_cutflow->GetBinContent(4) <<" preSelection: " << m_cutflow->GetBinContent(6) << "\n";
    std::cout << "elesTotal=" << eleMVASel.getTotal() << ";   musTotal=" << muSel.getTotal() << ";   tausTotal=" << m_tausTotal << "; tausF=" << m_tausFTotal << "; tausL=" << m_tausLTotal << ";  jets=" << m_jetsTotal << ";  bjetsM=" << m_bjetsM << "\n";//includes entries not passing selection
    // std::cout<<"muonsTopMVAT="<<muTopMVATSel.getTotal()<<"; muonsTopMVAF="<<muTopMVAFSel.getTotal()<<"; elesTopMVAT="<<eleTopMVATSel.getTotal()<<"; elesTopMVAF="<<eleTopMVAFSel.getTotal()<<"\n";

    // get Runs tree
    if (!m_isData)
    {
        std::cout << "copy Runs tree\n";
        TTree *runs = (TTree *)m_input->Get("Runs");
        runs->SetBranchStatus("*", 0);
        runs->SetBranchStatus("genEventSumw", 1);
        runs->SetBranchStatus("LHEPdfSumw", 1);//Sum of genEventWeight * LHEPdfWeight[i], divided by genEventSumw
        runs->SetBranchStatus("LHEScaleSumw", 1);//Sum of genEventWeight * LHEScaleWeight[i], divided by genEventSumw

        TTree *runsForOut = runs->CloneTree();
        runsForOut->SetDirectory(m_output);
    }

    m_output->Write();
    m_output->Close();

    std::cout << "Termination done .....................................................\n";
};

objectSelection::~objectSelection()
{
    delete m_input;
    delete e;
};
