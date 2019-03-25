// C. An impassioned circulation of affection - #418 - 2
// Precomputation -- > for each l,r : map  #repaints to length got = (r-l+1), and take max for a particular # of repaints
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; scanf("%lld",&n); ;
	char s[1501];scanf("%s",s);string str(s);
	
	vector<vector<ll>> fills_to_max_cts(26);
	vector<vector<ll>> prefix_cnt(26);
	for(int i=0;i<26;i++){
		prefix_cnt[i].resize(n);
		prefix_cnt[i][0] = (str[0] == ('a' + i)) ;
		for(int j=1;j<n;j++){
			prefix_cnt[i][j] = prefix_cnt[i][j-1] + (str[j] == ('a' + i)) ;
		}
	}
	// printf("yolo\n");
	for(int letter = 0;letter < 26;letter++){
		fills_to_max_cts[letter].resize(n + 1);
		ll fill_mxm = 0;
		for(int l = 0;l<n;l++){
			for(int r = l;r < n;r++){
				ll fill = (r - l + 1)- (prefix_cnt[letter][r] - (l != 0)*prefix_cnt[letter][l - 1]);
				fill_mxm = max(fill,fill_mxm);
				fills_to_max_cts[letter][fill] = max((ll)(r - l + 1), fills_to_max_cts[letter][fill]);
			}
		}
		for(int i = fill_mxm+1;i<=n;i++)fills_to_max_cts[letter][i] = fills_to_max_cts[letter][fill_mxm];
	}
	// printf("yolo2\n");
	ll num_queries;scanf("%lld",&num_queries);
	for(int i=0;i<num_queries;i++){
		ll num;char latte[2];scanf("%lld%s",&num,latte);
		// printf("%lld %d\n",num, latte[0] - 'a');
		int let = (unsigned int)(latte[0] - 'a');
		printf("%lld\n", fills_to_max_cts[let][num]);
	}
}