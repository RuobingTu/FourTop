
lumiMap = {
    "2016preVFP": 19500.,
    "2016postVFP": 16810.,
    "2016": 36310.,
    "UL2017": 41480.0,
    "UL2018", 59830.0,
}


summedProcessList = [ 'tttt', 'tt', 'qcd', 'ttX', 'VV', 'singleTop', 'data' ]

histoGramPerSample = {
    'tttt':'tttt',
    'ttbar_0l':'tt',
    'ttbar_1l': 'tt',
    'ttbar_2l': 'tt',
    'qcd_50to100':'qcd',
    'qcd_100to200':'qcd',
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

    #data
    'jetHT_2016F': 'data',
    'jetHT_2016G': 'data',
    'jetHT_2016H': 'data',
    'jetHT_2016B_v1': 'data',
    'jetHT_2016B_v2': 'data',
    'jetHT_2016C': 'data',
    'jetHT_2016D': 'data',
    'jetHT_2016E': 'data',
    'jetHT_2016F_hipm': 'data',
    'jetHT_2018a': 'data',
    'jetHT_2018b': 'data',
    'jetHT_2018c': 'data',
    'jetHT_2018d': 'data',

    'jetHT_2017b': 'data',
    'jetHT_2017c': 'data',
    'jetHT_2017d': 'data',
    'jetHT_2017e': 'data',
    'jetHT_2017f': 'data',
}


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

    'jetHT_2017b',
    'jetHT_2017c',
    'jetHT_2017d',
    'jetHT_2017e',
    'jetHT_2017f',
]

samplesCrossSection = {
    "tttt": 0.01197,
    "ttbar_2l": 88.29,
    "ttbar_0l": 377.96,
    "ttbar_1l": 365.34,
    "ttG": 4.62 ,#3.773
    "ttZ":  0.783,#0.6559
    "ttW": 0.611 ,#0.2014 changed to 611
     "ttH_bb": 0.2897, # 0.2897
    "ttH_nonbb": 0.209, # 0.20

    "wz": 2.343 ,
    "ww": 6.430 ,
    "zz": 1.016 ,#ZZ
    "st_tZq": 0.07358 ,
    "st_tW_antitop": 35.85 ,#38.06
    "st_tW_top": 35.85 ,#38.09

     "qcd_50to100": 2.466e+08, # 50-100  //2.466e+08 +- 2.190e+05 pb
     "qcd_100to200": 2.801e+07, # 100to200  //2.801e+07 +- 2.608e+04 pb
    "qcd_200to300": 1.721e+6 , # 1.710e+06 +- 1.626e+03 pb
    "qcd_300to500":  3.479e+05, # 3.473e+05 +- 3.327e+02 pb
    "qcd_500to700":  3.206e+04, # 3.220e+04 +- 3.100e+01 pb
    "qcd_700to1000":  6.827e+03,  # 6.839e+03 +- 6.602e+00 pb
    "qcd_1000to1500":  1.207e+03, # 1.207e+03 +- 1.167e+00 pb
    "qcd_1500to2000":  1.20e+02, # 1.201e+02 +- 1.160e-01 pb
    "qcd_2000toInf":  2.525e+01 , # 2.524e+01 +- 2.436e-02 pb
}
