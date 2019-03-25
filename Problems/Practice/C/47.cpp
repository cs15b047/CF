#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n;cin>>n;
	vector<ll>a(n);for(int i=0;i<n;i++)cin>>a[i];
	ll s,f;cin>>s>>f;
	s--;f--;
	vector<ll> dp(n),p(n);
	p[0] = a[0];
	for(int i=1;i<n;i++)p[i] = p[i-1]+a[i];
	ll ans=0,index=-1;
	for (int i = 0; i < n; ++i)
	{
		ll j = (i - (f-s-1) + n) % n;
		if(i >= j){
			if(j==0){
				bool cond = ((ans == p[i]) && (((s - (index-1) + n) % n) > ((s - (j-1) + n) % n))) ;
				if(ans < p[i] || cond) {
					ans = p[i];index = j;
				}
			}
			else{
				bool cond = ((ans == p[i]-p[j-1]) && (((s - (index-1) + n) % n) > ((s - (j-1) + n) % n))) ;
				if((ans < (p[i]-p[j-1])) || cond){
					ans = p[i]-p[j-1]; index = j ;
				}				
			} 
		}
		else{
			bool cond = ((ans == (p[i] + (p[n-1] - p[j-1]))) && (((s - (index-1) + n) % n) > ((s - (j-1) + n) % n))) ;
			if((ans < (p[i] + (p[n-1] - p[j-1]))) || cond ) {
				ans = (p[i] + (p[n-1] - p[j-1])) ;
				index = j ;
			}
		}
	}
	ll i = ((s - (index) + n) % n) ;	
	cout << i+1 << endl;

	return 0;
}