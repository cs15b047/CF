#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b){
	if(b == 0)return a;
	return gcd(b, a % b);
}

vector<ll> get_divisors(ll num){
	vector<ll> answer;
	for(ll i = 2;i <= (ll)sqrt(num);i++){
		if(i * i == num)answer.push_back(i);
		else{
			if(num % i == 0){
				answer.push_back(i);
				answer.push_back(num/i);
			}
		}
	}
	sort(answer.begin(), answer.end());
	answer.push_back(num);
	return answer;
}

int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q < t; q++){
		ll a, m; scanf("%lld%lld",&a, &m);
		ll g = gcd(a, m);
		ll c1 = a / g, c2 = m / g;

		vector<ll> divisors = get_divisors(c2);
		for(auto it: divisors)cout << it << " ";cout << endl;

		ll compl_ans = divisors.size();
		ll ans = (c2 - 1) - compl_ans + 1;
		printf("%lld\n",ans);
	}
}