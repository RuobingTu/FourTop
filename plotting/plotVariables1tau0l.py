import usefulFunc as uf
import writeCSVforEY as wc
import plotVaribles as pv



def main():
    inputDir = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v4baselineBtagRUpdated_v57ovelapWithTausF/mc/variableHists_v1FR_application/'
    
    
    variables = ['jets_bScore' ]
    # variables = ['bjetsM_num', 'jets_bScore']
    # variables = ['tausF_1jetPtFRWeight']
    # variables = [ 'tausF_prongNum', 'tausF_charge', 'tausF_1decayMode', 'tausL_1ptFRWeight', 'tausL_1etaAbsFRWeight' , 'tausF_1jetPtFRWeight', 'tausF_1eta', 'PV_npvs', 'tausF_1pt', 'jets_HT', 'jets_bScore', 'jets_bScoreMultiply', 'jets_4largestBscoreSum', 'jets_4largestBscoreMulti', 'bjetsM_invariantMass', 'jets_1pt', 'jets_2pt','jets_3pt', 'jets_4pt', 'jets_5pt', 'jets_6pt', 'jets_num', 'bjetsM_num']  
    # variables = ['jets_HT', 'jets_bScore', 'jets_bScoreMultiply', 'jets_4largestBscoreSum', 'jets_4largestBscoreMulti', 'bjetsM_invariantMass', 'jets_1pt', 'jets_2pt','jets_3pt', 'jets_4pt', 'jets_5pt', 'jets_6pt', 'jets_num', 'bjetsM_num', ] #1tau0l
    # regionList = ['1tau0lVR', '1tau0lVRGen', '1tau0lVRNotGen']
    # regionList = ['1tau0lCR', '1tau0lCRGen', '1tau0lCRLTauNotT_Weighted', '1tau0lCRLTauNotTGen_Weighted']
    # regionList = ['1tau0lVR', '1tau0lVRGen', '1tau0lVRLTauNotT_Weighted', '1tau0lVRLTauNotTGen_Weighted'] # new MR
    # regionList = ['1tau0lCRb', '1tau0lCRbGen', '1tau0lCRbLTauNotT_Weighted', '1tau0lCRbLTauNotTGen_Weighted'] # new CR
    # regionList = ['1tau0lCRc', '1tau0lCRcGen', '1tau0lCRcLTauNotT_Weighted', '1tau0lCRcLTauNotTGen_Weighted'] # new VR
    regionList = ['1tau0lSR', '1tau0lSRGen',  '1tau0lSRLTauNotT_Weighted', '1tau0lSRLTauNotTGen_Weighted']
    ifFR_sys = True 
    plotName = 'dataVsMC_fakeTauFromData'
    
    
    era = uf.getEraFromDir(inputDir)
    print('era=', era)
    isRun3 = uf.isRun3(inputDir)
    regionList = appendSYSRegions( ifFR_sys, regionList) 

    inputDirDic = uf.getInputDicNew( inputDir)
    #sumProcessPerVar[var][region][sumedProcess] = hist
    #sumProcessPerVarSys[var][region][sumedProcess][isysVariation] = hist
    sumProcessPerVar = {}
    sumProcessPerVarSys = {}
    for ivar in variables:
        sumProcessPerVar[ivar], sumProcessPerVarSys[ivar] = uf.getSummedHists( inputDirDic, regionList, ivar , False, era, False, isRun3)       
    print( sumProcessPerVar )
    print( sumProcessPerVarSys )
    print('\n')
   
    legendOrder = ['tt', 'ttX', 'singleTop', 'VV', 'WJets']
    
    for ivar in sumProcessPerVar:
        wc.replaceBgWithGen( inputDirDic, sumProcessPerVar[ivar], ivar, regionList, 2, ifFR_sys, sumProcessPerVarSys[ivar]  )
    legendOrder.insert(0, 'fakeTau')
    sumProcessPerVar[ivar][regionList[0]].pop('qcd')

    if regionList[0]=='1tau0lSR' and 'jets_bScore' in variables: 
        pv.writeTemplatesForCombine(sumProcessPerVar, sumProcessPerVarSys, inputDirDic['mc'], regionList[0]) 

    
    
    
    
def appendSYSRegions( ifFR_sys, regionList) :
    if ifFR_sys:
        regionList.append(regionList[2]+'_up')
        regionList.append(regionList[2]+'_down')
        regionList.append(regionList[3]+'_up')
        regionList.append(regionList[3]+'_down')
    return regionList 





if __name__ == "__main__":
    main()