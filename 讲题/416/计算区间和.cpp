#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int m;
    cin >> m;
    while(m -- ) {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
}