#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_planks;
vector<ll> heights;

vector<vector<ll>> dp;

//########### My solution: Wrong somehow... Don't know why##############
void initialize(){
	scanf("%lld", &num_planks);
	heights.resize(num_planks + 1, 0);
	dp.resize(num_planks + 1, vector<ll>(2, 0));
	for(int i = 1;i <= num_planks; i++){
		scanf("%lld", &heights[i]);
	}
}

void calc_vertical_stroke_case(ll idx){
	dp[idx][0] = 1 + min(dp[idx - 1][0], dp[idx - 1][1]);
}

void calc_horizontal_stroke_case(ll idx){
	ll horiz_ht_painted = heights[idx - 1];
	ll pillars_with_min_ht = 0;
	dp[idx][1] = 2e9;

	// cout << "Inner Loop: " << endl;
	// j is rightmost index to left of idx such that it is painted horizontally entirely
	for(ll j = idx - 1; j >= 1; j--){
		ll new_min = min(horiz_ht_painted, heights[j]);
		if(horiz_ht_painted == new_min)pillars_with_min_ht++;
		else pillars_with_min_ht = 1;
		horiz_ht_painted = new_min;
		// cost till j (with j in horiz) + Paint [i - 1 to j + 1] vertically + Paint remaining pole of idx horizontally
		ll calc_answer = dp[j][1] + (idx - 1 - j) - (pillars_with_min_ht - 1) + max((ll)0, heights[idx] - horiz_ht_painted);
		dp[idx][1] = min(dp[idx][1], calc_answer);
		// cout << "J: " << j << ", Horizontal ht painted: " << horiz_ht_painted << ", Ans(iteration):" << calc_answer << ", Ans: " << dp[idx][1] << endl;
	}
	// cout << endl;
}


ll calc_min_strokes(){
	// init answer array
	dp[1][0] = 1; dp[1][1] = heights[1];

	for(ll i = 2;i <= num_planks; i++){
		calc_vertical_stroke_case(i);
		calc_horizontal_stroke_case(i);
		// cout << "Idx: " << i << ", Vertical: " << dp[i][0] << ", Horizontal: " << dp[i][1] << endl;
	}

	return min(dp[num_planks][0], dp[num_planks][1]);
}
///#################################################################################################
// Tutorial solution idea

void print_parts(vector<pair<ll,ll>> partitions){
	cout <<  "Partitions:" << endl;
	for(auto it: partitions)cout << "[ " << it.first << " " << it.second << "]" << endl;
}


ll get_min_ht(ll left, ll right){
	ll min_ht = heights[left];
	for(int i = left; i <= right; i++)
		min_ht = min(min_ht, heights[i]);
	return min_ht;
}

vector<pair<ll,ll>> get_partitions(ll left, ll right, ll ht){
	vector<pair<ll,ll>> partitions; partitions.clear();

	ll strt = left, curr = left;
	while(strt <= right){
		while(strt <= right && heights[strt] == ht)strt++;
		curr = strt;
		while(curr <= right && heights[curr] > ht)curr++;
		if(strt <= right)partitions.push_back(make_pair(strt, curr - 1));
		strt = curr;
	}

	return partitions;
}


ll calc_min_strokes(ll left, ll right, ll already_painted_ht){
	//option 1: get min ht and paint horizontally --> divides into several portions: sum them up
	//option 2: all vertical painted
	// cout << "SubProblem: [" << left << ", " << right << ", " << already_painted_ht << " ]" << endl;

	// Only 1 plank: vertical paint
	if(left == right){
		// cout << "Only 1 plank" << endl;
		return 1;
	}

	// get min ht
	ll min_ht = get_min_ht(left, right);
	ll horiz_stroke_ht = min_ht - already_painted_ht;
	ll horizontal_option_ans = horiz_stroke_ht;
	// cout << "Min ht:  " << min_ht << ", stroke ht: " << horiz_stroke_ht << endl;
	
	// get partitions
	vector<pair<ll,ll>> partitions = get_partitions(left, right, min_ht);
	// print_parts(partitions);
	for(auto it: partitions){
		horizontal_option_ans += calc_min_strokes(it.first, it.second, min_ht);
	}

	ll vertical_option_ans = (right - left + 1);
	ll answer = min(horizontal_option_ans, vertical_option_ans);

	// cout << "Horiz option answer: " << horizontal_option_ans << " Vertical answer: " << vertical_option_ans << endl;

	return answer;
}






int main(){
	initialize();
	ll answer = calc_min_strokes(1, num_planks, 0);
	printf("%lld\n", answer);
}