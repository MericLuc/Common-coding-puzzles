#include <vector>
#include <climits>
#include <algorithm>

std::vector<std::vector<int>> maxIncSubSeq(std::vector<int> m) {
	std::vector<int>              seqs(m.size(), INT_MIN), sums(m);
	std::vector<std::vector<int>> res = {{}, {}};
	for ( int i = 0; i < m.size(); i++ )
		for ( int j = 0; j < i; j++ )
			if ( m[j] < m[i] && sums[j] + m[i] >= sums[i] ) { 
				sums[i] = sums[j] + m[i];
				seqs[i] = j;
			}
	auto maxElt(std::max_element(std::begin(sums), std::end(sums)));
	int  maxIdx(std::distance(std::begin(sums), maxElt));
	res[0].push_back(*maxElt);
	
	while( maxIdx != INT_MIN) { 
		res[1].insert(res[1].begin(), m[maxIdx]);
		maxIdx = seqs[maxIdx];
	}
	return res;
}