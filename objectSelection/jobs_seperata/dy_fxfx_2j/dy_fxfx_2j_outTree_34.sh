#!/bin/bash
cd /publicfs/cms/user/fabioiemmi/CMSSW_10_6_27/src/FourTop/objectSelection/
root -l -b -q 'run_objectTSelectorForNanoAOD.C(false,"/publicfs/cms/data/TopQuark/nanoAOD/2016/mc/dy_fxfx_2j/","/publicfs/cms/user/fabioiemmi/TauOfTTTT_NanoAOD/UL2016_postVFP/v8_METfiltersAndPresel_fixJSONmask/mc/dy_fxfx_2j/","outTree_34.root","5",false)'
