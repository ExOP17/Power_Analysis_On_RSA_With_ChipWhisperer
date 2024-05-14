import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft, ifft
from math import sqrt
from sklearn.cluster import DBSCAN
from sklearn.decomposition import PCA



# plt.figure()

# for i in range(2,len(signal)):
# 	truc = signal
# 	truc[i-1:] = 0
# 	truc[:i] = 0
# 	truc = ifft(truc)
# 	plt.plot(np.real(truc))





# plt.figure()
# plt.plot(np.real(signal))
# plt.show()


def fourier(trace,nbr_frequences):
    if type(trace)!=np.ndarray:
        trace = np.array(sample1)

    signal = fft(trace)
    signal[nbr_frequences:] = 0
    signal = ifft(signal)
    return signal


def compare_patern_correlation(sample1, sample2):
    if len(sample1)!=len(sample2):
    	return 69

    if type(sample1)!=np.ndarray:

    	sample1 = np.array(sample1)
    	sample2 = np.array(sample2)

    moy1 = np.mean(sample1)
    moy2 = np.mean(sample2)

    ecart_type1 = np.std(sample1)
    ecart_type2 = np.std(sample2)


    sample1_centered = (sample1 - moy1) / ecart_type1
    sample2_centered = (sample2 - moy2) / ecart_type2

    # Calcul du coefficient de corrélation de Pearson
    correlation_coefficient = np.corrcoef(sample1_centered, sample2_centered)[0, 1]

    return np.real(correlation_coefficient)



# def find_pattern_existence(tab,start_range,range_len_pattern,nbr_pattern_min):

    # list_pattern1 = []
    # list_pattern2 = []
    # list_pattern_final = []
    # incrementation = 0

    # for len_pattern in range(start_range,range_len_pattern):#On teste toutes les tailles de patterns

    #     for sample1 in range(len(tab)-len_pattern): # On parcours le tableau et on prend deux échantillions que l'on compare
    #         if incrementation>0:
    #             incrementation-=1
    #             continue
    #         for sample2 in range(len(tab-len_pattern)):
    #             if len(tab[sample1:sample1+len_pattern]) == 0:
    #                 print(sample1+len_pattern,len(tab))
    #             #Calcul du coef de corelation entre les deux échantillions
    #             corelation = compare_patern_correlation(tab[sample1:sample1+len_pattern],tab[sample2:sample2+len_pattern])
    #             if (corelation >= 0.9 and corelation <= 1): 
    #                 # print("ouhou")
    #                 # plt.figure()
    #                 # plt.plot(tab[sample1:sample1+len_pattern])
    #                 # plt.plot(tab[sample2:sample2+len_pattern])
    #                 # plt.show()

    #             # Si le premier echantillion match avec le deuxieme on l'ajoute dans la liste des patterns 
    #             # et on décale le premier échantillion pour ne pas avoir plusieurs fois le meme positif 
                    
    #                 list_pattern1.append(tab[sample1:sample1+len_pattern])
    #                 incrementation = len_pattern
    #                 break
    #     print(len(list_pattern1))            
    #     #lorsque sample1 est le meme que sample2 il s'ajoute dans la liste
    #     #on le supprime ici en regardant si un pattern est retrouvé plus d'une fois
    #     print(len(list_pattern1),len(list_pattern2))
    #     for pattern1 in list_pattern1:
    #         if len(list_pattern2) > 0:
    #             for pattern2 in list_pattern1:
    #                 # print("ouhou")
    #                 if(pattern1.all()==pattern2.all()): # si pattern1 == pattern2 on ne vérifie pas car faux positif
    #                     continue
    #                 corelation = compare_patern_correlation(pattern1,pattern2)
    #                 print(corelation)
    #                 if (corelation > 0.90 and corelation <= 1):
    #                     list_pattern2.append(pattern1)
    #         else:
    #             list_pattern2=list_pattern1


    #     #Puisqu'on augmente a chaque fois la taille possible du pattern on verifie s'il existe
    #     # encore des patterns lorsqu'on augmente celle ci
    #     # si on ne trouve plus de pattern cela veut dire qu'il n'y a pas de patterns de cette
    #     # taille ou plus on arrête la recherche et on revoie la liste finale
    #     # si on trouve des patterns on écrase la liste finale avec la nouvelle liste de patterns

    #     if len(list_pattern2)>nbr_pattern_min:
    #         list_pattern_final = list_pattern2
    #         list_pattern2 = []
    #         list_pattern1 = []
    #     else:
    #         break

    # return list_pattern_final

def find_pattern_existence (tab,len_sample):
    list_pattern = []
    moy1 = 0

    for i in range(len(tab)-len_sample):
        skip = 0
        if skip > 0:
            skip -= 1 
            continue

        for j in range(len(tab)-len_sample):
            cpt = 0  
            moy = 0 

            test = compare_patern_correlation(tab[i:i+len_sample],tab[j:j+len_sample])
            if test > 0.55 :
                if compare_patern_correlation(tab[i+1:i+len_sample+1],tab[j+1:j+len_sample+1]) > test:
                    continue
                else:
                    cpt += 1
                    moy += test 
        if cpt > 0:
            moy/=cpt 

        if moy > 0.55 :
            if moy > moy1:

                moy1 = moy 
                continue
            else:
                list_pattern.append(tab[i-1:i-1+len_sample])
                moy1 = 0 
                skip = len_sample
    return list_pattern

def plot_pattern_correlation(tab,len_sample):
    plt.figure()
    plt.plot(tab*25)
    tab_3D = []
    for i in range(len(tab)-len_sample):
        for j in range(len(tab)-len_sample):
            tab2 = []
            tab2.append(compare_patern_correlation(tab[i:i+len_sample],tab[j:j+len_sample]))
        tab_3D.append(tab2)

    plt.plot(tab_3D)
    plt.show()


def find_pattern(tab,pattern):
    list_pattern = []
    skip = 0
    for i in range(len(tab)-len(pattern)):
        if(skip>0):
            skip-=1
            continue
        corelation = compare_patern_correlation(tab[i:i+len(pattern)],pattern)
        # print(corelation)
        if corelation > 0.9 and corelation <= 1:
            # print("ohou")
            list_pattern.append(tab[i:i+len(pattern)])
            skip = len(pattern)
            plt.figure()
            plt.plot(tab[i:i+len(pattern)])
            plt.show()
    return list_pattern

def solve_rsa_key(trace,pattern_1,pattern_0):
    res = ""
    skip = 0
    for i in range(len(trace)):
        if(skip>0):
            skip-=1
            continue
        if(len(trace)>i+len(pattern_1)):
            
            corelation = compare_patern_correlation(pattern_1,trace[i:i+len(pattern_1)])
            if(corelation>0.9 and corelation <=1):
                res+="1"
                skip+=len(pattern_1)

        if(len(trace)> i+len(pattern_0)):
            corelation = compare_patern_correlation(pattern_0,trace[i:i+len(pattern_0)])
            if(corelation>0.9 and corelation <=1):
                res+="0"
                skip+=len(pattern_0)

    return res[::-1]
















file = open("trace.txt",'r')
trace = eval(file.read())[:400]
x = np.array(trace)

signal = np.real(fourier(x,40))

# dbscan = DBSCAN(eps=0.5, min_samples=4)
# caca = []
# for i in range(len(signal)-40):
#     caca.append(signal[i:i+40])




# plot_pattern_correlation(signal,40)
# test = find_pattern_existence(signal,40)

# for i in test:
#     plt.figure()
#     plt.plot(i)
# plt.figure()
# plt.plot(signal)
# plt.show()

s1 = signal[55:85]
s2 = signal[90:125]

truc = solve_rsa_key(signal,s1,s2)
# print(truc)

# pat = find_pattern_existence(signal,50,100,6)
# print(len(pat))
# patt = find_pattern(signal,signal[55:85])

# print(len(patt))
# print(compare_patern_correlation(pat[0],patt[1]))

# for i in pat:
#     for k in pat:
#         print(compare_patern_correlation(i,k))


# for i in patt:
#     plt.figure()
#     plt.plot(i)
# plt.plot(patt[1])
# plt.plot(pat[4])
# plt.plot(patt[0])

# plt.show()
# plt.figure()
# plt.plot(signal[55:85])
# for fig in patt:
#     plt.plot(fig)
# plt.show()
# plt.plot(s1)
# plt.plot(s2)
# plt.show()
# plt.figure()
# plt.plot(signal)
# plt.show()
plt.plot(x)
plt.show()
plt.plot(signal)
print(truc)
plt.show()




