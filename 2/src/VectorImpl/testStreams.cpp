//
// Created by loulaan on 10.10.2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <string>
#include "Vector.h"
#include <initializer_list>


int main(){
    Vector<std::ofstream> vStreams;
    for (int i = 0; i < 10; i++) {
        std::string name = std::to_string(i) + ".txt";
        vStreams.push_back(std::ofstream(name));
    }
    std::shuffle(vStreams.begin(), vStreams.end(), std::random_device());
    int num = 0;
    for (auto &stream: vStreams) {
        stream << num;
        stream.close();
        ++num;
    }
    return 0;
}