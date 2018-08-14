// Copyright 2018 <Author>

#include "typing_machine.h"
#include <string>

TypingMachine::TypingMachine() {
	root = cursor = new Node(0);
	head = tail = nullptr;
	str_length = 0;

  return;
}

void TypingMachine::HomeKey() {
	cursor = root;
  return;
}

void TypingMachine::EndKey() {
	cursor = tail;
  return;
}

void TypingMachine::LeftKey() {
	if (cursor == root) return;

	Node *n = cursor->GetPreviousNode();
	if (n != nullptr)
		cursor = n;
  return;
}

void TypingMachine::RightKey() {
	Node *n = cursor->GetNextNode();
	if (n != nullptr)
		cursor = n;
	return;
}

bool TypingMachine::TypeKey(char key) {
//	if (key !=8 && (key < 32 || key > 126)) return false;
	if (key < 32 || key > 126) return false;
	if (str_length == 100) return false;
	str_length++;

	Node *n;
	if (cursor == root)
	{
		n = root->InsertNextNode(key);
		head=cursor = n;
		if (tail == nullptr)
			tail = n;
	}
	else
	{
		n = cursor->InsertNextNode(key);
		if (tail == cursor) tail = n;
		cursor = n;

	}

  return true;
}

bool TypingMachine::EraseKey() {
	
	Node * n;
	if (cursor == root) 
		return false;
	else
	{
		if (cursor == head)
		{
			if (head == tail)
			{
				head = tail = nullptr;
				root->EraseNextNode();
				cursor = root;
			}
			else // head != tail
			{
				head = head->GetNextNode();
				cursor = root;

				root->EraseNextNode();

			}
		}
		else // cursor != head
		{
			n = cursor->GetPreviousNode();
			if (cursor == tail)
				cursor = tail = n;
			else 
				cursor = n;

			n->EraseNextNode();
		}
	}

	str_length--;
	return true;
}

std::string TypingMachine::Print(char separator) {
	Node *n;
	char c;
	std::string st;
	n = head;
	if (head == nullptr)
	{
		if (separator!=0)
			st.push_back(separator);
	}
	else
	{
		if (root == cursor){
			if (separator != 0)
				st.push_back(separator);
		}
		while (n != nullptr)
		{
			if (n == cursor ){
				c = n->GetData();
				st.push_back(c);
				if (separator != 0)
					st.push_back(separator);
			}
			else
				st.push_back((char)n->GetData());
		
			n = n->GetNextNode();
		}
	}

  return st;
}
