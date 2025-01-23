#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &modelb);
		~Serializer();
		Serializer	&operator=(const Serializer &model);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
