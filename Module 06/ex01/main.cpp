#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "Mohammad";

	uintptr_t raw = Serializer::serialize(&data);
	Data * ptr = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Deserialized ptr: " << ptr << std::endl;

	if (ptr == &data)
		std::cout << "Success: pointers match" << std::endl;
	else
		std::cout << "Error: pointers do not match" << std::endl;

	std::cout << "Data.id = " << ptr->id << std::endl;
	std::cout << "Data.name = " << ptr->name << std::endl;

	return 0;
}
