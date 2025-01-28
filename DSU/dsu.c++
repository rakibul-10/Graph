#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
vector<int> ad[1000002];
vector<vector<int>> adw[1000002];
int vst[1000002];
int col[1000002];

/***************************Disjoint Data Structures(DSU)-->All function**************************
 * 
// Global arrays for parent and size of the component
vector<int> parent, sizee;
// Function to initialize DSU structure
void initialize(int n)
{
    parent.resize(n + 1);
    sizee.resize(n + 1, 1); // Initially, all components are of size 1
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i; // Every node is its own parent
    }
}
// Simple root function to find the root of a node (without path compression)
int root(int x)
{
    while (x != parent[x])
    {
        x = parent[x];
    }
    return x;
}
// Modified root function with path compression
int modifiedRoot(int x)
{
    if (x != parent[x])
    {
        parent[x] = modifiedRoot(parent[x]); // Path compression
    }
    return parent[x];
}
// Simple find function that checks if two nodes are in the same component
bool find(int x, int y)
{
    return root(x) == root(y); // Check if they have the same root
}
// Modified find function with path compression
bool modifiedFind(int x, int y)
{
    return modifiedRoot(x) == modifiedRoot(y); // Check if they have the same root with path compression
}
// Simple union function that merges two components (without union by size)
void unionSimple(int x, int y)
{
    int rootX = root(x);
    int rootY = root(y);

    if (rootX != rootY)
    {
        parent[rootY] = rootX; // Make one root the parent of the other
    }
}
// Modified union function with union by size (weighted-union)
void unionBySize(int x, int y)
{
    int rootX = modifiedRoot(x);
    int rootY = modifiedRoot(y);

    if (rootX != rootY)
    {
        // Union by size: attach the smaller tree under the larger tree
        if (sizee[rootX] < sizee[rootY])
        {
            parent[rootX] = rootY;
            sizee[rootY] += sizee[rootX]; // Increase the size of the root of Y
        }
        else
        {
            parent[rootY] = rootX;
            sizee[rootX] += sizee[rootY]; // Increase the size of the root of X
        }
    }
}
int32_t main()
{
    int N = 5; // Number of nodes
    initialize(N);

    // Example: Perform some union operations
    unionSimple(1, 2); // Union 1 and 2
    unionSimple(2, 3); // Union 3 and 4
    unionSimple(4, 5); // Union 4 and 5

    unionBySize(2, 4); // Weighted union of 4 and 5 (merge two subset)

    // Example: Find if two nodes are connected
    cout << "Are 1 and 2 connected? " << find(1, 2) << endl;         // 1 (true)
    cout << "Are 3 and 5 connected? " << find(3, 5) << endl;         // 1 (true)
    cout << "Are 2 and 5 connected? " << modifiedFind(2, 5) << endl; // 1 (true)

    return 0;
}*/
