#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

typedef long long int ll;
vector<ll> arr;

// class cmp{
// public:
// 	bool operator()(ll idx1, ll idx2){
// 		if(arr[idx1] > arr[idx2])return true;
// 		else if(arr[idx1] == arr[idx2])return idx1 < idx2;
// 		return false;
// 	}
// };

bool cmpr(ll idx1, ll idx2){
	if(arr[idx1] > arr[idx2])return true;
	else if(arr[idx1] == arr[idx2])return idx1 < idx2;
	return false;
}

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll num_ele; cin >> num_ele;
    arr.resize(num_ele);for(int i = 0;i < num_ele;i++)cin >> arr[i];
    ll num_requests; cin >> num_requests;
    vector<vector<ll>> queries(num_ele + 1);
    vector<pair<ll,ll>> query_vec;
    for(int i = 0;i < num_requests;i++){
    	ll k, pos; cin >> k >> pos;
    	queries[k].push_back(pos);
    	query_vec.push_back(make_pair(k, pos));
    }
    vector<ll> idxs(num_ele);for(int i = 0;i < num_ele;i++)idxs[i] = i;
    sort(idxs.begin(), idxs.end(), cmpr);

    // for(auto it:idxs)cout << it << " ";cout << endl;

    ordered_set ord_set;

    int ptr = 0;

    map<pair<ll,ll>, ll> query_to_ans;
    for(int i = 1;i <= num_ele;i++){
    	if(!queries[i].empty()){
    		while(ptr < i){
    			ord_set.insert(idxs[ptr]);
    			ptr++;
    		}
    		// for(auto it: ord_set)cout << it << " "; cout << endl; 

    		for(auto pos: queries[i]){
    			query_to_ans[make_pair(i, pos)] = arr[*(ord_set.find_by_order(pos - 1))];
    		}
    	}
    }
    for(int i = 0;i < num_requests;i++){
    	cout << query_to_ans[query_vec[i]] << endl;
    }
}