#!/bin/bash
cd /workfs2/cms/huahuil/4topCode/CMSSW_10_6_27/src/FourTop/objectSelection/
root -l -b -q 'run_objectTSelectorForNanoAOD.C(false,"/publicfs/cms/data/TopQuark/nanoAOD/2016/mc/zz/","/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/UL2016_postVFP/v7_preselectionAddingTausL/mc/zz/","outTree_0.root","7",true)'
