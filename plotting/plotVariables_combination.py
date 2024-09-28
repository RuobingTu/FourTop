import usefulFunc as uf
import ttttGlobleQuantity as gq                                
import plotVariblesSRBDT as pl

def main():
    #for mass in [50,55,65,75,95]:
    #for mass in [70,80,85,90,100]:
    for mass in [65]:
        for i in [4]:
            ifVLL = f'VLLm{mass}0'
            inputDir2018 = f'/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v0baselineHardroSR_v81addSysSum/mc/variableHists_v0Basictraining1tau1l_VLLm{mass}0_{i}/'
            inputDir2017 = f'/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2017/v0baselineHardroSR_v81addSysSum/mc/variableHists_v0Basictraining1tau1l_VLLm{mass}0_{i}/'
            inputDir2016preVFP = f'/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2016preVFP/v0baselineHardroSR_v81addSysSum/mc/variableHists_v0Basictraining1tau1l_VLLm{mass}0_{i}/'
            inputDir2016postVFP = f'/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2016postVFP/v0baselineHardroSR_v81addSysSum/mc/variableHists_v0Basictraining1tau1l_VLLm{mass}0_{i}/'
            
            regionList = ['1tau1lSR']
            variables = ['BDT']
            channel = '1tau1l'
            
            sumPros = gq.proChannelDic[channel]
            if ifVLL:
                sumPros.append(ifVLL)
            #sumPros.append('jetHT')
            print(sumPros)
            
            sumProHists2018, sumProHistsSys2018 = getSumHistPerYear(inputDir2018, regionList, variables, sumPros)
            sumProHists2017, sumProHistsSys2017 = getSumHistPerYear(inputDir2017, regionList, variables, sumPros)
            sumProHists2016preVFP, sumProHistsSys2016preVFP = getSumHistPerYear(inputDir2016preVFP, regionList, variables, sumPros)
            sumProHists2016postVFP, sumProHistsSys2016postVFP = getSumHistPerYear(inputDir2016postVFP, regionList, variables, sumPros)
            
            
            combineHists = {}
            for ire in sumProHists2018['BDT'].keys():
                print(ire)
                combineHists[ire] = {}
                for isumPro in sumProHists2018['BDT'][ire].keys():
                    # sumProHists2018['BDT'][ire][isumPro].Print()
                    combineHists[ire][isumPro] = sumProHists2018['BDT'][ire][isumPro].Clone()
                    if not uf.isData(isumPro):
                        combineHists[ire][isumPro].Add(sumProHists2017['BDT'][ire][isumPro])
                        combineHists[ire][isumPro].Add(sumProHists2016preVFP['BDT'][ire][isumPro])
                        combineHists[ire][isumPro].Add(sumProHists2016postVFP['BDT'][ire][isumPro])
                    else:
                        combineHists[ire][isumPro]
                        uf.addDataHist(combineHists[ire][isumPro], sumProHists2017['BDT'][ire][isumPro])
                        uf.addDataHist(combineHists[ire][isumPro], sumProHists2016preVFP['BDT'][ire][isumPro])
                        uf.addDataHist(combineHists[ire][isumPro], sumProHists2016postVFP['BDT'][ire][isumPro])
            
            plotDir = inputDir2018+'results/'
            uf.checkMakeDir(plotDir)
            # plotName = 'combination' 
            plotName = 'combination_fixedDataError' 
            for ire in combineHists.keys():
                pl.makeStackPlotNew(combineHists[ire], sumPros, 'BDT', ire, plotDir, False, plotName, 'Run2', False, 100, True ,True, True, ifVLL, ifSystematic = True) 
            if ifVLL in sumPros:
                sumPros.remove(ifVLL)
    
def getSumHistPerYear(inputDir2018, regionList, variables, sumPros):
    era = uf.getEraFromDir(inputDir2018)
    print('era=', era)
    # isRun3 = uf.isRun3(inputDir2018)
    inputDirDic = uf.getInputDicNew( inputDir2018)
    uf.checkMakeDir( inputDirDic['mc']+'results/')
    sumProHists, sumProHistsSys = uf.getSumHist(inputDirDic, regionList, sumPros,{},  variables, era, False)
    return sumProHists, sumProHistsSys
    

    
if __name__ == '__main__':
    main()