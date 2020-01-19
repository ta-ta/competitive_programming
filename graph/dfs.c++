// dfs

///// dependency
// #include "graph.c++"
/////

void dfs(Graph& graph, int start){
    vector<Edge> next_edges = graph.next(start); // 接続先
    for(auto edge : next_edges){
        if(graph.vertice[edge.to].visited == false){
            graph.vertice[edge.to].visited = true;
            graph.vertice[edge.to].from = start;
            graph.vertice[edge.to].distance = graph.vertice[start].distance + edge.cost + graph.vertice[edge.to].cost;
            dfs(graph, edge.to);
        }
    }
}
