#ifndef GENSUMMAP_H
#define GENSUMMAP_H

#include <map>
//writen with getGenSum.py
namespace GENSUM{

inline const std::map<TString, std::map<TString, Double_t>> genSumMap = {
{"2018", {
    {"TTToSemiLeptonic", 1.35336e+12},// only for BDT training in 1tau1l and 1tau2l
    {"TTToHadronic", 7.16154e+11},
    {"TTTo2L2Nu", 9.77873e+10}, //!!!

{"TTTo2L2Nu12", 3676686735.3588},
{"TTTo2L2Nu20", 4686306971.145},
{"dy", 44304135.0},
{"qcd_200to300", 57336623.0},
{"TTTo2L2Nu19", 4316055324.3996},
{"ZJetsToNuNu_HT-2500ToInf", 350168.8629485784},
{"VLL_EE_M900", 28.57328571},
{"TTTo2L2Nu7", 5107198152.420001},
{"WJetsToLNu_HT-2500ToInf", 2097648.0},
{"TTWJetsToQQ", 656374.2728368},
{"TTToSemiLeptonic8", 58902792307.920006},
{"VLL_NN_M750", 18.732711000000002},
{"TTTo2L2Nu13", 4123992377.0602016},
{"dy_fxfx_2j", 0.0},
{"dy_fxfx_0j", 0.0},
{"DYJetsToLL_M-4to50_HT-100to200", 6784415.669920306},
{"ZHToTauTau", 3757651.586189425},
{"zz", 3526000.0},
{"TTTo2L2Nu2", 10457566706.558405},
{"dy_fxfx", 1865334146117.397},
{"VLL_NN_M950", 4.80302336},
{"ZJetsToNuNu_HT-400To600", 9483323.05142726},
{"TTToSemiLeptonic0", 59525436999.57598},
{"ZJetsToNuNu_HT-1200To2500", 340171.00930426666},
{"st_tW_top", 258137398.5808001},
{"ttbar_2l", 10457566706.558403},
{"dy_100to200", 25271871.0},
{"ZGToLLG", 2945217421.2728004},
{"dy_400to600", 4615088.0},
{"WGToLNuG", 21973848102.29522},
{"VLL_NN_M900", 6.619644970000002},
{"ggH_bb", 306093781.5276001},
{"ttG", 27849497.759999998},
{"vbfH_WW_2l", 36941581.16351999},
{"dy_600to800", 7035971.0},
{"TTToSemiLeptonic20", 59994502183.19997},
{"VLL_EN_M800", 102.43406055000001},
{"DYJetsToLL_M-50", 1237360468.848},
{"st_schan_had", 115657659.06405006},
{"TTWJetsToLNu", 3502613.3919518394},
{"WJetsToQQ_HT-600to800", 15246402.339965336},
{"VLL_EE_M500", 591.1833100000001},
{"TTToSemiLeptonic3", 58317663263.20004},
{"ZZZ", 3690.7843549760005},
{"DYJetsToLL_M-50_HT-600to800", 7035971.0},
{"st_tchan", 18955983507.894},
{"qcd_50to100", 38599389.0},
{"qcd_2000toInf", 5374711.0},
{"WJetsToLNu_HT-600To800", 7718765.0},
{"VLL_NN_M550", 91.491543},
{"VLL_EE_M650", 166.886744},
{"ggH_WW_2l", 136936228.18140003},
{"dy_70to100", 17004433.0},
{"ZJetsToQQ_HT-600to800", 14600689.076338131},
{"TTToHadronic6", 97194927854.9522},
{"TTToSemiLeptonic16", 59104136472.96404},
{"TTToHadronic3", 104910439190.40396},
{"ggH_ZZ_4l", 27138279.532200005},
{"TTToSemiLeptonic18", 59998667622.47604},
{"TTTo2L2Nu11", 4323628205.963002},
{"TTTW", 494000.0},
{"DYJetsToLL_M-4to50_HT-200to400", 1933953.2940268652},
{"TTTo2L2Nu6", 4435418494.282599},
{"ttZH", 500000.0},
{"dy_2500toInf", 106267.0},
{"TTTo2L2Nu0", 4319091786.994},
{"TTTo2L2Nu15", 10797600355.304184},
{"DYJetsToLL_M-50_HT-1200to2500", 5966661.0},
{"DYJetsToLL_M-50_HT-800to1200", 6554679.0},
{"VLL_EN_M750", 145.8602032},
{"TTToHadronic10", 43375307823.66003},
{"TTToHadronic5", 43787699958.8},
{"DYJetsToLL_M-50_HT-70to100", 17004433.0},
{"wz", 7940000.0},
{"dy_ext", 88819930.0},
{"WJetsToLNu", 1188874708.6423705},
{"ttbar_0l", 104910439190.40405},
{"qcd_700to1000", 48506751.0},
{"TTToHadronic11", 43849410601.71601},
{"VLL_EN_M700", 209.162717},
{"WJetsToQQ_HT-400to600", 10046074.61723694},
{"WJetsToLNu_HT-70To100", 66220256.0},
{"st_tW_antitop", 251902163.21000004},
{"TTToHadronic2", 43328394801.03},
{"TTToSemiLeptonic13", 58518292489.722},
{"TTToSemiLeptonic1", 59977563613.13203},
{"WJetsToLNu_HT-1200To2500", 6481518.0},
{"DYJetsToLL_M-10to50", 94452816.0},
{"TTToSemiLeptonic21", 67828954921.01004},
{"TTToSemiLeptonic4", 59635849027.61204},
{"VLL_NN_M600", 59.59120400000002},
{"TTToSemiLeptonic7", 50874238399.147995},
{"DYJetsToLL_M-50_HT-2500toInf", 1978203.0},
{"TTToSemiLeptonic12", 59586418661.66006},
{"TTToHadronic4", 49168689979.65599},
{"tt", 3311826398.912999},
{"TTTo2L2Nu3", 4218732074.6372004},
{"VLL_NN_M850", 9.260824567000002},
{"VLL_NN_M500", 143.230307},
{"TTToSemiLeptonic14", 59534257770.35002},
{"DYJetsToLL_M-4to50_HT-600toInf", 1964769.6021715738},
{"VLL_EN_M1000", 28.120041399999995},
{"ggH_ZZ_2l", 28813633.235200007},
{"TTToSemiLeptonic5", 59374335623.416016},
{"VLL_EN_M850", 72.97437290000002},
{"TTToHadronic14", 41845099323.056},
{"ggH_gg", 465089.7155499391},
{"TTTo2L2Nu16", 4299241370.782402},
{"WWZ", 42310.517360879996},
{"TTToHadronic12", 43861623026.944016},
{"vbfH_bb", 29417189.70328001},
{"vbfH_tautau", 11530157.705640003},
{"DYJetsToLL_M-50_HT-400to600", 8682257.0},
{"VLL_EN_M600", 451.9382500000002},
{"WJetsToLNu_HT-100To200", 51408967.0},
{"ttWH", 497000.0},
{"TTZToLLNuNu", 4782962.671003081},
{"qcd_500to700", 49184771.0},
{"TTToSemiLeptonic19", 50794376435.20801},
{"TTTJ", 500000.0},
{"TTToSemiLeptonic15", 58140741853.34999},
{"VLL_EE_M950", 20.554075400000002},
{"TTToSemiLeptonic10", 91624122566.98811},
{"DYJetsToLL_M-50_HT-200to400", 18455718.0},
{"TTToHadronic7", 39928686942.576004},
{"TTTo2L2Nu4", 4221545062.6574025},
{"ttbar_1l", 143354137521.54016},
{"VLL_EE_M800", 55.58882853},
{"TTToHadronic0", 43357269007.32803},
{"TTToSemiLeptonic9", 58707486787.22403},
{"vH_nonbb", 7023767.516864},
{"VLL_NN_M800", 13.167602720000001},
{"VLL_EE_M750", 79.04369200000001},
{"TTToSemiLeptonic2", 143354137521.54007},
{"ZH_HToBB_ZToLL", 176281.34766683044},
{"TTTo2L2Nu18", 4009940860.8139997},
{"VLL_EN_M650", 305.767699},
{"ww", 15679122.7146132},
{"qcd_300to500", 61609663.0},
{"TTTo2L2Nu10", 4114968337.0812016},
{"TTToHadronic9", 42938302139.52201},
{"WJetsToLNu_HT-800To1200", 7306187.0},
{"VLL_EN_M500", 1063.77671},
{"TTTo2L2Nu1", 4324824484.1388},
{"ttH_nonbb", 9281203.666461302},
{"VLL_EN_M900", 14.164579149999998},
{"ttH_bb", 9451717.2550458},
{"qcd_100to200", 84434559.0},
{"TTTo2L2Nu17", 4298318538.562201},
{"TTToSemiLeptonic6", 57138751583.45202},
{"ttW", 27686862.0},
{"VLL_EE_M550", 378.4951099999999},
{"WWW", 51638.257653960005},
{"VLL_NN_M700", 27.080457},
{"DYJetsToLL_M-50_HT-100to200", 26202328.0},
{"TTZToQQ", 29608637.71729323},
{"ZJetsToNuNu_HT-800To1200", 2055725.5230469361},
{"ZJetsToQQ_HT-800toInf", 10513086.250308977},
{"ttZZ", 498000.0},
{"qcd_1500to2000", 10411831.0},
{"TGJets", 6935139.129627102},
{"dy_200to400", 18455718.0},
{"WZTo3LNu", 83145979.09836997},
{"TTToHadronic8", 34734821996.607994},
{"WJetsToQQ_HT-800toInf", 14476833.800819013},
{"ttWZ", 498000.0},
{"VLL_EN_M550", 589.0643299999999},
{"ttZ", 32793815.0},
{"VLL_EE_M850", 39.047127379999985},
{"ttWW", 944000.0},
{"TTToSemiLeptonic11", 63363746785.32},
{"dy_fxfx_1j", 0.0},
{"VLL_EN_M950", 38.63094899999999},
{"ZJetsToQQ_HT-400to600", 16669536.822226059},
{"TTToHadronic1", 39388467256.86398},
{"TTTo2L2Nu8", 3979048160.395001},
{"ggH_tautau", 278393469.9064},
{"DYJetsToLL_M-4to50_HT-400to600", 2001264.5194430775},
{"VLL_EE_M1000", 14.825747000000002},
{"VLL_NN_M650", 40.048385},
{"WJetsToLNu_HT-400To600", 7444030.0},
{"TTToSemiLeptonic17", 59040696427.85603},
{"WZZ", 17121.264030234},
{"TTTo2L2Nu5", 4213360833.440001},
{"dy_pu", 15296958.0},
{"tttt", 106024.995330672},
{"dy_40to70", 0.0},
{"st_schan_lep", 68767082.31869161},
{"TTToHadronic13", 43873260112.40801},
{"ttHH", 500000.0},
{"WJetsToLNu_HT-200To400", 58225632.0},
{"VLL_EE_M600", 248.85666},
{"TTTo2L2Nu14", 3897563367.062399},
{"dy_1200to2500", 5831760.0},
{"st_tZq", 924058.9126336002},
{"st_antitchan", 6114949908.582959},
{"VLL_EE_M700", 113.84298499999998},
{"dy_800to1200", 6090972.0},
{"VLL_NN_M1000", 3.4763252},
{"ZJetsToNuNu_HT-600To800", 5726462.973848988},
{"qcd_1000to1500", 14394786.0},
{"TTTo2L2Nu9", 4291003926.409401}}

},
{"2017",{
    {"dy", 75384332.0},
    {"qcd_200to300", 42714435.0},
    {"ZJetsToNuNu_HT-2500ToInf", 6446.0},
    {"WJetsToLNu_HT-2500ToInf", 1185699.0},
    {"dy_fxfx_2j", 27638859467.298496},
    {"DYJetsToLL_M-4to50_HT-100to200", 9013361.0},
    {"ZHToTauTau", 3900412.331112001},
    {"zz", 2706000.0},
    {"dy_fxfx", 3050861455465.427},
    {"ZJetsToNuNu_HT-400To600", 9094890.0},
    {"ZJetsToNuNu_HT-1200To2500", 334332.0},
    {"st_tW_top", 183284888.00640005},
    {"ttbar_2l", 7695841311.017003},
    {"THW", 4714331.0},
    {"ZGToLLG", 2942151048.0234017},
    {"WGToLNuG", 21474318870.45336},
    {"st_tZq_Zhad_Wlept", 710609.0680508534},
    {"ttG", 22157555.754240006},
    {"vbfH_WW_2l", 25060273.79328001},
    {"DYJetsToLL_M-50", 1819671163.6799998},
    {"st_schan_had", 108334027.1538623},
    {"WJetsToQQ_HT-600to800", 8761386.0},
    {"VLL_EE_M500", 0.0},
    {"ZZZ", 2628.4716708940005},
    {"DYJetsToLL_M-50_HT-600to800", 5118706.0},
    {"st_tchan", 13808000809.116001},
    {"qcd_50to100", 26243010.0},
    {"qcd_2000toInf", 4112573.0},
    {"WJetsToLNu_HT-600To800", 5545298.0},
    {"ggH_WW_2l", 138353339.5638},
    {"ZJetsToQQ_HT-600to800", 8845052.0},
    {"ggH_ZZ_4l", 28814099.9888},
    {"TTTW", 360000.0},
    {"DYJetsToLL_M-4to50_HT-200to400", 1018593.0},
    {"ttZH", 350000.0},
    {"DYJetsToLL_M-50_HT-1200to2500", 4725936.0},
    {"DYJetsToLL_M-50_HT-800to1200", 4347168.0},
    {"DYJetsToLL_M-50_HT-70to100", 12205958.0},
    {"wz", 7889000.0},
    {"dy_ext", 95647960.0},
    {"WJetsToLNu", 1030816975.0363598},
    {"ttbar_0l", 73140765879.47008},
    {"qcd_700to1000", 32934816.0},
    {"WJetsToQQ_HT-400to600", 9708539.0},
    {"WJetsToLNu_HT-70To100", 44576510.0},
    {"st_tW_antitop", 184446313.3},
    {"WJetsToLNu_HT-1200To2500", 4752118.0},
    {"DYJetsToLL_M-10to50", 68480179.0},
    {"DYJetsToLL_M-50_HT-2500toInf", 1480047.0},
    {"DYJetsToLL_M-4to50_HT-600toInf", 1974671.0},
    {"ggH_ZZ_2l", 14432313.032999994},
    {"ggH_gg", 465183.05253755697},
    {"WWZ", 30386.291709359997},
    {"vbfH_tautau", 10852732.550760003},
    {"DYJetsToLL_M-50_HT-400to600", 5384252.0},
    {"WJetsToLNu_HT-100To200", 47424468.0},
    {"ttWH", 360000.0},
    {"qcd_500to700", 36194860.0},
    {"TTTJ", 354000.0},
    {"ttzp_M1000", 99353.0},
    {"st_schan_hadron", 83147970.29072505},
    {"DYJetsToLL_M-50_HT-200to400", 12451701.0},
    {"ttbar_1l", 104129959042.42812},
    {"vH_nonbb", 5066302.999085},
    {"ZH_HToBB_ZToLL", 381528.22049080016},
    {"ww", 15634116.199513812},
    {"qcd_300to500", 43429979.0},
    {"WJetsToLNu_HT-800To1200", 5088483.0},
    {"VLL_EN_M500", 0.0},
    {"ttH_nonbb", 2540302.943178},
    {"ttH_bb", 9041282.569697702},
    {"qcd_100to200", 54381393.0},
    {"ttW", 27662138.0},
    {"WWW", 36869.1616059},
    {"DYJetsToLL_M-50_HT-100to200", 18648544.0},
    {"ZJetsToNuNu_HT-800To1200", 2041779.0},
    {"ZJetsToQQ_HT-800toInf", 7764804.0},
    {"ttZZ", 327000.0},
    {"qcd_1500to2000", 7701876.0},
    {"TGJets", 6797736.704000087},
    {"WZTo3LNu", 87559049.33500399},
    {"WJetsToQQ_HT-800toInf", 8028207.0},
    {"ttWZ", 350000.0},
    {"ttZ", 31791131.0},
    {"ttWW", 698000.0},
    {"dy_fxfx_1j", 211638650463.3513},
    {"ZJetsToQQ_HT-400to600", 10227695.0},
    {"ggH_tautau", 278582221.6264001},
    {"DYJetsToLL_M-4to50_HT-400to600", 2057894.0},
    {"WJetsToLNu_HT-400To600", 5468473.0},
    {"THQ", 9865010.0},
    {"WZZ", 17023.649914284004},
    {"tttt", 84047.03675157604},
    {"st_schan_lep", 48361411.361051396},
    {"ttHH", 360000.0},
    {"WJetsToLNu_HT-200To400", 42281979.0},
    {"st_tZq", 737624.2674496},
    {"ttzp_M3000", 81011.0},
    {"st_antitchan", 4462869081.826045},
    {"ZJetsToNuNu_HT-600To800", 5664642.0},
    {"qcd_1000to1500", 10186734.0},}
},

{"2016postVFP",{
{"dy", 103360164.0},
{"qcd_200to300", 17569141.0},
{"ZJetsToNuNu_HT-2500ToInf", 405030.0},
{"WJetsToLNu_HT-2500ToInf", 709514.0},
{"dy_fxfx_2j", 61377743073.5482},
{"ZHToTauTau", 451664.57493800024},
{"zz", 1151000.0},
{"dy_fxfx", 1220934627963.0723},
{"ZJetsToNuNu_HT-400To600", 1020309.0},
{"ZJetsToNuNu_HT-1200To2500", 143957.0},
{"st_tW_top", 80821432.59200002},
{"ttbar_2l", 3140127171.4748},
{"THW", 4989133.867540885},
{"ZGToLLG", 3106465270.7114997},
{"WGToLNuG", 19949453763.756798},
{"ggH_bb", 147440978.75400004},
{"ttG", 8868804.739200002},
{"DYJetsToLL_M-50", 1220934627963.0723},
{"st_schan_had", 37656391.852050014},
{"ZZZ", 1066.5219449800002},
{"DYJetsToLL_M-50_HT-600to800", 2299853.0},
{"st_tchan", 6703802049.126003},
{"qcd_50to100", 11197186.0},
{"qcd_2000toInf", 1847781.0},
{"WJetsToLNu_HT-600To800", 2251807.0},
{"TTTW", 159000.0},
{"ttZH", 160000.0},
{"DYJetsToLL_M-50_HT-1200to2500", 1970857.0},
{"DYJetsToLL_M-50_HT-800to1200", 2393976.0},
{"DYJetsToLL_M-50_HT-70to100", 5893910.0},
{"wz", 7584000.0},
{"ttHZ", 145000.0},
{"WJetsToLNu", 9697410121705.158},
{"ttbar_0l", 33608820216.92401},
{"qcd_700to1000", 13750537.0},
{"WJetsToLNu_HT-70To100", 19439931.0},
{"st_tW_antitop", 83024149.938},
{"WJetsToLNu_HT-1200To2500", 2090561.0},
{"DYJetsToLL_M-10to50", 22388550.0},
{"DYJetsToLL_M-50_HT-2500toInf", 696811.0},
{"ggH_gg", 224262.779408616},
{"WWZ", 11495.724679200002},
{"ggH_ww_2l", 60982512.35820003},
{"vbfH_bb", 13604905.523520002},
{"vbfH_tautau", 5790326.143260001},
{"DYJetsToLL_M-50_HT-400to600", 2491416.0},
{"WJetsToLNu_HT-100To200", 19753958.0},
{"ttWH", 160000.0},
{"qcd_500to700", 14212819.0},
{"TTTJ", 160000.0},
{"DYJetsToLL_M-50_HT-200to400", 5653782.0},
{"ttbar_1l", 43548253725.28405},
{"vH_nonbb", 1917613.6729720004},
{"ZH_HToBB_ZToLL", 223865.06672720012},
{"ww", 15821137.255063502},
{"qcd_300to500", 16747056.0},
{"WJetsToLNu_HT-800To1200", 2132228.0},
{"ttH_nonbb", 4656112.5881172},
{"ttH_bb", 4933085.6407413},
{"qcd_100to200", 23717410.0},
{"ttW", 14396003.0},
{"WWW", 14869.109274660004},
{"DYJetsToLL_M-50_HT-100to200", 8316351.0},
{"ZJetsToNuNu_HT-800To1200", 2170137.0},
{"ttZZ", 152000.0},
{"qcd_1500to2000", 3003707.0},
{"TGJets", 648.435550763155},
{"WZTo3LNu", 88368498.47598004},
{"ttWZ", 159000.0},
{"ttZ", 14329456.0},
{"ttWW", 309000.0},
{"ggH_tautau", 138249353.18799996},
{"WJetsToLNu_HT-400To600", 2115509.0},
{"THQ", 9670778.47476965},
{"WZZ", 7833.564293412001},
{"tttt", 36885.692722128006},
{"st_schan_lep", 19433132.409308404},
{"ttHH", 152000.0},
{"WJetsToLNu_HT-200To400", 15067621.0},
{"st_tZq", 307250.9332064001},
{"ggH_zz_4l", 28869643.6672},
{"st_antitchan", 1957283270.7582042},
{"vbfH_ww_2l", 11257548.8256},
{"ZJetsToNuNu_HT-600To800", 5693589.0},
{"qcd_1000to1500", 4365993.0}    }
},

{"2016preVFP",{
    {"dy", 95170542.0},
    {"qcd_200to300", 16524587.0},
    {"WJetsToLNu_HT-2500ToInf", 3879925.0},
    {"dy_fxfx_2j", 0.0},
    {"dy_fxfx_0j", 406307058919.9026},
    {"zz", 1282000.0},
    {"dy_fxfx", 1471067716178.8298},
    {"st_tW_top", 74624666.33600003},
    {"ttbar_2l", 2704527536.2742},
    {"ZGToLLG", 2291513672.0671},
    {"WGToLNuG", 19208075872.49375},
    {"ttG", 9472781.390399998},
    {"vbfH_WW_2l", 0.0},
    {"DYJetsToLL_M-50", 1545707981555.562},
    {"st_schan_had", 33390116.131950013},
    {"ZZZ", 1190.8428809000002},
    {"DYJetsToLL_M-50_HT-600to800", 2681650.0},
    {"st_tchan", 5948135224.055999},
    {"qcd_50to100", 12233035.0},
    {"qcd_2000toInf", 1629000.0},
    {"WJetsToLNu_HT-600To800", 2227346.0},
    {"ggH_WW_2l", 60724515.94020002},
    {"ggH_ZZ_4l", 28875244.710400004},
    {"TTTW", 140000.0},
    {"ttZH", 140000.0},
    {"DYJetsToLL_M-50_HT-1200to2500", 2189664.0},
    {"DYJetsToLL_M-50_HT-800to1200", 2411091.0},
    {"DYJetsToLL_M-50_HT-70to100", 6724232.0},
    {"wz", 7934000.0},
    {"WJetsToLNu", 791830252.8648005},
    {"ttbar_0l", 30530922535.484},
    {"qcd_700to1000", 15808790.0},
    {"WJetsToLNu_HT-70To100", 16931765.0},
    {"st_tW_antitop", 74766343.79400003},
    {"WJetsToLNu_HT-1200To2500", 2119975.0},
    {"DYJetsToLL_M-10to50", 25799525.0},
    {"DYJetsToLL_M-50_HT-2500toInf", 721404.0},
    {"st_schan_leptonDecay", 19596250.124904204},
    {"tZq_ll", 0.0},
    {"WWZ", 13881.850040880001},
    {"DYJetsToLL_M-50_HT-400to600", 2716892.0},
    {"WJetsToLNu_HT-100To200", 21734530.0},
    {"ttWH", 140000.0},
    {"qcd_500to700", 15775001.0},
    {"TTTJ", 138000.0},
    {"DYJetsToLL_M-50_HT-200to400", 5862631.0},
    {"ttbar_1l", 39772305735.140015},
    {"vH_nonbb", 2561276.295292},
    {"ww", 15859130.783078272},
    {"qcd_300to500", 15341307.0},
    {"WJetsToLNu_HT-800To1200", 1932857.0},
    {"ttH_nonbb", 4577157.3517845},
    {"ttH_bb", 4727975.882143499},
    {"qcd_100to200", 26312661.0},
    {"ttW", 14186416.0},
    {"WWW", 15310.596232080003},
    {"DYJetsToLL_M-50_HT-100to200", 9570042.0},
    {"ttZZ", 140000.0},
    {"qcd_1500to2000", 3503675.0},
    {"WZTo3LNu", 81516538.17486201},
    {"ttWZ", 140000.0},
    {"ttZ", 17127765.0},
    {"ttWW", 278000.0},
    {"dy_fxfx_1j", 77533353123.7072},
    {"ggH_tautau", 131717241.93999998},
    {"WJetsToLNu_HT-400To600", 2467498.0},
    {"WZZ", 9141.971308236},
    {"tttt", 34109.10189328801},
    {"st_schan_lep", 0.0},
    {"ttHH", 140000.0},
    {"WJetsToLNu_HT-200To400", 17870845.0},
    {"VBFH_WW_2L", 8576738.438399997},
    {"st_tZq", 287986.5921072001},
    {"st_antitchan", 1983864521.5964816},
    {"qcd_1000to1500", 4773503.0}}
}
};


};
#endif