#include "Types.hpp"
#include "SM3.hpp"

int main() {
	u8 test[512];
	u32 tmp = 0x64636261;
	for (int i = 0; i < 16; i++) {
		memcpy(test + i * 4, &tmp, 4);
	}

	SM3 SM3Handler;
	std::string ret = SM3Handler.Hash(test, 64);
	std::cout << ret << std::endl;

	std::string path = "E:\\Learning Materials\\2019-200.zip";
	ret = SM3Handler.Hash(path);
	std::cout << ret << std::endl;

	return 0;
}