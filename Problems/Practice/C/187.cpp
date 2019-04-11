#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; scanf("%lld",&n);
	vector<vector<ll>> grid(n+1, vector<ll>(2, 0));
	for(int i=1;i<=n;i++)scanf("%lld",&grid[i][0]);for(int i=1;i<=n;i++)scanf("%lld",&grid[i][1]);
	vector<ll> prefix_sum(n+1, 0), suffix_sum(n+2, 0), suffix_sum0(n+2, 0), suffix_sum1(n+2, 0);
	for(int i=1;i<=n;i++)
		prefix_sum[i] = prefix_sum[i - 1] + (i % 2 == 1) * ((ll)(2*(i-1)) * grid[i][0] + (ll)(2*(i-1) + 1) * grid[i][1]) + (i % 2 == 0) * ((ll)(2*(i-1)) * grid[i][1] + (ll)(2*(i-1) + 1) * grid[i][0]);

	// for(int i=1;i<=n;i++)cout << prefix_sum[i] << " ";cout << endl;

	for(int i=n;i>=1;i--){
		suffix_sum1[i] = suffix_sum1[i + 1] + (2*(n - i) + 1) * grid[i][0] + suffix_sum[i + 1];
		suffix_sum0[i] = suffix_sum0[i + 1] + (2*(n - i) + 1) * grid[i][1] + suffix_sum[i + 1];
		suffix_sum[i] = suffix_sum[i + 1] + (grid[i][0] + grid[i][1]);
	}
	// for(int i=1;i<=n;i++)cout << suffix_sum[i] << " ";cout << endl;
	// for(int i=1;i<=n;i++)cout << suffix_sum0[i] << " ";cout << endl;
	// for(int i=1;i<=n;i++)cout << suffix_sum1[i] << " ";cout << endl;
	ll answer = 0;
	for(int i=0;i<=n;i++){
		answer = max(answer, prefix_sum[i] + ((i + 1) % 2 == 0) * suffix_sum1[(i + 1)] + ((i + 1) % 2 == 1) * suffix_sum0[(i + 1)] + (ll)(2*i) * suffix_sum[i + 1]);
	}
	cout << answer << endl;
}