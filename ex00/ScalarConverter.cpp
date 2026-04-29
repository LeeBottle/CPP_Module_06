#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	//std::cout << "ScalarConverter Default Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	//std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	//std::cout << "ScalarConverter Copy Constructor called" << std::endl;
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	//std::cout << "ScalarConverter Copy Assignment Operator called" << std::endl;
	(void)other;
	return *this;
}

void printValues(double baseValue, bool isPossible, bool isPseudo, const std::string& input)
{
	std::cout << "char: ";
	if (isPseudo || !isPossible ||
		baseValue < 0 || baseValue > 127)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		int c = static_cast<int>(baseValue);
		if (std::isprint(c))
		{
			std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
		}
		else 
		{
			std::cout << "Non displayable" << std::endl;
		}
	}

	std::cout << "int: ";
	if (isPseudo || !isPossible ||
		baseValue < std::numeric_limits<int>::min() ||
		baseValue > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(baseValue) << std::endl;
	}

	std::cout << "float: ";
	if (isPseudo)
	{
		if (input.find("nan") != std::string::npos)
			std::cout << "nanf" << std::endl;
		else if (input[0] == '-')
			std::cout << "-inff" << std::endl;
		else
			std::cout << "inff" << std::endl;
	}
	else if (!isPossible)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		float fval = static_cast<float>(baseValue);
		if (fval == static_cast<int>(fval))
		{
			std::cout << std::fixed << std::setprecision(1) << fval << "f" << std::endl;
		}
		else
		{
			std::cout << fval << "f" << std::endl;
		}
	}

	std::cout << "double: ";
	if (isPseudo)
	{
		if (input.find("nan") != std::string::npos)
			std::cout << "nan" << std::endl;
		else if (input[0] == '-')
			std::cout << "-inf" << std::endl;
		else
			std::cout << "inf" << std::endl;
	}
	else if (!isPossible)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		double dval = static_cast<double>(baseValue);
		if (dval - static_cast<int>(dval) == 0)
		{
			std::cout << std::fixed << std::setprecision(1) << dval << std::endl;
		}
		else
		{
			std::cout << dval << std::endl;
		}
	}
}

void ScalarConverter::convert(std::string input)
{
	double baseValue = 0;
	bool isPossible = true;
	bool isPseudo = false;

	if (input == "nan" || input == "-nan" || 
		input == "nanf" ||input == "-nanf" ||
		input == "inf" || input == "+inf" || input == "-inf" ||
		input == "inff" || input == "+inff" || input == "-inff")
	{
		isPseudo = true;
		baseValue = std::strtod(input.c_str(), NULL);
	}
	else if (input.length() == 1 && !std::isdigit(input[0]))
	{
		baseValue = static_cast<double>(input[0]);
	}
	else
	{
		char* endPtr;
		baseValue = std::strtod(input.c_str(), &endPtr);
		if (*endPtr != '\0' && !(*endPtr == 'f' && *(endPtr + 1) == '\0'))
		{
			isPossible = false;
		}
	}
	printValues(baseValue, isPossible, isPseudo, input);
}