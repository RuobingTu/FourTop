
# import ROOT
import os
import subprocess

# pre_dir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016_preVFP/v2Add2Variables_fromV9/'
# post_dir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016_postVFP/v2Add2Variables_fromV9/' 
# merged_dir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v2Add2Variables_fromV9/'
# pre_dir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016_preVFP/v3correctBjetsvariable_fromV9/'
# post_dir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016_postVFP/v3correctBjetsvariable_fromV9/' 
# merged_dir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v3correctBjetsvariable_fromV9/'
# pre_dir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016_preVFP/v4modifiedMinDeltaR_fromV9/'
# post_dir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016_postVFP/v4modifiedMinDeltaR_fromV9/' 
# merged_dir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/v4modifiedMinDeltaR_fromV9/'
forMVAFile = 'v0baseline_v16_HLTselection/'

# pre_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016_preVFP/'
# post_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016_postVFP/'
pre_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/'
post_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/'
merged_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/'
pre_dir = pre_dir_base + forMVAFile
post_dir = post_dir_base + forMVAFile
merged_dir = merged_dir_base + forMVAFile


if not os.path.exists( merged_dir ):
    os.mkdir( merged_dir )


for i in os.listdir( pre_dir ):

    if os.path.isdir( pre_dir + i ):
        continue

    ifile = pre_dir  + i
    ifile_post = post_dir + i 
    ifile_merged = merged_dir + i

    icommand = 'hadd {} {} {}'.format( ifile_merged, ifile, ifile_post )
    print( icommand )
    process = subprocess.run( icommand, shell=True )
    output = process.stdout
    print( output )


 





