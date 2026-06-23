#include<iostream>

#include<algorithm>

using namespace std;
const int N = 3e5 + 10;
bool qpp[N];
bool hpp[N];

int main()
{
    string s, t;
    cin >> s >> t;

    qpp[0] = true;
    for (int i = 0; i < t.size(); i++) {

        if (s[i] == t[i] || s[i] == '?' || t[i] == '?')
        {
            qpp[i + 1] = true;
           
        }
        else
        {
            break;
         
        }
    }

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    hpp[0] = true;
    for (int i = 0; i < t.size(); i++) {
        if (s[i] == t[i] || s[i] == '?' || t[i] == '?')hpp[i + 1] = true;
        else break;
    }

    for (int x = 0; x <= t.size(); x++)
    {
        if (qpp[x] && hpp[t.size() - x])cout << "Yes" << endl;
        else cout << "No" << endl;
    }




}