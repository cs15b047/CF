#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n;
vector<ll> permutation;

map<ll,ll> incline_info;

vector<pair<ll,ll>> peak_inclines;

void initialize(){
	scanf("%lld", &n);
	permutation.resize(n);
	for(int i = 0;i < n; i++)scanf("%lld", &permutation[i]);
}

// X can only go downward, y can only go upward
// 1. Find all "peaks", so suitable for wins for X. All others cannot be win spots: If "valley"--> can't make next move. If "incline" --> can be blocked by y on downward side
// 2. Find all valleys, which are suitable for y
// 3. If l = highest incline length:
	// a) l is odd: If 2 or more peaks contain incline of length l --> x loses everywhere. Else, l wins at the only peak where there's an incline of length l
	// b) l is even: Always loss for x: y will be valley of longest incline. x same path --> collide and x 1st move, else both complete path and x 1st move

bool cmp_incr_order(ll curr){
	return permutation[curr] > permutation[curr - 1];
}

bool cmp_decr_order(ll curr){
	return permutation[curr] < permutation[curr - 1];
}

pair<ll,ll> get_incline_for_peaks(ll peak_idx){
	ll curr = peak_idx - 1;
	ll len1, len2;

	while(curr >= 0 && cmp_incr_order(curr + 1)){
		curr--;
	}
	len1 = peak_idx - curr;

	curr = peak_idx + 1;
	while(curr < n && cmp_decr_order(curr)){
		curr++;
	}
	len2 = curr - peak_idx;
	
	// update incline lengths for getting longest
	incline_info[len1]++;
	incline_info[len2]++;

	return make_pair(len1, len2);
}




// // order = 0 --> asc, 1 --> desc
// bool cmp(ll curr, bool order){
// 	if(order) return cmp_decr_order(curr);
// 	return cmp_incr_order(curr);
// }

// void compute_inclines(bool order){
// 	ll curr = 1, start = 0;
// 	while(start < n){
// 		curr = start + 1;
// 		while(curr < n && cmp(curr, order)){
// 			curr++;
// 		}
// 		ll len = curr - start;
// 		incline_info[len]++;
// 		cout << "patch with order: " << order << " [" << start << "," << curr - 1 << "] : len: " << len << endl;
// 		start = curr;
// 	}
// }


vector<ll> get_peaks(){
	vector<ll> peaks;
	// no need to add endpoints as peaks, as cannot win there
	for(int i = 0; i < n; i++){
		if(!(i == 0 || i == n - 1)){
			if(permutation[i] > permutation[i - 1] && permutation[i] > permutation[i + 1])peaks.push_back(i);
		} else if(i == 0){
			if(permutation[i] > permutation[i + 1]) peaks.push_back(i);
		} else if (i == n - 1){
			if(permutation[i] > permutation[i - 1]) peaks.push_back(i);
		}
	}
	return peaks;
}

pair<ll,ll> get_peaks_with_incline_len(ll highest_len){
	ll ans1 = 0, ans2 = 0;
	for(auto it: peak_inclines){
		if(it.first == highest_len || it.second == highest_len){
			ans1++;
			ans2 = ans2 + ((it.first == highest_len) && (it.second == highest_len));
		}
	}
	return make_pair(ans1, ans2);
}

void print_arr(vector<ll> arr){
	for(auto it: arr)cout << it << " ";cout << endl;
}

void print_pair(vector<pair<ll,ll>> arr){
	for(auto it: arr)cout << it.first << " " << it.second << endl;
}


ll calc_possible_win_spots(){
	vector<ll> peaks = get_peaks();
	// print_arr(peaks);

	if(peaks.empty())return 0;

	peak_inclines.clear();
	incline_info.clear();
	for(auto it: peaks){
		pair<ll,ll> p = get_incline_for_peaks(it);
		if(it != 0 && it != n - 1){
			// cout << it << "!" << endl;
			peak_inclines.push_back(p);
		}
	}
	// print_pair(peak_inclines);
	
	ll answer = 0;

	ll highest_len = incline_info.rbegin()->first, inclines_with_highest_len = incline_info.rbegin()->second;
	if(highest_len % 2 == 0)return 0;
	if(inclines_with_highest_len > 2)return 0;

	pair<ll,ll> peaks_with_highest_inclines = get_peaks_with_incline_len(highest_len);
	if(peaks_with_highest_inclines.first == 1 && peaks_with_highest_inclines.second == 1)return 1;
	else return 0;
}


int main() {
	initialize();
	ll win_spots = calc_possible_win_spots();
	printf("%lld\n", win_spots);
	return 0;
}