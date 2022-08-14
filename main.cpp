#include <bits/stdc++.h>
using namespace std;
// const int M = 1e9 + 7;
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
 
vector<vector<char>> matrix;
vector<vector<int>> mintimes;
vector<vector<int>> playertimes;
vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 0, 1, 2, 3
int start_x = -1, start_y = -1;
int N = -1, M = -1;
 
bool isValid(int x, int y, int timer){
	if(x<0 || x>=N || y<0 || y>=M) return false;
	if(matrix[x][y]=='#') return false;
	if(mintimes[x][y] <= timer) return false;
	return true;
}
 
bool isValidEscape(int x, int y, int timer){
	if(isValid(x, y, timer) and (x==0 or x==N-1 or y==0 or y==M-1))
		return true;
	return false;
}
 
int evaluate(pair<int, int>& p){
	for(int i=0; i<moves.size(); i++){
		if(p == moves[i]) return i;
	}
	return 69;
}
 
char evaluate2(int i){
	if(i==0) return 'D';
	if(i==1) return 'U';
	if(i==2) return 'R';
	if(i==3) return 'L';
	return 'x';
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
	cin>>n>>m;
	matrix.resize(n, vector<char>(m, '_'));
	mintimes.resize(n, vector<int>(m, INT_MAX));
	vector<pair<int, int>> monsters;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>matrix[i][j];
			if(matrix[i][j]=='A'){
				start_x = i, start_y = j;
			}else if(matrix[i][j]=='M'){
				monsters.push_back({i, j});
			}
		}
	}
	if(start_x==0 or start_x==n-1 or start_y==0 or start_y==m-1){
		cout<<"YES"<<endl;
		return 0;
	}
	N = n, M = m;
	// multisource bfs type problem
	// we have to get the min time at which a block is
	// accessed by the monster, and then call bfs for
	// A, if A can reach that block before the min time
	// A can find his way forward
	queue<pair<pair<int, int>, int>> q;
	// {x, y, mintime/level}
	for(auto& p:monsters) q.push({p, 0});
	while(!q.empty()){
		auto el = q.front(); q.pop();
		int x = el.first.first, y = el.first.second, timer = el.second;
		// cout<<"time = "<<timer<<endl;
		if(timer>mintimes[x][y]) continue;
		mintimes[x][y] = timer;
		for(auto& el:moves){
			int new_x = x + el.first, new_y = y + el.second;
			// cout<<"new x = "<<new_x<<" new_y = "<<new_y<<endl;
			if(isValid(new_x, new_y, timer+1)){
				mintimes[new_x][new_y] = timer+1;
				q.push({{new_x, new_y}, timer+1});
			}
		}
	}
	
	
	// now, we call bfs for A.
	playertimes.resize(n, vector<int>(n, INT_MAX));
	vector<vector<int>> path(n, vector<int>(m, INT_MAX));
	q.push({{start_x, start_y}, 0});
	path[start_x][start_y] = 0;
	bool flag = false;
	string str_path = "";
	// cout<<"q start"<<endl;
	int end_x = -1, end_y = -1;
	while(!q.empty()){
		auto e = q.front(); q.pop();
		int x = e.first.first, y = e.first.second, timer = e.second;
		
		// timer exceeds the min time of M --> not possible
		if(timer >= mintimes[x][y] || timer >=playertimes[x][y]) continue;
		
		playertimes[x][y] = min(playertimes[x][y], timer);
		// else visit neighbours
		for(auto& el:moves){
			int new_x = x + el.first, new_y = y + el.second;
			// if (x, y) is a boundary escape point
			if(isValidEscape(new_x, new_y, timer+1)){
				// cout<<"hello"<<endl;
				flag = true;
				end_x = new_x, end_y = new_y;
				int val = evaluate(el);
				path[new_x][new_y] = val;
				break;
			}
			if(isValid(new_x, new_y, timer+1)){
				int val = evaluate(el);
				path[new_x][new_y] = val;
				q.push({{new_x, new_y}, timer+1});
			}
		}
		if(flag) break;
	}
	
	// cout<<"q end"<<endl;
	
	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<m; j++){
	// 		if(path[i][j]==INT_MAX) cout<<'i'<<" ";
	// 		else cout<<path[i][j]<<" ";
	// 	}cout<<endl;
	// }
	
	if(flag){
		cout<<"YES"<<endl;
		// cout<<"end = "<<"[ "<<end_x<<", "<<end_y<<" ]"<<endl;
		while(start_x!=end_x or start_y!=end_y){
			char dir = evaluate2(path[end_x][end_y]);
			str_path.push_back(dir);
			if(dir=='D') end_x--;
			else if(dir=='U') end_x++;
			else if(dir=='R') end_y--;
			else if(dir=='L') end_y++;
		}
		cout<<str_path.length()<<endl;
		reverse(str_path.begin(), str_path.end());
		cout<<str_path<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	
	return 0;
}