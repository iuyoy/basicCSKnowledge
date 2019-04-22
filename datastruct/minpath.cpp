// 【Floyd算法】

//多源无负权  
//通过邻接矩阵跑出所有点之间的最短路,时间复杂度O(n^3),空间复杂度O(n^2)  
//d[i][j]表示i到j的最短路径长度
//初始化：d[i][i]=0,点到点有路按正常权值初始化,其余为INF  

int mp[n][n];  
int d[n][n];  
void Floyd()  
{  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=n;j++)  
            d[i][j]=mp[i][j];  
  
    for(int k=1;k<=n;k++)  //枚举以k为中间点的所有点的最短路  
        for(int i=1;i<=n;i++)  
            for(int j=1;j<=n;j++)  
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);  
}  

// 【Dijkstra算法】 

//单源无负权  
//适用于边权为正的情况,单源最短路问题  
//时间复杂度为O(V*V+E)  
//算法思路:设G=(V,E)是一个带权有向图，把图中顶点集合V分成两组，第一组为已求出最短路径的顶点集合（用S表示，初始时S中只有一个源点，以后每求得一条最短路径 , 就将加入到集合S中，直到全部顶点都加入到S中，算法就结束了）  
//不断的维护一个dis数组，最后得到的dis数组中dis[i]就是源点到图中节点i的最短路径的长度  
//记录vis数组判断当前点是否访问过 

int mp[n][n];  
int dis[n];  
int vis[n];  
void init()  
{  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=1;j<=n;j++)  
        {  
            if(i==j)  
                mp[i][j]=0;  
            else  
                mp[i][j]=INF;  
        }  
    }  
}  
int djs(int st,int ed)  
{  
    for(int i=1;i<=n;i++)  
    {  
        dis[i]=mp[st][i];  
        vis[i]=0;  
    }  
    vis[st]=1;  
    for(int i=1;i<n;i++)  
    {  
        int minn=INF;   
        int next=-1;   //确定下一个点  
        for(int j=1;j<=n;j++)  
        {  
            if(vis[j]==0&&dis[j]<minn)  
            {  
                minn=dis[j];  
                next=j;  
            }  
        }  
        if(next==-1)   //当前已不存在点  
            continue;  
        vis[next]=1;  
        for(int j=1;j<=n;j++)  
        {  
            if(vis[j]==0)                                  //vis[j]=1已为最短路径  
                dis[j]=min(dis[j],dis[next]+mp[next][j]);  //以next为中间点进行松弛  
        }  
    }  
    return dis[ed]; 
}  
// 【Bellman-Ford算法】 
//可解决负权边,解决单源最短路径,时间复杂度O(nm),空间复杂度O(m)  
//主要思想:最短路一定不含环(不论正、负、零环),所以最短路一定最多只包含n-1条边  
//我们对每条边进行n-1次松弛后即为最短路  
//此外，Bellman_Ford还可以检测一个图是否含有负权回路：如果在进行n-1轮松弛后仍然存在dst[e[i]] > dst[s[i]]+w[i]  
//建图时注意,如果是无向图,s,e,w数组应该开2*m大小,要建双向边  

int s[m];  //起点  
int e[m];  //终点  
int w[m];  //权值  
int dis[n];   //源点到每个点的最短路  
int blm(int st,int ed)  
{  
    for(int i=1;i<=n;i++)  
        dis[i]=INF;  
    dis[st]=0;  
    for(int k=1;k<n;k++)  
    {  
        for(int i=1;i<=m;i++)  
        {  
            dis[e[i]]=min(dis[e[i]],dis[s[i]]+w[i]);  
        }  
    }  
    return dis[ed];  
    //检测负权回路  
    /* 
    bool flag=false; 
    for(int i=1;i<=m;i++) 
        if(dis[e[i]]>dis[s[i]]+w[i]) 
            flag=true; 
    if(flag) 
        cout<<"存在负权回路"<<endl; 
    */  
}  

// 【SPFA,Bellman-Ford的队列优化】

//玄学时间复杂度,O(E)-O(VE)之间  
//假设有一个点刚刚被优化了，我们可以很明显的发现，针对这条边，  也就只有这条边的出边上的终点才可以继续被优化，这就给了我们启示，  其实我们可以再维护一个队列，一个点如果被优化过了，那么就进队列。

int mp[n][n];  
int n,m;  
int dis[n];  
int vis[n];  
void init()  
{  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=1;j<=n;j++)  
        {  
            if(i==j)  
                mp[i][j]=0;  
            else  
                mp[i][j]=INF;  
        }  
    }  
}  
int spfa(int st,int ed)  
{  
    for(int i=1;i<=n;i++)  
    {  
        dis[i]=INF;  
        vis[i]=0;  
    }  
    dis[st]=0;  
    queue<int>q;  
    q.push(st);  
    vis[st]=1;  
    while(!q.empty())  
    {  
        int now=q.front();  
        q.pop();  
        vis[now]=0;  
        for(int i=1;i<=n;i++)  
        {  
            if(dis[i]>dis[now]+mp[now][i])  
            {  
                dis[i]=dis[now]+mp[now][i];  
                if(vis[i]==0)  
                {  
                    q.push(i);  
                    vis[i]=1;  
                }  
            }  
        }  
    }  
    return dis[ed];  
}  
