#ifndef NODE_HPP
#define NODE_HPP

struct Node{
	Node(){
		left = right = nullptr;
	}
	Node(Node* l, Node* r)
		: left(l), right(r)
	{};
	virtual void killSelf()=0;
	virtual void printSelf()=0;
	virtual ~Node()=0;
	Node* left, *right;
};
Node::~Node(){
	delete right;
	delete left;
}
#endif
