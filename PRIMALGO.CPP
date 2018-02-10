#include<stdio.h>
#include<conio.h>
int g[20][20];
int v,e;
int d[20],p[20],visited[20];
void creategraph()
{
int a,b,w,i,j;
printf("Enter number of vertices");
scanf("%d",&v);
printf("Enter number of edges");
scanf("%d",&e);
for(i=1;i<=v;i++)
for(j=1;j<=v;j++)
g[i][j]=0;
for(i=1;i<=e;i++)
{
printf("Enter edge information");
scanf("%d",&a);
scanf("%d",&b);
printf("Enter the weight of edges");
scanf("%d",&w);
g[a][b]=g[b][a]=w;
}
}
void prim()
{
int c,current,mincost=0,i,min;
current=1;
visited[current]=1;
d[current]=0;
c=1;
while(c!=v)
{
for(i=1;i<=v;i++)
{
if(g[current][i]!=0&&visited[i]!=1)
if(g[current][i]<d[i])
{
d[i]=g[current][i];
p[i]=current;
}
}
min=32767;
for(i=1;i<=v;i++)
{
if(visited[i]!=1&&d[i]<min)
{
min=d[i];
current=1;
}
}
visited[current]=1;
c=c+1;
}
//Find out minimum cost by element to d array
for(i=1;i<=v;i++)
mincost +=d[i];
printf("minimum cost = %d\n",mincost);
}//End prim
void main()
{
int i;
clrscr();
creategraph();
//Initialize visited array to zero
for(i=1;i<=v;i++)
{
visited[i]=p[i]=0;
d[i]=32767;
}
prim();
getch();
}



