#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll p1,p2,p3,p4;
	cout << "? 1 2" << endl;fflush(stdout);
	cin >> p1;
	cout << "? 2 3" << endl;fflush(stdout);
	cin >> p2;
	cout << "? 4 5" << endl;fflush(stdout);
	cin >> p3;
	cout << "? 5 6" << endl;fflush(stdout);
	cin >> p4;
	
	vector<ll> numb;numb.push_back(0);numb.push_back(4);numb.push_back(8);numb.push_back(15);numb.push_back(16);numb.push_back(23);numb.push_back(42);
	vector<set<ll>> vec(7);
	for(int i=1;i<=6;i++)
		for(int j=1;j<=6;j++)
			if(j != i)vec[i].insert(numb[i]*numb[j]);

	vector<ll> prod;prod.push_back( p1);prod.push_back( p2);prod.push_back( p3);prod.push_back( p4);
	vector<ll> ans(7, 0);
	for(int i=0;i<2;i++){
		ll pr1 = prod[2*i], pr2 = prod[2*i + 1];
		set<ll> idx1, idx2;idx1.clear();idx2.clear();
		for(int i=1;i<=6;i++){
			if(vec[i].find(pr1) != vec[i].end())idx1.insert(i);
			if(vec[i].find(pr2) != vec[i].end())idx2.insert(i);
		}
		// for(auto it:idx1)cout << it << " ";cout << endl;
		// for(auto it:idx2)cout << it << " ";cout << endl;
		if(idx2.find(*idx1.begin()) != idx2.end()){
			ll num2 = numb[*idx1.begin()];
			ans[3*i + 2] = num2;
			ans[3*i + 1] = pr1/num2;
			ans[3*i + 3	] = pr2/num2;
		}
		else{
			ll num2 = numb[*idx1.rbegin()];
			ans[3*i + 2] = num2;
			ans[3*i + 1] = pr1/num2;
			ans[3*i + 3	] = pr2/num2;
		}
	}
	cout << "! ";
	for(int i=1;i<=6;i++)cout << ans[i] << " ";cout << endl;fflush(stdout);
}
