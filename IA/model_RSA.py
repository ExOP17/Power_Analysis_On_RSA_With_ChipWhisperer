import IA
import numpy as np

#Défintion de la taille d'un échantillon
TE = 20

#Création d'un model de classification binaire
RSA_model=binary_model("RSA_Power_Analysis")
RSA_model.initialisation([{"couche":1 ,"neurones":64 ,"parametres":TE },{"couche":2 ,"neurones":64 ,"parametres":64 },{"couche":3 ,"neurones":1 ,"parametres":64 }])

#Entrainement

epoch = 500
pas = np.array([0.3])
batch_size = 10
#pas est les taux d'apprentissage plus il est faible plus l'entrainement sera précis et long
# X_train est un tableau de données pour l'entrainement
# Label_train est le tableau correspondant aux résultats des données d'entrainement
# batch_size est la taille de paquet a utiliser sur les données d'entrainement (1/10 de la taille totale peut etre pas mal)

RSA_model.train(X_train,Label_train,pas,epoch,batch_size,step=1)

# Vérification de la fiabilité du model

RSA_model.score_F1(Label_test,RSA_model.prediction(X_test))
print(RSA_model.score_F1)



