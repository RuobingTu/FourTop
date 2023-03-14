import numpy as np

import usefulFunc as uf

from plotForFakeRate import plotEfficiency 

def main():
    inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2016postVFP/v2baslineNoHLT_v52noHLTButPreSelection/mc/variableHists_v0triggerEff/'
    variableList = ['jets_HT', 'bjetsM_num', 'jets_6pt', 'jets_number']
    regionList = ['baseline1Muon', 'baseline1MuonAndHLT', 'baseline', 'baselineAndHLT']
    
    # variableDic = {
    #     'jets_HT': np.array( [500., 550, 600, 650, 750, 850, 950, 1050, 1250, 1450, 1650, 1950, 2500] ),
    # }
    # variableDic = {
    #     'bjetsM_num': np.array([-0.5, 0.5, 1.5, 2.5, 3.5, 5.5, 7.5]),
    # }
    
    # variableDic = {
    #     'jets_6pt': np.array([25.0, 40, 55, 70, 85, 115, 145])
    # }
    variableDic = {
        'jets_number': []
    } 
    
    
    
    inputDirDic = uf.getDirDic(inputDir)
    plotDir = inputDirDic['mc'] + 'results/'
    uf.checkMakeDir(plotDir)
    era = uf.getEraFromDir(inputDir)
     
    sumProcessPerVar = {}
    sumProcessPerVarSys = {} 
    for ivar in variableList:
        sumProcessPerVar[ivar], sumProcessPerVarSys[ivar]= uf.getSummedHists( inputDirDic, regionList, ivar )
    print( sumProcessPerVar )
    
    # plotEffHLT(variableDic, 'baseline', 'baselineAndHLT', sumProcessPerVar, 'MCTruthEff', plotDir)
    # plotEffHLT(variableDic, 'baseline1Muon', 'baseline1MuonAndHLT', sumProcessPerVar,  'MCRefEff', plotDir)
    # plotEffHLT(variableDic, 'baseline1Muon', 'baseline1MuonAndHLT', sumProcessPerVar, 'dataRefEff', plotDir, ifData=1)
    plotEffHLT(variableDic, 'baseline', 'baselineAndHLT', sumProcessPerVar, 'ttttHLTEff', plotDir, ifData=2)
    
   
   
    
    
    #overlay of MC truth efficiency, MC reference efficiency and data reference efficiency


def plotEffHLT(variableDic,  regionDe, regionNu, sumProcessPerVar, plotName, plotDir, ifData=0): 
    if  ifData==0:
        MCTrueth_de = uf.addBGHist(sumProcessPerVar[list(variableDic.keys())[0]], list(variableDic.keys())[0], regionDe, includeQCD=True)
        MCTrueth_nu = uf.addBGHist(sumProcessPerVar[list(variableDic.keys())[0]], list(variableDic.keys())[0], regionNu, includeQCD=True)
    elif ifData==1:
        MCTrueth_de = sumProcessPerVar[list(variableDic.keys())[0]][regionDe]['singleMu'].Clone()
        MCTrueth_nu = sumProcessPerVar[list(variableDic.keys())[0]][regionNu]['singleMu'].Clone()
        MCTrueth_de.SetName(regionDe)
        MCTrueth_nu.SetName(regionNu)
    elif ifData==2:
        MCTrueth_de = sumProcessPerVar[list(variableDic.keys())[0]][regionDe]['tttt'].Clone()
        MCTrueth_nu = sumProcessPerVar[list(variableDic.keys())[0]][regionNu]['tttt'].Clone()
        MCTrueth_de.SetName(regionDe)
        MCTrueth_nu.SetName(regionNu)
        
    if len( variableDic[list(variableDic.keys())[0]] ) >0:
        binLowEges = variableDic[list(variableDic.keys())[0]]
        MCTrueth_de = MCTrueth_de.Rebin(len(binLowEges)-1, '', binLowEges)
        MCTrueth_nu = MCTrueth_nu.Rebin(len(binLowEges)-1, '', binLowEges)
    eff_MCTrueth = MCTrueth_de.Clone()
    eff_MCTrueth.Reset()
    eff_MCTrueth.Divide(MCTrueth_nu, MCTrueth_de)
    # eff_MCTrueth.SetName('eff_MCTrueth')
    eff_MCTrueth.SetName(plotName)
    eff_MCTrueth.SetTitle('efficiency')
    eff_MCTrueth.Print()
    plotName = plotDir + list(variableDic.keys())[0] + plotName + '.png'
    plotEfficiency(MCTrueth_nu, MCTrueth_de, eff_MCTrueth, plotName, '2016postVFP', False)

    
if __name__=='__main__':
    main()