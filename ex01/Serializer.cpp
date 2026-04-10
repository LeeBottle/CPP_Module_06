#include "Serializer.hpp"

Serializer::Serializer(void)
{
	//std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::~Serializer(void)
{
	//std::cout << "Serializer Destructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	//std::cout << "Serializer Copy Constructor called" << std::endl;
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	//std::cout << "Serializer Copy Assignment Operator called" << std::endl;
	(void)other;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}