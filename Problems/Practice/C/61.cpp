#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll lim = 3500000;
int main(){
	ll q;cin>>q;
	vector<ll> factors;
	for(ll i=2;i<=min((ll)(sqrt(q)+1),lim);i++){
		if(q % i == 0 && q != i){
			factors.push_back(i);
			// if(q/i!=i)factors.push_back(q/i);
		}
	}

	bool prime[3500001] = {};
	for(ll i=2;i<=min((ll)(sqrt(q)+1),lim);i++){
		if(!prime[i]){
			for(ll j=2*i;j<=min((ll)(sqrt(q)+1),lim);j+=i)prime[j] =1;
		}
	}

	if(factors.empty())cout << 1 << endl << 0 << endl ;

	else{
		ll p1=-1,p2=-1;
		for(auto it: factors){
			if(!prime[it] && p1 == -1)p1 = it;
			else if(!prime[it] && p1 != -1){p2 = it;break;}
		}
		if(p1 !=-1 && p2 != -1 && q != p1*p2 )cout << "1\n"<<p1*p2<<endl;
		else if((q % (p1*p1) == 0) && q != p1*p1)cout << "1\n"<<p1*p1<<endl;
		else cout << 2 << endl;		
	}

}