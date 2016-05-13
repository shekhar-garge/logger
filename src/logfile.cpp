#include "logfile.h"

logfile::~logfile()
{
	_mutex.lock();
		_logfile.close();
	_mutex.unlock();
}

logfile::logfile()
{
	_mutex.lock();
		_logfile.open( _configParameter._logfileName, ofstream::out | ofstream::app );
	_mutex.unlock();
}

