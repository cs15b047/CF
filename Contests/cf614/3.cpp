#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, q; cin >> n >> q;
	set<pair<ll,ll>> blocks;
	vector<map<ll,set<ll>>> maps(3);
	maps[1].clear();maps[2].clear();

	for(int i = 0;i < q; i++){
		ll row, col; cin >> row >> col;
		pair<ll,ll> blk = make_pair(row,col);
		if(blocks.find(blk) == blocks.end()){
			blocks.insert(blk);
			if(blocks.find(make_pair(3 - row, col)) != blocks.end()){
				maps[row][col].insert(col);
				maps[3 - row][col].insert(col);
			}
			if(blocks.find(make_pair(3 - row, col - 1)) != blocks.end()){
				maps[row][col].insert(col - 1);
				maps[3 - row][col - 1].insert(col);
			}
			if(blocks.find(make_pair(3 - row, col + 1)) != blocks.end()){
				maps[row][col].insert(col + 1);
				maps[3 - row][col + 1].insert(col);
			}
		} else{
			blocks.erase(blk);
			if(blocks.find(make_pair(3 - row, col)) != blocks.end()){
				maps[row][col].erase(col);
				maps[3 - row][col].erase(col);
				if(maps[3 - row][col].empty())maps[3 - row].erase(col);
			}
			if(blocks.find(make_pair(3 - row, col - 1)) != blocks.end()){
				maps[row][col].erase(col - 1);
				maps[3 - row][col - 1].erase(col);
				if(maps[3 - row][col - 1].empty())maps[3 - row].erase(col - 1);
			}
			if(blocks.find(make_pair(3 - row, col + 1)) != blocks.end()){
				maps[row][col].erase(col + 1);
				maps[3 - row][col + 1].erase(col);
				if(maps[3 - row][col + 1].empty())maps[3 - row].erase(col + 1);
			}
			if(maps[row][col].empty())maps[row].erase(col);
		}
		// for(auto it:maps[1]){
		// 	cout << it.first << " :";
		// 	for(auto it2:it.second)cout<<it2 << " ";cout << endl;
		// }
		// for(auto it:maps[2]){
		// 	cout << it.first << " :";
		// 	for(auto it2:it.second)cout<<it2 << " ";cout << endl;
		// }
		if(maps[1].empty() || maps[2].empty()){
			cout << "Yes" << endl;
		} else{
			cout << "No" << endl;
		}
	}

}