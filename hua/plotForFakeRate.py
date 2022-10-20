
from math import sqrt

import numpy as np
import ROOT
import usefulFunc as uf
# from cv2 import sqrt
from ttttGlobleQuantity import summedProcessList

from writeCSVforEY import getSummedHists


def main():
    era = '2016' 
    inVersion = 'v1baseline_v38TESandJERTauPt20_preselection'
    histVersion = 'variableHists_v6forFakeRate3EtaRegions'
    
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v1baseline_v38TESandJERTauPt20_preselection/'
    # version = 'v6forFakeRate3EtaRegions'
   
    # versions = ['v4forFakeRate_eta0-06', 'v4forFakeRate_eta06-12', 'v4forFakeRate_eta12-18', 'v4forFakeRate_eta18-24']
    # for version in versions:``
    ptBins = np.array( [20.0, 40.0, 60.0, 80.0, 120.0,  220.0] )
    variableDic = {
        'tausL_1pt': ptBins,
    }
  
    
        
    
    # isVR = True
    isVR = False
    FR_ptInEtaList, tauPtEtaListAR = getFRAndARNotTList(inVersion, histVersion, era, variableDic, isVR, True)
    
    
    #application in AR
    getFTFromLNotTData(FR_ptInEtaList, tauPtEtaListAR)
            
    
    # etaBins = np.array( [0.0, 0.6, 1.2, 1.8, 2.4] )
    # fakeRate2D = ROOT.TH2D('fakeRate2D', 'fake rate in pt eta',  len(ptBins)-1, ptBins, len(etaBins)-1, etaBins )

def getFTFromLNotTData(FR_ptInEtaList, tauPtEtaListAR):    
    fakeTauBG = 0.0
    fakeTauError = 0.0
    FTFromData = tauPtEtaListAR[0].Clone()
    FTFromData.Reset()
    FTFromData.Sumw2()
    for ipt in range(len(tauPtEtaListAR)):
        iEtaFT, iEtaFTErr, iFT_hist = calFTPerEta( tauPtEtaListAR[ipt], FR_ptInEtaList[ipt])
        fakeTauBG = fakeTauBG+iEtaFT
        fakeTauError = fakeTauError + iEtaFTErr
        FTFromData.Add(iFT_hist)
    print('fake tau in AR:{} error: {}, '.format( fakeTauBG, sqrt(fakeTauError) ) )
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
        distribution.SetBinError(ibin, iNErr)
    return FT, FTErr, distribution
            
    
def getSumProcessVarEta( inVersion, histVersion, era, ieta, variableDic, isVR=True):
    inputDirBase = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/' + era +'/'
    inputDirDic = {
        'mc': inputDirBase + inVersion + '/mc/' + histVersion + '/',
        'data': inputDirBase + inVersion + '/data/' + histVersion + '/',
    }

    regionList = ["1tau0lCRGen", '1tau0lCR', '1tau0lCRLTauGen', "1tau0lCRLTau", "1tau0lVRLTauNotT", "1tau0lVRLTauNotTGen"]
    if not isVR:
        regionList[4] = '1tau0lCRLTauNotT'
        regionList[5] = '1tau0lCRLTauNotTGen'
    

    #sumProcessPerVar[var][region][sumedProcess] = hist
    # etaList = ['_Eta1', '_Eta2', '_Eta3']
    for ire in range(len(regionList)):
        regionList[ire] = regionList[ire] + ieta
    sumProcessPerVar = {}
    for ivar in variableDic.keys():
        sumProcessPerVar[ivar] = getSummedHists( inputDirDic, regionList, ivar )
    print( sumProcessPerVar )
    
    return sumProcessPerVar, inputDirDic, regionList
       
    
    
    
    
def plotPtInEta(  sumProcessPerVar, inputDirDic, regionList, variableDic, etaRegion , ifPlot = True):

        
    # h_CR_dataSubBG, h_CRLTau_dataSubBG = getHistForFakeRate( list(variableDic.keys())[0], sumProcessPerVar)
    h_CR_dataSubBG = histDateMinusGenBG(list(variableDic.keys())[0], sumProcessPerVar, '1tau0lCR'+etaRegion)
    h_CRLTau_dataSubBG = histDateMinusGenBG(list(variableDic.keys())[0], sumProcessPerVar, '1tau0lCRLTau'+etaRegion)
    # h_VRLTauNotT_dataSubBG = histDateMinusGenBG(list(variableDic.keys())[0], sumProcessPerVar, '1tau0lVRLTauNotT'+etaRegion)
    h_VRLTauNotT_dataSubBG = histDateMinusGenBG(list(variableDic.keys())[0], sumProcessPerVar, regionList[4])


    binLowEges = variableDic[list(variableDic.keys())[0]]
    h_CR_dataSubBG_rebin =  h_CR_dataSubBG.Rebin(len(binLowEges)-1, 'h_CR_dataSubBG_rebin', binLowEges  ) 
    h_CRLTau_dataSubBG_rebin = h_CRLTau_dataSubBG.Rebin(len(binLowEges)-1, 'CRLTau', binLowEges )
    h_VRLTauNotT_dataSubBG_rebin = h_VRLTauNotT_dataSubBG.Rebin(len(binLowEges)-1, regionList[4], binLowEges)

    h_fakeRateCR = h_CR_dataSubBG_rebin.Clone()
    h_fakeRateCR.Reset()
    h_fakeRateCR.Sumw2()
    h_fakeRateCR.Divide(h_CR_dataSubBG_rebin, h_CRLTau_dataSubBG_rebin)
    h_fakeRateCR.SetName('fakeRate')

    if ifPlot:
        plotDir = inputDirDic['mc'] + 'results/' 
        uf.checkMakeDir( plotDir )
        plotName = plotDir + list(variableDic.keys())[0] +etaRegion+ '_FR.png'
        plotEfficiency( h_CR_dataSubBG_rebin, h_CRLTau_dataSubBG_rebin, h_fakeRateCR, plotName )
   
    h_fakeRateCR.Print() 
    return h_fakeRateCR, h_VRLTauNotT_dataSubBG_rebin
    
    
def getFRAndARNotTList( inVersion, histVersion, era, variableDic, isVR, ifPlot=True):
    etaList = ['_Eta1', '_Eta2', '_Eta3']
    FR_ptInEtaList = []
    tauPtEtaListAR = []
    for ieta in etaList:
        sumProcessPerVar, inputDirDic, regionList  = getSumProcessVarEta( inVersion, histVersion, era, ieta, variableDic, isVR )
        ietaPt, ietaVR =  plotPtInEta( sumProcessPerVar, inputDirDic, regionList,  variableDic , ieta, ifPlot)
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

def histDateMinusGenBG(var, sumProcessPerVar, region):
    h_data = sumProcessPerVar[var][region]['data']
    h_data.Sumw2()
    h_bgGen = addBGHist(sumProcessPerVar, var, region)
    h_dataMBG = h_data - h_bgGen
    return h_dataMBG



def plotEfficiency(h_numeritor, h_dinominator, h_eff, plotName):
    can = ROOT.TCanvas('efficiency', 'efficiency', 800, 600)
    ROOT.gStyle.SetOptStat(ROOT.kFALSE)

    h_dinominator.SetLineColor(ROOT.kBlue+4)
    h_dinominator.GetYaxis().SetRangeUser(h_numeritor.GetMinimum()*0.9, h_dinominator.GetMaximum()*1.1)
    h_dinominator.Draw()
    h_numeritor.Draw('same')
    can.Update()

    h_efficiency = h_eff.Clone()
    rightmax = 1.1*h_efficiency.GetMaximum();
    scale = ROOT.gPad.GetUymax()/rightmax;
    h_efficiency.SetLineColor(ROOT.kRed)
    h_efficiency.Scale(scale) #!!!need to consider this scaling effect on uncertainty
    h_efficiency.Draw("same")
    
    axis = ROOT.TGaxis(ROOT.gPad.GetUxmax(),ROOT.gPad.GetUymin(),
        ROOT.gPad.GetUxmax(), ROOT.gPad.GetUymax(),0,rightmax,510,"+L")
    axis.SetLineColor(ROOT.kRed)
    axis.SetLabelColor(ROOT.kRed)
    axis.Draw()


    can.SaveAs(plotName)



def addBGHist(sumProcessPerVar, var, region):
    sumHist = sumProcessPerVar[var][region][summedProcessList[0]]
    sumHist.Reset()
    sumHist.Sumw2()
    sumHist.SetName(region+ '_bgSum_' + var )
    for ipro in summedProcessList:
        # if ipro=='data' or ipro=='tttt': continue
        if ipro=='data' or ipro=='qcd' or ipro=='tttt': continue
        sumHist.Add( sumProcessPerVar[var][region][ipro])
    return sumHist




if __name__=='__main__':
    main()
