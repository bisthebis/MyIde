#include "catch.hpp"
#include "libtmp/find_compilers.hpp"

#include <QDebug>

TEST_CASE ("Dummy test", "[dummy]")
{
	REQUIRE(true);
}

TEST_CASE ("Compilers are found", "[find_compilers]")
{
    QStringList compilers = find_compilers();
    CHECK(!compilers.empty());
}
