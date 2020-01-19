// bfs

///// dependency
// #include "graph.c++"
/////

void bfs(Graph graph, int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        vector<Edge> next_edges = graph.next(p); // 接続先
        for(auto edge : next_edges){
            if(graph.vertice[edge.to].visited == false){
                graph.vertice[edge.to].visited = true;
                graph.vertice[edge.to].from = graph.vertice[p].id;
                graph.vertice[edge.to].distance = graph.vertice[p].distance + edge.cost + graph.vertice[edge.to].cost;
                q.push(edge.to);
            }
        }
    }
}
