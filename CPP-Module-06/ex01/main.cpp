#include <iostream>
#include "Serializer.hpp"

int main()
{
	std::cout << "=== Test ex01: Serialization ===" << std::endl;

	// Create a Data object
	Data original;
	original.id    = 42;
	original.name  = "Hello 42";
	original.value = 3.14;

	std::cout << "Original pointer : " << &original << std::endl;
	std::cout << "  id    = " << original.id << std::endl;
	std::cout << "  name  = " << original.name << std::endl;
	std::cout << "  value = " << original.value << std::endl;

	// Serialize
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "\nSerialized (uintptr_t): " << raw << std::endl;

	// Deserialize
	Data * recovered = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer : " << recovered << std::endl;
	std::cout << "  id    = " << recovered->id << std::endl;
	std::cout << "  name  = " << recovered->name << std::endl;
	std::cout << "  value = " << recovered->value << std::endl;

	// Verify
	std::cout << "\nPointers equal? "
	          << (recovered == &original ? "YES" : "NO") << std::endl;

	return 0;
}
