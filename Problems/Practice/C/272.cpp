#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_days, ban_days, threshold;
vector<ll> below_threshold, above_threshold;

void initialize(){
	scanf("%lld%lld%lld",&num_days, &ban_days, &threshold);
	below_threshold.clear(); above_threshold.clear();
	for(int i = 0;i < num_days;i++){
		ll fun_factor; scanf("%lld", &fun_factor);
		if(fun_factor > threshold)above_threshold.push_back(fun_factor);
		else below_threshold.push_back(fun_factor);
	}
}

void print(deque<ll> dq){
	cout << "Working set: "<< endl;
	while(!dq.empty()){
		cout << dq.front() << " ";
		dq.pop_front();
	}
	cout << endl;
}
void print_stk(stack<ll> stk){
	while(!stk.empty()){
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << endl;
}


ll calc_max_fun(){
	sort(below_threshold.begin(), below_threshold.end(), greater<ll>());
	sort(above_threshold.begin(), above_threshold.end(), greater<ll>());

	deque<ll> working_set(below_threshold.begin(), below_threshold.end());

	// print(working_set);

	ll virtual_limit = num_days +  ban_days, curr_virtual_size = below_threshold.size();
	
	// set baseline answer and working copy
	ll answer = 0, curr_value = 0;
	for(auto it: below_threshold)curr_value += it;
	answer = curr_value;

	// iterate through above threshold ones in desc order and add into working set and remove appropriate number of elements till it is not profitable to do so
	ll ptr = 0, max_size = above_threshold.size();
	while(ptr < max_size){
		ll insert_value = above_threshold[ptr];
		
		// cout << "Ptr: " << ptr << " Inserted value: " << insert_value << " Current virtual size: " << curr_virtual_size << endl;
		// print(working_set);

		// evaluate total value of to be removed values
		ll next_virtual_size = curr_virtual_size + ban_days + 1;
		stack<ll> stk;
		ll removed_val = 0, itrs = next_virtual_size - virtual_limit;
		for(int i = 0;i < itrs && !working_set.empty();i++){
			removed_val += working_set.back();
			// stk.push(working_set.back());
			working_set.pop_back();
			next_virtual_size--;
		}
		
		// cout << "REmoved elements: " << endl;
		// print_stk(stk);
		// cout << "Removed value: " << removed_val << " Virtual size: " << next_virtual_size << endl;

		

		// if greater value to be inserted--> insert. else--> terminate as further ones will insert lesser value and remove same value
		if(insert_value > removed_val){
			// push front will disturb the order, but order won't matter in that side as we won't need to dequeue enqueued elements.
			working_set.push_front(insert_value);
			curr_value += (insert_value - removed_val);
			curr_virtual_size = next_virtual_size;
		} else{
			break;
		}

		// next ele
		ptr++;
	}
	working_set.clear();
	below_threshold.clear();
	above_threshold.clear();

	return curr_value;
}

int main(){
	initialize();
	ll ans = calc_max_fun();
	printf("%lld\n", ans);
}