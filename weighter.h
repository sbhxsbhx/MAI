#ifndef weighter_h_
#define weighter_h_

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct hist{
	int t;
	int m;
	int Dm;
};

class model{
private:
	map<string, int> mass;
public:
	map<string, int> number;
	model();
	bool put(int d);
	void printModel();
	bool remove(int d);
	~model();
};

class weight{
private:
	vector<hist> history;
	int mass;
	model obj;
public:
	weight();
	void InitHist();
	int returnMass();
	void printModel();
	void change(int Dm);
	~weight();
};

#endif // weighter_h_
