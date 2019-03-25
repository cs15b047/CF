#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int gcd(int x, int y){
	if(y==0)return x;
	return gcd(y, x % y);
}
int main()
{
	bool not_primes[15000001];
	// int lowest_prime_factor[15000001];
	ll n;scanf("%lld",&n);
	vector<int>a(n);
	scanf("%d",&a[0]);
	int G=a[0];
	int mxm = 1;
	for(int i=1;i<n;i++){scanf("%d",&a[i]);G = gcd(G,a[i]);}
	for(int i=0;i<n;i++){a[i] = a[i]/G ;mxm = max(mxm,a[i]);}

	not_primes[1] =1;
	// printf("%d\n",mxm);
	map<int,int> lowest_prime_factor;
	for(ll i=2;i<=mxm;i++){
		if(!not_primes[i]){
			for(ll j=i*i;j<=mxm;j=j+i){				
				if(!not_primes[j]){
					lowest_prime_factor[j] = i ;
					not_primes[j]=1;
				}
			}
		}
	}
	map<int,int>cnt_fact;
	for(int i=0;i<n;i++){
		if(!not_primes[a[i]])cnt_fact[a[i]]++;
		else{			
			int x = a[i];			
			while(x != 1 && not_primes[x]){
				int f = lowest_prime_factor[x];
				cnt_fact[f]++;
				while(x % f == 0)x = x / f ;
			}			
			if(x != 1 && !not_primes[x])cnt_fact[x]++;			
		}
	}
	int ans = INT_MAX;
	if(cnt_fact.empty())ans = -1;
	else{
		for(auto it:cnt_fact){
			ans = min(ans, (int)n - (int)it.second);
		}
	}
	printf("%d\n",ans );
}