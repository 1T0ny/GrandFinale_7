//  main.cpp
//  Grand_Finale_7
#include <iostream>
#include <vector>
#include <climits>
#include <chrono>

using namespace std;
using namespace std::chrono;

class primsAlgorithmn {
private:
    
    int Key(const vector<int> & key, const vector<bool> & mstSet, int totalNodes) {
        int min = INT_MAX, min_index = -1;
        
        for (int i = 0; i < totalNodes; i++) {
            if (!mstSet[i] && key[i] < min) {
                min = key[i];
                min_index = i;
            }
        }
        return min_index;
    }
    
public:
    
    void primMST(const vector<vector<int>> & graph) {
        int totalNodes = graph.size();
        vector<int> parent(totalNodes);
        vector<int> twokey(totalNodes);
        vector<bool> mst(totalNodes);
        
        for (int i = 0; i < totalNodes; i++) {
            twokey[i] = INT_MAX;
            mst[i] = false;
        }
        twokey[0] = 0;
        parent[0] = -1;
        
        auto begin = high_resolution_clock::now();
        
        for (int count = 0; count < totalNodes - 1; count ++) {
            int red = Key(twokey, mst, totalNodes);
            if (red == -1) break;
            mst[red] = true;
            
            for (int blue = 0; blue < totalNodes; blue++) {
                if (graph[red][blue] && !mst[blue] && graph[red][blue] < twokey[blue]) {
                    parent[blue] = red;
                    twokey[blue] = graph[red][blue];
                }
            }
        }
        
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - begin);
        
        displayResults(parent, graph, duration.count());
    }
   
    void displayResults(const vector<int> & parent, const vector<vector<int>> & graph, long long time) {
        cout << "\n       Prim's Algorithm: MST Results      " << endl;
        cout << "=========================================" << endl;
        cout << "Edge \tWeight" << endl; // Fixed string literal
            
        int totalWeight = 0;
        for (int i = 1; i < graph.size(); i++) {
            cout << parent[i] << " - " << i << "\t" << graph[parent[i]][i] << endl;
            totalWeight += graph[parent[i]][i];
        }
        cout << " [INFO] Total MST Weight is: " << totalWeight << endl;
        cout << " [INFO] Total Execution time is: " << time << " nanoseconds" << endl;
        cout << " =========================================\n" << endl;
    }
};

int main() {
    
    
    cout << " ========================================= " << endl;
    cout << "      Welcome to the Prim Algorithm        " << endl;
    
    vector<vector<int>> graph = {
        
        //        { 0, 2, 0, 6, 0 },
        //        { 2, 0, 3, 8, 5 },
        //        { 0, 3, 0, 0, 7 },
        //        { 6, 8, 0, 0, 9 },
        //        { 0, 5, 7, 9, 0 }
        
        //        {0, 4, 0, 0, 0, 0, 0, 8, 0, 0},
        //        {4, 0, 8, 0, 0, 0, 0, 11, 0, 4},
        //        {0, 8, 0, 7, 0, 4, 0, 0, 2, 0},
        //        {0, 0, 7, 0, 9, 14, 0, 0, 0, 0},
        //        {0, 0, 0, 9, 0, 10, 0, 0, 0, 0},
        //        {0, 0, 4, 14, 10, 0, 2, 0, 0, 0},
        //        {0, 0, 0, 0, 0, 2, 0, 1, 6, 0},
        //        {8, 11, 0, 0, 0, 0, 1, 0, 7, 0},
        //        {0, 0, 2, 0, 0, 0, 6, 7, 0, 0},
        //        {0, 0, 0, 0, 0, 0, 0, 0, 0, 7}
        
        {0, 4, 0, 0, 0, 0, 0, 8, 0, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2, 0},
        {0, 0, 7, 0, 9, 14, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6, 0},
        {8, 11, 0, 0, 0, 0, 1, 0, 7, 0},
        {0, 0, 2, 0, 0, 0, 6, 7, 0, 0},   //{0, 0, 2, 0, 0, 0, 6, 7, 0, 3}
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}    //{0, 0, 0, 0, 0, 0, 0, 0, 3, 0}
    };
    
    primsAlgorithmn solver;
    solver.primMST(graph);
    
    return 0;
};
