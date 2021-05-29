#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int max_rating(vector<int> ratings) {
	ll n = ratings.size();

	sort(ratings.begin(), ratings.end());

	if(n == 1 && ratings[0] < 0)return 0;
	else if(n == 1) return ratings[0];

	ll pos_idx = upper_bound(ratings.begin(), ratings.end(), 0) - ratings.begin();

	ll num_pos = (n  - pos_idx);

	ll pos_prod = -1e9;
	for(int i = n - 1;i >= min(pos_idx, n - 3);i--){
		if(i == n - 1){
			pos_prod = ratings[n - 1];
		} else pos_prod = pos_prod * ratings[i];
	}

	ll neg_prod = -1e9;
	if(ratings[0] < 0 && ratings[1] < 0){
		neg_prod = ratings[0] * ratings[1];
		if(ratings[n - 1] > 0)neg_prod = neg_prod * ratings[n - 1];
	}
	ll ans = max(neg_prod, pos_prod);
	ans = max(ans, (ll)0);
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

}