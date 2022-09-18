#include<bits/stdc++.h>
using namespace std;

#define MX 110

vector < int > graph[MX];
bool vis[MX]; // for visited array
int dis[MX]; // for distance array

void bfs(int source)
{
    queue < int > Q;
    //initialization
    vis[source] = 1;
    dis[source]  = 0;
    Q.push(source);

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop(); // for remove front element
        //for visited all adjacency node

        for(int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            if(vis[next]== 0)
            {
                vis[next] = 1; // visit node if the are unvisited
                dis[next] =  dis[node] + 1; // update distance
                Q.push(next); // push to queue
            }
        }

    }
}

int main()
{

    int nodes, edges;

    cout<<"Enter number of nodes & Edges: ";
    cin >> nodes >> edges;
    cout<<"Enter edges values: "<<endl;
    for(int i = 1; i <= edges; i++ )
    {
        int u,v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    int source;

    cout<<"Enter source "<<endl;
    cin >> source;
    bfs(source);

    cout<<" From node "<< source << endl;

    for(int i = 1; i <= nodes; i++ )
    {
        cout<< "Distance of " << i << " is :"<< dis[i] << endl;
    }
    return 0;
}
