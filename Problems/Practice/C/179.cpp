// D. Xenia and Bit Operations  CF# 197 - 2
// Traverse the path from node to parent and make recalculate those nodes
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m;cin>>n>>m;
	vector<ll> a((ll)pow(2,n) + 1);for(int i=1;i<=(ll)pow(2,n);i++)cin >> a[i];
	vector<vector<ll>> tree(n + 1);
	tree[n] = a;
	for(int i = n - 1;i >=0;i--){
		ll sz = (ll)pow(2,i);
		tree[i].resize(sz + 1);
		for(int j = 1;j <= sz;j++){
			if(i % 2 == (n-1) % 2)tree[i][j] = tree[i+1][2*j - 1] | tree[i+1][2*j] ;
			else tree[i][j] = tree[i+1][2*j - 1] ^ tree[i+1][2*j] ;
		}
	}

	for(int i=0;i<m;i++){
		ll p,b; cin >> p >> b ;
		tree[n][p] = b;
		ll curr = p ;
		for(int j = n - 1;j>=0;j--){
			ll pos = (curr + 1)/2;
			ll ele1;
			if(j % 2 == (n - 1) % 2)ele1 = tree[j + 1][2*pos - 1] | tree[j + 1][2*pos] ;
			else ele1 = tree[j + 1][2*pos - 1] ^ tree[j + 1][2*pos] ;
			tree[j][(curr + 1)/2] = ele1;
			curr = pos ;
		}
		cout << tree[0][1] << endl;
	}


}