#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include "image.hpp"

using namespace std;

struct Pixel {
    int x, y;
    int distance;
};

bool isValid(const Image& image, int x, int y, const vector<vector<bool>>& visited) {
    return x >= 0 && x < image.width() && y >= 0 && y < image.height() && !visited[y][x] &&
           (image.getPixel(x, y) == Color::White || image.getPixel(x, y) == Color::Red);
}

vector<pair<int, int>> findShortestPath(Image& image) {
    int startX = -1, startY = -1;
    int endX = -1, endY = -1;

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            if (image.getPixel(x, y) == Color::Green) {
                startX = x;
                startY = y;
            }
            if (image.getPixel(x, y) == Color::Red) {
                endX = x;
                endY = y;
            }
        }
    }

    if (startX == -1 || startY == -1 || endX == -1 || endY == -1) {
        puts("Start or end point not found!");
        return {};
    }

    vector<vector<bool>> visited(image.height(), vector<bool>(image.width(), false));
    vector<vector<Pixel>> parent(image.height(), vector<Pixel>(image.width(), {-1, -1, -1}));
    queue<Pixel> q;
    q.push({startX, startY, 0});
    visited[startY][startX] = true;

    while (!q.empty()) {
        Pixel current = q.front();
        q.pop();

        if (current.x == endX && current.y == endY) {
            break;
        }

        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (const auto& dir : directions) {
            int newX = current.x + dir.first;
            int newY = current.y + dir.second;
            if (isValid(image, newX, newY, visited)) {
                q.push({newX, newY, current.distance + 1});
                visited[newY][newX] = true;
                parent[newY][newX] = current;
            }
        }
    }

    vector<pair<int, int>> path;
    Pixel current = {endX, endY, -1};
    while (current.x != -1 && current.y != -1) {
        path.push_back({current.x, current.y});
        current = parent[current.y][current.x];
    }
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    string inputFile = "code/wave_algo/input.ppm";
    string outputFile = "code/wave_algo/output.ppm";

    Image image(inputFile);
    vector<pair<int, int>> path = findShortestPath(image);

    for (const auto& point : path) {
        image.setPixel(point.first, point.second, Color::Blue);
    }

    image.save(outputFile);

    return 0;
}