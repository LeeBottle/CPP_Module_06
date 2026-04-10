#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <string>
#include <iostream>
#include <stdint.h>

struct Data
{
	int			id;
	std::string	name;
	double		value;
};

class Serializer
{
private:
	Serializer( void );
	~Serializer( void );
	Serializer( const Serializer& other );
	Serializer& operator=( const Serializer& other );

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif