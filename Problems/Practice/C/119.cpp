// F. Clique in the Divisibility Graph vk cup 2015 finals
// Problem reduces to finding a series of numbers, next divisible by previous.
// Dp[num] --> max size of clique if largest number is num. When giving answer  in asc order for particular number, increment answer for all its multiples till MaX.
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int dp[1000001]={};
int main(){
	int n; cin >> n ;
	int mxm = 1;
	vector<int> num(n);for(int i=0;i<n;i++){scanf("%d",&num[i]);mxm= max(mxm,num[i]);}
	int answer = 1;
	for(int i=0;i<n;i++){
		dp[num[i]]++;
		for(int j=2*num[i];j<=mxm;j+=num[i]){
			dp[j] = max(dp[j],dp[num[i]]);
		}
		answer = max(dp[num[i]], answer);
	}
	printf("%d\n",answer );
}