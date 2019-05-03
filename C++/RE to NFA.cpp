#include <iostream>
#include <stdio.h>

using namespace std;

int s=0;
void plus(a,b)
{
    states[s][s+1] = 'E';
    states[s][s+3] = 'E';
    states[s+1][s+2] = a;
    states[s+3][s+4] = b;
    states[s+2][s+5] = 'E';
    states[s+3][s+5] = 'E';
    s = s + 5;
}
void star(a)
{
    states[s][s+1] = a;
    states[s][s+2] = 'E';
    states[s+1][s] = 'E';
    s = s + 2
}
int main()
{
    int ;
    char str[20], states[20][20];
    cin >> str;
    for(i=0;i<strlen(str);i++)
    {
        if (str[i+1]!='*' || str[i+1]!='+' || str[i+1]!='(' || str[i+1]!=')')
        {

        }
        else if (str[i]=='+')
        {
            plus(str[i-1],str[i+1])
        }
        else if (str[i]=='*')
        {
            star(str[i-1]);
        }
    }
}
