#ifndef TOKEN_HPP
#define TOKEN_HPP

enum class type {
				 variable,plus, minus, multiplication, exponentiation,
				 division, number, lpar, rpar, EMPTY, END
};

struct Token {
	type kind;
	std::string value;
	Token(){
		kind = type::EMPTY;
		value = "";
	}
	Token(type t, std::string v)
		: kind(t), value(v)
	{};
	Token(type t, char v)
		: kind(t)
	{
		value = v;
	};
	Token(const Token &t)
		: kind(t.kind), value(t.value)
	{}
	Token operator=(const Token &t){
		kind = t.kind;
		value = t.value;
		return *this;
	}
};

#endif
