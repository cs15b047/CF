#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; cin >> tests;
	for(int t = 0;t < tests;t++){
		ll n; cin >> n;
		vector<ll> arr(n + 1);for(int i = 1;i <= n;i++)cin >> arr[i];

		vector<ll> even_locns;
		for(int i = 1;i <= n;i++){
			if(llabs(arr[i]) % 2 == 0)even_locns.push_back(i);
		}
		ll sz = even_locns.size();
		ll not_poss = 0;
		for(int i = 0;i < sz;i++){
			if(llabs(arr[even_locns[i]]) % 4 != 0){
				ll left_tmp, right_tmp;
				if(i == 0){
					left_tmp = even_locns[0];
				} else{
					left_tmp = (even_locns[i] - even_locns[i - 1]);
				}

				if(i == sz - 1){
					right_tmp = ((n + 1) - even_locns[sz - 1]);
				} else{
					right_tmp = (even_locns[i + 1] - even_locns[i]);
				}
				not_poss += left_tmp * right_tmp;
			}
		}
		ll answer = (n * (n + 1))/2 - not_poss;
		cout << answer << endl;
	}

}