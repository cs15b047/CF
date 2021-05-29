#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_apps, memory_to_be_freed, tests;
vector<ll> app_memories, ratings;

vector<ll> memories_with_one_rating, memories_with_two_rating;

void print(vector<ll>& arr){
	if(arr.empty())cout << "Empty array" << endl;
	for(auto it: arr)cout << it << " ";
	cout << endl;
}


void initialize(){
	scanf("%lld%lld",&num_apps, &memory_to_be_freed);
	app_memories.clear();app_memories.resize(num_apps);
	ratings.clear();ratings.resize(num_apps);
	memories_with_one_rating.clear();
	memories_with_two_rating.clear();
	
	for(int i = 0;i < num_apps; i++)scanf("%lld", &app_memories[i]);
	for(int i = 0;i < num_apps; i++)scanf("%lld", &ratings[i]);
	for(int i = 0;i < num_apps; i++){
		ll rating = ratings[i], mem = app_memories[i];
		if(rating == 1)memories_with_one_rating.push_back(mem);
		else memories_with_two_rating.push_back(mem);
	}
}

bool is_possible(){
	ll mem_sum = 0;
	for(auto it: memories_with_one_rating) mem_sum += it;
	for(auto it: memories_with_two_rating) mem_sum += it;
	return (mem_sum >= memory_to_be_freed);
}

ll calc_min_rating_loss(){
	if(!is_possible())return -1;
	sort(memories_with_one_rating.begin(), memories_with_one_rating.end(), greater<ll>());
	sort(memories_with_two_rating.begin(), memories_with_two_rating.end(), greater<ll>());

	ll ptr1 = 0, ptr2 = 0, size1 = memories_with_one_rating.size(), size2 = memories_with_two_rating.size();

	ll memory_freed = 0, value_lost = 0;

	// till both are not exhausted
	while(ptr1 < size1 || ptr2 < size2){
		// only 1 array left
		// first is over
		if(ptr1 == size1){
			memory_freed += memories_with_two_rating[ptr2];
			value_lost += 2;
			ptr2++;
		}

		// second is over
		else if(ptr2 == size2){
			memory_freed += memories_with_one_rating[ptr1];
			value_lost += 1;
			ptr1++;
		}

		// both have some elements

		// first one satisfies req
		else if((ptr1 < size1) && (memory_freed + memories_with_one_rating[ptr1] >= memory_to_be_freed)) return value_lost + 1;
		
		// 2 remaining in arr with mem 1
		else if(ptr1 + 1 < size1){
			// compare 1 of 2 value and 2 of value 1
			if(memories_with_one_rating[ptr1] + memories_with_one_rating[ptr1 + 1] >= memories_with_two_rating[ptr2]){
				memory_freed += (memories_with_one_rating[ptr1]);
				ptr1 += 1; // Take 1 steps instead of 2 !!
				value_lost += 1;
			} else{
				memory_freed += memories_with_two_rating[ptr2];
				ptr2 += 1;
				value_lost += 2;
			}
		}

		// 1 left in 1 arr and it's not adequate --> take from 2
		else{
			memory_freed += memories_with_two_rating[ptr2];
			ptr2 += 1;
			value_lost += 2;
		}
		if(memory_freed >= memory_to_be_freed)return value_lost;
	}


	return 1;
}


int main(){
	scanf("%lld", &tests);
	for(int i = 0;i < tests; i++){
		initialize();
		ll ans = calc_min_rating_loss();
		printf("%lld\n", ans);
	}

}