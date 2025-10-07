#include <bits/stdc++.h>
using namespace std;

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

struct BmiResult
{
    double bmi_display;
    string category;
};

BmiResult bmi_calculate(double weight_kg, double height_m)
{
    if (weight_kg <= 0 || height_m <= 0)
        throw invalid_argument("Invalid input");
    double raw = weight_kg / (height_m * height_m);
    string cat = classify(raw);
    double display = floor(raw * 10 + 0.5) / 10;
    return {display, cat};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}