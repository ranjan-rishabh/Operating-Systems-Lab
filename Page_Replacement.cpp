#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
vector <int> f[100];
main()
{
    int mm,ps,mw;
    double pls,w,s=0;
    cout<<"Enter Max Word Limit:";
    cin>>mw;
    cout<<"Enter Main Memory Size:";
    cin>>mm;
    cout<<"Enter Page Size:";
    cin>>ps;
    queue <int> q;
    int n=mm/ps,i,qw=mw/ps;
    int fr[qw];
    for(int k=0,i=0;i<=qw;i++)
    {
        f[i].push_back(k);
        f[i].push_back(-1);
        fr[i]=-1;
        k++;
    }
    cout<<"Enter Number Of Words:";
    cin>>w;
    int l=0;
    vector <int> qt;
    for(i=0;i<w;i++)
    {
        int ws,d;
        cout<<"\nEnter Word:";
        cin>>ws;
        d=ws/ps;
        bool c=0;
        if(f[d][1]==0)
        {
            c=1;
            s++;
            cout<<"\nSuccess\n";
        }
        if(!c)
        {
            if(n>0)
            {
                n--;
                f[d][1]=0;
                fr[d]=l++;
                q.push(d);
                cout<<"\nPage Loaded\n";
            }
            else
            {
                int z=q.front();
                q.pop();
                fr[d]=fr[z];
                fr[z]=-1;
                f[z][1]=-1;
                f[d][1]=0;
                q.push(d);
                cout<<"\nPage Replacd\n";
            }
        }
        cout<<"\nPage Table:\n";
        for(int k=0;k<=qw;k++)
        {
            cout<<f[k][0]<<'\t'<<f[k][1]<<'\t'<<fr[k]<<'\n';
        }
        cout<<"Queue:\t";
        for(int lo=0;!q.empty();lo++)
        {
            qt.push_back(q.front());
            cout<<q.front()<<'\t';
            q.pop();
        }
        for(int lo=0;lo<qt.size();lo++)
        {
            q.push(qt[lo]);
        }
        cout<<'\n';
        qt.clear();
    }
    cout<<"Success Frequency:"<<s;
    cout<<"\nSuccess Fraction:"<<(float)(s/w);
}
