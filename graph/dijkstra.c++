#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
    long from, to, cost;

    Edge(long f, long t, long c){
        from = f; // 0-indexed
        to = t; // 0-indexed
        cost = c;
    }

    Edge(long f, long t){
        Edge(f, t, 1);
    }

    bool operator<(const Edge &e) const{
        if(cost < e.cost){
            return true;
        }
        return false;
    }

    bool operator==(const Edge &e) const{
        if(to == e.to && from == e.from && cost == e.cost){
            return true;
        }
        return false;
    }

    inline bool operator!=(const Edge& e) const{
        return !(*this == e);
    }
};

class Vertex{
public:
    int id; // 0-indexed
    long cost;
    bool visited;
    int from;

    Vertex(int i, long c, bool v, int f){
        id = i;
        cost = c;
        visited = v;
        from = f;
    }

    Vertex(int i){
        Vertex(i, 0, false, INF);
    }

    bool operator<(const Vertex &v) const{
        if(cost < v.cost){
            return true;
        }
        return false;
    }

    bool operator==(const Vertex &v) const{
        if(id == v.id){
            return true;
        }
        return false;
    }

    inline bool operator!=(const Vertex& v) const{
        return !(*this == v);
    }

    void reset_vertex(){
        cost = 0;
        visited = false;
        from = INF;
    }
};

class Graph{
public:
    int N; // vertices
    int M; // edges
    vector<Vertex> vertex;
    vector < vector < Edge > > edge; // 隣接リスト

    void reset_vertex(){
        for(int i=0; i<N; ++i){
            vertex[i].reset_vertex();
        }
    }
};

void dijkstra(Graph graph, Vertex start){
    priority_queue <Vertex> pq;
    pq.push(start);
    while(!pq.empty()){
        Vertex p = pq.top();
        pq.pop();
        int l = graph.edge[p.id].size(); // 接続先
        for(int i=0; i<l; ++i){
            int next = graph.edge[p.id][i].to; // next vertex id
            if(graph.vertex[next].cost > graph.vertex[p].cost + graph.edge[p.id][i].cost){
                graph.vertex[next].cost = graph.vertex[p].cost + graph.edge[p.id][i].cost;
                graph.vertex[next].from = p;
                pq.push(graph.vertex[next]);
            }
        }
    }
}

int main(){
    Graph graph;
    int from, to, cost;

    cin>>graph.N>>graph.M;
    graph.vertex.resize(graph.N);
    graph.edge.resize(graph.N);
    
    // edge init
    for(int i=0; i<graph.M; i++){
        cin>>from>>to>>cost;
        // 入力される値の範囲, 0-indexed ?
        from--;
        to--;
        
        graph.edge[from].push_back((Edge){from, to, cost});
        graph.edge[to].push_back((Edge){to, from, cost}); // 無向
    }

    // vertex init
    for(int i=0; i<graph.N; i++){
        graph.vertex[i] = (Vertex){i, INF, false};
    }
    graph.reset_index();

    // dijkstra
    Vertex start = graph.vertex[0];
    dijkstra(graph, start);




    return 0;
}
