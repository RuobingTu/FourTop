#ifndef EVENTREADDER_FORMV_H
#define EVENTREADDER_FORMV_H

#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <TTreeReaderValue.h>

class EventForMV
{
public:
    EventForMV(TTreeReader &reader) :
     HLT_PFHT450_SixJet40_BTagCSV_p056_(reader, "HLT_PFHT450_SixJet40_BTagCSV_p056_"),
     HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_(reader, "HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_"),
     HLT_PFJet450_(reader, "HLT_PFJet450_"),
     HLT_IsoMu24_(reader, "HLT_IsoMu24_"),
     HLT_IsoMu27_(reader, "HLT_IsoMu27_"),
     HLT_PFJet500_(reader, "HLT_PFJet500_"),
     //2018
     HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5_(reader, "HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5_"),
     HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2_(reader, "HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2_"),
     HLT_PFHT430_SixPFJet40_PFBTagDeepCSV_1p5_(reader, "HLT_PFHT430_SixPFJet40_PFBTagDeepCSV_1p5_"),
     HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59_(reader, "HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59_"),
     HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94_(reader, "HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94_"),
     HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5_(reader, "HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5_"),
    // 2017
     HLT_PFHT430_SixJet40_BTagCSV_p080_(reader, "HLT_PFHT430_SixJet40_BTagCSV_p080_"),
     HLT_PFHT380_SixJet32_DoubleBTagCSV_p075_(reader, "HLT_PFHT380_SixJet32_DoubleBTagCSV_p075_"),
     HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2_(reader, "HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2_"),
    //2022
     HLT_PFHT450_SixPFJet36_PFBTagDeepJet_1p59_(reader, "HLT_PFHT450_SixPFJet36_PFBTagDeepJet_1p59_"),
     HLT_PFHT400_SixPFJet32_DoublePFBTagDeepJet_2p94_(reader, "HLT_PFHT400_SixPFJet32_DoublePFBTagDeepJet_2p94_"),
     HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5_(reader, "HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5_"),
     HLT_PFHT400_FivePFJet_100_100_60_30_30_DoublePFBTagDeepJet_4p5_(reader, "HLT_PFHT400_FivePFJet_100_100_60_30_30_DoublePFBTagDeepJet_4p5_"),
     HLT_PFHT400_FivePFJet_120_120_60_30_30_DoublePFBTagDeepJet_4p5_(reader, "HLT_PFHT400_FivePFJet_120_120_60_30_30_DoublePFBTagDeepJet_4p5_"),


                                      muonsT_pt(reader, "muonsT_pt"),
                                      muonsT_eta(reader, "muonsT_eta"),
                                      muonsT_phi(reader, "muonsT_phi"),
                                      muonsT_mass(reader, "muonsT_mass"),
                                      muonsT_charge(reader, "muonsT_charge"),
                                      muonsTopMVAT_pt(reader, "muonsTopMVAT_pt"),
                                      muonsTopMVAT_eta(reader, "muonsTopMVAT_eta"),
                                      muonsTopMVAT_phi(reader, "muonsTopMVAT_phi"),
                                      muonsTopMVAT_mass(reader, "muonsTopMVAT_mass"),
                                      muonsTopMVAT_charge(reader, "muonsTopMVAT_charge"),
                                      elesMVAT_pt(reader, "elesMVAT_pt"),
                                      elesMVAT_eta(reader, "elesMVAT_eta"),
                                      elesMVAT_phi(reader, "elesMVAT_phi"),
                                      elesMVAT_mass(reader, "elesMVAT_mass"),
                                      elesMVAT_charge(reader, "elesMVAT_charge"),
                                      elesTopMVAT_pt(reader, "elesTopMVAT_pt"),
                                      elesTopMVAT_eta(reader, "elesTopMVAT_eta"),
                                      elesTopMVAT_phi(reader, "elesTopMVAT_phi"),
                                      elesTopMVAT_mass(reader, "elesTopMVAT_mass"),
                                      elesTopMVAT_charge(reader, "elesTopMVAT_charge"),

                                      tausT_pt(reader, "tausT_pt"),
                                      tausT_eta(reader, "tausT_eta"),
                                      tausT_phi(reader, "tausT_phi"),
                                      tausT_mass(reader, "tausT_mass"),
                                      tausT_genPartFlav(reader, "tausT_genPartFlav"),
                                      tausT_decayMode(reader, "tausT_decayMode"),
                                      tausT_charge(reader, "tausT_charge"),
                                      tausT_jetPt(reader, "tausT_jetPt"),
                                      tausT_jetEta(reader, "tausT_jetEta"),

                                      tausTT_pt(reader, "tausTT_pt"),
                                      tausTT_eta(reader, "tausTT_eta"),
                                      tausTT_phi(reader, "tausTT_phi"),
                                      tausTT_mass(reader, "tausTT_mass"),
                                      tausTT_genPartFlav(reader, "tausTT_genPartFlav"),
                                      tausTT_decayMode(reader, "tausTT_decayMode"),
                                      tausTT_charge(reader, "tausTT_charge"),
                                      tausTT_jetPt(reader, "tausTT_jetPt"),
                                      tausTT_jetEta(reader, "tausTT_jetEta"),

                                      tausTTT_pt(reader, "tausTTT_pt"),
                                      tausTTT_eta(reader, "tausTTT_eta"),
                                      tausTTT_phi(reader, "tausTTT_phi"),
                                      tausTTT_mass(reader, "tausTTT_mass"),
                                      tausTTT_genPartFlav(reader, "tausTTT_genPartFlav"),
                                      tausTTT_decayMode(reader, "tausTTT_decayMode"),
                                      tausTTT_charge(reader, "tausTTT_charge"),
                                      tausTTT_jetPt(reader, "tausTTT_jetPt"),
                                      tausTTT_jetEta(reader, "tausTTT_jetEta"),

                                      tausM_pt(reader, "tausM_pt"),
                                      tausM_eta(reader, "tausM_eta"),
                                      tausM_phi(reader, "tausM_phi"),
                                      tausM_mass(reader, "tausM_mass"),
                                      tausM_genPartFlav(reader, "tausM_genPartFlav"),
                                      tausM_decayMode(reader, "tausM_decayMode"),
                                      tausM_charge(reader, "tausM_charge"),
                                      tausM_jetPt(reader, "tausM_jetPt"),
                                      tausM_jetEta(reader, "tausM_jetEta"),

                                      tausF_pt(reader, "tausF_pt"),
                                      tausF_eta(reader, "tausF_eta"),
                                      tausF_phi(reader, "tausF_phi"),
                                      tausF_mass(reader, "tausF_mass"),
                                      tausF_genPartFlav(reader, "tausF_genPartFlav"),
                                      tausF_decayMode(reader, "tausF_decayMode"),
                                      tausF_charge(reader, "tausF_charge"),
                                      tausF_jetPt(reader, "tausF_jetPt"),
                                      tausF_jetEta(reader, "tausF_jetEta"),

                                      tausL_pt(reader, "tausL_pt"),
                                      tausL_eta(reader, "tausL_eta"),
                                      tausL_phi(reader, "tausL_phi"),
                                      tausL_mass(reader, "tausL_mass"),
                                      tausL_genPartFlav(reader, "tausL_genPartFlav"),
                                      tausL_decayMode(reader, "tausL_decayMode"),
                                      tausL_charge(reader, "tausL_charge"),
                                      tausL_jetPt(reader, "tausL_jetPt"),
                                      tausL_jetEta(reader, "tausL_jetEta"),

                                      jets_pt(reader, "jets_pt"),
                                      jets_eta(reader, "jets_eta"),
                                      jets_phi(reader, "jets_phi"),
                                      jets_mass(reader, "jets_mass"),
                                      jets_btags(reader, "jets_btags"),
                                      jets_btagsPN(reader, "jets_btagsPN"),
                                      jets_btagsPT(reader, "jets_btagsPT"),
                                      jets_flavour(reader, "jets_flavour"),

                                      bjetsM_pt(reader, "bjetsM_pt"),
                                      bjetsM_eta(reader, "bjetsM_eta"),
                                      bjetsM_phi(reader, "bjetsM_phi"),
                                      bjetsM_mass(reader, "bjetsM_mass"),
                                      bjetsL_pt(reader, "bjetsL_pt"),
                                      bjetsL_eta(reader, "bjetsL_eta"),
                                      bjetsL_phi(reader, "bjetsL_phi"),
                                      bjetsL_mass(reader, "bjetsL_mass"),
                                      bjetsT_pt(reader, "bjetsT_pt"),
                                      bjetsT_eta(reader, "bjetsT_eta"),
                                      bjetsT_phi(reader, "bjetsT_phi"),
                                      bjetsT_mass(reader, "bjetsT_mass"),
                                      bjetsPNM_pt(reader, "bjetsPNM_pt"),
                                      bjetsPNM_eta(reader, "bjetsPNM_eta"),
                                      bjetsPNM_phi(reader, "bjetsPNM_phi"),
                                      bjetsPNM_mass(reader, "bjetsPNM_mass"),
                                      bjetsPTM_pt(reader, "bjetsPTM_pt"),
                                      bjetsPTM_eta(reader, "bjetsPTM_eta"),
                                      bjetsPTM_phi(reader, "bjetsPTM_phi"),
                                      bjetsPTM_mass(reader, "bjetsPTM_mass"),
                                      bjetsPTT_pt(reader, "bjetsPTT_pt"),
                                      bjetsPTT_eta(reader, "bjetsPTT_eta"),
                                      bjetsPTT_phi(reader, "bjetsPTT_phi"),
                                      bjetsPTT_mass(reader, "bjetsPTT_mass"),

                                      PV_npvsGood_(reader, "PV_npvsGood_"),
                                      MET_pt_(reader, "MET_pt_"),
                                      EVENT_genWeight_(reader, "EVENT_genWeight_"),
                                      EVENT_prefireWeight_(reader, "EVENT_prefireWeight_"),
                                      EVENT_prefireWeight_up_(reader, "EVENT_prefireWeight_up_"),
                                      EVENT_prefireWeight_down_(reader, "EVENT_prefireWeight_down_"),
                                      PUWeight(reader, "PUWeight"),
                                      PUWeight_up(reader, "PUWeight_up"),
                                      PUWeight_down(reader, "PUWeight_down"),
                                      pdfWeight_up(reader, "pdfWeight_up"),
                                      pdfWeight_down(reader, "pdfWeight_down"),
                                      pdfWeightAlphaS_up(reader, "pdfWeightAlphaS_up"),
                                      pdfWeightAlphaS_down(reader, "pdfWeightAlphaS_down"),
                                      scaleWeight_up(reader, "scaleWeight_up"),
                                      scaleWeight_down(reader, "scaleWeight_down"),
                                      scaleWeightRe_up(reader, "scaleWeightRe_up"),
                                      scaleWeightRe_down(reader, "scaleWeightRe_down"),
                                      scaleWeightFa_up(reader, "scaleWeightFa_up"),
                                      scaleWeightFa_down(reader, "scaleWeightFa_down")

    {
        std::cout << "Initializing EventForMV..\n";
        std::cout << "Done initialization.......\n";
        std::cout << "\n";
    };

    ~EventForMV(){};

    // event branches reading
    TTreeReaderValue<Bool_t> HLT_PFHT450_SixJet40_BTagCSV_p056_;
    TTreeReaderValue<Bool_t> HLT_PFHT400_SixJet30_DoubleBTagCSV_p056_;
    TTreeReaderValue<Bool_t> HLT_PFJet450_;
    TTreeReaderValue<Bool_t> HLT_IsoMu24_;
    TTreeReaderValue<Bool_t> HLT_IsoMu27_;
    TTreeReaderValue<Bool_t> HLT_PFJet500_;
    TTreeReaderValue<Bool_t> HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5_;
    TTreeReaderValue<Bool_t> HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2_;
    TTreeReaderValue<Bool_t> HLT_PFHT430_SixPFJet40_PFBTagDeepCSV_1p5_;
    TTreeReaderValue<Bool_t> HLT_PFHT450_SixPFJet36_PFBTagDeepCSV_1p59_;
    TTreeReaderValue<Bool_t> HLT_PFHT400_SixPFJet32_DoublePFBTagDeepCSV_2p94_;
    TTreeReaderValue<Bool_t> HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepCSV_4p5_;
    // 2017
    TTreeReaderValue<Bool_t> HLT_PFHT430_SixJet40_BTagCSV_p080_;
    TTreeReaderValue<Bool_t> HLT_PFHT380_SixJet32_DoubleBTagCSV_p075_;
    TTreeReaderValue<Bool_t> HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2_;
    //2022
    TTreeReaderValue<Bool_t> HLT_PFHT450_SixPFJet36_PFBTagDeepJet_1p59_;
    TTreeReaderValue<Bool_t> HLT_PFHT400_SixPFJet32_DoublePFBTagDeepJet_2p94_;
    TTreeReaderValue<Bool_t> HLT_PFHT330PT30_QuadPFJet_75_60_45_40_TriplePFBTagDeepJet_4p5_;
    TTreeReaderValue<Bool_t> HLT_PFHT400_FivePFJet_100_100_60_30_30_DoublePFBTagDeepJet_4p5_;
    TTreeReaderValue<Bool_t> HLT_PFHT400_FivePFJet_120_120_60_30_30_DoublePFBTagDeepJet_4p5_;

    TTreeReaderArray<Double_t> muonsT_pt;
    TTreeReaderArray<Double_t> muonsT_eta;
    TTreeReaderArray<Double_t> muonsT_phi;
    TTreeReaderArray<Double_t> muonsT_mass;
    TTreeReaderArray<Int_t> muonsT_charge;
    TTreeReaderArray<Double_t> muonsTopMVAT_pt;
    TTreeReaderArray<Double_t> muonsTopMVAT_eta;
    TTreeReaderArray<Double_t> muonsTopMVAT_phi;
    TTreeReaderArray<Double_t> muonsTopMVAT_mass;
    TTreeReaderArray<Int_t> muonsTopMVAT_charge;
    // TTreeReaderArray<Int_t> muonsTopMVAT_index;
    TTreeReaderArray<Double_t> elesMVAT_pt;
    TTreeReaderArray<Double_t> elesMVAT_eta;
    TTreeReaderArray<Double_t> elesMVAT_phi;
    TTreeReaderArray<Double_t> elesMVAT_mass;
    TTreeReaderArray<Int_t> elesMVAT_charge;
    TTreeReaderArray<Double_t> elesTopMVAT_pt;
    TTreeReaderArray<Double_t> elesTopMVAT_eta;
    TTreeReaderArray<Double_t> elesTopMVAT_phi;
    TTreeReaderArray<Double_t> elesTopMVAT_mass;
    TTreeReaderArray<Int_t> elesTopMVAT_charge;

    TTreeReaderArray<Double_t> tausT_pt;
    TTreeReaderArray<Double_t> tausT_eta;
    TTreeReaderArray<Double_t> tausT_phi;
    TTreeReaderArray<Double_t> tausT_mass;
    TTreeReaderArray<UChar_t> tausT_genPartFlav;
    TTreeReaderArray<Int_t> tausT_decayMode;
    TTreeReaderArray<Int_t> tausT_charge;
    TTreeReaderArray<Double_t> tausT_jetPt;
    TTreeReaderArray<Double_t> tausT_jetEta;


    TTreeReaderArray<Double_t> tausTT_pt;
    TTreeReaderArray<Double_t> tausTT_eta;
    TTreeReaderArray<Double_t> tausTT_phi;
    TTreeReaderArray<Double_t> tausTT_mass;
    TTreeReaderArray<UChar_t> tausTT_genPartFlav;
    TTreeReaderArray<Int_t> tausTT_decayMode;
    TTreeReaderArray<Int_t> tausTT_charge;
    TTreeReaderArray<Double_t> tausTT_jetPt;
    TTreeReaderArray<Double_t> tausTT_jetEta;

    TTreeReaderArray<Double_t> tausTTT_pt;
    TTreeReaderArray<Double_t> tausTTT_eta;
    TTreeReaderArray<Double_t> tausTTT_phi;
    TTreeReaderArray<Double_t> tausTTT_mass;
    TTreeReaderArray<UChar_t> tausTTT_genPartFlav;
    TTreeReaderArray<Int_t> tausTTT_decayMode;
    TTreeReaderArray<Int_t> tausTTT_charge;
    TTreeReaderArray<Double_t> tausTTT_jetPt;
    TTreeReaderArray<Double_t> tausTTT_jetEta;

    TTreeReaderArray<Double_t> tausM_pt;
    TTreeReaderArray<Double_t> tausM_eta;
    TTreeReaderArray<Double_t> tausM_phi;
    TTreeReaderArray<Double_t> tausM_mass;
    TTreeReaderArray<UChar_t> tausM_genPartFlav;
    TTreeReaderArray<Int_t> tausM_decayMode;
    TTreeReaderArray<Int_t> tausM_charge;
    TTreeReaderArray<Double_t> tausM_jetPt;
    TTreeReaderArray<Double_t> tausM_jetEta;

    TTreeReaderArray<Double_t> tausF_pt;
    TTreeReaderArray<Double_t> tausF_eta;
    TTreeReaderArray<Double_t> tausF_phi;
    TTreeReaderArray<Double_t> tausF_mass;
    TTreeReaderArray<UChar_t> tausF_genPartFlav;
    TTreeReaderArray<Int_t> tausF_decayMode;
    TTreeReaderArray<Int_t> tausF_charge;
    TTreeReaderArray<Double_t> tausF_jetPt;
    TTreeReaderArray<Double_t> tausF_jetEta;

    TTreeReaderArray<Double_t> tausL_pt;
    TTreeReaderArray<Double_t> tausL_eta;
    TTreeReaderArray<Double_t> tausL_phi;
    TTreeReaderArray<Double_t> tausL_mass;
    TTreeReaderArray<UChar_t> tausL_genPartFlav;
    TTreeReaderArray<Int_t> tausL_decayMode;
    TTreeReaderArray<Int_t> tausL_charge;
    TTreeReaderArray<Double_t> tausL_jetPt;
    TTreeReaderArray<Double_t> tausL_jetEta;

    TTreeReaderArray<Double_t> jets_pt;
    TTreeReaderArray<Double_t> jets_eta;
    TTreeReaderArray<Double_t> jets_phi;
    TTreeReaderArray<Double_t> jets_mass;
    TTreeReaderArray<Double_t> jets_btags;
    TTreeReaderArray<Double_t> jets_btagsPN;
    TTreeReaderArray<Double_t> jets_btagsPT;
    TTreeReaderArray<Int_t> jets_flavour;
    // TTreeReaderArray<Double_t> jetsT_pt;
    // TTreeReaderArray<Double_t> jetsT_eta;
    // TTreeReaderArray<Double_t> jetsT_phi;
    // TTreeReaderArray<Double_t> jetsT_mass;
    // TTreeReaderArray<Double_t> jetsT_btags;
    TTreeReaderArray<Double_t> bjetsM_pt;
    TTreeReaderArray<Double_t> bjetsM_eta;
    TTreeReaderArray<Double_t> bjetsM_phi;
    TTreeReaderArray<Double_t> bjetsM_mass;
    TTreeReaderArray<Double_t> bjetsL_pt;
    TTreeReaderArray<Double_t> bjetsL_eta;
    TTreeReaderArray<Double_t> bjetsL_phi;
    TTreeReaderArray<Double_t> bjetsL_mass;
    TTreeReaderArray<Double_t> bjetsT_pt;
    TTreeReaderArray<Double_t> bjetsT_eta;
    TTreeReaderArray<Double_t> bjetsT_phi;
    TTreeReaderArray<Double_t> bjetsT_mass;
    TTreeReaderArray<Double_t> bjetsPNM_pt;
    TTreeReaderArray<Double_t> bjetsPNM_eta;
    TTreeReaderArray<Double_t> bjetsPNM_phi;
    TTreeReaderArray<Double_t> bjetsPNM_mass;
    TTreeReaderArray<Double_t> bjetsPTM_pt;
    TTreeReaderArray<Double_t> bjetsPTM_eta;
    TTreeReaderArray<Double_t> bjetsPTM_phi;
    TTreeReaderArray<Double_t> bjetsPTM_mass;
    TTreeReaderArray<Double_t> bjetsPTT_pt;
    TTreeReaderArray<Double_t> bjetsPTT_eta;
    TTreeReaderArray<Double_t> bjetsPTT_phi;
    TTreeReaderArray<Double_t> bjetsPTT_mass;

    TTreeReaderValue<Int_t> PV_npvsGood_;
    TTreeReaderValue<Double_t> MET_pt_;

    TTreeReaderValue<Double_t> EVENT_genWeight_;
    TTreeReaderValue<Double_t> EVENT_prefireWeight_;
    TTreeReaderValue<Double_t> EVENT_prefireWeight_up_;
    TTreeReaderValue<Double_t> EVENT_prefireWeight_down_;
    TTreeReaderValue<Double_t> PUWeight;
    TTreeReaderValue<Double_t> PUWeight_up;
    TTreeReaderValue<Double_t> PUWeight_down;
    // TTreeReaderValue<Double_t> ;
    TTreeReaderValue<Double_t> pdfWeight_up;
    TTreeReaderValue<Double_t> pdfWeight_down;
    TTreeReaderValue<Double_t> pdfWeightAlphaS_up;
    TTreeReaderValue<Double_t> pdfWeightAlphaS_down;
    TTreeReaderValue<Double_t> scaleWeight_up;
    TTreeReaderValue<Double_t> scaleWeight_down;
    TTreeReaderValue<Double_t> scaleWeightRe_up;
    TTreeReaderValue<Double_t> scaleWeightRe_down;
    TTreeReaderValue<Double_t> scaleWeightFa_up;
    TTreeReaderValue<Double_t> scaleWeightFa_down;
};

#endif