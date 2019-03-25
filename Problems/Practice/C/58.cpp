#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;
int main(){
	ll n;cin>>n;
	vector<string> grid(n);
	for(int i=0;i<n;i++)cin>>grid[i];

	vector<int>row(n),col(n);
	int r = 0,c=0;
	for(int i=0;i<n;i++){
		int j=0;
		for(;j<n;j++){
			if(grid[i][j] == '.'){row[i] = j;break;}
		}
		if(j == n){r = -1;break;}
	}
	for(int j=0;j<n;j++){
		int i=0;
		for(;i<n;i++){
			if(grid[i][j] == '.'){col[j] = i;break;}
		}
		if(i == n){c = -1;break;}
	}
	if(r == -1 && c == -1)cout << -1 << endl;
	else if(r != -1){
		for(int i=0;i<n;i++){
			cout << i + 1 << " " << row[i] + 1<< endl ;
		}
	}
	else if(c != -1){
		for(int j=0;j<n;j++){
			cout << col[j] + 1 << " " << j + 1 << endl ;
		}
	}

}