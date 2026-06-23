#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main() {
    freopen("data.in", "w", stdout);
    srand( (unsigned int) time (NULL));

    cout << "1\n";

    int n = rand() % 3 + 1;
    int m = rand() % 3 + 1;
    cout << n << " " << m << endl;

    for(int i = 1; i <= n; i ++) {
        cout << rand() % 3 + 1 << " ";
    } cout << endl;
    
    for(int i = 1; i <= m; i ++) {
        cout << rand()%10 + 1 << " " << rand()%n + 1 << endl;
    }

}