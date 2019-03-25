// A. Cows and Sequence #174 - 1
// Handle append and remove by vector
// For prefix addition, keep track of sum of such additions only for end number , which will propagate back on removal
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n;cin >> n;
	ll added_ele, position;
	vector<ll> inserted_data;inserted_data.clear();
	inserted_data.push_back(0);
	map<ll,ll> end_pos_to_added_value ; end_pos_to_added_value.clear();
	double total = 0;

	for(int i=0;i<n;i++){
		int op;scanf("%d",&op);
		if(op == 1){
			scanf("%lld%lld",&position,&added_ele);
			end_pos_to_added_value[position-1] += added_ele ; // vulnerable to old values
			total += (double)(added_ele*position) ;
		}
		else if(op == 2){
			ll new_ele;scanf("%lld",&new_ele);
			inserted_data.push_back(new_ele);
			end_pos_to_added_value[inserted_data.size()-1] = 0;
			total += (double)new_ele ;
		}
		else if(op == 3){
			double to_be_subd = (double)(inserted_data.back() + end_pos_to_added_value[ (inserted_data.size()-1) ]);
			// cout << inserted_data.back() << endl;
			// cout << "Subd:"<<to_be_subd << endl;
			total = total -  to_be_subd;
			end_pos_to_added_value[(inserted_data.size()-2)] += end_pos_to_added_value[ (inserted_data.size()-1) ] ;
			end_pos_to_added_value[inserted_data.size()-1] = 0;
			inserted_data.pop_back();
		}
		printf("%.6lf\n",total/(double)(inserted_data.size()) );
		// for(auto it:inserted_data)cout << it << " "; cout << endl;
		// for(auto it:end_pos_to_added_value)cout << it.first << " " << it.second << " "; cout << endl;
	}
}