#ifndef AST_HPP
#define AST_HPP
#include "node.hpp"
#include "token.hpp"

typedef Node AST;

struct Character{
	typedef char T;
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

template <typename ST>
class BinaryOperator: public NodeTree<ST>{
	//Testing, talvez sea mejor un char
	Token op;
public:
	BinaryOperator(AST* l, Token t, AST* r)
		: NodeTree<ST>(t, l, r), op(t)
	{}

};

template <typename ST>
class Number: public NodeTree<ST>{

public:
	Number(Token t)
		: NodeTree<ST>(t)
	{
		NodeTree<ST>::value = stoi(t.value);
	};
};

#endif
