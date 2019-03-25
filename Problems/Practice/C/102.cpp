//C. Alyona and Spreadsheet --> #401 - 2
// 1.Calculate non-decr intervals in each column, and for each row in a particular col, calc rightmost point of non-decr segment to which it belongs1
// 2. Take max of this rightmost point across columns for a row , and for query if r > ans(l) ---> no, else --> yes
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n,m; cin >> n >> m;
	vector<vector<ll>> grid(n),mygrid(n);
	for(int i=0;i<n;i++){
		grid[i].resize(m);
		for(int j=0;j<m;j++){
			scanf("%lld",&grid[i][j]);
		}
	}
	vector<vector<pair<ll,ll>>> intervals(m);
	for(int j =0;j<m;j++){
		int strt = 0;
		while(strt < n){
			int end = strt;
			while(end < n - 1 && grid[end][j] <= grid[end + 1][j])end++;
			intervals[j].push_back(make_pair(strt, end));
			strt = end + 1;
		}
	}
	
	for(int i=0;i<n;i++)mygrid[i].resize(m);
	
	for(int j=0;j<m;j++){
		int row = 0;
		for(auto it:intervals[j]){
			while(row <= it.second){mygrid[row][j] = it.second;row++;}
		}
	}
	vector<ll> myvec(n);
	for(int i=0;i<n;i++){
		myvec[i] = i;
		for(int j=0;j<m;j++){
			myvec[i] = max(myvec[i],mygrid[i][j]);
		}
	}

	// for(auto row: mygrid){
	// 	for(auto ele:row){
	// 		cout << ele << " ";
	// 	}
	// 	cout << endl;
	// }
	// for(auto ele: myvec)cout << ele << " ";
	// cout << endl;


	ll k; cin >> k;
	for(int q =0;q<k;q++){
		ll left, right;scanf("%lld%lld",&left,&right);
		left--;right--;
		if(myvec[left] >= right)printf("Yes\n");
		else printf("No\n");
	}
}