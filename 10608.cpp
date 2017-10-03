// main.cpp
#include <iostream>
#include "ConnComp.h"

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	int numData, numComp, numPairs;

	cin >> numData;

	for(int n=0; n<numData; ++n) {
		cin >> numComp >> numPairs;
		ConnComp *cc = new ConnComp(numComp);
		int i, j;
		for(int p=0; p<numPairs; ++p) {
			cin >> i >> j;
			cc->processPair(i, j);
		}
		cout << cc->getMax() << endl;
		delete cc;
	}

	return 0;
}

