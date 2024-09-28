import ROOT
import numpy as np
import matplotlib.pyplot as plt

year = '2018'
ProcessNames = ['VLLm600','tt', 'ttX', 'singleTop', 'WJets', 'tttt']
SystematicsNames = [
    '_CMS_pileup_',
    '_CMS_prefiring_',
    '_CMS_eff_t_vsJet_',
    '_CMS_eff_t_vsMu_',
    '_CMS_eff_t_vsEle_',
    '_CMS_tttt_eff_e_',
    '_CMS_tttt_eff_m_',
    '_CMS_btag_shape_jes_',
    '_CMS_btag_shape_hf_',
    '_CMS_btag_shape_lf_',
    '_CMS_btag_shape_hfstats1_',
    '_CMS_btag_shape_hfstats2_',
    '_CMS_btag_shape_lfstats1_',
    '_CMS_btag_shape_lfstats2_',
    '_CMS_btag_shape_cferr1_',
    '_CMS_btag_shape_cferr2_',
    '_CMS_eff_bWPM_',
    '_CMS_eff_bWPMT_',
    '_CMS_tau_FR_',
    '_CMS_tttt_eff_hlt_stats_',
    '_pdf_',
    '_pdfAlphaS_',
    '_QCDscale_Re_',
    '_QCDscale_Fa_',
    '_QCDscale_Re_normalised_',
    '_QCDscale_Fa_normalised_',
    '_pdfAlphaS_normalised_'
]


def getContextForBin(histogram, n_bins):
    bin_content = np.array([])
    bin_error = np.array([])
    for i in range(1, n_bins + 1):
        bin_content = np.append(bin_content, histogram.GetBinContent(i))
        bin_error = np.append(bin_error, histogram.GetBinError(i))
    return bin_content, bin_error

def StartPlotiing(file_path, base_name, up_name, down_name):
    root_file = ROOT.TFile.Open(file_path)

    bin_edges = np.array([-0.35, -0.2, -0.16, -0.12, -0.08, -0.04, 0, 0.06, 0.21])
    bin_widths = np.diff(bin_edges)
    bin_centers = bin_edges[:-1] + bin_widths / 2
    n_bins = bin_edges.size -1
    fig, ax = plt.subplots(figsize=(8, 6))
    if len(bin_centers) != len(bin_widths):
        raise ValueError("bin_centers and bin_widths must have the same length")

    for hist_name in [base_name, up_name, down_name]:
        hist = root_file.Get(hist_name)
        bin, error_bar = getContextForBin(hist, n_bins)
        if hist_name == base_name:
            ax.bar(bin_centers, bin, yerr=error_bar, align='center', width=bin_widths, label='Nominal', color='black', capsize=0, alpha=0.5)
            #ax.errorbar(bin_edges, bin, yerr=error_bar, fmt='_', label='Nominal', color='black', capsize=0)
        elif hist_name == up_name:
            ax.bar(bin_centers, bin, yerr=error_bar, align='center', width=bin_widths, label='Up variation', color='red', capsize=0, alpha=0.5)
            #ax.errorbar(bin_edges, bin, yerr=error_bar, fmt='_', label='Up variation', color='red', capsize=0)
        else:
            ax.bar(bin_centers, bin, yerr=error_bar, align='center', width=bin_widths, label='Down variation', color='blue', capsize=0, alpha=0.5)
            #ax.errorbar(bin_edges, bin, yerr=error_bar, fmt='_', label='Down variation', color='blue', capsize=0)

    ax.set_xlabel(r'$BDT$')
    ax.set_ylabel('Value')
    ax.set_yscale('log')  # If you want a logarithmic scale
    ax.legend()
    ax_ratio = fig.add_subplot(212)
    bin_up, error_bar_up = getContextForBin(root_file.Get(up_name), n_bins)
    bin_down, error_bar_up = getContextForBin(root_file.Get(down_name), n_bins)
    bin_base, error_bar_up = getContextForBin(root_file.Get(base_name), n_bins)

    mask = bin_base != 0                #to avoid invalid value encountered in true_divide
    ratio_up = np.zeros_like(bin_base)
    ratio_down = np.zeros_like(bin_base)
    ratio_up[mask] = bin_up[mask] / bin_base[mask]
    ratio_down[mask] = bin_down[mask] / bin_base[mask]

    ax_ratio.plot(bin_centers, ratio_up, marker='_', color='red')
    ax_ratio.plot(bin_centers, ratio_down, marker='_', color='blue')
    ax_ratio.axhline(1, color='gray', linestyle='--')  # y=1 line
    ax_ratio.set_xlabel(r'$BDT$')
    ax_ratio.set_ylabel('Ratio')
    ax_ratio.set_ylim(0.8, 1.2)  # Set limits for better visibility
    plt.savefig(f"/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/plotting/TemplatCheckPlot/{up_name}.pdf", format='pdf')


def main():
    file_path = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v0baselineHardroSR_v81addSysSum/mc/variableHists_v0Basictraining1tau1l_VLLm600_6/combine/templatesForCombine1tau1l.root"
    # root_file = ROOT.TFile.Open(file_path)
    # raw_histogram = root_file.GetListOfKeys()
    # name_histogram = [key.ReadObj().GetName() for key in raw_histogram]
    bin_edges = np.array([-0.35, -0.2, -0.16, -0.12, -0.08, -0.04, 0, 0.06, 0.21])
    n_bins = bin_edges.size
    for ProcessName in ProcessNames:
        for SystematicsName in SystematicsNames:
            base_name = ProcessName + '_1tau1lSR_BDT'
            up_name = f'{ProcessName}_1tau1lSR{SystematicsName}{year}Up_BDT'
            down_name = f'{ProcessName}_1tau1lSR{SystematicsName}{year}Down_BDT'
            StartPlotiing(file_path, base_name, up_name, down_name)

if __name__ == "__main__":
    main()