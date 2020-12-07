#include "bits/stdc++.h"

using namespace std;


int main() {
	int n;
	int m_len, c_len, last;
	cin >> n;
	m_len = c_len = last = 0;
	
	for(int i = 0; i < n;i++){
		int tmp;
		cin >> tmp;

		if (tmp < last) { // Seq ended
			if (c_len > m_len) {
				m_len = c_len;
			}
			c_len = 0;
		}
		c_len++;
		last = tmp;
	}

	if ( c_len >  m_len)
		m_len = c_len;

	cout << m_len;
	return 0;
}
