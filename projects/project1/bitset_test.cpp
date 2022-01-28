#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

TEST_CASE( "Test bitset construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString() == "00000000");
}

TEST_CASE( "Test bitset construction (Length plugged in)", "[bitset]" ) {

    Bitset b(5);  
    REQUIRE(b.size() == 5);
    REQUIRE(b.good());
    REQUIRE(b.asString() == "00000");

    Bitset c(-4);
    REQUIRE(c.good() == false);
}


TEST_CASE( "Test bitset construction (String plugged in)", "[bitset]" ) {

    Bitset b("0000000000");  
    REQUIRE(b.size() == 10);
    REQUIRE(b.good());
    REQUIRE(b.asString() == "0000000000");

    Bitset c("0212");
    REQUIRE(c.size() == 4);
    REQUIRE(c.good() == false);
}


TEST_CASE( "Test bitset size", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    
    Bitset c(4);
    REQUIRE(c.size() == 4);
    REQUIRE(c.good());


    Bitset d("00101");
    REQUIRE(d.size() == 5);
    REQUIRE(d.good());

}



TEST_CASE( "Test bitset valid", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    
    Bitset c(-4);
    REQUIRE(c.good() == false);

    Bitset d("00101");
    REQUIRE(d.size() == 5);
    REQUIRE(d.good());

    Bitset e;
    e.set(20);
    REQUIRE(e.good() == false);

    Bitset f;
    f.toggle(3);
    REQUIRE(f.good());


    Bitset g;
    g.reset(9);
    REQUIRE(g.good() == false);

    Bitset h;
    h.reset(5);
    REQUIRE(h.good());


}


TEST_CASE( "Reset bit test", "[bitset]" ) {

    Bitset b; 
    b.set(4); 
    b.reset(4);
    REQUIRE(b.asString() == "00000000");
    
    Bitset c(4);
    c.reset(5);
    REQUIRE(c.good() == false);

    Bitset d("00101");
    d.reset(2);
    REQUIRE(d.asString() == "00001");

}


TEST_CASE( "Toggle bit test", "[bitset]" ) {

    Bitset b; 
    b.toggle(4); 
    REQUIRE(b.asString() == "00010000");
    REQUIRE(b.good());
    
    Bitset c(4);
    c.toggle(5);
    REQUIRE(c.good() == false);

    Bitset d("00101");
    d.toggle(2);
    REQUIRE(d.asString() == "00001");
    REQUIRE(b.good());

}

TEST_CASE( "Return as string test", "[bitset]" ) {

    Bitset b; 
    b.toggle(4); 
    REQUIRE(b.asString() == "00010000");
    REQUIRE(b.good());
    
    Bitset c(4);
    c.toggle(2);
    REQUIRE(c.asString() == "0100");
    REQUIRE(c.good());

    Bitset d("00101");
    d.reset(0);
    REQUIRE(d.asString() == "00100");
    REQUIRE(d.good());

}






