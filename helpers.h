#pragma once
#include <string>
#include <vector>

// parse a line of a csv file and return a vector of strings
std::vector<std::string> CSV_parse(const std::string& str)
{
    // set the divider
	const char delim = ',';
	std::vector<std::string> return_vec;
	
	size_t start = 0;
	size_t delimLoc = str.find_first_of(delim, start);
	while (delimLoc != std::string::npos)
	{
		return_vec.emplace_back(str.substr(start, delimLoc - start));
		
		start = delimLoc + 1;
		delimLoc = str.find_first_of(delim, start);
	}
	
	return_vec.emplace_back(str.substr(start));
	return return_vec;
}
