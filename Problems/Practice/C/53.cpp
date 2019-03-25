#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod = 1e9+7;
int main()
{
	int n;cin>>n;
	char s[1001];scanf("%s",s);
	string str(s);
	vector<int>a(26);
	for(int i=0;i<26;i++)scanf("%d",&a[i]);

	//1
	int j=0, curr_min = a[str[0]-'a'],curr_len = 1, num=0;
	while(j < n){
		curr_min = a[str[j]-'a'];
		curr_len = 1;
		j++;
		while(j < n && min(curr_min, a[str[j]-'a']) >= curr_len+1){
			curr_min = min(curr_min, a[str[j]-'a']) ;
			curr_len++;
			j++;
		}
		num++;
	}
	vector<ll>dp(n+1),len(n+1);
	dp[0] = 1;
	int ptr1=n,ptr2=n,curr = a[str[n-1]-'a'];

	for(ptr2 = n;ptr2 >=1;ptr2--){
		curr = a[str[ptr2-1]-'a'];
		for(ptr1=ptr2;(ptr1>=1) && (curr >= ptr2-ptr1+1) ;ptr1--){
			if(ptr1 >= 2)
				curr = min(curr, (int)a[str[ptr1-2]-'a']);
		}
		len[ptr2] = ptr2 - ptr1 ;
	}

	ll mxm = 0;
	for(int i=1;i<=n;i++)mxm = max(mxm, len[i]);

	for(int i=1;i<=n;i++){
		dp[i] = 0;
		for(int j=1;j<=len[i];j++){
			dp[i] = (dp[i] + dp[i-j]) % mod;
		}
	}
	cout << dp[n] % mod << endl << mxm << endl << num << endl ;
}