#!/bin/bash
cd /publicfs/cms/user/fabioiemmi/CMSSW_10_6_27/src/FourTop/objectSelection/
root -l -b -q 'run_objectTSelectorForNanoAOD.C(false,"/publicfs/cms/data/TopQuark/nanoAOD/2016/mc/ttbar_2l/","/publicfs/cms/user/fabioiemmi/TauOfTTTT_NanoAOD/UL2016_postVFP/v8_METfiltersAndPresel_fixJSONmask/mc/ttbar_2l/","outTree_41.root","5",false)'
