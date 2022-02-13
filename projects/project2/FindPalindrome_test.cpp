#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

/*TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}
*/

TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome a;
	std::vector<std::string> test;
	test.push_back("ok");
	test.push_back("okk");
	test.push_back("okk@k");
	test.push_back("okkkk");
	test.push_back("okkkkk");

	FindPalindrome b;
	//See if input vector has the same
	std::vector<std::string> test2;
	test2.push_back("ok");
	test2.push_back("oK");
	test2.push_back("okkk");
	test2.push_back("okkkk");
	test2.push_back("okkkkk");

	FindPalindrome c;
	std::vector<std::string> test3;
	test3.push_back("ok");
	test3.push_back("okk");
	test3.push_back("okkk");
	test3.push_back("okkkk");
	test3.push_back("okkkkk");

	FindPalindrome d;
	std::vector<std::string> test4;
	test4.push_back("ok");
	test4.push_back("okk");
	test4.push_back("okkk");
	test4.push_back("okkkk");
	test4.push_back("okkkkk");


	REQUIRE(!a.add(test));
	REQUIRE(!b.add(test2));
	REQUIRE(c.add("okk"));
	REQUIRE(!c.add(test3));
	REQUIRE(d.add(test4));
	
}
/*
TEST_CASE( "Cut Test 1", "[FindPalindrome]" )
{
	FindPalindrome test;
	std::vector<std::string> a;
	a.push_back("bbbb");
	a.push_back("cccc");
	a.push_back("dddd");

	REQUIRE(test.cutTest1(a));

	a.push_back("eee");

	REQUIRE(test.cutTest1(a));

	a.push_back("fff");
	REQUIRE(!test.cutTest1(a));

	a.push_back("e");
	REQUIRE(test.cutTest1(a));

	a.push_back("c");
	a.push_back("d");
	REQUIRE(!test.cutTest1(a));



	
}

*/

TEST_CASE( "Cut Test 2", "[FindPalindrome]" )
{
	FindPalindrome test;
	std::vector<std::string> a;
	a.push_back("abc");
	a.push_back("def");
	a.push_back("ghi");

	std::vector<std::string> b;
	b.push_back("ihg");
	b.push_back("fed");
	b.push_back("cba");

	REQUIRE(test.cutTest2(a,b));


	std::vector<std::string> c;
	c.push_back("abc");
	c.push_back("def");
	c.push_back("ghi");

	std::vector<std::string> d;
	d.push_back("hdkhihg");
	d.push_back("fed");
	d.push_back("cba");

	REQUIRE(test.cutTest2(c,d));

	std::vector<std::string> e;
	e.push_back("abc");
	e.push_back("dff");
	e.push_back("ghi");

	std::vector<std::string> f;
	f.push_back("ihg");
	f.push_back("fed");
	f.push_back("cba");

	REQUIRE(!test.cutTest2(e,f));
	
}