#include<bits/stdc++.h>
using namespace std;
// Supposing the maximum nodes that can be present in Graph are 10^5 + 1
int nodes,edges;
vector<int> nodeNeighbour[100002];
bool isVisited[100002];
void input()
{
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        nodeNeighbour[u].push_back(v);
        nodeNeighbour[v].push_back(u);
    }
    memset(isVisited,false,sizeof(isVisited));
}
void DFS(int node)
{
    cout << node << " ";
	isVisited[node] = true;
	for(int n: nodeNeighbour[node])
	{
		if(!isVisited[n]) DFS(n);
	}
}

int main()
{
    // Our graph is ready by the end of this for loop
	// We have used Adjacency list to store the edges
	// Node from which we want to start Depth First Search
    input();
    int startNode;
    cin >> startNode;
    DFS(startNode);
}