class Solution {
    // Check if we can safely color this node with 'col'
    bool safe(int node, vector<int>& color, vector<vector<int>>& edges, int v, int col) {
        for(int i = 0; i < v; i++) {
            // If there's an edge and adjacent node has same color
            if(edges[node][i] == 1 && color[i] == col) {
                return false;
            }
        }
        return true;
    }

    // Backtracking to try coloring the graph
    bool solve(int node, vector<int>& color, int m, int v, vector<vector<int>>& edges) {
        // Base case: All nodes are colored
        if(node == v) return true;

        // Try all colors from 1 to m
        for(int i = 1; i <= m; i++) {
            if(safe(node, color, edges, v, i)) {
                color[node] = i; // Assign color

                // Recurse for next node
                if(solve(node + 1, color, m, v, edges)) return true;

                // Backtrack
                color[node] = 0;
            }
        }
        return false; // No color fits
    }

public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int> color(v, 0); // 0 means uncolored
        return solve(0, color, m, v, edges);
    }
};
