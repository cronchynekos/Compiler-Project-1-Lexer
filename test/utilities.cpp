/**
 *  CPSC 323 Compilers and Languages
 * 
 *  Dalton Caron, Teaching Associate
 *  dcaron@fullerton.edu, +1 949-616-2699
 *  Department of Computer Science
 */
#include <catch2/catch.hpp>

#include <utilities.h>

TEST_CASE("CsvReader", "[CsvReader]") {

    SECTION("Test Valid CSV file") {
        const char *csv_path = "../test/dummy.csv";
        CsvReader reader(csv_path);

        REQUIRE(reader.getRows() == 4);
        REQUIRE(reader.getColumns() == 4);

        REQUIRE(reader.get(0, 0) == "");
        REQUIRE(reader.get(0, 1) == "a");
        REQUIRE(reader.get(1, 1) == "2");
        REQUIRE(reader.get(3, 0) == "bob");
        REQUIRE(reader.get(3, 3) == "25");
    }

}