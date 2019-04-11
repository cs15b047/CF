#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,h; cin >> n >> h;
	vector<ll> ht(n);for(int i=0;i<n;i++)cin >> ht[i];
	ll opt_k = 1;
	for(int k = 1;k <= n;k++){
		vector<ll> new_ht(ht.begin(),ht.begin() + k);sort(new_ht.begin(),new_ht.end());
		ll reqd = 0;
		for(int i = new_ht.size() - 1;i >= 0;i-=2){
			if(i == 0)reqd += new_ht[0];
			else reqd += max(new_ht[i], new_ht[i - 1]);
		}
		if(reqd <= h)opt_k = k;
	}
	cout << opt_k << endl;
}