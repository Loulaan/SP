//
// Created by loulaan on 10.10.2019.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Vector.h"


int main(){
    Vector<std::ofstream> vStreams;
    for (int i = 1; i < 11; i++) {
        std::string name = std::to_string(i) + ".txt";
        vStreams.push_back(std::ofstream(name));
    }
    std::shuffle(vStreams.begin(), vStreams.end(), std::random_device());
    int num = 1;
    for (auto &stream: vStreams) {
        stream << num;
        stream.close();
        ++num;
    }
    return 0;

}
