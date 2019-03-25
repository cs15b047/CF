#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	ll n;cin>>n;
	vector<ll>v(n+1);for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
	int wrong=-1;
	if(v[1] != 0){wrong =1;}
	else{
		ll mxm = 0;
		for(int i=2;i<=n;i++){
			if(v[i] > mxm + 1){
				wrong =i;break;
			}
			mxm = max(mxm, v[i]);
		}
	}
	cout << wrong << endl ;
}