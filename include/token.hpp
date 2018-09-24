#ifndef TOKEN_HPP
#define TOKEN_HPP

enum class type : char{
					   variable = 'v',
					   plus = '+',
					   minus = '-',
					   multiplication = 'x',
					   exponentiation = '^',
					   division = '/',
					   number = 'n',
					   lpar = '(',
					   rpar = ')',
					   uplus = 's',
					   uminus = 'r',
					   EMPTY,
					   END
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
