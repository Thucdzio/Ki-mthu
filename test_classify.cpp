// test_classify.cpp
#include <cassert>
#include <string>
using namespace std;

// Copy hàm classify từ main.cpp
string classify(double bmi)
{
    if (bmi < 18.5)
        return "Underweight";
    if (bmi <= 24.9)
        return "Normal";
    if (bmi <= 29.9)
        return "Overweight";
    if (bmi <= 34.9)
        return "Obesity I";
    if (bmi <= 39.9)
        return "Obesity II";
    return "Obesity III";
}

int main()
{
    assert(classify(18.4) == "Underweight");
    assert(classify(18.5) == "Normal");
    assert(classify(24.9) == "Normal");
    assert(classify(25.0) == "Overweight");
    assert(classify(29.9) == "Overweight");
    assert(classify(30.0) == "Obesity I");
    assert(classify(34.9) == "Obesity I");
    assert(classify(35.0) == "Obesity II");
    assert(classify(39.9) == "Obesity II");
    assert(classify(40.0) == "Obesity III");
    assert(classify(-5.0) == "Underweight");
    return 0;
}