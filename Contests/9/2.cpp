#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
int main(){
	ll t;cin>>t;
	for(int q=0;q<t;q++){
		ll a,b;	cin>>a>>b;
		ll sqr = (ll)sqrt(a+b)+1;
		if(a-b != 1)cout << "NO"<<endl;
		else{
			int fl=0;
			for(ll i=2;i<=sqr&& i<(a+b);i++){
				if((a+b)%i == 0){
					cout << "NO"<<endl;
					fl=1;
					break;
				}
			}
			if(fl==0)cout<< "YES"<<endl;
		}
	}
}