
# ASCII Character Display via Pendulum Swing

A microcontroller project leveraging UART for PC communication, employing interrupts and a LED-based pendulum to display ASCII characters. It utilizes a Texas Instruments EK-TM4C1294XL board, clocked at 120MHz to meet timing constraints, and demonstrates dynamic character display modifications at runtime through a 2-D array bitmap import.

<p align="center">
  <img src="images/circuit_figure.png" alt="Connection and General Circuit Figure"/>
</p>

## Features

- **UART Communication**: Facilitates microcontroller to PC data transfer.
- **Interrupt-Driven Display**: Main functionality embedded in interrupts, with the main loop handling initial configurations.
- **LED Pendulum Mechanism**: Innovatively displays ASCII characters.
- **Dynamic Character Update**: Real-time modifications of the display characters.
- **High-Speed Microcontroller Operation**: Ensures timing accuracy for display synchronization.
- **Bitmap-Based Character Importing**: For detailed character visualization.
- **Sizable ASCII Buffer**: Manages incoming character stream efficiently.

<p align="center">
  <img src="images/general_program_diagram.png" alt="General Program Diagram"/>
</p>
## Setup

1. **Pre-requisites**:CCS,  EK-TM4C1294XL board.
2. **Importing**: Clone and import into Eclipse; configure `targetConfigs` for the EK-TM4C1294XL board.
3. **Building**: Compile and upload to the EK-TM4C1294XL board from CCS.




