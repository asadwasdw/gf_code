#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;
int id;

int ra(){
    return rand()*id;
}

int main() {
    freopen("data.in","w", stdout);
    freopen("dp.out","r", stdin);
    srand((unsigned int) time (NULL));
    cin >> id;

    int t = 1;
    cout << t << endl;
}