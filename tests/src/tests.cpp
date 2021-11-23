#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.hpp"

TEST_CASE ("duration") {

    //creating three test cases: p, p1 and p2. Both without start value (p) and with start value (p1 and p2)
    Duration* p = new Duration();
    Duration* p1 = new Duration(6);
    Duration* p2 = new Duration(10); 

    //testing for correct initializing values
    REQUIRE(p->getDuration()==0);
    REQUIRE(p1->getDuration()==6);
    REQUIRE(p2->getDuration()==10);

    //testing tick function without any input value
    p->tick();
    p1->tick();
    p2->tick();

    REQUIRE(p->getDuration()==1);
    REQUIRE(p1->getDuration()==7);
    REQUIRE(p2->getDuration()==11);

    //testing tick function with input value 2
    p->tick(2);
    p1->tick(2);
    p2->tick(2);

    REQUIRE(p->getDuration()==3);
    REQUIRE(p1->getDuration()==9);
    REQUIRE(p2->getDuration()==13);

    //testing alarm function with three different alarms
    p->setAlarm(5);
    p1->setAlarm(20);
    p2->setAlarm(30);

    REQUIRE(p->tick(2)==true);
    REQUIRE(p1->tick(9)==false);
    REQUIRE(p1->tick(5)==true);
    REQUIRE(p2->tick(100)==true);

    //clean-up
    delete p;
    delete p1;
    delete p2;
}