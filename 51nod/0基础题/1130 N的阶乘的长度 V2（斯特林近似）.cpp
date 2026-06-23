#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const double PI = acos(-1);
const double e = exp(1);

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    
    ll n;
    cin>>n;
    cout<<(ll)(0.5*log10(2*PI*n)+n*log10(n*1.0/e)+1)<<endl;
    }

}