import os
import subprocess

import usefulFunc as uf

# from pathlib import Path


# import sys


#???make all job subscrison more modulized



def main():
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/v1baseline_v29LorentzProblemSolvedNoJERnoTES/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0noBaseline_v30TESnoJER/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0noBaseline_v31TESandJER/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v1baseline_v33TESnoJERCodeOptimzation/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v1baseline_v36TESandJERByHuiling/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v1baseline_v36TESandJERByHuiling/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v1baseline_v37TauPt30AndPreselection/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1baseline_v36TESandJERByHuiling/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v1baseline_v38TESandJERTauPt20_preselection/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v2baselineAddingTauProng_v38TESandJERTauPt20_preselection/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v0addMoreVariables_v39addTauBranches/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v1fixedTauVariables_v39addTauBranches/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v1fixedTauVariables_v40addTauJetEtau/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v1fixedTauVariables_v40addTauJetEtau/'
    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2017/v1fixedTauVariables_v40addTauJetEtau/'
    inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3extra1tau1lCut_v41addVertexSelection/'

    # inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/v0noBaseline_v29LorentzProblemSolvedNoJERnoTES/'

    # version = "v0forCutFlow"
    # version = "v1variablesUsingMyclass"
    # version = 'v2addingPileupWeight'
    # version = 'v4forFakeRate'
    # version = 'v5forFakeRateEtaDivided'
    # version = 'v0forFakeRate'
    # version = 'v1forFRSwitchToTauJetPt'
    # version = 'v1forFRSwitchToTauJetPt_1prong'
    # version = 'v1forFRSwitchToTauJetPt_3prong'
    # version = 'v2forFRVariables'
    # version = 'v2forFRVariables_finerPtBin'
    # version = 'v0forFakeRate'
    # version = 'v0forFakeRateRepeat'
    # version = 'v1forFREtaRegionCorrected'
    # version = 'v1forFREtaRegionCorrected_1prong'
    # version = 'v1forFREtaRegionCorrected_3prong'
    # version = 'v2forFRforVariables'
    # version = 'v3forFRaddFRWeightUpDownRegions'
    # version = 'v4forFRAddHistTitle'
    # version = 'v5forFRMCMasure'
    # version = 'v6forFRCR12'
    # version = 'v6forFRCR12_3prong'
    # version = 'v7addFRWeightReForEventCount'
    version = 'v0for1tau1lCRs'
    justMC = False
    # justMC = True
    isTest = 0
    print( inputDir, ' ', version )





    # Jobsubmitpath = '/workfs2/cms/huahuil/4topCode/CMSSW_12_2_4/src/FourTop/hua/writeVariableHist/' 
    Jobsubmitpath = os.path.abspath(__file__+'/..')
    subAllProcess = open( Jobsubmitpath+'subAllProcess.sh', 'w') 
    #important to add the full path so that it can be ran in any folder
    subAllProcess.write('#!/bin/bash\n')
    subAllProcess.write('cd '+ Jobsubmitpath +'\n')
    inputDirDic={}
    inputDirDic['mc'] = inputDir + 'mc/'
    if not justMC:
        inputDirDic['data'] = inputDir + 'data/'

    for i in inputDirDic.keys():
        makeJobsforDir( inputDirDic[i], version, isTest, subAllProcess, Jobsubmitpath )
    subAllProcess.close()

    # subDir = str(Path(__file__).absolute()).strip()
    # subDir = subDir[0:subDir.rindex('/')]
    uf.sumbitJobs(  Jobsubmitpath+'subAllProcess.sh')



def makeJobsforDir( inputDir, version, isTest, subAllProcess, Jobsubmitpath ):

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
            makeIjob( iJobFile, iProcess, isTest, inputDir, version, Jobsubmitpath )  

            logFile = outputDir +   "log/" + iProcess + ".log"
            errFile = outputDir +  "log/" + iProcess +".err"
            subAllProcess.write('hep_sub '+ iJobFile + ' -o ' + logFile + ' -e ' + errFile +'\n' )

    subprocess.run('chmod 777 ' + jobDir +'*sh',  shell=True)
    subprocess.run('chmod 777 ' + Jobsubmitpath+ 'subAllProcess.sh', shell=True)





def makeIjob( shFile, iProcess, isTest, inputDir, version, Jobsubmitpath ):
    subFile = open( shFile, "w" )
    subFile.write('#!/bin/bash\n')
    subFile.write('cd '+ Jobsubmitpath + '\n' )
    subFile.write( 'root -q -b \'run_writeHist.C( \"{}\", \"{}\", \"{}\", {} )\' '.format( inputDir, iProcess, version, isTest ) )
    print( 'done writing: ', shFile)


if __name__=='__main__':
    main()
