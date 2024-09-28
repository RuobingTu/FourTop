import os
import subprocess

for mass in [75]:
    for i in [4]:
        file_path = "/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/writeHistGood/src/treeAnalyzer.C"
        new_line = f"        std::vector<Double_t> bins = {{-0.35, -0.2, -0.16, -0.12, -0.08, -0.04, 0, 0.0{i}, 0.21}}; //1tau1l Bin B\n"
        print(new_line)
        new_line_50 = f'''        weightfile = "/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM{mass}0/inputList_1tau1l_final25.csv/dataset/weight/TMVAClassification_BDT.weights.xml";\n'''
        print(new_line_50)
        # 读取文件并替换第36行
        with open(file_path, 'r') as file:
            lines = file.readlines()

        if len(lines) >= 49:
            lines[35] = new_line
            lines[49] = new_line_50

            with open(file_path, 'w') as file:
                file.writelines(lines)
            print(f"Replaced line 36 and 50 in {file_path}")
        else:
            print(f"File {file_path} does not have 36 lines")

        # 指定编译目录
        compile_dir = "/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/writeHistGood"

        # 编译命令
        commands = [
            ["make", "clean"],
            ["make"]
        ]
        for command in commands:
            subprocess.run(command, cwd=compile_dir, check=True)
        print("Compilation finished")

        # 重命名编译后的文件
        original_file = os.path.join(compile_dir, "apps/run_treeAnalyzer.out")
        renamed_file = os.path.join(compile_dir, f"apps/run_treeAnalyzer_{mass}0_{i}.out")

        if os.path.exists(original_file):
            os.rename(original_file, renamed_file)
            print(f"Renamed {original_file} to {renamed_file}")
        else:
            print(f"Compiled file {original_file} does not exist")
