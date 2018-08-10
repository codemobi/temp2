// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	node_data = data;
	prev_ptr = nullptr;
	next_ptr = nullptr;
	return;
}

char Node::GetData() {

  return node_data ;
}

Node* Node::GetPreviousNode() {

  return prev_ptr;
}

Node* Node::GetNextNode() {
  return next_ptr;
}

Node* Node::InsertPreviousNode(char data) {
	Node * node = new Node(data);
	if (prev_ptr != nullptr) {
		prev_ptr->next_ptr = node;
		node->prev_ptr = prev_ptr;
		node->next_ptr = this;
		prev_ptr = node;
	}
	else { // nullptr
		prev_ptr = node;
		node->next_ptr = this;
	}
	return node;
}

Node* Node::InsertNextNode(char data) {
	Node * node = new Node(data);
	if (next_ptr != nullptr) {
		next_ptr->prev_ptr = node;
		node->next_ptr = next_ptr;
		node->prev_ptr = this;
		next_ptr = node;
	}
	else { // nullptr
		next_ptr = node;
		node->prev_ptr = this;

	}
	return node;
}

bool Node::ErasePreviousNode() {
	Node *temp_ptr ;
	if (prev_ptr != nullptr) {
		temp_ptr = prev_ptr;
		
		prev_ptr = prev_ptr->prev_ptr;
		if (prev_ptr != nullptr) prev_ptr->next_ptr = this;
		
		delete temp_ptr;
		return true;
	}

	return false;
}

bool Node::EraseNextNode() {
	Node *temp_ptr;
	if (next_ptr != nullptr) {
		temp_ptr = next_ptr;

		next_ptr = next_ptr->next_ptr;
		if (next_ptr != nullptr) next_ptr->prev_ptr = this;

		delete temp_ptr;
		return true;
	}

	return false;
}
