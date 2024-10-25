import pandas as pd

# obCSV = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/objectSelectionResults/v27noJERnoTESWithObjectRemoval/mc/results/cutFlowRawEntries_objectSelection.csv'
# R1tau0l = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0noBaseline_v27noJERnoTESWithObjectRemoval/mc/variableHists_v0forCutFlow/results/cutflow_rawEntries.csv'
# obCSV = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/objectSelectionResults/v27noJERnoTESWithObjectRemoval/mc/results/cutFlow_objectSelection.csv'
# R1tau0l = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0noBaseline_v27noJERnoTESWithObjectRemoval/mc/variableHists_v0forCutFlow/results/cutflow.csv'
# obCSV = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/objectSelectionResults/v27noJERnoTESWithObjectRemoval/mc/results/cutFlowRawEntries_objectSelection.csv'
# R1tau0l = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0noBaseline_v27noJERnoTESWithObjectRemoval/mc/variableHists_v0forCutFlow/results/cutflow_rawEntries.csv'
# R1tau0l = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0noBaseline_v27noJERnoTESWithObjectRemoval/mc/variableHists_v4add1tau1lCutflow/results/1tau1lCutflow_rawEntries.csv'
# R1tau0l = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0noBaseline_v27noJERnoTESWithObjectRemoval/mc/variableHists_v4add1tau1lCutflow/results/1tau1lCutflow.csv'
# obCSV = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/objectSelectionResults/v29LorentzProblemSolvedNoJERnoTES/mc/results/cutFlow_objectSelection.csv'
obCSV = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/objectSelectionResults/v29LorentzProblemSolvedNoJERnoTES/mc/results/cutFlow_objectSelection.csv'
# obCSV = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/objectSelectionResults/v27noJERnoTESWithObjectRemoval//mc/results/cutFlowRawEntries_objectSelection.csv'
# R1tau0l = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/v0noBaseline_v27noJERnoTESWithObjectRemoval/mc/variableHists_v4add1tau1lCutflow/results/1tau1lCutflow.csv'
# R1tau0l = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/v0noBaseline_v27noJERnoTESWithObjectRemoval/mc/variableHists_v4add1tau1lCutflow/results/1tau0lCutflow.csv'
R1tau0l = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016preVFP/v0noBaseline_v29LorentzProblemSolvedNoJERnoTES/mc/variableHists_v0forCutFlow/results/1tau0lCutflow.csv'
# R1tau0l = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v0noBaseline_v29LorentzProblemSolvedNoJERnoTES/mc/variableHists_v0forCutFlow/results/1tau1lCutflow.csv'

df1 = pd.read_csv( obCSV )
df2 = pd.read_csv( R1tau0l )

df2 = df2.join( df1['OBinitial'] )
df2 = df2.join( df1['OBHLT'])
# df2 = df2.join( df1['preSelection'])
# df2 = df2.join( df1['HLTeff'])

# df2['baselineEff'] = df2['baseline']/df2['HLTeff']

print( df1 )
print( df2 )

df2.to_csv( R1tau0l )

