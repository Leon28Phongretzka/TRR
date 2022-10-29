





#include<vector>





Đỉnh đầu    Đỉnh cuối
1            2
1            3
1            4
2            4
3            4
3            5
3            6
4            6
5            6


Đỉnh đầu    Đỉnh cuối
1            2
1            3
3            4
3            5
3            6
4            1
4            2
4            6
6            5




tuple<int,int,int> edge; // dinh dau, dinh cuoi, trong so


struct edge
{
    int dinh_dau, dinh_cuoi, w; // dinh dau, dinh cuoi, trong so
}




Đỉnh đầu    Đỉnh cuối   Trọng số
1           2           5
1           3           4
1           4           2
2           4           8
3           4           1
3           5           6
3           6           3
4           6           7
5           6           8

vector<int> adjancency_list[100]; // danh sách kề
vector<vector<int,int>> adjancency_list[100]; // danh sách kề
map<int,vector<int>> adjancency_list; // danh sách kề


Đỉnh    Danh sách kề
1       2,3,4
2       1,4
3       1,4,5,6
4       1,2,3,6
5       3,6
6       3,4,5


// Pseudo code of DFS
// Bat dau duyet tu dinh u
DFS(u){
	<Tham Dinh u>;
	visited[u]=true; // Danh dau la u da duoc tham
	// Duyet cac dinh ke voi dinh u
	for(v:adj[u]){
		if(!visited[v]){ // Neu v chua duoc tham
			DFS(v);
		}
	}
}


// adjacency matrix
vector<vector<int> > adj;
 
// function to add edge to the graph
void addEdge(int x, int y)
{
    adj[x][y] = 1;
    adj[y][x] = 1;
}

// Edge list
vector<pair<int, int> > adj; // vector of pairs

int x[10001], y[10001];
int n,m; // n là số đỉnh, m là số cạnh
cin >> n >> m;
for(int i=1; i<=m; i++)
{
	cin >> x[i] >> y[i];
}



