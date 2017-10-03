// ConnComp.h
#ifndef CONNCOMP_H
#define CONNCOMP_H
#include <vector>
#include <algorithm>

using std::vector;

class ConnComp {
public:
	ConnComp(int);
	~ConnComp();
	void processPair(int, int);
	int getMax(void) const;
private:
	vector<int> id_;
	vector<int> size_;
	int findRoot(int);
	void unionComps(int, int);
	
};

#endif

