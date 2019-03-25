#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n;cin >> n ;
	vector<ll> a(n);for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	printf("%lld\n",n+1 );
	for(int i=n-1;i>=0;i--){
		ll diff = ((i - (a[i] % n)) + n) % n ;
		// printf("%lld %lld\n",diff,a[i] );
		printf("1 %d %lld\n",i+1,diff );
		for(int j=0;j<=i;j++){
			a[j] += diff ;
		}
	}
	printf("2 %lld %lld\n", n, n );
}