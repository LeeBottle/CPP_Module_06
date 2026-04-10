#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << "--- 무작위 객체 생성 및 포인터 식별 테스트 ---" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base* ptr = generate(); // A, B, C 중 하나가 무작위로 생성됨
		std::cout << "Test " << i + 1 << ": ";
		identify(ptr);
	}

	std::cout << "\n--- 무작위 객체 생성 및 참조자 식별 테스트 ---" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base* ptr = generate();
		std::cout << "Test " << i + 1 << ": ";
		identify(*ptr);
		delete ptr;
	}

	std::cout << "\n--- 잘못된 값(Edge Cases) 식별 테스트 ---" << std::endl;
	std::cout << "1. NULL pointer test: ";
	Base* nullPtr = NULL;
	identify(nullPtr);

	std::cout << "2. Only Base object pointer test: ";
	Base* onlyBasePtr = new Base();
	identify(onlyBasePtr);
	
	std::cout << "3. Only Base object reference test: ";
	identify(*onlyBasePtr);

	delete onlyBasePtr;
	return 0;
}