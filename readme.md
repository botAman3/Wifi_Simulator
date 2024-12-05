WiFi Simulation Project
Overview
This project simulates the performance of three different Wi-Fi technologies: Wi-Fi 4 (CSMA/CA), Wi-Fi 5 (MU-MIMO), and Wi-Fi 6 (OFDMA). The simulation calculates the throughput, average latency, and maximum latency for each Wi-Fi technology under varying numbers of users. The goal is to provide insights into how network performance changes as the number of connected users increases, with a focus on differences in throughput and latency across Wi-Fi versions.

The project is implemented in C++ and is designed to compare the behavior of different Wi-Fi technologies in terms of data transmission and channel access mechanisms.

Key Features
Wi-Fi 4 (CSMA/CA):

Simulates the use of Carrier Sense Multiple Access with Collision Avoidance (CSMA/CA), a protocol used by Wi-Fi 4 (802.11n) to manage channel access and avoid collisions.
Wi-Fi 5 (MU-MIMO):

Simulates Multi-User Multiple Input Multiple Output (MU-MIMO) technology, which allows multiple devices to communicate simultaneously by using multiple spatial streams.
Wi-Fi 6 (OFDMA):

Simulates Orthogonal Frequency Division Multiple Access (OFDMA), a technology that divides the communication channel into sub-channels, allowing multiple devices to share the same frequency band efficiently.
Performance Metrics:

Throughput: Measured in Mbps (Megabits per second), representing the rate at which data is transmitted over the network.
Average Latency: The average time taken for data to travel from the sender to the receiver.
Maximum Latency: The maximum time delay observed during the transmission process.
Libraries and Tools Used
This project is written in C++ and utilizes the following:

Standard C++ Libraries:
"iostream": For input/output operations (printing to console).
"vector": For storing and managing dynamic arrays of users and packets.
"cstdlib": For generating random numbers (used for backoff in Wi-Fi 4 simulation).
"ctime": For time-related functions (seeding the random number generator).
"thread" and "chrono": For simulating delays during data transmission (representing the time taken to transmit packets).









Compilation and Running the Project
Requirements
G++ compiler (version 4.9 or higher)
Make build system
Steps to Compile and Run
Clone the repository (if applicable) or download the project files to your local machine.

Compile the project:

Open a terminal in the project directory.
Run the following command to compile the project:
bash
Copy code
make
This will compile the source files and generate two versions of the binary:
Debug version (with debugging symbols and no optimization)
Optimized version (with optimization for performance)
Run the simulation:

After compilation, you will have two binaries:

wifi_sim_debug: The debug version of the binary
wifi_sim_opt: The optimized version of the binary
To run the debug version, use:

bash
Copy code
./wifi_sim_debug
To run the optimized version, use:

bash
Copy code
./wifi_sim_opt
Clean the project (optional):

To remove all compiled object files and binaries, run:
bash
Copy code
make clean