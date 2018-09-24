#ifndef AST_HPP
#define AST_HPP

#include <string>
#include "node.hpp"
#include "token.hpp"

typedef Node AST;

struct Character{
	typedef std::string T;
};

struct Integer{
	typedef int T;
};

template <typename ST>
struct NodeTree : public AST{
	typedef typename ST::T T;
	T value;
	Token token;
	NodeTree(Token token) : AST(), token(token)
	{};
	NodeTree(Token token, AST* l, AST* r) : AST(l,r), token(token)
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
		std::cout << value  << "\n";	
		if(left){
			left->printSelf();
		}
		if(right){
			right->printSelf();
		}

	}
	double eval(){
		if( token.kind == type::number ){
			return stoi(value);
		}else{
			double tmpval;
			switch( token.kind ){
				case type::plus:
					tmpval = 0;
					if(left) tmpval += left->eval();
					if(right) tmpval += right->eval();
					break;
				case type::minus:
					tmpval = 0;
					if(left) tmpval -= left->eval();
					if(right) tmpval = right->eval() - tmpval;
					break;
				case type::multiplication:
					tmpval = 1;
					if(left) tmpval *= left->eval();
					if(right) tmpval *= right->eval();
					break;
				case type::division:
					tmpval = 1;
					if(left) tmpval = left->eval()/ tmpval;;
					if(right) tmpval /= right->eval(); 
					break;
			}
			return tmpval;
		}
	}
	~NodeTree(){
		killSelf();
	}
};

class BinaryOperator: public NodeTree<Character>{
	//Testing, talvez sea mejor un char
	Token op;
public:
	BinaryOperator(AST* l, Token t, AST* r)
		: NodeTree<Character>(t, l, r), op(t)
	{
		NodeTree<Character>::value = t.value;
	}
	~BinaryOperator(){
		
	}
};

class Number: public NodeTree<Character>{

public:
	Number(Token t)
		: NodeTree<Character>(t)
	{
		NodeTree<Character>::value = t.value;
	};
	~Number(){
		
	}
};

#endif
