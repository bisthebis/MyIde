#include "catch.hpp"
#include "compiler_processes/find_fileinfos.hpp"

#include <QDebug>

TEST_CASE ("Dummy test", "[dummy]")
{
	REQUIRE(true);
}

TEST_CASE ("Compilers are found", "[findCompilers]")
{
    QStringList compilers = findCompilers();
    CHECK(!compilers.empty());
}
