// C. Dasha and Password -- >#394 --> 2
// calc ans for each type of char for each row, and brute force using i, j, k rows as ans for 3 char types, and take min
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, m; cin >> n >> m ;
	vector<string> strings(n);for(int i=0;i<n;i++)cin >> strings[i];

	vector<vector<ll>> moves(n);for(int i=0;i<n;i++)moves[i].resize(3);
	
	for(int i=0;i<n;i++){
		moves[i][0] = moves[i][1] = moves[i][2] = 1e18 ;
		for(ll j = 0;j < m ;j++){
			if(strings[i][j] >= 'a' && strings[i][j] <= 'z'){moves[i][0] = min(moves[i][0], (ll)min(j,m-j));} // small lett
			else if(strings[i][j] >= '0' && strings[i][j] <= '9'){moves[i][1] = min(moves[i][1], (ll)min(j,m-j));} // numeric
			else if(strings[i][j] == '#' || strings[i][j] == '&' || strings[i][j] == '*'){moves[i][2] = min(moves[i][2], (ll)min(j,m-j));} // # & *
		}
	}
	ll answer = 1e18;
	for(int i = 0;i < n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(i != j && j != k && i != k){
					answer = min(answer, moves[i][0] + moves[j][1] + moves[k][2]);
				}
			}
		}
	}
	cout << answer << endl;


}