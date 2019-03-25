#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t;cin>>t;
	for(int i=0;i<t;i++){
		ll a;cin>>a;
		ll ans = 1;
		while(a!=0){
			if(a%2==1)ans = ans * 2;
			a = a/2 ;
		}
		cout << ans << endl ;
	}
}