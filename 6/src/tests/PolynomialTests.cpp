#include <gtest/gtest.h>
#include "../6/Polynomial.h"
#include <complex>

TEST(PolynomialTests, creationInt){
	Polynomial<int> p(1, 2);
	EXPECT_EQ(1, p.getCoeff(0));
	EXPECT_EQ(2, p.getCoeff(1));
}

TEST(PolynomialTests, multiplyInt){
	Polynomial<int> p(1, 2);
	p.multiply(3);
	EXPECT_EQ(3, p.getCoeff(0));
	EXPECT_EQ(6, p.getCoeff(1));
}

TEST(PolynomialTests, creationComplex){
	std::complex<double> first(1, 1);
	std::complex<double> second(2, 2);

	Polynomial<std::complex<double>> p(first, second);
	
	EXPECT_EQ(std::real(second), std::real(p.getCoeff(1)));
	EXPECT_EQ(std::imag(second), std::imag(p.getCoeff(1)));
}

TEST(PolynomialTests, SchurComplex2Num){
	std::complex<double> first(1, 1);
	std::complex<double> second(2, 2);

	Polynomial<std::complex<double>> p(first, second);
	
	Polynomial<std::complex<double>> schurP = schurTransform(p);

	EXPECT_EQ(0, std::real(schurP.getCoeff(0)));
	EXPECT_EQ(0, std::imag(schurP.getCoeff(0)));
	EXPECT_EQ(6, std::real(schurP.getCoeff(1)));
	EXPECT_EQ(0, std::imag(schurP.getCoeff(1)));
}

TEST(PolynomialTests, SchurComplex3Num){
	std::complex<double> first = std::complex<double>(1, 1);
	std::complex<double> second = std::complex<double>(2, 2);
	std::complex<double> third = std::complex<double>(3, 3);

	Polynomial<std::complex<double>> p(first, second, third);
	
	Polynomial<std::complex<double>> schurP = schurTransform(p);

	EXPECT_EQ(0, std::real(schurP.getCoeff(0)));
	EXPECT_EQ(0, std::imag(schurP.getCoeff(0)));
	EXPECT_EQ(8, std::real(schurP.getCoeff(1)));
	EXPECT_EQ(0, std::imag(schurP.getCoeff(1)));
	EXPECT_EQ(16, std::real(schurP.getCoeff(2)));
	EXPECT_EQ(0, std::imag(schurP.getCoeff(2)));
}