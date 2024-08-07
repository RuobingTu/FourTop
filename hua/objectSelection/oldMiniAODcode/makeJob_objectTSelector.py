import sys
import os
import glob
import string
import subprocess

outputDir = "/publicfs/cms/user/huahuil/TauOfTTTT/2016v1/v28_ptForAllLeptons/"

Jobsubmitpath = "/publicfs/cms/user/huahuil/code/FourTopTau/CMSSW_10_2_20_UL/src/FourTop/objectSelection/"
rootplizer = "run_objectTSelector.C"
allJobFileName = Jobsubmitpath+"/hepsub.sh"
if os.path.exists(allJobFileName):
    os.popen('rm -fr '+allJobFileName)
if os.path.exists(Jobsubmitpath+"/Jobsubmit"):
   os.popen('rm -fr '+Jobsubmitpath+"/Jobsubmit")
os.popen('mkdir -p '+Jobsubmitpath+"/Jobsubmit")

sample = {
  "TTTT_TuneCP5_PSweights_13TeV-amcatnlo-pythia8_correctnPartonsInBorn/Legacy16V2_TTTT_TuneCP5_PSweights_13TeV-amcatnlo-pythia8addGenWeight/210201_023641/0000/":"0",
  # {{{
##tt
    "TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8/Legacy16V2_TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8addGenWeight/210201_024446/0000/":"1_0",
    "TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8/Legacy16V2_TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8addGenWeight/210201_024239/0000/":"1_1",
    "TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8/Legacy16V2_TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8addGenWeight/210201_024040/0000/":"1_2",
 #  "TTJets_TuneCUETP8M2T4_13TeV-amcatnloFXFX-pythia8":"1",
 #  "TT_TuneCUETP8M2T4_13TeV-powheg-pythia8" :"1_2",
#  "TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8":"1",
 #  "ttZJets_13TeV_madgraphMLM-pythia8":"2",
#  "ttWJets_13TeV_madgraphMLM":"3",
#  "ttH_4f_ctcvcp_TuneCP5_13TeV_madgraph_pythia8":"4",#ttH
#  "ttHJetToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8_mWCutfix":"4_0",
#  "ttbb_4FS_ckm_amcatnlo_madspin_pythia8":"5",

##diboson and triboson an w/z+jets
  #  "WZ_TuneCUETP8M1_13TeV-pythia8":"6",
#  "WW_TuneCUETP8M1_13TeV-pythia8":"7_0",
#  "WWTo2L2Nu_DoubleScattering_13TeV-pythia8":"7_3",
  #  "WpWpJJ_EWK-QCD_TuneCUETP8M1_13TeV-madgraph-pythia8":"7_1",
 #  "ZZ_TuneCUETP8M1_13TeV-pythia8":"8",
  #  "WGJets_MonoPhoton_PtG-40to130_TuneCUETP8M1_13TeV-madgraph":"9",
  #  "ZGJetsToLLG_EW_LO_13TeV-sherpa":"10",
  #  "WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8":"11",
#  "WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8":"12",
  #  "WWG_TuneCUETP8M1_13TeV-amcatnlo-pythia8":"13",
  #  "ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8":"14",
  #  "WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8":"15",
  #  "WZG_TuneCUETP8M1_13TeV-amcatnlo-pythia8":"16",
#  "WGGJets_TuneCUETP8M1_13TeV_madgraphMLM_pythia8":"17",
#  "WGG_5f_TuneCUETP8M1_13TeV-amcatnlo-pythia8":"17_1",
  #  "ZGGJets_ZToHadOrNu_5f_LO_madgraph_pythia8":"18",
#
#  "WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8":"19",
##DY
#  "DYJetsToTauTau_ForcedMuEleDecay_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_ext1":"20",
##single top
  #  "tZq_ll_4f_ckm_NLO_TuneCP5_PSweights_13TeV-amcatnlo-pythia8":"21_1",
  #  "tZq_nunu_4f_13TeV-amcatnlo-pythia8_TuneCUETP8M1":"21_2",
#  "ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M2T4":"21_3",
#  "ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M2T4":"21_4",
  #  "TGJets_TuneCUETP8M1_13TeV_amcatnlo_madspin_pythia8":"22",
#  "THW_ctcvcp_HIncl_M125_TuneCP5_13TeV-madgraph-pythia8":"23_1",
#  "THQ_ctcvcp_Hincl_13TeV-madgraph-pythia8_TuneCUETP8M1":"23_2",
##  H
#  "VHToNonbb_M125_13TeV_amcatnloFXFX_madspin_pythia8":"24",
#  "VHToNonbb_M125_DiLeptonFilter_TuneCUETP8M1_13TeV_amcatnloFXFX_madspin_pythia8":"24_1",
#  "ZHToTauTau_M125_13TeV_powheg_pythia8":"25_1",
#  "ZH_HToBB_ZToLL_M125_13TeV_powheg_pythia8":"25_2",
#  "GluGluHToZZTo4L_M125_13TeV_powheg2_JHUgenV6_pythia8":"26_0",
#  "GluGluHToBB_M125_13TeV_amcatnloFXFX_pythia8":"26_1",
#  "GluGluHToGG_M125_13TeV_amcatnloFXFX_pythia8":"26_2",
#  "GluGluHToMuMu_M-125_TuneCP5_PSweights_13TeV_powheg_pythia8":"26_3",
#  "GluGluHToTauTau_M125_13TeV_powheg_pythia8":"26_4",
#  "GluGluHToWWTo2L2Nu_M125_13TeV_powheg_JHUgen_pythia8":"26_5",
#  "GluGluHToWWToLNuQQ_M125_13TeV_powheg_JHUGenV628_pythia8":"26_6",
#  "VBFHToWWToLNuQQ_M125_13TeV_powheg_JHUGenV628_pythia8":"27_0",
#  "VBFHToWWTo2L2Nu_M125_13TeV_powheg_JHUgenv628_pythia8":"27_1",
#  "VBFHToTauTau_M125_13TeV_powheg_pythia8":"27_2",
#  "VBFHToMuMu_M-125_TuneCP5_PSweights_13TeV_powheg_pythia8":"27_3",
#  "VBFHToGG_M125_13TeV_amcatnlo_pythia8_v2":"27_4",
#  "VBFHToBB_M-125_13TeV_powheg_pythia8_weightfix":"27_5",
#  "VBF_HToZZTo4L_M125_13TeV_powheg2_JHUgenV6_pythia8":"27_6",
# }}}

}

allJobFile = file(allJobFileName,"w")
print >> allJobFile, "cd "+Jobsubmitpath+"/Jobsubmit"

def prepareCshJob(inputFile,shFile):
    subFile  = file(shFile,"w")
    print >> subFile, "#!/bin/bash"
    print >> subFile, "/bin/hostname"
    #  print >> subFile, "gcc -v"
    #  print >> subFile, "pwd"
    print >> subFile, "cd "+Jobsubmitpath
    print >> subFile, "root -l -b -q "+"\'"+rootplizer+"(false,\""+inputFile+"\","+"\""+outputDir+"\")"+"\'"


for k in sample:
    print k
    print sample[k]
    sample_k = k
    sampleNumber = sample[k]
    sampleName = sample_k.split("/")[0]
    shFile = "OS_2016"+"_"+sampleName+".sh"
    shFileName = "Jobsubmit/"+shFile
    prepareCshJob( sample_k ,shFileName)	
    logFileName = outputDir+sampleName+".log"
    errorFileName = outputDir+sampleName+".err"
    print >> allJobFile, "hep_sub "+ shFile + " -o "+logFileName+ " -e "+errorFileName	 
    #  print >> allJobFile, "cd .."


os.popen('chmod 777 '+Jobsubmitpath+"/Jobsubmit/*sh")
os.popen('chmod 777 '+Jobsubmitpath+"/hepsub.sh")





