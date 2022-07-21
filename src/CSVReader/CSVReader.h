#ifndef _H_CSV_READER
#define _H_CSV_READER

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
/*
 * A class to read data from a csv file.
 */
class CSVReader {
  std::string fileName;
  std::string delimeter;

public:
  CSVReader(std::string filename, std::string delm = ",")
      : fileName(filename), delimeter(delm) {}
  // Function to fetch data from a CSV File
  std::vector<std::vector<std::string>> getData();
};

#endif