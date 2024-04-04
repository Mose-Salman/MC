
# ASCII Character Display via Pendulum Swing

A microcontroller project leveraging UART for PC communication, employing interrupts and a LED-based pendulum to display ASCII characters. It utilizes a Texas Instruments EK-TM4C1294XL board, clocked at 120MHz to meet timing constraints, and demonstrates dynamic character display modifications at runtime through a 2-D array bitmap import.

## Features

- **UART Communication**: Facilitates microcontroller to PC data transfer.
- **Interrupt-Driven Display**: Main functionality embedded in interrupts, with the main loop handling initial configurations.
- **LED Pendulum Mechanism**: Innovatively displays ASCII characters.
- **Dynamic Character Update**: Real-time modifications of the display characters.
- **High-Speed Microcontroller Operation**: Ensures timing accuracy for display synchronization.
- **Bitmap-Based Character Importing**: For detailed character visualization.
- **Sizable ASCII Buffer**: Manages incoming character stream efficiently.

## Project Structure

- `src/`: Core source files for interrupt handling and display logic.
- `Debug/`: Compiled binaries and debugging artifacts.
- `targetConfigs/`: Microcontroller setup and configuration files.
- `.settings/`, `.launches/`: IDE-specific configurations for Eclipse.

## Setup

1. **Pre-requisites**: Eclipse IDE with C/C++ Development Tooling (CDT), toolchains for the EK-TM4C1294XL board.
2. **Importing**: Clone and import into Eclipse; configure `targetConfigs` for the EK-TM4C1294XL board.
3. **Building**: Compile and upload to the EK-TM4C1294XL board from Eclipse.

## Diagrams & Circuit

<p align="center">
  <img src="C:\MC\C:\MC\general_program_diagram.png" alt="General Program Diagram"/>
</p>

<p align="center">
  <img src="C:\MC\circuit_figure.png" alt="Connection and General Circuit Figure"/>
</p>

