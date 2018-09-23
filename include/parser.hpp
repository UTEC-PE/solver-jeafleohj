#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>

#include "token.hpp"
#include "lexer.hpp"
#include "ast.hpp"

class Parser{
	Lexer lex;
	Token token;

	void error(std::string msg);
	void next_token();
	void consume(type t);

	AST* factor();
	AST* term();
public:
	Parser(Lexer lexer)
		: lex(lexer), token(lexer.next_token())
	{};
	Parser(std::string t)
		:  lex(t)
	{
		token = lex.next_token();
	};
	AST* expression();
		  
};
void Parser::error(std::string msg){
	std::cout<<"Error: "<<msg<<std::endl;
}

void Parser::consume(type t){
	if( token.kind == t ){
		token = lex.next_token();
	}else{
		error("Token: "+token.value+ " is not the desired");
	}
}

AST* Parser::factor(){
	AST* nodo = nullptr;
	if( token.kind == type::number ){
		nodo = new Number(token);
		consume(type::number);
		return nodo;
	}
	else if(token.kind == type::lpar) {
		consume(type::lpar);
		nodo = expression();
		consume(type::rpar);
		return nodo;
	}
	return nodo;
}

AST* Parser::term(){
	AST* nodo = factor();
	while( token.kind == type::multiplication || token.kind == type::division ){
		Token t = token;
		if( t.kind == type::multiplication ){
			consume(type::multiplication);
		}else if( t.kind == type::division ){
			consume(type::division);
		}

		nodo = new BinaryOperator(nodo, t, factor());
	}
	return nodo;
}

AST* Parser::expression(){
	//Arithmetic expression parser / interpreter
	AST* nodo = term();
	while ( token.kind == type::minus || token.kind == type::plus) {
		Token t = token;
		if( t.kind == type::plus){
			consume(type::plus);
		}else if(t.kind == type::minus){
			consume(type::minus);
		}
		nodo = new BinaryOperator(nodo, t, term());
	}
	return nodo;
}
#endif
