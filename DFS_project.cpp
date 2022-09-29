#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0)
typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<bool, ll> pbl;
typedef pair<ul, int> pui;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<int> vi;
typedef vector<int>::iterator ip;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<pll> vpll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pbl> vpbl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<pdd> vpdd;
typedef vector<string> vs;
typedef vector<pui> vpui;
typedef vector<ul> vu;
typedef vector<string> vs;
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
		void addEdge(int v, int w);
		void DFS(int v);
		bool hasCycle(int v);
		void ConnectedComponents();
};
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}
void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}
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
void Graph::ConnectedComponents()
{
	int ans=0;
	for (auto i = adj.begin(); i != adj.end(); ++i)
	{
		int v = i->first;
		if (!visited[v])
		{
			ans++;
			DFS(v);
			cout << endl;
		}
	}
	cout << ans << endl;
}
int main()
{
	Graph g;
	int n,m;
	cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int x,y; cin >> x >> y;
        g.addEdge(x,y);
		g.addEdge(y,x);
    }
	// int k; cin >> k; g.DFS(k); cout << endl;
	// cout << g.hasCycle(k) << endl;
	g.ConnectedComponents();
}

