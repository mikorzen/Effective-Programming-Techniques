#include <string>

#include <OrdinalHelper.hpp>


std::string OrdinalHelper::chooseSuffix(int number) {

    std::string suffix = "th";
    switch (number % 10) {
        case 1: suffix = "st"; break;
        case 2: suffix = "nd"; break;
        case 3: suffix = "rd"; break;
    }
    return suffix;
}