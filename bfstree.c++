#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

void printPath(map<string, string>& parent, string start, string goal) {
    vector<string> path;
    string current = goal;

    while (current != "") {
        path.push_back(current);
        current = parent[current];
    }

    cout << "Rute yang ditemukan: ";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

void bfs(map<string, vector<string>>& graph, string start, string goal) {
    queue<string> q; 
    map<string, bool> visited; 
    map<string, string> parent; 

    q.push(start);
    visited[start] = true;
    parent[start] = ""; 

    bool found = false;

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == goal) {
            found = true;
            break;
        }

        for (string tetangga : graph[current]) {
            if (!visited[tetangga]) {
                visited[tetangga] = true;
                parent[tetangga] = current;
                q.push(tetangga);
            }
        }
    }

    if (found) {
        printPath(parent, start, goal);
    } else {
        cout << "Tidak ada rute yang ditemukan dari " << start << " ke " << goal << endl;
    }
}

int main() {
    map<string, vector<string>> graph;

    graph["Oradea"] = {"Zerind", "Sibiu"};
    graph["Zerind"] = {"Oradea", "Arad"};
    graph["Arad"] = {"Zerind", "Sibiu", "Timisoara"};
    graph["Sibiu"] = {"Oradea", "Arad", "Rimnicu Vilcea", "Fagaras"};
    graph["Timisoara"] = {"Arad", "Lugoj"};
    graph["Lugoj"] = {"Timisoara", "Mehadia"};
    graph["Mehadia"] = {"Lugoj", "Drobeta"};
    graph["Drobeta"] = {"Mehadia", "Craiova"};
    graph["Craiova"] = {"Drobeta", "Rimnicu Vilcea", "Pitesti"};
    graph["Rimnicu Vilcea"] = {"Sibiu", "Craiova", "Pitesti"};
    graph["Fagaras"] = {"Sibiu", "Bucharest"};
    graph["Pitesti"] = {"Rimnicu Vilcea", "Craiova", "Bucharest"};
    graph["Bucharest"] = {"Fagaras", "Pitesti", "Giurgiu", "Urziceni"};
    graph["Giurgiu"] = {"Bucharest"};
    graph["Urziceni"] = {"Bucharest", "Hirsova", "Vaslui"};
    graph["Hirsova"] = {"Urziceni", "Eforie"};
    graph["Eforie"] = {"Hirsova"};
    graph["Vaslui"] = {"Urziceni", "Iasi"};
    graph["Iasi"] = {"Vaslui", "Neamt"};
    graph["Neamt"] = {"Iasi"};

    string start, goal;

    cout << "Masukkan kota awal: ";
    cin >> start;
    cout << "Masukkan kota tujuan: ";
    cin >> goal;

    if (graph.find(start) == graph.end() || graph.find(goal) == graph.end()) {
        cout << "Kota yang dimasukkan tidak valid!" << endl;
        return 1;
    }

    cout << "\nMencari rute dari " << start << " ke " << goal << " menggunakan BFS...\n";
    bfs(graph, start, goal);

    return 0;
}