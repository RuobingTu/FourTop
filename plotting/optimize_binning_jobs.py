import os
import subprocess
import time

import argparse

def main():
    parser = argparse.ArgumentParser(description='Process two numbers.')
    
    parser.add_argument('num1', type=int, help='The first number')
    parser.add_argument('num2', type=int, help='The second number')
    
    # 解析参数
    args = parser.parse_args()
    
    # 获取参数值
    num1 = args.num1
    num2 = args.num2
    
    for mass in [num1]:
        for i in [num2]:
            file_path = "/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/writeHistGood/jobs/makeJob_forWriteHist_BDT.py"
            new_line_54 = f"    version = 'v0Basictraining1tau1l_VLLm{mass}0_{i}'\n"
            print(new_line_54)
            new_line_110 = f'''            run = './run_treeAnalyzer_{mass}0_{i}.out {{}} {{}} {{}} {{}} {{}}'.format(inputDir, iProcess, version, channel, isTest)\n'''
            print(new_line_110)
            # 读取文件并替换第36行
            with open(file_path, 'r') as file:
                lines = file.readlines()

            if len(lines) >= 110:
                lines[54] = new_line_54
                lines[110] = new_line_110

                with open(file_path, 'w') as file:
                    file.writelines(lines)
                print(f"Replaced line 36 and 50 in {file_path}")
            else:
                print(f"File {file_path} does not have 36 lines")
    

if __name__ == "__main__":
    main()

