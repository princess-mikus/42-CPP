#include "Serializer.hpp"

int	main(void) {
	Data		data;
	Data		*dptr;
	uintptr_t	uintptr;

	data.index = 1;
	data.name = "Mica";
	data.value = 23.564;
	std::cout << data.value << std::endl;
	std::cout << &data.name << std::endl;
	uintptr = Serializer::serialize(&data);
	dptr = Serializer::deserialize(uintptr);
	std::cout << dptr->value << std::endl;
	std::cout << &dptr->name << std::endl;
}