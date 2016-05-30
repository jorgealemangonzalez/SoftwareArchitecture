#include "Fraction.cpp"
#include <iostream>

int main(){

	Fraction < int > init1(5,10);
	Fraction < int > init2(9,14);

	Fraction <int> res = init1+init2;
	std::cout << "("<< init1._numerator  << " / " << init1._denominator << ") + (" << init2._numerator  << " / " << init2._denominator;
	std::cout << ") = " << res._numerator << " / " << res._denominator <<  std::endl;
	res = init2 * init1;
	std::cout << "("<< init1._numerator  << " / " << init1._denominator << ") * (" << init2._numerator  << " / " << init2._denominator;
	std::cout << ") = " << res._numerator << " / " << res._denominator <<  std::endl;


	Fraction < short > short1(-5,-10);
	Fraction < short > short2(9,-14);

	Fraction <short> res1 = short1+short2;
	std::cout << "("<< short1._numerator  << " / " << short1._denominator << ") + (" << short2._numerator  << " / " << short2._denominator;
	std::cout << ") = " << res1._numerator << " / " << res1._denominator <<  std::endl;
	res1 = short2 * short1;
	std::cout << "("<< short1._numerator  << " / " << short1._denominator << ") * (" << short2._numerator  << " / " << short2._denominator;
	std::cout << ") = " << res1._numerator << " / " << res1._denominator <<  std::endl;

	
	return 0;
}