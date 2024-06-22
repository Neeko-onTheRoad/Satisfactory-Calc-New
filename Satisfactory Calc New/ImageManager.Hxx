#pragma once

#ifndef _IMAGE_MANAGER_HXX_
#define _IMAGE_MANAGER_HXX_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// ANSI 색상 코드 생성
std::string getANSIColor(uint8_t red, uint8_t green, uint8_t blue) {
    return "\033[48;2;" + std::to_string(red) + ";" + std::to_string(green) + ";" + std::to_string(blue) + "m";
}

// ASCII 문자 세트 (밝기 순)
const char* ASCII_CHARS = " .:-=+*#%@";

// BMP 파일 헤더 구조체
#pragma pack(push, 1)
struct BMPHeader {
    uint16_t fileType;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offsetData;
};

struct DIBHeader {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
};
#pragma pack(pop)

// BMP 파일에서 픽셀 데이터를 읽어오기
std::vector<uint8_t> readBMP(const std::string& filePath, BMPHeader& bmpHeader, DIBHeader& dibHeader) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "파일을 열 수 없습니다: " << filePath << std::endl;
        exit(1);
    }

    // BMP 및 DIB 헤더 읽기
    file.read(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
    file.read(reinterpret_cast<char*>(&dibHeader), sizeof(dibHeader));

    // 픽셀 데이터 읽기
    file.seekg(bmpHeader.offsetData, std::ios::beg);
    std::vector<uint8_t> pixelData(dibHeader.sizeImage);
    file.read(reinterpret_cast<char*>(pixelData.data()), dibHeader.sizeImage);

    file.close();
    return pixelData;
}

// 밝기에 따른 ASCII 문자 선택
char getASCIIChar(uint8_t brightness) {
    int index = brightness * 9 / 255; // 0-255 사이의 밝기를 0-9 사이로 매핑
    return ASCII_CHARS[index];
}

// 픽셀 데이터를 ANSI 색상이 포함된 ASCII 아트로 변환하여 char**로 반환하기
char** convertToANSIASCII(const std::vector<uint8_t>& pixelData, int width, int height, int bitCount) {
    int bytesPerPixel = bitCount / 8;
    int stride = (width * bytesPerPixel + 3) & ~3; // 4바이트 배수로 맞추기

    // 메모리 할당
    char** asciiArt = new char* [height];
    for (int i = 0; i < height; ++i) {
        asciiArt[i] = new char[width * 16]; // ANSI 색상 코드 포함을 고려해 충분히 큰 크기 할당
    }

    for (int y = height - 1; y >= 0; --y) { // BMP는 아래에서 위로 스캔라인 저장
        std::string line;
        for (int x = 0; x < width; ++x) {
            uint8_t blue = pixelData[y * stride + x * bytesPerPixel];
            uint8_t green = pixelData[y * stride + x * bytesPerPixel + 1];
            uint8_t red = pixelData[y * stride + x * bytesPerPixel + 2];

            uint8_t brightness = static_cast<uint8_t>(0.299 * red + 0.587 * green + 0.114 * blue);
            std::string color = getANSIColor(red, green, blue);
            line += color + getASCIIChar(brightness) + "\033[0m";
        }
        strcpy_s(asciiArt[height - 1 - y], line.length() + 1, line.c_str()); // 저장할 때 위에서 아래로 저장
    }

    return asciiArt;
}

#endif