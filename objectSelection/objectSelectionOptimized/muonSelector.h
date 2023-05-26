#ifndef MUONSELECTOR_H
#define MUONSELECTOR_H

// #include <vector.h>

#include "eventReader_nano.h"

class osBase
{
public:
    osBase(TTree *outTree) : m_outTree{outTree}
    {
        m_outTree->Branch("Muon_pt_", &Muon_pt_);
    };
    ~osBase(){

    };
    // init(){

    // };
    void Select(const eventForNano *e)
    {
        clearBranch();
        for (UInt_t j = 0; j < e->Muon_pt.GetSize(); ++j)
        {
            if (!(e->Muon_pt.At(j) > 10))
                continue;
            Muon_pt_.push_back(e->Muon_pt.At(j));
        }
        m_outTree->Fill();
    };
    void clearBranch()
    {
        Muon_pt_.clear();
    }
    // void

private:
    TTree *m_outTree;
    // output branches
    std::vector<Double_t> Muon_pt_;
    std::vector<Double_t> Muon_eta_;
    std::vector<Double_t> Muon_phi_;
    std::vector<Double_t> Muon_mass_;
};

#endif
