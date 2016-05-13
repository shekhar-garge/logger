#include "configParameter.h"


configParameter::configParameter()
	:
	// default values for Config parameters
	_logfileName("defaultLogfile.log" ),
	_logLevel(1),
	_date(true),
	_time(true),
	_fileName(true),
	_lineNumber(true)
{

		// 1. open config file
		_config.open( "logConfig" );

		// 2. If config file gets opened with success read it
		//	Else use the default values
		if ( ! _config.fail() )
		{
			// These are the config file parameters.
			// The parameters and values are seperated by "="
			// If you want to add new parameter, just add here, no further changes required
			string parameters[]=	{
						"LOG_FILE=",
						"LOG_LEVEL=",
						"DATE=",
						"TIME=",
						"FILE_NAME=",
						"LINE_NUMBER="
						};
			//calculate the number of parameters to read
			auto parametersLength = end ( parameters ) - begin ( parameters );

			// 3. create the regular expression pattern to extract the values
			vector< regex > patterns;
			for ( auto i = 0 ; i < parametersLength ; ++i)
			{
				patterns.push_back( regex(parameters[i]+"(.*);") );
			};
	
			// variable to match the values found after applying regular expression
			smatch match;
			// regular expression to match comments
			regex comments("#.*");

			// 4. read the config file in loop till end of file
			while ( _config.good() )
			{
				// 5. read the file line by line
				getline( _config, _line );
				
				if ( regex_search ( _line, match, comments ) )
					continue;

				// 6. apply regular expression one after another till we found one match 
				for ( auto i = 0 ; i < parametersLength ; ++i )
				{
					// match found
					if ( regex_search ( _line, match, patterns[i] ) )
					{
						if ( match.size() )
						{
							// This is index based.
							// one regular expression equals one parameter.
							// when you add new config parameter add one case here
							switch ( i )
							{
								case 0:
									_logfileName = match.str(1);
									break;
								case 1:
									_logLevel = readAsInt ( match.str(1) );
									break;
								case 2:
									_date = readAsBool ( match.str(1) );
									break;
								case 3:
									_time = readAsBool( match.str(1) );
									break;
								case 4:
									_fileName = readAsBool( match.str(1) );
									break;
								case 5:
									_lineNumber= readAsBool( match.str(1) );
									break;
								default:
									// ignore
									break;

							}
						}
						// match found. skip the iteration as one line one parameter
						break;
					}
				}

			}
		}
}

