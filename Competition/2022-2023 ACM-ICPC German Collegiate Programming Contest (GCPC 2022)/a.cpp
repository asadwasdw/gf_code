#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b;
    cin >> a >> b;
    if(a > b)swap(a, b);
    ll cnt = 1;
    a--,b--;
    for(ll i = 1; i < a; i++){
        ll j = (a * a) - i * i;
        ll tmp = (ll)sqrt(j);
        if(tmp * tmp != j)continue;
        if(b * i % a)continue;
        if(b * tmp % a)continue;
        cnt++;
    }    
    if(a != b)cnt *= 2;
    cout << cnt << '\n';
}