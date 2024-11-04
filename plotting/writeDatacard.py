import os
import usefulFunc as uf
import ttttGlobleQuantity as gq

MCSys = {
    #sys: [isCorrelated, whichProces] ; whichProcess=0: mc; whichProcess=1: fakeTau, whichProcess=2: fakeLepton
    'CMS_pileup': [True, 0],
    'CMS_prefiring': [True, 0],
    
    'CMS_eff_t_vsMu': [False, 0], #uncorrelated
    'CMS_eff_t_vsEle': [False, 0], #need to add era to the name
    'CMS_eff_t_vsJet_stat1_dm0': [False, 0],
    'CMS_eff_t_vsJet_stat1_dm1': [False, 0],
    'CMS_eff_t_vsJet_stat1_dm10': [False, 0],
    'CMS_eff_t_vsJet_stat1_dm11': [False, 0],
    'CMS_eff_t_vsJet_stat2_dm0': [False, 0],
    'CMS_eff_t_vsJet_stat2_dm1': [False, 0],
    'CMS_eff_t_vsJet_stat2_dm10': [False, 0],
    'CMS_eff_t_vsJet_stat2_dm11': [False, 0],
    'CMS_eff_t_vsJet_syst_alleras': [True, 0],
    'CMS_eff_t_vsJet_syst': [False, 0],
    'CMS_eff_t_vsJet_syst_dm0': [False, 0],
    'CMS_eff_t_vsJet_syst_dm1': [False, 0],
    'CMS_eff_t_vsJet_syst_dm10': [False, 0],
    'CMS_eff_t_vsJet_syst_dm11': [False, 0],
    
    
}



def main():
   channel = '1tau1l'
   inputTemplate = '/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_v86HadroPreSelWithTTWTTZNLO/mc/variableHists_v0BDT1tau1l/combine/templatesForCombine1tau1l.root'
   
   inputDir = os.path.dirname(inputTemplate) 
   outDir = inputDir + 'datacardSys/'
   uf.checkMakeDir(outDir)
   outCard = f"{outDir}datacard_{channel}.txt"
    
   processes = gq.proChannelDic[channel]
   processes.remove('jetHT')  
   print(processes)
  
   era = uf.getEraFromDir(inputTemplate) 
   sysDic = getSysDic(processes, channel, era) 
#    print(sysDic)
   for i, iv in sysDic.items():
       print(i, iv)
       
   write_shape_datacard(outCard, inputTemplate, channel, processes,  sysDic) 

def getSysDic(processes, channel, era):
    sysDic = {}
    for sys, sysList in MCSys.items():
        sysName = sys if sysList[0] else f"{sys}_{era}"
        sysDic[sysName] = []
        sysDic[sysName].append("shape")     
        proSysDic = getProSysDic(sysName, sysList, processes)   
        sysDic[sysName].append(proSysDic)

    return  sysDic
     
     
def getProSysDic(sys, sysList, processes):
    proSys = {}
    for ipro in processes:
        if uf.isData(ipro) : continue
        if ipro=='fakeTau':
            proSys[ipro] = 1 if sysList[1]==1 else 0
        elif ipro=='fakeLepton':
            proSys[ipro] = 1 if sysList[1]==2 else 0
        else: 
            proSys[ipro] = 1 if sysList[1]==0 else 0
             
    return proSys            
             
   
def write_shape_datacard(output_file, root_file, channel_name, processes,  systematics):
    """
    Write a shape datacard for CMS Combine.

    Parameters:
    - output_file: Name of the text file to write the datacard to.
    - root_file: Name of the ROOT file containing histograms.
    - channel_name: Name of the analysis channel.
    - processes: List of process names (e.g., ["signal", "background1", "background2"]).
    - rates: List of initial expected rates for each process.
    - systematics: Dictionary of systematic uncertainties structured as:
      { "uncertainty_name": (type, { "process_name": ("up_modifier", "down_modifier") }) }
      Example: { "lumi": ("lnN", {"background1": (1.10, 0.90) }) }
    """

    num_processes = len(processes)
    signal_index = -1  # Assuming the first process is the signal
    
    process_col_width = 40
    value_col_width = 12
    
    rates = f"rate".ljust(process_col_width)
    proString = f"process".ljust(process_col_width)
    binString = f"bin".ljust(process_col_width)
    lines = [
        "imax 1  number of channels",
        "jmax {}  number of background processes".format(num_processes - 1),
        "kmax *  number of nuisance parameters (sources of systematic uncertainties)",
        "---------------",
        f"shapes * {channel_name} {root_file} $PROCESS $PROCESS_$SYSTEMATIC",
        "---------------",
        f"bin         {channel_name}",
        "observation -1",
        "---------------",
        f"{binString}{''.join([channel_name.ljust(value_col_width) for _ in range(num_processes)])}",
        f"{proString}{''.join([proc.ljust(value_col_width) for proc in processes])}",
        f"{proString}{''.join([str(i - signal_index).ljust(value_col_width) for i in range(num_processes)])}",
        f"{rates}{''.join(['-1'.ljust(value_col_width) for i in range(num_processes)])}" ,
        
        "---------------"
    ]

    for unc_name, (unc_type, uncertainties) in systematics.items():
        line = f"{unc_name }  {unc_type}".ljust(process_col_width)
        ilist = []
        for proc in processes:
           iuncer = uncertainties[proc] if not uncertainties[proc]==0 else '-'
        #    print(type(iuncer))
           ilist.append(f"{iuncer}".ljust(value_col_width))
        line += " ".join(
            ilist
            # f"{uncertainties[proc][0]:.3f}/{uncertainties[proc][1]:.3f}" if proc in uncertainties else "-"
            # for proc in processes
            # f"{uncertainties[proc]}" if proc in uncertainties else "-"
            # for proc in processes
        )
        # print(line)
        lines.append(line)

    # Write to file
    with open(output_file, 'w') as f:
        for line in lines:
            f.write(line + "\n")
    print(f"Datacard written to {output_file}")

if __name__=='__main__':
    main()