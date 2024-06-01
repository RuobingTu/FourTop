import types

lumiMap = {
    "2016preVFP": 19500.,
    "2016postVFP": 16810.,
    "2016": 36310.,
    "2017": 41480.0,
    "2018": 59830.0,
    "Run2" : 137620.0,
    "2022": 37300,  
    "2022preEE": 7875,  
    "2022postEE": 26377,  
}

crossSectionMap = {
    "tttt": 0.01337,
    "ttbar_0l": 377.96,
    "ttbar_1l": 365.34,
    "ttbar_2l": 88.29,
    "ttG": 4.62,
    "ttZ": 0.783,
    "ttW": 0.611,
    "ttH_bb": 0.2897,
    "ttH_nonbb": 0.209,
    "wz": 2.343,
    "ww": 6.430,
    "zz": 1.016,
    "st_tZq": 0.07358,
    "st_tW_antitop": 35.85,
    "st_tW_top": 35.85,
    "qcd_50to100": 2.466e+08,
    "qcd_100to200": 2.801e+07,
    "qcd_200to300": 1.721e+6,
    "qcd_300to500": 3.479e+05,
    "qcd_500to700": 3.206e+04,
    "qcd_700to1000": 6.827e+03,
    "qcd_1000to1500": 1.207e+03,
    "qcd_1500to2000": 1.20e+02,
    "qcd_2000toInf": 2.525e+01,
    "WJetsToLNu_HT-200To400": 532.4,
    "WJetsToLNu_HT-400To600": 61.6,
    "WJetsToLNu_HT-600To800": 12.4,
    "WJetsToLNu_HT-800To1200": 5.77,
    "WJetsToLNu_HT-1200To2500": 1.023,
    "WJetsToLNu_HT-2500ToInf": 0.0248,
    "QCD_PT-30to50": 112800000.0,
    "QCD_PT-50to80": 16660000.0,
    "QCD_PT-80to120": 2507000.0,
    "QCD_PT-120to170": 441100.0,
    "QCD_PT-170to300": 113400.0,
    "QCD_PT-300to470": 7589.0,
    "QCD_PT-470to600": 626.4,
    "QCD_PT-600to800": 178.6,
    "QCD_PT-800to1000": 30.57,
    "QCD_PT-1000to1400": 8.92,
    "QCD_PT-1400to1800": 0.8103,
    "QCD_PT-1800to2400": 0.1148,
    "QCD_PT-2400to3200": 0.007542,
    "QCD_PT-3200": 0.0002331,
    "TTto4Q": 419.69,
    "TTto2L2Nu": 98.09,
    "TTtoLNu2Q": 405.80,
    "TTTT": 0.0158,
   
    "VLL_EE_M500": 0.004918,
    "VLL_EN_M500": 0.008811 * 1.98,
    "VLL_NN_M500": 0.001194 * 3.96,
    "VLL_EE_M550": 0.003158,
    "VLL_EN_M550": 0.005739 * 1.98,
    "VLL_NN_M550": 0.0007615 * 3.96,
    "VLL_EE_M600": 0.002079,
    "VLL_EN_M600": 0.003743 * 1.98,
    "VLL_NN_M600": 0.0004964 * 3.96,
    "VLL_EE_M650": 0.001397,
    "VLL_EN_M650": 0.002551 * 1.98,
    "VLL_NN_M650": 0.0003352 * 3.96,
    "VLL_EE_M700": 0.0009504,
    "VLL_EN_M700": 0.001747 * 1.98,
    "VLL_NN_M700": 0.0002255 * 3.96,
    "VLL_EE_M750": 0.0006623,
    "VLL_EN_M750": 0.001215 * 1.98,
    "VLL_NN_M750": 0.0001578 * 3.96,
    "VLL_EE_M800": 0.0004645,
    "VLL_EN_M800": 0.0008622 * 1.98,
    "VLL_NN_M800": 0.0001095 * 3.96,
    "VLL_EE_M850": 0.0003267,
    "VLL_EN_M850": 0.000606 * 1.98,
    "VLL_NN_M850": 7.764e-5 * 3.96,
    "VLL_EE_M900": 0.0002385,
    "VLL_EN_M900": 0.0004428 * 1.98,
    "VLL_NN_M900": 5.562e-5 * 3.96,
    "VLL_EE_M950": 0.0001715,
    "VLL_EN_M950": 0.0003206 * 1.98,
    "VLL_NN_M950": 4e-5 * 3.96,
    "VLL_EE_M1000": 0.0001241,
    "VLL_EN_M1000": 0.0002329 * 1.98,
    "VLL_NN_M1000": 2.909e-5 * 3.96 
    
    
}


genSumDic={
    'ttW': 27686900.0,
    'qcd_2000toInf': 5374710.0,
    'qcd_200to300': 57336600.0,
    'st_tW_top': 258137000.0,
    'WJetsToLNu_HT-200To400': 58225600.0,
    'WJetsToLNu_HT-400To600': 7444030.0,
    'WJetsToLNu_HT-1200To2500': 6481520.0,
    'qcd_1000to1500': 14394800.0,
    'WJetsToLNu_HT-2500ToInf': 2097650.0,
    'qcd_300to500': 61609700.0,
    'qcd_50to100': 38599400.0,
    'tttt': 106025.0,
    'qcd_1500to2000': 10411800.0,
    'ttbar_0l': 104910000000.0,
    'ttbar_2l': 10457600000.0,
    'ttH_nonbb': 9281200.0,
    'WJetsToLNu_HT-600To800': 7718760.0,
    'st_tW_antitop': 251902000.0,
    'st_tZq': 924059.0,
    'ttH_bb': 9451720.0,
    'ww': 15679100.0,
    'zz': 3526000.0,
    'ttG': 27849500.0,
    'qcd_700to1000': 48506800.0,
    'wz': 7940000.0,
    'qcd_500to700': 49184800.0,
    'ttbar_1l': 143354000000.0,
    'WJetsToLNu_HT-800To1200': 7306190.0,
    'ttZ': 32793800.0
}

# summedProcessList = [ 'tttt', 'tt', 'qcd', 'ttX', 'VV', 'singleTop', 'WJets', 'data' ]
summedProcessList = [ 'tttt', 'tt', 'qcd', 'ttX', 'VV', 'singleTop', 'WJets', 'jetHT', 'singleMu' ]

histoGramPerSample = { 
    'tttt':'tttt',
    'ttbar_0l':'tt',
    'ttbar_1l': 'tt',
    'ttbar_2l': 'tt',
    'qcd_50to100':'qcd',
    # 'qcd_100to200':'qcd',//!!!to be updated
    'qcd_200to300':'qcd',
    'qcd_300to500':'qcd',
    'qcd_500to700':'qcd',
    'qcd_700to1000':'qcd',
    'qcd_1000to1500':'qcd',
    'qcd_1500to2000':'qcd',
    'qcd_2000toInf':'qcd',

    "ttG":"ttX",
    "ttZ":"ttX",  
    "ttW":"ttX",
    "ttH_bb": "ttX", 
    "ttH_nonbb": "ttX", 
    "wz":"VV",
    "ww":"VV",
    "zz":"VV",
    "st_tZq":"singleTop",
    "st_tW_antitop":"singleTop",
    "st_tW_top":"singleTop",

    "WJetsToLNu_HT-200To400": "WJets",
    "WJetsToLNu_HT-400To600": "WJets",
    "WJetsToLNu_HT-600To800": "WJets",
    "WJetsToLNu_HT-800To1200": "WJets",
    "WJetsToLNu_HT-1200To2500": "WJets",
    "WJetsToLNu_HT-2500ToInf": "WJets",
    
    "fakeTau_tauF": "fakeTau",
    "fakeTau_tauT": "fakeTau",
    "fakeTau_tauFGen": "fakeTau",
    "fakeTau_tauTGen": "fakeTau",
    
    "VLL_EE_M600": "VLLm600",
    "VLL_EN_M600": "VLLm600",
    "VLL_NN_M600": "VLLm600",
    "VLL_EE_M650": "VLLm650",
    "VLL_EN_M650": "VLLm650",
    "VLL_NN_M650": "VLLm650",
    "VLL_EE_M700": "VLLm700",
    "VLL_EN_M700": "VLLm700",
    "VLL_NN_M700": "VLLm700",
    "VLL_EE_M750": "VLLm750",
    "VLL_EN_M750": "VLLm750",
    "VLL_NN_M750": "VLLm750",
    "VLL_EE_M800": "VLLm800",
    "VLL_EN_M800": "VLLm800",
    "VLL_NN_M800": "VLLm800",
    "VLL_EE_M850": "VLLm850",
    "VLL_EN_M850": "VLLm850",
    "VLL_NN_M850": "VLLm850",
    "VLL_EE_M900": "VLLm900",
    "VLL_EN_M900": "VLLm900",
    "VLL_NN_M900": "VLLm900",
    "VLL_EE_M950": "VLLm950",
    "VLL_EN_M950": "VLLm950",
    "VLL_NN_M950": "VLLm950",
    "VLL_EE_M1000": "VLLm1000",
    "VLL_EN_M1000": "VLLm1000",
    "VLL_NN_M1000": "VLLm1000",
    

    #data
    'jetHT_2016F': 'jetHT',
    'jetHT_2016G': 'jetHT',
    'jetHT_2016H': 'jetHT',
    'jetHT_2016B_v1': 'jetHT',
    'jetHT_2016B_v2': 'jetHT',
    'jetHT_2016C': 'jetHT',
    'jetHT_2016D': 'jetHT',
    'jetHT_2016E': 'jetHT',
    'jetHT_2016F_hipm': 'jetHT',
    'jetHT_2018a': 'jetHT',
    'jetHT_2018b': 'jetHT',
    'jetHT_2018c': 'jetHT',
    'jetHT_2018d': 'jetHT',

    'jetHT_2017b': 'jetHT',
    'jetHT_2017c': 'jetHT',
    'jetHT_2017d': 'jetHT',
    'jetHT_2017e': 'jetHT',
    'jetHT_2017f': 'jetHT',
    
    'singleMu_2016F': 'singleMu',
    'singleMu_2016G': 'singleMu',
    'singleMu_2016H': 'singleMu',
    'singleMu_2016B_v1': 'singleMu',
    'singleMu_2016B_v2': 'singleMu',
    'singleMu_2016C': 'singleMu',
    'singleMu_2016D': 'singleMu',
    'singleMu_2016E': 'singleMu',
    'singleMu_2016F_hipm': 'singleMu',
    'singleMu_2018a': 'singleMu',
    'singleMu_2018b': 'singleMu',
    'singleMu_2018c': 'singleMu',
    'singleMu_2018d': 'singleMu',

    'singleMu_2017b': 'singleMu',
    'singleMu_2017c': 'singleMu',
    'singleMu_2017d': 'singleMu',
    'singleMu_2017e': 'singleMu',
    'singleMu_2017f': 'singleMu',
    
    
}
# histoGramPerSampleR = types.MappingProxyType(histoGramPerSample)


samples = [
    'tttt', 
    'ttbar_0l','ttbar_2l', 'ttbar_1l',
    'qcd_50to100',
    'qcd_100to200',
    'qcd_200to300',
    'qcd_300to500',
    'qcd_500to700',
    'qcd_700to1000',
    'qcd_1000to1500',
    'qcd_1500to2000',
    'qcd_2000toInf',
    "ttG",
    "ttZ",  
    "ttW",
    "ttH_bb", 
    "ttH_nonbb", 
    "wz",
    "ww",
    "zz",
    "st_tZq",
    "st_tW_antitop",
    "st_tW_top",
    # "WJetsToLNu",
    # "WJetsToLNu_HT-100To200",
    "WJetsToLNu_HT-200To400",
    "WJetsToLNu_HT-400To600",
    "WJetsToLNu_HT-600To800",
    "WJetsToLNu_HT-800To1200",
    "WJetsToLNu_HT-1200To2500",
    "WJetsToLNu_HT-2500ToInf",

#2016
    'jetHT_2016F',
    'jetHT_2016G',
    'jetHT_2016H',
    'jetHT_2016B_v1',
    'jetHT_2016B_v2',
    'jetHT_2016C',
    'jetHT_2016D',
    'jetHT_2016E',
    'jetHT_2016F_hipm',
    #2018
    'jetHT_2018a',
    'jetHT_2018b',
    'jetHT_2018c',
    'jetHT_2018d',
    #2017
    'jetHT_2017b',
    'jetHT_2017c',
    'jetHT_2017d',
    'jetHT_2017e',
    'jetHT_2017f',
    
#2016
    'singleMu_2016F',
    'singleMu_2016G',
    'singleMu_2016H',
    'singleMu_2016B_v1',
    'singleMu_2016B_v2',
    'singleMu_2016C',
    'singleMu_2016D',
    'singleMu_2016E',
    'singleMu_2016F_hipm',
    #2018
    'singleMu_2018a',
    'singleMu_2018b',
    'singleMu_2018c',
    'singleMu_2018d',
    #2017
    'singleMu_2017b',
    'singleMu_2017c',
    'singleMu_2017d',
    'singleMu_2017e',
    'singleMu_2017f',
]



Run3Samples = {
    'TTTT': 'tttt', 
    
    'TTto2L2Nu': 'tt',
    'TTto2L2Nu1': 'tt',
    'TTto4Q': 'tt',
    'TTto4Q1': 'tt',
    'TTtoLNu2Q': 'tt',
    'TTtoLNu2Q1': 'tt',
    
    'QCD_PT-50to80': 'qcd',
    'QCD_PT-80to120': 'qcd',
    'QCD_PT-120to170': 'qcd',
    'QCD_PT-170to300': 'qcd',
    'QCD_PT-300to470': 'qcd',
    'QCD_PT-470to600': 'qcd',
    'QCD_PT-600to800': 'qcd',
    'QCD_PT-800to1000': 'qcd',
    'QCD_PT-1000to1400': 'qcd',
    'QCD_PT-1400to1800': 'qcd',
    'QCD_PT-1800to2400': 'qcd',
    'QCD_PT-2400to3200': 'qcd',
    'QCD_PT-3200': 'qcd',
    
    'JetHT2022C': 'jetHT',
    'JetMET2022C': 'jetHT',
    'JetMET2022D': 'jetHT',
    #2022postEE
    'JetMET2022E': 'jetHT',
    'JetMET2022F': 'jetHT',
    'JetMET2022G': 'jetHT',
    
    #Muon
    'SingleMuon2022C': 'singleMu',
    'Muon2022C': 'singleMu',
    'Muon2022D': 'singleMu',
    'Muon2022E': 'singleMu',
    'Muon2022F': 'singleMu',
    'Muon2022G': 'singleMu',
    
}

dataDict = {
    '2022preEE':['2022C', '2022D'],
    '2022postEE': ['2022E', '2022F', '2022G'],
    '2016': ['2016B', '2016C', '2016D', '2016E', '2016F'],
    '2017': ['2017b', '2017c', '2017d', '2017e', '2017f'],
    '2018': ['2018a', '2018b', '2018c', '2018d'],
}