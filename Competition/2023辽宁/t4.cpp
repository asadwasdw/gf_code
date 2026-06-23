#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e6 + 10;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;

void solve() {
    // 打开文件用于写入
    ofstream outFile("student.dat", ios::out);
    string s;
    while (cin >> s) {
        outFile << s << endl;
    }
    outFile.close();

    // 打开文件用于读取
    ifstream inFile("student.dat", ios::in);
    while (inFile >> s) {
        cout << s << endl;
    }
    inFile.close();
}

int main() {
    solve();
    return 0;
}