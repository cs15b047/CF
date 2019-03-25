#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(){
	ll n,q; cin >> n >> q;
	vector<ll> l(q),r(q);for(int j=0;j<q;j++)cin >> l[j]>>r[j];

	vector<ll> painted(n + 2, 0);
	for(int j=0;j<q;j++){
		for(int i=l[j];i<=r[j];i++)painted[i]++;
	}
	painted[n + 1] = 1e18;

	vector<ll> missed(q,0);

	vector<ll>prefix_1_cnt(n + 2, 0), prefix_2_cnt(n + 2, 0);
	for(int i=1;i<=n+1;i++){
		prefix_1_cnt[i] = prefix_1_cnt[i-1] + (painted[i] == 1);
		prefix_2_cnt[i] = prefix_2_cnt[i-1] + (painted[i] == 2);
	}
	ll fin_ans = 1e18, answer = 0;
	for(int i=1;i<=n;i++)answer += (painted[i] == 0);
	for(int j=0;j<q;j++){
		for(int k = j + 1;k < q; k++){
			ll ans = 0;
			ll l1 = l[j],r1 = r[j],l2 = l[k],r2 = r[k];
			// cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;

			if((l1 <= l2 && r1 >= r2)){
				ans += (prefix_2_cnt[r2] - prefix_2_cnt[l2 - 1]) ;
				ans += max(prefix_1_cnt[l2 - 1] - prefix_1_cnt[l1 - 1], (ll)0);
				ans += max(prefix_1_cnt[r1] - prefix_1_cnt[r2], (ll)0);
			}
			else if((l2 <= l1 && r2 >= r1)){
				ans += prefix_2_cnt[r1] - prefix_2_cnt[l1 - 1] ;
				ans += max(prefix_1_cnt[l1 - 1] - prefix_1_cnt[l2 - 1], (ll)0);
				ans += max(prefix_1_cnt[r2] - prefix_1_cnt[r1], (ll)0);
			}
			else if(r1 < l2 || r2 < l1){
				ans += prefix_1_cnt[r1] - prefix_1_cnt[l1 - 1];
				ans += prefix_1_cnt[r2] - prefix_1_cnt[l2 - 1];
			}
			else if(r2 >= l1 && l2 <= l1){
				ans += max(prefix_1_cnt[l1 - 1] - prefix_1_cnt[l2 - 1], (ll)0);
				ans += max(prefix_1_cnt[r1] - prefix_1_cnt[r2], (ll)0);
				ans += prefix_2_cnt[r2] - prefix_2_cnt[l1 - 1] ;
			}
			else if(r1 >= l2 && l1 <= l2){
				// cout << "here"<<endl;
				ans += max((ll)0,prefix_1_cnt[l2 - 1] - prefix_1_cnt[l1 - 1]);
				ans += max((ll)0, prefix_1_cnt[r2] - prefix_1_cnt[r1]);
				ans += prefix_2_cnt[r1] - prefix_2_cnt[l2 - 1] + prefix_1_cnt[r1] - prefix_1_cnt[l2 - 1];
			}
			fin_ans  = min(fin_ans, ans);
			// cout << ans << endl;
		}
	}
	cout << n - (fin_ans + answer) << endl;
}