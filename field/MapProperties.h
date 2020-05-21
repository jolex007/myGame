#pragma once

enum Relief
{
    Ground,
    Coin
};

struct Coordinates
{
    size_t x;
    size_t y;

    Coordinates() = default;
    Coordinates(size_t x, size_t y) :
        x(x), y(y) {}

    Coordinates& operator=(const Coordinates& rhs) {
        x = rhs.x;
        y = rhs.y;
        return (*this);
    }

    bool operator==(const Coordinates& rhs) {
        return x == rhs.x && y == rhs.y;
    }

    bool operator!=(const Coordinates& rhs) {
        return !((*this) == rhs);
    }

    static int dist(const Coordinates& lhs, const Coordinates& rhs) {
        return abs(int(lhs.x) - int(rhs.x)) + abs(int(lhs.y) - int(rhs.y));
    }
};