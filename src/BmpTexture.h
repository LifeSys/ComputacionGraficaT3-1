#pragma once

#include <GL/freeglut.h>

#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>


#ifndef _WIN32
inline int fopen_s(FILE** file, const char* fileName, const char* mode) {
    if (file == nullptr) {
        return 1;
    }
    *file = std::fopen(fileName, mode);
    return *file == nullptr;
}
#endif

struct BmpImage {
    int width = 0;
    int height = 0;
    std::vector<unsigned char> pixelsRgb;
};

inline bool LoadBmp24(const char* fileName, BmpImage& image) {
    FILE* file = nullptr;
    if (fopen_s(&file, fileName, "rb") != 0 || file == nullptr) {
        return false;
    }

    std::array<unsigned char, 54> header{};
    if (std::fread(header.data(), 1, header.size(), file) != header.size()) {
        std::fclose(file);
        return false;
    }

    if (header[0] != 'B' || header[1] != 'M') {
        std::fclose(file);
        return false;
    }

    std::uint32_t dataOffset = 0;
    std::uint32_t dibSize = 0;
    std::int32_t width = 0;
    std::int32_t height = 0;
    std::uint16_t planes = 0;
    std::uint16_t bitsPerPixel = 0;
    std::uint32_t compression = 0;
    std::memcpy(&dataOffset, &header[10], sizeof(dataOffset));
    std::memcpy(&dibSize, &header[14], sizeof(dibSize));
    std::memcpy(&width, &header[18], sizeof(width));
    std::memcpy(&height, &header[22], sizeof(height));
    std::memcpy(&planes, &header[26], sizeof(planes));
    std::memcpy(&bitsPerPixel, &header[28], sizeof(bitsPerPixel));
    std::memcpy(&compression, &header[30], sizeof(compression));

    if (dibSize < 40 || width <= 0 || height == 0 || planes != 1 || bitsPerPixel != 24 || compression != 0) {
        std::fclose(file);
        return false;
    }

    const int absHeight = height > 0 ? height : -height;
    const int rowStride = ((width * 3 + 3) / 4) * 4;
    std::vector<unsigned char> row(static_cast<size_t>(rowStride));
    image.width = width;
    image.height = absHeight;
    image.pixelsRgb.assign(static_cast<size_t>(width) * absHeight * 3, 0);

    std::fseek(file, static_cast<long>(dataOffset), SEEK_SET);
    for (int y = 0; y < absHeight; ++y) {
        if (std::fread(row.data(), 1, row.size(), file) != row.size()) {
            std::fclose(file);
            return false;
        }
        const int destY = height > 0 ? (absHeight - 1 - y) : y;
        for (int x = 0; x < width; ++x) {
            const size_t src = static_cast<size_t>(x) * 3;
            const size_t dst = (static_cast<size_t>(destY) * width + x) * 3;
            image.pixelsRgb[dst + 0] = row[src + 2];
            image.pixelsRgb[dst + 1] = row[src + 1];
            image.pixelsRgb[dst + 2] = row[src + 0];
        }
    }

    std::fclose(file);
    return true;
}

inline BmpImage CreateCheckerTexture(int width = 64, int height = 64) {
    BmpImage image;
    image.width = width;
    image.height = height;
    image.pixelsRgb.resize(static_cast<size_t>(width) * height * 3);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const bool light = ((x / 8) + (y / 8)) % 2 == 0;
            const size_t i = (static_cast<size_t>(y) * width + x) * 3;
            image.pixelsRgb[i + 0] = light ? 230 : 50;
            image.pixelsRgb[i + 1] = light ? 230 : 120;
            image.pixelsRgb[i + 2] = light ? 230 : 200;
        }
    }
    return image;
}

inline GLuint CreateOpenGlTexture(const char* bmpPath, bool repeat, GLint minMagFilter = GL_LINEAR) {
    BmpImage image;
    if (!LoadBmp24(bmpPath, image)) {
        image = CreateCheckerTexture();
    }

    GLuint textureId = 0;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repeat ? GL_REPEAT : GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repeat ? GL_REPEAT : GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minMagFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, minMagFilter);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.pixelsRgb.data());
    return textureId;
}
