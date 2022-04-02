#include "StackNode.h"

StackNode::StackNode(int large){
	StackNode::Nodes = new Node*[large];
	StackNode::large = large;
	StackNode::position = -1;
}

StackNode::~StackNode(){
	delete[] Nodes;
}

void StackNode::push(Node *newNode){
	position++;
	Nodes[position] = newNode;
}

void StackNode::pop(){
	if(isEmpty()){
		return;
	}
	Nodes[position] = NULL;
	position --;
}

Node* StackNode::top(){
	return Nodes[position];
}

bool StackNode::isEmpty(){
	return position == -1;
}