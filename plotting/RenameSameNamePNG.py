#import os
#import shutil
#
## 指定远程文件路径模板
#remote_path_template = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2016postVFP/v0baselineHardroSR_v81addSysSum/mc/variableHists_v0Basictraining1tau1l_{}0_{}/results/1tau1lSR_BDT_logy_VLL_dataVsMC_v831S.png"
#
## 指定本地目录路径
#local_dir = "/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/plotting/tmppng/"
#
## 确保本地目录存在
#os.makedirs(local_dir, exist_ok=True)
#
## VLLm的范围
#vllm_values = ["VLLm50", "VLLm80", "VLLm85", "VLLm90", "VLLm95", "VLLm100"]
#
## 遍历VLLm值和04到8的路径并重命名
#for vllm in vllm_values:
#    for i in range(4, 9):
#        remote_path = remote_path_template.format(vllm, i)
#        if os.path.exists(remote_path):
#            # 构造新的文件名
#            new_filename = f"1tau1lSR_BDT_logy_VLL_dataVsMC_v831S_{vllm}_{i}.png"
#            new_filepath = os.path.join(local_dir, new_filename)
#            # 拷贝并重命名文件
#            shutil.copy2(remote_path, new_filepath)
#            print(f"Copied and renamed: {remote_path} -> {new_filepath}")
#        else:
#            print(f"File does not exist: {remote_path}")


#import os
#
#for mass in [50,55,60,65,70,75,80,85,90,95,100]:
#    for i in [4,5,6,7,8]:
#        file_path = f"/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2016postVFP/v0baselineHardroSR_v81addSysSum/mc/variableHists_v0Basictraining1tau1l_VLLm{mass}0_{i}/combine/datacard_mainSys/datacard_1tau1lNoSys.txt"
#        os.makedirs(os.path.dirname(file_path), exist_ok=True)
#        content = f'''imax * number of bins
#jmax * number of processes minus 1
#kmax * number of nuisance parameters
#----------------------------------------------------------------------------------------------------------------------------------
#shapes *   SR1tau1l_2016postVFP  /publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2016postVFP/v0baselineHardroSR_v81addSysSum/mc/variableHists_v0Basictraining1tau1l_VLLm{mass}0_{i}/combine/templatesForCombine1tau1l.root  $PROCESS_1tau1lSR_BDT $PROCESS_1tau1lSR_$SYSTEMATIC_BDT
#----------------------------------------------------------------------------------------------------------------------------------
#bin          SR1tau1l_2016postVFP
#observation  -1                 
#----------------------------------------------------------------------------------------------------------------------------------
#bin                                     SR1tau1l_2016postVFP  SR1tau1l_2016postVFP  SR1tau1l_2016postVFP  SR1tau1l_2016postVFP   SR1tau1l_2016postVFP  SR1tau1l_2016postVFP
#process                                 tttt           singleTop      tt             ttX             WJets          VLLm{mass}0
#process                                 5              1              2              3               4              0
#rate                                    -1             -1             -1             -1              -1             -1
#----------------------------------------------------------------------------------------------------------------------------------
#lumi_13TeV_2016postVFP lnN                     1.025          1.025          1.025          1.025           1.025          1
#CMS_pileup_2016postVFP shape                   1              1              1              1               1              1
#CMS_prefiring_2016postVFP shape                1              1              1              1               1              1
#CMS_eff_t_vsJet_2016postVFP shape              1              1              1              1               1              1
#CMS_eff_t_vsMu_2016postVFP shape               1              1              1              1               1              1
#CMS_eff_t_vsEle_2016postVFP shape              1              1              1              1               1              1
#CMS_tttt_eff_e_2016postVFP shape               1              1              1              1               1              1
#CMS_tttt_eff_m_2016postVFP shape               1              1              1              1               1              1
#CMS_tttt_eff_hlt_stats_2016postVFP shape       1              1              1              1               1              1
#CMS_eff_bWPMT_2016postVFP shape                1              1              1              1               1              1
#pdf_2016postVFP     shape                      1              -              1              1               1              1
#pdfAlphaS_normalised_2016postVFP shape         1              -              1              1               1              1
#QCDscale_Re_normalised_2016postVFP shape       1              1              1              1               1              1
#QCDscale_Fa_normalised_2016postVFP shape       1              1              1              1               1              1
#----------------------------------------------------------------------------------------------------------------------------------
#SR1tau1l_2016postVFP autoMCStats 10 0 1'''
#        # 向文件写入内容
#        with open(file_path, 'w') as file:
#            file.write(content)
#
#        print(f"Successfully wrote to {file_path}")

#import os
#
#directory = '/publicfs/cms/data/TopQuark/nanoAOD/2018/mc/WZTo3LNu/'
#
#root_files = [f for f in os.listdir(directory) if f.endswith('.root')]
#
#for i, root_file in enumerate(root_files):
#    new_name = f'outTree_{i}.root'
#    os.rename(os.path.join(directory, root_file), os.path.join(directory, new_name))
#    print(f'Renamed {root_file} to {new_name}')




#import os
#
## 指定目录路径
#base_dir = "/afs/ihep.ac.cn/users/t/turuobing/AN-20-175/forMVA/VLL_2018/BDTTrain"
#
#for i in range(500, 1001, 50):
#    dir_name = f"VLLM{i}"
#    dir_path = os.path.join(base_dir, dir_name)
#
#    if not os.path.exists(dir_path):
#        os.mkdir(dir_path)
#        print(f"Created directory: {dir_name}")
#    else:
#        print(f"Directory {dir_name} already exists")
#

import os
import shutil
#2016postVFP
# 源目录和目标目录的路径模板
source_template = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2017/v0baselineHardroSR_v81addSysSum/mc/variableHists_v0Basictraining1tau1l_VLLm{mass}_{binning}/combine/datacard_mainSys/combineResults/impactResult/impacts.pdf"
#source_template = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v2cut1tau1lCR1TauF_v76WithVLLAllMassOfficial/mc/variableHists_v0BasicBDTtraining1tau1l_VLLm"
#source_template = "/publicfs/cms/user/turuobing/tauOfTTTT_NanoAODOfficial/forMVA/2018/v0baselineHardroCR1_v81addSysSum/mc/variableHists_v0BasicBDTtraining1tau1l_VLLm{mass}/results/1tau1lCR1_BDT_logy_VLL_dataVsMC_v831S.png"
destination_template = "/afs/ihep.ac.cn/users/t/turuobing/AN-20-175/forMVA/VLL_2017/BDTTrain/VLLM{mass}"

# 质量范围
mass_range = range(500, 1001, 50)

for mass in mass_range:
    if mass in [500,550,650,750,950]:
        binning = 4
    elif mass in [700,800,850,900,1000]:
        binning = 5
    else:
        binning = 6
    source_file = source_template.format(mass=mass, binning = binning)
    #source_file = source_template.format(mass=mass)
    destination_dir = destination_template.format(mass=mass)
    
    # 确保目标目录存在
    os.makedirs(destination_dir, exist_ok=True)
    
    # 目标文件路径
    destination_file = os.path.join(destination_dir, os.path.basename(source_file))
    
    # 拷贝文件
    if os.path.exists(source_file):
        shutil.copy2(source_file, destination_file)
        print(f"Copied {source_file} to {destination_file}")
    else:
        print(f"Source file {source_file} does not exist")
