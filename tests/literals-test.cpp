#include <iostream>
#include <string>
#include <cassert>

#include "rencpp/ren.hpp"

using namespace ren;

#include "catch.hpp"

TEST_CASE("literals construction", "[rebol] [literals]")
{
    SECTION("default")
    {
        AnyValue value;
        CHECK(is<None>(value));
    }

    SECTION("none")
    {
        AnyValue value = none;
        CHECK(is<None>(value));
    }

    SECTION("logic")
    {
        AnyValue value = false;
        CHECK(is<Logic>(value));

        // https://github.com/hostilefork/rencpp/issues/24
        // No way ATM to test the "shouldn't compile" cases

        auto logical = [](Logic const &) {};

        logical(true); // should work
        // logical("hello"); // shouldn't compile (!)
        // logical(15); // shouldn't compile (!)

        Logic temp1 = true;
        // Logic temp2 = "hello"; // shouldn't compile (!)
        // Logic temp3 = 15; // shouldn't compile (!)

        logical(Logic {true}); // should work
        logical(Logic {"hello"}); // this compiles, as it's "explicit"
        logical(Logic {15}); // also okay, as it's "explicit"
    }

    SECTION("integer")
    {
        AnyValue value = 1;
        CHECK(is<Integer>(value));
    }


    SECTION("float construction")
    {
        AnyValue value = 10.20;
        CHECK(is<Float>(value));
    }


    SECTION("string construction")
    {
        String value {"Hello"};
        CHECK(value.length() == 5);
    }


    SECTION("string construction error")
    {
        CHECK_THROWS_AS(
            runtime("{Hello"),
            load_error
        );
    }
}
