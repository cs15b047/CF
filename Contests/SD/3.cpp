#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll t;cin>>t;
	for(int i=0;i<t;i++){
		ll n,m,k,l;scanf("%lld%lld%lld%lld",&n,&m,&k,&l);
		vector<ll>a(n+1);for(int j=0;j<n;j++)scanf("%lld",&a[j]);
		a[n]=k;
		sort(a.begin(),a.end());

		ll ans = 1e18;
		for(int j=0;j<a.size();j++){
			// cout << j << " " << (m+j+1)*l - a[j] << endl;
			ans = min(max((m+j+1)*l - a[j], (ll)0), ans);
		}
		printf("%lld\n",ans);
	}
}