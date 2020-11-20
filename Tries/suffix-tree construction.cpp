#include <unordered_map>
using namespace std;

class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
  TrieNode *root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieFrom(string str) {
        char c;
    for ( int i = 0; i < str.size(); i++ )
        {
            TrieNode* cur = root;
            for ( int j = i; j < str.size(); j++ )
            {
                c = str[j];
                if ( (cur->children.find(c) == cur->children.end()) ||
                     !cur->children[c] ) { cur->children[c] = new TrieNode(); }
                cur = cur->children[c];
            }
            cur->children[endSymbol] = nullptr;
        }
  }

  bool contains(string str) {
        TrieNode* cur = root;
    for ( auto& c : str )
        {
            if ( cur->children.find(c) == cur->children.end() ) { return false; }
            cur = cur->children[c];
        }
    return cur->children.find(endSymbol) != cur->children.end();
  }
};
