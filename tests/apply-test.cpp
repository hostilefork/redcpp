#include <iostream>
#include <cassert>

#include "rencpp/ren.hpp"

using namespace ren;

#include "catch.hpp"

TEST_CASE("apply test", "[rebol] [apply]")
{
    SECTION("set-word success")
    {
        AnyValue result = SetWord {"w"}(10);
        CHECK(is<Integer>(result));
        CHECK(static_cast<int>(static_cast<Integer>(result)) == 10);
    }

    SECTION("set-word failure")
    {
        CHECK_THROWS_AS(
            SetWord {"w"}(10, 20),
            evaluation_error
        );
    }

    SECTION("blank failure")
    {
        // technical note: explicit blank(arg1, arg2...) is now illegal
        AnyValue value = blank;

        CHECK_THROWS_AS(
            value.apply(10),
            evaluation_error
        );
    }
}
