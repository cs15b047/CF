// D. Tree CF# 353 - 2
// Take node closest to and just higher than current & if left of that node is not there, put it. Else put it at right extreme of that node 
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll> arr(n);for(int i=0;i<n;i++)cin >> arr[i];
	map<ll,ll> l, r, p, l_extreme, r_extreme;
	set<ll> tree_nodes, neg;tree_nodes.insert(arr[0]);neg.insert(-arr[0]);
	l_extreme[arr[0]] = arr[0];r_extreme[arr[0]] = arr[0];
	for(int i=1;i<n;i++){
		auto it1 = tree_nodes.upper_bound(arr[i]);
		auto it2 = neg.upper_bound(-arr[i]);
		
		if(it1 == tree_nodes.end()){
			r[r_extreme[arr[0]]] = arr[i];
			p[arr[i]] = r_extreme[arr[0]];
			r_extreme[arr[0]] = arr[i];
			l_extreme[arr[i]] = arr[i];
			// cout << "End:" << arr[i] << endl;
		}
		else if(it1 == tree_nodes.begin()){
			l[l_extreme[arr[0]]] = arr[i];
			p[arr[i]] = l_extreme[arr[0]];
			l_extreme[arr[0]] = arr[i];
			r_extreme[arr[i]] = arr[i];
			// cout << "Begin:" << arr[i] << endl;
		}
		else{
			// cout << "Middle:" << arr[i] << endl;
			ll node = *it1;
			if(l[node] == 0){
				l[node] = arr[i];
				p[arr[i]] = node;
				l_extreme[node] = arr[i];
				r_extreme[arr[i]] = arr[i];
			}
			else{
				ll left = l[node];
				r[r_extreme[left]] = arr[i];
				p[arr[i]] = r_extreme[left];
				r_extreme[left] = arr[i];
			}
		}
		tree_nodes.insert(arr[i]);
	}
	for(int i=1;i<n;i++)cout << p[arr[i]] <<" "; cout<< endl;

}