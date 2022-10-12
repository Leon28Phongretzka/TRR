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
#define fora(i, n) for(auto x:n)
#define Len 100005
int n,m;
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
class Graph 
{
	public:
        vl adj[1001];
		bool visited[1001][1001];
		map<int, list<int>> adj;
		int parent[1001];
		void addEdge(int v, int w);
		void DFS(int v);
};
// add edge
void Graph::addEdge(int v, int w)
{
    adj[v].pb(w);
}
// DFS
void Graph::DFS(int v, int w)
{
    visited[v][w] = true;
    for(ll k=0; k<4; k++)
    {
        ll i1=i+dx[k];
        ll i2=j+dy[k];
        if(i1>=0 && i1<n && i2>=0 && i2<m && !visited[i1][i2] && adj[i1][i2]=='.')
        {
            DFS(i1, i2);
        }
    }
}
// Return
void Graph::Return()
{
	// Return visited bool to false
	for (auto i = visited.begin(); i != visited.end(); ++i)
		i->second = false;
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
	
}


