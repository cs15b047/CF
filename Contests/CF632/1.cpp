#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; cin >> tests;
	for(int t = 0;t < tests;t++){
		ll n, m; cin >> n >> m;
		if((n *m) % 2 == 1){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					if((i + j) % 2 == 0)cout << "B";
					else cout << "W";
				}
				cout << endl;
			}
		} else{
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					if((i + j) % 2 == 0 && (i != 0 || j != 0))cout << "W";
					else cout << "B";
				}
				cout << endl;
			}
		}
	}
}