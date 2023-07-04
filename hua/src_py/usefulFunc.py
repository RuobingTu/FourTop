import os
import subprocess

import pandas as pd
import ROOT
# from ttttGlobleQuantity import (histoGramPerSample, lumiMap, summedProcessList,
                                # samplesCrossSection)
                                
import ttttGlobleQuantity as tg                                


def checkMakeDir( folder ):
    if not os.path.exists( folder ):
        os.mkdir( folder )

def getGenSumDic( inputCsv, era ):
    df = pd.read_csv( inputCsv )
    # genSumDic = pd.Series( df['2016postVFP'].values, index=df['process'] ).to_dict()
    genSumDic = pd.Series( df[era].values, index=df['process'] ).to_dict()
    # print( genSumDic )
    return genSumDic

# def getProcessScale( processName, era ):
#     scale = lumiMap[era]*samplesCrossSection[processName]/getGenSumDic()

def sumbitJobs(  jobsh):
    print('staring to submit jobs')
    command = 'bash {}'.format(  jobsh )
    process = subprocess.run( command, shell=True ) 
    output = process.stdout
    print(output)

    print('jobs submitted')


def getInputDic( inVersion, histVersion, era):
    '''
    for final hists folder structure
    '''
    inputDirBase = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/' + era +'/'
    inputDirDic = {
        'mc': inputDirBase + inVersion + '/mc/' + histVersion + '/',
        'data': inputDirBase + inVersion + '/data/' + histVersion + '/',
    }
    return inputDirDic

def getInputDicNew( inputDirMC ):
    inputDirmc = inputDirMC[:]
    inputDirData = inputDirMC.replace('mc', 'data')
    inputDirDic = {
        'mc': inputDirmc,
        'data': inputDirData,
    }
    return inputDirDic

def getEraFromDir(inputDir):
    era = ''
    if '2016' in inputDir:
        if '2016post' in inputDir or '2016_post' in inputDir:
            era = '2016postVFP'
        elif '2016pre' in inputDir or '2016_post' in inputDir:
            era = '2016preVFP'
        else:
            era = '2016'
    elif '2017' in inputDir:
        era = '2017'
    elif '2018' in inputDir:
        era = '2018'
    elif 'Run2' in inputDir:
        era = 'Run2'
    elif '2022' in inputDir:
        era = '2022'
    return era

def getChannelFromDir( dir ):
    cha = ''
    if '1tau1l' in dir:
        cha = '1tau1l'
    elif '1tau0l' in dir:
        cha = '1tau0l'
    return cha


def getDirDic(inputMC):
    inputDirDic = {
        'mc': inputMC,
        'data': inputMC.replace('mc', 'data')
    }
    return inputDirDic

def getSysList(rootFile, variable):
    histList = []
    sysList = []
    for key in rootFile.GetListOfKeys():
        obj = key.ReadObj()
        histName = obj.GetName()
        if isinstance(obj, ROOT.TH1):
            histList.append(histName)
            if '_up' in histName or '_down' in histName:
                iSys = histName[histName.find(variable)+len(variable)+1:len(histName)]
                sysList.append(iSys)
    # print('all hists in file: ', histList)
    return sysList

def compare2List( list1, list2):
    print('comparing lists now: ')
    for (i, ie) in enumerate(list1):
        list1[i] = list1[i].split('.root')[0]
    diff1 = set(list1) -set(list2)
    diff2 = set(list2) - set(list1)
    print('!!!subprocess missing: ', diff2)
    print('\n')
    print('\n')
    
    

def getSummedHists( inputDir, regionsList, variable='jetsNumber_forYieldCount', ifScale=False, era = '2016postVFP' , ifGetSys=False, isRun3=False):
    if not isRun3:
        histoGramPerSample = tg.histoGramPerSample
    else:
        histoGramPerSample = tg.Run3Samples
    allSubProcess = histoGramPerSample.keys()
    sumProcessHistsDict = {}
    sumProcessHistsDictSys = {}
    mcFileList = os.listdir( inputDir['mc'] )
    dataFileList = os.listdir ( inputDir['data'] )
    #!!!need to be optimized for checking the hists
    compare2List(mcFileList+dataFileList, list(histoGramPerSample.keys()))
    
    for ifile in mcFileList+dataFileList:
        ifileName = ifile.split('.root')[0]
        if ('singleMu' in ifileName) or ('jetHT' in ifileName) or ('JetMET' in ifileName):
            isdata = True
        else:
            isdata = False
        if not ifileName in allSubProcess: continue
        iProScale = 1.0
        # if ifScale and (not 'jetHT' in ifileName):
        if ifScale and (not isdata):
            iProScale = getProcessScale( ifileName, era )
        print('ifileName: {}, scale: {}'.format( ifileName , iProScale) )
        if isdata:
            iRootFile = ROOT.TFile( inputDir['data']+ifile, 'READ' )
        else:
            iRootFile = ROOT.TFile( inputDir['mc']+ifile, 'READ' ) 
        print('openning file: ', iRootFile.GetName() )
        
        if ifGetSys: 
            sysList = getSysList(iRootFile, variable)  
            print('systematic in file: ', sysList)
        else:
            sysList=[]
        
        for iRegion in regionsList:
            # if 'SR' in iRegion and isdata: continue
            if (iRegion=='1tau1lSR' or iRegion=='1tau0lSR') and isdata: continue
            if not isRun3:
                iHistName = iRegion + '_' + ifileName + '_' + variable
            else:
                iHistName = ifileName +'_' +iRegion+ '_' + variable
            
            if iRegion not in sumProcessHistsDict.keys(): 
                sumProcessHistsDict[iRegion]={}
                sumProcessHistsDictSys[iRegion]={}
            print('iHistName: ', iHistName )
            
            if histoGramPerSample[ifileName] not in sumProcessHistsDict[iRegion].keys():
                sumProcessHistsDictSys[iRegion][histoGramPerSample[ifileName]] = {}
                sumProcessHistsDict[iRegion][histoGramPerSample[ifileName]] = iRootFile.Get( iHistName)
                sumProcessHistsDict[iRegion][histoGramPerSample[ifileName]].Sumw2()
                sumProcessHistsDict[iRegion][histoGramPerSample[ifileName]].SetDirectory(0)
                print('sumProcessHistDic[{}][{}] get hist: {}'.format( iRegion, histoGramPerSample[ifileName], iHistName ))
                if ifScale or not isdata: 
                    sumProcessHistsDict[iRegion][histoGramPerSample[ifileName]].Scale(iProScale)
                #get systematic hist
                if ifGetSys:
                    for isys in sysList:
                        sumProcessHistsDictSys[iRegion][histoGramPerSample[ifileName]][isys] = iRootFile.Get( iHistName+'_'+isys)
                        sumProcessHistsDictSys[iRegion][histoGramPerSample[ifileName]][isys].Sumw2()
                        sumProcessHistsDictSys[iRegion][histoGramPerSample[ifileName]][isys].SetDirectory(0)
            else:
                itemp = iRootFile.Get( iHistName)
                if ifScale or not isdata: 
                    itemp.Scale(iProScale)
                sumProcessHistsDict[iRegion][histoGramPerSample[ifileName]].Add( itemp)
                print('sumProcessHistDic[{}][{}] add hist: {}'.format( iRegion, histoGramPerSample[ifileName], iHistName ))
                if ifGetSys:
                    for isys in sysList:
                        sumProcessHistsDictSys[iRegion][histoGramPerSample[ifileName]][isys].Add( iRootFile.Get( iHistName+'_'+ isys))
                        
        iRootFile.Close()
        print( '\n')

    return sumProcessHistsDict, sumProcessHistsDictSys


def getProcessScale( processName, era ):
    # genWeight = uf.getGenSumDic( '../objectSelection/genWeightCSV/genSum_2016postVFP.csv' )[processName]
    genWeight = uf.getGenSumDic( '../objectSelection/genWeightCSV/genSum_'+era+'.csv', era )[processName]
    scale = lumiMap[era]*samplesCrossSection[processName]/genWeight
    print( processName, ': ', 'genWeight= ', genWeight, ' lumi=', lumiMap[era], ' cross=', samplesCrossSection[processName],  ' scale= ', scale)
    return scale


def addBGHist(sumProcessIVar,  region, includeQCD=False):
    # sumHist = sumProcessIVar[region][summedProcessList[0]]
    sumHist = sumProcessIVar[region][summedProcessList[0]].Clone()
    sumHist.Reset()
    sumHist.Sumw2()
    sumHist.SetName(region)
    for ipro in summedProcessList:
        if not includeQCD:
            # if ipro=='data' or ipro=='qcd' or ipro=='tttt': continue
            if ipro=='jetHT' or ipro=='singleMu' or ipro=='qcd' or ipro=='tttt': continue
        else:
            if ipro=='jetHT' or ipro=='singleMu' or ipro=='tttt': continue
        sumHist.Add( sumProcessIVar[region][ipro])
    # sumHist.SetName(region+ '_allBG_' + var)
    return sumHist

# def getPathDir()