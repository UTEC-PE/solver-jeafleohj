#ifndef LEXER_HPP
#define LEXER_HPP
#include <string>
#include "token.hpp"

class Lexer{
	std::string text;
	int pos;
	char cchar;
	std::string number();
	void error(std:: string msg);
	void advance();
	void skip_space();

public:
	Lexer(std::string txt):
		text(txt), pos(0), cchar(txt[0])
	{};
	Lexer(const Lexer &lexer)
		: Lexer(lexer.text)
	{};
	Token next_token();
};
void Lexer::error(std::string msg){
	std::cout << msg << "\n";
}
void Lexer::advance(){
	if( ++pos > text.size() -1 ){
		cchar = '\0';
	}else{
		cchar = text[pos];
	}
}

void Lexer::skip_space(){
	while( cchar != '\0' && cchar == ' ' ){
		advance();
	}	
}

std::string Lexer::number(){
	std::string n = "";
	while( cchar !='\0' && cchar >= '0' && cchar <='9'){
		n += cchar;
		advance();
	}
	return n;
}

Token Lexer::next_token(){
	while( cchar != '\0'){
		if( cchar == ' '){
			skip_space();
			continue;
		}
		if( cchar >= '0' && cchar <= '9'){
			return Token(type::number, number());
		}
		if( cchar == '+' ){
			advance();
			return Token(type::plus, '+');
		}
		if( cchar == '-'){
			advance();
			return Token(type::minus, '-');
		}
		if( cchar == '*'){
			advance();
			return Token(type::multiplication, '*');
		}
		if( cchar == '/'){
			advance();
			return Token(type::division, '/');
		}
		if( cchar == '^'){
			advance();
			return Token(type::exponentiation, '^');
		}
		if( cchar == '('){
			advance();
			return Token(type::lpar, '(');
		}
		if( cchar == ')'){
			advance();
			return Token(type::rpar, ')');
		}
		if( cchar >= 'a' && cchar <= 'z' ||
			cchar >= 'A' && cchar <= 'Z'
			){
			char c = cchar;
			advance();
			return Token(type::variable, c);
		}
		error("Token not valid");
	}
	//error("Expression's end");
	return Token(type::END, '\0');
}
#endif
