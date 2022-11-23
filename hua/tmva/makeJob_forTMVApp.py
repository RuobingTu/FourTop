import os
import subprocess

import usefulFunc as uf


def main():
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v5baselineExtraTauLepCut_v41addVertexSelection/'
    inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v3extra1tau1lCut_v42fixedChargeType/'

    version = 'v0_BDT1tau1lCRs'
    
    # variableListCsv = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v3extra1tau1lCut_v41addVertexSelection/1tau1l_v0/variableList/varibleList_10.csv"
    # weightDir = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v3extra1tau1lCut_v41addVertexSelection/1tau1l_v0/dataset/1tau1lvaribleList_10_weight/"
    variableListCsv = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v3extra1tau1lCut_v42fixedChargeType/1tau1l_v0/variableList/varibleList_13.csv'
    weightDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v3extra1tau1lCut_v42fixedChargeType/1tau1l_v0/dataset/1tau1lvaribleList_13_weight/'
    
    
    print( inputDir, ' ', version )
    
    makeSubAllJob(inputDir, version, variableListCsv, weightDir)
    
def makeSubAllJob(inputDir, version, variableListCsv, weightDir, allJobName='subTMVApp.sh'):
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
        makeJobsforDir( inputDirDic[i], version, subAllProcess, Jobsubmitpath, variableListCsv, weightDir )
    subAllProcess.close()

    uf.sumbitJobs(  Jobsubmitpath+'subAllProcess.sh')


def makeJobsforDir( inputDir, version,  subAllProcess, Jobsubmitpath, variableListCsv, weightDir ):

    # jobDir = 'jobSH/'
    jobDir = Jobsubmitpath +'jobSH/'
    outputDir = inputDir + 'variableHists_' + version +'/'
    if not os.path.exists( jobDir ):
        os.mkdir( jobDir )
    if not os.path.exists( outputDir ): os.mkdir( outputDir)

    if not os.path.exists(outputDir +"/log/" ):
        os.mkdir( outputDir  +"/log/")
    for iFile in os.listdir( inputDir ):
        if '.root' in iFile:
            iProcess = iFile.split('.root')[0]
            print(iProcess)
            iJobFile = jobDir + iProcess +'.sh' 
            makeIjob( iJobFile, iProcess, inputDir, version, Jobsubmitpath , outputDir, variableListCsv, weightDir)  

            logFile = outputDir +   "log/" + iProcess + ".log"
            errFile = outputDir +  "log/" + iProcess +".err"
            subAllProcess.write('hep_sub '+ iJobFile + ' -o ' + logFile + ' -e ' + errFile +'\n' )

    subprocess.run('chmod 777 ' + jobDir +'*sh',  shell=True)
    # subprocess.run('chmod 777 ' + Jobsubmitpath+ 'subAllProcess.sh', shell=True)
    subprocess.run('chmod 777 ' + subAllProcess.name, shell=True)
     


def makeIjob( shFile, iProcess,  inputDir, version, Jobsubmitpath , outDir, variableListCsv, weightDir ):
    channel = '1tau1lCR0'
    subFile = open( shFile, "w" )
    subFile.write('#!/bin/bash\n')
    subFile.write('cd '+ Jobsubmitpath + '\n' )
    subFile.write( 'root -q -b \'TMVAClassificationApplication_perSample.C( \"{}\", \"{}\", \"{}\", \"{}\", {} , \"{}\", \"{}\", \"{}\", \"{}\" )\' '.format( inputDir, iProcess, version, channel, 10, variableListCsv, weightDir, outDir, '2016'  ) )
    print( 'done writing: ', shFile)


if __name__=='__main__':
    main()
