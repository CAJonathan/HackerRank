#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cassert>

using namespace std;

#define rep(i,a,b) for(__typeof(a) i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()
#define min 100009
#define inf 1e9

/******** Data Structure ************/
int dist[2][min];
int pre [2][min];

vector< vector<int> > vv(min) , cost(min);
vector< vector<int> > tr(min) , trc(min);

/********* ititialize **************/
//
void reset() {
    rep( i , 0 , 2 ) rep( j , 0 , min ) dist[i][j] = inf; 
    CLEAR( pre , -1 );
    rep( i , 0 , min ) vv[i].clear() , cost[i].clear();
    rep( i , 0 , min ) tr[i].clear() , trc[i].clear();
}

/********Dijkstra *****************/
void DIJ( int src , int id ) {
    rep( i , 0 , min ) dist[id][i] = inf;
    dist[id][src] = 0;
    priority_queue< ii , vector<ii> , greater<ii> > Q;
    ii tmp = make_pair( 0 , src );
    Q.push(tmp);

    while( !Q.empty()  ) {
        tmp = Q.top();Q.pop();
        int w = tmp.first , u = tmp.second;
        int sz = vv[u].size();        

        rep( i , 0 , sz ) {        
            int v = vv[u][i] , cst = cost[u][i];
            if( dist[id][v] > w+cst ) {
                dist[id][v] = w + cst;
                pre[id][v]  = u;
                ii newp = make_pair( dist[id][v] , v );
                Q.push(newp);
            }    
        }
    }
}

/*****Data structure for Query part ***********/
struct edge {
    int u , v , w;
    bool friend operator < ( const edge &A , const edge &B ) {
        return A.w > B.w;
    }
};
typedef struct edge edge;
edge arr[min];

priority_queue< edge > Heap[min];
int label[min] , minl[min] , minl[min];
int counter;
/********* tree labeling **********************/
void DFS( int src ) {
    int sz = tr[src].size();minl[src] = counter;
        rep( i , 0 , sz ) {
        int v = tr[src][i];
        DFS( v );
    }
    label[src] = counter;
    minl[src]  = counter;
    counter++;
}
/*****MMG Algorithm****************************/
void replace( int src ) {
        
    int sz = tr[src].size();
    rep( i , 0 , sz ) {
        int v = tr[src][i];
        replace( v ); 
        while(!Heap[v].empty()) {
            Heap[src].push(Heap[v].top());Heap[v].pop();
        }
    }
    while(!Heap[src].empty()) {    
        edge e = Heap[src].top();Heap[src].pop();
        int u = e.u , v = e.v , w = e.w; 

        if( (label[u] >= minl[src] && label[u] <= minl[src] ) && !(label[v] >= minl[src] && label[v] <= minl[src] ) ) {
            arr[src] = e;Heap[src].push(e);break;
        }
        else if(!(label[u] >= minl[src] && label[u] <= minl[src] ) && (label[v] >= minl[src] && label[v] <= minl[src] )) {
            arr[src] = e;Heap[src].push(e);break;
        }
    }
}
int main()
{
    reset();
    int n , m;
    scanf("%d %d" , &n , &m);
    
    assert( n < 200000 && m < 200000 && n > 0 && m > 0 );
    

    rep( i , 0  , m ) {
        int u , v , w;scanf("%d %d %d" , &u , &v , &w );
    
    
        assert( u >= 0 && u < n );assert( v >= 0 && v < n );assert( u != v );    
        assert( w <= 1000 );
    
        vv[u].push_back(v);cost[u].push_back(w);
        vv[v].push_back(u);cost[v].push_back(w);
    }
    
    int S , T;
    scanf("%d %d" , &S , &T );


    assert( S >= 0 && S < n );assert( T >= 0 && T < n );

    DIJ( S , 0 );
    DIJ( T , 1 );
    

    map<ii,int> mp;mp.clear();
    rep( i , 0 , n ) {
        if( pre[0][i] != -1 ) { 
            tr[pre[0][i]].push_back(i); 
            mp[make_pair( i , pre[0][i])] = 1;
            mp[make_pair( pre[0][i] , i)] = 1;
        }
    }
    
    // After shortest path
    counter = 1;
    DFS( S ); 
/*    DFS labeling for fining cut
    rep( i , 0 , n ) {
        cout << label[i] <<" " <<  minl[i] << " " << minl[i] << "\n";
    }
*/
    rep( i , 0 , n ) arr[i].w = inf; 
    rep( i , 0 , n ) {    
        int sz = vv[i].size();
        rep( j , 0 , sz ) {
            int v = vv[i][j] , w = cost[i][j];
            if( !mp[make_pair( i ,v )] ) {
                    edge e = (edge){ i , v , dist[0][i]+w+dist[1][v] };
                    Heap[v].push(e);            
            }
        }
    }
    replace(S);
    // Query Part
    mp.clear();
    rep( i , 0 , n ) {
        if( i != S ) {
            mp[ make_pair(pre[0][i] , i ) ] = arr[i].w;
            mp[ make_pair(i , pre[0][i] ) ] = arr[i].w; 
        }
    }    

    int Q;scanf("%d" , &Q);

    assert( Q < 200000 && Q > 0 );
    map< ii , int > mp1;

    int cur = T;
    //
    int tcnt = 0;

    while( cur != -1 ) {
         
        mp1[make_pair(pre[0][cur] , cur )] = mp[make_pair(pre[0][cur] , cur )];
        mp1[make_pair(cur , pre[0][cur] )] = mp[make_pair(cur , pre[0][cur] )];
        cur = pre[0][cur];     
    
    }
    mp.clear();
    rep( i , 0 , Q ) {
        int u , v;
        scanf("%d %d" , &u  , &v );
        assert( u >= 0 && u < n );assert( v >= 0 && v < n );assert( u != v );
                

        if( mp1[make_pair( u , v ) ] == 0 ) cout << dist[0][T] << "\n";
        else if( mp1[make_pair(u,v)] == inf ) cout << "Infinty\n"; 
        else cout << mp1[make_pair( u , v ) ] <<"\n";
    }
    

    return 0;
}