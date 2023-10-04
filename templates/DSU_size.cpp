vector<int> parent;
vector<int> sizeArr;

void makeSet(int n){
	for(int i=1; i<=n; i++){
		parent[i] = i;
		sizeArr[i] = 1;
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
	
	if(u!=v){
		if(sizeArr[u] < sizeArr[v]){
			swap(u, v);
		}
		
		parent[v] = u;
		sizeArr[u] += sizeArr[v];
	}
}