/**
 *  CPSC 323 Compilers and Languages
 * 
 *  Dalton Caron, Teaching Associate
 *  dcaron@fullerton.edu, +1 949-616-2699
 *  Department of Computer Science
 */
#ifndef UTILITIES_H__
#define UTILITIES_H__

#include <memory>
#include <string>

#include <assertions.h>
#include <logging.h>

class CsvReader {
    public:
        CsvReader(const std::string path, const char separator=',');
        virtual ~CsvReader();

        std::string get(const int row, const int col) const;
        int getRows() const { return this->rows; };
        int getColumns() const { return this->columns; };
    private:
        int rows;
        int columns;
        std::unique_ptr<std::string[]> data;
};

#endif