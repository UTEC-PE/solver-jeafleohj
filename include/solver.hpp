#ifndef SOLVER_HPP
#define SOLVER_HPP
#include <iostream>
#include <cstring>
#include <cstdlib>
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
};

class Solver{
	enum class type {numero, variable, parleft, parrigth,
					 invalid, suma, resta, potencia, multiplicacion,
					 division};
	Node* root;
	type filter(char c){
		if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' )
			return type::variable;
		else if( c == '(')
			return type::parleft;
		else if( c == ')')
			return type::parrigth;
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
public:
	Solver(char * str);
};

Solver::Solver(char* str){
	filter('s');
	int size = strlen(str);
	for(int i=0; i<size; i++){
		type check = filter(str[i]);
		if( check == type::invalid ){
			std::cout << "Invalid expresion" << "\n";
			//root->killSelf();
			break;
		}
		Node* tmp;
		if( check == type::numero){
			int buffer = str[i]-'0';
			int j=i+1;
			while( j<size && filter(str[j]) == type::numero ){
				buffer*=10 + str[i]-'0';
				j++;
			}
			tmp = new NodeTree<Integer>(buffer);
			i = j-1;
		}else{
			tmp = new NodeTree<Character>(str[i]);
		}
	}
}

#endif
