#pragma once

enum Relief
{
    Ground,
    Coin,
};

struct Coordinates
{
    size_t x;
    size_t y;

    Coordinates() = default;
    Coordinates(size_t x, size_t y) :
        x(x), y(y) {}

};