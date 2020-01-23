#include <iostream>
#include "stat_buffer.h"
#include <string>

int main(){
    std::streambuf* oldbuf = std::cin.rdbuf();
    stat_buffer stbuff(oldbuf);
    std::cin.rdbuf(&stbuff);
    std::cout << std::cin.rdbuf();
    std::cout << stbuff.getStrCount() << " " << stbuff.getWordCount() << " " 
        << stbuff.getCharCount() << std::endl;
    std::cin.rdbuf(oldbuf);
    return 0;
}
