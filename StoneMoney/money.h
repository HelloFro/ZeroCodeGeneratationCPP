#ifndef MONEY_H
#define MONEY_H

#include <stdexcept>

template<int dollar, int cents>
class Currency
{
private:
	static constexpr auto verifyD(int const value)
	{
		if (value < 0) { throw std::out_of_range("error: Will not convert negative dollars!"); }
		return value;
	}
	static constexpr auto verifyC(int const value)
	{
		if (value < 0) { throw std::out_of_range("error: Will not convert negative cents!"); }
		if (value >= 100) { throw std::out_of_range("error: Will not convert excess cents!"); }
		return value / 100.0;
	}
protected:
	static constexpr auto value_{ verifyD(dollar) + verifyC(cents) };
};
#endif
//template defining how my monies work. Takes place of using doubles for values

//TODO:Find a way to convert excess amount(s) of cents to their dollar equivalent?