// bfs

///// dependency
// #include "graph.c++"
/////

void bfs(Graph graph, int start){
    queue<Vertex> q;
    q.push(graph.vertice[start]);
    while(!q.empty()){
        Vertex p = q.front();
        q.pop();
        vector<Edge> next_edges = graph.next(p.id); // 接続先
        for(auto edge : next_edges){
            if(graph.vertice[edge.to].visited == false){
                graph.vertice[edge.to].visited = true;
                graph.vertice[edge.to].from = p.id;
                graph.vertice[edge.to].distance = p.distance + edge.cost + graph.vertice[edge.to].cost;
                q.push(edge.to);
            }
        }
    }
}
