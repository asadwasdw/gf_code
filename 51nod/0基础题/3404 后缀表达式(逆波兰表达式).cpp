#include<iostream>
#include<algorithm>
#include<stack>
#include <stdlib.h>

using namespace std;


stack<double>num;

int main()
{
    char s[1010];
    while (cin >> s)
    {
        if (s[0] >= '0' && s[0] <= '9')
        {
            double e = atof(s);
            num.push(e);
        }
        else if (s[0] == '-' && s[1] >= '0' && s[1] <= '9')
        {
            double e = atof(s);
            num.push(e);
        }
        else if (s[0] == '+' && s[1] >= '0' && s[1] <= '9')
        {
            double e = atof(s);
            num.push(e);
        }
        else
        {
            double b = num.top(); num.pop();
            double a = num.top(); num.pop();
            double c;
            if (s[0] == '+') {
                c = a + b;
            }
            else if (s[0] == '-') c = a - b;
            else if (s[0] == '*')c = a * b;
            else c = a / b;
            num.push(c);
        }
    }

    printf("%.6lf", num.top());

}