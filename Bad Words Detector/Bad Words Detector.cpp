#include "Headers.h"

int main()
{
	std::string Thingy = "";
	printf("Enter Your Bad Words: ");
	std::getline(std::cin, Thingy);

	std::transform(Thingy.begin(), Thingy.end(), Thingy.begin(), ::tolower);

	Filters::CheckWord(Thingy);

	printf("What You Said: %s\n", Thingy.c_str());

	system("pause");
}