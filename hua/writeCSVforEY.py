# import ROOT
from ROOT import *

import csv
import os

from plotVaribles import  histoGramPerSample, summedProcessList

def main():
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v0baseline_v16_HLTselection/mc/variableHists_v0basicWeight/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0baseline_v17NoSelection/mc/variableHists_v0forCutFlow/'
    # regionList = [ '1tau1lSR', '1tau1lCR0', '1tau1lCR1', '1tau1lCR2', '1tau1lCR3' ]
    regionList = [ 'preChannel' ]
    inputDir = {
        'mc': '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0baseline_v17NoSelection/mc/variableHists_v1forCutFlow/',
        'data': '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0baseline_v17NoSelection/data/variableHists_v1forCutFlow/'
    }
    variableList = [ 'jetsNumber_initial', 'jetsNumber_HLT', 'jetsNumber_baseline' ]

    sumProcessPerVar = {}
    for ivar in variableList:
        sumProcessPerVar[ivar] = getSummedHists( inputDir, regionList, ivar )
    print( sumProcessPerVar )

    # sumProcessHistsDict = getSummedHists( inputDir, regionList, 'jetsNumber_initial' )
    # print( sumProcessHistsDict )

    # writeHistsToCSV( sumProcessHistsDict,  inputDir+'results/', regionList )


def writeHistsToCSV( sumProcessHistDic, outDir , regionList):
    if not os.path.exists(outDir): os.mkdir(outDir)
    csvFile = open( outDir+'1tau1lCR_EY.csv', 'w')
    csvWriter = csv.writer( csvFile, delimiter=',')

    csvField = list(sumProcessHistDic.keys())
    csvField.insert(0, 'process')
    csvWriter.writerow( csvField )

    # for iProcess in sumProcessHistDic[csvField[1]].keys():
    for iProcess in summedProcessList:
        iProcessEYList = []
        for iRegion in regionList:
            print( iProcess, iRegion )
            iProcessEYList.append( '{:.2f}'.format( sumProcessHistDic[iRegion][iProcess].Integral() ) )
        iProcessEYList.insert(0, iProcess)
        print(iProcessEYList)
        csvWriter.writerow( iProcessEYList  )

    print(csvFile)
    csvFile.close()




def getSummedHists( inputDir, regionsList, variable='jetsNumber_forYieldCount' ):
    allSubProcess = histoGramPerSample.keys()
    sumProcessHistsDict = {}
    mcFileList = os.listdir( inputDir['mc'] )
    dataFileList = os.listdir ( inputDir['data'] )

    # for ifile in os.listdir( inputDir ):
    for ifile in mcFileList+dataFileList:
        ifileName = ifile.split('_variableHists')[0]
        print('ifileName: ', ifileName )
        if not ifileName in allSubProcess: continue
        if 'jetHT' in ifileName:
            iRootFile = TFile( inputDir['data']+ifile, 'READ' )
        else:
            iRootFile = TFile( inputDir['mc']+ifile, 'READ' ) 
        print('openning file: ', iRootFile.GetName() )
        # iRootFile.ls()
        for iRegion in regionsList:
            iHistName = iRegion + '_' + ifileName + '_' + variable
            if iRegion not in sumProcessHistsDict.keys(): sumProcessHistsDict[iRegion]={}
            print('iHistName: ', iHistName )
            if histoGramPerSample[ifileName] not in sumProcessHistsDict[iRegion].keys():
                sumProcessHistsDict[iRegion][histoGramPerSample[ifileName]] = iRootFile.Get( iHistName).Clone()
                sumProcessHistsDict[iRegion][histoGramPerSample[ifileName]].SetDirectory(0)
                print('sumProcessHistDic[{}][{}] get hist: {}'.format( iRegion, histoGramPerSample[ifileName], iHistName ))
            else:
                sumProcessHistsDict[iRegion][histoGramPerSample[ifileName]].Add(iRootFile.Get( iHistName))
                print('sumProcessHistDic[{}][{}] add hist: {}'.format( iRegion, histoGramPerSample[ifileName], iHistName ))
        iRootFile.Close()

    return sumProcessHistsDict



if __name__=='__main__':
    main()

