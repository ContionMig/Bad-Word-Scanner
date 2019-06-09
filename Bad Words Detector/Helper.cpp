#include "Headers.h"

using namespace std;
namespace Helper
{
	std::string replaceStrChar(std::string str, const std::string& replace, char ch) {

		size_t i = str.find_first_of(replace);
		int found = str.find(replace);
		while (found != string::npos) 
		{
			str[found] = ch; 
			found = str.find_first_of(replace, found + 1);
		}

		return str; // return our new string.
	}

	std::string remove_duplicates(std::string s) 
	{
		if (s.begin() == s.end()) return s;
		auto no_duplicates = s.begin();
		for (auto current = no_duplicates; current != s.end();) 
		{
			current = std::find_if(std::next(current), s.end(), [no_duplicates](const char c) { return c != *no_duplicates; });
			*++no_duplicates = std::move(*current);;
		}
		s.erase(++no_duplicates, s.end());
		return s;
	}
}