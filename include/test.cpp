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
	string s = " 7 + (((3 + 2)))";
	Parser i(s);
	AST* p = i.expression();
	p->printSelf();
}
