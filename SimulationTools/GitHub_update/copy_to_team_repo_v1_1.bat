@ECHO OFF

SET EPHCC=..\..\
SET DISTR=..\..\DistributionSystems\SimulinkOpal\Banshee\
SET COMP=..\..\Components\SimulinkOpal\
SET DOCS=..\..\..\MGC_Challange_Docs\
SET DEST=..\..\..\MGCP2017_Team1\

ECHO ABCD %dest%

copy "%DOCS%2017 MGCP Information Packet v1_0.pdf" "%DEST%0_Instruction\2017 MGCP Information Packet v1_0.pdf"
copy "%DOCS%2017 MGCP Information Packet v1_1.pdf" "%DEST%0_Instruction\2017 MGCP Information Packet v1_1.pdf"

xcopy "%DOCS%HardwareSpecs\*.*" "%DEST%1_References\*.*" /S

xcopy %EPHCC%DistributionSystems\SimulinkOpal\Banshee\*.* %DEST%\5_Source\DistributionSystems\SimulinkOpal\Banshee\*.* /S
xcopy %EPHCC%Components\SimulinkOpal\*.* %DEST%5_Source\Components\SimulinkOpal\*.* /S



REM ECHO ********************************************************************************
REM ECHO ************* CREATE DIRECTORY WHICH WILL BE OutputD WITH OPAL-RT ***************
REM ECHO ************* MAKE SURE PRIOR TO THIS NETLIST HAVE BEEN COMPILED  **************
REM ECHO ********************************************************************************
REM rd /s /q Output
REM mkdir Output
REM mkdir Output\0_Source

REM ECHO ********************************************************************************
REM ECHO ************* Copy sources needed for netlist instantiation and template *******
REM ECHO ********************************************************************************
REM copy ..\0_Source\plink_core_impl_template.vhd Output\0_Source\plink_core_impl_template.vhd
REM copy ..\0_Source\plink_master_demo_core_100mhz_pack.vhd Output\0_Source\plink_master_demo_core_100mhz_pack.vhd
REM copy ..\0_Source\plink_slave_core_100mhz_pack.vhd Output\0_Source\plink_slave_core_100mhz_pack.vhd

REM ECHO ********************************************************************************
REM ECHO ************* Copy testbench files *********************************************
REM ECHO ********************************************************************************
REM mkdir Output\1_Testbench
REM copy ..\1_Testbench\plink_core_netlist_tb.vhd Output\1_Testbench\plink_core_netlist_tb.vhd
REM copy ..\1_Testbench\plink_core_netlist_tb_pack.vhd Output\1_Testbench\plink_core_netlist_tb_pack.vhd
REM copy ..\1_Testbench\plink_core_netlist_tb_pack.vhd Output\1_Testbench\plink_core_netlist_tb_pack.vhd

REM ECHO ********************************************************************************
REM ECHO ************* Copy netlists files **********************************************
REM ECHO ********************************************************************************
REM mkdir Output\4_Xilinx
REM mkdir Output\4_Xilinx\plink_master_demo_core_100mhz
REM mkdir Output\4_Xilinx\plink_slave_core_100mhz
REM copy ..\4_Xilinx\plink_master_demo_core_100mhz\plink_master_demo_core_100mhz.ngc Output\4_Xilinx\plink_master_demo_core_100mhz\plink_master_demo_core_100mhz.ngc
REM copy ..\4_Xilinx\plink_slave_core_100mhz\plink_slave_core_100mhz.ngc Output\4_Xilinx\plink_slave_core_100mhz\plink_slave_core_100mhz.ngc

REM ECHO ********************************************************************************
REM ECHO ************* Generate simulation models based on netlists *********************
REM ECHO ********************************************************************************
REM CALL sim_netgen.bat

REM ECHO ********************************************************************************
REM ECHO ************* Copy simulation models based on netlists *************************
REM ECHO ********************************************************************************
REM copy ..\4_Xilinx\plink_master_demo_core_100mhz\plink_master_demo_core_100mhz.vhd Output\4_Xilinx\plink_master_demo_core_100mhz\plink_master_demo_core_100mhz.vhd
REM copy ..\4_Xilinx\plink_slave_core_100mhz\plink_slave_core_100mhz.vhd Output\4_Xilinx\plink_slave_core_100mhz\plink_slave_core_100mhz.vhd

REM ECHO ********************************************************************************
REM ECHO ************* Copy Xilinx project containg simulation & implementation template
REM ECHO ********************************************************************************
REM mkdir Output\4_Xilinx\plink_core_tb
REM copy ..\4_Xilinx\plink_core_tb\plink_core_tb.xise Output\4_Xilinx\plink_core_tb\plink_core_tb.xise

REM ECHO ********************************************************************************
REM ECHO ************* Copy datasheet
REM ECHO ********************************************************************************
REM copy ..\7_Spec\PLink_core_description.pdf Output\PLink_core_description.pdf


REM ECHO ********************************************************************************
REM ECHO ************* END - Zip the file and send to customer      *********************
REM ECHO ********************************************************************************
