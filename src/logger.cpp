#include "logger.h"

logger* logger::_logger = nullptr;
mutex 	logger::_mutex;
logfile	logger::_logfile;
int logger::_logging = 1;
