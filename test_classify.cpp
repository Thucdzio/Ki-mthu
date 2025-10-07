
#include <iostream>
#include <stdexcept>
#include <string>
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
    return {raw, classify(raw)};
}

#define TEST(expr)                           \
    do                                       \
    {                                        \
        if (expr)                            \
            cout << "[PASS] " #expr << endl; \
        else                                 \
        {                                    \
            cout << "[FAIL] " #expr << endl; \
            exit(1);                         \
        }                                    \
    } while (0)

bool expect_invalid(double w, double h)
{
    try
    {
        (void)bmi_calculate(w, h);
        return false;
    }
    catch (const invalid_argument &)
    {
        return true;
    }
}

int main()
{
    cout << "=== Running tests ===" << endl;

    TEST(expect_invalid(-1, 1.70));
    TEST(expect_invalid(0, 1.70));
    TEST(expect_invalid(60, 0));

    TEST(bmi_calculate(53.4, 1.70).category == "Underweight");
    TEST(bmi_calculate(53.5, 1.70).category == "Normal");
    TEST(bmi_calculate(71.9, 1.70).category == "Normal");
    TEST(bmi_calculate(72.3, 1.70).category == "Overweight");
    TEST(bmi_calculate(86.3, 1.70).category == "Overweight");
    TEST(bmi_calculate(86.7, 1.70).category == "Obesity I");
    TEST(bmi_calculate(100.9, 1.70).category == "Obesity II");
    TEST(bmi_calculate(101.2, 1.70).category == "Obesity II");
    TEST(bmi_calculate(115.3, 1.70).category == "Obesity III");
    TEST(bmi_calculate(115.6, 1.70).category == "Obesity III");
    TEST(bmi_calculate(115.9, 1.70).category == "Obesity III");

    cout << "✅ All tests passed!" << endl;
    return 0;
}
