#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<double>> probability;
double p;
ll n, t;

double recurse(ll T, ll num_people){
	// cout << T << " " << num_people << " " << probability[T][num_people] << endl;
	if(probability[T][num_people] != -1)return probability[T][num_people];
	if(T < num_people){
		probability[T][num_people] = 0;
		return 0;
	}
	if(num_people == 0){
		probability[T - 1][num_people] = recurse(T - 1, num_people);
		probability[T][num_people] = probability[T - 1][num_people] * (1 - p);
		return probability[T][num_people];
	} 
	probability[T][num_people] = recurse(T - 1, num_people - 1) * p;
	double part2 = recurse(T - 1, num_people);
	if(num_people < n){
		part2 = part2 * (1 - p);
	}
	probability[T][num_people] += part2;
	return probability[T][num_people];
}

int main(){
	cin >> n >> p >> t;
	probability.resize(t + 1, vector<double>(n + 1, -1));
	probability[0][0] = 1;
	for(int i = 1;i <= min(t, n);i++){
		probability[i][i] = probability[i - 1][i - 1] * p;
	}
	for(int i = 0;i <=t;i++ ){
		for(int j = i + 1;j <= n;j++){
			probability[i][j] = 0;
		}
	}
	double answer;
	for(int i = 0;i <= n;i++){
		recurse(t, i);
	}
	for(int i = 0;i <= n;i++){
		answer += probability[t][i] * (double)i;
	}
	printf("%.6lf\n", answer);
}