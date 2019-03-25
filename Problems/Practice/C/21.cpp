#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
ll mxm = 1e18;
int main()
{
	int n;cin>>n;
	vector<ll>c(n);vector<string> str(n);
	vector<vector<ll>> dp(n) ;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int i=0;i<n;i++)cin>>str[i];
	for(int i=0;i<n;i++)dp[i].resize(2);

	dp[0][0] = 0;dp[0][1] = c[0] ;
	int err = 0;

	for(int i=1;i<n;i++){
		string rev = str[i]; reverse(rev.begin(),rev.end());
		string rev_prev = str[i-1];reverse(rev_prev.begin(),rev_prev.end());
		dp[i][0] = mxm;dp[i][1] = mxm;

		if(dp[i-1][0] != mxm ){
			if(str[i] >= str[i-1]){
				dp[i][0] = dp[i-1][0] ;
			}
			if(rev >= str[i-1]){
				dp[i][1] = dp[i-1][0] + c[i] ;
			}
		}

		if(dp[i-1][1] != mxm){			
			if(str[i] >= rev_prev){
				dp[i][0] = min(dp[i][0],dp[i-1][1]) ;
			}
			if(rev >= rev_prev){
				dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]) ;
			}
		}
		if(dp[i][0] == mxm && dp[i][1] == mxm){
			cout << -1 << endl ;
			err = 1;
			break;
		}		
	}
	if(err == 0){
		cout << min(dp[n-1][0],dp[n-1][1]) << endl ;
	}

	return 0;
}