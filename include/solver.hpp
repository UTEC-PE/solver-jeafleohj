#ifndef SOLVER_HPP
#define SOLVER_HPP
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>

struct Character{
	typedef char T;
};

struct Integer{
	typedef int T;
};

struct Node{
	Node(){
		left = right = nullptr;
	}
	virtual void killSelf()=0;
	virtual void printSelf()=0;
	virtual ~Node()=0;

	Node* left, *right;
};


template <typename ST>
struct NodeTree : public Node{
	typedef typename ST::T T;
	T data;
	NodeTree(T data) : Node(), data(data)
	{};
	void killSelf(){
		if(left){
			left->killSelf();
		}
		if(right){
			right->killSelf();
		}
		delete this;
	}
	void printSelf(){
		//Print inorder
		if(left){
			left->printSelf();
		}
		if(right){
			right->printSelf();
		}
		std::cout << data  << "\n";
	}
	~NodeTree(){
		killSelf();
	}
};

class Solver{
	enum class type {numero, variable, lpar, rpar,
					 invalid, suma, resta, potencia, multiplicacion,
					 division};
	Node* root;
	std::map<char, int> variables;
	//void cancelOperation(str *str, int &i, int size, bool& signo);
	void toStack();
	void toTree();
	int power(int a, int x);
	type filter(char c);
public:
	Solver(char * str);
	~Solver(){
		//Todo
	}
};

Solver::Solver(char* str){
	int size = strlen(str);
	int parentesis = 0;
	for(int i=0; i<size; i++){
		type check = filter(str[i]);
		if( check == type::invalid ){
			std::cout << "Invalid expresion" << "\n";
			//root->killSelf();
			break;
		}
		if( check == type::lpar ){
			parentesis++;
			continue;
		}else if( check == type::rpar ){
			parentesis--;
			continue;
		}
		Node* tmp;
		if( check == type::numero ){
			int buffer = str[i]-'0';
			int j=i+1;
			while( j<size && filter(str[j]) == type::numero ){
				buffer*=10 + str[i]-'0';
				j++;
			}
			tmp = new NodeTree<Integer>(buffer);
			i = j-1;
		}else if( check == type::variable ){
			variables[str[i]];
		}else if( check == type::suma || check == type::resta ){
			bool signo = check == type::suma ? true : false;
			//cancelOperation(str, i, size, signo);
			if( signo ) tmp = new NodeTree<Character>('+');
			else tmp = new NodeTree<Character>('-');
		}else{
			tmp = new NodeTree<Character>(str[i]);
		}
		
		if( root == nullptr ){
			root = tmp;
		}else{
			if( parentesis ){
				
			}else{

			}
		}
	}
}
//void Solver::cancelOperation(str *str, int &i, int size, bool& signo){
//	for(int k=1; k<size-i; k++){
//		if( str[k] == type::resta ) {
//			signo = !signo;
//		}
//	}
//	i = --k;
//}
int Solver::power(int a, int x){
	if( a == 0 ) return 1;
	int a2 = power(a, x>>1);
	if( x&1 ) return a2*a2;
	return a2*a2*a;
}
Solver::type Solver::filter(char c){
		if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' )
			return type::variable;
		else if( c == '(')
			return type::lpar;
		else if( c == ')')
			return type::rpar;
		else if( c == '+' )
			return type::suma;
		else if( c == '-' )
			return type::resta;
		else if( c == '^' )
			return type::potencia;
		else if( c == '*' )
			return type::multiplicacion;
		else if( c == '/' )
			return type::division;
		else if( c >= '0' && c <= '9')
			return type::numero;
		return type::invalid;
};
#endif
