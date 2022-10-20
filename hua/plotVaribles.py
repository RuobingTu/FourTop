import math
import os
# import sys
from array import array

# from ROOT import TFile, TLatex
from ROOT import *
from ttttGlobleQuantity import (histoGramPerSample, lumiMap, samples,
                                samplesCrossSection, summedProcessList)

from plotForFakeRate import getFRAndARNotTList, getFTFromLNotTData
from setTDRStyle import setTDRStyle
from writeCSVforEY import getProcessScale, getSummedHists

setTDRStyle()
latex = TLatex()
latex.SetNDC()
latex.SetTextAlign(31)

cmsTextFont = 61
extraTextFont = 52

latex2 = TLatex();
latex2.SetNDC();
latex2.SetTextSize(0.04);
latex2.SetTextAlign(31);

cmsText = "CMS"
extraText = "Preliminary"


colourPerSample = {
    'tttt':kPink-9,
    'tt': kRed-4,
    'qcd': kOrange-2,
    'ttX': kPink+2,
    'singleTop': kGreen-4,
    'VV': kGreen+2,
    'WJets': kOrange,
    'fakeTau': kBlue,
}


legendOrder = ['fakeTau', 'tttt', 'qcd', 'tt', 'ttX', 'singleTop', 'VV', 'WJets']

fakeTauYiled = {
    '1tau0lCR':  15569.67,
    '1tau0lVR': 11997.29, 
}


# includeDataInStack = False
includeDataInStack = True

def main():
    # era = '2016preVFP'
    # era = '2016postVFP'
    era = '2016'
    # era = '2018'

    # inVersion = 'v0noBaseline_v29LorentzProblemSolvedNoJERnoTES'
    # inVersion = 'v1baseline_v29LorentzProblemSolvedNoJERnoTES'
    # inVersion = 'v0noBaseline_v30TESnoJER'
    # inVersion = 'v1baseline_v33TESnoJERCodeOptimzation'
    # inVersion = 'v1baseline_v36TESandJERByHuiling'
    inVersion = 'v1baseline_v38TESandJERTauPt20_preselection'
    # histVersion = 'variableHists_v1variables'
    # histVersion = 'variableHists_v1variablesUsingMyclass'
    # histVersion = 'variableHists_v2addingPileupWeight'
    # histVersion = 'variableHists_v3pileUpAndNewRange'
    histVersion = 'variableHists_v6forFakeRate3EtaRegions'
    # variables = [ 'jets_HT', 'jets_number', 'jets_bScore', 'jets_1pt','jets_2pt','jets_3pt', 'jets_4pt', 'jets_5pt', 'jets_6pt', 'jets_rationHT_4toRest', 'tausT_1pt', 'tausT_1eta', 'tausT_1phi', 'bjetsM_MHT', 'bjetsM_number', 'bjetsM_1pt', 'bjetsM_HT'  ]
    # variables = [ 'jets_HT', 'tausL_1pt']
    variables = [ 'tausL_1pt']
    # regionList = [ '1tau0lSR', '1tau0lCR', '1tau0lVR', '1tau0lCR2', '1tau0lCR3', '1tau0lCR4']
    # regionList = ['1tau1lSR', '1tau1lCR0', '1tau1lCR1','1tau1lCR2', '1tau1lCR3']
    # regionList = ['1tau1lCR0', '1tau1lCR2' ]
    # regionList = ['1tau0lCR', '1tau0lVR', '1tau0lCR2', '1tau0lCR3', '1tau0lCR4']
    regionList = ['1tau0lCR', '1tau0lCRGen', '1tau0lCRNotGen', '1tau0lCRLTauNotT']
    # regionList = ['1tau0lVR', '1tau0lVRGen', '1tau0lVRNotGen']
   
    ifFromData = True 
    # plotName = 'dataVsMC_qcdYieldCorrected'
    plotName = 'dataVsMC'






    inputDirBase = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/' + era +'/'
    inputDir = {
        'mc': inputDirBase + inVersion + '/mc/' + histVersion + '/',
        'data': inputDirBase + inVersion + '/data/' + histVersion + '/',
    }


    #sumProcessPerVar[var][region][sumedProcess] = hist
    sumProcessPerVar = {}
    for ivar in variables:
        sumProcessPerVar[ivar] = getSummedHists( inputDir, regionList, ivar )       
    print( sumProcessPerVar )
    #getSummedHists gets null pointer for hist don't exist


    hasFakeTau = False
    for ire in regionList:
        if 'Gen' in ire:
            hasFakeTau = True
    if hasFakeTau:
        for ivar in sumProcessPerVar:
            replaceBgWithGen( sumProcessPerVar[ivar], regionList, False )
            


    plotDir = inputDir['mc']+'results/'
    if not os.path.exists( plotDir ):
        os.mkdir( plotDir )
    sumProcessPerVarSys = {}
    for variable in variables:
        if not hasFakeTau:
            for iRegion in regionList:       
                makeStackPlot(sumProcessPerVar[variable][iRegion], sumProcessPerVarSys, variable, iRegion, plotDir, plotName) 
        else:
            makeStackPlot(sumProcessPerVar[variable][regionList[0]], sumProcessPerVarSys, variable, regionList[0], plotDir, plotName)
            
            
    #     print( systs[variable])
        # makeStackPlot_mcOnly(nom[variable],systs[variable],variable,myRegion, plotDir, 'mcOnly' )
            # makeStackPlot( nom[variable], systs[variable], variable, myRegion,  plotDir, 'dataVsMC' )

def replaceBgWithGen( sumProcessIvar, regionList, ifGetFromMC=True):
    #1tau0lCR relace with 1tauCRGen
    for ipro in sumProcessIvar[regionList[0]].keys():
        if ipro=='data': continue
        sumProcessIvar[regionList[0]][ipro] = sumProcessIvar[regionList[1]][ipro]
        
    sumProcessIvar[regionList[0]]['fakeTau'] = sumProcessIvar[regionList[0]]['tttt'].Clone()
    sumProcessIvar[regionList[0]]['fakeTau'].Sumw2()
    if not ifGetFromMC:
    #adding 'fakeTau' process from CRNotGen
        for ipro in sumProcessIvar[regionList[2]].keys():
            if ipro=='data' or ipro=='tttt': continue
            sumProcessIvar[regionList[0]]['fakeTau'].Add( sumProcessIvar[regionList[2]][ipro] ) 
    else:
        #adding 'fakeTau' from CRLTauNotT data
       sumProcessIvar[regionList[0]]['fakeTau'] = getShapeFromData() 
        
    #scale to fake rate prediction
    sumProcessIvar[regionList[0]]['fakeTau'].Scale( fakeTauYiled[regionList[0]]/ sumProcessIvar[regionList[0]]['fakeTau'].Integral())
 
 
 def getShapeFromData( inputDir, ifPt=True):
    # etaList = ['_Eta1', '_Eta2', '_Eta3']
    # for ieta in etaList:
    ptBins = np.array( [20.0, 40.0, 60.0, 80.0, 120.0,  220.0] )
    variableDic = {
        'tausL_1pt': ptBins,
    }
    isVR = False
    FR_ptInEtaList, tauPtEtaListAR = getFRAndARNotTList(inputDir, variableDic, isVR, False)
    
    fakeTauFromData = getFTFromLNotTData(FR_ptInEtaList, tauPtEtaListAR)
    
    return fakeTauFromData
        
        
        
        


def checkHists( histsDict ):
    for ikey in histsDict.keys():
        print('iProcess: ', ikey )
        histsDict[ikey].Print()

def extractHistograms( dir, variablesToCheck , myRegion):
    nominalHists = {}
    systematicHists = {}

    for var in variablesToCheck:
        nominalHists[var] = {}
        systematicHists[var] = {}
    #nominalHists[varName][histoGramPerSample[sampleName]]

    # getHistsFromDir() #???need to combine the data mc into one function

    for inFileName in os.listdir( dir['mc'] ):
        # sampleName = inFileName.split('_variableHist')[0]
        sampleName = inFileName.split('.root')[0]

        if not sampleName in samples: continue
        print('opening file: ', inFileName )
        inFile = TFile( os.path.join(dir['mc']+inFileName), "READ" )
        for key in inFile.GetListOfKeys():
            ihistName = key.GetName()
            if 'eventCount' in  key.GetName(): continue
            varName = key.GetName().split(sampleName)[1][1:]
            # print('keys in file: ', key)

            iProScale = 1.0
            print('sampleName: ', sampleName)
            if  (not 'jetHT' in sampleName):
                # iProScale = getProcessScale( sampleName, '2016postVFP' )
                # print('passing mc')

                iregionName = ihistName.split('_')[0]
                print('iregion: ', iregionName)
                if not myRegion==iregionName: continue
                print('passing region')
                if not varName in variablesToCheck: continue#only check 
                print('passing varName')
                if not ('up' in key.GetName()) or ('down' in key.GetName()  ):
                    #for nominal hists
                    print('start to get mc hists<<<<<<<<<<<<<<<<<<<<<<<<<\n')
                    if histoGramPerSample[sampleName] not in nominalHists[varName].keys():
                        #nominalHist[varName].keys() is summed hists
                        nominalHists[varName][histoGramPerSample[sampleName]] = inFile.Get( key.GetName()).Clone()
                        # nominalHists[varName][histoGramPerSample[sampleName]].Scale( iProScale)
                        nominalHists[varName][histoGramPerSample[sampleName]].SetDirectory(0)
                        print('nom[{}][{}] get hist: {} '.format( varName, histoGramPerSample[sampleName], key ) )
                    else: #add grouped mc bg together
                        nominalHists[varName][histoGramPerSample[sampleName]].Add(inFile.Get(key.GetName()), iProScale)
                        print('nom[{}][{}] add hist: {} '.format( varName, histoGramPerSample[sampleName], key)  )
                else: #systematic uncertainties
                    if histoGramPerSample[sampleName] not in systematicHists[varName].keys(): systematicHists[varName][histoGramPerSample[sampleName]] = {}
                    systName = key.GetName().split("{0}_".format(sampleName))[-1]
                    #depends on how I name my syst histgram
                    if systName in systematicHists[varName][histoGramPerSample[sampleName]].keys():
    #                    print sampleName,varName,systName, systematicHists[varName][histoGramPerSample[sampleName]][systName]
                        systematicHists[varName][histoGramPerSample[sampleName]][systName].Add(inFile.Get(key.GetName()))
                    else:
                        systematicHists[varName][histoGramPerSample[sampleName]][systName] = inFile.Get(key.GetName()).Clone()
                        systematicHists[varName][histoGramPerSample[sampleName]][systName].SetDirectory(0)
            # for syst in ["JER","JES"]:
            #JER and JES in a different files, good idea!
        # else: # Now do data stuff
        inFile.Close()
        print('done getting mc hists<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n')
        # print('\n')    


    print( 'now getting data hists<<<<<<<<<<<<\n')
    for inFileName in os.listdir( dir['data'] ):
        print('\n')
        if not '.root' in inFileName: continue
        inFile = TFile( os.path.join(dir['data']+inFileName), "READ" )
        print( 'openning {}\n'.format( inFileName ) )

        sampleName = inFileName.split('.root')[0]
        for key in inFile.GetListOfKeys():
            ihistName = key.GetName()
            if 'forYieldCount' in  ihistName: continue
            varName = ihistName.split(sampleName)[1][1:]
            if not varName in variablesToCheck: continue#only check 
            iregionName = ihistName.split('_')[0]
            if not myRegion==iregionName: continue
            print( 'ihist:{} in {}\n'.format( ihistName, inFileName  ) )
            if not "data" in nominalHists[varName].keys():
                nominalHists[varName]["data"] = inFile.Get( ihistName ).Clone()
                nominalHists[varName]["data"].SetDirectory(0)
                print('nomMap[{}][\'data\'] get hist:{}: '.format( varName, ihistName ) )
                # nominalHists[varName]["qcd"] = inFileQCD.Get("{0}_{1}".format(varName,sampleName)).Clone()
                # nominalHists[varName]["qcd"].SetDirectory(0)
            else:
                nominalHists[varName]["data"].Add(inFile.Get( ihistName ))
                print('nomMap[{}][\'data\'] add hist:{}: '.format( varName, ihistName ) )
                # nominalHists[varName]["qcd"].Add(inFileQCD.Get("{0}_{1}".format(varName,sampleName)))
    print( 'done getting data hists<<<<<<<<<<<\n')

    return (nominalHists,systematicHists)

# def getHistsFromDir( dir ):
#     return ( nominalHists, systematicHists )




def makeStackPlot_mcOnly(nominal,systHists,name,region,outDir, plotNameEtra = ""):
    #name is variable name
    stack = THStack("{1}_{0}".format(region,name),"{1}_{0}".format(region,name))
    canvy = TCanvas("{1}_{0}".format(region,name),"{1}_{0}".format(region,name),1000,800)
    leggy = TLegend(0.8,0.6,0.95,0.9)
    leggy.SetFillStyle(1001)
    leggy.SetBorderSize(1)
    leggy.SetFillColor(0)
    leggy.SetLineColor(0)
    leggy.SetShadowColor(0)
    leggy.SetFillColor(kWhite)

    canvy.cd()
    if includeDataInStack: canvy.SetBottomMargin(0.3)

    #???no dataHist
    # sumHist = nominal[nominal.keys()[0]].Clone()
    keyList = list(nominal.keys())
    sumHist = nominal[keyList[0]].Clone()
    sumHist.Reset()
    #???no systsUp systsDown

    for i in nominal.keys():
        print('ikey: ', i)
        if i=='data': continue
        nominal[i].SetFillColor(colourPerSample[i])
        nominal[i].SetLineColor(kBlack)
        nominal[i].SetLineWidth(1)
        nominal[i].GetXaxis().SetTitle(name)
        sumHist.Add(nominal[i])

    if "data" in nominal.keys():
        leggy.AddEntry(nominal['data'],"Data","p")
    for entry in legendOrder:
        if entry=='tttt': continue
        leggy.AddEntry(nominal[entry],entry,"f")
    # leggy.AddEntry(assymErrorPlot,"Systs","f")

    legendOrder.reverse()
    for entry in legendOrder:
        if entry=='tttt': continue
        stack.Add(nominal[entry])
        # print( 'ientry integral: ', nominal[entry].Integral() )
    legendOrder.reverse()


    maxi = stack.GetMaximum()
    # if dataHist.GetMaximum() > stack. GetMaximum(): maxi = dataHist.GetMaximum()
    stack.SetMaximum(maxi)
    # stack.GetXaxis().SetTitle(name)
    stack.Draw("hist")

    #scale tttt
    signal = nominal['tttt'].Clone()
    signal.Scale(1000)
    # signal.SetLineColor(kPink-9)
    signal.SetLineColor(kBlue)
    signal.SetLineStyle(kSolid)
    signal.SetLineWidth(4)
    signal.SetFillStyle(3335)
    signal.SetFillColor(kBlue)
    leggy.AddEntry( signal, 'tttt', 'l')
    # signal.GetXaxis().SetTitle(name)
    # signal.Print()
    signal.Draw("SAME HIST ")


    leggy.Draw()

    # canvy.SaveAs(outDir+"{2}{0}{1}.png".format(region,savePost,name))
    canvy.SaveAs( outDir+"{}_{}_{}.png".format(region,name, plotNameEtra) )

    canvy.cd()

def makeStackPlot(nominal,systHists,name,region,outDir,savePost = ""):
    #name is variable name
    print( 'start plotting data/mc plot for {}'.format(name))
    canvasName = '{}_{}'.format( region, name )
    stack = THStack( canvasName, canvasName )
    canvy = TCanvas( canvasName, canvasName, 1000,800)
    leggy = TLegend(0.8,0.6,0.95,0.9)
    leggy.SetFillStyle(1001)
    leggy.SetBorderSize(1)
    leggy.SetFillColor(0)
    leggy.SetLineColor(0)
    leggy.SetShadowColor(0)
    leggy.SetFillColor(kWhite)

    canvy.cd()
    if includeDataInStack: canvy.SetBottomMargin(0.3)

    # sumHist = nominal[nominal.keys()[0]].Clone()
    keyList = list(nominal.keys())
    #the base hist for adding
    sumHist = nominal[keyList[0]].Clone()
    sumHist.Reset()
    systsUp = nominal[keyList[0]].Clone("systsUp")
    systsUp.Reset()
    systsDown = nominal[keyList[0]].Clone("systsDown")
    systsDown.Reset()
    dataHist = 0

    doSystmatic = False
    if not systHists:
        print( 'systHist empty, not including systematic uncertainty\n')
        doSystmatic = False
    print( 'doSystmatic: ', doSystmatic )

    #here we get dataHist and add all MC for sumHist    
    for i in nominal.keys():
        # i is i summed MC
        if i == "data":
            dataHist = nominal["data"]
            dataHist.SetMarkerStyle(20)
            dataHist.SetMarkerSize(1.2)
            dataHist.SetMarkerColor(kBlack)
            continue
        nominal[i].SetFillColor(colourPerSample[i])
        nominal[i].SetLineColor(kBlack)
        nominal[i].SetLineWidth(1)
        nominal[i].GetXaxis().SetTitle(name)
        sumHist.Add(nominal[i]) #sumHist is bg+signal
        # if i == "qcd": continue #special treatment to data driven bg
        #???need systsUp and systsDown calculation
            # tempUp,tempDown = getSystVariation(nominal[i],systHists[i],i,region, doSystmatic )
        if doSystmatic:
            tempUp,tempDown = getSystVariation_my(nominal[i],systHists[i] )
            systsUp.Add(tempUp)
            systsDown.Add(tempDown)

    #add sytematic uncertainty
    systsUp, systsDown = addStatisticUncer( sumHist, systsUp, systsDown )

    #get the uncertainty for stack MC
    assymErrorPlot = getErrorPlot(sumHist,systsUp,systsDown)
    #systsUp and systsDown are the total bin up and down uncertainty, not n+-uncertainty


    assymErrorPlot.SetFillStyle(3013)
    assymErrorPlot.SetFillColor(14)



    if "data" in nominal.keys():
        leggy.AddEntry(nominal['data'],"Data","p")
    for entry in legendOrder:
        leggy.AddEntry(nominal[entry],entry,"f")
    leggy.AddEntry(assymErrorPlot,"totalUncer","f")

    legendOrder.reverse()
    for entry in legendOrder:
        stack.Add(nominal[entry])
        # print( 'ientry integral: ', nominal[entry].Integral() )
    legendOrder.reverse()


    maxi = stack.GetMaximum()
    if dataHist.GetMaximum() > stack. GetMaximum(): maxi = dataHist.GetMaximum()
    stack.SetMaximum(maxi)
    stack.Draw("hist")

    dataHist.Print()
    # if includeDataInStack: dataHist.Draw("e1x0 same")
    if includeDataInStack: dataHist.Draw("e0 same")

    assymErrorPlot.Draw("e2 SAME")

    if includeDataInStack:
        ratioCanvy = TPad("{0}_ratio".format(name),"{0}_ratio".format(name),0.0,0.0,1.0,1.0)
        ratioCanvy.SetTopMargin(0.7)
        ratioCanvy.SetFillColor(0)
        ratioCanvy.SetFillStyle(0)
        ratioCanvy.SetGridy(1)
        ratioCanvy.Draw()
        ratioCanvy.cd(0)
        SetOwnership(ratioCanvy,False)

        sumHistoData = dataHist.Clone(dataHist.GetName()+"_ratio")
        sumHistoData.Sumw2()
        sumHistoData.Divide(sumHist)

        sumHistoData.GetYaxis().SetTitle("Data/MC")
        sumHistoData.GetYaxis().SetTitleOffset(1.3)
        ratioCanvy.cd()
        SetOwnership(sumHistoData,False)
        sumHistoData.SetMinimum(0.8)
        sumHistoData.SetMaximum(1.2)
        sumHistoData.GetXaxis().SetTitle(name)
        sumHistoData.GetXaxis().SetTitleOffset(1.2)
        sumHistoData.GetXaxis().SetLabelSize(0.04)
        print( 'sumHistoData title: ', sumHistoData.GetXaxis().GetTitle() )
        sumHistoData.GetYaxis().SetNdivisions(6)
        sumHistoData.GetYaxis().SetTitleSize(0.03)
        sumHistoData.Draw("E1X0")
        assymErrorPlotRatio = getErrorPlot(sumHist,systsUp,systsDown,True)

        assymErrorPlotRatio.SetFillStyle(3013)
        assymErrorPlotRatio.SetFillColor(14) 
        assymErrorPlotRatio.Draw("e2 same")

    leggy.Draw()
    latex.SetTextSize(0.04)
    latex.SetTextFont(cmsTextFont)
    latex.DrawLatex(0.23, 0.95, cmsText )
    
    latex.SetTextFont(extraTextFont)
    latex.SetTextSize(0.04*0.76)
    latex.DrawLatex(0.35, 0.95 , extraText )
    
    latex2.DrawLatex(0.95, 0.95, '35.9 fb^{-1}(13TeV) ' );

    canvy.SaveAs(outDir+"{}_{}_{}.png".format(region,name, savePost))
    # canvy.SaveAs(outDir+"/{2}{0}{1}.root".format(region,savePost,name))
    print( 'done plotting data/mc plot for {}\n'.format(name))
    print('\n')



def getErrorPlot(totalMC,systUp,systDown,isRatio = False):
    # for the data/mc ratio or the error bar in the stack for MC
    x = array('d',[])
    y = array('d',[])
    exl = array('d',[])
    exh = array('d',[])
    eyl = array('d',[])
    eyh = array('d',[])
    xAxis = systUp.GetXaxis()
    for i in range(1,xAxis.GetNbins()+1):
        x.append(xAxis.GetBinCenter(i)) # x is the x value
        if not isRatio: y.append(totalMC.GetBinContent(i))
        else: y.append(1.)
        exl.append(xAxis.GetBinCenter(i) - xAxis.GetBinLowEdge(i))
        exh.append(xAxis.GetBinLowEdge(i)+xAxis.GetBinWidth(i)-xAxis.GetBinCenter(i))
        if not isRatio:
            eyl.append(systDown.GetBinContent(i))
            eyh.append(systUp.GetBinContent(i))
        else:
            if not totalMC.GetBinContent(i)==0 :
                eyl.append(systDown.GetBinContent(i)/totalMC.GetBinContent(i))
                eyh.append(systUp.GetBinContent(i)/totalMC.GetBinContent(i))
            #???can you simply divide error like this? i think it's wrong
            else: 
                #???set to 0 by me
                eyl.append(0)
                eyh.append(0)
    # print(x)
    # print(y)
    # print(exl)
    # print(exh)
    # print(eyl)
    # print(eyh)
    errors = TGraphAsymmErrors(xAxis.GetNbins(),x,y,exl,exh,eyl,eyh)
    return errors


def getSystVariation(nominalHist,systHists,sampleName,region):
    # to calculate the total sysHistUp and down
    #here the input nominalHist and systHists are for one summed process
    # systHists include 'up' and 'down' for varias sources, but it's just for one process
    #???the calculation seems wrong
    systHistUp = nominalHist.Clone("up")
    systHistDown = nominalHist.Clone("down")
    systHistUp.Reset()
    systHistDown.Reset()
    
    for systHi in systHists.keys():
    #systHi is 'up' or 'down' for varias sources
    #so this is to sum the sytstmatic variation for sources of systematic uncertainty
        print( systHi )
        if "bTag" in systHi: continue
        syst = systHists[systHi].Clone()
        syst.Add(nominalHist,-1)
        syst.Divide(nominalHist)
        for i in range(1,syst.GetXaxis().GetNbins()+1):
            # print( "{0}: {1:.1f} ({2:.1f} - {3:.1f})".format(i, 100*syst.GetBinContent(i),systHists[systHi].GetBinContent(i),nominalHist.GetBinContent(i)) )
            if "up" in syst.GetName():
                # print( 'sytHistUp: ', systHistUp.GetBinContent() )
                systHistUp.SetBinContent(i,systHistUp.GetBinContent(i)+(syst.GetBinContent(i) * syst.GetBinContent(i)))
            else:
                systHistDown.SetBinContent(i,systHistDown.GetBinContent(i)+(syst.GetBinContent(i) * syst.GetBinContent(i)))
    for i in range(1,systHistUp.GetXaxis().GetNbins()+1):
        systHistUp.SetBinContent(i,(math.sqrt(systHistUp.GetBinContent(i)))*nominalHist.GetBinContent(i))
        systHistDown.SetBinContent(i,(math.sqrt(systHistDown.GetBinContent(i)))*nominalHist.GetBinContent(i))

    return systHistUp,systHistDown


def getSystVariation_my(nominalHist,systHists):
    # to calculate the total sysHistUp and down
    #here the input nominalHist and systHists are for one summed process
    # systHists include 'up' and 'down' for varias sources, but it's just for one process
    #???the calculation seems wrong
    systHistUp = nominalHist.Clone("up")
    systHistDown = nominalHist.Clone("down")
    systHistUp.Reset()
    systHistDown.Reset()

    for systHi in systHists.keys():
    #systHi is 'up' or 'down' for varias sources
    #so this is to sum the systematic variation for sources of systematic uncertainty
        print( systHi )
        if "bTag" in systHi: continue
        syst = systHists[systHi].Clone()
        syst.Add(nominalHist,-1)
        syst.Divide(nominalHist)
        for i in range(1,syst.GetXaxis().GetNbins()+1):
            if "up" in syst.GetName():
                # print( 'sytHistUp: ', systHistUp.GetBinContent() )
                systHistUp.SetBinContent(i,systHistUp.GetBinContent(i)+(syst.GetBinContent(i) * syst.GetBinContent(i)))
            else:
                systHistDown.SetBinContent(i,systHistDown.GetBinContent(i)+(syst.GetBinContent(i) * syst.GetBinContent(i)))
    for i in range(1,systHistUp.GetXaxis().GetNbins()+1):
        systHistUp.SetBinContent(i,(math.sqrt(systHistUp.GetBinContent(i)))*nominalHist.GetBinContent(i))
        systHistDown.SetBinContent(i,(math.sqrt(systHistDown.GetBinContent(i)))*nominalHist.GetBinContent(i))
    return systHistUp,systHistDown


def addStatisticUncer(sumHist, systsUp, systsDown ):
    for i in range(1,sumHist.GetXaxis().GetNbins()+1):
        systsUp.SetBinContent(i, math.sqrt( systsUp.GetBinContent(i)*systsUp.GetBinContent(i) + sumHist.GetBinError(i)*sumHist.GetBinError(i) ) )
        systsDown.SetBinContent(i, math.sqrt( systsDown.GetBinContent(i)*systsDown.GetBinContent(i) + sumHist.GetBinError(i)*sumHist.GetBinError(i) ) )
    return systsUp,systsDown



if __name__ == "__main__":
    main()
