#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; scanf("%lld",&t);
	for(int q=0;q<t;q++){
		ll n; scanf("%lld",&n);
		vector<vector<ll>> M(n, vector<ll>(n , 0));for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%lld",&M[i][j]);
		int flag = 1;
		for(int i=0;i<n;i++){
			int tmp = 0;
			for(int j=0;j<n;j++){
				if(M[i][j] == 0){tmp = 1;break;}
			}
			if(tmp == 0){flag =0;break;}
		}
		for(int j=0;j<n;j++){
			int tmp = 0;
			for(int i=0;i<n;i++){
				if(M[i][j] == 0){tmp = 1;break;}
			}
			if(tmp == 0){flag =0;break;}
		}
		if(flag == 1)printf("YES\n");
		else printf("NO\n");
	}
}