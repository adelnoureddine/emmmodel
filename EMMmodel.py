# Copyright (c) 2020, Université de Pau et des Pays de l'Adour.
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the GNU General Public License v3.0
# which accompanies this distribution, and is available at
# https://www.gnu.org/licenses/gpl-3.0.html
#
# Author : Kamar Kesrouani

import csv
import os.path
import time
from datetime import datetime

class EMM():
    def __init__(self):
        
        self.P=0
        # the components of the formula: u = (Cbusy[t]-Cbusy[t-1])/(Ctotal[t]-Ctotal[t-1])
        self.u=0

        # Cbusy=Cuser+Cnice+Csystem
        self.Cbusyt=0
        self.Cbusyt_1=0

        # Ctotal=Cbusy+Cidle
        self.Ctotalt=0
        self.Ctotalt_1=0

        self.Cuser=0  # Time spent in user mode
        self.Cnice=0  # Time spent in user mode with low priority
        self.Csystem=0  # Time spent in system mode

        # idle = Time spent in the idle task.
        # This value should be USER_HZ times the second entry in the /proc/uptime pseudo-file
        self.Cidle=0
        
    def getCPUCycles(self):
        with open('/proc/stat', 'r') as f:
            data = f.readlines()
            for line in data:
                words = line.split()
                cpu = words[0]
                if cpu == 'cpu':
                    self.Cuser = int(words[1])
                    self.Cnice = int(words[2])
                    self.Csystem = int(words[3])
                    self.Cidle = int(words[4])
                    break
                
    # called at the begining of the application execution
    def calculateVar_1(self):
        self.getCPUCycles()

        # calculate CPU cycles
        self.Cbusyt_1 = self.Cuser + self.Cnice + self.Csystem
        self.Ctotalt_1 = self.Cbusyt_1 + self.Cidle

    # called at the end of the application execution
    def calculateVar(self):
        self.getCPUCycles()

        # calculate the final CPU cycles
        self.Cbusyt = self.Cuser + self.Cnice + self.Csystem
        self.Ctotalt = self.Cbusyt + self.Cidle
        
        self.calculateP()
        
    def calculateP(self):
        self.u = (self.Cbusyt - self.Cbusyt_1)/(self.Ctotalt - self.Ctotalt_1)
        if self.u <= 0.5:
            self.P = 3.4495*self.u + 3.8563
        else:
            self.P = 1.4584*self.u + 4.7788 
        
    #save the information in a csv file
    def recordInfo(self, name, time):
        filename = name + '.csv'
        header = ['Time', 'Cuser', 'Cnice', 'Csystem', 'Cidle', 'Cbusyt', ' Cbusyt_1', 'Ctotalt', 'Ctotalt_1', 'u', 'P']
        stats = [time, self.Cuser, self.Cnice, self.Csystem, self.Cidle, self.Cbusyt, self.Cbusyt_1, self.Ctotalt, self.Ctotalt_1, self.u, self.P]
            
        if os.path.isfile(filename):
            with open(filename, 'a', newline='') as csvfile:
                writer = csv.writer(csvfile,
                                    quotechar='|', quoting=csv.QUOTE_MINIMAL)
                writer.writerow(stats)
        else:
            with open(filename, 'a', newline='') as csvfile:
                writer = csv.writer(csvfile,
                                    quotechar='|', quoting=csv.QUOTE_MINIMAL)
                writer.writerow(header)
                writer.writerow(stats)

c1=EMM()
while True:    
    c1.calculateVar_1()  # calculate the variables at the begining of each execution of the application
    time.sleep(1)
    c1.calculateVar()  # calculate the variables and the power at the end of each execution of the application
    now = datetime.now()
    date_time = now.strftime("%H:%M:%S")
    c1.recordInfo("csvFile_Name", date_time)



