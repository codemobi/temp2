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

	// do nothing case
	static void LeftKeyTest_DoNothing() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.LeftKey();
		tm.LeftKey();
		ASSERT_EQ(tm.Print('|'), std::string("|a"));
	}
	static void RightKeyTest_DoNothing() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.RightKey();
		ASSERT_EQ(tm.Print('|'), std::string("a|"));
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
		LeftKeyTest_DoNothing();
		RightKeyTest_DoNothing();
		// add more..
	}
};

class EraseTestSuite
{
private:
	// "abc|" case
	static void EraseTest_Case1() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), std::string("ab|"));
	}
	static void EraseTest_Case2() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.EraseKey();
		tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), std::string("a|"));
	}
	static void EraseTest_Case3() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.EraseKey();
		tm.EraseKey();
		tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
	}
	static void EraseTest_Case4_DoNothing() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		tm.TypeKey('c');
		tm.EraseKey();
		tm.EraseKey();
		tm.EraseKey();
		tm.EraseKey();
		ASSERT_EQ(tm.Print('|'), std::string("|"));
	}

public:
	static void RunTest() {
		EraseTest_Case1();
		EraseTest_Case2();
		EraseTest_Case3();
		EraseTest_Case4_DoNothing();

		// add more..
	}
};

class PrintTestSuite
{
private:
	// "ab|" case
	static void PrintTest_Case1() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		ASSERT_EQ(tm.Print('|'), std::string("ab|"));
	}
	static void PrintTest_Separator_Other() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		ASSERT_EQ(tm.Print('$'), std::string("ab$"));
	}
	static void PrintTest_Separator_NUL() {
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey('b');
		ASSERT_EQ(tm.Print(0), std::string("ab"));
	}
	static void PrintTest_MAX_STRING() {
		TypingMachine tm;
		for (int i = 0; i < 110; i++)
			tm.TypeKey('a');
		// compare it with 100 'a' + '|'
		ASSERT_EQ(tm.Print('|'), std::string("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa|"));
	}

public:
	static void RunTest() {
		PrintTest_Case1();
		PrintTest_Separator_Other();
		PrintTest_Separator_NUL();
		PrintTest_MAX_STRING();

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

	EraseTestSuite::RunTest();
	puts("EraseTestSuite::RunTest Done");

	PrintTestSuite::RunTest();
	puts("PrintTestSuite::RunTest Done");
	// add more..
}