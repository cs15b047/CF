#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll tests;
ll num_dishes;
vector<ll> cooking_time;

vector<vector<ll>> dp;

void print(){
	for(int i = 0;i <= (3 * num_dishes)/2;i++){
		for(int j =0;j <= num_dishes;j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

void init(){
	cooking_time.clear();
	dp.clear();
}

void take_input(){
	scanf("%lld", &num_dishes);
	dp.resize(301, vector<ll>(num_dishes + 1));
	cooking_time.resize(num_dishes + 1);
	for(int i = 1;i <= num_dishes;i++)
		scanf("%lld", &cooking_time[i]);
	sort(cooking_time.begin(), cooking_time.end());
}

void init_ans_array(){
	dp[0][0] = 0;
	for(int i = 0; i <= 300; i++){
		dp[i][0] = 0;
	}
	for(int i = 0; i <= 300; i++){
		for(int j = i + 1;j <= num_dishes; j++){
			dp[i][j] = 1e9;
		}
	}
	// print();
}

ll get_cost(ll time, ll dish_idx){
	return llabs(time - cooking_time[dish_idx]);
}

ll calc_min_value(){
	init_ans_array();
	for(ll time = 1; time <= 300; time++){
		for(ll dishes = 1;dishes <= min(time, num_dishes); dishes++){
			dp[time][dishes] = min(dp[time - 1][dishes], dp[time - 1][dishes - 1] + get_cost(time, dishes));
		}
	}
	return dp[300][num_dishes];
}

int main(){
	scanf("%lld", &tests);
	for(int q = 0; q < tests; q++){
		init();
		take_input();
		ll value = calc_min_value();
		// print();
		printf("%lld\n", value);
	}
}