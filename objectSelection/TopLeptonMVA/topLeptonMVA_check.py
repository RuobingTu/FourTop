import os
import ROOT
from ROOT import std
from array import array
# import uproot
# import pandas as pd

import sys
sys.path.append("/workfs2/cms/huahuil/4topCode/CMSSW_10_2_20_UL/src/FourTop/hua/codeFromOthers/")
import mvaTOPreader as tl
import usefulFunc as uf

def main():
    #xrootd for accessing data
    #redirector for Europe and Asia: rootd-cms.infn.it
    # nanoFile = '/store/mc/RunIISummer20UL18NanoAODv9/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/120000/B8F4ECF8-1363-C14F-B6F4-D292106546A0.root'
    # inputFile = ROOT.TFile.Open("root://rootd-cms.infn.it//" + nanoFile )#???not working
    inputFile = ROOT.TFile("/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/nanoAOD/B8F4ECF8-1363-C14F-B6F4-D292106546A0.root", "READ") #UL2018
    
    tree = inputFile.Get("Events") 
    # tree.Print()
    # tree.SetBranchStatus("*", 0)
    # tree.SetBranchStatus("Electron_pt", 1)#???
        
    outDir = os.path.dirname(os.path.realpath(__file__)) + '/output/'
    uf.checkMakeDir(outDir) 
    outFile = ROOT.TFile( outDir + 'syncWithSS.root', "RECREATE")
    outTree = ROOT.TTree('events', 'event tree for sync')
    
    event = array('L', [0])
    ele_topLeptonMVA = std.vector('float')()
    outTree.Branch('eventNumber', event, 'event/l')
    outTree.Branch('ele_topLeptonMVA', ele_topLeptonMVA)
    
    # for i in range(tree.GetEntries()):
    for i in range( 20):
        tree.GetEntry(i)
        event[0] = tree.event
        print('eventNumber: ', tree.event)
        ele_topLeptonMVA.clear()
                
        for ele in range(tree.nElectron):
            lep = {} 
            lep['pdgId'] = 11
            lep["pt"] = tree.Electron_pt[ele]
            lep["eta"] = tree.Electron_eta[ele] #absolute or not?
            lep["jetNDauCharged"] = tree.Electron_jetNDauCharged[ele]
            lep["miniPFRelIso_chg"] = tree.Electron_miniPFRelIso_chg[ele]
            lep["miniPFRelIso_all"] = tree.Electron_miniPFRelIso_all[ele]
            lep["jetPtRelv2"] = tree.Electron_jetPtRelv2[ele]
            lep["jetPtRatio"] = 1. / (tree.Electron_jetRelIso[ele] + 1.) 
            lep["pfRelIso03_all"] = tree.Electron_pfRelIso03_all[ele]
            lep["jetBTag"] = tree.Jet_btagDeepB[tree.Electron_jetIdx[ele]]
            lep["sip3d"] = tree.Electron_sip3d[ele]
            lep["dxy"] = tree.Electron_dxy[ele]
            lep["dz"] = tree.Electron_dz[ele]
            lep["mvaFall17V2noIso"] = tree.Electron_mvaFall17V2noIso[ele]
            # print(lep)
        
            top = tl.mvaTOPreader('UL2018')
            # print(top.getmvaTOPScore(lep))
            ele_topLeptonMVA.push_back(top.getmvaTOPScore((lep))[0])
        
        outTree.Fill() 
        
    inputFile.Close()   
    
    outFile.Write()
    print('outFile here: ', outFile.GetName())
    outFile.Close()
    

        

    
    
    
    

if __name__=='__main__':
    main()