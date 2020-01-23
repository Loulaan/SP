#include <iostream>
#include <string>


class ln80c_buffer : public std::streambuf {
private:
    int stringNumber;
    int size;
    std::streambuf* buf;
    bool newString;

public:
    explicit ln80c_buffer(std::streambuf* oBuf) : 
        buf(oBuf), stringNumber(0), size(0), newString(true) {}

protected:
    int_type overflow(int_type c) override {
        if (newString) {
            std::string string = std::to_string(stringNumber);
            if(string.length() < 8) {
                string += std::string(8 - string.length(), ' ');
            }
            buf->sputn(string.data(), 8);
            newString = false;
            ++stringNumber;
            size = 0;
        }
        if (static_cast<char>(c) == '\n') {
            newString = true;
            buf->sputc(c);
        }
        else if (size == 71) {
            newString = true;
            buf->sputc(c);
            buf->sputc('\n');
        } else 
            buf->sputc(c);
        ++size;
        return c;
    }
};
