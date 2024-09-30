import os
import subprocess

import ttttGlobleQuantity as gq
import usefulFunc as uf


codePath = os.path.dirname(os.path.abspath(__file__)) + '/'
# jobVersionName = 'v72PreSelWithTauF_METAdd'
# jobVersionName = 'v73NoHLTNoTauHT400/'
# jobVersionName = 'v73NoHLTTauFHT400/'
# jobVersionName = 'v74AddMETPhi/'
# jobVersionName = 'v75AddTauTTTT/'
# jobVersionName = 'v75AddTauTTTTNoHTCut/'
# jobVersionName = 'v75OverlapRemovalFTau/'
# jobVersionName = 'v76For1tau2l/'
# jobVersionName = 'v77ForHLT/'
# jobVersionName = 'v76WithVLLSample/'
# jobVersionName = 'v76WithVLLAllMass/'
# jobVersionName = 'v77forBtagMeasurement/'
# jobVersionName = 'v77HadroPresel/'
# jobVersionName = 'v78HadroPresel/'
# jobVersionName = 'v79HadroPresel/'
# jobVersionName = 'v79forHLT/'
# jobVersionName = 'v80addTauJetVar/'
# jobVersionName = 'v80addTTExtra/'
# jobVersionName = 'v80addTTExtra1/'
# jobVersionName = 'v81addSysSum/'
# jobVersionName = 'v81for1tau2l/'
# jobVersionName = 'v82for1tau2l/'
# jobVersionName = 'v83for1tau2lEleEtaCut/'
# jobVersionName = 'v84fakeLeptonUpdate/'
# jobVersionName = 'v84fakeLeptonUpdateV2/'
# jobVersionName = 'v84Pre1tau2lNoLepCut/'
jobVersionName = 'v84Pre1tau2lLepF2/'

#!same version numbers means no change in algrithm but only in selection

def main():
    # era = '2016'
    # era = '2016APV'
    # era = '2017'
    era = '2018'
    # era = '2022_13p6/crabNanoPost_2022postEE_v3'
    # era = '2022_13p6/crabNanoPost_2022preEE_v3'
    # onlyMC = True
    # dataList = ['jetHT', 'BTagCSV']#!for 1tau1l and 1tau0l
    # dataList = ['singleMu'] #!for HLT
    # dataList = ['JetMET', 'JetHT']
    # dataList = [ 'Muon']
    # dataList = ['doubleMu', 'muonEG', 'eGamma', 'singleMu'] #!for 1tau2l  
    
    # sumProToSkip = ['jetHT', 'ttExtra'] #! and 1tau2l
    sumProToSkip = ['jetHT'] #! need ttExtra for BDT training




###########################################
#better not modify anything afer this
    inputDir, outputDir, eraOut = getInputOutDir(jobVersionName, era)

    jobsDir = codePath + 'jobs_eachYear/'
    uf.checkMakeDir(jobsDir)
    isRun3 = uf.isRun3(inputDir)
    print( "era: ", era, 'isRun3=', isRun3 )
    print('version: ', jobVersionName)
    
    
    jobScriptsFolder = jobsDir+eraOut+'/'
    if os.path.exists( jobScriptsFolder ):
        subprocess.run('rm -fr '+ jobScriptsFolder , shell=True)
        print('removing old job folder', jobScriptsFolder)
    uf.checkMakeDir(jobScriptsFolder)

    inputDirMC = inputDir + 'mc/'
    makeJobsInDir( inputDirMC, outputDir , jobScriptsFolder, False,   eraOut, isRun3,  sumProToSkip)
    # if not onlyMC:
        # for idata in dataList:
    inputDirData = inputDir + 'data/'
    makeJobsInDir( inputDirData, outputDir, jobScriptsFolder, True, eraOut , isRun3, sumProToSkip)

    makeSubAllJobs( jobsDir , eraOut)
    subprocess.run('chmod 777 '+jobScriptsFolder + "*sh", shell=True )

    


def getInputOutDir( jobVersionName, era):
    eraDic = {
        '2016':'UL2016_postVFP',
        '2016APV': 'UL2016_preVFP',
        '2017': 'UL2017',
        '2018': 'UL2018',
        '13p6TeV/2022':'Prompt2022',
        '2022_13p6/NanoPost/2022preEE': 'ReReco2022PreEE',
        '2022_13p6/crabNanoPost_2022PostEE/2022postEE': 'Prompt2022postEE',
        '2022_13p6/crabNanoPost_2022postEE_v3': '2022postEE',
        '2022_13p6/crabNanoPost_2022preEE_v3': '2022preEE',
    }
    inputBase = '/publicfs/cms/data/TopQuark/nanoAOD/'
    outputBase = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/'
    inputDir = inputBase + era +'/'
    outputDir = outputBase + eraDic[era] + '/' +jobVersionName  
    uf.checkMakeDir( outputDir) 
    return inputDir, outputDir, eraDic[era]
    




def makeSubAllJobs( jobsDir , era):
    subAllFile = jobsDir+"subAllJobs"+era+ ".sh"
    if os.path.exists(subAllFile):
        subprocess.run('rm -fr '+subAllFile , shell=True)

    subAllProcessName = open( subAllFile, 'w')
    subAllProcessName.write( "#!/bin/bash\n")
    subAllProcessName.write( 'cd ' + jobsDir+era + '\n')
    for ijob in os.listdir( jobsDir+era ):
        if '.sh' in ijob:
            subAllProcessName.write( "sh  " + ijob + "\n")
    subAllProcessName.close()
    print( 'submitting all jobs using: ', subAllFile )
    subprocess.run( 'chmod 777 ' + subAllFile,  shell=True )









# def makeJobsInDir( inputDir, outputDir, jobScriptsFolder, isData, dataSet, era, isRun3, ifSkipTTExtra=True):
def makeJobsInDir( inputDir, outputDir, jobScriptsFolder, isData, era, isRun3,  sumProToSkip=[]):
    allProcesses = os.listdir( inputDir )
    if isData:
        outputDir = outputDir + 'data/'
    else:
        outputDir = outputDir + 'mc/'
    uf.checkMakeDir( outputDir )

    for k in allProcesses:
        print( 'kProcess: ', k )
        if not uf.checkIfInputDic(k, isRun3): continue
        print('input=', inputDir+k)
        
        print(k)
        sample_k = k
        # if  isData:
        #     if dataSet not in k:
        #         print( "omitting: ", k )
        #         continue
        # if ifSkipTTExtra and gq.histoGramPerSample.get(k)=='ttExtra': continue
        
        if gq.histoGramPerSample.get(k) in sumProToSkip:
            print(gq.histoGramPerSample.get(k), ' is in sumProToSkip, skipping')
            continue

        print( 'have made folder neccessary for out put directory' )

        oneProcess =  jobScriptsFolder +  sample_k + ".sh"
        kProcessDir = jobScriptsFolder + sample_k + '/'
        if os.path.exists( kProcessDir ):
            subprocess.run('rm -fr '+ kProcessDir , shell=True)
        subprocess.run('mkdir -p '+ kProcessDir, shell=True )
        if os.path.exists(oneProcess):
            subprocess.run('rm -fr '+ oneProcess,  shell=True )
        sub_oneProcess = open ( oneProcess, 'w')
        sub_oneProcess.write( "cd "+ jobScriptsFolder + sample_k + "/" + "\n" + "\n")
        print( 'job sub script for kProcess is: ', oneProcess )

        sampleDir = inputDir + sample_k +'/'
        koutputDir = outputDir + k + '/'
        kOutDirLog = koutputDir + 'log/'
        uf.checkMakeDir( koutputDir )
        uf.checkMakeDir( kOutDirLog )
        print( 'outputDir for kprocess: ', koutputDir )
        for entry in os.listdir( sampleDir):
            if not '.root' in entry: continue
            if os.path.isfile(os.path.join(sampleDir, entry)):
                smallFile = entry.replace( ".root", "")
                iSmallJobName = 'OS_'+ era + sample_k + '_' + smallFile + ".sh"
                smallFilejob = jobScriptsFolder +sample_k + "/" + iSmallJobName   
                prepareCshJob( sampleDir, koutputDir, smallFilejob, entry)
                
                logFile = kOutDirLog + smallFile + ".log"
                errFile = kOutDirLog + smallFile + ".err"
                # sub_oneProcess.write( "hep_sub -os CentOS7 " + iSmallJobName + " -o " + logFile + " -e " + errFile + "\n")
                sub_oneProcess.write( "hep_sub -os CentOS7 -mem 8000 " + iSmallJobName + " -o " + logFile + " -e " + errFile + "\n")#!Memory comsuption is too high, need to be understood

        os.popen('chmod 777 '+ jobScriptsFolder + sample_k + "/*sh")
        sub_oneProcess.close()
        print( 'done with kProcess: ', k )
        print( '\n')




# def prepareCshJob( inputDir, koutputDir, shFile, singleFile, eventSelection):
def prepareCshJob( inputDir, koutputDir, shFile, singleFile):
    subFile = open( shFile, 'w')
    subFile.write( "#!/bin/bash\n" )
    appDir = codePath.rsplit('/', 2)[0]
    # subFile.write( "cd "+codePath + "\n")
    subFile.write( "cd "+appDir + "\n")
    subFile.write('./apps/run_objectSelection.out ' + inputDir +' ' + singleFile +' '+ koutputDir  + ' 0' )
    subFile.close()
    # print( 'done writing the iJob for kProcess: ', shFile )



if __name__ == "__main__":
    main()





