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