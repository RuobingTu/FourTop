# Instructon for implemention

## Workflow
* run_treeAnalyzer.out -> addTemplatesForCombine.py ->
* 
* 1tau0l: 
* writeHist_fakeRate.C and plotVariables1tau0l.py for generating faketau bg and plot distribution
* treeAnalyzer.C -> addTemplatesForCombine.py -> runCombineAll.py


## To do 
* python script for generating datacards

* install
  <!-- * export SCRAM_ARCH=slc7_amd64_gcc900 -->
  <!-- * cmsrel CMSSW_12_2_4 -->
  <!-- * cd CMSSW_12_2_4/src -->
  * git clone ssh://git@gitlab.cern.ch:7999/cms-nanoAOD/jsonpog-integration.git
  * git clone git@github.com:huiling110/FourTop.git 
  * bash setupEnv.sh( setting up proper g++ root python and correction)
  * cd FourTop
 * run
   <!-- * cmsenv --****>
  * cd objectSelection
* mkdir output
   <!-- * make clean -->
   * make 
   * ./run_objectTSelectorForNanoAOD.out
   * or root -b -q run_objectTSelectorForNanoAOD.C
 * tips
   * modify Linkdef.h and Makefile to use classes and functions from other source file(.C). never #inlude .C source code! only #include .h
   * only member functions of objectTSelector class should be in the class file, other functions go to utilityFunctions.C( keep things clean and code modulized)
   * only need to recompile if modifying source code, don't need to if only modifying run_objectTSelectorForNanoAOD.C


 * submit jobs in IHEP cluster
    * cd FourTop/objectSelection
    * open makeJob_objectTSelectorForNanoAOD.py, change the parameters to your setting in the file in the first few lines.
      * all the modification you should do it in the makeJob script
    * python3 makeJob_objectTSelector_forSeperate.py
    * . subAllJobs.sh

 * set up combine
    * cd $CMSSW_BASE/src
    * git clone git@github.com:cms-analysis/HiggsAnalysis-CombinedLimit.git HiggsAnalysis/CombinedLimit
    * cd HiggsAnalysis/CombinedLimit
    * cd $CMSSW_BASE/src/HiggsAnalysis/CombinedLimit
    * git fetch origin
    * git checkout v8.1.0
    * cd $CMSSW_BASE/src
    * curl -s https://raw.githubusercontent.com/cms-analysis/CombineHarvester/master/CombineTools/scripts/sparse-checkout-https.sh
    * scramv1 b clean; scramv1 b


       
      
       
  
      
     
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                