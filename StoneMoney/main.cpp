#include "stdafx.h"

#include "conversion.h"

int main()
{
	try 
	{
		auto check{ Conversion<Conversion<Currency<4,20>, Convert::kFrom, CountryCode::kAU>.value_, Convert::kTo, CountryCode::kUS>.value_ };
	} catch (...) { return 1; }

    return 0;
}

