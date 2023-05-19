#ifndef OBJECTSELECTIONNANO_H
#define OBJECTSELECTIONNANO_H
// #include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "TTreeReader.h"
#include "TTreeReaderArray.h"

// #include "eventReader_nano.C"
#include "eventReader_nano.h"

class objectSelection
{
public:
    objectSelection(TString inputFile, TString outputDir)
    {
        std::cout << "initialize objectSelection class\n";
        m_input = new TFile(inputFile, "READ");
        if (!m_input->IsZombie())
        {
            std::cout << "input file: " << m_input->GetName() << "\n";
            m_tree = (TTree *)m_input->Get("Events");
            // m_reader = TTreeReader("Events", m_input);
            m_reader = TTreeReader(m_tree);
            e = new eventForNano{m_reader};
            // e = new eventForNano{m_tree};
        }
        else
        {
            std::cout << "BAD!!! file not correctly open\n";
        }
        std::cout << "done initializing objectSelection class\n";
    };
    ~objectSelection();
    // osBase muonSelection(e, m_outTree);

    void Init();

    void EventLoop();
    void Terminate();

private:
    TFile *m_input;
    TTree *m_tree;
    TTreeReader m_reader;
    eventForNano *e;
    TFile *m_output;
};

#endif