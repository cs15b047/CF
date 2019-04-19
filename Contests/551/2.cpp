#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m,h; cin >> n >> m >> h ;
	vector<ll> a(m), b(n);
	vector<vector<ll>> top(n, vector<ll>(m , 0)), ans(n, vector<ll>(m , 0));
	for(int i=0;i<m;i++)cin >> a[i];
	for(int i=0;i<n;i++)cin >> b[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> top[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(top[i][j] == 1)ans[i][j] = a[j];
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cout << ans[i][j] <<" ";
	// 	}
	// 	cout << endl;
	// }
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(top[i][j] == 1 && b[i] < ans[i][j])ans[i][j] = b[i];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << ans[i][j] <<" ";
		}
		cout << endl;
	}
}