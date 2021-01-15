/*!
 * @description
 * Given a list of jobs and a list of dependencies
 * (i.e. a job needs another one to be completed first)
 * write a programm that computes a valid order for
 * the jobs completion OR returns an empty arry if
 * such an order does not exist.
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

template < typename T >
using V = std::vector<T>;

struct Node {
    Node(int p_job): m_job(p_job) {}
    
    Node* popDep( void ) { 
        Node* res = nullptr;
        if ( !std::empty(m_deps) ) 
        { 
            res = m_deps.back();
            m_deps.pop_back();
            res->m_prereqs--;
        }
        return res;
    }

    int      m_job;
    int      m_prereqs{0}; /*!< Number of prereqs */
    V<Node*> m_deps   { };
};

struct Graph {
    Graph(const V<int>& p_jobs);
    
    void  addDep (int p_job, int p_dep);
    void  addNode(int p_job);
    Node* getNode(int p_job);
    
    V<Node*>                       m_nodes{};
    std::unordered_map<int, Node*> m_graph{};
};

Graph::Graph(const V<int>& p_jobs) {
    for ( const int& job : p_jobs ) addNode(job);
}
    
void  Graph::addDep (int p_job, int p_dep) {
    Node* jobNode { getNode(p_job) };
    Node* depNode { getNode(p_dep) };
    jobNode->m_deps.push_back( depNode );
    depNode->m_prereqs++;
}

void  Graph::addNode(int p_job) {
    m_graph.insert_or_assign( p_job, new Node(p_job) );
    m_nodes.push_back( m_graph[p_job] );
}

Node* Graph::getNode(int p_job) {
    if ( m_graph.find(p_job) == std::end(m_graph) ) { addNode(p_job); }
    return m_graph[p_job];
}

Graph* createGraph( const V<int>& p_jobs, const V<V<int>>& p_deps ) {
    Graph* res = new Graph(p_jobs);
    for ( const V<int>& dep : p_deps ) res->addDep( dep[0], dep[1] );
    return res;
}

void removeDeps( Node* n, V<Node*>* p_noPrereqs ) {
    Node* dep{ n->popDep() };
    while ( dep ) {
        if ( !dep->m_prereqs ) { p_noPrereqs->push_back(dep); }
        dep = n->popDep();
    }
}

V<int> getOrdered( Graph* p_graph ) {
    V<Node*>& gNodes   { p_graph->m_nodes };
    V<int>    ordered  {};
    V<Node*>  noPrereqs{ std::size(gNodes) };
    
    auto it = std::copy_if( std::begin( gNodes ),
                            std::end  ( gNodes ),
                            std::begin( noPrereqs ),
                            [](Node* n) { return n->m_prereqs == 0; } );
    noPrereqs.resize( std::distance( std::begin(noPrereqs), it) );
    
    while ( std::size(noPrereqs) ) {
        Node* n { noPrereqs.back() };
        noPrereqs.pop_back();
        ordered.push_back( n->m_job );
        removeDeps( n, &noPrereqs );
    }
    
    return std::find_if( std::begin(gNodes), std::end(gNodes),
                    [](Node* n){ return n->m_prereqs; } ) != std::end(gNodes) ? V<int>{} : ordered;
}

V<int> topologicalSort(V<int> jobs, V<V<int>> deps) {
    Graph* graph = createGraph( jobs, deps );
    return getOrdered(graph);
}
