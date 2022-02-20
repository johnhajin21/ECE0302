#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Add String Test Function", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
	REQUIRE(!b.add("#ok"));
	REQUIRE(!b.add("@345"));
	REQUIRE(!b.add("hello mami"));
	REQUIRE(b.add("hello"));
	REQUIRE(!b.add("hEllo"));
	REQUIRE(b.add("hEllos"));
	REQUIRE(!b.add("hEllos"));
	REQUIRE(b.add("HELLOSS"));

	std::string bank = "abcdefghijklmnopqrstuvwxyz";
	
	for(int i=0;i<25;i++)
	{
		bank.push_back(bank[i]);
		REQUIRE(b.add(bank));
		REQUIRE(b.add(bank+bank));
	}

}


TEST_CASE( "Add Vector Test Function", "[FindPalindrome]" )
{
	
	FindPalindrome b;
	std::vector <std::string> a;
	a.push_back("apple");
	a.push_back("baseball");
	a.push_back("coffee");
	REQUIRE(b.add(a));


	std::vector <std::string> c;
	c.push_back("dAtE");
	c.push_back("ELEPHANT");
	c.push_back("Fruity");
	REQUIRE(b.add(c));

	std::vector <std::string> d;
	d.push_back("grape");
	d.push_back("hello");
	d.push_back("idiot!");
	REQUIRE(!b.add(d));


	std::vector <std::string> e;
	e.push_back("jackie21");
	e.push_back("jackie");
	e.push_back("kelly");
	REQUIRE(!b.add(e));

	std::vector <std::string> f;
	f.push_back("jackie");
	f.push_back("kelly");
	f.push_back("hello");
	REQUIRE(b.add(f));

	std::vector <std::string> g;
	g.push_back("your mom");
	g.push_back("weirdo");
	g.push_back("zebra");
	REQUIRE(!b.add(g));

	std::vector <std::string> h;
	h.push_back("apple");
	h.push_back("trumpet");
	h.push_back("bafoon");
	REQUIRE(!b.add(h));

	std::vector <std::string> i;
	i.push_back("laroi");
	i.push_back("LAroi");
	i.push_back("dell");
	REQUIRE(!b.add(i));

	FindPalindrome final;
	std::string bank = "abcdefghijklmnopqrstuvwxyz";
	std::vector <std::string> bank2;
	
	for(int i=0;i<26;i++)
	{
		bank.push_back(bank[i]);
		bank2.push_back(bank);
	}

	REQUIRE(final.add(bank2));
	REQUIRE(!final.add(bank2));

}





TEST_CASE( "Cut Test 2", "[FindPalindrome]" )
{
	std::string bank = "abcdefghijklmnopqrstuvwxyz";
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
	REQUIRE(test.cutTest2(b,a));

	std::vector<std::string> c;
	c.push_back("abc");
	c.push_back("def");
	c.push_back("ghi");

	std::vector<std::string> d;
	d.push_back("iiig");
	d.push_back("fed");
	d.push_back("cba");
	REQUIRE(!test.cutTest2(c,d));
	REQUIRE(!test.cutTest2(d,c));

	
	std::vector<std::string> e;
	e.push_back("r");
	e.push_back("a");
	e.push_back("c");

	std::vector<std::string> f;
	f.push_back("rac");
	f.push_back("fedadadsdasdsadasdas");
	f.push_back("cba");
	REQUIRE(test.cutTest2(e,f));
	REQUIRE(test.cutTest2(f,e));

	
	std::vector<std::string> g;
	g.push_back("r");
	g.push_back("a");
	g.push_back("c");

	std::vector<std::string> h;
	h.push_back("rac");
	h.push_back("fedadadsdasdsadasdas");
	h.push_back("cba");
	REQUIRE(test.cutTest2(h,g));
	REQUIRE(test.cutTest2(g,h));


	std::vector<std::string> i;
	i.push_back("r");
	i.push_back("a");
	i.push_back("c");

	std::vector<std::string> j;
	j.push_back("ac");
	j.push_back("fedadadsdasdsadasdas");
	j.push_back("cba");
	REQUIRE(!test.cutTest2(i,j));
	REQUIRE(!test.cutTest2(j,i));


	
	std::string one;
	std::string two;
	std::vector <std::string> oneV;
	std::vector <std::string> twoV;

	one.push_back('a');
	two += "aaa";
	oneV.push_back(one);
	twoV.push_back(two);
	

	REQUIRE(test.cutTest2(oneV,twoV));
	
	
}

TEST_CASE( "Cut Test 1", "[FindPalindrome]" )
{
	FindPalindrome test;
	std::vector <std::string> hello;
	hello.push_back("aaa");
	hello.push_back("bbbb");
	hello.push_back("cccc");
	REQUIRE(test.cutTest1(hello));
	
	hello.push_back("b");
	REQUIRE(!test.cutTest1(hello));

	hello.push_back("b");
	hello.push_back("cc");
	REQUIRE(test.cutTest1(hello));

	hello.push_back("a");
	REQUIRE(test.cutTest1(hello));

	hello.push_back("bbb");
	hello.push_back("ccc");
	REQUIRE(!test.cutTest1(hello));
	
}

TEST_CASE( "isPalindrome test case/number of palindromes test/recursive palindrome test", "[FindPalindrome]" )
{
	FindPalindrome test;
	REQUIRE(test.add("MrOwlate"));
	REQUIRE(test.add("myMetal"));
	REQUIRE(test.add("WORM"));

	REQUIRE(test.number() == 1);

	FindPalindrome test2;
	REQUIRE(test2.add("a"));
	REQUIRE(test2.add("AA"));
	REQUIRE(test2.add("AAA"));

	REQUIRE(test2.number() == 6);
	

}

TEST_CASE( "toVector test", "[FindPalindrome]" )
{
	FindPalindrome test;
	REQUIRE(test.add("MrOwlate"));
	REQUIRE(test.add("myMetal"));
	REQUIRE(test.add("WORM"));

	REQUIRE(test.number() == 1);

	std::vector<std::vector<std::string>> testy1;
	testy1 = test.toVector();
	REQUIRE(testy1[0][0] == "MrOwlate");
	REQUIRE(testy1[0][1] == "myMetal");
	REQUIRE(testy1[0][2] == "WORM");

	FindPalindrome test2;
	REQUIRE(test2.add("a"));
	REQUIRE(test2.add("aa"));
	REQUIRE(test2.add("aaa"));

	REQUIRE(test2.number() == 6);

	std::vector<std::vector<std::string>> testy2;
	testy2 = test2.toVector();
	REQUIRE(testy2[0][0] == "a");
	REQUIRE(testy2[0][1] == "aa");
	REQUIRE(testy2[0][2] == "aaa");

	REQUIRE(testy2[1][0] == "a");
	REQUIRE(testy2[1][1] == "aaa");
	REQUIRE(testy2[1][2] == "aa");

	REQUIRE(testy2[2][0] == "aa");
	REQUIRE(testy2[2][1] == "a");
	REQUIRE(testy2[2][2] == "aaa");

	REQUIRE(testy2[3][0] == "aa");
	REQUIRE(testy2[3][1] == "aaa");
	REQUIRE(testy2[3][2] == "a");

	REQUIRE(testy2[4][0] == "aaa");
	REQUIRE(testy2[4][1] == "a");
	REQUIRE(testy2[4][2] == "aa");

	REQUIRE(testy2[4][0] == "aaa");
	REQUIRE(testy2[4][1] == "a");
	REQUIRE(testy2[4][2] == "aa");

	REQUIRE(testy2[5][0] == "aaa");
	REQUIRE(testy2[5][1] == "aa");
	REQUIRE(testy2[5][2] == "a");
	
	

}

TEST_CASE( "Clear Test", "[FindPalindrome]" )
{
	FindPalindrome test;
	REQUIRE(test.add("MrOwlate"));
	REQUIRE(test.add("myMetal"));
	REQUIRE(test.add("WORM"));

	REQUIRE(test.number() == 1);

	test.clear();
	REQUIRE(test.number() == 0);

	FindPalindrome test2;
	REQUIRE(test2.add("a"));
	REQUIRE(test2.add("AA"));
	REQUIRE(test2.add("AAA"));

	REQUIRE(test2.number() == 6);

	test2.clear();
	REQUIRE(test2.number() == 0);
	

}