import csv
import os

import ROOT
import ttttGlobleQuantity as gq
import usefulFunc as uf


def main():
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v0LepLAdded_v46addPOGIDL/mc/variableHists_v2FR_vetoPOGMuLEleV/'
    inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v0LepLAdded_v46addPOGIDL/mc/variableHists_v2FR_vetoPOGlepL/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v0LepLAdded_v45newLepBugFixed/mc/variableHists_v1FR_vetoNewLepL_repeat/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v0LepLAdded_v45newLepBugFixed/mc/variableHists_v0FR_newLep/'

    # inputDirDic = uf.getDirDic(inputDir) 
    # era = uf.getEraFromDir(inputDir)
    # checkJobStatus(inputDirDic)
    
    #check object selection jobs 
    # obDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD//UL2016_preVFP/v46addPOGIDL/'
    # obDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD//UL2016_preVFP/v45newLepBugFixed/'
    # checkOSJobs(obDir, '2016preVFP')
    # obDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD//UL2016_postVFP/v46addPOGIDL/'
    # obDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_postVFP/v45newLepBugFixed/'
    obDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_postVFP/v49FixedPileUpJERAndTES/'
    checkOSJobs(obDir, '2016postVFP')
    
    # mvDir = inputDir[:inputDir.find('variableHist')]
    # mvDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/v0LepLAdded_v46addPOGIDL/'
    # mvDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0LepLAdded_v46addPOGIDL/'
    # mvDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/v0LepLAdded_v45newLepBugFixed/'
    # mvDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0LepLAdded_v45newLepBugFixed/'
    # checkMVJobs(mvDir)
    
    
    
    
    
    
    
def checkOSJobs(obDir, era='2016preVFP'):
    nanoDirDic = {
        '2016postVFP': '/publicfs/cms/data/TopQuark/nanoAOD/2016/',
        '2016preVFP': '/publicfs/cms/data/TopQuark/nanoAOD/2016APV/',
        '2017': '/publicfs/cms/data/TopQuark/nanoAOD/2017/',
        '2018': '/publicfs/cms/data/TopQuark/nanoAOD/2018/',
    }
    nanoDir = nanoDirDic[era]
    print('inputNano dir: ', nanoDir)
    fileDic = getProcessFileDic(nanoDir, era)
    print(fileDic)
    print('\n')
    
    OSfileDic = getProcessFileDic(obDir, era, True)
    print(OSfileDic)
    print('\n')
    
    if not fileDic==OSfileDic:
        print('os file not the same with nanofile')
    else:
        print('os file the same with nanofile')

    checkLogOB(obDir)
    
def checkLogOB(obDir):
    print('start to check log dir')
    obDirDic={}
    obDirDic['mc']=obDir+'mc/'
    obDirDic['data']=obDir+'data/'
    for ikey in obDirDic.keys():
        for isub in os.listdir(obDirDic[ikey]):
            checkLogDir(obDirDic[ikey]+isub+'/log/')
                
         
    
    
def getProcessFileDic(nanoDir, era, isOB=False):
    fileDir = {}
    fileDir['mc']={}
    fileDir['data']={}
    subProList = getAllSub(era)
    print('all subProcess considered: \n', subProList)
    mcDir = nanoDir+'mc/'
    for ipro in subProList:
        if 'jetHT' in ipro:
            fileDir['data'][ipro] = []
            fileDir['data'][ipro] = getCheckNanoFile(nanoDir+'data/'+ipro+ '/', isOB)
        else:
            fileDir['mc'][ipro] = []
            fileDir['mc'][ipro] = getCheckNanoFile(mcDir+ipro+ '/', isOB)
    # print( fileDir)
    return fileDir
        
def getCheckNanoFile(dir, isOB=False, ifCheckNano=False):
    fileList = []
    for ifile in os.listdir(dir):
        if not '.root' in ifile: continue
        fileList.append(ifile)
        if ifCheckNano:
            rootF = ROOT.TFile(dir+ifile, 'READ')
            if rootF.IsZombie():
                print('BAD!!! file corrupt!!! ', ifile )
            rootF.Close()
    sorted(fileList)
    return fileList        
    
    
    
def checkMVJobs(mvDir):
    mvDic = expandDirDic(mvDir)
    for idir in mvDic.keys():
        logDir = mvDic[idir] + 'log/'
        checkLogDir(logDir)
       
def expandDirDic( dir):
    dirDic={}
    dirDic['mc'] = dir+'mc/'
    dirDic['data'] = dir+'data/'
    return dirDic

        
def getAllSub(era):
    #era can be 2016 or '2016preVPF'
    dic={
        '2016postVFP': ['jetHT_2016F',  'jetHT_2016G', 'jetHT_2016H'],
        '2016preVFP': ['jetHT_2016B_v1', 'jetHT_2016B_v2','jetHT_2016C', 'jetHT_2016D', 'jetHT_2016E', 'jetHT_2016F_hipm'],
    }
    allSubPros = list(gq.histoGramPerSample.keys())[:] #copy
    allSubProsNew = []
    for isub in allSubPros:
        if era=='2016preVFP' or era=='2016postVFP':
            if 'jetHT' in isub and not ( isub in dic[era] ): continue
        else: 
            if 'jetHT' in isub and (not era in isub): continue
        allSubProsNew.append(isub)    
        # print('remove data: ', isub)
    return allSubProsNew
        

def checkJobStatus(inputDirDic):
    #check if any input file missing
    inputList = os.listdir(inputDirDic['mc']  ) + os.listdir(inputDirDic['data']) 
    for i, ipro in enumerate(inputList):
        inputList[i] = ipro.replace('.root', '')
    inputList.remove('log') 
    inputList.remove('log') 
    inputList.remove('results')
    inputList = sorted(inputList)
   
    era = uf.getEraFromDir(inputDirDic['mc']) 
    allSubProsNew = getAllSub(era) 
    allSubProsNew = sorted(allSubProsNew)
   
    print('subProcess from inputDir:\n', inputList)
    print('\n')
    print('all subProcess removing non year data :\n', allSubProsNew) 
    print('\n')
    
    missingPro = list(filter(lambda x: x not in inputList, allSubProsNew))
    print( 'in allSub not in dir:\n' , missingPro)  
    print( 'in allSub not in dir:\n' ,list(filter(lambda x: x not in allSubProsNew, inputList))  )
    if len(missingPro) >0 :
        # raise ValueError('missing some sub processes: ', missingPro)
        print('WARNING!!! sub process file not exist!!!\n')
    
    
    checkLogDir( inputDirDic['mc'] +'/log/')    
    checkLogDir( inputDirDic['data'] +'/log/')    
            
def checkLogDir(logDir):            
    print('checking log dir: ', logDir)
    for ifile in os.listdir(logDir):
        if not 'err' in ifile: continue
        if not checkWordInFile( logDir + ifile ):
            print('job not successful: ', ifile)
            
                    
def checkWordInFile( file, word='Terminate' ):
    inFile = False
    # print('file read: ', file)
    with open(file, 'r') as file:
        reader = csv.reader(file )
        for row in reader:
            # print(row)
            if len(row) <1: continue
            if word in row[0]:
                   inFile = True
    # print(inFile)
    return inFile


if __name__=='__main__':
    main()
    