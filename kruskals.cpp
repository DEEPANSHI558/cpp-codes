#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};
bool cmp(Edge a,Edge b){
    return a.weight <b.weight; //increasing order
}
int findparent(int v,vector<int>parent){
    if(parent[v]==v){
        return v;
    }
    return findparent(parent[v],parent);
}
vector<Edge>kruskals(vector<Edge> edges,int v,int e){
    // sort on the basis of weights
    sort(edges.begin(),edges.end(),cmp);
    // now start putting it in the edges list and checking if adding the edge will result in creatin an edge so keeping an parent array
    // if v1 and v2 do not have the same parent then (using union find algo)
    vector<int>parent(v,0);
    // pehle sabke parent wo khud hi honge
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    //  int *parent= new int [v];
   
    // for (int i=0;i<v;i++){
    //     parent [i]=i;
    // }
    vector<Edge> ans;
    // we have to traverse through all the edges
    int count=0; //and this can have a maximum value of n-1 
    int i=0;
     while(count<v-1)
     {
          int sourceparent=findparent(edges[i].source,parent);
          int destinationparent=findparent(edges[i].dest,parent);
          if(sourceparent!=destinationparent){
                    ans.push_back({edges[i].source,edges[i].dest,edges[i].weight});
                    parent[sourceparent]=destinationparent;
                    count++;
          }
            i++;
     }
     return ans;
}

int main(){
    int v; //number of vertices
    int e; //number of edges
    cin>>v>>e;
    vector<Edge> edges;
    // ={
        
    //     {0 ,1, 3},{0, 3, 5},{1, 2 ,1},{2, 3, 8}
    // };
    
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        edges.push_back({s,d,w});
    }
    vector<Edge> ans=kruskals(edges,v,e);
    for(int i=0;i<ans.size();i++){
        if(ans[i].source<ans[i].dest){
            cout<<ans[i].source<<" "<<ans[i].dest<<" "<<ans[i].weight<<endl;
        }
        else{
            cout<<ans[i].dest<<" "<<ans[i].source<<" "<<ans[i].weight<<endl;
        }
    }
    return 0;
}