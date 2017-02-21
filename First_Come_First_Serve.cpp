#include<bits/stdc++.h>
#include<conio.h>
#define ll long long
using namespace std;

ll att=0,awt=0;

struct process
{
    string id;
    int ar;
    int ct;
    int wt;
    int tt;
    process()
    {
        wt=0;
        tt=0;
    }
    process *n;
}*h=NULL;
process *crn()
{
    process *p=new process;
    cout<<"Enter Process ID:";
    cin>>p->id;
    cout<<"Enter Arrival Time:";
    cin>>p->ar;
    cout<<"Enter CPU Time:";
    cin>>p->ct;
    p->n=NULL;
    return p;
}
void shcn(int t)
{
    cout<<"Process ID:"<<h->id<<'\n';
    cout<<"Process Arrival:"<<h->ar<<'\n';
    cout<<"Process CPU Time:"<<h->ct<<'\n';
    h->wt=t-h->ar-h->ct;
    h->tt=t-h->ar;
    cout<<"Waiting Time:"<<h->wt<<'\n';
    cout<<"Turnaround Time:"<<h->tt<<'\n';
    att+=h->tt;
    awt+=h->wt;
}
main()
{
    cout<<"Enter Number Of Processes:";
    ll c,i=1;
    cin>>c;
    process *cu;
    while(i<=c)
    {
        if(h==NULL)
        {
            h=crn();
            cu=h;
        }
        else
        {
            cu->n=crn();
            cu=cu->n;
        }
        i++;
    }
    process *te=h;
    ll t=0;
    for(i=0;i<c;i++)
    {
        te=h;
        cout<<"At Time:"<<t<<'\n';
        cout<<"Ready Queue:";
        while(te!=NULL)
        {
            if(te->ar<=t)
                cout<<te->id<<" ";
            te=te->n;
        }
        cout<<'\n';
        t=t+h->ct;
        cout<<"Process Completed\n";
        shcn(t);
        cout<<'\n';
        h=h->n;
        getch();
    }
    cout<<"Average Turnaround Time:"<<att/c<<'\n';
    cout<<"Average Waiting Time:"<<awt/c<<'\n';
}
