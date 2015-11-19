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
	model(){ m1 = 0;  m2 = 0;  m3 = 0; }
	
	void put(int d){
		if(d == 2) m1++;
		else if(d == 3) m2++;
		else if(d == 5) m3++;
	}

	void printModel(){
		printf("m1 - %d\n", m1);
		printf("m2 - %d\n", m2);
		printf("m3 - %d\n\n", m3);
	}

	bool remove(int d){
		if((d == 2) && (m1 > 0)){ m1--; return true; }
		else if((d == 3) && (m2 > 0)){ m2--; return true; }
		else if((d == 5) && (m3 > 0)){ m3--; return true; }
		return false;
	}
};

class weight{
private:
	vector<hist> history;
	int mass;
	model obj;
public:
	weight(){ mass = 0; }

	int returnMass(){ return mass; }

	void printModel(){
		obj.printModel();
	}

	void change(int Dm){
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

	~weight(){ mass = 0; }
};


int main(){
	int cmd;
	int m;
	weight pribor;
	while(true){
		printf("1. Dobavit' ves.\n");
		printf("2. Ubavit' ves.\n");
		printf("3. Vivesti tekushii ves.\n");
		printf("4. Vivesti kolichestvo predmetov.\n");
		scanf(" %d", &cmd);
		if(cmd == 1){
			printf("Vvedite massu: ");
			scanf(" %d", &m);
			pribor.change(m);
		}
		else if(cmd == 2){
			printf("Vvedite massu: ");
			scanf(" %d", &m);
			pribor.change(-m);
		}
		else if(cmd == 3) printf("Tekushaya massa %d\n\n", pribor.returnMass());
		else if(cmd == 4){
			printf("Kolichestvo predmetov:\n");
			pribor.printModel();
		}
		else printf("Vi vveli nekorrektnie dannie.\n");
	}
}
