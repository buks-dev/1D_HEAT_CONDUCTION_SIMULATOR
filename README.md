# KWARA STATE UNIVERSITY

MALETE P.M.B. 1530, ILORIN, KWARA STATE, NIGERIA.

<img width="227" height="155" alt="image" src="https://github.com/user-attachments/assets/a221950a-0af9-4183-8597-3e0be125c206" />


## FACULTY OF ENGINEERING AND TECHNOLOGY

### DEPARTMENT OF AERONAUTICAL AND ASTRONAUTICAL ENGINEERING

<img width="196" height="167" alt="image" src="https://github.com/user-attachments/assets/db534408-ad56-499d-9054-a2d867d163f5" />


### AAE202: APPLICATION OF MATLAB IN AEROSPACE ENGINEERING

## INSTRUCTOR :

ENGR. DOUGLAS

## AUTHOR :

**OSOKOYA OLUWABUKUNMI OLADAPO**

# 1D HEAT CONDUCTION SIMULATOR

BY OSOKOYA OLUWABUKUNMI OLADAPO

WITH MATLAB AND C++ IMPLEMENTATION

<img width="520" height="260" alt="image" src="https://github.com/user-attachments/assets/51d71771-f912-49be-a031-d28c622cdae0" />


This report details the development and implementation of a 1D heat conduction simulator using explicit finite-difference methods, integrating MATLAB for visualization and GUI interaction with a C++ MEX solver for computational efficiency.

## Overview

This project implements a transient one-dimensional (1D) heat conduction simulator for multi-layer slabs using the explicit finite-difference method. The simulator features a user-friendly graphical user interface (GUI) built with MATLAB App Designer for input, visualization, and real-time animations. For computational efficiency, it integrates a C++ MEX solver, providing significant speedups over pure MATLAB implementations.

The tool solves the 1D heat equation:

∂T/∂t = α ∂²T/∂x²

Discretized as:

$T_i^{n+1} = T_i^n + r \left( T_{i+1}^n - 2 T_i^n + T_{i-1}^n \right)$

where $r = \frac{\alpha \Delta t}{\Delta x^2} \leq 0.5$ for stability.

It supports multi-layer configurations, initial and boundary conditions, and exports results to TXT files. Developed as part of the AAE202: Application of MATLAB in Aerospace Engineering course at Kwara State University.

## Author

- **Osokoya Oluwabukunmi Oladapo**

**Instructor**: Engr. Douglas

## Features

- **Interactive GUI**: Tabs for input, simulation, data import, settings, and performance comparison.
- **Multi-layer Support**: Specify number of layers, thermal diffusivity ($\alpha$), spatial step ($\Delta x$), time step ($\Delta t$), and initial temperature distribution.
- **Solver Options**: Choose between MATLAB or C++ MEX for computation.
- **Visualizations**: Real-time temperature profile plots, animated heat diffusion, and exportable results.
- **Data Handling**: Import initial temperatures from CSV files for large datasets.
- **Performance Monitoring**: Tic-Toc timing for runtime comparisons between solvers.
- **Stability Checks**: Automatic validation of $r \leq 0.5$  to ensure numerical stability.
- **Export Functionality**: Save simulation results (parameters and final temperatures) to TXT files.

## Requirements

- MATLAB with App Designer and MEX support.
- C++ compiler (e.g., Microsoft Visual C++ or GCC) for compiling the MEX file.

## Installation and Compilation

1. **Clone/Download the Project**: Ensure you have the MATLAB app file `One_Dimensional_Heat_Conduction_Simulator.mlapp` and the C++ source `HeatSlab.cpp`.

2. **Compile the C++ MEX Solver**:
   Open MATLAB and run the following command in the project directory:
   ```
   mex HeatSlab.cpp -output heat_slab_mex
   ```
   This generates the MEX file `heat_slab_mex` for integration.

3. **Launch the GUI**:
   - Open `One_Dimensional_Heat_Conduction_Simulator.mlapp` in MATLAB App Designer.
   - Click **Run** to start the simulator.

## Usage

1. **Input Tab**: Enter parameters such as initial temperatures, ($\alpha$), ($\Delta x$), ($\Delta t$), number of steps, and layers.
2. **Data Import Tab**: Load initial temperatures from a CSV file for complex distributions.
3. **Settings Tab**: Select solver (MATLAB or C++ MEX), boundary conditions, and animation speed.
4. **Run Simulation**: Click **Simulate** to compute and visualize results.
5. **Performance Comparison Tab**: View runtime benchmarks.
6. **Export**: Save results to a TXT file via the **Export** button.

<img width="549" height="387" alt="image" src="https://github.com/user-attachments/assets/26c835a1-5c2a-4f87-ac71-cfa7aebfed3a" />

*Screenshot of the Input tab with yellow background, showing fields for Alpha, dt, dx, Steps, Layers, and T0.*

<img width="576" height="406" alt="image" src="https://github.com/user-attachments/assets/ba60798f-7eef-424b-a53c-21413baf80ed" />

*Screenshot of the Simulation tab with green background, displaying a temperature profile plot after 1000 steps using C++ solver, along with buttons for Run, Animate, Reset, and Export.*

<img width="576" height="406" alt="image" src="https://github.com/user-attachments/assets/b2a2ae40-b6ff-424d-b86a-2ba374af4260" />

*Screenshot of the Data Import tab with cyan background, showing a table for Initial Temperature (T0) and a Load CSV button.*

### Sample Input

- **Initial Temperatures**: `[20, 20, 50, 20, 20]` (or load from CSV).
- **Thermal Diffusivity ($\alpha$)**: `0.1`
- **Spatial Step ($\Delta x$)**: `0.1`
- **Time Step ($\Delta t$)**: `0.005`
- **Number of Steps**: `1000`
- **Number of Layers**: `5`
- **Solver**: C++ MEX
- **Boundary Conditions**: Fixed temperatures at ends.

### Sample Output

- **Temperature Profile Plot**: Shows heat diffusion over time (e.g., smoothing from initial hot spot).
- **Animation**: Real-time visualization of temperature evolution.
- **Exported '.txt' File Example**:
  ```
  Heat Conduction Simulator Results
  Generated on: 08-Aug-2025 16:35:52

  Input Parameters:
  Initial Temperature (T0): [100 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20]
  Thermal Diffusivity (alpha): 0.0001
  Spatial Step (dx): 0.0100
  Time Step (dt): 0.1000
  Number of Steps: 1000
  Number of Layers: 50
  Solver Used: C++

  Output Temperature Array (T_out):
  [100; 95.4909933273275; 91.0044697958878; ... ; 20]
  ```

## GUI Interface, Sample Inputs and Results

The simulator was tested with a sample configuration: T0 = data loaded from a CSV file, α = 0.1, ∆x = 0.1, ∆t = 0.005, and 1000 steps. The resulting temperature profile smoothed over time, consistent with heat diffusion principles.

<img width="576" height="406" alt="image" src="https://github.com/user-attachments/assets/5160e33c-df99-4959-ace1-9655565869ab" />

*Screenshot of the Settings tab with blue background, showing Simulation Solver toggle (Matlab/C++), checkboxes for Initial Condition and Boundary Condition, and Animation Speed slider.*

## Performance

The C++ MEX solver provides substantial speedups for large grids. Example benchmarks (for 50 layers, 1000 steps):

| Solver    | Runtime (seconds) |
|-----------|-------------------|
| MATLAB   | 0.0088            |
| C++ MEX  | 0.0005            |

This demonstrates over 10x improvement, making it suitable for large-scale simulations.

<img width="573" height="404" alt="image" src="https://github.com/user-attachments/assets/191e716a-e785-4204-81ea-1bb71dd39e27" />

*Screenshot of the Performance Comparison tab with purple background, showing a report of comparison between Matlab and C++ solver times.*

Performance comparisons showed the C++ MEX solver to be significantly faster than the MATLAB solver for large grids, with runtimes recorded in the Performance Comparison Tab.

## Challenges and Solutions

### Challenges
- Ensuring stability (\( r \leq 0.5 \)).
- Building an intuitive GUI with error handling.
- Maintaining performance for large simulations.

### Solutions
- Input validation and stability checks.
- Modular, object-oriented MATLAB code with GUI tabs.
- C++ MEX integration for high-speed computation.
- Extensive testing for edge cases.

## Additional Notes

- **Special Statements**: Uses MATLAB App Designer components, C++ `std::vector` for memory efficiency, MEX API, loops, conditionals, and plotting functions.
- **GUI Screenshots**: The interface includes tabs for simulation inputs, data import (with CSV loader), settings (solver selection), and performance reports. Plots display node-based temperature profiles.

## Conclusion

This simulator demonstrates the synergy of MATLAB's visualization capabilities and C++'s computational power for efficient, interactive heat conduction analysis. It ensures numerical accuracy and stability, enabling aerospace engineers to explore thermal diffusion in multi-layer structures.

For questions or contributions, contact the author.
