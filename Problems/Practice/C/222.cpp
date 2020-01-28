#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<ll,ll>> sorted_segs, unsorted_segs;
ll len, num_segments;
vector<ll> answer, diff;
bool possible;

void take_input(){
	cin >> len >> num_segments;
	
	for(int i = 1;i <= num_segments;i++){
		ll sort_flag, left, right; cin >> sort_flag >> left >> right;
		pair<ll,ll> seg = make_pair(left,right);
		if(sort_flag == 1)sorted_segs.push_back(seg);
		else unsorted_segs.push_back(seg);
	}
	//  imp if 2+ segs present inside an unsorted seg
	sort(sorted_segs.begin(), sorted_segs.end());

	diff.resize(len + 1, -1);
	answer.resize(len + 1, 0);
}

void process_sorted_segs(){
	for(int i = 0;i < (ll)sorted_segs.size();i++){
		ll strt = sorted_segs[i].first, end = sorted_segs[i].second;
		for(int i = strt;i < end;i++)
			diff[i] = 0;
	}
}

bool process_unsorted_segs(){
	possible = true;
	for(int i = 0;i < (ll)unsorted_segs.size();i++){
		ll strt = unsorted_segs[i].first, end = unsorted_segs[i].second;
		bool unsorted = false;
		for(int j = strt; j <= end - 1; j++){
			if(answer[j] > answer[j + 1])unsorted = true;
		}
		if(!unsorted)return false;
	}
	return true;
}

void calc_ans(){
	process_sorted_segs();
	answer[1] = len;
	for(int j = 2;j <= len;j++){
		answer[j] = answer[j - 1] + diff[j - 1];
	}
}

int main(){
	take_input();
	calc_ans();
	possible = process_unsorted_segs();

	if(!possible)cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for(int i = 1;i <= len; i++){
			cout << answer[i] << " ";
		}
		cout << endl;
	}
}