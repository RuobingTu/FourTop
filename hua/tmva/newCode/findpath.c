#include <TFile.h>
#include <TKey.h>
#include <TClass.h>
#include <iostream>
#include <vector>

// 递归函数，用于遍历文件中的所有对象
void printKeys(TDirectory* dir, const std::string& path = "") {
    TIter next(dir->GetListOfKeys());
    TKey* key;
    while ((key = (TKey*)next())) {
        std::string className = key->GetClassName();
        std::string keyName = key->GetName();
        std::string fullPath = path.empty() ? keyName : path + "/" + keyName;
        std::cout << fullPath << std::endl;
        
        // 如果对象是TDirectory类型，则递归调用
        if (className == "TDirectoryFile" || className == "TDirectory") {
            TDirectory* subdir = (TDirectory*)key->ReadObj();
            printKeys(subdir, fullPath);
        }
    }
}

int findpath() {
    // 打开ROOT文件
    TFile* file = TFile::Open("/afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root");
    if (!file || file->IsZombie()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // 打印所有路径
    printKeys(file);

    // 关闭文件
    file->Close();
    delete file;

    return 0;
}

