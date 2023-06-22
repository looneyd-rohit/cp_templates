const int N = 1e5+10;
int bit[N+1];
// BIT array is always 1-based indexing since 0 will cause infinite loops
void update(int i, int x){
	for(; i < N; i += (i&-i))
		bit[i] += x;
}

int sum(int i){
	int ans = 0;
	for(; i > 0; i -= (i&-i))
		ans += bit[i];
	return ans;
}
