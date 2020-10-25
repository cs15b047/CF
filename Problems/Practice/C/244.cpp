#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, l, x, y; cin >> n >> l >> x >> y;
	set<ll> marks;for(int i =0;i < n;i++){ll mrk;cin >> mrk; marks.insert(mrk);}

	bool present1 = false, present2 = false, present_diff = false;
	ll diff_strt;
	for(auto mrk : marks){
		if(marks.find(mrk + x) != marks.end()){
			present1 = true;
		}
		if(marks.find(mrk + y) != marks.end()){
			present2 = true;
		}
	}
	ll cnt = -1;
	vector<ll> answers;answers.clear();
	if(present1 && present2){
		cnt = 0;
	} else{
		if(present1 && !present2){
			cnt = 1;
			answers.push_back(y);
		} else if(!present1 && present2){
			cnt = 1;
			answers.push_back(x);
		} else{
			for(auto mrk: marks){
				bool cond1 = ((mrk - x >= 0) && (marks.find(mrk - x - y) != marks.end() || marks.find(mrk - x + y) != marks.end()));
				bool cond2 = ((mrk + x <= l) && (marks.find(mrk + x - y) != marks.end() || marks.find(mrk + x + y) != marks.end()));
				bool cond3 = ((mrk - y >= 0) && (marks.find(mrk - y - x) != marks.end() || marks.find(mrk - y + x) != marks.end()));
				bool cond4 = ((mrk + y <= l) && (marks.find(mrk + y - x) != marks.end() || marks.find(mrk + y + x) != marks.end()));
				if(cond1 || cond2 || cond3 || cond4){
					cnt = 1;
					if(cond1)answers.push_back(mrk - x);
					else if(cond2)answers.push_back(mrk + x);
					else if(cond3)answers.push_back(mrk - y);
					else if(cond4)answers.push_back(mrk + y);
					break;
				}
			}
			if(cnt == -1){
				cnt = 2;
				answers.push_back(x);
				answers.push_back(y);
			}
		}
	}
	cout << cnt << endl;
	for(auto it:answers)cout << it << " ";cout << endl;
}