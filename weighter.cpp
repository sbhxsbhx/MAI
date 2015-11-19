#include "weighter.h"

using namespace std;

model::model(){ m1 = 0;  m2 = 0;  m3 = 0; }

void model::put(int d){
    if(d == 2) m1++;
    else if(d == 3) m2++;
    else if(d == 5) m3++;
}

void model::printModel(){
	printf("m1 - %d\n", m1);
	printf("m2 - %d\n", m2);
	printf("m3 - %d\n\n", m3);
}

bool model::remove(int d){
	if((d == 2) && (m1 > 0)){ m1--; return true; }
	else if((d == 3) && (m2 > 0)){ m2--; return true; }
	else if((d == 5) && (m3 > 0)){ m3--; return true; }
	return false;
}


weight::weight(){ mass = 0; }

int weight::returnMass(){ return mass; }

void weight::printModel(){
	obj.printModel();
}

void weight::change(int Dm){
	bool rez = true;
	if(Dm > 0) obj.put(Dm);
	else rez = obj.remove(-Dm);
	if(rez){
		hist newH;
		newH.t = history.size()+1;
		newH.m = mass;
        newH.Dm = Dm;
		history.push_back(newH);
		mass += Dm;
	}
	else printf("Takogo predmeta net.\n");
}

weight::~weight(){ mass = 0; }
