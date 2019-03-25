#include <bits/stdc++.h>
using namespace std ;

int main(int argc, char const *argv[])
{
	string num ;

	cin >> num ;

	int sum = -1;
	int ans =0 ;
	
	vector<vector<int>> dp(num.length()) ;
	for (int i = 0; i < dp.size(); ++i)	
		dp[i].resize(3) ;

	int d = (num[0] - '0') ;
	dp[0][0] = (d% 3 == 0);
	dp[0][1] = (d% 3 == 1);
	dp[0][2] = (d% 3 == 2);

	for (int i = 1; i < num.length(); ++i)
	{
		d = (num[0] - '0') % 3 ;
		if (!dp[i-1][1] && !dp[i-1][2])
		{
			dp[i][0] = (d==0) + dp[i-1][0] ;
			dp[i][1] = (d==1); dp[i][2] = (d==2);			
		}
	}

	return 0;
}