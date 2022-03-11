#include <bits/stdc++.h>

using namespace std;
 char a[20][20];
 int b[20][20],m,n;
 void kt()
 {
     for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
         b[i][j]=-1;
 }
 void in()
 {
     for (int i=1;i<=m;i++)
        {for (int j=1;j<=n;j++)
          cout<<a[i][j];
          cout<<endl;}
 }
int countbomb(int i,int j)
{   int res=0;
    for (int x=-1;x<=1;x++)
        for (int y=-1;y<=1;y++)
           if (a[i+x][j+y]=='M')
           res++;
    return res;
}
int main()
{
    int k;
    cin>>m>>n>>k;
    kt();
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
          cin>>a[i][j];
     while (k>0)
     {  int x,y;
        cin>>x>>y;
        if (a[x][y]=='M')
                {cout<<"YOU'RE DEAD!"<<endl;
                   in();
                   return 0;
                }
        for (int i=1;i<=m;i++)
         {for (int j=1;j<=n;j++)
            {if (i==x&&j==y)
                b[i][j]=countbomb(i,j);
            cout<<b[i][j]<<" ";
            }
          cout<<endl;
         }
         k--;
     }


}
