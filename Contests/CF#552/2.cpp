#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

ll mat[501][501]={};
int main(){
	ll n,m; cin >> n >>m;
	vector<set<ll>> num(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> mat[i][j];
			num[i].insert(mat[i][j]);
		}
	}
	vector<ll> ans(n);
	int row = -1;
	int flag = 0;
	ll answer = 0;
	for(int i=0;i<n;i++){
		if(num[i].size() > 1){flag = 1;row=i;}
		ans[i] = *(num[i].begin());
		answer = answer ^ ans[i];
	}
	if(answer != 0 || flag == 1){
		cout << "TAK" <<endl;
		if(answer == 0){ans[row] = *(num[row].rbegin());answer = *(num[row].rbegin()) ^ *(num[row].begin());}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(mat[i][j] == ans[i]){cout << j + 1 << " ";break;}
			}
		}
		cout << endl;
	}
	else cout <<"NIE" << endl;
}