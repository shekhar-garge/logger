#ifndef _LOGFILE_H__
#define _LOGFILE_H__

#include <iostream>
#include <ostream>
#include <mutex>
#include <string>
#include "configParameter.h"
using namespace std;


class logfile : public ostream
{
public:
	logfile();	
	~logfile();

public:
	template < typename DATA>
	logfile& operator << ( DATA& d)
	{
		_mutex.lock();
		        _logfile << d;
		_mutex.unlock(); 

		return *this;
	}

public:
	configParameter _configParameter;

private:
	ifstream	_config;
	ofstream	_logfile;
	mutex		_mutex;
};
#endif
