#pragma once

#include "countries.h"
#include "convert.h"

template<int value, CountryCode kCode, Convert kDir> //Primary template
class Conversion; //If the kCode is not defined in the partial specializations, nothing happens (as by my design)

template<int value>
class Conversion<value, CountryCode::kUS, Convert::kFrom> //partial specialization
{
private:
	static constexpr int value_{ value };

protected:
	Conversion() = default;

public:
	
};

template<int value>
class Conversion<value, CountryCode::kAU, Convert::kFrom>
{
private:
	constexpr int USD_{ 76 };
};

template<int value>
class Conversion<value, CountryCode::kNZ, Convert::kFrom>
{
private:
	constexpr int USD_{ 71 };
};

template<int value>
class Conversion<value, CountryCode::kFJ, Convert::kFrom>
{
private:
	constexpr int USD_{ 49 };
};

template<int value>
class Conversion<value, CountryCode::kTO, Convert::kFrom>
{
private:
	constexpr int USD_{ 45 };
};

template<int value>
class Conversion<value, CountryCode::kPG, Convert::kFrom>
{
private:
	constexpr int USD_{ 31 };
};

template<int value>
class Conversion<value, CountryCode::kSB, Convert::kFrom>
{
private:
	constexpr int USD_{ 13 };
};

template<CountryCode kCode> //to handle the conversion from one currency to another (Prof informed me this is unlikely to work but i can try it)
class Conversion<kCode, Conversion<CountryCode, int>>
{
	
};