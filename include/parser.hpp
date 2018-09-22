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

	int factor();
	int term();
public:
	Parser(Lexer lexer)
		: lex(lexer), token(lex.next_token())
	{};
	Parser(std::string t)
		: token(lex.next_token()), lex(t)
	{};
	int expression();
		  
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

int Parser::factor(){
	std::string val = token.value;
	if( token.kind == type::number ){
		consume(type::number);
		return stoi(val);
	}
	else if(token.kind == type::lpar) {
		consume(type::lpar);
		int r = expression();
		consume(type::rpar);
		return r;
	}

	return 1;
}

int Parser::term(){
	int r = factor();
	while( token.kind == type::multiplication || token.kind == type::division ){
		if( token.kind == type::multiplication ){
			consume(type::multiplication);
			r = r * factor();
		}else if( token.kind == type::division ){
			consume(type::division);
			r = r / factor();
		}
	}
	return r;
}

int Parser::expression(){
	//Arithmetic expression parser / interpreter
	int r = term();
	while ( token.kind == type::minus || token.kind == type::plus) {
		if( token.kind == type::plus){
			consume(type::plus);
			r = term() + r;
		}else if(token.kind == type::minus){
			consume(type::minus);
			r = r - term();
		}
	}
	return r;
}
#endif
