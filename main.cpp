#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ll long long
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define nsync                                                                  \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

// constant
const int M = (int)(1e9 + 7);
const int s = 1e5 + 1;
const int INF = 3e18L + 5;
const int INF64 = 1e18;
const int NINF = 1e18 * (-1);

void fun() { cout << "MF World!!!" << endl; }

void calculateLPS(string& pat, vector<int>& lps){
    int m = pat.size();
    lps[0] = 0;
    int i = 1, length = 0;
    while(i<m){
        if(pat[i]==pat[length]){
            lps[i++] = ++length;
        }else{
            if(length > 0){
                length = lps[length-1];
            }else{
                i++;
            }
        }
    }
}

vector<int> findAllOccurencesKMP(string& text, string& pattern, vector<int>& lps){
	int n = text.size(), m = pattern.size();
	vector<int> result;
	int i=0, j=0;
	while(i < n){
		if(text[i]==pattern[j]){
			// matched
			i++; j++;
			if(j==m){
				// fully matched
				result.push_back(i-j);
				j = lps[j-1];
			}
		}else{
			// point j to lps[j-1]
			if(j > 0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	return result;
}


int32_t main() {
  nsync;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  // Knuth Morris Pratt Algorithm

  // int t;
  // cin >> t;
  // while (t--) {
  	
  // }
  string text, pattern;
  cin>>text>>pattern;
  int n = text.size(), m = pattern.size();
  vector<int> lps(m, 0);
  calculateLPS(pattern, lps);
  for(auto& e: lps) cout<<e<<" ";cout<<endl;
  vector<int> result = findAllOccurencesKMP(text, pattern, lps);
  for(auto& e: result) cout<<e<<" ";cout<<endl;

  return 0;
}
