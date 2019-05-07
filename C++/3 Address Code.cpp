#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int i,n,t;
    string str;
    cout<<"Enter an expression\n";
    cin>>str;
    n = str.length();
    t=1;
    while(n>1)
    {
        for(i=0;i<n;i++)
        {
            if(str[i]=='*')
            {
                cout<<"t"<<t<<" = "<<str[i-1]<<" * "<<str[i+1]<<endl;
                str.replace(i-1,3,to_string(t));
                t++;
                n=n-2;
            }
        }
        for(i=0;i<n;i++)
        {
            if(str[i]=='/')
            {
                cout<<"t"<<t<<" = "<<str[i-1]<<" / "<<str[i+1]<<endl;
                str.replace(i-1,3,to_string(t));
                t++;
                n=n-2;
            }
        }
        for(i=0;i<n;i++)
        {
            if(str[i]=='+')
            {
                cout<<"t"<<t<<" = "<<str[i-1]<<" + "<<str[i+1]<<endl;
                str.replace(i-1,3,to_string(t));
                t++;
                n=n-2;
            }
        }
        for(i=0;i<n;i++)
        {
            if(str[i]=='-')
            {
                cout<<"t"<<t<<" = "<<str[i-1]<<" - "<<str[i+1]<<endl;
                str.replace(i-1,3,to_string(t));
                t++;
                n=n-2;
            }
        }
    }
    return 0;
}
