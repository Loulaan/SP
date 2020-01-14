#pragma once
#include <cmath>
#include <array>
#include <iostream>


class Circle
{
public:
	Circle()
	{
		radius = 0;
	}

	explicit Circle(float r)
	{
		radius = r;
	}

	~Circle() {}

	void setR(float r) {
		radius = r;
	}

    float getR() const{
        return radius;
    }

	float area() {
		return M_PI*pow(this->radius, 2);
	}

private:
	float radius;
};


class Rectangle {
public:
	Rectangle() {
		a = 0;
        b = 0;
	}

	explicit Rectangle(float a, float b) {
		this->a = a;
        this->b = b;
	}
    
    ~Rectangle() {}

    void set(float a, float b){
        this->a = a;
        this->b = b;
    }

    float getA() const{
        return a;
    }

    float getB() const{
        return b;
    }

	void print() {
		std::cout << "A: " << a << "\nB: " << b << std::endl;
	}

	float area(){
		return a * b;
	}

private:
	float a, b;
};


namespace std
{
    template<class T> 
    struct MyTraits;

    template<>
    struct MyTraits<Circle>{
        static int size(const Circle& circle){
            return sizeof(circle.getR());
        }
    };

    template<>
    struct MyTraits<Rectangle>{
        static int size(const Rectangle& rectangle){
            return sizeof(rectangle.getA()) + sizeof(rectangle.getB());
        }
    };
} // namespace std