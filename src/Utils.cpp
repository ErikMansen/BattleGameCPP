//
// Created by Erik Mansén on 20/03/2023.
//

#include <random>
#include <fstream>
#include "../include/Utils.h"

int Utils::intInRange(int lower, int upper) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uniform(lower, upper);
    return uniform(rng);
}

void Utils::serializeInt(int num, const std::string &filename) {
    std::ofstream outfile(filename);
    outfile << num;
    outfile.close();
}

int Utils::deserializeInt(const std::string &filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        throw std::runtime_error("File not found");
    }
    int num;
    infile >> num;
    infile.close();
    return num;
}

void Utils::serializeString(const std::string &str, const std::string &filename) {
    std::ofstream outfile(filename);
    outfile << str;
    outfile.close();
}

std::string Utils::deserializeString(const std::string &filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        throw std::runtime_error("File not found");
    }
    std::string str;
    infile >> str;
    infile.close();
    return str;
}