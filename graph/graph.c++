// graph

///// dependency
/////

class Edge{
public:
    int from, to;
    long cost;

    Edge(int f, int t, long c){
        from = f;
        to = t;
        cost = c;
    }

    Edge(int f, int t){
        Edge(f, t, 1);
    }

    Edge(){
        Edge(INF, INF, 1);
    }

    bool operator<(const Edge &e) const{
        if(cost < e.cost){
            return true;
        }else if(cost > e.cost){
            return false;
        }else{
            if(from < e.from){
                return true;
            }else if(from > e.from){
                return false;
            }else{
                if(to < e.to){
                    return true;
                }else if(to > e.to){
                    return false;
                }else{
                    return false;
                }
            }
        }
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
    long distance; // ここまでのパスの cost の合計

    Vertex(int i, long c, bool v, int f, long d){
        id = i;
        cost = c;
        visited = v;
        from = f;
        distance = d;
    }

    Vertex(int i, long c, bool v){
        Vertex(i, c, v, INF, INF);
    }

    Vertex(int i){
        Vertex(i, 0, false, INF, INF);
    }
    
    Vertex(){
        Vertex(INF, 0, false, INF, INF);
    }

    bool operator<(const Vertex &v) const{
        // cost で比較
        if(cost < v.cost){
            return true;
        }else if(cost > v.cost){
            return false;
        }else{
            if(id < v.id){
                return true;
            }else if(id > v.id){
                return false;
            }else{
                return false;
            }
        }
    }

    bool operator==(const Vertex &v) const{
        if(cost == v.cost && id == v.id){
            return true;
        }
        return false;
    }

    inline bool operator!=(const Vertex& v) const{
        return !(*this == v);
    }

    void reset_vertex(){
        distance = 0;
        visited = false;
        from = INF;
    }
};

class Graph{
public:
    int number_of_vertice;
    int number_of_edges;
    vector<Vertex> vertice;
    vector<vector<Edge>> edges; // 隣接リスト

    void reset(){
        for(auto &vertex : vertice){
            vertex.reset_vertex();
        }
    }

    vector<Edge> next(int vertex_id){
        // 隣接枝リストを返す
        return edges[vertex_id];
    }
};