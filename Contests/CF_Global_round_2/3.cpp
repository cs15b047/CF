#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll A[501][501]={},B[501][501]={}, D[501][501]={};

int main(){
	ll n,m; scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)scanf("%lld",&A[i][j]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)scanf("%lld",&B[i][j]);
	}
	ll tot_diff = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(A[i][j] != B[i][j]){D[i][j] = 1; tot_diff++;}
		}
	}
	int flag = 0;
	for(int i=0;i<n;i++){
		ll row_sum = 0;
		for(int j=0;j<m;j++)row_sum+=D[i][j];
		if(row_sum % 2 != 0){flag = 1;break;}
	}
	for(int j=0;j<m;j++){
		ll col_sum = 0;
		for(int i=0;i<n;i++)col_sum+=D[i][j];
		if(col_sum % 2 != 0){flag = 1;break;}
	}
	if((n == 1 || m == 1) && tot_diff != 0)flag = 1;
	if(flag == 1){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
}