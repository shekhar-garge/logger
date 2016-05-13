# logger
# This is a simplified logger solution.
# This generic application supports "LOG", "LOGWARNING" and "LOGERROR" types of logs
# The logger can be configured using configuration parameters from file located at ./src/logConfig
# In case of missing configfile or missing/incorrect parameters, logger application gets initialised to default values
# It can be extendded by simply adding small code fragment to suit the user needs
# Templates are used for generic logic
# This is Thread safe and uses mutex as a synchonization mechanism
# It uses not all but some of the advanced C++14 features e.g. regex
# The main.cpp file consist of the Stub code for testing purpose and can be replaced by user code 

