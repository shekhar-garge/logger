#include <iostream>
using namespace std;

#include "logger.h"

int main()
{
#if 0
	string testMessage{ "testMessage" };
	string logMessage{ "to test logger" };

	int i = 10;
	float f = 10.20;

	LOG << testMessage << logMessage << "\n";
	LOG << i << f << "\n"; 

	LOGWARNING << testMessage << logMessage << "\n";
	LOGWARNING << i << f << "\n"; 

	LOGERROR << testMessage << logMessage << "\n";
	LOGERROR << i << f << "\n"; 
#else
	string input="";
	cout << "Enter data you want to write to file." << endl;
	cout << "To quit logging, just enter q or Q and then press enter." << endl;
	do
	{
		getline ( cin , input );
		LOG << input << "\n" ;
	}
	while ( input != "q" && input != "Q" );
#endif
	return 0;
}
