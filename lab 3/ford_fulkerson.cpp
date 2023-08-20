#include <bits/stdc++.h>

using namespace std;
// #define n 6
   
#define n 4

    bool bfs(int rgraph[n][n], int s, int t, int parent[]){
    int i, v, u;
    int visited[n];
    for(i=0; i<n; i++){
        visited[i] = 0;
    }
    queue<int>q;
    q.push(s);//source push
    visited[s] = 1;
    parent[s] = -1; // source has no parent then value is 0
    
    while(!q.empty()){
        int u = q.front();
        cout<<q.front()<<endl;
        q.pop();
        for(v=0; v<n; v++){
            if(visited[v] == 0 && rgraph[u][v] > 0){
                if(v == t){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                visited[v] = 1;
                parent[v] = u;
            }
        }
    }
    return false;
}

int fordfulkerson(int G[n][n], int s, int t){
    int u, v;
    int rgraph[n][n];
    for(u=0; u<n; u++){
        for(v=0; v<n; v++){
            rgraph[u][v] = G[u][v];
        }
    }
    int parent[n];
    int max_flow = 0;
    while(bfs(rgraph, s, t, parent)){
      int path_flow = INT_MAX;
        for(v=t; v!=s; v = parent[v]){ // finding path flow
            u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }
        for(v=t; v!=s; v = parent[v]){
            u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    } // when bfs return false
    
    return max_flow;
}

int main()
{
    // int n;
    // cin>>n;
    int G[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>G[i][j];
        }
    }
    //   int G[n][n] = {{0,16,13,0,0,0},
    //                 {0,0,10,12,0,0},
    //                 {0,4,0,0,14,0},
    //                 {0,0,9,0,0,20},
    //                 {0,0,0,7,0,4},
    //                 {0,0,0,0,0,0},
    //               };
    cout<<"max_flow = "<<fordfulkerson(G, 0, 4)<<endl;
    return 0;
}