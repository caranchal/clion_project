#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFSFromNode(int start, vector<bool>& visited, const vector<vector<int>>& adj) {
    stack<int> st;
    st.push(start);
    visited[start] = true;
    
    while (!st.empty()) {
        int current = st.top();
        st.pop();
        cout << current << " ";
        
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                st.push(neighbor);
            }
        }
    }
}

void DFSFullGraph(int vertices, const vector<vector<int>>& adj) {
    vector<bool> visited(vertices, false);
    
    cout << "Full graph DFS: ";
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFSFromNode(i, visited, adj);
        }
    }
    cout << endl;
}

int main() {
    int vertices = 7;
    vector<vector<int>> adj(vertices);
    
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);
    DFSFullGraph(vertices, adj);
    
    return 0;
}
