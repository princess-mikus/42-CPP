#include "Serializer.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer &model) {
	(void)model;
}

Serializer::~Serializer() {

}

Serializer	&Serializer::operator=(const Serializer &model) {
	(void)model;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}


