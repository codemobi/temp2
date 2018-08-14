// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
    Node *node = new Node('A');
    ASSERT_EQ(node->GetData(), 'A');
    delete node;
  }

public:
  static void RunTest() {
    SingleNodeTest();
    // add more..
  }
};

class InsertNodeTestSuite
{
private:
	static void InsertPreviousNodeTest() {
		Node *node = new Node('A');
		node->InsertPreviousNode('1');
		ASSERT_EQ(node->GetPreviousNode()->GetData(), '1');
		node->ErasePreviousNode();
		delete node;
	}
	static void InsertNextNodeTest() {
		Node *node = new Node('A');
		node->InsertNextNode('2');
		ASSERT_EQ(node->GetNextNode()->GetData(), '2');
		node->EraseNextNode();
		delete node;
	}
	static void InsertPreviousNodeTest_ManyTimes() {
		Node *node = new Node('A');
		node->InsertPreviousNode('1');
		node->InsertPreviousNode('2');
		node->InsertPreviousNode('3');
		ASSERT_EQ(node->GetPreviousNode()->GetData(), '3');
		node->ErasePreviousNode();
		node->ErasePreviousNode();
		node->ErasePreviousNode();
		delete node;
	}
	static void InsertNextNodeTest_ManyTimes() {
		Node *node = new Node('A');
		node->InsertNextNode('1');
		node->InsertNextNode('2');
		node->InsertNextNode('3');
		ASSERT_EQ(node->GetNextNode()->GetData(), '3');
		node->EraseNextNode();
		node->EraseNextNode();
		node->EraseNextNode();
		delete node;
	}

public:
  static void RunTest() {
	  InsertPreviousNodeTest(); 
	  InsertNextNodeTest();
	  InsertPreviousNodeTest_ManyTimes();
	  InsertNextNodeTest_ManyTimes();
    // add more..
  }
};

class GetNodeTestSuite
{
private:
	static void GetNodeTest() {
		Node *node = new Node('A');
		ASSERT_EQ(node->GetData(), 'A');
		delete node;
	}
	static void GetPreviousNodeTest() {
		Node *node = new Node('A');
		node->InsertPreviousNode('1');
		ASSERT_EQ(node->GetPreviousNode()->GetData(), '1');
		node->ErasePreviousNode();
		delete node;
	}
	static void GetNextNodeTest() {
		Node *node = new Node('A');
		node->InsertNextNode('2');
		ASSERT_EQ(node->GetNextNode()->GetData(), '2');
		node->EraseNextNode();
		delete node;
	}

public:
	static void RunTest() {
		GetNodeTest();
		GetPreviousNodeTest();
		GetNextNodeTest();
		// add more..
	}
};

class EraseNodeTestSuite
{
private:
	static void ErasePreviousNodeTest() {
		Node *node1 = new Node('A');
		node1->InsertPreviousNode('1');

		ASSERT_EQ(node1->ErasePreviousNode(), true);
		delete node1;
	}
	static void ErasePreviousNodeTest_false_case() {
		Node *node1 = new Node('A');
		node1->InsertPreviousNode('1');
		node1->ErasePreviousNode();

		ASSERT_EQ(node1->ErasePreviousNode(), false);
		delete node1;
	}
	static void EraseNextNodeTest() {
		Node *node1 = new Node('A');
		node1->InsertNextNode('1');

		ASSERT_EQ(node1->EraseNextNode(), true);
		delete node1;
	}
	static void EraseNextNodeTest_false_case() {
		Node *node1 = new Node('A');
		node1->InsertNextNode('1');
		node1->EraseNextNode();

		ASSERT_EQ(node1->EraseNextNode(), false);
		delete node1;
	}

public:
	static void RunTest() {
		ErasePreviousNodeTest();
		ErasePreviousNodeTest_false_case();
		EraseNextNodeTest();
		EraseNextNodeTest_false_case();
		// add more..
	}
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  puts("NodeConstructorTestSuite::RunTest Done");

  GetNodeTestSuite::RunTest();
  puts("GetNodeTestSuite::RunTest Done");

  InsertNodeTestSuite::RunTest();
  puts("InsertNodeTestSuite::RunTest Done");

  EraseNodeTestSuite::RunTest();
  puts("EraseNodeTestSuite::RunTest Done");
  // add more..
}