#!/bin/bash
cd /workfs2/cms/huahuil/4topCode/CMSSW_10_6_27/src/FourTop/objectSelection/
root -l -b -q 'run_objectTSelectorForNanoAOD.C(false,"/publicfs/cms/data/TopQuark/nanoAOD/2016/mc/ttbar_0l/","/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2016postVFP/v0_testing/ttbar_0l/","outTree_6.root")'
