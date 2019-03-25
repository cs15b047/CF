#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b){
	if(!b)return a;return gcd(b, a%b);
}

vector<ll> reduce(ll a, ll b, ll c){	
	ll g = gcd(a,c);
	ll a1 = a/g;
	c = c/g;	
	g = gcd(b,c);
	ll b1= b/g;
	c = c/g;
	vector<ll>tmp;tmp.push_back(a1);
	tmp.push_back(b1);tmp.push_back(c);	
	return tmp;
}

int main(){
	ll n,m,k;cin>>n>>m>>k;
	vector<ll> frac = reduce(n,m,k);

	if(frac.back() >2){
		cout << "NO"<<endl;
	}
	else{
		cout << "YES" << endl;
		cout << "0 0"<<endl;
		if(frac.back() == 2){
			cout << frac[0] <<" 0"<<endl<<"0 "<<frac[1]<<endl;
		}
		else{
			if(frac[0]*2<=n)cout << 2*frac[0]<<" 0"<<endl<<"0 "<< frac[1]<<endl ;
			else cout << frac[0]<<" 0"<<endl<<"0 "<< 2*frac[1]<<endl ;
		}
		
	}

}