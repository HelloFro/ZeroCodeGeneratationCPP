#pragma once

#include "countries.h"
#include "convert.h"
#include "money.h"

template<Currency<int, int> value, Convert kDir, CountryCode kCode> //Primary template
class Conversion; //If the kCode is not defined in the partial specializations, nothing happens (as by my design)

template<Currency<int, int> value>
class Conversion<value, Convert::kFrom, CountryCode::kUS> //partial specialization
{
private:
	static constexpr Currency<1,00> USD_;

protected:
	Conversion() = default;

public:
	
};

template<Currency<int, int> value>
class Conversion<value, Convert::kFrom, CountryCode::kAU>
{
private:
	static constexpr Currency<0,76> USD_;
};

template<Currency<int, int> value>
class Conversion<value, Convert::kFrom, CountryCode::kNZ>
{
private:
	static constexpr Currency<0, 71> USD_;
};

template<Currency<int, int> value>
class Conversion<value, Convert::kFrom, CountryCode::kFJ>
{
private:
	static constexpr Currency<0, 49> USD_;
};

template<Currency<int, int> value>
class Conversion<value, Convert::kFrom, CountryCode::kTO>
{
private:
	static constexpr Currency<0, 45> USD_;
};

template<Currency<int, int> value>
class Conversion<value, Convert::kFrom, CountryCode::kPG>
{
private:
	static constexpr Currency<0, 31> USD_;
};

template<Currency<int, int> value>
class Conversion<value, Convert::kFrom, CountryCode::kSB>
{
private:
	static constexpr Currency<0, 13> USD_;
};

/*template<> //TODO: handle the conversion from one currency to another (Prof informed me this is unlikely to work but i can try it)
class Conversion<>
{
	
};*/