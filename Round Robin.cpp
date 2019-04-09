#include <iostream>
using namespace std;
struct processes
{
    int at,bt,c,wt,tat;
} p[10];
int main()
{
    int ct=0,rem_bt[10],i,j,n,qt,done=1;
    float awt=0,atat=0;
    cout<<"Enter the number of processes: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter arrival time and burst time of process "<<i+1<<": ";
        cin>>p[i].at>>p[i].bt;
    }
    cout<<"Enter the time quantum: ";
    cin>>qt;
    for(i=0;i<n;i++)
    {
        rem_bt[i] = p[i].bt;
    }
    i=0;
    // Calculation of completion time
    while(1)
    {
        done = 1;
        if(i==n-1)
            i=0;
        if(rem_bt[i] > 0)
        {
            if(rem_bt[i] >= qt)
            {
                rem_bt[i] = rem_bt[i] - qt;
                ct = ct + qt;
            }
            else
            {
                ct = ct + rem_bt[i];
                rem_bt[i] = 0;
            }
            p[i].c = ct;
        }
        i++;
        for(j=0;j<n;j++)
        {
            if(rem_bt[j] != 0)
                done = 0;
        }
        if(done)
        break;
    }

    // Calculation of turnaround time
    for(i=0;i<n;i++)
    {
        p[i].tat = p[i].c - p[i].at;
    }

    // Calculation of waiting time
    for(i=0;i<n;i++)
    {
        p[i].wt = p[i].tat - p[i].bt;
    }

    // Calculation of average waiting time
    for(i=0;i<n;i++)
    {
        awt = awt + p[i].wt;
    }
    awt = awt/n;

    //Calcuation of average turnaround time
    for(i=0;i<n;i++)
    {
        atat = atat + p[i].tat;
    }
    atat = atat/n;

    cout<<awt<<" "<<atat<<endl;
    return 0;
}
