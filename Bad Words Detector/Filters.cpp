#include "Headers.h"

namespace Filters
{
	// Normal Scans
	std::string Filter1(std::string STR)
	{
		printf("[+] Filter Received: %s\n", STR.c_str());
		for (int i = 0; i != BadWordsArry.size(); i++)
		{
			if (BadWordsArry[i].size() > 0)
			{
				if (STR.find(BadWordsArry[i]) != std::string::npos)
				{
					printf("[-] Found Bad Word: %s\n", BadWordsArry[i].c_str());
				}
			}
		}

		printf("\n");
		return STR;
	}

	// Removed Spaces
	std::string Filter2(std::string ST)
	{
		ST.erase(remove_if(ST.begin(), ST.end(), isspace), ST.end());;
		return ST;
	}

	// Replacement
	std::string Filter3(std::string ST)
	{
		for (int i = 0; i != CharsChanged.size(); i++)
		{
			if (ST.find(CharsChanged[i]) != std::string::npos)
			{
				ST = Helper::replaceStrChar(ST, CharsChanged[i], CharsReplaced[i]);
			}
		}
		return ST;
	}

	// Remove Dups
	std::string Filter4(std::string ST)
	{
		return Helper::remove_duplicates(ST);
	}

	void CheckWord(std::string ST)
	{
		printf("\n");
		printf("No Mods:\n");
		Filter1(ST); 
		printf("No Space:\n");
		Filter1(Filter2(ST));
		printf("Replaced Symbols:\n");
		Filter1(Filter3(ST));
		printf("No Dups:\n");
		Filter1(Filter4(ST));

		printf("\n");
		std::string Dual = ST;
		Dual = Filter2(Dual);
		Dual = Filter3(Dual);
		printf("No Space + Replaced Symbols:\n");
		Filter1(Dual);

		printf("\n");
		std::string Triple = ST;
		Triple = Filter2(Triple);
		Triple = Filter3(Triple);
		Triple = Filter4(Triple);
		printf("No Space + Replaced Symbols + No Dups:\n");
		Filter1(Triple);
	}
}