#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    vector<bool> isprime(1e6 + 1, true);
    vector<ll> primes;
    for(ll i = 2;i <= 1e6; i++){
        if(isprime[i]){
            primes.push_back(i);
            for(ll j = i*i; j <= 1e6; j+=i){
                isprime[j] = false;
            }
        }
    }
    ll n; cin >> n;
    if(isprime[n]){
        cout <<  n << endl;
        for(int k = 1;k <= n; k++){
            if(k == n)cout << n << " " << 1 << endl;
            else cout << k << " " << k + 1 << endl;
        }
    } else {
        for(int i = 2; i <= n; i+=2){
            if(isprime[(2*n + i)/2]){
                cout << (2*n + i)/2 << endl;
                if(i == 2){
                    cout << 1 << " " << 3 << endl;
                } else {
                    for(int j = 1; j <= i / 2; j++){
                        cout << j << " " << i/2 + j << endl;
                    }
                }
                for(int k = 1;k <= n; k++){
                    if(k == n)cout << n << " " << 1 << endl;
                    else cout << k << " " << k + 1 << endl;
                }
                break;
            }
        }
    }
    
}