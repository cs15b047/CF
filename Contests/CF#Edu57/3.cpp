#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >>t;
	ll flag =0;
	ll ans[180];
	for(ll ang=1;ang<180;ang++){
		flag = 0;
		for(ll n = 3;n <= 360;n++){
			for(ll mult = 1;mult <= n - 2;mult++){
				if(((mult*180) % n == 0) && ((mult*180)/n == ang)){
					// cout << ang << " " << n << " " << mult << endl;
					ans[ang] = n;
					flag = 1;
					break;
				}
			}
			if(flag == 1)break;
		}
	}

	for(int i=0;i<t;i++){
		ll ang; scanf("%lld",&ang);
		printf("%lld\n",ans[ang]);
	}
}