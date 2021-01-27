using namespace std;

class MinMaxStack {
public:
    // O(1) time | O(1) space
  int peek() { return m_stack.back(); } // undefined behaviour if empty tho

    // O(1) time | O(1) space
  int pop() {
        int l_val { m_stack.back() };
        m_stack.pop_back();
        m_minMax.pop_back();
    return l_val;
  }

    // O(1) time | O(1) space
  void push(int p_val) {
        std::pair<int, int> l_val{p_val, p_val};
        if ( !std::empty(m_minMax) ) { 
            l_val.first  = std::min( l_val.first , m_minMax.back().first  );
            l_val.second = std::max( l_val.second, m_minMax.back().second );
        }
        m_stack.push_back(p_val);
        m_minMax.push_back( l_val );
  }

    // O(1) time | O(1) space
  int getMin() { return m_minMax.back().first;  } // undefined behaviour if empty tho
  int getMax() { return m_minMax.back().second; } // undefined behaviour if empty tho
    
private:
    std::vector<int>                   m_stack{};
    std::vector< std::pair<int, int> > m_minMax{};
};
