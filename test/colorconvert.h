#ifndef COLORCONVERT_H
#define COLORCONVERT_H

#include <tuple>
#include <algorithm>
#include <cmath>
#include<QtDebug>

class ColorConvert
{
public:
    ColorConvert();

    std::tuple<int,int,int> RGBinCMY(int r, int g, int b);
    std::tuple<int,int,int> CMYinRGB(int c, int m, int y);

    std::tuple<int,int,int> RGBinHSL(int r, int g, int b);
    std::tuple<int,int,int> HSLinRGB(int h, int s, int l);

    std::tuple<int,int,int> RGBinHSV(int r, int g, int b);
    std::tuple<int,int,int> HSVinRGB(int h, int s, int v);

    std::tuple<int,int,int> RGBinYCbCr(int r, int g, int b,bool is601);
    std::tuple<int,int,int> YCbCrinRGB(int ry, int rcb, int rcr, bool is601);

    std::tuple<int,int,int> RGBinYCoCg(int r, int g, int b);
    std::tuple<int,int,int> YCoCginRGB(int ry, int rco, int rcg);
};

#endif // COLORCONVERT_H
