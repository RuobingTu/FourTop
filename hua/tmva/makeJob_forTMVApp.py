import os
import subprocess

import usefulFunc as uf


def main():
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v5baselineExtraTauLepCut_v41addVertexSelection/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v5baselineExtraTauLepCut_v42fixedChargeType/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v5baselineExtraTauLepCut_v42fixedChargeType/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v6Cut1tau1lVariableFixed_v42fixedChargeType/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v1cut1tau1l_v51TESNewLepFoLepForrObjectRemoval/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/Run2/v1cut1tau1l_v51TESNewLepObjectRemovalCorrected/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baseline_v51TESNewLepObjectRemovalCorrected/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baseline_v51TESNewLepObjectRemovalCorrected/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v0baseline_v51TESNewLepObjectRemovalCorrected/'
    inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v6baseline_v56preselection/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v6baseline_v56NoHLTButPre/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v4baselineBtagRUpdated_v57ovelapWithTausF/'

    version = 'v0BDT_SR30Bins'
    # version = 'v0_BDTWithSystematics'
    region = '1tau1lCR0'
    
    # variableListCsv = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2018/v6Cut1tau1lVariableFixed_v42fixedChargeType/1tau1l_v0/variableList/varibleList_19.csv'
    # weightDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2018/v6Cut1tau1lVariableFixed_v42fixedChargeType/1tau1l_v0/dataset/1tau1lvaribleList_19_weight/'
    # variableListCsv = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/Run2/v8Cut1tau1l_v42fixedChargeType/1tau1l_v0/variableList/varibleList_12.csv"
    # weightDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/Run2/v8Cut1tau1l_v42fixedChargeType/1tau1l_v0/dataset/1tau1lvaribleList_12_weight/"
    # variableListCsv = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/Run2/v1cut1tau1l_v51TESNewLepObjectRemovalCorrected/1tau1l_v0/variableList/varibleList_17.csv"
    # weightDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/Run2/v1cut1tau1l_v51TESNewLepObjectRemovalCorrected/1tau1l_v0/dataset/1tau1lvaribleList_17_weight/"
    variableListCsv = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v5extra1tau1lCut_v56NoHLTButPre/1tau1l_v0/variableList/varibleList_16.csv'
    weightDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v5extra1tau1lCut_v56NoHLTButPre/1tau1l_v0/dataset/1tau1lvaribleList_16_weight/'
    # variableListCsv = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v5extra1tau1lCut_v56preselection/1tau1l_v0/variableList/varibleList_16.csv'
    # weightDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v5extra1tau1lCut_v56preselection/1tau1l_v0/dataset/1tau1lvaribleList_16_weight/'
    
    
    print( inputDir, ' ', version )
   
    era = uf.getEraFromDir(inputDir) 
    makeSubAllJob(inputDir, version, variableListCsv, weightDir,  era, region )
    
def makeSubAllJob(inputDir, version, variableListCsv, weightDir, era, allJobName='subTMVApp.sh', region = '1tau1lCR0'):
    #???move this to usefulFunc
    Jobsubmitpath = os.path.dirname( os.path.abspath(__file__) ) +'/'
    subAllProcess = open( Jobsubmitpath+'subAllProcess.sh', 'w') 
    #important to add the full path so that it can be ran in any folder
    subAllProcess.write('#!/bin/bash\n')
    subAllProcess.write('cd '+ Jobsubmitpath +'\n')
    
    inputDirDic={}
    inputDirDic['mc'] = inputDir + 'mc/'
    inputDirDic['data'] = inputDir + 'data/'
    
    for i in inputDirDic.keys():
        makeJobsforDir( inputDirDic[i], version, subAllProcess, Jobsubmitpath, variableListCsv, weightDir, era , region)
    subAllProcess.close()

    uf.sumbitJobs(  Jobsubmitpath+'subAllProcess.sh')


def makeJobsforDir( inputDir, version,  subAllProcess, Jobsubmitpath, variableListCsv, weightDir, era, region ):

    # jobDir = 'jobSH/'
    jobDir = Jobsubmitpath +'jobSH/'
    outputDir = inputDir + 'variableHists_' + version +'/'
    uf.checkMakeDir(jobDir)
    uf.checkMakeDir(outputDir)

    if not os.path.exists(outputDir +"/log/" ):
        os.mkdir( outputDir  +"/log/")
    for iFile in os.listdir( inputDir ):
        if '.root' in iFile:
            iProcess = iFile.split('.root')[0]
            print(iProcess)
            iJobFile = jobDir + iProcess +'.sh' 
            makeIjob( iJobFile, iProcess, inputDir, version, Jobsubmitpath , outputDir, variableListCsv, weightDir, era, region)  

            logFile = outputDir +   "log/" + iProcess + ".log"
            errFile = outputDir +  "log/" + iProcess +".err"
            subAllProcess.write('hep_sub '+ iJobFile + ' -o ' + logFile + ' -e ' + errFile +'\n' )

    subprocess.run('chmod 777 ' + jobDir +'*sh',  shell=True)
    # subprocess.run('chmod 777 ' + Jobsubmitpath+ 'subAllProcess.sh', shell=True)
    subprocess.run('chmod 777 ' + subAllProcess.name, shell=True)
     


def makeIjob( shFile, iProcess,  inputDir, version, Jobsubmitpath , outDir, variableListCsv, weightDir, era, channel ):
    # channel = '1tau1lCR0'
    # channel = '1tau1lSR'
    subFile = open( shFile, "w" )
    subFile.write('#!/bin/bash\n')
    subFile.write('cd '+ Jobsubmitpath + '\n' )
    subFile.write( 'root -q -b \'TMVAClassificationApplication_perSample.C( \"{}\", \"{}\", \"{}\", \"{}\", {} , \"{}\", \"{}\", \"{}\", \"{}\" )\' '.format( inputDir, iProcess, version, channel, 10, variableListCsv, weightDir, outDir, era  ) )
    print( 'done writing: ', shFile)


if __name__=='__main__':
    main()
