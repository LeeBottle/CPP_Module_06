#include "Serializer.hpp"
#include <iostream>

int main()
{
	// 1. 테스트용 Data 객체 생성 및 초기화
	Data myData;
	myData.id = 42;
	myData.name = "CPP Module 06";

	// 원래 포인터 주소 저장
	Data* ptrOriginal = &myData;

	std::cout << "=== 직렬화 전 (Original) ===" << std::endl;
	std::cout << "Address: " << ptrOriginal << std::endl;
	std::cout << "Data content: " << ptrOriginal->name << " (ID: " << ptrOriginal->id << ")" << std::endl;
	std::cout << "---------------------------" << std::endl;

	// 2. Serialize: 포인터를 정수(uintptr_t)로 변환
	uintptr_t raw = Serializer::serialize(ptrOriginal);
	std::cout << "Serialized (uintptr_t): " << raw << " (Hex: 0x" << std::hex << raw << std::dec << ")" << std::endl;

	// 3. Deserialize: 정수를 다시 포인터(Data*)로 변환
	Data* ptrDeserialized = Serializer::deserialize(raw);

	std::cout << "---------------------------" << std::endl;
	std::cout << "=== 역직렬화 후 (Deserialized) ===" << std::endl;
	std::cout << "Address: " << ptrDeserialized << std::endl;
	std::cout << "Data content: " << ptrDeserialized->name << " (ID: " << ptrDeserialized->id << ")" << std::endl;

	// 4. 검증: 두 포인터가 동일한지 확인
	if (ptrOriginal == ptrDeserialized) {
		std::cout << "\n✅ 성공: 원래 포인터와 역직렬화된 포인터가 일치합니다!" << std::endl;
	} else {
		std::cout << "\n❌ 실패: 포인터가 일치하지 않습니다." << std::endl;
	}

	return 0;
}