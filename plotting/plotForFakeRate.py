
from math import sqrt

import numpy as np
import ROOT
import usefulFunc as uf

from setTDRStyle import addCMSTextToCan, setTDRStyle

def main():
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v5updateHLTSF_v52noHLTButPreSelection/mc/variableHists_v0FR_measureVR_3prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v6baseline_v56NoHLTButPre/mc/variableHists_v0FR_measureVR_1prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v6baseline_v56NoHLTButPre/mc/variableHists_v0FR_measureVR_1prong_Add/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baseline_v57ovelapWithTausF/mc/variableHists_v0FR_measureVR_3prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v4baselineBtagRUpdated_v57ovelapWithTausF/mc/variableHists_v0FR_measureVR_3prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v4baselineBtagRUpdated_v57ovelapWithTausF/mc/variableHists_v0FR_measureVR_3prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHT350_v75AddTauTTTTNoHTCut/mc/variableHists_v0FR_measure1prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHT350_v75OverlapRemovalFTau/mc/variableHists_v0FR_measure1prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHT450_v75OverlapRemovalFTau/mc/variableHists_v0FR_measure1prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHT450_v75OverlapRemovalFTau/mc/variableHists_v0FR_measure1prong_jetEta/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHT450_v75OverlapRemovalFTau/mc/variableHists_v0FR_measureNot1prong_jetEta/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baselineHardro_v79HadroPresel/mc/variableHists_v0FR_measure3prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v1baselineHardroHLTSF_v79HadroPresel/mc/variableHists_v0FR_measure3prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/v1baselineHardroHLTSF_v79HadroPresel/mc/variableHists_v0FR_measure1prong/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_v85HadroPreselTauOverlap0.5/mc/variableHists_v0FR_measure1prongNew/'
    inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_v85HadroPreselTauOverlap0.5/mc/variableHists_v0FR_measure3prongNew/'
    
   
    
  
    inputDirDic = uf.getDirDic(inputDir)
    era = uf.getEraFromDir(inputDir)
    # plotFR(inputDirDic, era, '1prong')
    # plotFR(inputDirDic, era, '3prong')
    plotFRNew(inputDirDic, era)
    # plotFRNew(inputDirDic, era, '3prong')
   
# def plotFRNew(inputDirDic, era, tauProng='1prong'):
def plotFRNew(inputDirDic, era):
    # tauProng1 = '_1prong'
    regionList = ['1tau0lMRCR', '1tau0lMRCRGen', '1tau0lMRCRLTau', '1tau0lMRCRLTauGen']
    # FR_eta1 = plotFRPerEta( inputDirDic, regionList, era, '_Eta1', tauProng1, 'FR' + tauProng1 + 'Eta1')
    # FR_eta2 = plotFRPerEta( inputDirDic, regionList, era, '_Eta2', tauProng1, 'FR' + tauProng1 + 'Eta2')
    # FR_eta3 = plotFRPerEta( inputDirDic, regionList, era, '_Eta3', tauProng1, 'FR' + tauProng1 + 'Eta3')
    # uf.plotOverlay([FR_eta1, FR_eta2, FR_eta3],  ['0<|#eta|<0.8', '0.8<|#eta|<1.5', '1.5<|#eta|<2.4'], era, 'Fake rate of #tau_{h}', inputDirDic['mc'] + 'results/FR_MRCR_' + tauProng1 + '', 'AP', [0.5, 0.7, 0.9, 0.9], [0, 0.3]) 
    
    tauProng3 = '_3prong'
    FR_tauProng3 = plotFRPerEta( inputDirDic, regionList, era, '_EtaAll', tauProng3, 'FR' + tauProng3 + 'EtaAll')
    uf.plotOverlay([FR_tauProng3],  ['0<|#eta| <2.4'], era, 'Fake rate of #tau_{h}', inputDirDic['mc'] + 'results/FR_MRCR_' + tauProng3 + '', 'AP', [0.5, 0.7, 0.9, 0.9], [0, 0.3])
    
    
    # writeFRToFileNew([FR_eta1, FR_eta2, FR_eta3], inputDirDic)
    
def plotFR(inputDirDic, era,  tauProng='1prong'):
    regionList = ['1tau0lMR', '1tau0lMRGen', '1tau0lMRLTau', '1tau0lMRLTauGen']
    FR_eta1 = plotFRPerEta( inputDirDic, regionList, era, '_Eta1', 'FR_' + tauProng + 'Eta1')
    FR_eta2 = plotFRPerEta( inputDirDic, regionList, era, '_Eta2', 'FR_' + tauProng + 'Eta2')
    FR_eta3 = plotFRPerEta( inputDirDic, regionList, era, '_Eta3', 'FR_' + tauProng + 'Eta3')
    uf.plotOverlay([FR_eta1, FR_eta2, FR_eta3],  ['0<|#eta|<0.8', '0.8<|#eta|<1.5', '1.5<|#eta|<2.4'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_MR_' + tauProng + '', 'AP', [0.5, 0.7, 0.9, 0.9], [0, 0.3])
    
    writeFRToFileNew([FR_eta1, FR_eta2, FR_eta3], inputDirDic)
    
    regionListVR = ['1tau0lVR', '1tau0lVRGen', '1tau0lVRLTau', '1tau0lVRLTauGen']
    FR_eta1_VR = plotFRPerEta( inputDirDic, regionListVR, era, '_Eta1', 'FR_' + tauProng + 'Eta1_VR')
    FR_eta2_VR = plotFRPerEta( inputDirDic, regionListVR, era, '_Eta2', 'FR_' + tauProng + 'Eta2_VR')
    FR_eta3_VR = plotFRPerEta( inputDirDic, regionListVR, era, '_Eta3', 'FR_' + tauProng + 'Eta3_VR')
    uf.plotOverlay([FR_eta1_VR, FR_eta2_VR, FR_eta3_VR],  ['0<|#eta|<0.8', '0.8<|#eta|<1.5', '1.5<|#eta|<2.4'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_VR_' + tauProng + '', 'AP', [0.5, 0.7, 0.9, 0.9], [0, 0.3])
    
    regionListCR = ['1tau0lCR', '1tau0lCRGen', '1tau0lCRLTau', '1tau0lCRLTauGen']
    FR_eta1_CR = plotFRPerEta( inputDirDic, regionListCR, era, '_Eta1', 'FR_' + tauProng + 'Eta1_CR')
    FR_eta2_CR = plotFRPerEta( inputDirDic, regionListCR, era, '_Eta2', 'FR_' + tauProng + 'Eta2_CR')
    FR_eta3_CR = plotFRPerEta( inputDirDic, regionListCR, era, '_Eta3', 'FR_' + tauProng + 'Eta3_CR')
    uf.plotOverlay([FR_eta1_CR, FR_eta2_CR, FR_eta3_CR],  ['0<|#eta|<0.8', '0.8<|#eta|<1.5', '1.5<|#eta|<2.4'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_CR_' + tauProng + '', 'AP', [0.5, 0.7, 0.9, 0.9], [0, 0.3])
    
    
    uf.plotOverlay([FR_eta1, FR_eta1_VR], ['MR: N_{jet}>=8, N_{b-jet}=2', 'VR: N_{jet}<8, N_{b-jet}>=3'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_MRVR_' + tauProng + 'Eta1', 'AP', [0.4, 0.7, 0.9, 0.9], [0, 0.3])
    uf.plotOverlay([FR_eta2, FR_eta2_VR], ['MR: N_{jet}>=8, N_{b-jet}=2', 'VR: N_{jet}<8, N_{b-jet}>=3'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_MRVR_' + tauProng + 'Eta2', 'AP', [0.4, 0.7, 0.9, 0.9], [0, 0.3])
    uf.plotOverlay([FR_eta3, FR_eta3_VR], ['MR: N_{jet}>=8, N_{b-jet}=2', 'VR: N_{jet}<8, N_{b-jet}>=3'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_MRVR_' + tauProng + 'Eta3', 'AP', [0.4, 0.7, 0.9, 0.9], [0, 0.3])
    
    uf.plotOverlay([FR_eta1, FR_eta1_CR], ['MR: N_{jet}>=8, N_{b-jet}=2', 'CR: N_{jet}<8, N_{b-jet}=2'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_MRCR_' + tauProng + 'Eta1', 'AP', [0.4, 0.7, 0.9, 0.9], [0, 0.3])
    uf.plotOverlay([FR_eta2, FR_eta2_CR], ['MR: N_{jet}>=8, N_{b-jet}=2', 'CR: N_{jet}<8, N_{b-jet}=2'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_MRCR_' + tauProng + 'Eta2', 'AP', [0.4, 0.7, 0.9, 0.9], [0, 0.3])
    uf.plotOverlay([FR_eta3, FR_eta3_CR], ['MR: N_{jet}>=8, N_{b-jet}=2', 'CR: N_{jet}<8, N_{b-jet}=2'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_MRCR_' + tauProng + 'Eta3', 'AP', [0.4, 0.7, 0.9, 0.9], [0, 0.3])
    
    uf.plotOverlay([FR_eta1_CR, FR_eta1_VR], ['CR: N_{jet}<8, N_{b-jet}=2', 'VR: N_{jet}<8, N_{b-jet}>=3'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_CRVR_' + tauProng + 'Eta1', 'AP', [0.4, 0.7, 0.9, 0.9], [0, 0.3])
    uf.plotOverlay([FR_eta2_CR, FR_eta2_VR], ['CR: N_{jet}<8, N_{b-jet}=2', 'VR: N_{jet}<8, N_{b-jet}>=3'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_CRVR_' + tauProng + 'Eta2', 'AP', [0.4, 0.7, 0.9, 0.9], [0, 0.3])
    uf.plotOverlay([FR_eta3_CR, FR_eta3_VR], ['CR: N_{jet}<8, N_{b-jet}=2', 'VR: N_{jet}<8, N_{b-jet}>=3'], era, 'Fake rate', inputDirDic['mc'] + 'results/FR_CRVR_' + tauProng + 'Eta3', 'AP', [0.4, 0.7, 0.9, 0.9], [0, 0.3])
   
def writeFRToFileNew(FR_ptInEtaList, inputDirDic):
    outFile = ROOT.TFile( inputDirDic['mc'] + 'results/fakeRateInPtEta.root', "RECREATE")
    for i in range(len(FR_ptInEtaList)):
        FR_ptInEtaList[i].SetName('fakeRate_Eta'+str(i+1))
        FR_ptInEtaList[i].Write()
    outFile.Write()
    print('fake rate file here: ', outFile.GetName())
    outFile.Close() 

    
    
    
# def plotFRPerEta(inputDirDic, regionList, era, eta, plotName):
def plotFRPerEta(inputDirDic, regionList, era, eta, prong, plotName):
    regionList_eta1 = addEta(regionList, eta, prong)
    variable = ['tausF_1jetPt']
    processList = ['jetHT', 'tt', 'ttX', 'singleTop', 'WJets']
    # sumProcessPerVar = uf.getSumHist(inputDirDic, regionList_eta1, processList, variable, era, False)#sumProcessPerVar[ivar][region][sumPro]
    sumProcessPerVar, sys = uf.getSumHist(inputDirDic, regionList_eta1, processList,{}, variable, era, False)#sumProcessPerVar[ivar][region][sumPro]

    h_TTau = dataMinusGenBG(sumProcessPerVar['tausF_1jetPt'], regionList_eta1[0], regionList_eta1[1])
    h_TTau.Print()
    h_FTau = dataMinusGenBG(sumProcessPerVar['tausF_1jetPt'], regionList_eta1[2], regionList_eta1[3]) 
    h_FTau.Print()
    ptBins = np.array( [20.0, 30, 40.0, 50, 70.0, 90.0, 120.0,  300.0] )
    h_TTau_rebin = h_TTau.Rebin(len(ptBins)-1, 'h_TTau_rebin', ptBins)
    h_FTau_rebin = h_FTau.Rebin(len(ptBins)-1, 'h_FTau_rebin', ptBins)
   
    plotDir = inputDirDic['mc'] + 'results/'
    uf.checkMakeDir( plotDir )
    plotName = plotDir + plotName
    FR = uf.plotEffTEff( h_TTau_rebin, h_FTau_rebin, plotName, era, 'tau fake rate', [0., 0.3], 'Fake rate')
    
    return FR
    
    
def dataMinusGenBG(sumProcessIVar, regionData, regionBG):
    data = sumProcessIVar[regionData]['jetHT'].Clone()
    bg = uf.addBGHist(sumProcessIVar, regionBG)
    return data-bg



def addEta(regionList, eta, prong):
    regionList_eta = []
    for i in regionList:
        regionList_eta.append(i+eta+prong)
    return regionList_eta
   
def plotOverlay_FR(inputDirDic, variableDic, etaBins,isVR, era, isJet=True): 
    FR_EtaListDic = {}
    FR_EtaListDic['1Eta'] = []
    FR_EtaListDic['2Eta'] = []
    FR_EtaListDic['3Eta'] = []
    # CRnames = ['CRa',  'CRc'] # for bjet
    # CRnames = ['CRa',  'CRb', 'CRc'] # for bjet
    # CRnames = ['CR', 'CRa'] # for jet
    if isJet:
        CRnames = ['CRb', 'VR'] # for jet
        legendList = ['<8 jets', '>=8 jets']
        plotUncer = False
    else:
        # CRnames = ['CRc', 'CRb'] # for bjet; new 'VR' and 'CR'
        CRnames = ['CRb', 'CRc'] # for bjet; new 'VR' and 'CR'
        legendList = [ '=1 bjet', '>=2 bjets']
        plotUncer = True
    for iCR in CRnames:
        iFR_EtaList, inoUse = getFRAndARNotTList( inputDirDic, variableDic, etaBins, isVR, True, era, iCR )
        FR_EtaListDic['1Eta'].append(iFR_EtaList[0])
        FR_EtaListDic['2Eta'].append(iFR_EtaList[1])
        FR_EtaListDic['3Eta'].append(iFR_EtaList[2])
    
    plotDir = inputDirDic['mc'] + 'results/'
    for iEta in ['1Eta', '2Eta', '3Eta']:
        # overLayName = plotDir + 'overlay_' + iEta +'.png'
        overLayName = plotDir + 'overlay' + CRnames[0]+CRnames[1] + iEta +'.png'
        # plotFROverlay( FR_EtaListDic[iEta], legendList, era, "FR", overLayName, False, [0, 0.35] )
        plotFROverlay( FR_EtaListDic[iEta], legendList, era, "FR", overLayName, plotUncer, [0, 0.35] )
   
    
    
            
def plotFROverlay(FRInRegionList, legendList,  era, yTitle,  plotName, ifUncerBand=False, yRange=[]):
    print('start to plot overlay..........\n')
    # can = ROOT.TCanvas('FR overlay', 'FR_overlay', 800, 600)
    can = ROOT.TCanvas('FR overlay', 'FR_overlay', 1000, 800)
    ROOT.gStyle.SetOptStat(ROOT.kFALSE)
    ROOT.gStyle.SetOptTitle(0)
    # ROOT.gStyle.SetTitleSize(0.07, "X")#not working
    # ROOT.gStyle.SetTitleSize(0.05, "Y")
    
    FRInRegionList[0].GetYaxis().SetRangeUser(FRInRegionList[0].GetMinimum()*0.6, FRInRegionList[0].GetMaximum()*1.5)
    FRInRegionList[0].GetYaxis().SetTitle(yTitle)
    FRInRegionList[0].GetYaxis().SetTitleSize(0.05)
    FRInRegionList[0].GetYaxis().SetLabelSize(0.035)
    FRInRegionList[0].GetYaxis().SetTitleOffset(1.0)
    FRInRegionList[0].GetXaxis().SetTitle(FRInRegionList[0].GetTitle())
    FRInRegionList[0].GetXaxis().SetTitleSize(0.05)
    FRInRegionList[0].SetLineColor(ROOT.kOrange)
    FRInRegionList[0].SetLineWidth(3)
    FRInRegionList[0].SetMarkerStyle(45)
    FRInRegionList[0].SetMarkerSize(2)
    FRInRegionList[0].SetMarkerColor(ROOT.kOrange)
    if len(yRange)>1:
        FRInRegionList[0].GetYaxis().SetRangeUser(yRange[0], yRange[1])
    
    FRInRegionList[0].Draw()
    print(FRInRegionList[0].GetName())
    
    FRInRegionList[1].SetLineColor(ROOT.kRed)
    FRInRegionList[1].SetLineWidth(3)
    FRInRegionList[1].SetMarkerStyle(94)
    FRInRegionList[1].SetMarkerSize(2)
    FRInRegionList[1].SetMarkerColor(ROOT.kRed )
    FRInRegionList[1].Draw('same')
    
    # if len(CRnames)>2:
    if len(FRInRegionList)>2:
        FRInRegionList[2].SetLineColor(ROOT.kMagenta)
        FRInRegionList[2].SetLineWidth(3)
        FRInRegionList[2].SetMarkerStyle(22)
        FRInRegionList[2].SetMarkerSize(2)
        FRInRegionList[2].SetMarkerColor(ROOT.kMagenta )
        FRInRegionList[2].Draw('same')
    
    #add uncertainty band for FR1
    if ifUncerBand:
        uncert = FRInRegionList[0].Clone()
        uncertValue = 0.10
        for ibin in range(1, FRInRegionList[0].GetNbinsX()+1):
            uncert.SetBinError(ibin, uncert.GetBinContent(ibin)*uncertValue)
        uncert.SetFillStyle(3013)
        uncert.SetFillColor(ROOT.kOrange)
        uncert.Draw('same e2')
   
    legend = ROOT.TLegend(0.55,0.7,0.9,0.9)
    for (i,iLe) in enumerate(legendList):
        legend.AddEntry(FRInRegionList[i], iLe)
            
   
    if ifUncerBand: 
        uncerEntry = '{} % uncertainty'.format(uncertValue*100)    
        legend.AddEntry(uncert, uncerEntry)
    legend.Draw()
    
    addCMSTextToCan(can, 0.18, 0.3, 0.92, era)
    
    can.SaveAs( plotName )
    print( yTitle, ' overlay plot here:', plotName )    
    
        

def writeFRToFile( FR_ptInEtaList, inputDirDic):
    etaBins = [0, 0.8, 1.5, 2.3]
    # ptBins = FR_ptInEtaList[0].GetXaxis().GetXbins().GetArray()
    n_bins_x = FR_ptInEtaList[0].GetNbinsX()
    ptBins = [FR_ptInEtaList[0].GetXaxis().GetBinLowEdge(i) for i in range(1, n_bins_x + 2)] # # +2 to include the upper edge of the last bin
    print('ptBins:', ptBins)
    
    outFileName = inputDirDic['mc'] + 'results/fakeRateInPtEta.root'
    outFile = ROOT.TFile( outFileName, "RECREATE") 
    fakeRate2D = ROOT.TH2D('fakeRate2D', 'fake rate in pt eta',  len(ptBins)-1, ptBins, len(etaBins)-1, etaBins )
    for ixbin in range(len(ptBins)-1):
        for iybin in range(len(etaBins)-1):
            iFR =  FR_ptInEtaList[iybin].GetBinContent(ixbin+1) #if the sum of squares of weights has been defined (via Sumw2), this function returns the sqrt(sum of w2). otherwise it returns the sqrt(contents) for this bin.
            iFRerror =  FR_ptInEtaList[iybin].GetBinError(ixbin+1)
            fakeRate2D.SetBinContent(ixbin+1, iybin+1, iFR)
            fakeRate2D.SetBinError(ixbin+1, iybin+1, iFRerror)
            

    # Assuming all histograms have the same binning along the x-axis
    # n_bins_x = hist_list[0].GetNbinsX()
    # x_bin_edges = [hist_list[0].GetXaxis().GetBinLowEdge(i) for i in range(1, n_bins_x + 2)]  # +2 to include the upper edge of the last bin
    
    # # Create the TH2D histogram
    # n_bins_y = len(hist_list)
    # th2d = ROOT.TH2D(name, title, n_bins_x, x_bin_edges[0], x_bin_edges[-1], n_bins_y, 0.5, n_bins_y + 0.5)
    
    # # Fill the TH2D histogram
    # for i, hist in enumerate(hist_list, start=1):
    #     for j in range(1, n_bins_x + 1):
    #         bin_content = hist.GetBinContent(j)
    #         th2d.SetBinContent(j, i, bin_content)
            
    # return th2d            

    
    outFile.Write()
    outFile.Close()
    print('fake rate file here: ', outFile.GetName())
    
    
 


def getFTFromLNotTData(FR_ptInEtaList, tauPtEtaListAR, ifPtBin=True):    
    fakeTauBG = 0.0
    fakeTauError = 0.0
    FTFromData = ROOT.TH1D()
    if ifPtBin:
        FTFromData = tauPtEtaListAR[0].Clone()
        FTFromData.Reset()
    else:
        etaBins = np.array([0, 0.8,1.6,2.3])
        FTFromData = ROOT.TH1D('fake tau from data', 'fake tau from data', 3, etaBins )
    FTFromData.Sumw2()
   
    for ipt in range(len(tauPtEtaListAR)):
        iEtaFT, iEtaFTErr, iFT_hist = calFTPerEta( tauPtEtaListAR[ipt], FR_ptInEtaList[ipt])
        fakeTauBG = fakeTauBG+iEtaFT
        fakeTauError = fakeTauError + iEtaFTErr
        if ifPtBin: 
            FTFromData.Add(iFT_hist)
        else:
            FTFromData.SetBinContent(ipt+1, iEtaFT)
            # FTFromData.SetBinError(ipt+1, iEtaFTErr)
            FTFromData.SetBinError(ipt+1, sqrt(iEtaFTErr) ) #???
    
        
    print('fake tau in AR:{} error: {}, '.format( fakeTauBG, sqrt(fakeTauError) ) )
    print('fake tau from hist ', FTFromData.Integral())
    return FTFromData
    
def calFTPerEta( tauptAR, FR):
    FT = 0.0
    FTErr = 0.0
    distribution = tauptAR.Clone()
    distribution.Reset()
    # distribution.Sumw2()
    for ibin in range(1,tauptAR.GetNbinsX()+1):
        iN_LnotT = tauptAR.GetBinContent(ibin)
        iFR = FR.GetBinContent(ibin)
        ifakeTau = iN_LnotT*(iFR/(1-iFR))
        FT=FT+ifakeTau
        
        iFRErr = FR.GetBinError(ibin)
        iNErr = ( pow(iN_LnotT, 2)/pow(1-iFR, 4) )*iFRErr + pow(iFR/(1-iFR), 2)*tauptAR.GetBinError(ibin)
        FTErr = FTErr+iNErr
        # print('iFR={} ,iFRErr={} , iFT={}, iNErr={}'.format( iFR, iFRErr, FT, iNErr) )
        
        distribution.SetBinContent( ibin, ifakeTau )
        distribution.SetBinError(ibin, sqrt( iNErr) )#???
    return FT, FTErr, distribution
            
    
def getSumProcessVarEta( inputDirDic, ieta, variableDic, isVR=True, ifGetLNotT=True, FRMeasureRegion='CR'):

    regionList = ["1tau0lCRGen", '1tau0lCR', '1tau0lCRLTauGen', "1tau0lCRLTau"]
    for (i,ire) in enumerate(regionList):
        ire = ire.replace('CR', FRMeasureRegion)
        regionList[i] = ire
    
    if ifGetLNotT:
        regionList.append( '1tau0lVRLTauNotT' )
        regionList.append( '1tau0lVRLTauNotTGen' )
        if not isVR:
            regionList[4] = '1tau0lCRLTauNotT'
            regionList[5] = '1tau0lCRLTauNotTGen'
    

    #sumProcessPerVar[var][region][sumedProcess] = hist
    for ire in range(len(regionList)):
        regionList[ire] = regionList[ire] + ieta
    sumProcessPerVar = {}
    sumProcessPerVarSys = {} 
    for ivar in variableDic.keys():
        sumProcessPerVar[ivar], sumProcessPerVarSys[ivar]= uf.getSummedHists( inputDirDic, regionList, ivar )
    print( sumProcessPerVar )
    
    return sumProcessPerVar, inputDirDic, regionList
       
# def getInputDic( inVersion, histVersion, era):
#     inputDirBase = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/' + era +'/'
#     inputDirDic = {
#         'mc': inputDirBase + inVersion + '/mc/' + histVersion + '/',
#         'data': inputDirBase + inVersion + '/data/' + histVersion + '/',
#     }
#     return inputDirDic
        
    
    
    
# def plotPtInEta(  sumProcessPerVar, inputDirDic, regionList, variableDic, etaRegion , ifPlot = True, era = '2016', isDataMC=False):
#     print('starting to plot FR for ieta', )
#     h_CR_dataSubBG = histDateMinusGenBG(list(variableDic.keys())[0], sumProcessPerVar[list(variableDic.keys())[0]], regionList[1], regionList[0], isDataMC)
#     h_CRLTau_dataSubBG = histDateMinusGenBG(list(variableDic.keys())[0], sumProcessPerVar[list(variableDic.keys())[0]], regionList[3], regionList[2], isDataMC)

#     binLowEges = variableDic[list(variableDic.keys())[0]]
#     # h_CR_dataSubBG_rebin =  h_CR_dataSubBG.Rebin(len(binLowEges)-1, 'h_CR_dataSubBG_rebin', binLowEges  ) 
#     h_CR_dataSubBG_rebin =  h_CR_dataSubBG.Rebin(len(binLowEges)-1, regionList[1], binLowEges  ) 
#     # h_CRLTau_dataSubBG_rebin = h_CRLTau_dataSubBG.Rebin(len(binLowEges)-1, 'CRLTau', binLowEges )
#     h_CRLTau_dataSubBG_rebin = h_CRLTau_dataSubBG.Rebin(len(binLowEges)-1, regionList[3], binLowEges )
#     if len(regionList)>4:
#         h_VRLTauNotT_dataSubBG = histDateMinusGenBG(list(variableDic.keys())[0], sumProcessPerVar[list(variableDic.keys())[0]], regionList[4], regionList[5], isDataMC) #tausL_1pt in VRLNotT
#         h_VRLTauNotT_dataSubBG_rebin = h_VRLTauNotT_dataSubBG.Rebin(len(binLowEges)-1, regionList[4], binLowEges)
#     else:
#         h_VRLTauNotT_dataSubBG_rebin = h_CR_dataSubBG_rebin.Clone()
#         h_VRLTauNotT_dataSubBG_rebin.Reset()

#     h_fakeRateCR = h_CR_dataSubBG_rebin.Clone()
#     h_fakeRateCR.Reset()
#     h_fakeRateCR.Sumw2()
#     h_fakeRateCR.Divide(h_CR_dataSubBG_rebin, h_CRLTau_dataSubBG_rebin)
#     h_fakeRateCR.SetName('FR_' + regionList[1] )
    
    

#     if ifPlot:
#         plotDir = inputDirDic['mc'] + 'results/' 
#         uf.checkMakeDir( plotDir )
#         if not isDataMC:
#             plotName = plotDir + list(variableDic.keys())[0] +etaRegion+'_'+regionList[1]+ '_FR_sumGenBg_better.png'
#         else:
#             plotName = plotDir + list(variableDic.keys())[0] +etaRegion+ '_FR_sumGenBg_better_totalMCAsData.png'
#         plotEfficiency( h_CR_dataSubBG_rebin, h_CRLTau_dataSubBG_rebin, h_fakeRateCR, plotName, era , True, 'fake rate')
   
#     # h_fakeRateCR.Print() 
#     return h_fakeRateCR, h_VRLTauNotT_dataSubBG_rebin
    
    
def getFRAndARNotTList( inputDirDic, variableDic, etaBins, isVR,  ifPlot=True, era='2016', FRMeasureRegion='CR'):
    # etaBins = np.array([0, 0.8, 1.5, 2.3])
    etaList = []
    for i in range(1, len(etaBins)):
        etaList.append('_Eta'+str(i))
    FR_ptInEtaList = []
    tauPtEtaListAR = []
    for ieta in etaList:
        sumProcessPerVar, inputDirDic, regionList  = getSumProcessVarEta( inputDirDic, ieta, variableDic, isVR, False, FRMeasureRegion )
        ietaPt, ietaVR =  plotPtInEta( sumProcessPerVar, inputDirDic, regionList,  variableDic , ieta, ifPlot, era)
        FR_ptInEtaList.append(ietaPt)
        tauPtEtaListAR.append(ietaVR)
    return FR_ptInEtaList, tauPtEtaListAR





def getHistForFakeRate( var, sumProcessPerVar, etaRegion ):
    h_CR_data = sumProcessPerVar[var]['1tau0lCR'+etaRegion]['data'] 
    h_CR_data.Print()
    h_CR_bgGenTau = addBGHist(sumProcessPerVar, var, '1tau0lCRGen'+etaRegion)
    h_CR_bgGenTau.Print() 
    h_CR_dataSubBG = h_CR_data - h_CR_bgGenTau
    h_CR_dataSubBG.Print()

    h_CRLTau_data = sumProcessPerVar[var]['1tau0lCRLTau'+etaRegion]['data'] 
    h_CRLTau_bgGenTau = addBGHist(sumProcessPerVar, var, '1tau0lCRLTauGen'+etaRegion)
    h_CRLTau_dataSubBG = h_CRLTau_data - h_CRLTau_bgGenTau
    
    h_VR_data = sumProcessPerVar[var]['1tau0lVRLTauNotT'+etaRegion]['data']

    return h_CR_dataSubBG, h_CRLTau_dataSubBG










if __name__=='__main__':
    main()
