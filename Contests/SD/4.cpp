#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9+7;
int main(){
	ll t;cin>>t;
	for(int i=0;i<t;i++){
		ll n,k;cin>>n>>k;
		if(n < (k*(k+1))/2)cout << -1<< endl;
		else{
			ll tot = (n - (k*(k+1))/2);
			ll inc =  tot/ k ;
			ll remn = (tot % k);
			ll ans = 1;
			for(ll j=k-1;j>=1;j--){
				ll ele;
				ele = j + inc ;
				
				if(remn > 1){ele++;remn--;}

				ans = (ans * ((ele*(ele-1)) % mod)) % mod ;
			}
			ll last = k + inc;
			if(remn == 1)last++;
			ans = (ans * ((last * (last-1)) % mod)) % mod ;
			cout <<ans << endl;
		}
	}
}