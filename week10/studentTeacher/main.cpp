#include <iostream>


class Person {
private:
	char* name = nullptr;
	int age = 0;

    void copyFrom(const Person& other);
    void moveFrom(Person&& other) noexcept;
    void free();
	void copyName(const char* name);
public:
	Person(const char* name, int age);
	Person(const Person& other);
	Person(Person&& other) noexcept;
	Person& operator=(const Person& other);
	Person& operator=(Person&& other) noexcept;
	~Person();

	const char* getName() const;
	int getAge() const;

	void print() const;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
