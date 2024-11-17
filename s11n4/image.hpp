#pragma once
#include <vector>
#include <fstream>

class Image
{
public:
    Image(int width, int height) : width(width), height(height), data(width * height * 3, 255) {}

    void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
        int index = (y * width + x) * 3;
        data[index] = r;
        data[index + 1] = g;
        data[index + 2] = b;
    }

    void write(const std::string& filename) const {
        std::ofstream file(filename, std::ios::binary);
        file << "P6\n" << width << " " << height << "\n255\n";
        file.write(reinterpret_cast<const char*>(data.data()), data.size());
    }

private:
    int width;
    int height;
    std::vector<unsigned char> data;
};