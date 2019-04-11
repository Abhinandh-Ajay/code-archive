#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char input[100],*l,*r,*temp,productions[50][50];
    int flag=0,i=0,j=0;
    cout<<"Enter the production: ";
    cin>>input;
    l = strtok(input,"->");
    r = strtok(NULL,"->");
    temp = strtok(r,"|");
    while(temp)
    {
        if(temp[0]==l[0])
        {
            flag=1;
            sprintf(productions[i++],"%s'->%s%s'\0",l,temp+1,l);
        }
        else
        {
            sprintf(productions[i++],"%s->%s%s'\0",l,temp,l);
        }
        temp = strtok(NULL,"|");
    }
    sprintf(productions[i++],"%s'->\356\0",l);
    if(flag==0)
    {
        printf("The given productions don't have left recursion\n");
    }
    else
        for(j=0;j<i;j++)
            cout<<productions[j]<<endl;
    return 0;
}
