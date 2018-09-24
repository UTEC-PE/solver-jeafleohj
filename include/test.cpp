/*
 * file: test.cpp
 * author: Jhony Angulo
 * date: 19-09-2018
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "parser.hpp"
#include "ast.hpp"
using namespace std;
int main(){
	map<string, double> var;
	string s = " (7 + (((3 +---+- 2))) * 5 +7) / -b";
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
