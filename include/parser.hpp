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
		: lex(lexer), token(lex.next_token())
	{};
	Parser(std::string t)
		: token(lex.next_token()), lex(t)
	{};
	AST* expression();
		  
};
void Parser::error(std::string msg){
	std::cout<<"Error: "<<msg<<std::endl;
}

void Parser::consume(type t){
	if( token.kind == t ){
		token = lex.next_token();
	}else{
		error("Token is not the desired: "+token.value);
	}
}

AST* Parser::factor(){
	AST* nodo;
	std::string val = token.value;
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

	return nullptr;
}

AST* Parser::term(){
	AST* nodo = factor();
	while( token.kind == type::multiplication || token.kind == type::division ){
		nodo = new BinaryOperator(nodo, token, factor());
		if( token.kind == type::multiplication ){
			consume(type::multiplication);
		}else if( token.kind == type::division ){
			consume(type::division);
		}
	
	}
	return nodo;
}

AST* Parser::expression(){
	//Arithmetic expression parser / interpreter
	AST* nodo = term();
	while ( token.kind == type::minus || token.kind == type::plus) {
		nodo = new BinaryOperator(nodo, token, factor());
		if( token.kind == type::plus){
			consume(type::plus);
		}else if(token.kind == type::minus){
			consume(type::minus);
		}

	}
	return nodo;
}
#endif
