import ROOT
import os

def get_histograms_with_keyword(root_file, keyword):
    histograms = []
    for key in root_file.GetListOfKeys():
        obj = key.ReadObj()
        if isinstance(obj, ROOT.TH1) and "data_obs" not in obj.GetName() and "singleTop" not in obj.GetName() and "normalised" not in obj.GetName() and ((keyword in obj.GetName() and "SR" in obj.GetName()) or "SR_BDT" in obj.GetName()):
            histograms.append(obj)
    return histograms

def read_histogram_bins(histogram):
    bins = []
    for bin_num in range(1, histogram.GetNbinsX() + 1):
        bins.append(histogram.GetBinContent(bin_num))
    return bins

def calculate_deviation(base, up, down):
    up_deviation = [(u - b) / b * 100 if b != 0 else 0 for b, u in zip(base, up)]
    down_deviation = [(d - b) / b * 100 if b != 0 else 0 for b, d in zip(base, down)]
    return up_deviation, down_deviation

def main():
    file_path = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v0baselineHardroSR_v81addSysSum/mc/variableHists_v0Basictraining1tau1l_VLLm600_6/combine/templatesForCombine1tau1l.root"
    #file_path = "/publicfs/cms/user/huahuil/tauOfTTTT_NanoAOD/forMVA/2018/v0baselineHardro_v81addSysSum/mc/variableHists_v2BDT1tau1l_binE2/combine/templatesForCombine1tau1l.root"
    print(file_path)
    if not os.path.isfile(file_path):
        print(f"Error: File '{file_path}' does not exist.")
        return

    root_file = ROOT.TFile.Open(file_path)
    if not root_file or root_file.IsZombie():
        print(f"Error: Could not open file '{file_path}'.")
        return

    keyword = "pdfAlphaS"
    histograms = get_histograms_with_keyword(root_file, keyword)

    if not histograms:
        print(f"No histograms found with keyword '{keyword}'.")
        return
    dict_save = {}
    for hist in histograms:
        bins = read_histogram_bins(hist)
        dict_save[hist.GetName()] = bins
    #print(dict_save)
    
    for key in dict_save:
        if key.endswith('_BDT') and not key.endswith(('Up_BDT', 'Down_BDT')):
            base_key = key
            up_key = base_key.replace('_BDT', '_pdfAlphaS_2018Up_BDT')
            down_key = base_key.replace('_BDT', '_pdfAlphaS_2018Down_BDT')
            
            if up_key in dict_save and down_key in dict_save:
                base_values = dict_save[base_key]
                up_values = dict_save[up_key]
                down_values = dict_save[down_key]
                
                up_deviation, down_deviation = calculate_deviation(base_values, up_values, down_values)
                
                process_name = key.split('_')[0]
                print(f"Process: {process_name}")
                print(f"Up Deviation: {up_deviation}")
                print(f"Down Deviation: {down_deviation}")
                print()

    root_file.Close()

if __name__ == "__main__":
    main()
