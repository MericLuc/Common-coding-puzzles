/*!
 * @brief Multi string search using Trie class.
 */

#include <vector>
#include <memory>

template < typename T >
using PTR = std::unique_ptr<T>;

class Node  {
    public:
        bool  has     (char c) const { return m_children[c] != nullptr; }
        void  add     (char c) { if( !has(c) ) m_children[c] = std::make_unique<Node>(); }
        Node* getChild(char c) { return has(c) ? m_children[c].get() : nullptr; }
    
    private:
        std::vector<PTR<Node>>  m_children{255};
};

class Trie {
    public: 
        explicit Trie(const std::string& p_str = "") { insert(p_str); }
    
        void insert(const std::string& p_str) {         
            for ( int i = 0; i < std::size(p_str); ++i ) {
                Node* curNode { m_root.get() };
                for ( int j = i; j < std::size(p_str); ++j ) {
                    curNode->add(p_str[j]);
                    curNode = curNode->getChild(p_str[j]);
                }
            }
        }
    
        bool contains(const std::string& p_str) {
            Node* curNode { m_root.get() };
            for ( const auto& c : p_str )
                if ( curNode = curNode->getChild(c); !curNode ) return false;
            return true;
        }
    
    private:
        PTR<Node> m_root{ new Node() };
};

std::vector<bool> multiStringSearch(std::string              bigString, 
                                    std::vector<std::string> smallStrings) {
  std::vector<bool> ret;
    Trie myTrie{ bigString };
    
    for ( const auto& curStr : smallStrings ) ret.push_back( myTrie.contains( curStr ) );
  return ret;
}