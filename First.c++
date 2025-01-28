#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
vector<int> ad[1000002];
vector<vector<int>> adw[1000002];
int vst[1000002];
int col[1000002];

/// ..........3.If Find the longest distance  and its node from the source vertex (using BFS)..........

/// problem link--->https://atcoder.jp/contests/abc361/tasks/abc361_e
// Perform BFS and return the farthest distance and its node from the start node
/*pair<int, int> bfs(int n, int start)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int farthest_node = start;
    int max_distance = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adw[node])
        {
            int v = it[0];
            int w = it[1];
            if (dist[v] == -1)
            {
                dist[v] = dist[node] + w;
                q.push(v);
                if (dist[v] > max_distance)
                {
                    max_distance = dist[v];
                    farthest_node = v;
                }
            }
        }
    }
    return {farthest_node, max_distance};
}
void solve()
{
    int n, u, v, w,sum=0;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v >> w;
        sum+=w;
        adw[u].push_back({v, w});
        adw[v].push_back({u, w});
    }
    // Step 1: Perform BFS from an arbitrary node (let's choose node 1)
    pair<int, int> result1 = bfs(n, 1);

   // cout << result1.first << endl;

    // Step 2: Perform BFS from the farthest node found in step 1
    pair<int, int> result2 = bfs(n, result1.first);

    // The distance in result2.second is the longest distance in the tree
    cout << (result2.second + 2*(sum-result2.second))<< endl;
}*/

/// ..........2. Find the shortest distance of all the vertices from the source vertex S(dijkstra)..........

/// --->https://www.youtube.com/watch?v=V6H1qAeB-l4
/* vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Create a priority queue for storing the nodes as a pair {dist, node}
    // where dist is the distance from source to the node.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initializing distTo list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> distTo(V, INT_MAX);

    // Source initialized with dist=0.
    distTo[S] = 0;
    pq.push({0, S});

    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        // Check for all adjacent nodes of the popped out
        // element whether the previous dist is larger than current or not.
        for (auto it : adj[node])
        {
            int v = it[0];
            int w = it[1];
            if (dis + w < distTo[v])
            {
                distTo[v] = dis + w;

                // If current distance is smaller,
                // push it into the queue.
                pq.push({dis + w, v});
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return distTo;
}

int32_t main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});
    adj[1].push_back({2, 3});
    adj[1].push_back({0, 1});
    adj[2].push_back({1, 3});
    adj[2].push_back({0, 6});

    vector<int> res = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}*/
// .................1.The longest path (from one node to another) in that tree.................

//--->https://www.youtube.com/watch?v=9goVqAvYEbI&list=PL5DyztRVgtRVLwNWS7Rpp4qzVVHJalt22&index=15
/* int maxd;
int maxnode;
void dfs(int node,int d)
{
   vst[node]=1;
    if(d>maxd)
        maxd=d,maxnode=node;
    for(int child:ad[node])
    {
        if(vst[child]==0)
            dfs(child,d+1);
    }
}
int32_t main()
{

    int n,e,a,b;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        ad[i].clear();
        vst[i]=0;
    }
    for(int i=0; i<n-1; i++)
    {
        cin>>a>>b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    maxd=-1;
    dfs(1,0);
    for(int i=1; i<=n; i++)
        vst[i]=0;
   // cout<<maxnode<<endl;
    dfs(maxnode,0);
    cout<<maxd<<endl;

}*/
