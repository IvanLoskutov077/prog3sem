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

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <frames> <iterations> <output_folder>" << endl;
        return 1;
    }

    int frames = std::stoi(argv[1]);
    int maxIter = std::stoi(argv[2]);
    std::string outputFolder = argv[3];

    float realStart = -1.5f, realEnd = 0.0f;
    float imagStart = -0.5f, imagEnd = 1.0f;
    float realStep = (realEnd - realStart) / frames;
    float imagStep = (imagEnd - imagStart) / frames;

    for (int i = 0; i < frames; ++i) {
        float realPart = realStart + i * realStep;
        float imagPart = imagStart + i * imagStep;
        Complex c(realPart, imagPart);
        std::string filename = outputFolder + "/complex_" + std::to_string(i) + ".ppm";
        generateJuliaSet(c, 800, 800, maxIter, filename);
    }

    return 0;
}