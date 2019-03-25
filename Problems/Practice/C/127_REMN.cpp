#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	int n;scanf("%d",&n);
	vector<int>a(n);for(int i=0;i<n;i++)scanf("%d",&a[i]);
	vector<map<int,int>>maps(n);
	vector<int>dp(n);
	dp[0]=1;
	maps[0][-1] = 1;
	for(int i=1;i<n;i++){
		maps[i].clear();
		dp[i] =0;
		for(int j=i-1;j>=0;j--){
			if(maps[i].find(a[j]) == maps[i].end()){
				maps[i][a[j]] = max(maps[j][a[i]] + 1,2);
				dp[i] = max(dp[i], maps[i][a[j]]);
			}
		}
	}
	int ans = 1;
	for(auto it:dp)ans = max(ans, it);
	printf("%d\n",ans );
}