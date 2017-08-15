@ECHO OFF

SET EPHCC=..\..\
SET DISTR=..\..\DistributionSystems\SimulinkOpal\Banshee\
SET COMP=..\..\Components\SimulinkOpal\
SET DOCS=..\..\..\MGC_Challange_Docs\
SET DEST=..\..\..\MGCP2017_Team1\

ECHO ABCD %dest%

copy "%DOCS%2017 MGCP Information Packet v1_0.pdf" "%DEST%0_Instruction\2017 MGCP Information Packet v1_0.pdf"
copy "%DOCS%2017 MGCP Information Packet v1_1.pdf" "%DEST%0_Instruction\2017 MGCP Information Packet v1_1.pdf"
copy "%DOCS%2017 MGCP Information Packet v1_2.pdf" "%DEST%0_Instruction\2017 MGCP Information Packet v1_2.pdf"

xcopy "%DOCS%HardwareSpecs\*.*" "%DEST%1_References\*.*" /S

xcopy %EPHCC%DistributionSystems\SimulinkOpal\Banshee\*.* %DEST%\5_Source\DistributionSystems\SimulinkOpal\Banshee\*.* /S
xcopy %EPHCC%Components\SimulinkOpal\*.* %DEST%5_Source\Components\SimulinkOpal\*.* /S

xcopy %EPHCC%SimulationTools\UDP_Tools\*.m %DEST%6_TestSequence\UDP_Tools\*.m /S
xcopy %EPHCC%SimulationTools\UDP_Tools\*.mexw32 %DEST%6_TestSequence\UDP_Tools\*.mexw32 /S
xcopy %EPHCC%SimulationTools\UDP_Tools\*.m %DEST%6_TestSequence\UDP_Tools\*.m /S
xcopy %EPHCC%SimulationTools\TestSequence\*.m %DEST%6_TestSequence\TestSequence\*.m /S
xcopy %EPHCC%SimulationTools\TestSequence\*.png %DEST%6_TestSequence\TestSequence\*.png /S
xcopy %EPHCC%SimulationTools\TestSequence\*.txt %DEST%6_TestSequence\TestSequence\*.txt /S



