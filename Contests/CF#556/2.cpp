#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<string> grid(n);for(int i=0;i<n;i++)cin >> grid[i];
	ll remn = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j] == '.')remn++;
		}
	}
	if(remn % 5 != 0)cout << "NO" << endl;
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j] == '.' && i >= 1 && i < n - 1 && j >= 1 && j < n - 1 && grid[i-1][j] == '.' && grid[i+1][j] == '.'&& grid[i][j-1] == '.'&& grid[i][j+1] == '.' ){
					grid[i][j] = '#';grid[i-1][j] = '#';grid[i+1][j] = '#';grid[i][j-1] = '#';grid[i][j +1] = '#';
					remn = remn - 5;
				}
			}
		}
		if(remn == 0){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}