// D. Jerry's Protest 8VC Venture cup 2016 elmn round
// summation over i,j,k s.t. difference bw 2 players is i in round1 & p1 wins, j in round2 and p1 wins, k in round3 and k >= (i+ j) & p2 wins
// use counts of all difference values and suffix sums over them
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; scanf("%lld",&n);
	vector<ll> numbers(n);
	for (int i = 0; i < n; ++i)scanf("%lld",&numbers[i]);
	vector<ll> difference_count(5001), suffix_cnt(5001);
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < n; ++i){
		for(int j = 0;j < i ;j++){
			difference_count[numbers[i] - numbers[j]]++;
		}
	}
	for (ll i = 5000; i >= 0; --i){
		if(i == 5000)suffix_cnt[i] = difference_count[i];
		else suffix_cnt[i] = suffix_cnt[i + 1] + difference_count[i];
	}
	// for (int i = 0; i < 10; ++i)printf("%lld ",difference_count[i] );
	// for (int i = 0; i < 10; ++i)printf("%lld ",suffix_cnt[i] );

	double answer = 0.0;
	for(ll i = 1;i <= 5000;i++){
		if(difference_count[i] == 0)continue;
		for(ll j = 1; j<= 5000; j++){
			if(difference_count[j] == 0)continue;
			ll third_cond_cnt = 0;
			ll min_reqd = i + j + 1;
			if(min_reqd <= 5000)third_cond_cnt = suffix_cnt[min_reqd];
			answer += (double)(third_cond_cnt * difference_count[i] * difference_count[j]) ;
		}
	}
	answer = (answer*(double)8.0) / pow((double)(n*(n - 1)), 3) ;

	printf("%.9lf\n",answer );




}