#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll x, ll y){
    if(y == 0)return x;
    return gcd(y, x % y);
}

int main(){
    ll x, y, n; cin >> x >> y >> n;
    ll g = gcd(x, y);
    x = x / g;y = y/g;
    if(y <= n)cout << x << "/" << y << endl;
    else {
        ll finn, find;
        double diff = 1e18;
        for(ll i =1; i <= n; i++){
            ll ansn, ansd;
            double num = (double)(x*i) / (double)y;
            ll num1 = floor(num), num2 = ceil(num);
            if(llabs(i*x - y*num1) <= llabs(i*x - y*num2)){
                ansn = num1; ansd = i;
            } else {
                ansn = num2; ansd = i;
            }
            ll gc = gcd(ansn, ansd);ansn = ansn / gc; ansd = ansd/gc;
            double tempdiff = (double)(llabs(x*ansd - ansn*y))/ (double)(y*ansd);
            if(tempdiff < diff){
                finn = ansn;find = ansd;
                diff = tempdiff;
            }
        }
        cout << finn << "/" << find << endl;
    }
}