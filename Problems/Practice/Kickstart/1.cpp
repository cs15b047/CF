#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll t;
	scanf("%lld",&t);
	for(ll q = 0;q < t;q++){
		ll n, p; scanf("%lld%lld",&n,&p);
		vector<ll> skill(n), prefix_sum_skill(n);
		for(int i = 0;i < n;i++)
			scanf("%lld",&skill[i]);

		sort(skill.begin(), skill.end());
		prefix_sum_skill[0] = skill[0];
		for(int i = 1;i < n;i++)
			prefix_sum_skill[i] = prefix_sum_skill[i - 1] + skill[i];
		
		ll curr = p - 1, answer = 1e18;
		for(curr = p - 1;curr < n;curr++){
			ll tmp_ans = p * skill[curr];
			if(curr == p - 1){
				tmp_ans = tmp_ans - prefix_sum_skill[p - 1];
			} else{
				tmp_ans = tmp_ans - (prefix_sum_skill[curr] - prefix_sum_skill[curr -p]);
			}
			answer = min(answer, tmp_ans);
		}
		printf("Case #%lld: %lld\n", q + 1, answer);
	}
}
