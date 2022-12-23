
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

# version = 'v0baseline_v16_HLTselection/'
# version = 'v0noBaseline_v29LorentzProblemSolvedNoJERnoTES/'
# version = 'v1baseline_v29LorentzProblemSolvedNoJERnoTES/'
# version = 'v1baseline_v36TESandJERByHuiling/'
# version = 'v1baseline_v38TESandJERTauPt20_preselection/'
# version = 'v2baselineAddingTauProng_v38TESandJERTauPt20_preselection/'
# version = 'v0addMoreVariables_v39addTauBranches/'
# version = 'v1fixedTauVariables_v39addTauBranches/'
# version = 'v1fixedTauVariables_v40addTauJetEtau/'
# version = 'v3extra1tau1lCut_v41addVertexSelection/'
# version = 'v4baseline_v41addVertexSelection/'
# version = 'v5baselineExtraTauLepCut_v41addVertexSelection/'
# version = 'v4baseline_v42fixedChargeType/'
# version = 'v6Cut1tau1lVariableFixed_v42fixedChargeType/'
version = 'v8Cut1tau1l_v42fixedChargeType/'
ifJustMC = False

pre_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/'
post_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/'
merged_dir_base = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016/'
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




 





