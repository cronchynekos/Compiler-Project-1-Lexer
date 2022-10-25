/**
 *  CPSC 323 Compilers and Languages
 * 
 *  Dalton Caron, Teaching Associate
 *  dcaron@fullerton.edu, +1 949-616-2699
 *  Department of Computer Science
 */
#include <catch2/catch.hpp>

#include <lexer.h>

TEST_CASE("ScanningTable", "[ScanningTable]") {

    const char *scanning_table_path = "../test/scanning_table.csv";
    ScanningTable scanning_table(CsvReader(scanning_table_path, ','));

    REQUIRE(scanning_table.getNextState(0, 'a') == 1);
    REQUIRE(scanning_table.containsNextState(3, '\t') == false);
    REQUIRE(scanning_table.getNextState(2, '\n') == 3);
    REQUIRE(scanning_table.getNextState(1, 'a') == 2);
}

TEST_CASE("TokenTable", "[TokenTable]") {

    const char *token_table_path = "../test/token_table.csv";
    TokenTable token_table(CsvReader(token_table_path, ','));

    REQUIRE(token_table.isStateFinal(2) == true);
    REQUIRE(token_table.isStateFinal(100) == false);
    REQUIRE(token_table.getTokenTypeFromFinalState(2) == (token_class_t) 2);
}

TEST_CASE("Test Case 1", "[Lexer]") {

    const char *file_path = "../test/test_code/test1.p0";
    const int token_count = 42;
    token_class_t expected_types[token_count] = {
        VAR_KEYWORD, IDENTIFIER, COMMA, IDENTIFIER, SEMICOLON,
        PROCEDURE_KEYWORD, IDENTIFIER, SEMICOLON, BEGIN_KEYWORD,
        IDENTIFIER, DEFINE_EQUALS, IDENTIFIER, MUL_OP, IDENTIFIER,
        END_KEYWORD, SEMICOLON, BEGIN_KEYWORD, IDENTIFIER, DEFINE_EQUALS,
        NUMBER_LITERAL, SEMICOLON, WHILE_KEYWORD, IDENTIFIER,
        COMPARE_OP, NUMBER_LITERAL, DO_KEYWORD, BEGIN_KEYWORD, CALL_KEYWORD,
        IDENTIFIER, SEMICOLON, WRITE_OP, IDENTIFIER, SEMICOLON, IDENTIFIER,
        DEFINE_EQUALS, IDENTIFIER, ADD_OP, NUMBER_LITERAL, END_KEYWORD,
        END_KEYWORD, PERIOD, END_OF_FILE
    };

    Lexer lexer;
    token_stream_t token_stream = lexer.lex(file_path);
    
    for (int i = 0; i < token_count; i++) {
        REQUIRE(token_stream.at(i).type == expected_types[i]);
    }

}
