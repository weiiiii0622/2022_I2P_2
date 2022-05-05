#include <iostream>
#include "function.h" // include definition of class Rational
using namespace std;

#include <iostream>
#include "function.h" // include definition of class Rational
using namespace std;

Rational::Rational(int a, int b){
	int f = a>b?gcd(a, b):gcd(b, a);
	numerator = a/f;
	denominator = b/f;
}

Rational Rational::addition(const Rational& d) const{
	Rational ans(numerator*d.denominator+d.numerator*denominator, denominator*d.denominator);
	ans.reduce();
	return ans;
}

Rational Rational::multiplication(const Rational& d) const{
	Rational ans(numerator*d.numerator, denominator*d.denominator);
	ans.reduce();
	return ans;
}

void Rational::printRational() const{
	cout << numerator << '/' << denominator << '\n';
    return;
}

void Rational::reduce(){
	int f = numerator>denominator?gcd(numerator,denominator):gcd(denominator, numerator);
	numerator /= f;
	denominator /= f;
	if(denominator < 0){
		numerator *= -1;
		denominator *= -1;
	}
}