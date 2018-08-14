// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
    TypingMachine tm;
    ASSERT_EQ(tm.Print('|'), std::string("|"));
  }

public:
  static void RunTest() {
    BarSeparatorTest();
    // add more..
  }
};

class TypeKeyTestSuite
{
private:
	static void TypeKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}
	static void TypeKeyTest_InputScope_Under() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.TypeKey(0x19); // under 0x19 (' ')
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}
	static void TypeKeyTest_InputScope_Over() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.TypeKey(0x7F); // over 0x7E ('~')
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}

public:
  static void RunTest() {
	  TypeKeyTest();
	  TypeKeyTest_InputScope_Under();
	  TypeKeyTest_InputScope_Over();
    // add more..
  }
};

class KeyMovementTestSuite
{
private:
	// "abc|" case
	static void HomeKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|abc"));
	}
	static void EndKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}
	static void LeftKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("ab|c"));
	}
	static void RightKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}

	// "ab|c" case
	static void HomeKeyTest_MiddleCursor() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|abc"));
	}
	static void EndKeyTest_MiddleCursor() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}
	static void LeftKeyTest_MiddleCursor() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("a|bc"));
	}
	static void RightKeyTest_MiddleCursor() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}

public:
	static void RunTest() {
		HomeKeyTest();
		EndKeyTest();
		LeftKeyTest();
		RightKeyTest();
		HomeKeyTest_MiddleCursor();
		EndKeyTest_MiddleCursor();
		LeftKeyTest_MiddleCursor();
		RightKeyTest_MiddleCursor();
		// add more..
	}
};

class EraseTestSuite
{
private:
	// "abc|" case
	static void EraseTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|abc"));
	}
	static void EndKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}
	static void LeftKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("ab|c"));
	}
	static void RightKeyTest() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}

	// "ab|c" case
	static void HomeKeyTest_MiddleCursor() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		tm.HomeKey();
		ASSERT_EQ(tm.Print('|'), std::string("|abc"));
	}
	static void EndKeyTest_MiddleCursor() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		tm.EndKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}
	static void LeftKeyTest_MiddleCursor() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("a|bc"));
	}
	static void RightKeyTest_MiddleCursor() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.LeftKey();
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("abc|"));
	}

public:
	static void RunTest() {
		HomeKeyTest();
		EndKeyTest();
		LeftKeyTest();
		RightKeyTest();
		HomeKeyTest_MiddleCursor();
		EndKeyTest_MiddleCursor();
		LeftKeyTest_MiddleCursor();
		RightKeyTest_MiddleCursor();
		// add more..
	}
};

void TypingMachineTest() {
  
	TmConstructorTestSuite::RunTest();
	puts("TmConstructorTestSuite::RunTest Done");

	TypeKeyTestSuite::RunTest();
	puts("TypeKeyTestSuite::RunTest Done");

	KeyMovementTestSuite::RunTest();
	puts("KeyMovementTestSuite::RunTest Done");

//	EraseTestSuite::RunTest();
	puts("EraseTestSuite::RunTest Done");

//	PrintTestSuite::RunTest();
	puts("PrintTestSuite::RunTest Done");
	// add more..
}