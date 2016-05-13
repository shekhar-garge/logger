#ifndef __CONFIG_PARAMETER_H__
#define __CONFIG_PARAMETER_H__

#include <iostream>
#include <fstream> 
#include <regex>
#include <vector>
using namespace std;

struct configParameter
{
public:
	configParameter();
	~configParameter(){}

	inline int readAsInt ( string str ) 
	{
		if ( str.size() )
		{
			auto i = stoi ( str );
			if ( i > 0 ) 
				return i;
		}
		return 0;
	}

	inline bool readAsBool ( string str ) 
	{
		if ( str.size() )
		{
			auto i = stoi ( str );
			if ( i > 0 ) 
				return true;
		}
		return false;
	}
public:
	ifstream	_config;
	string		_line;

	string		_logfileName;
	int		_logLevel;
	bool		_date;
	bool		_time;
	bool		_fileName;
	bool		_lineNumber;
};

#endif
