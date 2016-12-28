# Electric Power HIL Controls Consortium Repository README

Copyright (c) 2016 Massachusetts Institute of Technology

## Overview
This code base contains Mathworks Simulink Opal-RT models used to simulate power systems in a small test microgrid. The test system used several actual controllers from hardware vendors in a hardware-in-the-loop setup.

 The vision for this work is to create a standardized demonstration and evaluation platform for any available commercial microgrid or device controller in the market using any distribution system topology. The outcome of this work will reduce microgrid development cost, validate marketing claims, and reduce risk of equipment damage, as well as reduce deployment time.
 
The EPHCC repository is intended to be a common resource that microgrid developers can utilize to test new controllers, components, or usage scenarios.  Models exist with various stages of maturity and detail.  Not every version of a model will be correct for any given problem investigation but development details are listed in the documentation.  Those should be consulted as a starting point to familiarize the developer with a given model’s assumptions, validation, time scale, etc. 

## Folder Structure
The folders are organized into subfolders that cover the following areas:
-	**Case Studies**:  Data and stimulus for exercising the systems in particular scenarios
-	**Components**:  Models for devices on a microgrid which range from transformers, generators, cables, and power sources
-	**Distribution Systems**: Networks of connectivity between components which makeup a typical microgrid
-	**High Level Docs**:  Documentation about the repository in general
-	**Simulation Tools**:  Simulation tool specific scripts, setup, and configuration files
-	**Templates**: Model and documentation files that can be referenced to begin new work

Most simulations will look at the interactions from the distribution system point of view so the top level model files can be found under the Distribution Systems folders.

Individual power systems components are organized in their own folder.  And have working unit tests to show how the part functions, how it was intended to be used, and which functions it implements.

The repository is designed to support multiple simulation tools with a separate sub-folder for each simulation environment.  Unit tests at the component level allow a user to validate that each tools implements the component with equivalent results.  In the future the project is planning to have translation tools that could help with taking a component or distribution system from one simulation tool to another.  At present only Simulink and Opal models are represented.  

## Simulink and Opal-RT
When using the Simulink and Opal for simulation of systems the following rules should be followed:
-	Open the repository using the Matlab project file /SimulationTools/SimulinkOpal/HIL.prj
-	Watch for warnings when loading the project file.  The system is designed to work under
    -	Matlab 2013a 32-bit
    -	Matlab Simulink Simscape and SimPowerSystems toolbox
    -	OPAL RT-LAB version 11  
-	After loading the project the path will be correctly configured, but individual simulations need to be run from their respective folders.  For instance the unit test for CHP needs to be run from Components/SimulinkOpal/CHPandThermal/.
-	Templates are provided in the Templates folder and should be the starting point for all new models.
-	Since Opal does not support slx model files all models are saved in the mdl format.  Multiple copies of the same model in different formats is discourged because this greatly complicates the revision control process.  
-	New models should use the component library blocks where needed but should usually keep their own local copies of any setting or configurations needed.  Unit tests should be setup to keep external upstream folder dependencies to a minimum since ensuring that future changes don’t disrupt the test poses an undue burden on future work.



