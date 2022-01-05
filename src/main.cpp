#include "Types.h"
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

	return 0;
}