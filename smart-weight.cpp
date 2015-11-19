#include <stdio.h>
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
