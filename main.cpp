#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int s = 1e5 + 1;
#define int long long
#define INF LONG_MAX
#define ull unsigned long long
#define ll long long
#define lb lower_bound
#define nsync                         \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define t()   \
	int t;    \
	cin >> t; \
	while (t--)

// BINARY LIFTING TECHNIQUE OF FINDING THE LCA:
// T.C. - O(LOG N) --> for queries
// T.C. - O(N * LOG N) --> for building sparse table
// S.C. - O(N * LOG N) --> for sparse table

unordered_map<int, list<int>> adj;
vector<vector<int>> LCA;
vector<int> level;
int maxN, N;

void dfs(int node, int parent = -1, int l = 0)
{
	level[node] = l;
	LCA[node][0] = parent;
	for (auto& next:adj[node])
	{
		if (next != parent)
		{
			dfs(next, node, l + 1);
		}
	}
}

void print(){
	// printing the LCA list
	for(int i=1; i<=N; i++){
		for(int j=0; j<maxN; j++){
			cout<<LCA[i][j]<<" ";
		}
		cout<<endl;
	}
}

void buildLCA()
{
	dfs(1);
	for (int j = 1; j <= maxN; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			// building the LCA array columnwise
			int par = LCA[i][j - 1];
			if (par != -1)
			{
				LCA[i][j] = LCA[par][j - 1];
			}
		}
	}
}

int getLCA(int a, int b)
{
	if (level[a] < level[b])
		swap(a, b);

	// level[a] > level[b]

	int d = level[a] - level[b];
	while (d > 0)
	{
		int jump = log2(d);
		a = LCA[a][jump];
		d = d - (1 << jump);
	}

	if (a == b)
		return a;
	
	for (int i = maxN; i >= 0; i--)
	{
		if (LCA[a][i] != -1 and LCA[a][i] != LCA[b][i])
			a = LCA[a][i], b = LCA[b][i];
	}

	return LCA[a][0];
}

int getDist(int a, int b)
{
	int lca = getLCA(a, b);
	return ((level[a] + level[b]) - 2 * (level[lca]));
}

int32_t main()
{
	nsync;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	// t(){

	// }

	int n, m;
	// cin >> n >> m;

	// for (int i = 0; i < m; i++)
	// {
	// 	int u, v;
	// 	cin >> u >> v;
	// 	adj[u].push_back(v);
	// 	adj[v].push_back(u);
	// }
	
	n = 16, m = 15;
	adj[1].push_back(2);
	adj[1].push_back(10);
	adj[2].push_back(3);
	adj[2].push_back(7);
	adj[3].push_back(4);
	adj[3].push_back(5);
	adj[5].push_back(6);
	adj[7].push_back(8);
	adj[8].push_back(9);
	adj[10].push_back(11);
	adj[11].push_back(12);
	adj[10].push_back(13);
	adj[13].push_back(14);
	adj[14].push_back(15);
	adj[15].push_back(16);

	maxN = log2(n) + 1;
	N = n;

	LCA.resize(n + 1, vector<int>(maxN+1, -1));
	level.resize(n + 1, 0);

	buildLCA();
	
	int q=0;
	cin >> q;
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		cout << "Distance b/w " << u << " and " << v << " = " << getDist(u, v) << endl;
	}

	return 0;
}