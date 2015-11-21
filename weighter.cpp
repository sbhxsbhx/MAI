#include "weighter.h"

using namespace std;

model::model(){
    ifstream cfg("iweight.cfg");
    string name;
    int m;
    while(!cfg.eof()){
        cfg >> m >> name;
        mass[name] = m;
        number[name] = 0;
    }
    cfg.close();
}

bool model::put(int d){
    map<string, int>::iterator iter = mass.begin();
    while(iter!=mass.end()){
        if(d == iter->second){
            number[iter->first]++;
            return true;
        }
        iter++;
    }
    return false;
}

void model::printModel(){
    map<string, int>::iterator iter = mass.begin();
    while(iter!=mass.end()){
        cout << iter->first << " - " << number[iter->first] << endl;
        iter++;
    }
}

bool model::remove(int d){
    map<string, int>::iterator iter = mass.begin();
    while(iter!=mass.end()){
        if((d == iter->second) && (number[iter->first] > 0)){ number[iter->first]--; return true; }
        iter++;
    }
	return false;
}

model::~model(){
    map<string, int>::iterator iter = mass.begin();
    while(iter!=mass.end()){
        number.erase(iter->first);
        mass.erase((iter++)->first);
    }
}

weight::weight(){
    mass = 0;
    fhist = fopen("history.hist", "w");
}

int weight::returnMass(){ return mass; }

void weight::printModel(){
	obj.printModel();
}

void weight::change(int Dm){
	bool rez = true;
	if(Dm > 0) rez = obj.put(Dm);
	else rez = obj.remove(-Dm);
	if(rez){
		hist newH;
		newH.t = history.size()+1;
		newH.m = mass;
        newH.Dm = Dm;
		history.push_back(newH);
		mass += Dm;

		// write to file
		fprintf(fhist, "%d %d %d\n", newH.t, newH.Dm, newH.m);
		map<string, int>::iterator iter = number.begin();
        while(iter!=number.end()){
            fprintf(fhist, "%d ", number[iter->first]);
            iter++;
        }
        fprintf(fhist, "\n");
	}
	else printf("Takogo predmeta net.\n");
}

weight::~weight(){
    mass = 0;
    fclose(fhist);
}
