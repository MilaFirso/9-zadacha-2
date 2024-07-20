#include<iostream>




class Fraction
{
private:
	int numerator_;
	int denominator_;

	int NOD(int numerator, int denominator) //Наименьший общий делитель
	{
		numerator = abs(numerator);
		denominator = abs(denominator);

		while (numerator > 0 && denominator > 0)

			if (numerator > denominator)
				numerator %= denominator;

			else
				denominator %= numerator;

		return numerator + denominator;
	}

public:
	

	friend std::ostream& operator<< (std::ostream& op_l, Fraction op_r);

	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	//Сложение
	Fraction operator+(Fraction op_r) 
	{
		int N_nom = numerator_ * op_r.denominator_ + op_r.numerator_ * denominator_;
		int N_den = denominator_ * op_r.denominator_;
		return Fraction(N_nom,N_den);
	}
	// Вычитание
	Fraction operator-(Fraction op_r)
	{
		int N_nom = numerator_ * op_r.denominator_ - op_r.numerator_ * denominator_;
		int N_den = denominator_ * op_r.denominator_;
		return Fraction(N_nom, N_den);
	}
	// Умножение
	Fraction operator*(Fraction op_r)
	{
		int N_nom = numerator_ * op_r.numerator_;
		int N_den = denominator_ * op_r.denominator_;

		int nod = NOD(N_nom,N_den);

		int nom = N_nom / nod;
		int den = N_den / nod;

		return Fraction(nom, den);
	}	
	// Деление
	Fraction operator/(Fraction op_r)
	{
		int N_nom = numerator_ * op_r.denominator_;
		int N_den = denominator_ * op_r.numerator_;

		int nod = NOD(N_nom, N_den);

		int nom = N_nom / nod;
		int den = N_den / nod;

		return Fraction(nom, den);
	}
	// Инкремент префиксный
	Fraction& operator++()
	{
		this->numerator_ = this->numerator_ + this->denominator_;

		int nod = NOD(this->numerator_, this->denominator_);

		int nom = this->numerator_ / nod;
		int den = this->denominator_ / nod;
		return *this;

}
	//Инкремент постфиксный
	Fraction operator++ (int)  
	{
		Fraction temp = *this;

		this->numerator_ = this->numerator_ + this->denominator_;

		int nod = NOD(this->numerator_, this->denominator_);

		this->numerator_ = this->numerator_ / nod;
		this->denominator_ = this->denominator_ / nod;

		return temp;
	}
	//Декремент префиксный
	Fraction& operator--()
	{
		this->numerator_ = this->numerator_ - this->denominator_;

		int nod = NOD(this->numerator_, this->denominator_);

		int nom = this->numerator_ / nod;
		int den = this->denominator_ / nod;
		return *this;

	}
	//Дектемент постфиксный
	Fraction operator-- (int)
	{
		Fraction temp = *this;

		this->numerator_ = this->numerator_ - this->denominator_;

		int nod = NOD(this->numerator_, this->denominator_);

		this->numerator_ = this->numerator_ / nod;
		this->denominator_ = this->denominator_ / nod;

		return temp;
	}
 
	
};
std::ostream& operator<<(std::ostream& ost, const Fraction fr)
	
{ 
	if (fr.denominator_ == 1)
		ost << fr.numerator_ << std::endl;
	else
		ost << fr.numerator_ << " / " << fr.denominator_ << std::endl;
	return ost;
}

int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	int num1 = 1;
	int den1 = 1;
	int num2 = 1;
	int den2 = 1;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> num1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> den1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> num2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> den2;

	Fraction f1(num1, den1);
	Fraction f2(num2, den2);

	std::cout << f1 << " + " << f2 << " = " << f1 + f2 << std::endl;
	std::cout << f1 << " - " << f2 << " = " << f1 - f2 << std::endl;
	std::cout << f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << f1 << " / " << f2 << " = " << f1 / f2 << std::endl;
	
	std::cout << ++f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << "Значение дроби 1 =" << f1 << std::endl;
	std::cout << --f1 << " * " << f2 << " = " << f1 * f2 << std::endl;
	std::cout << "Значение дроби 1 =" << f1 << std::endl;
	
	std::cout << f1 << " * " << ++f2 << " = " << f1 * f2 << std::endl;
	std::cout << "Значение дроби 2 =" << f2 << std::endl;
	std::cout << f1 << " * " << --f2 << " = " << f1 * f2 << std::endl;
	std::cout << "Значение дроби 2 =" << f2 << std::endl;

	return 0;
}