import subprocess 
import os
import ROOT
#!set up Voms credentials first 
#!also cmsenv, for the xroot dependance wrong
import input.VLL_Charis as VLL_Charis
import sys

#!xroot -r for copying directory too slow


def copyDir():
    redirector = 'root://cms-xrd-global.cern.ch/'
    # redirector = ''
    #from Charis: https://gitlab.cern.ch/ckoraka/vll-analysis/-/blob/master/samples/fileLists/Signal_2018.py?ref_type=heads
    sampleDic = {
    # 'VLL_EE_M600': '/store/user/ckoraka/VLferm_EWcouplings_4321_m600GeV_EE_to_4b/RunIISummer20UL18_NanoAODv9/230718_212705/0000/',
    # 'VLL_EN_M600': '/store/user/ckoraka/VLferm_EWcouplings_4321_m600GeV_EN_to_4b/RunIISummer20UL18_NanoAODv9/230718_212731/0000/',
    # 'VLL_NN_M600': '/store/user/ckoraka/VLferm_EWcouplings_4321_m600GeV_NN_to_4b/RunIISummer20UL18_NanoAODv9/230718_212756/0000/',#done

    # 'VLL_EE_M650': '/store/user/ckoraka/VLferm_EWcouplings_4321_m650GeV_EE_to_4b/RunIISummer20UL18_NanoAODv9/230718_212823/0000/',
    # 'VLL_EN_M650': '/store/user/ckoraka/VLferm_EWcouplings_4321_m650GeV_EN_to_4b/RunIISummer20UL18_NanoAODv9/230718_212847/0000/',
    # 'VLL_NN_M650': '/store/user/ckoraka/VLferm_EWcouplings_4321_m650GeV_NN_to_4b/RunIISummer20UL18_NanoAODv9/230718_212915/0000/',#done

    'VLL_EE_M600': '/store/mc/RunIISummer20UL18NanoAODv9/VLferm_m600GeV_EE_to_4b_TuneCP5_13TeV-madgraph-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v2/2820000/',
    'VLL_EN_M600': '/store/mc/RunIISummer20UL18NanoAODv9/VLferm_m600GeV_EN_to_4b_TuneCP5_13TeV-madgraph-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v2/70000/',
    'VLL_NN_M600': '/store/mc/RunIISummer20UL18NanoAODv9/VLferm_m600GeV_NN_to_4b_TuneCP5_13TeV-madgraph-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v2/70000/',


    # 'VLL_EE_M800': '/store/user/ckoraka/VLferm_EWcouplings_4321_m800GeV_EE_to_4b/RunIISummer20UL18_NanoAODv9/230718_213240/0000/',
    # 'VLL_EN_M800': '/store/user/ckoraka/VLferm_EWcouplings_4321_m800GeV_EN_to_4b/RunIISummer20UL18_NanoAODv9/230718_213240/0000/',
    # 'VLL_NN_M800': '/store/user/ckoraka/VLferm_EWcouplings_4321_m800GeV_NN_to_4b/RunIISummer20UL18_NanoAODv9/230718_213240/0000/',



    }

    # redirector = 'root://cmsxrootd-cms.infn.it//'
    VLLfile = 'root://cmsxrootd.hep.wisc.edu///store/user/ckoraka/VLferm_EWcouplings_4321_m500GeV_EE_to_4b/RunIISummer20UL18_NanoAODv9/230718_212434/0000/NanoAODv9_10.root'

    # outDir = '/publicfs/cms/data/TopQuark/nanoAOD/2018/mc/VVL_600/' 
    outDir = '/publicfs/cms/data/TopQuark/Fourtop_VLL/2018/' 

    for isam, ifile in sampleDic.items():
        inputDir = redirector + ifile
        ioutDir = outDir + isam + '/'
        if not os.path.exists( ioutDir ):
            os.mkdir( ioutDir )
        # command = 'xrdcp -r ' + inputDir + ' ' + ioutDir
        command = 'xrdcp -r --parallel 3 ' + inputDir + ' ' + ioutDir
        # command = 'xrdcp -r --parallel 5 ' + inputDir + '*.root ' + ioutDir
        print(command)
        # process = subprocess.run([command], shell=True)
        # output =  process.stdout
        # print(output)
        
    # inputDir = redirector + sampleDic['VLL_EE_M600']
    # # command = 'xrdcp '+ VLLfile + ' ' + outDir #only works with CMSSW
    # command = 'xrdcp -r ' + inputDir + ' ' + outDir
    # print(command)
    # process = subprocess.run([command], shell=True)
    # output =  process.stdout
    # print(output)
    
def copySingleFile(number):
    for isam, ifile in VLL_Charis.filesetSignal.items():
        if not f"{number}" in isam: continue
        #if not 'NN' in isam: continue
        print(isam)
        outName = transform_string(isam) 
        # outDir = '/publicfs/cms/data/TopQuark/nanoAOD/2018/mc/VLL/' + outName + '/'
        outDir = '/publicfs/cms/data/TopQuark/Fourtop_VLL/2018/' + outName + '/'
        
        if not os.path.exists( outDir ):
            os.mkdir( outDir )
        print(outName)
        # if not outName == 'VLL_EE_M500': continue
        # if outName == 'VLL_EE_M500': continue
        
        #for inano in ifile:
        ## inputDir = redirector + inano
        #    command = f'xrdcp {inano} {outDir}'
        #    print(command)
        #    
        #    try:
        #        process = subprocess.run(command, shell=True, capture_output=True, text=True, timeout=300)
        #        output = process.stdout
        #        error = process.stderr
        #        returncode = process.returncode
        #        print(f"Output:\n{output}")
        #        print(f"Error:\n{error}")
        #        print(f"Return Code: {returncode}")
        #    except subprocess.TimeoutExpired:
        #        print(f"Command '{command}' timed out.")
        #    except Exception as e:
        #        print(f"An error occurred: {e}")

        for inano in ifile:
            # inputDir = redirector + inano
            command = 'xrdcp --verbose ' + inano + ' ' + outDir
            print(command)
            file_name = inano.split('/')[-1]
            if os.path.exists(outDir+file_name):
                root_file = ROOT.TFile.Open(outDir+file_name)
                if root_file.IsZombie():
                    print(f'rm {outDir+file_name}')
                    subprocess.run([f'rm {outDir+file_name}'], shell=True)
                else:
                    print(f"{file_name} exists!!!")
                    continue
            process = subprocess.run([command], shell=True)
            output =  process.stdout
            print(output)
        print('\n\n') 
        
        
        
        
        
def transform_string(input_str):
    # Split the string by underscores
    parts = input_str.split('_')
    # Extract the relevant parts
    prefix = parts[0] + '_' + parts[1]  # 'VLL_EE'
    mass_part = parts[2]  # 'M-500GeV'
        # Remove the hyphen and 'GeV'
    mass_value = mass_part.replace('-', '').replace('GeV', '')
    # Combine the parts
    # output_str = f"{prefix}_M{mass_value}"
    output_str = f"{prefix}_{mass_value}"
    return output_str
        
if __name__=='__main__':
    # copyDir()
    args = sys.argv
    if len(args) > 1:
        first_arg = args[1]
    copySingleFile(first_arg)


