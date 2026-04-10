#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
private:
	ScalarConverter( void );
	~ScalarConverter( void );
	ScalarConverter( const ScalarConverter& other );
	ScalarConverter& operator=( const ScalarConverter& other );

public:
	static void		convert( std::string input );
	static void		printValues(double baseValue, bool isPossible, bool isPseudo, const std::string& input);
};

#endif