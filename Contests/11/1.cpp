#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	ll x,y,z,t1,t2,t3;cin>>x>>y>>z>>t1>>t2>>t3;
	ll p1 = t1*abs(y-x);
	ll p2=	t2*abs(y-x) + t2 * abs(z-x) + 3*t3;
	if(p1 < p2){
		cout << "NO"<<endl;
	}
	else{
		cout << "YES"<<endl;
	}
}