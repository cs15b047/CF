// normal implementn
// calculate factors of every num, and see in the range
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b){ if(b == 0)return a; return gcd(b, a%b);}

int main(){
	ll a,b; cin >> a >> b ;
	ll g = gcd (a, b);
	ll n; cin >> n ;

	vector<ll> divisors;
	for(ll i = 1;i <= (ll)sqrt(g) + 1; i++){
		if(g % i == 0){
			divisors.push_back(i);
			if(i*i != g)divisors.push_back(g/i);
		}
	}
	sort(divisors.begin(), divisors.end());
	// for(auto &it:divisors)cout << it << endl;
	for(int i=0;i<n;i++){
		ll low, high;scanf("%lld%lld",&low,&high);
		ll ind_l = lower_bound(divisors.begin(),divisors.end(), low) - divisors.begin();
		ll ind_h = lower_bound(divisors.begin(),divisors.end(), high) - divisors.begin();

		if(divisors[ind_h] != high)ind_h--;
		if(ind_l > ind_h)printf("-1\n");
		else{
			printf("%lld\n",divisors[ind_h] );
		}
	}
}