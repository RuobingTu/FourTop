
# import ROOT
import os
import subprocess

#???there is case when not all files is merged and copied. 


def copyData( dir ):
    for ifile in os.listdir( dir ):
        copyCom = 'cp {} {}'.format( dir+ifile, mergedDirDict['data']  )
        print( copyCom )
        process = subprocess.run( copyCom, shell=True )
        output = process.stdout
        print( output )

# version = 'v0LepLAdded_v45newLepBugFixed/'
# version = 'v0LepLAdded_v46addPOGIDL/'
# version = 'v1cut1tau1l_v51TESNewLepObjectRemovalCorrected/'
# version = 'v0baseline_v51TESNewLepObjectRemovalCorrected/'
# version = 'v3baslineNoHLTMuonTriggerAdded_v52noHLTButPreSelection/'
# version = 'v4baseline_v52noHLTButPreSelection/'
# version = 'v4baseline_re_v52noHLTButPreSelection/'
# version = 'v5updateHLTSF_v52noHLTButPreSelection/'
# version ='v2baslineNoHLT_v54noHLTButPreMetFixed/'
# version = 'v2baslineNoHLT_v55ojectRemovalwithTightNoHLT/'
# version = 'v3HLTWeightUpdated_v55ojectRemovalwithTightNoHLT/'
# version = 'v5extra1tau1lCut_v56preselection/'
# version = 'v6baseline_v56preselection/'
# version = 'v2baslineNoHLT_v57ovelapWithTausF/'
# version = 'v3baselineNoBCutHLTWeightUpdated_v57ovelapWithTausF/'
# version = 'v4baselineBtagRUpdated_v57ovelapWithTausF/'
# version = 'v0baseline_v61fixesLepRemovalBug/'
# version = 'v2eraBugFixed_v61fixesLepRemovalBug/'
# version = 'v3btagWeightGood_v61fixesLepRemovalBug/'
# version = 'v4forBDT1tau1lCut_v61fixesLepRemovalBug/'
# version = 'v0baseline_addTauGenNum_v61fixesLepRemovalBug/'
# version = 'v0baseline_v64noHLTSel/'
# version = 'v0baseline_v64PreAndHLTSel/'
# version = 'v0baseline_v64PreAndHLTSel_JESUp/'
# version = 'v0baseline_v64PreAndHLTSel_JESDown/'
# version = 'v0baseline_v64PreAndHLTSel_JERDown/'
# version = 'v0baseline_v64PreAndHLTSel_JERUp/'
version = 'v0baseline_v67TheoryWeightAdded/'

# version = 'v0baseline_v0preSel/' #2022
ifJustMC = False

pre_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/'
post_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/'
merged_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/'
# pre_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2022postEE/'
# post_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2022preEE/'
# merged_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2022/'

pre_dir = pre_dir_base + version
post_dir = post_dir_base + version
merged_dir = merged_dir_base + version


if not os.path.exists( merged_dir ):
    os.mkdir( merged_dir )

preDirDict = {}
postDirDict = {}
mergedDirDict = {}
preDirDict['mc'] = pre_dir + 'mc/'
postDirDict['mc'] = post_dir + 'mc/'
mergedDirDict ['mc']= merged_dir + 'mc/'
if not ifJustMC:
    preDirDict['data'] = pre_dir + 'data/'
    postDirDict['data'] = post_dir + 'data/'
    mergedDirDict['data'] = merged_dir + 'data/'


# for MC we should haddd to add
for ikey in preDirDict.keys():
    print( ikey )
    if not os.path.exists( mergedDirDict[ikey] ):
        os.mkdir( mergedDirDict[ikey] )
    if not ikey == 'mc': continue
    for i in os.listdir( preDirDict[ikey] ):
        if os.path.isdir( preDirDict[ikey] + i ):
            continue

        ifile = preDirDict[ikey]  + i
        ifile_post = postDirDict[ikey] + i 
        ifile_merged = mergedDirDict[ikey] + i
        # icommand = 'hadd {} {} {}'.format( ifile_merged, ifile, ifile_post )
        icommand = 'hadd -f {} {} {}'.format( ifile_merged, ifile, ifile_post )
        print( icommand )
        process = subprocess.run( icommand, shell=True )
        output = process.stdout
        print( output )



#for data
copyData( preDirDict['data'])
copyData( postDirDict['data'])




 





