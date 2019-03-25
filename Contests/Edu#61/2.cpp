#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(){
	ll n; scanf("%lld",&n);
	vector<ll>a(n);for(int i=0;i<n;i++)scanf("%lld",&a[i]);sort(a.begin(),a.end(),greater<ll>());
	ll m; scanf("%lld",&m);
	vector<ll>q(m);for(int i=0;i<m;i++)scanf("%lld",&q[i]);
	ll sm=0;
	for(int i=0;i<n;i++)sm += a[i];
	for(int i=0;i<m;i++){
		printf("%lld\n",sm - a[q[i] - 1]);
	}
}