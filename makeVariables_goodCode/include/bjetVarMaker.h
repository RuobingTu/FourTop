#ifndef BJETVARMAKER_H
#define BJETVARMAKER_H

#include "objVarMaker.h"

class BjetVarMaker : public ObjVarMaker
{
public:
    BjetVarMaker(TTree *outTree, TString objName, Int_t type = 0);
    ~BjetVarMaker();
    void makeVariables(const EventForMV *e);
    void clearBranch();
    void setupLorentzObjs(const EventForMV *e);
    Int_t getJet_num();

private:
    Double_t bjets_MHT = -99;
    Double_t bjets_HT = -99;
    Double_t bjets_invariantMass = -99;
    Double_t bjets_transMass = -99;
    Double_t bjets_minDeltaR = -99.;

};



#endif