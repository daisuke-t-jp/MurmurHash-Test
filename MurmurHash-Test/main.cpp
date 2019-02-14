//
//  main.cpp
//  MurmurHash-Test
//
//  Created by Daisuke T on 2019/02/07.
//  Copyright © 2019 test. All rights reserved.
//

#include <iostream>

#include "MurmurHash3.h"

void murmur_x86_32_test();
void murmur_x86_128_test();
void murmur_x64_128_test();

uint32_t murmur_x86_32(const char *p, uint32_t seed);
void murmur_x86_128(const char *p, uint32_t seed, uint32_t *out);
void murmur_x64_128(const char *p, uint32_t seed, uint64_t *out);

int main(int argc, const char * argv[]) {
	// insert code here...
	
	murmur_x86_32_test();
	murmur_x86_128_test();
	murmur_x64_128_test();
	
	return 0;
}


const char * keyArray[] = {
	"",
	"H",
	"He",
	"Hel",
	"Hell",
	"Hello",
	"Hello ",
	"Hello W",
	"Hello Wo",
	"Hello Wor",
	"Hello Worl",
	"Hello World",
	"Hello World!",
	"Hello World! ",
	"Hello World! H",
	"Hello World! He",
	"Hello World! Hel",
	"Hello World! Hell",
	"Hello World! Hello",
	"Hello World! Hello ",
	"Hello World! Hello W",
	"Hello World! Hello Wo",
	"Hello World! Hello Wor",
	"Hello World! Hello Worl",
	"Hello World! Hello World",
	"Hello World! Hello World!",
	"Hello World! Hello World! ",
	"Hello World! Hello World! H",
	"Hello World! Hello World! He",
	"Hello World! Hello World! Hel",
	"Hello World! Hello World! Hell",
	"Hello World! Hello World! Hello",
	"Hello World! Hello World! Hello ",
	"Hello World! Hello World! Hello W",
	"Hello World! Hello World! Hello Wo",
	"Hello World! Hello World! Hello Wor",
	"Hello World! Hello World! Hello Worl",
	"Hello World! Hello World! Hello World",
	"Hello World! Hello World! Hello World!",

	"メ",
	"メロ",
	"メロス",
	"メロスは",
	"メロスは激",
	"メロスは激怒",
	"メロスは激怒し",
	"メロスは激怒した",
	"メロスは激怒した。",
	"メロスは激怒した。必",
	"メロスは激怒した。必ず",
	"メロスは激怒した。必ず、",
	"メロスは激怒した。必ず、か",
	"メロスは激怒した。必ず、かの",
	"メロスは激怒した。必ず、かの邪",
	"メロスは激怒した。必ず、かの邪智",
	"メロスは激怒した。必ず、かの邪智暴",
	"メロスは激怒した。必ず、かの邪智暴虐",
	"メロスは激怒した。必ず、かの邪智暴虐の",
	"メロスは激怒した。必ず、かの邪智暴虐の王",
	"メロスは激怒した。必ず、かの邪智暴虐の王を",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除か",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かな",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなけ",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなけれ",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなければ",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなければな",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなければなら",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなければならぬ",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなければならぬと",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなければならぬと決",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなければならぬと決意",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなければならぬと決意し",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなければならぬと決意した",
	"メロスは激怒した。必ず、かの邪智暴虐の王を除かなければならぬと決意した。",
};

void murmur_x86_32_test()
{
	for(int i = 0; i < sizeof(keyArray) / sizeof(keyArray[0]); i++)
	{
		uint32_t out = murmur_x86_32(keyArray[i], 0);
		std::cout << "test_x86_32_unit(\"" << keyArray[i] << "\", hash: 0x" << std::hex << out << ")" << std::endl;
	}

	for(int i = 0; i < sizeof(keyArray) / sizeof(keyArray[0]); i++)
	{
		uint32_t out = murmur_x86_32(keyArray[i], 0x7FFFFFFF);
		std::cout << "test_x86_32_unit(\"" << keyArray[i] << "\", hash: 0x" << std::hex << out << ", seed: 0x" << std::hex << 0x7FFFFFFF << ")" << std::endl;
	}
}

void murmur_x86_128_test()
{
	for(int i = 0; i < sizeof(keyArray) / sizeof(keyArray[0]); i++)
	{
		uint32_t out[4];
		murmur_x86_128(keyArray[i], 0, out);
		std::cout << "test_x86_128_unit(\"" << keyArray[i] << "\", hash: \"0x" << std::hex << out[0] << std::hex << out[1] << std::hex << out[2] << std::hex << out[3] << "\")" << std::endl;
	}

	for(int i = 0; i < sizeof(keyArray) / sizeof(keyArray[0]); i++)
	{
		uint32_t out[4];
		murmur_x86_128(keyArray[i], 0x7FFFFFFF, out);
		std::cout << "test_x86_128_unit(\"" << keyArray[i] << "\", hash: \"0x" << std::hex << out[0] << std::hex << out[1] << std::hex << out[2] << std::hex << out[3] << "\", seed: 0x" << std::hex << 0x7FFFFFFF << ")" << std::endl;
	}
}

void murmur_x64_128_test()
{
	for(int i = 0; i < sizeof(keyArray) / sizeof(keyArray[0]); i++)
	{
		uint64_t out[4];
		murmur_x64_128(keyArray[i], 0, out);
		std::cout << "test_x64_128_unit(\"" << keyArray[i] << "\", hash: \"0x" << std::hex << out[0] << std::hex << out[1] << "\")" << std::endl;
	}

	for(int i = 0; i < sizeof(keyArray) / sizeof(keyArray[0]); i++)
	{
		uint64_t out[4];
		murmur_x64_128(keyArray[i], 0x7FFFFFFF, out);
		std::cout << "test_x64_128_unit(\"" << keyArray[i] << "\", hash: \"0x" << std::hex << out[0] << std::hex << out[1] << "\", seed: 0x" << std::hex << 0x7FFFFFFF << ")" << std::endl;
	}
}

uint32_t murmur_x86_32(const char *p, uint32_t seed)
{
	uint32_t out;
	MurmurHash3_x86_32((void*)p, (int)strlen(p), seed, &out);
	
	return out;
}

void murmur_x86_128(const char *p, uint32_t seed, uint32_t *out)
{
	MurmurHash3_x86_128((void*)p, (int)strlen(p), seed, out);
}

void murmur_x64_128(const char *p, uint32_t seed, uint64_t *out)
{
	MurmurHash3_x64_128((void*)p, (int)strlen(p), seed, out);
}
