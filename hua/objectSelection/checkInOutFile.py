

import os
import sys

import pandas as pd
import ROOT
import usefulFunc as uf
from ttttGlobleQuantity import (histoGramPerSample, lumiMap, samples,
                                samplesCrossSection, summedProcessList)

sys.path.insert(0,'/workfs2/cms/huahuil/4topCode/CMSSW_12_2_4/src/FourTop/hua/')
from writeCSVforEY import getSummedHists, writeHistsToCSV

from makeJob_objectTSelectorForNanoAOD import (era, eraDic, inputBase,
                                               jobVersionName, outputBase)


def main():
    inOutListMC = [ inputBase + era +'/' + 'mc/', outputBase + eraDic[era] + '/' +jobVersionName  + 'mc/' ]
    inOutListData = [ inputBase + era +'/' + 'data/',outputBase + eraDic[era] + '/' +jobVersionName  + 'data/' ]
    # iera = '2016postVFP'
    iera = '2016preVFP'
    # iera = '2016'

    # checkInOutFileNumber( inOutListMC )
    # checkInOutFileNumber( inOutListData )
    
    # writeGenSumToCSV( inOutListMC[1] )
    # writeGenSumToCSV( inOutListMC[1] , iera)
    fileDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/'+iera+'/objectSelectionResults/' + jobVersionName
    # writGenSum_fromRunTree(fileDir+'mc/', '2016preVFP')

    

    variableList = ['forEventCount']
    regionList = ['OBinitial', 'OBHLT']

    inputDir = {
        # 'mc': '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/objectSelectionResults/' +  jobVersionName+ '/mc/',
        # 'data': '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/objectSelectionResults/' + jobVersionName + '/data/',
        'mc': '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/'+iera+'/objectSelectionResults/' +  jobVersionName+ '/mc/',
        'data': '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/'+iera+'/objectSelectionResults/' + jobVersionName + '/data/',
    }
    # #sumProcessPerVar[var][region][sumedProcess] = hist
    sumProcessPerVar = {}
    for ivar in variableList:
        sumProcessPerVar[ivar] = getSummedHists( inputDir, regionList, ivar, False, iera )
    print( sumProcessPerVar )
    writeHistsToCSV( sumProcessPerVar,  inputDir['mc']+'results/', 'cutFlow_objectSelection.csv')
    writeHistsToCSV( sumProcessPerVar,  inputDir['mc']+'results/', 'cutFlowRawEntries_objectSelection.csv', True)





def writGenSum_fromRunTree( inDir, era='2016preVFP'):
    processList = []
    genWeightDic = {}
    for iPro in os.listdir( inDir ):
        if not '.root' in iPro: continue
        print( iPro) 
        iProcess = iPro.split('.root')[0]
        processList.append( iPro )
        if 'log' in iPro: continue
        iRoot = ROOT.TFile( inDir+iPro, 'READ' )
        iRoot.ls()
        iRunTree = iRoot.Get( 'Runs' )
        genSum = 0.0
        for entry in iRunTree:
        # for ive in range(iRunTree.GetEntries()):
            # iRunTree.GetEntry(ive)
            genSum += entry.genEventSumw
        genWeightDic[iProcess] = genSum
        iRoot.Close()

    df = pd.DataFrame.from_dict( genWeightDic, orient='index' , columns=[era])
    df['process'] = df.index
    print( df )
    # df.to_csv( 'genWeightCSV/' + 'genSum_2016postVFP.csv'  )
    df.to_csv( 'genWeightCSV/genSum_' + era +'.csv' )
    



def writeGenSumToCSV( outDir, era ):
    processList = []
    genWeightDic = {}
    for iPro in os.listdir( outDir ):
        if not '.root' in iPro: continue
        print( iPro) 
        processList.append( iPro )
        sumHist = ROOT.TH1D( 'summedHist' , 'summedHist', 2, -1, 1 )
        for ifile in os.listdir( outDir+iPro ):
            if 'log' in ifile: continue
            # print( ifile )
            iRoot = ROOT.TFile( outDir+iPro+ '/'+ ifile, 'READ' )
            ihist_initial = iRoot.Get( 'h_initial' )
            # ihist_initial.Print()
            sumHist.Add( ihist_initial )
            iRoot.Close()
        genWeightDic[iPro] = sumHist.Integral()
        # sumHist.Print()
        del sumHist

    print( genWeightDic )

    # series = pd.Series( genWeightDic, name='2016postVFP')

    # df = pd.DataFrame.from_dict( genWeightDic, orient='index' , columns=['2016postVFP'])
    df = pd.DataFrame.from_dict( genWeightDic, orient='index' , columns=[era])
    df['process'] = df.index
    print( df )
    # df.to_csv( 'genWeightCSV/' + 'genSum_2016postVFP.csv'  )
    df.to_csv( 'genWeightCSV/genSum_' + era +'.csv' )




def checkInOutFileNumber( inOutList):
    for ipro in os.listdir( inOutList[0]) :
        if not ipro in samples: continue
        print( ipro )
        if not len( os.listdir(inOutList[1]+ipro)) - len( os.listdir(inOutList[1]+ipro)) == 1: 
            print( 'strange!!!!!!!!!!!!!!!!!!!!!! ', ipro, ' :', len( os.listdir(inOutList[0]+ipro)), " ", len( os.listdir(inOutList[1]+ipro) ) )








if __name__=='__main__':
    main()
