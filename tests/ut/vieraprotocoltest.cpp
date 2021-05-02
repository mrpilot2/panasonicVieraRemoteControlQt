#include <catch2/catch.hpp>

#include "vieraprotocol.hpp"

using viera::core::VieraProtocol;

TEST_CASE("Any viera protocol")
{
    SECTION("can save the IP address")
    {
        VieraProtocol protocol;
        viera::core::VieraProtocol::setIpAddress("192.168.2.1");

        REQUIRE("192.168.2.1" == protocol.getIpAddress());
    }
}
