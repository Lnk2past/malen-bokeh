// main.cpp
// contains samplue usage of PythonVisualizer.h

#include "malenbokeh/malenbokeh.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void make_data(int size, std::vector<int> &x, std::vector<std::vector<int>>&, std::vector<int>&);

int main()
{
    int size = 100;

    std::vector<int> x_data;
    std::vector<std::vector<int>> y_data;
    std::vector<int> c_data;

    make_data(size, x_data, y_data, c_data);

    mb::MalenBokeh mb;
    auto figure = mb.make_new_figure("Test Plot", malen::kwarg("x_range", std::vector<int>{0,size}), malen::kwarg("y_range", std::vector<int>{0,size}));

    auto sc = mb.plot(figure, "circle", x_data, y_data[0], malen::kwarg("color", c_data));
    auto slider = mb.slider(sc, "Test Scatter", 0, size-1, malen::kwarg("y", y_data));
    mb.generate_html(mb.layout(figure, slider), "test.html");
}

void make_data(int size, std::vector<int> &x_data, std::vector<std::vector<int>> &y_data, std::vector<int> &c_data)
{
    x_data.resize(size);
    y_data.resize(size);
    c_data.resize(size);

    std::mt19937 eng(11);
    std::uniform_int_distribution<int> dis(0,100);
    auto rgen = [&eng, &dis]()
    {
        return dis(eng);
    };

    std::generate_n(std::begin(x_data), size, rgen);
    std::generate_n(std::begin(c_data), size, rgen);

    for (auto &y: y_data)
    {
        y.resize(size);
        std::generate_n(std::begin(y), size, rgen);
    }
}
