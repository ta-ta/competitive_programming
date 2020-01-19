///// dependency
#include "graph.c++"
/////

#include "dfs.c++"

void answer(){
    Graph graph;
    int from, to;

    cin>>graph.number_of_vertice>>graph.number_of_edges;
    graph.vertice.resize(graph.number_of_vertice);
    graph.edges.resize(graph.number_of_vertice);
    
    // init vertex
    for(int i=0; i<graph.number_of_vertice; i++){
        graph.vertice[i] = Vertex(i, 0, false);
        graph.edges[i] = vector<Edge>();
    }
    graph.reset();
    
    // init edge
    for(int i=0; i<graph.number_of_edges; i++){
        cin>>from>>to;
        // 入力される値の範囲, 0-indexed ?
        from--;
        to--;
        
        graph.edges[from].push_back(Edge(from, to, 1));
        graph.edges[to].push_back(Edge(to, from, 1)); // 無向
    }

    // dfs
    for(int i=0; i<graph.number_of_vertice; ++i){
        if(graph.vertice[i].visited == false){
            graph.vertice[i].visited = true;
            graph.vertice[i].distance = graph.vertice[i].cost;
            dfs(graph, i);
        }
    }


    return;
}
