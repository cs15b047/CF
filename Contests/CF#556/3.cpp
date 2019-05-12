#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	ll cnt1=0,cnt2=0;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i] == 1)cnt1++;else cnt2++;
	}

	vector<bool> is_prime(4e5 + 1, 1);
	is_prime[1] = 0;
	for(ll i=2;i <= 400000;i++){
		if(is_prime[i]){
			for(ll j = i*i;j<=400000;j+=i){
				is_prime[j] = 0;
			}
		}
	}

	vector<ll> perm(n);
	ll curr_sum = 0;
	for(int i=0;i<n;i++){
		if(!is_prime[curr_sum + 1] && cnt2 != 0){perm[i] = 2;cnt2--;}
		else if(cnt1 != 0) {perm[i] = 1;cnt1--;}
		else {perm[i] = 2;cnt2--;}
		curr_sum += perm[i];
	}
	for(auto it: perm)cout << it << " ";cout << endl;


}