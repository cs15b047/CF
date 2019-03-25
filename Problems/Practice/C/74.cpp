#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll get_num_one_bits(ll num){
	ll ans = 0;
	while(num != 0){
		ans+=(num%2);
		num = num /2;
	}
	return ans;
}

int main(){
	ll n;cin>>n;
	// if(n == 1)cout << 0 << endl ;
	vector<ll>a(n+1),b(n+1),pref_sum(n+1);for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)b[i] = get_num_one_bits(a[i]);
	for(int i=1;i<=n;i++)pref_sum[i] = pref_sum[i-1] + b[i];
	vector<ll>even_inds,odd_inds;even_inds.clear();odd_inds.clear();
	for(int i=0;i<=n;i++){
		if(pref_sum[i] % 2 == 0)even_inds.push_back(i);
		else odd_inds.push_back(i);
	}
	ll ans = 0;
	vector<ll> inds;
	for(int p =0;p<=1;p++){
		if(p==0)inds = even_inds;
		else inds = odd_inds ;

		// for(auto it:inds)cout << it <<" ";
		// cout << endl ;
		// cout << inds.size() << endl ;
		for(int l=0;l<(ll)inds.size()-1;l++){
			int j = 1;
			if(inds[l+1] - inds[l] == 1)j++;
			// cout << l << " " << j <<"yo"<< endl ;
			while(((l+j) < inds.size()) && (inds[l+j] - inds[l] <= 64)){
				// cout << j<<"mo" << endl ;
				// cout << inds[l+j] << " "<< inds[l] << endl ;
				int flag = 1 ;
				ll sum = pref_sum[inds[l+j]] - pref_sum[inds[l]];
				// cout  << sum << endl ;
				for(int k = inds[l]+1;k<=inds[l+j];k++){
					if(b[k] > sum / 2){
						flag = 0;
						// cout << b[k] << " " << sum << endl ;
						break;
					}
				}
				if(flag == 1)ans++;
				j++;
			}
			ll curr = l + j;
			// cout<< curr << endl ;
			ans += (inds.size()-1) - curr + 1 ;
			// cout << ans << endl ;
		}
	}
	cout << ans << endl ;
}