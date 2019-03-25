// C. Slava and tanks #442- 2
// Do even , do odd , again do even. (Remn : Proof that this is optimal ?)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n ;
	if(n % 2 == 0){
		printf("%lld\n",(3*(n/2)) );
	}
	else{
		printf("%lld\n",((n/2)+(n/2)+(n+1)/2) );
	}
	for(ll i = 2;i<=n;i+=2)printf("%lld ",i );
	for(ll i = 1;i<=n;i+=2)printf("%lld ",i );
	for(ll i = 2;i<=n;i+=2)printf("%lld ",i );
}