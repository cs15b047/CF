#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

vector<ll> arr, ST;
vector<pair<ll,ll>> ranges_ST;

ll construct(ll idx, ll left, ll right){
	if(left == right){
		ST[idx] = arr[left];
		ranges_ST[idx] = make_pair(left, right);
		return arr[left];
	}
	else{
		ll mid = (left + right)/ 2;
		ll left_val = construct(2 * idx + 1, left, mid);
		ll right_val = construct(2 * idx + 2, mid + 1, right);
		ST[idx] = left_val + right_val;
		ranges_ST[idx] = make_pair(ranges_ST[2*idx + 1].first, ranges_ST[2*idx + 2].second);
		return ST[idx];
	}
	return -1e18;
}

ll process_query(ll curr_node, ll query_left, ll query_right){
	if(ranges_ST[curr_node].first >= query_left && ranges_ST[curr_node].second <= query_right)return ST[curr_node];
	else if(ranges_ST[curr_node].first > query_right || ranges_ST[curr_node].second < query_left)return 0;
	else{
		ll left_val = process_query(2* curr_node + 1, query_left, ranges_ST[2*curr_node + 1].second);
		ll right_val = process_query(2* curr_node + 2, ranges_ST[2*curr_node + 2].first, query_right);
		return left_val + right_val;
	}
}

void update(ll node_to_update, ll curr_node, ll updated_value){
	if(ranges_ST[curr_node].first > node_to_update || ranges_ST[curr_node].second < node_to_update)return;
	if(node_to_update == ranges_ST[curr_node].first && node_to_update == ranges_ST[curr_node].second){ST[curr_node] = updated_value;return;}
	update(node_to_update, 2*curr_node + 1, updated_value);
	update(node_to_update, 2*curr_node + 2, updated_value);
	ST[curr_node] = ST[2*curr_node + 1] + ST[2*curr_node + 2];
	return;
}


int main(){
	ll n; cin >> n;arr.resize(n);for(int i=0;i<n;i++)cin >> arr[i];
	ST.resize(2*pow(2, ceil(log2((double)n))) - 1);ranges_ST.resize(ST.size());

	ll root_val = construct(0, 0, n - 1);
	cout << root_val << endl;
	ll sz = ST.size();
	for(int i=0;i<sz;i++)cout << ST[i] <<" ";cout << endl;
	for(int i=0;i<sz;i++)cout << ranges_ST[i].first << " " << ranges_ST[i].second << endl;
	for(int i=0;i<n;i++){
		update(i, 0, i +3);
	}
	for(int i=0;i<sz;i++)cout << ST[i] <<" ";cout << endl;
	for(int i=0;i< n -2 ;i++){
		cout << process_query(0, i, i + 2) << " ";
	}
	cout << endl;
	for(int i=0;i<sz;i++)cout << ST[i] <<" ";cout << endl;
}