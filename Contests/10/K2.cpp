#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	ll t;cin>>t;
	for(int i=0;i<t;i++){
		long double n,k;cin>>n>>k;
		vector<ll>v(n);for(int j=0;j<n;j++)scanf("%lld",&v[j]);
		long double sum = 0;
		for(auto it:v)sum += it ;
		// map<ll,ll>cnt;cnt.clear();for(int j=0;j<n;j++)cnt[v[j]]++;

		// long double sum=0;
		// long double x=0,tot=0;
		// long double ans=0;
		// for(auto it:cnt)sum += (long double)it.first*it.second;

		// for(auto itr_map = cnt.rbegin();itr_map != cnt.rend();itr_map++){
		// 	x += (long double)itr_map->second ;
		// 	tot += (long double)itr_map->first *itr_map->second ;
		// 	long double rem_sum = sum - tot ;
		// 	cout << x << " " << tot << " " << rem_sum << endl ;

		// 	if(x != n)rem_sum = rem_sum/(n-x);
		// 	// cout << x<< n << rem_sum << mxm << endl ;
		// 	long double mxm = tot/x ;
		// 	if(x == n)ans = max(ans,mxm) ;
		// 	else{
		// 		long double prob = ((long double)1 - pow((long double)1 - x/n, k+1));
		// 		ans = max(ans, prob * mxm + (1- prob) * rem_sum);
		// 	}	
		// }
		sort(v.begin(),v.end());
		vector<long double> E(k+1);
		E[0] = sum / n ;

		for(int j=1;j<=k;j++){
			long double tmp = 0 ;
			ll pos = lower_bound(v.begin(),v.end(),E[j-1]) - v.begin() ;
			for(int l=0;l<n;l++)tmp += max((long double)v[l], E[j-1])/n ;
			E[j] = tmp;
		}
		// for(int i=0;i<=k;i++)ans = max(ans, E[i])
		printf("Case #%d: %.6Lf\n",i+1, E[k]);
	}
}