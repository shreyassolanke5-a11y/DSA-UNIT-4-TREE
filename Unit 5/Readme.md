Industrial Automation Network Using Prim's Algorithm

📌 Project Description

This project implements an Industrial Automation Network using Prim's Algorithm in C++. It represents PLCs, HMIs, and monitoring stations as vertices and communication links as weighted edges.

The program finds the Minimum Spanning Tree (MST) to connect all devices with the minimum total communication cost.

🎯 Objectives

- Represent industrial devices using a graph.
- Apply Prim's Algorithm to find the Minimum Spanning Tree.
- Minimize the total communication cost.
- Understand graph data structures and greedy algorithms.

🛠️ Technologies Used

- Language: C++
- Algorithm: Prim's Algorithm
- Data Structure: Graph using an adjacency matrix
- Libraries: iostream, vector, string, climits, iomanip

✨ Features

- Accepts device names as input.
- Accepts communication links and their costs.
- Displays the list of industrial devices.
- Displays the communication cost matrix.
- Calculates the Minimum Spanning Tree.
- Displays selected links and total minimum cost.
- Detects disconnected networks.

⚙️ How It Works

1. Enter the number of devices.
2. Enter device names such as PLC1, HMI1, and Monitor1.
3. Enter the number of communication links.
4. Enter each link using two device numbers and its cost.
5. The program displays the graph and applies Prim's Algorithm.
6. The program displays the selected links and total minimum cost.

💻 How to Compile and Run

Compile

g++ main.cpp -o industrial_network

Run on Windows

industrial_network.exe

Run on Linux or macOS

./industrial_network

▶️ Sample Input

Enter number of devices: 4

Device 1: PLC1
Device 2: HMI1
Device 3: Monitor1
Device 4: PLC2

Enter number of communication links: 5
1 2 10
1 3 20
2 3 5
2 4 15
3 4 10

📤 Sample Output

Minimum Spanning Tree (MST):
Device Link        Cost
PLC1 - HMI1         10
HMI1 - Monitor1      5
Monitor1 - PLC2     10

Total Minimum Cost = 25

Network construction completed.

⏱️ Complexity Analysis

- Time Complexity: O(V²)
- Space Complexity: O(V²)

Here, "V" is the number of devices.

🏭 Applications

- Industrial automation networks
- PLC and HMI communication
- Factory monitoring systems
- Industrial control networks
- Communication cost optimization

📚 Learning Outcomes

- Understanding graph representation.
- Learning Prim's Algorithm.
- Finding a Minimum Spanning Tree.
- Applying DSA concepts to industrial automation.

👨‍💻 Project Details

- Project Name: Industrial Automation Network
- Subject: Data Structures and Algorithms (DSA)
- Programming Language: C++
- Algorithm: Prim's Algorithm

🚀 Future Enhancements

- Add graphical network visualization.
- Compare Prim's Algorithm with Kruskal's Algorithm.
- Save network details to a file.
- Improve input validation.
