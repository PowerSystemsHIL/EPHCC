import typhoon.api.hil as hil
import numpy as np
import scipy.io
import scipy.signal as sigtool
import os
import matplotlib.pyplot as plt

def phaseDiff(signala, signalb, onePeriodNumberOfSamples):
    # Calculates phase difference between 2 signals
    # Inputs: Two instantaneous data arrays of same size and one period number of samples.
    #         Both signals must have the same frequency.
    # Returns: Phase difference list of first signal regarding to second.

    numberOfSamples = len(signala)
    theta_array = []

    status = True
    if numberOfSamples < onePeriodNumberOfSamples:
        print "ERROR: Number of samples is less than one period number of samples"
        print "%i < %i" % (numberOfSamples, onePeriodNumberOfSamples)
        status = False
        return
    else:
        end_calc = int(round(numberOfSamples / onePeriodNumberOfSamples))
        # print "End_calc: ", end_calc
        for k in range(0, end_calc + 1):
            start = int(onePeriodNumberOfSamples * k)
            stop = int((onePeriodNumberOfSamples * k + onePeriodNumberOfSamples))

            if stop >= numberOfSamples:
                stop = numberOfSamples
                # print "theta: ", theta
                for i in range(start, stop):
                    theta_array.append(theta)
            else:
                sig1 = signala[start:stop]
                sig2 = signalb[start:stop]
                sig1_float = []
                for i in range(0, len(sig1)):
                    sig1_float.append(float(sig1[i]))

                hilb_sig1 = sigtool.hilbert(sig1_float)
                # print "hilb: ", hilb_sig1
                X_corr = sum(hilb_sig1 * sig2 * np.hanning(len(sig1)))
                theta = -(np.angle(X_corr))
                # print "theta: ", theta

                for i in range(start, stop):
                    theta_array.append(theta)

                    # print "Start %i, Stop %i." %(start, stop)
    # print "theta_array: ", theta_array[-10:]
    # print "numberOfSamples %i" %numberOfSamples
    # print "onePeriodNumberOfSamples %i" %onePeriodNumberOfSamples

    return (status, theta_array)

def mean(numbers):
    return float(sum(numbers)) / max(len(numbers), 1)



modelName = 'Banshee_Feeder_1_v3_simpleR'

# Define Path
#PATH = get_settings_dir_path()
PATH = 'C:\\Typhoon\\012 t_cprj\\00 Project management\\10 Customer projects\\91 Lincoln Laboratory 2017_workshop\\91.10 docs\\PowerFlow_Feeder1_Calculations\\Banshee_Feeder_1_v3_simpleR Target files\\'

# load compiled model in VIRTUAL HIL
hil.load_model(file = PATH + 'Banshee_Feeder_1_v3_simpleR.cpd',vhil_device = True)
# load settings file
hil.load_settings_file(file = PATH + 'Settings.runx')


simulationStep = hil.get_sim_step()
#define capture time
period = 5.0/60.0
#define number of samples
nSamples = 500.0e3
#calculates decimation
decimation = 1 #period/(simulationStep*nSamples)
#decimation, numberOfChannels, numberOfSamples
print "Decimation: ",decimation

capturedDataBuffer = []

busPhase = []
busVoltage = []
DGpower = []
steadyState = 0
counter = 0



set_scada_input_value('DIESEL GENSET.Control.P Secondary Control1.Pref', 1.5/3.5)
set_scada_input_value('DIESEL GENSET.Sync_Check.Contactor_Control.Grid_mode', 1.0)
set_scada_input_value('DIESEL GENSET.Control.Q Secondary Control1.Q_Control_Mode', 0.0)
set_scada_input_value('DIESEL GENSET.Control.Exciter1.Vref', 1.0)
set_scada_input_value('DIESEL GENSET.Control.Governor_and_Engine1.wref', 1.0)



hil.start_simulation()

hil.wait_sec(5)
print "Starting Simulation"
#hil.set_cp_input_value('User defined', 'Governor Settings', 'DIESEL GENSET.Control.Governor_and_Engine1.Gen1_On', 1.0)
print "Capture time: ", simulationStep*decimation*nSamples


captureSettings = [decimation,1,nSamples,True]
triggerSettings = ['Forced']
channelSettings = [["DIESEL GENSET.Control.P Secondary Control1.Pmeas"],["DIESEL GENSET.MCB_fb"]]

while steadyState == 0:
    print "starting capture of DG power"

    if hil.start_capture(captureSettings,
                         triggerSettings,
                         channelSettings,
                         dataBuffer=capturedDataBuffer,
                         fileName=PATH + 'DGpower.mat'):

        # when capturing is finished...
        while hil.capture_in_progress():
            pass

        # unpack data from data buffer
        # (signalsNames - list with names,
        #  yDataMatrix  - 'numpy.ndarray' matrix with data values,
        #  xData        - 'numpy.array' with time data)
        (signalsNames, DGpower, xData) = capturedDataBuffer[0]
    else:

        # if error occured
        print "Unable to start capture process."

    p = mean(DGpower[0])*3.5
    c = mean(DGpower[1])
    print "DG power is: ", p, "MW"
    print "DG contactor state is: ", c

    if (p<1.01*1.5 and p>0.99*1.5):
        steadyState = 1
        print "The system is in the desired steady state"
    else:
        print "System still not in steady state. Waiting 30 seconds"
        print "counter is: ", counter
        if counter==5:
            print "Forcing DG contactor to close"
            if hil.set_contactor('DIESEL GENSET.MCB',swControl= True,swState= True):
                print "DG contactor closed"
        counter += 1
        hil.wait_sec(30)
        capturedDataBuffer = []


# Start capturing bus voltages. First capture goes from bus 1 to 16
capturedDataBuffer = []
captureSettings = [decimation,16,nSamples]
triggerSettings = ['Forced']
channelSettings = ["REF","Grid_meas.BUS1","F1_PCC.Meas2.BUS2","F1_CB4.Meas1.BUS3","Feeder1_trafo1.BUS4","Feeder1_trafo2.BUS5",
                   "LOAD.BUS6","F1_CB7.Meas1.BUS7","LOAD2.BUS8","Feeder1_trafo4.BUS9","Coupling10.BUS10",
                   "F1_CB11.Meas1.BUS11","Feeder1_trafo6.BUS12","F1_CB14.Meas1.BUS13","LOAD1.BUS14","DIESEL_MCB.BUS15"]

# start capture process and if everything ok continue...
if hil.start_capture(captureSettings,
                     triggerSettings,
                     channelSettings,
                     dataBuffer = capturedDataBuffer,
                     fileName = PATH + 'busV_1to15.mat'):

    # when capturing is finished...
    while hil.capture_in_progress():
        pass

    # unpack data from data buffer
    # (signalsNames - list with names,
    #  yDataMatrix  - 'numpy.ndarray' matrix with data values,
    #  xData        - 'numpy.array' with time data)
    (signalsNames,yDataMatrix,xData) = capturedDataBuffer[0]

else:

    # if error occured
    print "Unable to start capture process."

print "Voltages from bus 1 to 15 captured. Calculating phase angles.."

counter = 1

while counter <= 15:
    x = []
    x = phaseDiff(yDataMatrix[0],yDataMatrix[counter],16668)
    busPhase.append(mean(x[1])*180/np.pi)
    busVoltage.append(np.sqrt(mean(yDataMatrix[counter]**2)))
    counter += 1

print "Calculation finished."
#print busPhase

# Capturing bus voltages from bus 17 to 19
capturedDataBuffer = []
captureSettings = [decimation,5,nSamples]
channelSettings = ["REF","DIESEL GENSET.Measurements.BUS16","F1_CB12.Meas1.BUS17","F1_CB13.Meas1.BUS18","LOAD3.BUS19"]

# start capture process and if everything ok continue...
if hil.start_capture(captureSettings,
                     triggerSettings,
                     channelSettings,
                     dataBuffer = capturedDataBuffer,
                     fileName = PATH + 'busV_16to19.mat'):

    # when capturing is finished...
    while hil.capture_in_progress():
        pass

    # unpack data from data buffer
    # (signalsNames - list with names,
    #  yDataMatrix  - 'numpy.ndarray' matrix with data values,
    #  xData        - 'numpy.array' with time data)
    (signalsNames,yDataMatrix,xData) = capturedDataBuffer[0]

else:

    # if error occured
    print "Unable to start capture process."

print "Voltages from bus 16 to 19 captured. Calculating phase angles.."

counter = 1

while counter <= 4:
    x = []
    x = phaseDiff(yDataMatrix[0],yDataMatrix[counter],16668)
    busPhase.append(mean(x[1])*180/np.pi)
    busVoltage.append(np.sqrt(mean(yDataMatrix[counter]**2)))
    counter += 1

print "Calculation finished."
#print busPhase

newRef = busPhase[0]
busPhase[:] = [x - newRef for x in busPhase]

# Capturing power

capturedDataBuffer = []
captureSettings = [decimation,4,nSamples]
channelSettings = ["Grid_meas.P","Grid_meas.Q","DIESEL GENSET.Measurements.P_Gen1","DIESEL GENSET.Measurements.Q_Gen1"]

# start capture process and if everything ok continue...
if hil.start_capture(captureSettings,
                     triggerSettings,
                     channelSettings,
                     dataBuffer = capturedDataBuffer,
                     fileName = PATH + 'PowerGen.mat'):

    # when capturing is finished...
    while hil.capture_in_progress():
        pass

    # unpack data from data buffer
    # (signalsNames - list with names,
    #  yDataMatrix  - 'numpy.ndarray' matrix with data values,
    #  xData        - 'numpy.array' with time data)
    (signalsNames,yDataMatrix,xData) = capturedDataBuffer[0]

else:

    # if error occured
    print "Unable to start capture process."

Pgen = []
Qgen = []

Pgen.append(mean(yDataMatrix[0])/1.0e6)
Pgen.append(mean(yDataMatrix[2])*3.5)
Qgen.append(mean(yDataMatrix[1])/1e6)
Qgen.append(mean(yDataMatrix[3])*3.5)

for i in range(0,len(busVoltage)):
    print "Bus %i: _____ Magnitude = %f V _____ Angle = %f degrees" % (i+1,busVoltage[i],busPhase[i])

print "Grid Power: _____ Active = %f MW _____ Reactive = %f MVAr" % (Pgen[0],Qgen[0])
print "DG Power: _____ Active = %f MW _____ Reactive = %f MVAr" % (Pgen[1],Qgen[1])

print "stoping simulation"
hil.stop_simulation()
print "waiting user to stop script"
hil.end_script_by_user()
