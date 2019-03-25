// C. Okabe and Boxes #420 --> 2
// Keep sorted ones separate and unsorted in stack.To reorder, put merge unord and ord ones. Pick first from unsorted, and if empty, from sorted
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n ;
	set<ll> sorted;
	vector<ll> unsorted;
	ll curr_to_remove=1,reorders=0;
	for(int i=0;i<2*n;i++){
		char str[20];scanf("%s",str);string cmd(str);
		if(cmd == "add"){
			ll ele;cin >> ele ;
			unsorted.push_back(ele);
		}
		else{
			if(!unsorted.empty() && unsorted.back() == curr_to_remove){
				unsorted.pop_back();
				curr_to_remove++;
			}
			else if(!unsorted.empty() && unsorted.back() != curr_to_remove){
				reorders++;
				for(auto it:unsorted)sorted.insert(it);
				unsorted.clear();
				sorted.erase(curr_to_remove);
				curr_to_remove++;
			}
			else if(unsorted.empty()){
				sorted.erase(curr_to_remove);
				curr_to_remove++;	
			}
		}
	}
	cout << reorders << endl ;
}