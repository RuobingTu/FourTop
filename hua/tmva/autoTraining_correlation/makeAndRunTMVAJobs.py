#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File              : makeAndRunTMVAJobs.py
# Author            : Huiling Hua <huahl@ihep.ac.cn>
# Date              : 03.10.2021
# Last Modified Date: 03.10.2021
# Last Modified By  : Huiling Hua <huahl@ihep.ac.cn>

import os

import generateVariableList as GV
import usefulFunc as uf


def main():
    channel = '1tau1l'
    # channel = '1tau2l'
    version = 0
    # version = 4 
    # outputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v2Add2Variables_fromV9/'
    # outputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v3correctBjetsvariable_fromV9/'
    # outputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v4modifiedMinDeltaR_fromV9/'
    # outputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v1fixedTauVariables_v40addTauJetEtau/'
    # outputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2016/v3extra1tau1lCut_v41addVertexSelection/'
    outputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/TMVAoutput/2017/v3extra1tau1lCut_v41addVertexSelection/'
    # isApp = True
    isApp = False
    appFolderName = 'AppResults'
    # appFolderName = 'AppResults_resubmit'
    # binNum = 11 #for App only
    # binNum = 40#for App only
    # binNum = 20#for App only
    binNum = 30

    
    

    # TMVACodeDir = '/workfs2/cms/huahuil/4topCode/CMSSW_10_2_20_UL/src/FourTop/hua/tmva/'
    TMVACodeDir = os.path.dirname(os.path.abspath(__file__)) +'/'
    vListDir, outputDir = checkMakeDir( channel, outputDir, TMVACodeDir, version, isApp, binNum, appFolderName )
    subAll = makeJobScripts( vListDir, channel, outputDir, TMVACodeDir, isApp, binNum, appFolderName )
    
    #???add features of submitting jobs and reporting job status and check job results
    uf.sumbitJobs( subAll )






def makeJobScripts( vlistDir, channel, outputDir, TMVACodeDir, isApp, binNum, appFolderName ):
    # jobDir = ''
    jobDir = os.path.dirname(os.path.abspath(__file__)) 
    subAllscriptName = ''
    if isApp:
        jobDirSep =  jobDir +'/singleJobs' + '_App/'
        subAllscriptName = jobDir + 'subAlljobs_App.sh'
    else:
        jobDirSep = jobDir +'/singleJobs' + '_Train/'
        subAllscriptName = jobDir + '/subAlljobs_train.sh'
    subAllscript = open( subAllscriptName, 'wt')
    if not os.path.exists( jobDirSep ):
        os.mkdir( jobDirSep )
    
    for entry in os.listdir( vlistDir ):
        entryName = entry[:-4]
        print( entry)
        iJob = jobDirSep +  entryName + ".sh"
        makeSingleTMVAJob( vlistDir, entry, channel, iJob, TMVACodeDir, outputDir, isApp, binNum, appFolderName )

        logFile = outputDir +   "log/" + entryName + ".log"
        errFile = outputDir +  "log/" + entryName +".err"
        subAllscript.write( "hep_sub -mem 4000 "+  iJob  + " -o " + logFile + " -e " + errFile + '\n')
    os.popen('chmod 777 '+jobDirSep + "*sh")
    os.popen('chmod 777 ' + subAllscriptName )
    print( 'sub all jobs using: ', subAllscriptName)
    return subAllscriptName

    
def makeSingleTMVAJob( vlistDir, entry, channel, jobName, TMVACodeDir , outputDir, isApp, binNum, appFolderName ):
    listCsv = vlistDir + entry
    output = open( jobName ,'wt')
    output.write( '#!/bin/bash' + '\n')
    output.write( '/bin/hostname' + '\n')
    output.write( 'cd '+ TMVACodeDir + '\n')
    if isApp:
        vlistName = entry[:-4]
        weightDir = outputDir[:outputDir.find( appFolderName )]
        
        weightDir = weightDir + 'dataset/'+ channel + vlistName + '_weight/'
        print( 'weightDir :', weightDir)
        output.write( 'root -b -l -q '  +'\'' + 'TMVAClassificationApplication_multipleSamples.C(' + '\"\",' + '\"'+outputDir+'\",' + '\"'+listCsv+'\"' +',\"' + weightDir+ "\","+ '\"'+ channel +'\"'  +',' +str(binNum) + ')' + '\''   )
    else:
        output.write( 'root -b -l -q '  +'\'' + 'TMVAClassification_variableFileInput.C(' + '\"\",' + '\"'+outputDir+'\",' + '\"'+listCsv+'\"' +',' + "\""+ channel +"\""+ ', false,  false )' + '\''   )
    output.close()
    print('written ', jobName)

#  def checkJob():







def checkMakeDir( channelName, outputDir, TMVACodeDir, version, isApp, binNum , appFolderName ):
    uf.checkMakeDir( outputDir )
    outputDir = GV.makeBaseDir(channelName, version, outputDir )
    vListDir = outputDir + 'variableList/'
    if isApp:
        # outputDir = outputDir + 'AppResults_' + str(binNum) +'bins/'
        outputDir = outputDir + appFolderName + '_' + str(binNum) +'bins/'
        if not os.path.exists(outputDir ):
            os.mkdir( outputDir )
    print( 'outputDir: ', outputDir)
    if not os.path.exists(outputDir +"/log/" ):
        os.mkdir( outputDir  +"/log/")
    return vListDir, outputDir



if __name__ == '__main__':
    main()






