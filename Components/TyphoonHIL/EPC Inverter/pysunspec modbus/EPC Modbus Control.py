import sunspec
import sunspec.core.client as client
import time

#.40 is ESS
#.41 is PV

ESS = client.SunSpecClientDevice(client.TCP, 1, ipaddr='192.168.10.41', max_count=10)
#PV = client.SunSpecClientDevice(client.TCP, 1, ipaddr='192.168.10.40', max_count=10)
#print sunpec models
print(ESS.models)

#Read common model
ESS.common.read()
print(ESS.common)

#Set to control source 0=CAN 1=Modbus
ESS.epc.read()
print(ESS.epc)
ESS.epc.CtlSrc = 1
ESS.epc.write()


ESS.inverter.read()
if ESS.inverter.StVnd == 3:
    #stop
    ESS.epc.CmdBits = 4648
    ESS.epc.write()
    ESS.epc.read()
    print(ESS.epc)
    time.sleep(.5)
    ESS.inverter.read()
    print(ESS.inverter.StVnd)

    #stop and clear faults
    ESS.epc.CmdBits = 4650
    ESS.epc.write()
    ESS.epc.read()
    print(ESS.epc)
    time.sleep(.5)
    ESS.inverter.read()
    print(ESS.inverter.StVnd)

    #stop
    ESS.epc.CmdBits = 4648
    ESS.epc.write()
    ESS.epc.read()
    print(ESS.epc)
    time.sleep(.5)
    ESS.inverter.read()
    print(ESS.inverter.StVnd)


# i=0
# for i in range(10):
#     #enable and run
#     d.epc.CmdBits = 4649
#     d.epc.CmdRealPwr = 100
#     d.epc.CmdReactivePwr = 0
#     d.epc.CmdV = 480
#     d.epc.CmdHz = 60
#     d.epc.write()
#     time.sleep(.5)
#     # d.epc.read()
#     # print(d.epc)
#     d.inverter.read()
#     print(d.inverter.StVnd)
#
# i=0
# for i in range(10):
#     #enable and run
#     ESS.epc.CmdBits = 5647 #4649
#     ESS.epc.CmdRealPwr = 100
#     ESS.epc.CmdReactivePwr = 0
#     ESS.epc.write()
#     time.sleep(.5)
#     # d.epc.read()
#     # print(d.epc)
#     ESS.inverter.read()
#     print(ESS.inverter.StVnd)


ESS.epc.CmdRealPwr = 200
ESS.epc.CmdReactivePwr = -50
ESS.epc.CmdV = 480
ESS.epc.CmdHz = 60
ESS.epc.write()

print(ESS.epc)