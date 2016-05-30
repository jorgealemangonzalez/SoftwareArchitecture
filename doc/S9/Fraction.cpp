template < class ElementType > 
ElementType MCD(ElementType a, ElementType b){
	if(a % b == 0) return b;
	return MCD((ElementType)b,(ElementType)(a%b));
}

template < class ElementType >
class Fraction {
public:
	ElementType _numerator;
	ElementType _denominator;
	
	Fraction(const ElementType &numerator, const ElementType &denominator):_numerator(numerator),_denominator(denominator){
		ElementType aux = MCD<ElementType>(_numerator,_denominator);
		_numerator /= aux;
		_denominator /= aux;
	}
	Fraction operator+(const Fraction &fract){
		return Fraction((_numerator*fract._denominator + _denominator*fract._numerator) , _denominator * fract._denominator );
	}
	Fraction operator*(const Fraction &fract){
		return Fraction(_numerator*fract._numerator , _denominator * fract._denominator);
	}

};

