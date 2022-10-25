/**
 *  CPSC 323 Compilers and Languages
 * 
 *  Dalton Caron, Teaching Associate
 *  dcaron@fullerton.edu, +1 949-616-2699
 *  Department of Computer Science
 */
#include <utilities.h>

#include <logging.h>
#include <fstream>
#include <algorithm>
#include <sstream>

CsvReader::CsvReader(const std::string path, const char separator) 
: rows(0), columns(0), data(nullptr) 
{
    std::string line;
    std::ifstream infile;

    infile.open(path);
    if (!infile.is_open()) {
        ERROR_LOG("Failed to open CSV file %s", path.c_str());
        exit(EXIT_FAILURE);
    }

    const int newlines = std::count(
        std::istreambuf_iterator<char>(infile),
        std::istreambuf_iterator<char>(), '\n'
    );

    infile.seekg(0, std::ios::beg);

    if (!getline(infile, line)) {
        WARNING_LOG("CSV file %s is empty", path.c_str());
        return;
    }

    const int commas = std::count(line.begin(), line.end(), separator);

    this->rows = newlines + 1;
    this->columns = commas + 1;
    this->data = std::make_unique<std::string[]>(this->rows * this->columns);

    int current_row = 0;
    int current_col = 0;

    do {
        std::istringstream ss(line);
        std::string token;
        ASSERT(current_row <= this->rows);

        while (getline(ss, token, ',')) {
            ASSERT(current_col < this->columns);
            *(this->data.get() + current_row * this->columns + current_col) = token;
            current_col++;
        }
        current_col = 0;
        current_row++;
    } while (getline(infile, line));
}

CsvReader::~CsvReader() {
    this->data = nullptr;
}

std::string CsvReader::get(const int row, const int col) const {
    return *(this->data.get() + row * this->columns + col);
}