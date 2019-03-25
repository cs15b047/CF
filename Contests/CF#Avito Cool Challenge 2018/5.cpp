#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> get_factors(map<ll,ll> prime_factorzn){
	ll total = 1;
	vector<ll>powers,primes,answer;
	for(auto it:prime_factorzn){total *=(it.second+1);powers.push_back(it.second+1);primes.push_back(it.first);}
	// for(auto it:primes)cout << it << " ";cout << endl;
	// for(auto it:powers)cout << it << " ";cout << endl;
	for(int i=0;i<total;i++){
		ll factor = 1,tmp_i=i;
		for(int j=0;j<powers.size();j++){
			factor *= pow(primes[j], tmp_i % powers[j]);
			tmp_i = tmp_i / powers[j];

		}
		answer.push_back(factor);
	}
	return answer;
}

int main(){
	ll n; cin >> n;
	vector<ll>a(n+1);
	for(int i=1;i<=n/2;i++){
		scanf("%lld",&a[2*i]);
	}

	bool not_prime[200001]={};
	int spf[200001];	
	vector< map<ll, ll> > factors(200001);

	for(ll i = 2;i<=200000;i++){
		if(!not_prime[i]){
			spf[i] = i;
			for(ll j = i*i;j <= 200000;j+=i){
				if(!not_prime[j]){
					spf[j] = i;
					not_prime[j] = 1;
				}
			}
		}
	}
	for(int i=1;i<=n/2;i++){
		ll tmp = a[2*i];
		while(tmp != 1){
			ll factor = spf[tmp],pwr = 0;
			while(tmp != 1 && tmp % factor == 0){
				tmp = tmp / factor;
				pwr++;
			}
			factors[a[2*i]][factor] = pwr ;
		}
	}
	// cout << "yolo" << endl ;
	vector<vector<ll>>divisors(n+1);
	for(int i=1;i<=n/2;i++){
		divisors[2*i] = get_factors(factors[a[2*i]]);
		// for(auto it:divisors[2*i])cout << it << " ";cout << endl ;
	}
	int no = 0;
	vector<ll> numbers(n+1);
	for(int i=1;i<=n/2;i++){
		vector<ll> vec = divisors[2*i];int sz = (int)vec.size();
		numbers[2*i - 1] = -1;
		ll a_t=1e18,a_v = 1e18;
		for(int j =0;j < sz;j++){
			ll num1 = vec[j],num2 = a[2*i]/num1;
			ll t = (+ num1 + num2), v = (- num1 + num2) ;
			if((num1 < num2) && (v % 2 == 0) && ( (i == 1) || (v/2 > numbers[2*i-2]) )){
				if(t < a_t){a_t = t;a_v = v;}
			}
		}
		if(a_t == 1e18 || a_v == 1e18){
			// cout << i << endl ;
			// cout << "yolo";
			no = 1;break;
		}
		numbers[2*i - 1] = a_v/2 ;
		numbers[2*i] = a_t/2 ;
		if(i == 1)a[1] = (a_v/2)*(a_v/2);
		else a[2*i - 1] = (a_v/2)*(a_v/2) - numbers[2*i - 2]*numbers[2*i - 2] ;
		if(a[2*i - 1]  <= 0){
			no=1;
			cout << i << endl ;
			break;
		}
	}
	if(no == 1){
		cout << "No" << endl;
	}
	else{
		cout << "Yes" << endl ;
		for(int i=1;i<=n;i++)cout << a[i] << " " ; cout << endl ;
	}
}