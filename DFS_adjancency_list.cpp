#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0)
typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;
#define mp make_pair
#define gl getline
#define pb push_back
#define eb emplace_back
#define ob pop_back
#define sz(s) ((int)(s.size()))
#define UM uno\nrdered_map
#define US uno\nrdered_set
#define forn(i, n) for (int i = 1; i <= int(n); i++)
#define fora(i, n) for(auto i:n)
#define Len 100005
const double pi=3.14159265358979323846;
const int MOD = 1000000007;
class Graph 
{
	public:
		map<int, bool> visited;
		map<int, list<int> > adj;
		int parent[1001];
		void addEdge(int v, int w);
		void DFS(int v);
		bool hasCycle(int v);
		void ConnectedComponents(int n);
		void DFS_path(int u);
		void Path(int u, int v);
		void Return();
		void SetParent();
};
// Add Edge
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}
// DFS
void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}
// Check Graph Cycle
bool Graph::hasCycle(int v)
{
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			hasCycle(*i);
		else
			return true;
	return false;
}
// Check number of Connected Components
void Graph::ConnectedComponents(int n)
{
	int ans=0;
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			ans++;
			cout << "Component " << ans << " : ";
			DFS(i);
			cout << endl;
		}
	}
	cout << "Numbers of Connected Components is: " << ans << endl;
}
// DFS_path
void Graph::DFS_path(int u)
{
	visited[u] = true;
	for(int v : adj[u])
	{
		if(!visited[v])
		{
			parent[v]=u;
			DFS_path(v);
		}
	}
}
// Path
void Graph::Path(int u, int v)
{
	int temp=v;
	memset(parent, 0, sizeof(parent));
	DFS_path(u);
	if(!visited[v])
	{
		cout << "No Path" << endl;
		return;
	}
	else
	{
		vector<int> path;
		while(v!=u)
		{
			path.pb(v);
			v=parent[v];
		}
		path.pb(u);
		reverse(path.begin(), path.end());
		cout << "The Path between " << u << " and " << temp << " is: ";
		fora(i, path)
			cout << i << " ";
	}
}
// Return
void Graph::Return()
{
	// Return visited bool to false
	for (auto i = visited.begin(); i != visited.end(); ++i)
		i->second = false;
}
// Set parent array to 0
void Graph::SetParent()
{
	memset(parent, 0, sizeof(parent));
}
int main()
{
	Graph g;
	int n,m;
	cout << "Enter the number of verticles and edges: " << endl;
	cin >> n >> m;
	// Use adjancency list to store graph
	g.Return();
	// Input graph use ajancency list
    for(int i=0; i<m; i++)
    {
        int x,y; cin >> x >> y;
        g.addEdge(x,y);
		g.addEdge(y,x);
    }
	// DFS from node k
	int k; cin >> k; g.DFS(k); cout << endl;
	// Check cycle from node k
	if(g.hasCycle(k)) cout << "Cycle" << endl;
	else cout << "No Cycle" << endl;
	// Connected Components for Graph
	g.Return(); g.ConnectedComponents(n);
	// Find path between u and v
	g.Return(); g.SetParent(); 
	int u,v; cin >> u >> v; g.Path(u,v);
}
