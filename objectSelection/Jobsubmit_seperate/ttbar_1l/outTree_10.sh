#!/bin/bash
cd /workfs2/cms/huahuil/4topCode/CMSSW_10_2_20_UL/src/FourTop/objectSelection/
root -l -b -q 'run_objectTSelectorForNanoAOD.C(false,"/publicfs/cms/data/TopQuark/nanoAOD/2016/mc/ttbar_1l/","/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/2016PPV/v0_testing/ttbar_1l/","outTree_10.root")'
