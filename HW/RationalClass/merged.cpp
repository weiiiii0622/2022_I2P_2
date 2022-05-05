#include <iostream>
using namespace std;


class Rational
{
    public:
        Rational( int = 0, int = 1 ); // default constructor
        Rational addition( const Rational & ) const; // function addition
        Rational multiplication( const Rational & ) const; // function multi.
        void printRational () const; // print rational format

    private:
        int numerator; // integer numerator
        int denominator; // integer denominator
        void reduce();
}; // end class Rational

int gcd(int a, int b);

Rational::Rational(int a, int b){
    int f = a>b?gcd(a, b):gcd(b,a);
    numerator = a/f;
    denominator = b/f;
}

Rational Rational::addition(const Rational& d) const{
    int f = this->denominator>d.denominator?gcd(this->denominator, d.denominator):gcd(d.denominator, this->denominator);
    int m1 = d.denominator/f;
    int m2 = this->denominator/f;
    Rational ans(this->numerator*m1+d.numerator*m2, this->denominator*m1);
    ans.reduce();
    return ans;
}

Rational Rational::multiplication(const Rational& d) const{
    int f1 = this->numerator>d.denominator?gcd(this->numerator, d.denominator):gcd(d.denominator, this->numerator);
    int f2 = this->denominator>d.numerator?gcd(this->denominator, d.numerator):gcd(d.numerator, this->denominator);
    Rational ans((this->numerator*d.numerator)/(f1*f2), (this->denominator*d.denominator)/(f1*f2));
    ans.reduce();
    return ans;
}

void Rational::printRational() const{
    cout << numerator << '/' << denominator << '\n';
    return;
}

void Rational::reduce(){
    int f = numerator>denominator?gcd(numerator,denominator):gcd(denominator,numerator);
    numerator /= f;
    denominator /=f;

    if(numerator<0 && denominator<0){
        numerator *= -1;
        denominator *= -1;
    }
    else if(denominator<0){
        numerator *= -1;
        denominator *= -1;       
    }
}

int main()
{
    char s1;
    int s2, s3, s4, s5;

    Rational x;

    while(cin >>s1>>s2>>s3>>s4>>s5)
    {
        if(cin.eof())
        {
            break;
        }
        Rational c(s2, s3), d(s4, s5);
        if(s1 == '+')
        {
            x = c.addition( d ); // adds object c and d; sets the value to x
            x.printRational(); // prints rational object x
        }
        else if(s1 == '*')
        {
            x = c.multiplication( d ); // multiplies object c and d
            x.printRational(); // prints rational object x
        }
    }
}

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}