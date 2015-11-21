#include <stdio.h>
#include <fstream>
#include "weighter.h"

int main(){
	int cmd;
	int m;
	weight pribor;
	while(true){
		printf("1. Dobavit' ves.\n");
		printf("2. Ubavit' ves.\n");
		printf("3. Vivesti tekushii ves.\n");
		printf("4. Vivesti kolichestvo predmetov.\n");
		printf("5. Prochitat' fayl.\n");
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
		else if(cmd == 5){
            char name[256];
            printf("Vvedite imya fayla: ");
            scanf("%s", name);
            ifstream fp(name);
            while(!fp.eof()){
                fp >> m;
                if(m > 0) pribor.change(m);
                else pribor.change(-m);
            }
            fp.close();
		}
		else printf("Vi vveli nekorrektnie dannie.\n");
	}
}
