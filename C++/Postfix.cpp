#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int pres(char ch)
{
    if(ch=='^')
    return 3;
    else if(ch=='*'||ch=='/')
    return 2;
    else if(ch=='+'||ch=='-')
    return 1;
    else
    return -1;
}int main()
{
    char A[100],post[100],stk[100];
    int i=0,j=0,k=0;
    stk[0]=0;
    cin>>A;
    while(i<strlen(A))
    {
        if(isalpha(A[i]))
        {
            post[j]=A[i];
            j++;
            i++;
        }
        else if(A[i]=='(')
        {
            stk[k]=A[i];
            k++;
            i++;
        }
        else if(A[i]==')')
        {
            while(stk[k]!='(')
            {
                post[j]=stk[k-1];
                if(post[j]=='(')
                j--;
                j++;
                k--;
            }
            i++;
        }
        else
        {
            while(pres(A[i])<=pres(stk[k-1]))
            {
                post[j]=stk[k-1];
                j++;
                k--;
            }
            stk[k]=A[i];
            i++;
            k++;
        }   
    }
    while(k>=0)
    {
        post[j]=stk[k-1];
        k--;
        j++;
    }
    cout<<post;
    return 0;
}