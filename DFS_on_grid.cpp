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
#define forn(i, n) for (ll i = 1; i <= ll(n); i++)
#define fora(i, n) for(auto x:n)
#define Len 100005
ll n,m;
ll dx[4] = {-1,0,0,1};
ll dy[4] = {0,-1,1,0};
class Graph 
{
	public:
        char adj[1001][1001];
		bool visited[1001][1001];
		void DFS(ll v,ll w);
        void Solve();
};
// DFS
void Graph::DFS(ll v, ll w)
{
    cout << v << " " << w << endl;
    visited[v][w] = true;
    for(ll k=0; k<4; k++)
    {
        ll i1=v+dx[k];
        ll i2=w+dy[k];
        if(i1>=1 && i1<=n && i2>=1 && i2<=m && !visited[i1][i2] && adj[i1][i2]=='x') 
            DFS(i1, i2);
    }
}
// 
void Graph::Solve()
{
    cin >> n >> m;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            cin >> adj[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    ll cnt=0;
    forn(i,n)
    {
        forn(j,m)
        {
            if( adj[i][j]=='x' && !visited[i][j])
            {
                cout << "Component " << ++cnt << ":" << endl;
                DFS(i,j);
            }
        }
    }
    cout << endl;
    cout << "Number of connected components: " << cnt << endl;
}
int main()
{
    // Call graph
	Graph g;
    // Solve
    g.Solve();
}


