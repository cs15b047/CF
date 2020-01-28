#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> nxt_vessel, curr_quantity, capacities;
ll num_vessels;

ll find_nxt(ll vessel_num){
	if(nxt_vessel[vessel_num] < 0)return vessel_num;
	nxt_vessel[vessel_num] = find_nxt(nxt_vessel[vessel_num]);
	return nxt_vessel[vessel_num];
}

void simulate(ll vessel_num, ll to_be_added){
	if(to_be_added == 0 || vessel_num > num_vessels - 1 || vessel_num < 0)
		return;
	if(curr_quantity[vessel_num] + to_be_added < capacities[vessel_num]){
		curr_quantity[vessel_num] = curr_quantity[vessel_num] + to_be_added;
		return;
	} else{
		to_be_added -= 	(capacities[vessel_num] - curr_quantity[vessel_num]);
		curr_quantity[vessel_num] = capacities[vessel_num];
		if(vessel_num == num_vessels - 1)
			return;
		else{
			ll node = find_nxt(vessel_num + 1);
			nxt_vessel[vessel_num] = node;
			if(to_be_added == 0)return;
			simulate(node, to_be_added);
		}
	}
}

int main(){
	scanf("%lld",&num_vessels);
	nxt_vessel.resize(num_vessels, -1);
	capacities.resize(num_vessels);
	curr_quantity.resize(num_vessels, 0);
	for(int i = 0;i < num_vessels;i++)
		scanf("%lld",&capacities[i]);

	ll num_queries;
	scanf("%lld",&num_queries);
	for(int i = 0;i < num_queries;i++){
		ll query_type;
		scanf("%lld",&query_type);
		if(query_type == 1){
			ll vessel_num, added_quantity;
			scanf("%lld%lld",&vessel_num, &added_quantity);
			vessel_num--;
			// find vessel where water will pour
			ll nxt = find_nxt(vessel_num);
			// cout << nxt << endl;
			simulate(nxt, added_quantity);

		} else{
			ll vessel_num;
			scanf("%lld",&vessel_num);
			printf("%lld\n",curr_quantity[vessel_num - 1] );
		}
	}
}