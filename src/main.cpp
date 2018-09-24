#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "parser.hpp"
#include "ast.hpp"


using namespace std;
void menu() {
      system("clear");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      //char* str="7/4*((a+b)*a)+3";
      //char* str="7/4*((a+-+--b)*a)+3";
      //char* str="2+(3)";
      //char* str="7/4*((a+b)^4*a)+3";
}


int main(int argc, char const *argv[]) {
	map<string, double> var;
	string s ;
	cout << "Ingrese una expression" << "\n";
	cin>>s;
	Parser i(s);
	AST* p;
	i.getData(p,var);
	if( var.empty()){
		cout << p->eval()  << "\n";		
	}else{
		for (auto it = var.begin(); it != var.end(); ++it) {
			double v ;
			cout << "Ingrese un valor para la variable \'"<<it->first<<"\'\n";
			cin>>v;
			var[it->first] = v;
		}
		cout << p->eval(var)  << "\n";		
	}
}

