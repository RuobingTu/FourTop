import os
import subprocess

import usefulFunc as uf

def main():
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v0baselineHardro_v79HadroPresel/'
    #inputDir = '/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v2cut1tau1lSRTauF_v76addTTExtra1Official/'
    #inputDir = '/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2017/v0baselineHardroSR_v81addSysSum/'
    # inputDir = '/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v2cut1tau1lCR1TauF_v76WithVLLAllMassOfficial/'
    # inputDir = '/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v0baselineHardroSR_v81addSysSum/'
    inputDir = '/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v0baseline1tau1l_v2_v84fakeLeptonUpdateV2/'


    #!fakerate
    # version = 'v0FR_measure1prong'
    # version = 'v0FR_measure3prong'
    # version = 'v1FR_application'
       
    #b-tag measurement 
    # version = 'v1_btagRMeasure'
    # version = 'v0_btagEffMeasure'
    # version = 'v0_btagEffMeasureT'
    
    #HLT 
    # version = 'v0HLTMeasure'
    # version = 'v0HLTMeasureBinB'
    # version = 'v0HLTMeasureBinB'
   
    #dataMC
    # version = 'v0dataMC_allCorrectionButHLT'
    # version = 'v0dataMC_allCorrection'
    # version = 'v0dataMC_basicWeight'
    # version = 'v1dataMC_allCorrectionFakeTau'
    
        
    #1tau1l
    # channel = '1tau1l'
    # version = 'v0Basictraining1tau1l_VLL'
    # version = 'v0Basictraining1tau1l_VLLm800'
    # version = 'v0Basictraining1tau1l_VLLm700'
    # version = 'v0Basictraining1tau1l_VLLm700_DifBin2'
    # version = 'v0BDT1tau1l'
    # version = 'v0BDT1tau1l_binC'
    # version = 'v1BDT1tau1l_evenBin'
    # version = 'v2BDT1tau1l_binD'
    version = 'v2BDT1tau1l_binE'
    # version = 'v0trainingWithBtagShape' #for btagWP or shape
    
    #1tau0l systematic
    channel = '1tau1l'
    # version = 'v0BDT1tau0l'
    # version = 'v0BDT1tau0lBinB'
    # version = 'v1BDTtauFJetVar2017train'
    # version = 'v2BDT25inputs'
    # version = 'v0BasicBDTtraining1tau1l_VLLm600'
    version = 'v0Basictraining1tau1l_VLLm650_4'
    # version = 'VariblesInputPlotting'
    
    # channel = '1tau2l'
    # version = 'v0BDT1tau2l'
   
    # exe = './run_WH_forDataMC.out'
    # exe = './run_treeAnalyzer.out' 
   
    # exe = './run_WH_forDataMC.out'
    # exe = './run_treeAnalyzer.out' 
    
   
    #justMC = False
    justMC = False
    isTest = 0
    print( inputDir, ' ', version )


    Jobsubmitpath = os.path.dirname( os.path.abspath(__file__) ) +'/'
    print('JobsubmitPath: ' ,Jobsubmitpath)
    subAllProcess = open( Jobsubmitpath+'subAllProcess.sh', 'w') 
    #important to add the full path so that it can be ran in any folder
    subAllProcess.write('#!/bin/bash\n')
    inputDirDic={}
    inputDirDic['mc'] = inputDir + 'mc/'
    if not justMC:
        inputDirDic['data'] = inputDir + 'data/'

    for i in inputDirDic.keys():
        makeJobsforDir( inputDirDic[i], version,  isTest, subAllProcess, Jobsubmitpath, channel )
        # makeJobsforDir( inputDirDic[i], version,  isTest, subAllProcess, Jobsubmitpath, exe, channel )
    subAllProcess.close()

    uf.sumbitJobs(  Jobsubmitpath+'subAllProcess.sh')



def makeJobsforDir( inputDir, version, isTest, subAllProcess, Jobsubmitpath , channel):
# def makeJobsforDir( inputDir, version, isTest, subAllProcess, Jobsubmitpath , exe='', channel= '1tau0l'):
# def makeJobsforDir( inputDir, version, isTest, subAllProcess, Jobsubmitpath , exe='', channel= '1tau0l'):
    jobDir = Jobsubmitpath +'jobSH/'
    outputDir = inputDir + 'variableHists_' + version +'/'
    logDir = outputDir+'log/'
    uf.checkMakeDir(jobDir)
    uf.checkMakeDir(outputDir)
    uf.checkMakeDir(logDir)
    
    exeDir = Jobsubmitpath.rsplit('/', 2)[0]+'/apps/'

    for iFile in os.listdir( inputDir ):
        if '.root' in iFile:
            iProcess = iFile.split('.root')[0]
            print(iProcess)
            iJobFile = jobDir + 'WH_'+iProcess +'.sh' 
            #run = './run_WH_forDataMC.out {} {} {} {}'.format(inputDir, iProcess, version, isTest)
            run = './run_treeAnalyzer_650_4.out {} {} {} {} {}'.format(inputDir, iProcess, version, channel, isTest)
            makeIjob( iJobFile,  Jobsubmitpath, run ,exeDir)  

            logFile = logDir + iProcess + ".log"
            errFile = logDir + iProcess +".err"
            #subAllProcess.write('hep_sub '+ iJobFile + ' -o ' + logFile + ' -e ' + errFile +'\n' )
            subAllProcess.write('hep_sub -os CentOS7 '+ iJobFile + ' -o ' + logFile + ' -e ' + errFile +'\n' )
                
    subprocess.run('chmod 777 ' + jobDir +'*sh',  shell=True)
    subprocess.run('chmod 777 ' + Jobsubmitpath+ 'subAllProcess.sh', shell=True)





def makeIjob( shFile, Jobsubmitpath, run, exeDir ):
    subFile = open( shFile, "w" )
    subFile.write('#!/bin/bash\n')
    subFile.write('cd '+ exeDir + '\n' )
    subFile.write(run) 
    print( 'done writing: ', shFile)


if __name__=='__main__':
    main()
