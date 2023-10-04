vector<int> parent;
vector<int> rankArr;

void makeSet(int n){
	for(int i=1; i<=n; i++){
		parent[i] = i;
		rankArr[i] = 1;
	}
}

int findParent(int u){
	if(u == parent[u]) return u;
	// path compression
	return parent[u] = findParent(parent[u]);
}

void unionSet(int u, int v){
	u = findParent(u);
	v = findParent(v);
	
	if(rankArr[u]==rankArr[v]){
		parent[v] = u;
		rank[u]++;
	}else if(rankArr[u]<rankArr[v]){
		parent[u] = v;
	}else{
		parent[v] = u;
	}
}