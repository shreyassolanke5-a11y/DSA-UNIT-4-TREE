#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <iomanip>
using namespace std;

class IndustrialNetwork {
private:
int V;
vector<string> devices;
vector<vector<int>> graph;

public:
IndustrialNetwork(int n) {
V = n;
devices.resize(V);
graph.resize(V, vector<int>(V, INT_MAX));

for (int i = 0; i < V; i++) {  
        graph[i][i] = 0;  
    }  
}  

void inputDevices() {  
    cout << "\nEnter device names:\n";  
    cout << "Example: PLC1, HMI1, Monitor1\n";  

    for (int i = 0; i < V; i++) {  
        cout << "Device " << i + 1 << ": ";  
        cin >> devices[i];  
    }  
}  

void addLink(int u, int v, int cost) {  
    if (u < 0 || u >= V || v < 0 || v >= V) {  
        cout << "Invalid device number!\n";  
        return;  
    }  

    if (cost < 0) {  
        cout << "Cost cannot be negative!\n";  
        return;  
    }  

    graph[u][v] = cost;  
    graph[v][u] = cost;  
}  

void inputLinks() {  
    int E, u, v, cost;  

    cout << "\nEnter number of communication links: ";  
    cin >> E;  

    cout << "Enter device numbers and cost:\n";  

    for (int i = 0; i < E; i++) {  
        cin >> u >> v >> cost;  
        addLink(u - 1, v - 1, cost);  
    }  
}  

void displayDevices() {  
    cout << "\nIndustrial Automation Devices:\n";  

    for (int i = 0; i < V; i++) {  
        cout << i + 1 << ". " << devices[i] << "\n";  
    }  
}  

void displayGraph() {  
    cout << "\nCommunication Cost Matrix:\n";  

    for (int i = 0; i < V; i++) {  
        for (int j = 0; j < V; j++) {  
            if (graph[i][j] == INT_MAX)  
                cout << setw(6) << "-";  
            else  
                cout << setw(6) << graph[i][j];  
        }  
        cout << "\n";  
    }  
}  

int minKey(vector<int>& key,  
           vector<bool>& mstSet) {  
    int minValue = INT_MAX;  
    int minIndex = -1;  

    for (int i = 0; i < V; i++) {  
        if (!mstSet[i] && key[i] < minValue) {  
            minValue = key[i];  
            minIndex = i;  
        }  
    }  

    return minIndex;  
}  

void primMST() {  
    vector<int> parent(V, -1);  
    vector<int> key(V, INT_MAX);  
    vector<bool> mstSet(V, false);  

    key[0] = 0;  

    for (int count = 0; count < V; count++) {  
        int u = minKey(key, mstSet);  

        if (u == -1) {  
            cout << "\nNetwork is disconnected!\n";  
            return;  
        }  

        mstSet[u] = true;  

        for (int v = 0; v < V; v++) {  
            if (graph[u][v] != INT_MAX &&  
                graph[u][v] != 0 &&  
                !mstSet[v] &&  
                graph[u][v] < key[v]) {  
                parent[v] = u;  
                key[v] = graph[u][v];  
            }  
        }  
    }  

    int totalCost = 0;  

    cout << "\nMinimum Spanning Tree (MST):\n";  
    cout << "Device Link\t\tCost\n";  

    for (int i = 1; i < V; i++) {  
        cout << devices[parent[i]] << " - "  
             << devices[i] << "\t\t"  
             << key[i] << "\n";  

        totalCost += key[i];  
    }  

    cout << "\nTotal Minimum Cost = "  
         << totalCost << "\n";  
}

};

int main() {
int n;

cout << "====================================\n";  
cout << " INDUSTRIAL AUTOMATION NETWORK\n";  
cout << " Prim's Algorithm - DSA Project\n";  
cout << "====================================\n";  

cout << "\nEnter number of devices: ";  
cin >> n;  

if (n <= 0) {  
    cout << "Invalid number of devices!\n";  
    return 0;  
}  

IndustrialNetwork network(n);  

network.inputDevices();  
network.displayDevices();  
network.inputLinks();  
network.displayGraph();  
network.primMST();  

cout << "\nNetwork construction completed.\n";  

return 0;

}
