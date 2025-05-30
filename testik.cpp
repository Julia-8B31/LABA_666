#include <iostream>
#include <string>

#include "dialog_form.h"



void duration_test(const QString& input,bool expected)
{
    // bool result = true;
    // for (QChar qc : input)
    // {
    //     char c = qc.toLatin1();
    //     if (!isdigit(static_cast<unsigned char>(c))) {
    //         result = false;
    //         break;
    //     }
    // }
    bool result=is_number(input);
    if (result == expected) {
        std::cout << "[PASS] Input: \"" << input.toStdString() << "\"\n";
    } else {
        std::cerr << "[FAIL] Input: \"" << input.toStdString() << "\" — Expected: " << expected << ", Got: " << result << "\n";
    }
}


void test_start()
{
    duration_test("12345",true);
    duration_test("12a45",false);
    duration_test("0000",true);
    duration_test("abc",false);
    duration_test("12 34",false);
}


