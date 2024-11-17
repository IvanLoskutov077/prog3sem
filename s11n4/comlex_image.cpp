#include <iostream>
#include <cmath>
#include "complex.hpp"
#include "image.hpp"

using std::cout, std::endl;

void generateJuliaSet(const Complex& c, int width, int height, int maxIter, const std::string& filename) {
    Image image(width, height);
    float xMin = -2.0f, xMax = 2.0f;
    float yMin = -2.0f, yMax = 2.0f;
    float dx = (xMax - xMin) / width;
    float dy = (yMax - yMin) / height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Complex z(xMin + x * dx, yMin + y * dy);
            int iter = 0;
            while (z.norm() < 2.0f && iter < maxIter) {
                z = z * z + c;
                ++iter;
            }
            unsigned char color = static_cast<unsigned char>(255 * iter / maxIter);
            image.setPixel(x, y, color, color, color);
        }
    }
    image.write(filename);
}

void generateMandelbrotSet(int width, int height, int maxIter, const std::string& filename) {
    Image image(width, height);
    float xMin = -2.0f, xMax = 2.0f;
    float yMin = -2.0f, yMax = 2.0f;
    float dx = (xMax - xMin) / width;
    float dy = (yMax - yMin) / height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Complex c(xMin + x * dx, yMin + y * dy);
            Complex z(0, 0);
            int iter = 0;
            while (z.norm() < 2.0f && iter < maxIter) {
                z = z * z + c;
                ++iter;
            }
            unsigned char color = static_cast<unsigned char>(255 * iter / maxIter);
            image.setPixel(x, y, color, color, color);
        }
    }
    image.write(filename);
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cout << "Usage: " << argv[0] << " <real_part> <imag_part> <iterations> <output_file>" << endl;
        return 1;
    }

    float realPart = std::stof(argv[1]);
    float imagPart = std::stof(argv[2]);
    int maxIter = std::stoi(argv[3]);
    std::string outputFile = argv[4];

    Complex c(realPart, imagPart);
    generateJuliaSet(c, 800, 800, maxIter, outputFile);

    return 0;
}