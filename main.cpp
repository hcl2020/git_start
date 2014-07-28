#include <iostream>
#include <stdio.h>

using namespace std;

int N,d;
struct computer
{
    int X;
    int Y;
    int run;
    computer *next;

    computer()
    {
        cin>>X>>Y;
        run=0;
    }
}*point[1002];

bool judge_d(computer a,computer b)
{
    if((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y)<=d*d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool judge_l(int a,int b)
{
    if(judge_d(*point[a],*point[b])*point[a]->run*point[b]->run==0)
        return false;
    else
        return true;
}

int main()
{
    freopen("data","r",stdin);

    cin>>N>>d;

    for(int i=1;i<=N;i++)
    {
        point[i]=new computer;
    }

    int dis[1002][1002];

    for(int i=1;i<N;i++)
    {
        for(int j=1;j<N;j++)
        {
            dis[i][j]=judge_d(*point[i],*point[j]);
        }
    }

    char option;
    int c1,c2;
    while(cin>>option)
    {
        if(option=='O'){
            cin>>c1;
            point[c1]->run=1;
            //cout<<"O\n";
        }
        if(option=='S'){
            cin>>c1>>c2;
            if(judge_l(c1,c2))
            {
                cout<<"SUCCESS"<<endl;
            }
            else
            {
                cout<<"FAIL"<<endl;
            }
        }
    }
    return 0;
}
