#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll data_size;
vector<ll> numbers;

vector<vector<int>> bit_reprs;
vector<bool> same_bit_for_all;


void initialize(){
	scanf("%lld", &data_size);
	numbers.resize(data_size);
	same_bit_for_all.resize(31);
	bit_reprs.resize(data_size, vector<int>(31, 0));
	for(int i = 0;i < data_size; i++) scanf("%lld", &numbers[i]);
}

vector<int> convert_to_bit_repr(ll number){
	vector<int> repr(31, 0);
	for(int i = 0;i < 31 && number > 0;i++){
		repr[i] = number % 2 ;
		number = number / 2;
	}
	return repr;
}

void print_bit_repr(ll num){
	vector<int> repr = convert_to_bit_repr(num);
	for(auto it: repr){
		cout << it;
	}
	cout << endl;
}

void populate_bit_reprs(){
	for(int i = 0;i < data_size; i++){
		bit_reprs[i] = convert_to_bit_repr(numbers[i]);
		// print_bit_repr(numbers[i]);
	}
}

void print_state(vector<int>& idxs, int pos){
	cout << "State:" <<endl;
	cout << "Elements: ";
	for(auto it: idxs)cout << numbers[it] << " ";
	cout << endl;
	cout << "Bit position: " << pos << endl;
	cout << endl;
}

bool calc_all_same_bits_positions(vector<int>& idxs, int position){
	// same if only one
	if(idxs.size() == 1)return true;
	// all bits should match bit of first data point
	int bit = bit_reprs[idxs[0]][position];
	ll sz = idxs.size();
	for(auto it: idxs){
		if(bit != bit_reprs[it][position]){
			return false;
		}
	}
	return true;
}


void preprocess(){
	populate_bit_reprs();
}

ll calc_answers(vector<int> idxs, int bit_position){

	// print_state(idxs, bit_position);

	// only 1 element present --> ans = 0
	if(idxs.size() == 1)return 0;

	// if bit_position = 0 --> check if all same --> yes: 0, no: 1
	bool all_same = calc_all_same_bits_positions(idxs, bit_position);
	
	// if(all_same) return 0; else return 1;
	if(bit_position == 0) return !all_same;

	// all concerned numbers(corresponding to idxs) have same bit at bit_position
	if(all_same) return calc_answers(idxs, bit_position - 1);

	// separate out numbers with 0 or 1 at bit_position
	// calc answers separately for bit_position - 1 separately, take min and add 2^bit_position
	vector<int> idxs_0, idxs_1; idxs_0.clear();	idxs_1.clear();

	// populate with 0 and 1 for bit_position
	for(auto it: idxs){
		if(bit_reprs[it][bit_position] == 0)idxs_0.push_back(it);
		else idxs_1.push_back(it);
	}

	// recursive calls
	ll part1 = calc_answers(idxs_0, bit_position - 1);
	ll part2 = calc_answers(idxs_1, bit_position - 1);
	// join answers
	ll answer = min(part1, part2) + pow(2, bit_position);

	return answer;
}


int main(){
	initialize();
	preprocess();
	vector<int> idxs(data_size);
	for(int i = 0;i < data_size;i++)idxs[i] = i;

	ll ans = calc_answers(idxs, 30);
	printf("%lld\n", ans);
}