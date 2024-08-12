                         :   12 : bjetsM_tausT_minDeltaR       : 3.616e-02
                         :   13 : bjetsT_2pt                   : 3.532e-02
                         :   14 : tausT_invariantMass          : 3.493e-02
                         :   15 : bjetsM_3pt                   : 3.487e-02
                         :   16 : bjetsT_2MET_stransMass       : 3.473e-02
                         :   17 : bjetsM_2MET_stransMass       : 3.471e-02
                         :   18 : muonsTopMVAT_1pt             : 3.288e-02
                         :   19 : jets_invariantMass           : 3.213e-02
                         :   20 : jets_5pt                     : 3.093e-02
                         :   21 : jets_3pt                     : 3.078e-02
                         :   22 : bjetsM_transMass             : 2.983e-02
                         :   23 : jets_1pt                     : 2.959e-02
                         :   24 : jets_HT                      : 2.957e-02
                         :   25 : bjetsT_1pt                   : 2.887e-02
                         :   26 : bjetsM_2tauF1lep1_stransMass : 2.876e-02
                         :   27 : bjetsM_1pt                   : 2.371e-02
                         :   28 : tausT_1lepton1_charge        : 1.751e-02
                         :   29 : jets_HTDivideMET             : 1.494e-02
                         : --------------------------------------------------------------
Factory                  : === Destroy and recreate all methods via weight files for testing ===
                         : 
                         : Reading weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_3_40.weights.xml
Factory                  : Test all methods
Factory                  : Test method: BDT_1000_7.5%_3_40 for Classification performance
                         : 
BDT_1000_7.5%_3_40       : [dataset] : Evaluation of BDT_1000_7.5%_3_40 on testing sample (55722 events)
                         : Elapsed time for evaluation of 55722 events: 3.2 sec       
Factory                  : Evaluate all methods
Factory                  : Evaluate classifier: BDT_1000_7.5%_3_40
                         : 
BDT_1000_7.5%_3_40       : [dataset] : Loop over test events and fill histograms with classifier response...
                         : 
TFHandler_BDT_1000_7.5...:                     Variable                            Mean                            RMS                    [        Min                            Max ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         :              jets_centrality:                       0.66184                       0.14677   [                       0.25830                        1.6941 ]
                         :                    tausT_1pt:                        55.640                        47.526   [                        20.000                        984.77 ]
                         :     jets_4largestBscoreMulti:                       0.27311                       0.22084   [                      0.023488                       0.99902 ]
                         :          jets_average_deltaR:                        2.2835                       0.25032   [                        1.2375                        3.2147 ]
                         :             bjetsM_transMass:                        429.62                        217.90   [                        91.218                        2692.0 ]
                         :                   bjetsT_2pt:                        46.498                        87.749   [                       -99.000                        1060.1 ]
                         :                   bjetsM_3pt:                        60.994                        30.463   [                        25.001                        537.35 ]
                         :                   bjetsT_1pt:                        153.47                        107.25   [                       -99.000                        1469.2 ]
                         :                   jets_1btag:                       0.37116                       0.40735   [                     0.0012627                       0.99951 ]
                         :                   bjetsM_1pt:                        198.97                        132.93   [                        31.638                        1589.2 ]
                         :       bjetsT_2MET_stransMass:                        28.906                        80.275   [                       -99.000                        649.60 ]
                         :              jets_sphericity:                       0.31512                       0.18858   [                     0.0038355                       0.95594 ]
                         : bjetsM_2tauF1lep1_stransMass:                        336.90                        224.25   [                        33.174                        3079.5 ]
                         :                     jets_MHT:                        189.49                        141.38   [                        1.0507                        1621.6 ]
                         :                      jets_HT:                        860.93                        323.02   [                        480.06                        3642.0 ]
                         :       bjetsM_2MET_stransMass:                        69.031                        53.447   [                        6.4940                        695.49 ]
                         :                     jets_3pt:                        121.48                        50.177   [                        45.026                        671.09 ]
                         :             bjetsM_minDeltaR:                        1.3098                       0.58987   [                       0.39310                        3.4579 ]
                         :           jets_invariantMass:                        1354.9                        557.86   [                        445.13                        5625.0 ]
                         :                     jets_1pt:                        274.17                        165.14   [                        63.318                        1797.0 ]
                         :                     jets_5pt:                        72.532                        24.422   [                        33.693                        382.51 ]
                         :                   jets_7btag:                       0.28253                       0.36859   [                     0.0014009                       0.99951 ]
                         :     bjetsM_leptons_minDeltaR:                        1.2626                       0.58420   [                       0.40045                        4.0134 ]
                         :       bjetsM_tausT_minDeltaR:                        1.2540                       0.58063   [                       0.40037                        4.0072 ]
                         :        tausT_1lepton1_deltaR:                        2.1411                       0.86478   [                       0.40055                        5.4321 ]
                         :             muonsTopMVAT_1pt:                       -10.142                        96.590   [                       -99.000                        933.77 ]
                         :          tausT_invariantMass:                       0.72529                       0.44708   [                       0.13953                        11.109 ]
                         :             jets_HTDivideMET:                        2.2884                        4.3950   [                      0.011409                        603.42 ]
                         :        tausT_1lepton1_charge:                      -0.56102                       0.82780   [                       -1.0000                        1.0000 ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         : 
                         : <PlotVariables> Will not produce scatter plots ==> 
                         : |  The number of 29 input variables and 0 target values would require 406 two-dimensional
                         : |  histograms, which would occupy the computer's memory. Note that this
                         : |  suppression does not have any consequences for your analysis, other
                         : |  than not disposing of these scatter plots. You can modify the maximum
                         : |  number of input variables allowed to generate scatter plots in your
                         : |  script via the command line:
                         : |  "(TMVA::gConfig().GetVariablePlotting()).fMaxNumOfAllowedVariablesForScatterPlots = <some int>;"
                         : 
                         : Some more output
                         : 
                         : Evaluation results ranked by best signal efficiency and purity (area)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet       MVA                       
                         : Name:         Method:          ROC-integ
                         : dataset       BDT_1000_7.5%_3_40: 0.896
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
                         : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample) 
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30   
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT_1000_7.5%_3_40: 0.271 (0.367)       0.692 (0.759)      0.896 (0.918)
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
Dataset:dataset          : Created tree 'TestTree' with 55722 events
                         : 
Dataset:dataset          : Created tree 'TrainTree' with 89580 events
                         : 
Factory                  : Thank you for using TMVA!
                         : For citation information, please visit: http://tmva.sf.net/citeTMVA.html
TFile**         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
 TFile*         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
  KEY: TDirectoryFile   dataset;1       dataset
0.896093
Factory                  : Booking method: BDT_1000_7.5%_4_20
                         : 
Factory                  : Train all methods
Factory                  : Train method: BDT_1000_7.5%_4_20 for Classification
                         : 
<WARNING>                : Events with negative event weights are USED during the BDT training. This might cause problems with small node sizes or with the boosting. Please remove negative events from training using the option *IgnoreEventsWithNegWeightsInTraining* in case you observe problems with the boosting
BDT_1000_7.5%_4_20       : #events: (reweighted) sig: 44790 bkg: 44790
                         : #events: (unweighted) sig: 4009 bkg: 85571
                         : Training 1000 Decision Trees ... patience please
                         : Elapsed time for training with 89580 events: 55.9 sec         
BDT_1000_7.5%_4_20       : [dataset] : Evaluation of BDT_1000_7.5%_4_20 on training sample (89580 events)
                         : Elapsed time for evaluation of 89580 events: 9.14 sec       
                         : Creating xml weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_4_20.weights.xml
                         : Creating standalone class: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight//TMVAClassification_BDT_1000_7.5%_4_20.class.C
                         : /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root:/dataset/Method_BDT/BDT_1000_7.5%_4_20
Factory                  : Training finished
                         : 
                         : Ranking input variables (method specific)...
BDT_1000_7.5%_4_20       : Ranking result (top variable is best ranked)
                         : --------------------------------------------------------------
                         : Rank : Variable                     : Variable Importance
                         : --------------------------------------------------------------
                         :    1 : jets_4largestBscoreMulti     : 5.144e-02
                         :    2 : jets_sphericity              : 4.793e-02
                         :    3 : tausT_1lepton1_deltaR        : 4.526e-02
                         :    4 : bjetsM_minDeltaR             : 4.525e-02
                         :    5 : tausT_1pt                    : 4.378e-02
                         :    6 : jets_1btag                   : 4.355e-02
                         :    7 : jets_centrality              : 4.205e-02
                         :    8 : jets_7btag                   : 3.875e-02
                         :    9 : bjetsM_3pt                   : 3.853e-02
                         :   10 : jets_average_deltaR          : 3.799e-02
                         :   11 : jets_MHT                     : 3.772e-02
                         :   12 : tausT_invariantMass          : 3.635e-02
                         :   13 : bjetsM_leptons_minDeltaR     : 3.623e-02
                         :   14 : bjetsM_2MET_stransMass       : 3.469e-02
                         :   15 : muonsTopMVAT_1pt             : 3.441e-02
                         :   16 : bjetsT_2pt                   : 3.352e-02
                         :   17 : bjetsM_tausT_minDeltaR       : 3.342e-02
                         :   18 : bjetsT_2MET_stransMass       : 3.333e-02
                         :   19 : jets_3pt                     : 3.190e-02
                         :   20 : bjetsM_transMass             : 3.151e-02
                         :   21 : jets_invariantMass           : 3.148e-02
                         :   22 : jets_5pt                     : 3.119e-02
                         :   23 : jets_HT                      : 3.039e-02
                         :   24 : bjetsM_2tauF1lep1_stransMass : 2.851e-02
                         :   25 : bjetsT_1pt                   : 2.727e-02
                         :   26 : jets_1pt                     : 2.680e-02
                         :   27 : bjetsM_1pt                   : 2.576e-02
                         :   28 : tausT_1lepton1_charge        : 1.773e-02
                         :   29 : jets_HTDivideMET             : 3.279e-03
                         : --------------------------------------------------------------
Factory                  : === Destroy and recreate all methods via weight files for testing ===
                         : 
                         : Reading weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_4_20.weights.xml
Factory                  : Test all methods
Factory                  : Test method: BDT_1000_7.5%_4_20 for Classification performance
                         : 
BDT_1000_7.5%_4_20       : [dataset] : Evaluation of BDT_1000_7.5%_4_20 on testing sample (55722 events)
                         : Elapsed time for evaluation of 55722 events: 3.89 sec       
Factory                  : Evaluate all methods
Factory                  : Evaluate classifier: BDT_1000_7.5%_4_20
                         : 
BDT_1000_7.5%_4_20       : [dataset] : Loop over test events and fill histograms with classifier response...
                         : 
TFHandler_BDT_1000_7.5...:                     Variable                            Mean                            RMS                    [        Min                            Max ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         :              jets_centrality:                       0.66184                       0.14677   [                       0.25830                        1.6941 ]
                         :                    tausT_1pt:                        55.640                        47.526   [                        20.000                        984.77 ]
                         :     jets_4largestBscoreMulti:                       0.27311                       0.22084   [                      0.023488                       0.99902 ]
                         :          jets_average_deltaR:                        2.2835                       0.25032   [                        1.2375                        3.2147 ]
                         :             bjetsM_transMass:                        429.62                        217.90   [                        91.218                        2692.0 ]
                         :                   bjetsT_2pt:                        46.498                        87.749   [                       -99.000                        1060.1 ]
                         :                   bjetsM_3pt:                        60.994                        30.463   [                        25.001                        537.35 ]
                         :                   bjetsT_1pt:                        153.47                        107.25   [                       -99.000                        1469.2 ]
                         :                   jets_1btag:                       0.37116                       0.40735   [                     0.0012627                       0.99951 ]
                         :                   bjetsM_1pt:                        198.97                        132.93   [                        31.638                        1589.2 ]
                         :       bjetsT_2MET_stransMass:                        28.906                        80.275   [                       -99.000                        649.60 ]
                         :              jets_sphericity:                       0.31512                       0.18858   [                     0.0038355                       0.95594 ]
                         : bjetsM_2tauF1lep1_stransMass:                        336.90                        224.25   [                        33.174                        3079.5 ]
                         :                     jets_MHT:                        189.49                        141.38   [                        1.0507                        1621.6 ]
                         :                      jets_HT:                        860.93                        323.02   [                        480.06                        3642.0 ]
                         :       bjetsM_2MET_stransMass:                        69.031                        53.447   [                        6.4940                        695.49 ]
                         :                     jets_3pt:                        121.48                        50.177   [                        45.026                        671.09 ]
                         :             bjetsM_minDeltaR:                        1.3098                       0.58987   [                       0.39310                        3.4579 ]
                         :           jets_invariantMass:                        1354.9                        557.86   [                        445.13                        5625.0 ]
                         :                     jets_1pt:                        274.17                        165.14   [                        63.318                        1797.0 ]
                         :                     jets_5pt:                        72.532                        24.422   [                        33.693                        382.51 ]
                         :                   jets_7btag:                       0.28253                       0.36859   [                     0.0014009                       0.99951 ]
                         :     bjetsM_leptons_minDeltaR:                        1.2626                       0.58420   [                       0.40045                        4.0134 ]
                         :       bjetsM_tausT_minDeltaR:                        1.2540                       0.58063   [                       0.40037                        4.0072 ]
                         :        tausT_1lepton1_deltaR:                        2.1411                       0.86478   [                       0.40055                        5.4321 ]
                         :             muonsTopMVAT_1pt:                       -10.142                        96.590   [                       -99.000                        933.77 ]
                         :          tausT_invariantMass:                       0.72529                       0.44708   [                       0.13953                        11.109 ]
                         :             jets_HTDivideMET:                        2.2884                        4.3950   [                      0.011409                        603.42 ]
                         :        tausT_1lepton1_charge:                      -0.56102                       0.82780   [                       -1.0000                        1.0000 ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         : 
                         : <PlotVariables> Will not produce scatter plots ==> 
                         : |  The number of 29 input variables and 0 target values would require 406 two-dimensional
                         : |  histograms, which would occupy the computer's memory. Note that this
                         : |  suppression does not have any consequences for your analysis, other
                         : |  than not disposing of these scatter plots. You can modify the maximum
                         : |  number of input variables allowed to generate scatter plots in your
                         : |  script via the command line:
                         : |  "(TMVA::gConfig().GetVariablePlotting()).fMaxNumOfAllowedVariablesForScatterPlots = <some int>;"
                         : 
                         : Some more output
                         : 
                         : Evaluation results ranked by best signal efficiency and purity (area)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet       MVA                       
                         : Name:         Method:          ROC-integ
                         : dataset       BDT_1000_7.5%_4_20: 0.898
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
                         : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample) 
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30   
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT_1000_7.5%_4_20: 0.260 (0.357)       0.711 (0.746)      0.907 (0.914)
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
Dataset:dataset          : Created tree 'TestTree' with 55722 events
                         : 
Dataset:dataset          : Created tree 'TrainTree' with 89580 events
                         : 
Factory                  : Thank you for using TMVA!
                         : For citation information, please visit: http://tmva.sf.net/citeTMVA.html
TFile**         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
 TFile*         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
  KEY: TDirectoryFile   dataset;1       dataset
0.897441
Factory                  : Booking method: BDT_1000_7.5%_4_30
                         : 
Factory                  : Train all methods
Factory                  : Train method: BDT_1000_7.5%_4_30 for Classification
                         : 
<WARNING>                : Events with negative event weights are USED during the BDT training. This might cause problems with small node sizes or with the boosting. Please remove negative events from training using the option *IgnoreEventsWithNegWeightsInTraining* in case you observe problems with the boosting
BDT_1000_7.5%_4_30       : #events: (reweighted) sig: 44790 bkg: 44790
                         : #events: (unweighted) sig: 4009 bkg: 85571
                         : Training 1000 Decision Trees ... patience please
                         : Elapsed time for training with 89580 events: 54.2 sec         
BDT_1000_7.5%_4_30       : [dataset] : Evaluation of BDT_1000_7.5%_4_30 on training sample (89580 events)
                         : Elapsed time for evaluation of 89580 events: 9.2 sec       
                         : Creating xml weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_4_30.weights.xml
                         : Creating standalone class: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight//TMVAClassification_BDT_1000_7.5%_4_30.class.C
                         : /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root:/dataset/Method_BDT/BDT_1000_7.5%_4_30
Factory                  : Training finished
                         : 
                         : Ranking input variables (method specific)...
BDT_1000_7.5%_4_30       : Ranking result (top variable is best ranked)
                         : --------------------------------------------------------------
                         : Rank : Variable                     : Variable Importance
                         : --------------------------------------------------------------
                         :    1 : jets_4largestBscoreMulti     : 5.294e-02
                         :    2 : bjetsM_minDeltaR             : 4.606e-02
                         :    3 : jets_sphericity              : 4.414e-02
                         :    4 : tausT_1lepton1_deltaR        : 4.290e-02
                         :    5 : tausT_1pt                    : 4.248e-02
                         :    6 : jets_1btag                   : 4.056e-02
                         :    7 : jets_centrality              : 4.048e-02
                         :    8 : jets_MHT                     : 3.916e-02
                         :    9 : jets_7btag                   : 3.891e-02
                         :   10 : bjetsM_leptons_minDeltaR     : 3.649e-02
                         :   11 : tausT_invariantMass          : 3.572e-02
                         :   12 : jets_average_deltaR          : 3.546e-02
                         :   13 : bjetsM_3pt                   : 3.534e-02
                         :   14 : bjetsM_tausT_minDeltaR       : 3.534e-02
                         :   15 : jets_3pt                     : 3.529e-02
                         :   16 : muonsTopMVAT_1pt             : 3.490e-02
                         :   17 : bjetsT_2pt                   : 3.482e-02
                         :   18 : bjetsT_2MET_stransMass       : 3.377e-02
                         :   19 : bjetsM_2MET_stransMass       : 3.316e-02
                         :   20 : jets_5pt                     : 3.203e-02
                         :   21 : jets_invariantMass           : 3.201e-02
                         :   22 : bjetsT_1pt                   : 3.068e-02
                         :   23 : bjetsM_transMass             : 3.043e-02
                         :   24 : bjetsM_2tauF1lep1_stransMass : 3.029e-02
                         :   25 : jets_HT                      : 2.965e-02
                         :   26 : jets_1pt                     : 2.659e-02
                         :   27 : bjetsM_1pt                   : 2.162e-02
                         :   28 : tausT_1lepton1_charge        : 1.724e-02
                         :   29 : jets_HTDivideMET             : 1.155e-02
                         : --------------------------------------------------------------
Factory                  : === Destroy and recreate all methods via weight files for testing ===
                         : 
                         : Reading weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_4_30.weights.xml
Factory                  : Test all methods
Factory                  : Test method: BDT_1000_7.5%_4_30 for Classification performance
                         : 
BDT_1000_7.5%_4_30       : [dataset] : Evaluation of BDT_1000_7.5%_4_30 on testing sample (55722 events)
                         : Elapsed time for evaluation of 55722 events: 3.9 sec       
Factory                  : Evaluate all methods
Factory                  : Evaluate classifier: BDT_1000_7.5%_4_30
                         : 
BDT_1000_7.5%_4_30       : [dataset] : Loop over test events and fill histograms with classifier response...
                         : 
TFHandler_BDT_1000_7.5...:                     Variable                            Mean                            RMS                    [        Min                            Max ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         :              jets_centrality:                       0.66184                       0.14677   [                       0.25830                        1.6941 ]
                         :                    tausT_1pt:                        55.640                        47.526   [                        20.000                        984.77 ]
                         :     jets_4largestBscoreMulti:                       0.27311                       0.22084   [                      0.023488                       0.99902 ]
                         :          jets_average_deltaR:                        2.2835                       0.25032   [                        1.2375                        3.2147 ]
                         :             bjetsM_transMass:                        429.62                        217.90   [                        91.218                        2692.0 ]
                         :                   bjetsT_2pt:                        46.498                        87.749   [                       -99.000                        1060.1 ]
                         :                   bjetsM_3pt:                        60.994                        30.463   [                        25.001                        537.35 ]
                         :                   bjetsT_1pt:                        153.47                        107.25   [                       -99.000                        1469.2 ]
                         :                   jets_1btag:                       0.37116                       0.40735   [                     0.0012627                       0.99951 ]
                         :                   bjetsM_1pt:                        198.97                        132.93   [                        31.638                        1589.2 ]
                         :       bjetsT_2MET_stransMass:                        28.906                        80.275   [                       -99.000                        649.60 ]
                         :              jets_sphericity:                       0.31512                       0.18858   [                     0.0038355                       0.95594 ]
                         : bjetsM_2tauF1lep1_stransMass:                        336.90                        224.25   [                        33.174                        3079.5 ]
                         :                     jets_MHT:                        189.49                        141.38   [                        1.0507                        1621.6 ]
                         :                      jets_HT:                        860.93                        323.02   [                        480.06                        3642.0 ]
                         :       bjetsM_2MET_stransMass:                        69.031                        53.447   [                        6.4940                        695.49 ]
                         :                     jets_3pt:                        121.48                        50.177   [                        45.026                        671.09 ]
                         :             bjetsM_minDeltaR:                        1.3098                       0.58987   [                       0.39310                        3.4579 ]
                         :           jets_invariantMass:                        1354.9                        557.86   [                        445.13                        5625.0 ]
                         :                     jets_1pt:                        274.17                        165.14   [                        63.318                        1797.0 ]
                         :                     jets_5pt:                        72.532                        24.422   [                        33.693                        382.51 ]
                         :                   jets_7btag:                       0.28253                       0.36859   [                     0.0014009                       0.99951 ]
                         :     bjetsM_leptons_minDeltaR:                        1.2626                       0.58420   [                       0.40045                        4.0134 ]
                         :       bjetsM_tausT_minDeltaR:                        1.2540                       0.58063   [                       0.40037                        4.0072 ]
                         :        tausT_1lepton1_deltaR:                        2.1411                       0.86478   [                       0.40055                        5.4321 ]
                         :             muonsTopMVAT_1pt:                       -10.142                        96.590   [                       -99.000                        933.77 ]
                         :          tausT_invariantMass:                       0.72529                       0.44708   [                       0.13953                        11.109 ]
                         :             jets_HTDivideMET:                        2.2884                        4.3950   [                      0.011409                        603.42 ]
                         :        tausT_1lepton1_charge:                      -0.56102                       0.82780   [                       -1.0000                        1.0000 ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         : 
                         : <PlotVariables> Will not produce scatter plots ==> 
                         : |  The number of 29 input variables and 0 target values would require 406 two-dimensional
                         : |  histograms, which would occupy the computer's memory. Note that this
                         : |  suppression does not have any consequences for your analysis, other
                         : |  than not disposing of these scatter plots. You can modify the maximum
                         : |  number of input variables allowed to generate scatter plots in your
                         : |  script via the command line:
                         : |  "(TMVA::gConfig().GetVariablePlotting()).fMaxNumOfAllowedVariablesForScatterPlots = <some int>;"
                         : 
                         : Some more output
                         : 
                         : Evaluation results ranked by best signal efficiency and purity (area)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet       MVA                       
                         : Name:         Method:          ROC-integ
                         : dataset       BDT_1000_7.5%_4_30: 0.896
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
                         : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample) 
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30   
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT_1000_7.5%_4_30: 0.287 (0.405)       0.722 (0.762)      0.889 (0.917)
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
Dataset:dataset          : Created tree 'TestTree' with 55722 events
                         : 
Dataset:dataset          : Created tree 'TrainTree' with 89580 events
                         : 
Factory                  : Thank you for using TMVA!
                         : For citation information, please visit: http://tmva.sf.net/citeTMVA.html
TFile**         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
 TFile*         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
  KEY: TDirectoryFile   dataset;1       dataset
0.896543
Factory                  : Booking method: BDT_1000_7.5%_4_40
                         : 
Factory                  : Train all methods
Factory                  : Train method: BDT_1000_7.5%_4_40 for Classification
                         : 
<WARNING>                : Events with negative event weights are USED during the BDT training. This might cause problems with small node sizes or with the boosting. Please remove negative events from training using the option *IgnoreEventsWithNegWeightsInTraining* in case you observe problems with the boosting
BDT_1000_7.5%_4_40       : #events: (reweighted) sig: 44790 bkg: 44790
                         : #events: (unweighted) sig: 4009 bkg: 85571
                         : Training 1000 Decision Trees ... patience please
                         : Elapsed time for training with 89580 events: 55 sec         
BDT_1000_7.5%_4_40       : [dataset] : Evaluation of BDT_1000_7.5%_4_40 on training sample (89580 events)
                         : Elapsed time for evaluation of 89580 events: 9.27 sec       
                         : Creating xml weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_4_40.weights.xml
                         : Creating standalone class: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight//TMVAClassification_BDT_1000_7.5%_4_40.class.C
                         : /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root:/dataset/Method_BDT/BDT_1000_7.5%_4_40
Factory                  : Training finished
                         : 
                         : Ranking input variables (method specific)...
BDT_1000_7.5%_4_40       : Ranking result (top variable is best ranked)
                         : --------------------------------------------------------------
                         : Rank : Variable                     : Variable Importance
                         : --------------------------------------------------------------
                         :    1 : jets_4largestBscoreMulti     : 5.150e-02
                         :    2 : bjetsM_minDeltaR             : 4.541e-02
                         :    3 : tausT_1lepton1_deltaR        : 4.536e-02
                         :    4 : jets_sphericity              : 4.413e-02
                         :    5 : tausT_1pt                    : 4.297e-02
                         :    6 : jets_1btag                   : 4.213e-02
                         :    7 : jets_centrality              : 4.190e-02
                         :    8 : jets_MHT                     : 3.789e-02
                         :    9 : bjetsM_3pt                   : 3.761e-02
                         :   10 : jets_average_deltaR          : 3.743e-02
                         :   11 : jets_7btag                   : 3.731e-02
                         :   12 : bjetsM_leptons_minDeltaR     : 3.691e-02
                         :   13 : tausT_invariantMass          : 3.606e-02
                         :   14 : bjetsM_2MET_stransMass       : 3.460e-02
                         :   15 : bjetsT_2pt                   : 3.455e-02
                         :   16 : bjetsT_2MET_stransMass       : 3.449e-02
                         :   17 : jets_5pt                     : 3.287e-02
                         :   18 : muonsTopMVAT_1pt             : 3.219e-02
                         :   19 : jets_3pt                     : 3.196e-02
                         :   20 : bjetsM_2tauF1lep1_stransMass : 3.192e-02
                         :   21 : jets_invariantMass           : 3.109e-02
                         :   22 : bjetsM_tausT_minDeltaR       : 3.051e-02
                         :   23 : bjetsM_transMass             : 2.995e-02
                         :   24 : jets_HT                      : 2.962e-02
                         :   25 : jets_1pt                     : 2.826e-02
                         :   26 : bjetsM_1pt                   : 2.617e-02
                         :   27 : bjetsT_1pt                   : 2.447e-02
                         :   28 : jets_HTDivideMET             : 1.571e-02
                         :   29 : tausT_1lepton1_charge        : 1.502e-02
                         : --------------------------------------------------------------
Factory                  : === Destroy and recreate all methods via weight files for testing ===
                         : 
                         : Reading weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_4_40.weights.xml
Factory                  : Test all methods
Factory                  : Test method: BDT_1000_7.5%_4_40 for Classification performance
                         : 
BDT_1000_7.5%_4_40       : [dataset] : Evaluation of BDT_1000_7.5%_4_40 on testing sample (55722 events)
                         : Elapsed time for evaluation of 55722 events: 4.11 sec       
Factory                  : Evaluate all methods
Factory                  : Evaluate classifier: BDT_1000_7.5%_4_40
                         : 
BDT_1000_7.5%_4_40       : [dataset] : Loop over test events and fill histograms with classifier response...
                         : 
TFHandler_BDT_1000_7.5...:                     Variable                            Mean                            RMS                    [        Min                            Max ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         :              jets_centrality:                       0.66184                       0.14677   [                       0.25830                        1.6941 ]
                         :                    tausT_1pt:                        55.640                        47.526   [                        20.000                        984.77 ]
                         :     jets_4largestBscoreMulti:                       0.27311                       0.22084   [                      0.023488                       0.99902 ]
                         :          jets_average_deltaR:                        2.2835                       0.25032   [                        1.2375                        3.2147 ]
                         :             bjetsM_transMass:                        429.62                        217.90   [                        91.218                        2692.0 ]
                         :                   bjetsT_2pt:                        46.498                        87.749   [                       -99.000                        1060.1 ]
                         :                   bjetsM_3pt:                        60.994                        30.463   [                        25.001                        537.35 ]
                         :                   bjetsT_1pt:                        153.47                        107.25   [                       -99.000                        1469.2 ]
                         :                   jets_1btag:                       0.37116                       0.40735   [                     0.0012627                       0.99951 ]
                         :                   bjetsM_1pt:                        198.97                        132.93   [                        31.638                        1589.2 ]
                         :       bjetsT_2MET_stransMass:                        28.906                        80.275   [                       -99.000                        649.60 ]
                         :              jets_sphericity:                       0.31512                       0.18858   [                     0.0038355                       0.95594 ]
                         : bjetsM_2tauF1lep1_stransMass:                        336.90                        224.25   [                        33.174                        3079.5 ]
                         :                     jets_MHT:                        189.49                        141.38   [                        1.0507                        1621.6 ]
                         :                      jets_HT:                        860.93                        323.02   [                        480.06                        3642.0 ]
                         :       bjetsM_2MET_stransMass:                        69.031                        53.447   [                        6.4940                        695.49 ]
                         :                     jets_3pt:                        121.48                        50.177   [                        45.026                        671.09 ]
                         :             bjetsM_minDeltaR:                        1.3098                       0.58987   [                       0.39310                        3.4579 ]
                         :           jets_invariantMass:                        1354.9                        557.86   [                        445.13                        5625.0 ]
                         :                     jets_1pt:                        274.17                        165.14   [                        63.318                        1797.0 ]
                         :                     jets_5pt:                        72.532                        24.422   [                        33.693                        382.51 ]
                         :                   jets_7btag:                       0.28253                       0.36859   [                     0.0014009                       0.99951 ]
                         :     bjetsM_leptons_minDeltaR:                        1.2626                       0.58420   [                       0.40045                        4.0134 ]
                         :       bjetsM_tausT_minDeltaR:                        1.2540                       0.58063   [                       0.40037                        4.0072 ]
                         :        tausT_1lepton1_deltaR:                        2.1411                       0.86478   [                       0.40055                        5.4321 ]
                         :             muonsTopMVAT_1pt:                       -10.142                        96.590   [                       -99.000                        933.77 ]
                         :          tausT_invariantMass:                       0.72529                       0.44708   [                       0.13953                        11.109 ]
                         :             jets_HTDivideMET:                        2.2884                        4.3950   [                      0.011409                        603.42 ]
                         :        tausT_1lepton1_charge:                      -0.56102                       0.82780   [                       -1.0000                        1.0000 ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         : 
                         : <PlotVariables> Will not produce scatter plots ==> 
                         : |  The number of 29 input variables and 0 target values would require 406 two-dimensional
                         : |  histograms, which would occupy the computer's memory. Note that this
                         : |  suppression does not have any consequences for your analysis, other
                         : |  than not disposing of these scatter plots. You can modify the maximum
                         : |  number of input variables allowed to generate scatter plots in your
                         : |  script via the command line:
                         : |  "(TMVA::gConfig().GetVariablePlotting()).fMaxNumOfAllowedVariablesForScatterPlots = <some int>;"
                         : 
                         : Some more output
                         : 
                         : Evaluation results ranked by best signal efficiency and purity (area)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet       MVA                       
                         : Name:         Method:          ROC-integ
                         : dataset       BDT_1000_7.5%_4_40: 0.890
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
                         : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample) 
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30   
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT_1000_7.5%_4_40: 0.240 (0.364)       0.680 (0.744)      0.896 (0.912)
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
Dataset:dataset          : Created tree 'TestTree' with 55722 events
                         : 
Dataset:dataset          : Created tree 'TrainTree' with 89580 events
                         : 
Factory                  : Thank you for using TMVA!
                         : For citation information, please visit: http://tmva.sf.net/citeTMVA.html
TFile**         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
 TFile*         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
  KEY: TDirectoryFile   dataset;1       dataset
0.890587
Factory                  : Booking method: BDT_1000_7.5%_5_20
                         : 
Factory                  : Train all methods
Factory                  : Train method: BDT_1000_7.5%_5_20 for Classification
                         : 
<WARNING>                : Events with negative event weights are USED during the BDT training. This might cause problems with small node sizes or with the boosting. Please remove negative events from training using the option *IgnoreEventsWithNegWeightsInTraining* in case you observe problems with the boosting
BDT_1000_7.5%_5_20       : #events: (reweighted) sig: 44790 bkg: 44790
                         : #events: (unweighted) sig: 4009 bkg: 85571
                         : Training 1000 Decision Trees ... patience please
                         : Elapsed time for training with 89580 events: 61.2 sec         
BDT_1000_7.5%_5_20       : [dataset] : Evaluation of BDT_1000_7.5%_5_20 on training sample (89580 events)
                         : Elapsed time for evaluation of 89580 events: 10.6 sec       
                         : Creating xml weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_5_20.weights.xml
                         : Creating standalone class: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight//TMVAClassification_BDT_1000_7.5%_5_20.class.C
                         : /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root:/dataset/Method_BDT/BDT_1000_7.5%_5_20
Factory                  : Training finished
                         : 
                         : Ranking input variables (method specific)...
BDT_1000_7.5%_5_20       : Ranking result (top variable is best ranked)
                         : --------------------------------------------------------------
                         : Rank : Variable                     : Variable Importance
                         : --------------------------------------------------------------
                         :    1 : jets_4largestBscoreMulti     : 5.096e-02
                         :    2 : tausT_1lepton1_deltaR        : 4.726e-02
                         :    3 : jets_sphericity              : 4.564e-02
                         :    4 : jets_1btag                   : 4.533e-02
                         :    5 : bjetsM_minDeltaR             : 4.385e-02
                         :    6 : tausT_1pt                    : 4.365e-02
                         :    7 : jets_7btag                   : 3.927e-02
                         :    8 : jets_average_deltaR          : 3.927e-02
                         :    9 : bjetsM_leptons_minDeltaR     : 3.883e-02
                         :   10 : jets_centrality              : 3.875e-02
                         :   11 : jets_MHT                     : 3.746e-02
                         :   12 : bjetsM_3pt                   : 3.675e-02
                         :   13 : bjetsM_tausT_minDeltaR       : 3.646e-02
                         :   14 : tausT_invariantMass          : 3.636e-02
                         :   15 : bjetsM_2MET_stransMass       : 3.557e-02
                         :   16 : bjetsT_2pt                   : 3.528e-02
                         :   17 : jets_5pt                     : 3.432e-02
                         :   18 : muonsTopMVAT_1pt             : 3.392e-02
                         :   19 : bjetsT_2MET_stransMass       : 3.211e-02
                         :   20 : jets_3pt                     : 3.097e-02
                         :   21 : bjetsM_transMass             : 3.073e-02
                         :   22 : bjetsM_2tauF1lep1_stransMass : 3.038e-02
                         :   23 : jets_HT                      : 3.035e-02
                         :   24 : jets_invariantMass           : 2.992e-02
                         :   25 : bjetsM_1pt                   : 2.515e-02
                         :   26 : jets_1pt                     : 2.469e-02
                         :   27 : bjetsT_1pt                   : 2.328e-02
                         :   28 : tausT_1lepton1_charge        : 1.709e-02
                         :   29 : jets_HTDivideMET             : 6.415e-03
                         : --------------------------------------------------------------
Factory                  : === Destroy and recreate all methods via weight files for testing ===
                         : 
                         : Reading weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_5_20.weights.xml
Factory                  : Test all methods
Factory                  : Test method: BDT_1000_7.5%_5_20 for Classification performance
                         : 
BDT_1000_7.5%_5_20       : [dataset] : Evaluation of BDT_1000_7.5%_5_20 on testing sample (55722 events)
                         : Elapsed time for evaluation of 55722 events: 4.48 sec       
Factory                  : Evaluate all methods
Factory                  : Evaluate classifier: BDT_1000_7.5%_5_20
                         : 
BDT_1000_7.5%_5_20       : [dataset] : Loop over test events and fill histograms with classifier response...
                         : 
TFHandler_BDT_1000_7.5...:                     Variable                            Mean                            RMS                    [        Min                            Max ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         :              jets_centrality:                       0.66184                       0.14677   [                       0.25830                        1.6941 ]
                         :                    tausT_1pt:                        55.640                        47.526   [                        20.000                        984.77 ]
                         :     jets_4largestBscoreMulti:                       0.27311                       0.22084   [                      0.023488                       0.99902 ]
                         :          jets_average_deltaR:                        2.2835                       0.25032   [                        1.2375                        3.2147 ]
                         :             bjetsM_transMass:                        429.62                        217.90   [                        91.218                        2692.0 ]
                         :                   bjetsT_2pt:                        46.498                        87.749   [                       -99.000                        1060.1 ]
                         :                   bjetsM_3pt:                        60.994                        30.463   [                        25.001                        537.35 ]
                         :                   bjetsT_1pt:                        153.47                        107.25   [                       -99.000                        1469.2 ]
                         :                   jets_1btag:                       0.37116                       0.40735   [                     0.0012627                       0.99951 ]
                         :                   bjetsM_1pt:                        198.97                        132.93   [                        31.638                        1589.2 ]
                         :       bjetsT_2MET_stransMass:                        28.906                        80.275   [                       -99.000                        649.60 ]
                         :              jets_sphericity:                       0.31512                       0.18858   [                     0.0038355                       0.95594 ]
                         : bjetsM_2tauF1lep1_stransMass:                        336.90                        224.25   [                        33.174                        3079.5 ]
                         :                     jets_MHT:                        189.49                        141.38   [                        1.0507                        1621.6 ]
                         :                      jets_HT:                        860.93                        323.02   [                        480.06                        3642.0 ]
                         :       bjetsM_2MET_stransMass:                        69.031                        53.447   [                        6.4940                        695.49 ]
                         :                     jets_3pt:                        121.48                        50.177   [                        45.026                        671.09 ]
                         :             bjetsM_minDeltaR:                        1.3098                       0.58987   [                       0.39310                        3.4579 ]
                         :           jets_invariantMass:                        1354.9                        557.86   [                        445.13                        5625.0 ]
                         :                     jets_1pt:                        274.17                        165.14   [                        63.318                        1797.0 ]
                         :                     jets_5pt:                        72.532                        24.422   [                        33.693                        382.51 ]
                         :                   jets_7btag:                       0.28253                       0.36859   [                     0.0014009                       0.99951 ]
                         :     bjetsM_leptons_minDeltaR:                        1.2626                       0.58420   [                       0.40045                        4.0134 ]
                         :       bjetsM_tausT_minDeltaR:                        1.2540                       0.58063   [                       0.40037                        4.0072 ]
                         :        tausT_1lepton1_deltaR:                        2.1411                       0.86478   [                       0.40055                        5.4321 ]
                         :             muonsTopMVAT_1pt:                       -10.142                        96.590   [                       -99.000                        933.77 ]
                         :          tausT_invariantMass:                       0.72529                       0.44708   [                       0.13953                        11.109 ]
                         :             jets_HTDivideMET:                        2.2884                        4.3950   [                      0.011409                        603.42 ]
                         :        tausT_1lepton1_charge:                      -0.56102                       0.82780   [                       -1.0000                        1.0000 ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         : 
                         : <PlotVariables> Will not produce scatter plots ==> 
                         : |  The number of 29 input variables and 0 target values would require 406 two-dimensional
                         : |  histograms, which would occupy the computer's memory. Note that this
                         : |  suppression does not have any consequences for your analysis, other
                         : |  than not disposing of these scatter plots. You can modify the maximum
                         : |  number of input variables allowed to generate scatter plots in your
                         : |  script via the command line:
                         : |  "(TMVA::gConfig().GetVariablePlotting()).fMaxNumOfAllowedVariablesForScatterPlots = <some int>;"
                         : 
                         : Some more output
                         : 
                         : Evaluation results ranked by best signal efficiency and purity (area)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet       MVA                       
                         : Name:         Method:          ROC-integ
                         : dataset       BDT_1000_7.5%_5_20: 0.893
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
                         : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample) 
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30   
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT_1000_7.5%_5_20: 0.253 (0.387)       0.700 (0.742)      0.901 (0.920)
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
Dataset:dataset          : Created tree 'TestTree' with 55722 events
                         : 
Dataset:dataset          : Created tree 'TrainTree' with 89580 events
                         : 
Factory                  : Thank you for using TMVA!
                         : For citation information, please visit: http://tmva.sf.net/citeTMVA.html
TFile**         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
 TFile*         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
  KEY: TDirectoryFile   dataset;1       dataset
0.893756
Factory                  : Booking method: BDT_1000_7.5%_5_30
                         : 
Factory                  : Train all methods
Factory                  : Train method: BDT_1000_7.5%_5_30 for Classification
                         : 
<WARNING>                : Events with negative event weights are USED during the BDT training. This might cause problems with small node sizes or with the boosting. Please remove negative events from training using the option *IgnoreEventsWithNegWeightsInTraining* in case you observe problems with the boosting
BDT_1000_7.5%_5_30       : #events: (reweighted) sig: 44790 bkg: 44790
                         : #events: (unweighted) sig: 4009 bkg: 85571
                         : Training 1000 Decision Trees ... patience please
                         : Elapsed time for training with 89580 events: 59.2 sec         
BDT_1000_7.5%_5_30       : [dataset] : Evaluation of BDT_1000_7.5%_5_30 on training sample (89580 events)
                         : Elapsed time for evaluation of 89580 events: 10.6 sec       
                         : Creating xml weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_5_30.weights.xml
                         : Creating standalone class: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight//TMVAClassification_BDT_1000_7.5%_5_30.class.C
                         : /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root:/dataset/Method_BDT/BDT_1000_7.5%_5_30
Factory                  : Training finished
                         : 
                         : Ranking input variables (method specific)...
BDT_1000_7.5%_5_30       : Ranking result (top variable is best ranked)
                         : --------------------------------------------------------------
                         : Rank : Variable                     : Variable Importance
                         : --------------------------------------------------------------
                         :    1 : jets_4largestBscoreMulti     : 4.913e-02
                         :    2 : tausT_1lepton1_deltaR        : 4.525e-02
                         :    3 : jets_sphericity              : 4.469e-02
                         :    4 : tausT_1pt                    : 4.306e-02
                         :    5 : bjetsM_minDeltaR             : 4.265e-02
                         :    6 : jets_1btag                   : 4.258e-02
                         :    7 : jets_MHT                     : 4.042e-02
                         :    8 : jets_centrality              : 3.984e-02
                         :    9 : jets_7btag                   : 3.836e-02
                         :   10 : jets_average_deltaR          : 3.822e-02
                         :   11 : bjetsM_leptons_minDeltaR     : 3.818e-02
                         :   12 : tausT_invariantMass          : 3.793e-02
                         :   13 : bjetsM_3pt                   : 3.708e-02
                         :   14 : muonsTopMVAT_1pt             : 3.509e-02
                         :   15 : jets_invariantMass           : 3.413e-02
                         :   16 : bjetsM_2MET_stransMass       : 3.353e-02
                         :   17 : bjetsM_tausT_minDeltaR       : 3.262e-02
                         :   18 : jets_3pt                     : 3.249e-02
                         :   19 : bjetsT_2pt                   : 3.247e-02
                         :   20 : bjetsT_2MET_stransMass       : 3.198e-02
                         :   21 : bjetsM_2tauF1lep1_stransMass : 3.108e-02
                         :   22 : jets_5pt                     : 3.073e-02
                         :   23 : bjetsM_transMass             : 3.052e-02
                         :   24 : jets_HT                      : 2.998e-02
                         :   25 : bjetsT_1pt                   : 2.730e-02
                         :   26 : jets_1pt                     : 2.618e-02
                         :   27 : bjetsM_1pt                   : 2.410e-02
                         :   28 : tausT_1lepton1_charge        : 1.806e-02
                         :   29 : jets_HTDivideMET             : 1.233e-02
                         : --------------------------------------------------------------
Factory                  : === Destroy and recreate all methods via weight files for testing ===
                         : 
                         : Reading weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_5_30.weights.xml
Factory                  : Test all methods
Factory                  : Test method: BDT_1000_7.5%_5_30 for Classification performance
                         : 
BDT_1000_7.5%_5_30       : [dataset] : Evaluation of BDT_1000_7.5%_5_30 on testing sample (55722 events)
                         : Elapsed time for evaluation of 55722 events: 4.5 sec       
Factory                  : Evaluate all methods
Factory                  : Evaluate classifier: BDT_1000_7.5%_5_30
                         : 
BDT_1000_7.5%_5_30       : [dataset] : Loop over test events and fill histograms with classifier response...
                         : 
TFHandler_BDT_1000_7.5...:                     Variable                            Mean                            RMS                    [        Min                            Max ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         :              jets_centrality:                       0.66184                       0.14677   [                       0.25830                        1.6941 ]
                         :                    tausT_1pt:                        55.640                        47.526   [                        20.000                        984.77 ]
                         :     jets_4largestBscoreMulti:                       0.27311                       0.22084   [                      0.023488                       0.99902 ]
                         :          jets_average_deltaR:                        2.2835                       0.25032   [                        1.2375                        3.2147 ]
                         :             bjetsM_transMass:                        429.62                        217.90   [                        91.218                        2692.0 ]
                         :                   bjetsT_2pt:                        46.498                        87.749   [                       -99.000                        1060.1 ]
                         :                   bjetsM_3pt:                        60.994                        30.463   [                        25.001                        537.35 ]
                         :                   bjetsT_1pt:                        153.47                        107.25   [                       -99.000                        1469.2 ]
                         :                   jets_1btag:                       0.37116                       0.40735   [                     0.0012627                       0.99951 ]
                         :                   bjetsM_1pt:                        198.97                        132.93   [                        31.638                        1589.2 ]
                         :       bjetsT_2MET_stransMass:                        28.906                        80.275   [                       -99.000                        649.60 ]
                         :              jets_sphericity:                       0.31512                       0.18858   [                     0.0038355                       0.95594 ]
                         : bjetsM_2tauF1lep1_stransMass:                        336.90                        224.25   [                        33.174                        3079.5 ]
                         :                     jets_MHT:                        189.49                        141.38   [                        1.0507                        1621.6 ]
                         :                      jets_HT:                        860.93                        323.02   [                        480.06                        3642.0 ]
                         :       bjetsM_2MET_stransMass:                        69.031                        53.447   [                        6.4940                        695.49 ]
                         :                     jets_3pt:                        121.48                        50.177   [                        45.026                        671.09 ]
                         :             bjetsM_minDeltaR:                        1.3098                       0.58987   [                       0.39310                        3.4579 ]
                         :           jets_invariantMass:                        1354.9                        557.86   [                        445.13                        5625.0 ]
                         :                     jets_1pt:                        274.17                        165.14   [                        63.318                        1797.0 ]
                         :                     jets_5pt:                        72.532                        24.422   [                        33.693                        382.51 ]
                         :                   jets_7btag:                       0.28253                       0.36859   [                     0.0014009                       0.99951 ]
                         :     bjetsM_leptons_minDeltaR:                        1.2626                       0.58420   [                       0.40045                        4.0134 ]
                         :       bjetsM_tausT_minDeltaR:                        1.2540                       0.58063   [                       0.40037                        4.0072 ]
                         :        tausT_1lepton1_deltaR:                        2.1411                       0.86478   [                       0.40055                        5.4321 ]
                         :             muonsTopMVAT_1pt:                       -10.142                        96.590   [                       -99.000                        933.77 ]
                         :          tausT_invariantMass:                       0.72529                       0.44708   [                       0.13953                        11.109 ]
                         :             jets_HTDivideMET:                        2.2884                        4.3950   [                      0.011409                        603.42 ]
                         :        tausT_1lepton1_charge:                      -0.56102                       0.82780   [                       -1.0000                        1.0000 ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         : 
                         : <PlotVariables> Will not produce scatter plots ==> 
                         : |  The number of 29 input variables and 0 target values would require 406 two-dimensional
                         : |  histograms, which would occupy the computer's memory. Note that this
                         : |  suppression does not have any consequences for your analysis, other
                         : |  than not disposing of these scatter plots. You can modify the maximum
                         : |  number of input variables allowed to generate scatter plots in your
                         : |  script via the command line:
                         : |  "(TMVA::gConfig().GetVariablePlotting()).fMaxNumOfAllowedVariablesForScatterPlots = <some int>;"
                         : 
                         : Some more output
                         : 
                         : Evaluation results ranked by best signal efficiency and purity (area)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet       MVA                       
                         : Name:         Method:          ROC-integ
                         : dataset       BDT_1000_7.5%_5_30: 0.896
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
                         : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample) 
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30   
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT_1000_7.5%_5_30: 0.256 (0.332)       0.722 (0.760)      0.881 (0.911)
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
Dataset:dataset          : Created tree 'TestTree' with 55722 events
                         : 
Dataset:dataset          : Created tree 'TrainTree' with 89580 events
                         : 
Factory                  : Thank you for using TMVA!
                         : For citation information, please visit: http://tmva.sf.net/citeTMVA.html
TFile**         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
 TFile*         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
  KEY: TDirectoryFile   dataset;1       dataset
0.895683
Factory                  : Booking method: BDT_1000_7.5%_5_40
                         : 
Factory                  : Train all methods
Factory                  : Train method: BDT_1000_7.5%_5_40 for Classification
                         : 
<WARNING>                : Events with negative event weights are USED during the BDT training. This might cause problems with small node sizes or with the boosting. Please remove negative events from training using the option *IgnoreEventsWithNegWeightsInTraining* in case you observe problems with the boosting
BDT_1000_7.5%_5_40       : #events: (reweighted) sig: 44790 bkg: 44790
                         : #events: (unweighted) sig: 4009 bkg: 85571
                         : Training 1000 Decision Trees ... patience please
                         : Elapsed time for training with 89580 events: 58.4 sec         
BDT_1000_7.5%_5_40       : [dataset] : Evaluation of BDT_1000_7.5%_5_40 on training sample (89580 events)
                         : Elapsed time for evaluation of 89580 events: 10.4 sec       
                         : Creating xml weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_5_40.weights.xml
                         : Creating standalone class: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight//TMVAClassification_BDT_1000_7.5%_5_40.class.C
                         : /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root:/dataset/Method_BDT/BDT_1000_7.5%_5_40
Factory                  : Training finished
                         : 
                         : Ranking input variables (method specific)...
BDT_1000_7.5%_5_40       : Ranking result (top variable is best ranked)
                         : --------------------------------------------------------------
                         : Rank : Variable                     : Variable Importance
                         : --------------------------------------------------------------
                         :    1 : jets_4largestBscoreMulti     : 5.000e-02
                         :    2 : bjetsM_minDeltaR             : 4.612e-02
                         :    3 : jets_sphericity              : 4.549e-02
                         :    4 : tausT_1lepton1_deltaR        : 4.334e-02
                         :    5 : jets_1btag                   : 4.187e-02
                         :    6 : tausT_1pt                    : 4.159e-02
                         :    7 : jets_centrality              : 3.961e-02
                         :    8 : jets_MHT                     : 3.957e-02
                         :    9 : bjetsM_3pt                   : 3.828e-02
                         :   10 : bjetsT_2MET_stransMass       : 3.728e-02
                         :   11 : jets_7btag                   : 3.688e-02
                         :   12 : tausT_invariantMass          : 3.675e-02
                         :   13 : jets_average_deltaR          : 3.602e-02
                         :   14 : bjetsM_2MET_stransMass       : 3.427e-02
                         :   15 : jets_5pt                     : 3.423e-02
                         :   16 : bjetsM_tausT_minDeltaR       : 3.389e-02
                         :   17 : bjetsM_leptons_minDeltaR     : 3.375e-02
                         :   18 : bjetsT_2pt                   : 3.334e-02
                         :   19 : bjetsM_2tauF1lep1_stransMass : 3.277e-02
                         :   20 : jets_3pt                     : 3.269e-02
                         :   21 : jets_invariantMass           : 3.128e-02
                         :   22 : muonsTopMVAT_1pt             : 3.123e-02
                         :   23 : jets_HT                      : 2.938e-02
                         :   24 : bjetsM_transMass             : 2.930e-02
                         :   25 : jets_1pt                     : 2.907e-02
                         :   26 : bjetsT_1pt                   : 2.636e-02
                         :   27 : bjetsM_1pt                   : 2.555e-02
                         :   28 : tausT_1lepton1_charge        : 1.540e-02
                         :   29 : jets_HTDivideMET             : 1.470e-02
                         : --------------------------------------------------------------
Factory                  : === Destroy and recreate all methods via weight files for testing ===
                         : 
                         : Reading weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT_1000_7.5%_5_40.weights.xml
Factory                  : Test all methods
Factory                  : Test method: BDT_1000_7.5%_5_40 for Classification performance
                         : 
BDT_1000_7.5%_5_40       : [dataset] : Evaluation of BDT_1000_7.5%_5_40 on testing sample (55722 events)
                         : Elapsed time for evaluation of 55722 events: 4.34 sec       
Factory                  : Evaluate all methods
Factory                  : Evaluate classifier: BDT_1000_7.5%_5_40
                         : 
BDT_1000_7.5%_5_40       : [dataset] : Loop over test events and fill histograms with classifier response...
                         : 
TFHandler_BDT_1000_7.5...:                     Variable                            Mean                            RMS                    [        Min                            Max ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         :              jets_centrality:                       0.66184                       0.14677   [                       0.25830                        1.6941 ]
                         :                    tausT_1pt:                        55.640                        47.526   [                        20.000                        984.77 ]
                         :     jets_4largestBscoreMulti:                       0.27311                       0.22084   [                      0.023488                       0.99902 ]
                         :          jets_average_deltaR:                        2.2835                       0.25032   [                        1.2375                        3.2147 ]
                         :             bjetsM_transMass:                        429.62                        217.90   [                        91.218                        2692.0 ]
                         :                   bjetsT_2pt:                        46.498                        87.749   [                       -99.000                        1060.1 ]
                         :                   bjetsM_3pt:                        60.994                        30.463   [                        25.001                        537.35 ]
                         :                   bjetsT_1pt:                        153.47                        107.25   [                       -99.000                        1469.2 ]
                         :                   jets_1btag:                       0.37116                       0.40735   [                     0.0012627                       0.99951 ]
                         :                   bjetsM_1pt:                        198.97                        132.93   [                        31.638                        1589.2 ]
                         :       bjetsT_2MET_stransMass:                        28.906                        80.275   [                       -99.000                        649.60 ]
                         :              jets_sphericity:                       0.31512                       0.18858   [                     0.0038355                       0.95594 ]
                         : bjetsM_2tauF1lep1_stransMass:                        336.90                        224.25   [                        33.174                        3079.5 ]
                         :                     jets_MHT:                        189.49                        141.38   [                        1.0507                        1621.6 ]
                         :                      jets_HT:                        860.93                        323.02   [                        480.06                        3642.0 ]
                         :       bjetsM_2MET_stransMass:                        69.031                        53.447   [                        6.4940                        695.49 ]
                         :                     jets_3pt:                        121.48                        50.177   [                        45.026                        671.09 ]
                         :             bjetsM_minDeltaR:                        1.3098                       0.58987   [                       0.39310                        3.4579 ]
                         :           jets_invariantMass:                        1354.9                        557.86   [                        445.13                        5625.0 ]
                         :                     jets_1pt:                        274.17                        165.14   [                        63.318                        1797.0 ]
                         :                     jets_5pt:                        72.532                        24.422   [                        33.693                        382.51 ]
                         :                   jets_7btag:                       0.28253                       0.36859   [                     0.0014009                       0.99951 ]
                         :     bjetsM_leptons_minDeltaR:                        1.2626                       0.58420   [                       0.40045                        4.0134 ]
                         :       bjetsM_tausT_minDeltaR:                        1.2540                       0.58063   [                       0.40037                        4.0072 ]
                         :        tausT_1lepton1_deltaR:                        2.1411                       0.86478   [                       0.40055                        5.4321 ]
                         :             muonsTopMVAT_1pt:                       -10.142                        96.590   [                       -99.000                        933.77 ]
                         :          tausT_invariantMass:                       0.72529                       0.44708   [                       0.13953                        11.109 ]
                         :             jets_HTDivideMET:                        2.2884                        4.3950   [                      0.011409                        603.42 ]
                         :        tausT_1lepton1_charge:                      -0.56102                       0.82780   [                       -1.0000                        1.0000 ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         : 
                         : <PlotVariables> Will not produce scatter plots ==> 
                         : |  The number of 29 input variables and 0 target values would require 406 two-dimensional
                         : |  histograms, which would occupy the computer's memory. Note that this
                         : |  suppression does not have any consequences for your analysis, other
                         : |  than not disposing of these scatter plots. You can modify the maximum
                         : |  number of input variables allowed to generate scatter plots in your
                         : |  script via the command line:
                         : |  "(TMVA::gConfig().GetVariablePlotting()).fMaxNumOfAllowedVariablesForScatterPlots = <some int>;"
                         : 
                         : Some more output
                         : 
                         : Evaluation results ranked by best signal efficiency and purity (area)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet       MVA                       
                         : Name:         Method:          ROC-integ
                         : dataset       BDT_1000_7.5%_5_40: 0.895
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
                         : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample) 
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30   
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT_1000_7.5%_5_40: 0.277 (0.352)       0.701 (0.773)      0.888 (0.912)
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
Dataset:dataset          : Created tree 'TestTree' with 55722 events
                         : 
Dataset:dataset          : Created tree 'TrainTree' with 89580 events
                         : 
Factory                  : Thank you for using TMVA!
                         : For citation information, please visit: http://tmva.sf.net/citeTMVA.html
TFile**         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
 TFile*         /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
  KEY: TDirectoryFile   dataset;1       dataset
0.895955
Best BDT Parameters: NTrees=500:MinNodeSize=2.5%:MaxDepth=4:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=40
Factory                  : Booking method: BDT
                         : 
Factory                  : Train all methods
Factory                  : Train method: BDT for Classification
                         : 
<WARNING>                : Events with negative event weights are USED during the BDT training. This might cause problems with small node sizes or with the boosting. Please remove negative events from training using the option *IgnoreEventsWithNegWeightsInTraining* in case you observe problems with the boosting
BDT                      : #events: (reweighted) sig: 44790 bkg: 44790
                         : #events: (unweighted) sig: 4009 bkg: 85571
                         : Training 500 Decision Trees ... patience please
                         : Elapsed time for training with 89580 events: 31.9 sec         
BDT                      : [dataset] : Evaluation of BDT on training sample (89580 events)
                         : Elapsed time for evaluation of 89580 events: 4.73 sec       
                         : Creating xml weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT.weights.xml
                         : Creating standalone class: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight//TMVAClassification_BDT.class.C
                         : /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root:/dataset/Method_BDT/BDT
Factory                  : Training finished
                         : 
                         : Ranking input variables (method specific)...
BDT                      : Ranking result (top variable is best ranked)
                         : --------------------------------------------------------------
                         : Rank : Variable                     : Variable Importance
                         : --------------------------------------------------------------
                         :    1 : jets_4largestBscoreMulti     : 4.924e-02
                         :    2 : jets_centrality              : 4.890e-02
                         :    3 : tausT_1pt                    : 4.804e-02
                         :    4 : tausT_1lepton1_deltaR        : 4.287e-02
                         :    5 : bjetsM_minDeltaR             : 4.263e-02
                         :    6 : jets_MHT                     : 4.083e-02
                         :    7 : jets_sphericity              : 4.081e-02
                         :    8 : jets_1btag                   : 3.717e-02
                         :    9 : bjetsM_2MET_stransMass       : 3.681e-02
                         :   10 : jets_average_deltaR          : 3.669e-02
                         :   11 : bjetsM_3pt                   : 3.663e-02
                         :   12 : tausT_invariantMass          : 3.641e-02
                         :   13 : bjetsM_leptons_minDeltaR     : 3.632e-02
                         :   14 : jets_7btag                   : 3.522e-02
                         :   15 : jets_invariantMass           : 3.444e-02
                         :   16 : bjetsM_tausT_minDeltaR       : 3.233e-02
                         :   17 : bjetsT_2MET_stransMass       : 3.189e-02
                         :   18 : bjetsT_2pt                   : 3.177e-02
                         :   19 : muonsTopMVAT_1pt             : 3.162e-02
                         :   20 : bjetsM_transMass             : 3.139e-02
                         :   21 : bjetsT_1pt                   : 3.127e-02
                         :   22 : bjetsM_2tauF1lep1_stransMass : 3.115e-02
                         :   23 : jets_5pt                     : 3.108e-02
                         :   24 : jets_3pt                     : 2.949e-02
                         :   25 : jets_HT                      : 2.771e-02
                         :   26 : jets_1pt                     : 2.511e-02
                         :   27 : bjetsM_1pt                   : 2.459e-02
                         :   28 : jets_HTDivideMET             : 2.035e-02
                         :   29 : tausT_1lepton1_charge        : 1.723e-02
                         : --------------------------------------------------------------
Factory                  : === Destroy and recreate all methods via weight files for testing ===
                         : 
                         : Reading weight file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv/dataset/weight/TMVAClassification_BDT.weights.xml
Factory                  : Test all methods
Factory                  : Test method: BDT for Classification performance
                         : 
BDT                      : [dataset] : Evaluation of BDT on testing sample (55722 events)
                         : Elapsed time for evaluation of 55722 events: 2.29 sec       
Factory                  : Evaluate all methods
Factory                  : Evaluate classifier: BDT
                         : 
BDT                      : [dataset] : Loop over test events and fill histograms with classifier response...
                         : 
TFHandler_BDT            :                     Variable                            Mean                            RMS                    [        Min                            Max ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         :              jets_centrality:                       0.66184                       0.14677   [                       0.25830                        1.6941 ]
                         :                    tausT_1pt:                        55.640                        47.526   [                        20.000                        984.77 ]
                         :     jets_4largestBscoreMulti:                       0.27311                       0.22084   [                      0.023488                       0.99902 ]
                         :          jets_average_deltaR:                        2.2835                       0.25032   [                        1.2375                        3.2147 ]
                         :             bjetsM_transMass:                        429.62                        217.90   [                        91.218                        2692.0 ]
                         :                   bjetsT_2pt:                        46.498                        87.749   [                       -99.000                        1060.1 ]
                         :                   bjetsM_3pt:                        60.994                        30.463   [                        25.001                        537.35 ]
                         :                   bjetsT_1pt:                        153.47                        107.25   [                       -99.000                        1469.2 ]
                         :                   jets_1btag:                       0.37116                       0.40735   [                     0.0012627                       0.99951 ]
                         :                   bjetsM_1pt:                        198.97                        132.93   [                        31.638                        1589.2 ]
                         :       bjetsT_2MET_stransMass:                        28.906                        80.275   [                       -99.000                        649.60 ]
                         :              jets_sphericity:                       0.31512                       0.18858   [                     0.0038355                       0.95594 ]
                         : bjetsM_2tauF1lep1_stransMass:                        336.90                        224.25   [                        33.174                        3079.5 ]
                         :                     jets_MHT:                        189.49                        141.38   [                        1.0507                        1621.6 ]
                         :                      jets_HT:                        860.93                        323.02   [                        480.06                        3642.0 ]
                         :       bjetsM_2MET_stransMass:                        69.031                        53.447   [                        6.4940                        695.49 ]
                         :                     jets_3pt:                        121.48                        50.177   [                        45.026                        671.09 ]
                         :             bjetsM_minDeltaR:                        1.3098                       0.58987   [                       0.39310                        3.4579 ]
                         :           jets_invariantMass:                        1354.9                        557.86   [                        445.13                        5625.0 ]
                         :                     jets_1pt:                        274.17                        165.14   [                        63.318                        1797.0 ]
                         :                     jets_5pt:                        72.532                        24.422   [                        33.693                        382.51 ]
                         :                   jets_7btag:                       0.28253                       0.36859   [                     0.0014009                       0.99951 ]
                         :     bjetsM_leptons_minDeltaR:                        1.2626                       0.58420   [                       0.40045                        4.0134 ]
                         :       bjetsM_tausT_minDeltaR:                        1.2540                       0.58063   [                       0.40037                        4.0072 ]
                         :        tausT_1lepton1_deltaR:                        2.1411                       0.86478   [                       0.40055                        5.4321 ]
                         :             muonsTopMVAT_1pt:                       -10.142                        96.590   [                       -99.000                        933.77 ]
                         :          tausT_invariantMass:                       0.72529                       0.44708   [                       0.13953                        11.109 ]
                         :             jets_HTDivideMET:                        2.2884                        4.3950   [                      0.011409                        603.42 ]
                         :        tausT_1lepton1_charge:                      -0.56102                       0.82780   [                       -1.0000                        1.0000 ]
                         : ---------------------------------------------------------------------------------------------------------------------------------------------------------------
                         : 
                         : <PlotVariables> Will not produce scatter plots ==> 
                         : |  The number of 29 input variables and 0 target values would require 406 two-dimensional
                         : |  histograms, which would occupy the computer's memory. Note that this
                         : |  suppression does not have any consequences for your analysis, other
                         : |  than not disposing of these scatter plots. You can modify the maximum
                         : |  number of input variables allowed to generate scatter plots in your
                         : |  script via the command line:
                         : |  "(TMVA::gConfig().GetVariablePlotting()).fMaxNumOfAllowedVariablesForScatterPlots = <some int>;"
                         : 
                         : Some more output
                         : 
                         : Evaluation results ranked by best signal efficiency and purity (area)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet       MVA                       
                         : Name:         Method:          ROC-integ
                         : dataset       BDT            : 0.901
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
                         : Testing efficiency compared to training efficiency (overtraining check)
                         : -------------------------------------------------------------------------------------------------------------------
                         : DataSet              MVA              Signal efficiency: from test sample (from training sample) 
                         : Name:                Method:          @B=0.01             @B=0.10            @B=0.30   
                         : -------------------------------------------------------------------------------------------------------------------
                         : dataset              BDT            : 0.313 (0.412)       0.744 (0.779)      0.893 (0.911)
                         : -------------------------------------------------------------------------------------------------------------------
                         : 
Dataset:dataset          : Created tree 'TestTree' with 55722 events
                         : 
Dataset:dataset          : Created tree 'TrainTree' with 89580 events
                         : 
Factory                  : Thank you for using TMVA!
                         : For citation information, please visit: http://tmva.sf.net/citeTMVA.html
==> Wrote root file: /afs/ihep.ac.cn/users/t/turuobing/CMSSW_10_6_20/src/FourTop/hua/tmva/newCode/BDTTrain/v1VLLM600/inputList_1tau1l_M600_26var.csv.root
==> TMVAClassification is done!
[Inferior 1 (process 18723) exited normally]