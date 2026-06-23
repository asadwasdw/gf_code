#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <algorithm>
#include <utility>
#include <tuple>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//c h o k u d a i
//0 1 2 3 4 5 6 7

//chochokudai


int main(){

    string s;
    cin >> s;

    map<char,ll> mp;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'c'){
            mp['c']++;
        }else if(s[i] == 'h'){
            mp['h'] += mp['c'];
        }else if(s[i] == 'o'){
            mp['o'] += mp['h'];
        }else if(s[i] == 'k'){
            mp['k'] += mp['o'];
        }else if(s[i] == 'u'){
            mp['u'] += mp['k'];
        }else if(s[i] == 'd'){
            mp['d'] += mp['u'];
        }else if(s[i] == 'a'){
            mp['a'] += mp['d'];
        }else if(s[i] == 'i'){
            mp['i'] += mp['a'];
        }

        mp[s[i]] %= MOD;
    }

    cout << mp['i'] << endl;

}
