#ifndef CONVERSION_H
#define CONVERSION_H

#include "countries.h"
#include "currency.h"

template<class money, CountryCode kCode> //Primary template
class Conversion; //If the kCode is not defined in the partial specializations, nothing happens (as by my design)

template<int dollar, int cent> //USD is the standard
class Conversion<Currency<dollar, cent>, CountryCode::kUS> //partial specialization 
{
public:
	static constexpr auto USD { Currency<dollar, cent>::value }; //1 US dollar == 1 US dollar
};

template<int dollar, int cent>
class Conversion<Currency<dollar, cent>, CountryCode::kAU>
{
public:
	static constexpr auto USD { Currency<dollar, cent>::value * Currency<0,76>::value }; //76 US cents == 1 AU dollar
};

template<int dollar, int cent>
class Conversion<Currency<dollar, cent>, CountryCode::kNZ>
{
public:
	static constexpr auto USD { Currency<dollar, cent>::value * Currency<0, 71>::value }; //71 US cents == 1 NZ dollar
};

template<int dollar, int cent>
class Conversion<Currency<dollar, cent>, CountryCode::kFJ>
{
public:
	static constexpr auto USD { Currency<dollar, cent>::value * Currency<0, 49>::value }; //49 US cents == 1 FJ dollar
};

template<int dollar, int cent>
class Conversion<Currency<dollar, cent>, CountryCode::kTO>
{
public:
	static constexpr auto USD { Currency<dollar, cent>::value * Currency<0, 45>::value }; //45 US cents == 1 TO dollar
};

template<int dollar, int cent>
class Conversion<Currency<dollar, cent>, CountryCode::kPG>
{
public:
	static constexpr auto USD { Currency<dollar, cent>::value * Currency<0, 31>::value }; //31 US cents == 1 PG dollar
};

template<int dollar, int cent>
class Conversion<Currency<dollar, cent>, CountryCode::kSB>
{
public:
	static constexpr auto USD { Currency<dollar, cent>::value * Currency<0, 13>::value }; //13 US cents == 1 SB dollar
};

template<int dollar, int cent>
class Conversion<Currency<dollar, cent>, CountryCode::kYP>
{
public:
	static constexpr auto USD { Currency<dollar, cent>::value * Currency<69, 00>::value }; //69 US dollars == 1 SB dollar
};

template<int dollar, int cent, CountryCode kFrom> //all currencies are pre converted to US monies
class Conversion<Conversion<Currency<dollar, cent>, kFrom>, CountryCode::kUS>
{
public:
	static constexpr auto value{ Conversion<Currency<dollar,cent>, kFrom>::USD };
};

template<int dollar, int cent, CountryCode kFrom>
class Conversion<Conversion<Currency<dollar, cent>, kFrom>, CountryCode::kAU>
{
public:
	static constexpr auto value { Conversion<Currency<dollar,cent>, kFrom>::USD * Currency<1,32>::value };
};

template<int dollar, int cent, CountryCode kFrom>
class Conversion<Conversion<Currency<dollar, cent>, kFrom>, CountryCode::kNZ>
{
public:
	static constexpr auto value{ Conversion<Currency<dollar,cent>, kFrom>::USD * Currency<1,41>::value };
};

template<int dollar, int cent, CountryCode kFrom>
class Conversion<Conversion<Currency<dollar, cent>, kFrom>, CountryCode::kFJ>
{
public:
	static constexpr auto value{ Conversion<Currency<dollar,cent>, kFrom>::USD * Currency<2,04>::value };
};

template<int dollar, int cent, CountryCode kFrom>
class Conversion<Conversion<Currency<dollar, cent>, kFrom>, CountryCode::kTO>
{
public:
	static constexpr auto value{ Conversion<Currency<dollar,cent>, kFrom>::USD * Currency<2,22>::value };
};

template<int dollar, int cent, CountryCode kFrom>
class Conversion<Conversion<Currency<dollar, cent>, kFrom>, CountryCode::kPG>
{
public:
	static constexpr auto value{ Conversion<Currency<dollar,cent>, kFrom>::USD * Currency<3,23>::value };
};

template<int dollar, int cent, CountryCode kFrom>
class Conversion<Conversion<Currency<dollar, cent>, kFrom>, CountryCode::kSB>
{
public:
	static constexpr auto value{ Conversion<Currency<dollar,cent>, kFrom>::USD * Currency<7,69>::value };
};

template<int dollar, int cent, CountryCode kFrom>
class Conversion<Conversion<Currency<dollar, cent>, kFrom>, CountryCode::kYP>
{
public:
	static constexpr auto value{ Conversion<Currency<dollar,cent>, kFrom>::USD * Currency<0,01>::value };
};

template<int dollar, int cent> //converting to itself
class Conversion<Conversion<Currency<dollar, cent>, CountryCode::kUS>, CountryCode::kUS>
{
public:
	static constexpr auto value{ Currency<dollar,cent>::value };
};

template<int dollar, int cent>
class Conversion<Conversion<Currency<dollar, cent>, CountryCode::kAU>, CountryCode::kAU>
{
public:
	static constexpr auto value{ Currency<dollar,cent>::value };
};

template<int dollar, int cent>
class Conversion<Conversion<Currency<dollar, cent>, CountryCode::kNZ>, CountryCode::kNZ>
{
public:
	static constexpr auto value{ Currency<dollar,cent>::value };
};

template<int dollar, int cent>
class Conversion<Conversion<Currency<dollar, cent>, CountryCode::kFJ>, CountryCode::kFJ>
{
public:
	static constexpr auto value{ Currency<dollar,cent>::value };
};

template<int dollar, int cent>
class Conversion<Conversion<Currency<dollar, cent>, CountryCode::kTO>, CountryCode::kTO>
{
public:
	static constexpr auto value{ Currency<dollar,cent>::value };
};

template<int dollar, int cent>
class Conversion<Conversion<Currency<dollar, cent>, CountryCode::kPG>, CountryCode::kPG>
{
public:
	static constexpr auto value{ Currency<dollar,cent>::value };
};

template<int dollar, int cent>
class Conversion<Conversion<Currency<dollar, cent>, CountryCode::kSB>, CountryCode::kSB>
{
public:
	static constexpr auto value{ Currency<dollar,cent>::value };
};

template<int dollar, int cent>
class Conversion<Conversion<Currency<dollar, cent>, CountryCode::kYP>, CountryCode::kYP>
{
public:
	static constexpr auto value{ Currency<dollar,cent>::value };
};

#endif