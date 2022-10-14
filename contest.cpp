#include <bits/stdc++.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
using namespace std;
const int M = 1e9 + 7;
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
#define int long long

int linear_search(vector<int>& arr, int key){
	for(int i=0; i<arr.size(); i++){
		if(arr[i]==key) return i;
	}
	return -1;
}

int32_t main()
{
	nsync;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	// int c = 0;
	t()
	{
		int n;
		cin>>n;
		vector<int> a(n);
		vector<int> b(n);
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		for(int i=0; i<n; i++){
			cin>>b[i];
		}
		int index = linear_search(a, b[0]);
		int diff = (index / 2) + (index % 2);
		cout<<diff<<endl;
	}
	return 0;
}