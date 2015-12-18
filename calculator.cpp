#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

string load(char *fname, string (*func)(char *arg)){
    return func(fname);
}

int calc(string formula, int (*func)(string arg)){
    return func(formula);
}

void showRezult(int val, void (*func)(int arg)){
    func(val);
}

string someFunc(char *someArg){
    string rez;
    ifstream File(someArg);
    getline(File, rez);
    if(rez[rez.length()] != ' ')
       rez = rez + " ";
    File.close();
    return rez;
}

string TestSomeFunc(char *someArg){
    string rez = "7 1 2 + - ";
    return rez;
}

int MyDivide(int &a, int &b){
    return a/b;
}
int MyMult(int &a, int &b){
    return a*b;
}
int MyMinus(int &a, int &b){
    return a-b;
}
int MyPlus(int &a, int &b){
    return a+b;
}

int someCalc(string arg){ /// something is not normal
    int (*oper[4])(int&a, int&b) = {MyDivide, MyMult, MyMinus, MyPlus};
    vector<int> numbers;
    char num[256];
    int buf;
    int i = 0, m = 0;
    while(arg[i]!='\0'){
        num[m++] = arg[i++];
        if(arg[i] == ' '){
            if(num[0] == '+')
                numbers.push_back(-1);
            else if(num[0] == '-')
                numbers.push_back(-2);
            else if(num[0] == '*')
                numbers.push_back(-3);
            else if(num[0] == '/')
                numbers.push_back(-4);
            else{
                buf = atoi(num);
                numbers.push_back(buf);
            }
            m = 0;
            i++;
        }
    }
    ///for(int i = 0; i < numbers.size(); i++){ cout << numbers[i] << endl;}
    //for(int j = 0; j < numbers.size(); j++){ cout << numbers[j] << endl;}
    //cout << endl;

    ///(numbers.size()+1)/2+1
    while(numbers.size() > 2){
        //for(int j = 0; j < numbers.size(); j++){ cout << numbers[j] << endl;}
        i = (numbers.size()+1)/2;
        if(numbers[i]<0){
            numbers[i-2] = (*oper[numbers[i]+4])(numbers.at(i-2), numbers.at(i-1));
            numbers.erase(numbers.begin()+i);
            numbers.erase(numbers.begin()+i-1);
        }
        else
            return 0; /// Error
        //for(int j = 0; j < numbers.size(); j++){ cout << numbers[j] << endl;}
    }
    return numbers[0];
}

void someCout(int something){
    cout << endl << something;
}

int main(){
    char someTXT[] = "CalcExample.txt";
    showRezult(calc(load(someTXT, someFunc), someCalc), someCout);
    start: goto start;
}
