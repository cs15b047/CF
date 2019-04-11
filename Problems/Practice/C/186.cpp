#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int mod = 1e9 + 7;
int main(){
	ll n,k; cin >> n >> k;
	ll dist;
	if(n % k == 1)dist = 2*((n - 1)/k);
	else if(n % k == 2 || (n % k == 0 && k == 2))dist = 2*((n - 1)/k) + 1;
	else dist = 2*((n - 1)/k) + 2;
	cout << dist << endl;

	vector<ll> curr;curr.push_back(1);
	for(int i=2;i<=k+1;i++){
		cout << 1 << " " << i << endl;
	}
	for(int i=k+2;i<=n;i++){
		cout << i - k << " " << i << endl;
	}


}