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
    struct TestCase
    {
        int id;
        double w;
        double h;
    };

    vector<TestCase> tests = {
        {0, -1, 1.7},
        {1, 0, 1.70},
        {2, 53.4, 1.70},
        {3, 53.5, 1.70},
        {4, 71.9, 1.70},
        {5, 72.3, 1.70},
        {6, 86.3, 1.70},
        {7, 86.7, 1.70},
        {8, 100.9, 1.70},
        {9, 101.2, 1.70},
        {10, 115.3, 1.70},
        {11, 115.6, 1.70},
        {12, 115.9, 1.70}};

    cout << left << setw(4) << "ID"
         << setw(8) << "w"
         << setw(8) << "h"
         << setw(10) << "BMI"
         << "Category\n";

    for (auto &tc : tests)
    {
        cout << setw(4) << tc.id
             << setw(8) << tc.w
             << setw(8) << tc.h;

        try
        {
            BmiResult res = bmi_calculate(tc.w, tc.h);
            cout << setw(10) << fixed << setprecision(2) << res.bmi_display
                 << res.category;
        }
        catch (const invalid_argument &e)
        {
            cout << setw(10) << "-" << e.what();
        }
        cout << "\n";
    }

    return 0;
}