#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int , list<pair<int,int>>> adj;

    for(int i =0; i<edges ; i++){

        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices);

    for(int i=0 ; i<vertices ; i++){

        dist[i]=INT_MAX;
    }

    set<pair<int,int>> st;
     
     dist[source]=0;
    st.insert(make_pair(0 , source));

    while(!st.empty()){

        //fetch top record;
        auto top = *(st.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        //remove top
        st.erase(top);
        
        //traverse neighbours
        for(auto neighbour: adj[topNode]){

            if(nodeDist + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if(record!=st.end()){
                    st.erase(record);
                }

                dist[neighbour.first]= nodeDist + neighbour.second;

                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}


int main(){
    
    int vertices = 5;
    int edges = 7;
    
    vector<vector<int>> vec( edges , vector<int>(3));
    
    vec[0] = { 0,1,7};
    vec[1] = { 0,2,1};
    vec[2] = { 0,3,2};
    vec[3] = { 2,1,3};
    vec[4] = { 3,1,5};
    vec[5] = { 4,1,1};
    vec[6] = { 4,3,7};
    
    int source;
    cout<<"Enter starting point: " ;
    cin>>source;
    
    vector< int> dist(vertices) ;
    
    for(int i=0; i<vertices; i++){
        
        dist[i]= dijkstra(vec, vertices, edges, source)[i];
    }
    
    for(auto i:dist){
        
        cout<< i<<" ";
    }
    
    cout<<endl;
    
}
