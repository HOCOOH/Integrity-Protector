#pragma once

#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <cstring>
#include "Types.h"
using namespace Types;

class SM3 {

public:
    SM3() {}
    ~SM3() {}

    // 常量
    u32 T(int j) { return (j < 16 ? 0x79CC4519U : 0x7A879D8AU); }

    // 布尔函数
    u32 FF(int j, u32 X, u32 Y, u32 Z) {
        if(j >= 0 && j < 16) 
            return X ^ Y ^ Z;
        else if (j < 64)
            return (X & Y) | (X & Z) | (Y & Z);
        return 0;
    }

    u32 GG(int j, u32 X, u32 Y, u32 Z) {
        if(j >= 0 && j < 16) 
            return X ^ Y ^ Z;
        else if (j < 64)
            return (X & Y) | ((~X) & Z);
        return 0;
    }

    // 置换函数
    u32 RotateLeft(u32 num, u32 shiftBits){
        shiftBits %= 32;
        return (num << shiftBits) | (num >> (32 - shiftBits));
    }

    u32 P_0(u32 X) {return X ^ RotateLeft(X, 9) ^ RotateLeft(X, 17); }
    u32 P_1(u32 X) {return X ^ RotateLeft(X, 15) ^ RotateLeft(X, 23); }

    void InitIV();
    void CF(const u8* block);
    void DumpU32(const u32* arr, int size);

    u32 EndianSwitch(u32 num) {
        u8* p = (u8*)&num;
        return p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3];
    }

    // API
    std::string Hash(const u8* arr, u32 length);

private:
    // std::array<u32, 8> buf;
    u32 buf[8];

};
