#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> acc(n);for(int i=0;i<n;i++)cin >> acc[i];
    double avg = 0.0;for(int i=0;i<n;i++)avg += (double)acc[i];avg = avg / (double)n;
    double left = 0.0, right = avg, mid = (left + right / 2), transferred = 0.0;
    for(int i=0;i<n;i++)transferred += ((double)(acc[i]) >= mid) * ((double)(acc[i]) - mid);
    double diff = mid - (avg - (double)k*transferred/((double)(100 * n) ) );
    while(fabs(diff) >= 1e-10 ){
        if(diff > 0){
            right = mid;
        } else if(diff < 0){
            left = mid;
        }
        mid = (left + right )/ 2;
        transferred = 0.0;
        for(int i=0;i<n;i++)transferred += ((double)(acc[i]) >= mid) * ((double)(acc[i]) - mid);
        diff = mid - (avg - (double)k*transferred/((double)(100 * n) ) );
    }
    printf("%.10f\n", mid);
}