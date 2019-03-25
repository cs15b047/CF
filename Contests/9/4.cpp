#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll mod = 998244353;
ll gcd(ll a, ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	ll n;cin>>n;
	vector<ll>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	vector<int>divs(n);
	map<ll,ll> prime_cnt;
	for(int i=0;i<n;i++){
		ll sqr = (ll)sqrt(a[i]),sqr2 = sqr+1;
		ll sqrsqr = (ll)sqrt(sqr),sqrsqr2 = (ll)sqrt(sqr) + 1;
		ll cr = (ll)pow(a[i],(double)1/(double)3),cr2 = cr+1;
		if(sqrsqr*sqrsqr*sqrsqr*sqrsqr == a[i] || sqrsqr2*sqrsqr2*sqrsqr2*sqrsqr2  == a[i]){
			divs[i] = 5;
			cout << sqrsqr<<endl;
			if(sqrsqr*sqrsqr*sqrsqr*sqrsqr == a[i])prime_cnt[sqrsqr]+= 4;
			if(sqrsqr2*sqrsqr2*sqrsqr2*sqrsqr2  == a[i])prime_cnt[sqrsqr2]+=4;
		}
		else if(sqr*sqr==a[i] || sqr2*sqr2*sqr2 == a[i]){
			cout << sqr <<endl;
			divs[i] = 3;
			if(sqr*sqr==a[i])prime_cnt[sqr]+=2;
			if(sqr2*sqr2==a[i])prime_cnt[sqr2]+=2;
		}
		else if(cr*cr*cr == a[i] || cr2*cr2*cr2 == a[i]){
			cout << cr << " ";
			divs[i] = 40;
			if(cr*cr*cr == a[i])prime_cnt[cr]+=3;
			if(cr2*cr2*cr2 == a[i])prime_cnt[cr2]+=3;
		}
		else{
			divs[i] = 41;
		}
	}
	map<ll,ll> cnt,vis;
	for(int i=0;i<n;i++){
		cnt[a[i]]++;
	}
	ll ans = 1;
	for(int i=0;i<n;i++){
		if(divs[i] == 41 && vis.find(a[i])==vis.end()){
			vis[a[i]]=1;
			int fl = 0;
			for(int j=0;j<n;j++){
				if(i != j && a[i] != a[j]){
					ll g = gcd(a[i],a[j]);
					if(g != 1){
						fl = 1;
						ll p1 = g,p2 = a[i]/g;
						prime_cnt[p1]+=cnt[a[i]];
						prime_cnt[p2]+=cnt[a[i]];
						break;
					}
				}
			}
			if(fl==0){
				ans = (ans * (((cnt[a[i]]+1)*(cnt[a[i]]+1))%mod)) % mod;
			}
		}
	}
	for(auto it: prime_cnt){
		ans = (ans * (it.second+1)) % mod ;
	}
	cout << ans << endl ;
	
	
}