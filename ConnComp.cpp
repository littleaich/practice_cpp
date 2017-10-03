// ConnComp.cpp
#include "ConnComp.h"
//#include <iostream>

ConnComp::ConnComp(int sz)
{
//	id_.resize(sz); // causes deallocation problem
//	size_.resize(sz, 1);
	for(int i=0; i<sz; ++i) {
	//	id_[i] = i;
		id_.push_back(i);
		size_.push_back(1);
	}	
}

ConnComp::~ConnComp()
{

}

int ConnComp::getMax(void) const 
{
	return *std::max_element(size_.begin(), size_.end());
}

void ConnComp::processPair(int id1, int id2) 
{
	this->unionComps(id1, id2);
//	std::cout << "processed = " << id1 << " " << id2 << std::endl;
	
}

void ConnComp::unionComps(int id1, int id2)
{
	int root1 = findRoot(id1);
	int root2 = findRoot(id2);
	if(root1 == root2) return;
	if(size_[root1] > size_[root2]) {// tree 1 greater
		size_[root1] += size_[root2];
		id_[root2] = root1;
	}
	else {
		size_[root2] += size_[root1];
		id_[root1] = root2;
	}
}

int ConnComp::findRoot(int p)
{	
	int i;
	for(i=p; i != id_[i]; i = id_[i]) {
		int t = i;
		i = id_[id_[t]];
		id_[t] = i;
	}
	return i;
}

