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
		//Print inorder
		if(left){
			left->printSelf();
		}
		if(right){
			right->printSelf();
		}
		std::cout << value  << "\n";
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

class Number: public NodeTree<Integer>{

public:
	Number(Token t)
		: NodeTree<Integer>(t)
	{
		NodeTree<Integer>::value = stoi(t.value);
	};
	~Number(){
		
	}
};

#endif
