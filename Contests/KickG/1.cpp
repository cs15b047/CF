#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll t;cin>>t;
	for(int i=0;i<t;i++){
		ll n;cin>>n;
		vector<ll>a(n),unq;
		for(int j=0;j<n;j++)scanf("%lld",&a[j]);
		map<ll,ll>cnt;
		for(int j=0;j<n;j++)cnt[a[j]]++;
		for(auto it:cnt)unq.push_back(it.first);
		// for(auto it:cnt)cout << it.first << " " << it.second << endl ;

		ll ans = 0;
		// all distinct
		ll s = unq.size();
		for(int j=0;j<s-2;j++){
			for(int k=j+1;k<s-1;k++){
				ll prod = unq[j]*unq[k];
				if(prod > 200000)break;
				if(cnt.find(prod) != cnt.end() && prod != unq[j] && prod != unq[k]){
					ans += cnt[unq[j]]*cnt[unq[k]]*cnt[prod] ;
				}
			}
			// cout << ans << endl;
		}
		if(cnt.find(1)!=cnt.end()){
			ans += ((cnt[1]*(cnt[1]-1)*(cnt[1]-2))/6) ;
			
			for(auto it:cnt){
				if(it.first != 1 && it.first != 0){
					ans += cnt[1] *((it.second * (it.second-1))/2) ;
				}
			}
			// cout << ans << endl;
		}
		//0s 2 0 1 distinct
		if(cnt.find(0)!=cnt.end()){
			ans += ((cnt[0]*(cnt[0]-1))/2) * (n - cnt[0]);
			ans += ((cnt[0]*(cnt[0]-1)*(cnt[0]-2))/6) ;
			// cout << ans << endl;
		}

		// 2 small same 1 diff large (doesn't incl 0s)
		for(int j=0;j<s-1;j++){
			ll prod = unq[j]*unq[j];
			if(cnt.find(prod) != cnt.end() && prod != unq[j]){
				ll c = cnt[unq[j]];
				ans += ((c*(c-1))/2) * cnt[prod] ;
			}
		}
		printf("Case #%d: %lld\n",i+1,ans);
	}
}