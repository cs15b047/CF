#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; scanf("%lld",&t);
	for(int q = 0;q < t;q++){
		ll n; scanf("%lld",&n);
		vector<ll> jars(2*n);for(int i = 0;i < 2*n;i++)scanf("%lld",&jars[i]);
		ll diff_1_2 = 0;
		for(int i = 0;i < 2*n;i++){
			if(jars[i] == 1)diff_1_2++;
			else diff_1_2--;
		}
		
		ll answer = 2*n;
		if(diff_1_2 == 0)answer = 0;
		else{
			// clc diff array bw 1 and 2
			vector<ll> diff(2*n, 0);
			diff[n - 1] = (jars[n - 1] == 1) - (jars[n - 1] == 2);
			diff[n] = (jars[n] == 1) - (jars[n] == 2);
			for(int i = n - 2;i >= 0;i--){
				diff[i] = diff[i + 1] + ((jars[i] == 1) - (jars[i] == 2));
			}
			for(int i = n + 1;i < 2*n;i++){
				diff[i] = diff[i - 1] + ((jars[i] == 1) - (jars[i] == 2));
			}

			// diff to locn, closest to cntr
			map<ll,ll> left_diff, right_diff;
			for(int i = n - 1;i >=0;i--){
				if(left_diff.find(diff[i]) == left_diff.end()){
					left_diff[diff[i]] = i;
				}
			}
			for(int i = n;i < 2*n;i++){
				if(right_diff.find(diff[i]) == right_diff.end()){
					right_diff[diff[i]] = i;
				}
			}
			for(int i = 0;;){
				if(i != 0 && i != diff_1_2){
					if(left_diff.find(i) != left_diff.end() && right_diff.find(diff_1_2 - i) != right_diff.end()){
						answer = min(answer, right_diff[diff_1_2 - i] - left_diff[i] + 1);
					}
				} else {
					if(i == 0 && right_diff.find(diff_1_2) != right_diff.end()){
						answer = min(answer, right_diff[diff_1_2] - n + 1);
					}
					if(i == diff_1_2 && left_diff.find(diff_1_2) != left_diff.end()){
						answer = min(answer, n - left_diff[diff_1_2]);
					}
				}
				if(diff_1_2 < 0){
					i--;
					if(i < diff_1_2)break;
				}
				else{
					i++;
					if(i > diff_1_2)break;
				}
			}
		}
		printf("%lld\n",answer );
	}
}