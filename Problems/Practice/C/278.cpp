#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_elements;
vector<ll> elements;

map<ll, ll> partition_1, partition_2;

void initialize(){
	scanf("%lld", &num_elements);
	elements.resize(num_elements);
	for(int i = 0;i < num_elements; i++)scanf("%lld", &elements[i]);
}

void populate_partitions(){
	partition_1.clear(); partition_2.clear();
	// populate partition 2 with all elements
	for(auto it: elements){
		partition_2[it] += 1;
	}
}

void print_partitions(){
	cout << "Partition 1"<< endl;
	for(auto it: partition_1){
		cout << it.first << " : " << it.second << endl;
	}
	cout << "Partition 2"<< endl;
	for(auto it: partition_2){
		cout << it.first << " : " << it.second << endl;
	}
}

void update_partitions(ll incoming_ele){
	partition_1[incoming_ele] += 1;
	partition_2[incoming_ele] -= 1;
	if(partition_2[incoming_ele] == 0)partition_2.erase(incoming_ele);
}

bool can_divide(){

	ll total_sum = 0;
	for(auto it: elements)total_sum += it;

	if(num_elements == 1 || total_sum % 2 == 1)return false;

	// initial setup
	ll sum_1 = 0, sum_2 = total_sum;
	populate_partitions();

	for(int partition_idx = 0; partition_idx < num_elements; partition_idx++){
		ll incoming_ele = elements[partition_idx];
		
		// update counters
		update_partitions(incoming_ele);
		sum_1 += incoming_ele; sum_2 -= incoming_ele;
		
		// print_partitions();
		// cout << "Sums: " << sum_1 << " " << sum_2<< endl;

		if(sum_1 == sum_2)return true;
		
		// check if swapping 1 element can make totals equal
		bool can_swap_and_fix;
		if(sum_1 < sum_2) can_swap_and_fix = (partition_2.find((sum_2 - sum_1)/2) != partition_2.end());
		else can_swap_and_fix = (partition_1.find((sum_1 - sum_2)/2) != partition_1.end());
		if(can_swap_and_fix)return true;
	}


	return false;
}


int main(){
	initialize();
	bool possible = can_divide();
	if(possible)printf("YES\n");
	else printf("NO\n");

}