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
	// Prueba con la siguiente ecuación: (17*3/2-a)^b    a=5, b=1
	/**

Revisa esta parte, está sumando en vez de restar

Ingrese una expression
17*3/2
25.5
Ingrese una expression
17*3/2-5
30.5

-(5-4) y -(5+4) dan el mismo resultado,
parece ser un tema de paréntesis o unarios
	 
	 */
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

