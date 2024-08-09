#include <TMVA/Tools.h>
#include <TMVA/Types.h>
#include <iostream>

void listTMVAMethodTypes() {
    TMVA::Tools::Instance();  // Initialize TMVA

    TMVA::Types::EMVA method = TMVA::Types::kMaxMethod;
    for (int i = 0; i < method; ++i) {
        try {
            TString methodName = TMVA::Types::Instance().GetMethodName(TMVA::Types::EMVA(i));
            std::cout << "Method: " << methodName << std::endl;
        } catch (const std::runtime_error& e) {
            std::cerr << "Error retrieving method name for index " << i << ": " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Unknown error retrieving method name for index " << i << std::endl;
        }
    }
}

