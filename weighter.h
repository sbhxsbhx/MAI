#ifndef weighter_h_
#define weighter_h_

#include <stdio.h>
#include <vector>

using namespace std;

struct hist{
	int t;
	int m;
	int Dm;
};

class model{
private:
	int m1, m2, m3;
public:
	model();
	void put(int d);
	void printModel();
	bool remove(int d);
};

class weight{
private:
	vector<hist> history;
	int mass;
	model obj;
public:
	weight();
	int returnMass();
	void printModel();
	void change(int Dm);
	~weight();
};

#endif // weighter_h_
