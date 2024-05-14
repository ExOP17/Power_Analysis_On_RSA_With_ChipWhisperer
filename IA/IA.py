import numpy as np
from tqdm import tqdm 
import matplotlib.pyplot as plt
import random



class couche:
    def __init__(self,nbr_neurone,nbr_parametre,numero_couche):
        self.nbr_neurone = nbr_neurone
        self.nbr_parametre = nbr_parametre
        self.numero = numero_couche
        
    def initialisation(self):
        self.W = np.random.randn(self.nbr_parametre,self.nbr_neurone)
        self.b = np.random.randn(self.nbr_neurone)
        
            
    
    def model(self,X,y):
        self.y = y
        self.Z = np.dot(X,self.W) + self.b
        self.A = 1/(1 + np.exp(-self.Z))
        
        
    def LogLoss(self):    
        self.L = -1/len(self.y) * np.sum(self.y * np.log(self.A + 1e-15) + (1-self.y)*np.log(1-self.A + 1e-15))
        
    def gradient(self,X,dZ):
        self.dW = 1/len(self.y) * np.dot(X.transpose(),dZ) ## vrai car on injecte le fonction d'activation A de la couche precedente en tant que X
        self.db = 1/len(self.y) * np.sum(dZ)
        self.dZ_pre = np.dot(self.dW,dZ.transpose()).transpose() * X * (1-X)
    
    def descente_gradients(self,pas):
        self.W = self.W - pas*self.dW
        self.b = self.b - pas*self.db




class binary_model:
    def __init__(self,name):
        self.name = name
        self.L_evolution=[]
    
    def initialisation(self,neurones_specs):
        couche_neurones=[]
        for i in range(len(neurones_specs)):
            couche_neurones.append(couche(neurones_specs[i]["neurones"],neurones_specs[i]["parametres"],neurones_specs[i]["couche"]))
            couche_neurones[i].initialisation()
        self.couche_neurones=couche_neurones
        self.neuron_numbers=len(self.couche_neurones)
        
    
    def forward_propagation(self,X,y):
        X_train = X
        for i in range(self.neuron_numbers):
            self.couche_neurones[i].model(X_train,y)
            X_train = self.couche_neurones[i].A
        self.couche_neurones[(self.neuron_numbers -1)].LogLoss()        

    
    
    def test(self,X_test,y_test):
        L=[]
        X=X_test
        for i in range(self.neuron_numbers):
            self.couche_neurones[i].model(X,y_test)
            X=self.couche_neurones[i].A
        y_prediction =(self.couche_neurones[(self.neuron_numbers -1)].A >= 0.5).astype(int)
        return y_prediction
    
    def score_F1(self,y,y_prediction):
        TP = 0
        FP = 0
        FN = 0
        for i in range(len(y)):
            if(y_prediction[i]==1):
                if(y[i]==1):
                    TP+=1
                else:
                    FP+=1
            else:
                if(y[i]==1):
                    FN += 1
            
        self.precision = TP/(TP + FP)
        self.recall = TP/(TP + FN)
        self.F1_score = 2 *((self.precision*self.recall)/(self.precision+self.recall)) 
        
    def prediction(self,X):
        X_compute = X
        for i in range(self.neuron_numbers):
            self.couche_neurones[i].model(X_compute,0)
            X_compute=self.couche_neurones[i].A
        return ((self.couche_neurones[(self.neuron_numbers -1)].A >= 0.5).astype(int))
    
    def back_propagation(self,X,pas):
        L = self.couche_neurones[(self.neuron_numbers-1)].LogLoss()
        dZ=self.couche_neurones[(self.neuron_numbers-1)].A - self.couche_neurones[(self.neuron_numbers-1)].y
        X_train=self.couche_neurones[(self.neuron_numbers-2)].A
        for i in reversed(range(1,self.neuron_numbers)):
            self.couche_neurones[i].gradient(X_train,dZ)
            X_train=self.couche_neurones[i-1].A
            dZ=self.couche_neurones[i].dZ_pre
        self.couche_neurones[0].gradient(X,dZ)
        
        for i in self.couche_neurones:
            i.descente_gradients(pas)


    def train(self,X,y,pas,epoch,batch_size,step=1):
        for i in tqdm(range(epoch)):
            iteration_start=random.randint(0,(len(y)-batch_size-1))
            X_train = X[iteration_start:(iteration_start+batch_size)]
            y_train = y[iteration_start:(iteration_start+batch_size)]
            self.forward_propagation(X_train,y_train)
            self.back_propagation(X_train,pas)
            if (i%step==0):
                self.L_evolution.append(self.couche_neurones[(self.neuron_numbers-1)].L)
            if (i%2500==0): 
                pas = pas - ((1/20)*pas)
                self.pas = pas
    
    def plot_L(self):
        plt.plot([i for i in range(len(self.L_evolution))],self.L_evolution,label='LogLoss')
        plt.show(self.L_evolution)
        
    def reset_L(self):
        self.L_evolution_backup=self.L_evolution
        self.L_evolution=[]
        
    def print_gradient(self):
        return self.couche_neurones[0].dW
        
        
