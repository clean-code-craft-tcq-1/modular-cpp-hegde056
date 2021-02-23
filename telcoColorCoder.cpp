#include "telcoColorCoder.h"

using namespace TelCoColorCoder;

ColorPair::ColorPair(MajorColor major, MinorColor minor):majorColor(major), minorColor(minor){}

MajorColor TelCoColorCoder::ColorPair::getMajor() {
    return majorColor;
    }

MinorColor TelCoColorCoder::ColorPair::getMinor() {
    return minorColor;
    }

std::string TelCoColorCoder::ColorPair::ToString() {
    std::string colorPairStr = MajorColorNames[majorColor];
    colorPairStr += " ";
    colorPairStr += MinorColorNames[minorColor];
    return colorPairStr;
    }


ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return ColorPair(majorColor, minorColor);
    }

int TelCoColorCoder::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }
