# Project Cyan Lightning

## Requirements

### Additional features

1. Sidepanel electrification
    - Self-designed PCBs that are connected through HUB75 ribbon cables with the rest of the matrices.
    - Synchronized with the rest of the matrices.
    - Primarily displaying the white dyed lightning 
2. Interior displays
    - Interior status displaying screens to inform the user about the state that the helmet is configured.
    - Since additional LCD/LED screens would hike up the power consumption, the the displays are realized with eInk^TM^ or Raspberry Pi^TM^ status LEDs.
3. Paw Control
    - With BlueTooth communication to the Raspberry Pi^TM^ a microcontroller unit with buttons will change the state configuration of the fursuit.
    - A multiprofile paging for button functions.

### Fine-tuning and development

1. I²C communication system
   - Reimplementing event handling for fixing the issue of memory leaks.
   - Self-designed upper layer protocol for effective and real-time messaging.
   - Platform IO doesn't suppot Wire1.h library, so the usage of multiple I²C will follow the factory design pattern and use the predefined I²CHardware structs for creating a substitution for Wire1..3.
2. HUB75 connectrs
   - Minimizing the size of the HUB75 connectors be removing the plastic housing and using SMT for connections.
   - Custom sized ribbon cables for better cable management and spacious interior.
3. Microphone
    - A feature to be completed since it was partially developed.
    - Soundspectrum analyzation with Fast Fourier Transformation
    - Realizes the lip synchronization of the fursuit, *in case the camera cannot control it.*
4. Code
   - OOP approach for the whole project is an essential feature for making most of the things modular and mitigating the upcoming issues when future developments are being carried out.
   - Using paradigms learnt from Szovertechnikák.
5. Cable management
    - For more organized and spacious interior.

### New technologies

1. Visor development
   - Tougher visor material search.
   - Further development of visor connection parts. Replacing the current one with full magnetic technology. 
2. Camera reapplication
    - Tracking the blink and synchronizing the fursuit in soft real time.
    - If the brightness of the interior makes it possible, the position of the pupil will be tracked and synchronized with fursuit.
    - If the brightness of the interior and the FOV of the camera makes it possible, the lips will be tracked and synchronized with the fursuit.