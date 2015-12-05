#include <stdio.h>
#include <fstream>
#include "weighter.h"

int TodayHist = 0;

void PrintAllHist(hist StrOfHist){
    printf("| t = %3d | Dm = %3d | m = %3d |\n", StrOfHist.t, StrOfHist.Dm, StrOfHist.m);
}

void PrintTwoHist(hist StrOfHist){
    if(StrOfHist.Dm%2 == 0)
        printf("| t = %3d | Dm = %3d | m = %3d |\n", StrOfHist.t, StrOfHist.Dm, StrOfHist.m);
}

void PrintTodayHist(hist StrOfHist){
    if(StrOfHist.t > TodayHist)
        printf("| t = %3d | Dm = %3d | m = %3d |\n", StrOfHist.t, StrOfHist.Dm, StrOfHist.m);
}

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
		printf("6. Initsializirovat' istoriyu.\n");
		printf("7. Vivesti vse na ekran.\n");
		printf("8. Vivesti vse predmeti s chetnoy massoy na ekran.\n");
		printf("9. Vivesti isturiyu za segodnya.\n");
		printf("0. Exit\n\n\n");
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
		else if(cmd == 3)
            printf("Tekushaya massa %d\n\n", pribor.returnMass());
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
		else if(cmd == 6)
            TodayHist = pribor.InitHist();
		else if(cmd == 7)
            pribor.PrintHist(PrintAllHist);
		else if(cmd == 8)
            pribor.PrintHist(PrintTwoHist);
		else if(cmd == 9)
            pribor.PrintHist(PrintTodayHist);
		else return 0;
		///else printf("Vi vveli nekorrektnie dannie.\n");
	}
}
