#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <memory>

struct Pt { int x, y; };

class Node {
    public :
        std::string getVal ( void ) const { return m_val; }
        Node*       getNode( char val )   { 
            return ( m_sons.find(val) != m_sons.end() ) ? m_sons[val].get() : nullptr; 
        }
        void        add    ( char val )   { m_sons[val] = std::make_unique<Node>(Node());  }
        bool        isWord ( void ) const { return ( m_sons.find(m_end) != m_sons.end() ); }
        void        setWord( std::string str ) { 
            m_val = str; if( !isWord() ) m_sons[m_end] = std::make_unique<Node>(Node()); 
        }
    
    private :
        std::string                                     m_val ;
        std::unordered_map<char, std::unique_ptr<Node>> m_sons;
        static const uint8_t                            m_end = '#'; 
};

class Trie {
    public :
        Trie() { m_root = std::make_unique<Node>(Node()); }
        Trie(const std::vector<std::string>& p_wrds): Trie() {
            for ( const auto& wrd : p_wrds ) { add(wrd); }
        }
    
        Node* getRoot( void ) { return m_root.get(); }
        void  add    ( std::string p_wrd ) {
            Node* cur = m_root.get();
            
            for ( auto& c : p_wrd ) {
                if ( !cur->getNode(c) ) { cur->add(c); }
                cur = cur->getNode(c);
            }
            cur->setWord(p_wrd);
        }   
    
    private :
        std::unique_ptr<Node> m_root;
};

bool inRange(Pt pt, const std::vector<std::string>& b) {
    return (pt.x >= 0 && pt.x < b.size()) && (pt.y >= 0 && pt.y < b.at(0).size());
}

std::vector<Pt> getNeighbours(Pt pt, const std::vector<std::string>& b) {
    std::vector<Pt> res; res.reserve(8);
    for     ( int i = pt.x -1; i <= pt.x + 1; i++ )
        for ( int j = pt.y -1; j <= pt.y + 1; j++ )
            if ( ( i != pt.x || j != pt.y ) && inRange({i,j}, b) ) { res.push_back({i,j}); }
    return res;
}

void explore( Pt pt, const std::vector<std::string>& b, Node* n,
              std::vector<std::vector<bool>> & vis,
              std::set<std::string>          & res ) {
    char c(b.at(pt.x).at(pt.y));
    if ( vis[pt.x][pt.y] || !n->getNode(c) ) { return; }
    vis[pt.x][pt.y] = true;
    n = n->getNode(c);
    if ( n->isWord() ) { res.insert(n->getVal()); }
    
    for ( auto& nhbr : getNeighbours(pt, b) ) { explore ( nhbr, b, n, vis, res); }
    vis[pt.x][pt.y] = false;
}

std::vector<std::string> findWords(std::vector<std::string> b, 
                                   std::vector<std::string> w,
                                   int N, int M) {    
    std::set<std::string>            res;
    std::string                      cur;
    std::vector< std::vector<bool> > vis( N, std::vector<bool>(M, false) );
    Trie                             trie(w);
    
    for     ( int i = 0; i < N; i++ )
        for ( int j = 0; j < M; j++ )
            explore( {i,j}, b, trie.getRoot(), vis, res );
    
  return std::vector<std::string>(res.begin(), res.end());
}

int main() {
    int N, M, W;
    std::cin >> N >> M >> W; std::cin.ignore();
    std::vector<std::string> grid(N, ""), wrds(W, "");

    for ( int i = 0; i < N; i++ ) { std::getline(std::cin, grid[i]); }
    for ( int w = 0; w < W; w++ ) { std::getline(std::cin, wrds[w]); }

    for ( auto& it : findWords(grid, wrds, N, M) ) { std::cout << it << std::endl; }
    return 0;
}