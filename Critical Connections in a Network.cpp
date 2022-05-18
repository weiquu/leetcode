// similar to Tarjan's algorithm for APs

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;

        bool *visited = new bool[n];
        int *discovered = new int[n];
        int *low = new int[n];
        int *parent = new int[n];

        for (int i = 0; i < n; i++) {
            visited[i] = false;
            parent[i] = -1;
        }

        // bool *adj[n];

        // for (int i = 0; i < n; i++) {
        //     adj[i] = new bool[n];
        //     for (int j = 0; j < n; j++) {
        //         adj[i][j] = false;
        //     }
        // }

        // for (int i = 0; i < connections.size(); i++) {
        //     vector<int> connection = connections.at(i);
        //     adj[connection.at(0)][connection.at(1)] = true;
        //     adj[connection.at(1)][connection.at(0)] = true;
        // }

        vector<vector<int>> adj;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            adj.push_back(temp);
        }
        for (int i = 0; i < connections.size(); i++) {
            vector<int> connection = connections.at(i);
            adj.at(connection.at(0)).push_back(connection.at(1));
            adj.at(connection.at(1)).push_back(connection.at(0));
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                criticalConnectionsHelper(n, i, visited, discovered, low, parent, adj, res);
            }
        }

        return res;
    }

    void criticalConnectionsHelper(int n, int u, bool visited[], int discovered[], int low[], int parent[], vector<vector<int>>& connections, vector<vector<int>>& res) {
        static int time = 0;    
        visited[u] = true;
        discovered[u] = low[u] = ++time;

        vector<int> adj = connections.at(u);
        for (int i = 0; i < adj.size(); i++) {
            int v = adj.at(i);
            if (!visited[v]) {
                parent[v] = u;
                criticalConnectionsHelper(n, v, visited, discovered, low, parent, connections, res);
                low[u]  = min(low[u], low[v]);
                if (low[v] > discovered[u]) {
                    vector<int> temp = {u, v};
                    res.push_back(temp);
                    cout << u <<" " << v << endl;
                }
            } else if (v != parent[u]) {
                low[u]  = min(low[u], discovered[v]);
            }
        }
    }
};