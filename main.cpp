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
    
    int vertices = 8;
    int edges = 16;
    
    vector<vector<int>> vec( edges , vector<int>(3));
    
    vec[0] = { 0,1,400};
    vec[1] = { 0,3,300};
    vec[2] = { 0,4,450};
    vec[3] = { 1,2,350};
    vec[4] = { 1,3,150};
    vec[5] = { 1,7,500};
    vec[6] = { 2,3,200};
    vec[7] = { 2,4,450};
    vec[8] = { 2,7,200};
    vec[9] = { 3,4,200};
    vec[10] = { 3,6,350};
    vec[11] = { 3,7,600};
    vec[12] = { 4,5,600};
    vec[13] = { 5,6,400};
    vec[14] = { 5,7,1400};
    vec[15] = { 0,6,500};
   
    
    int source;
    int dest;
    cout<<"0->CVR Hostel | 1->Carbon Mess | 2->Lecture Hall | 3->POD | "<<endl;
    cout<<"4->Library(LRC) | 5->Gate | 6->Abhinandan | 7->Health centre"<<endl;
    cout<<"Enter starting point: " ;
    cin>>source;
    cin>>dest;
    
    vector< int> dist(vertices) ;
    
    for(int i=0; i<vertices; i++){
        
        dist[i]= dijkstra(vec, vertices, edges, source)[i];
    }

        cout<< dist[dest];
    }
    
    cout<<endl;
    
}
