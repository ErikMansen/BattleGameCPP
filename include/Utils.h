//
// Created by Erik Mansén on 20/03/2023.
//

#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H


#include "Character.h"
#include <string>

class Utils {

public:
    static int intInRange(int lower, int upper);

    static void serializeInt(int num, const std::string &filename);

    static int deserializeInt(const std::string &filename);

    static void serializeString(const std::string &str, const std::string &filename);

    static std::string deserializeString(const std::string &filename);
};


#endif //UNTITLED_UTILS_H
