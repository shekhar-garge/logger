#ifndef __LOGGER_H__
#define __LOGGER_H__

#define LOG		*(logger::logging( __FILE__, __LINE__ )) 
#define LOGWARNING	*(logger::warning())
#define LOGERROR	*(logger::error())

#include <iostream>
#include <mutex>
using namespace std;

#include "logfile.h"


class logger
{
#if 0
	enum logging
	{
		log,
		warning,
		error
	};
#endif
public:
	template< typename F , typename L >
	inline static logger* logging( F fi, L li)
	{
		// additional activities for logging
		if ( _logfile._configParameter._fileName )
		{
			_mutex.lock();
				_logfile << "FileName: " << fi << " ";
			_mutex.unlock();
		}

		if ( _logfile._configParameter._lineNumber )
		{
			_mutex.lock();
				_logfile << "LineNumber: "<< li << " ";
			_mutex.unlock();
		}

		_logging = 1;
		
		return logInstance();
	}

	inline static logger* warning()
	{
		// additional activities for warning
		_logging = 2;
		return logInstance();
	}

	inline static logger* error()
	{
		// additional activities for error
		_logging = 3;
		return logInstance();
	}

	inline static logger* logInstance()
	{
		_mutex.lock();
			if ( _logger == nullptr) 
			{
				_logger = new logger;
			}
		_mutex.unlock();
			return _logger;
	}

	template < typename DATA>
	friend logger& operator << ( logger&, DATA& );

private:
	logger(const logger&) = delete;
	logger& operator = (const logger&) = delete;

	logger()
	{
		// future code
	}

	virtual ~logger()
	{ 
		_mutex.lock();
			if ( _logger != nullptr) delete _logger; 
		_mutex.unlock();
	}

private:
	static logger*	_logger;
	static mutex	_mutex;
	static logfile	_logfile;
	static int	_logging;
};

template < typename DATA>
logger& operator << ( logger& l, DATA& d )
{
	l._mutex.lock();
		l._logfile << d;
	l._mutex.unlock();

	return l;
}

#endif
