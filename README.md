# CST136SRS03

Stone Template Pirates

Student Name: Forrest Warner

Issues:

- Wasn't able to find a way to  take excess cents and convert them to dollars
- Wasn't able to fix the precision of the conversions

Notes:

- Macros would work, but for this assignment not allowed to use them.
- templates cannot recieve floating point values as parameters
- constexpr will help out greatly in generating 0 code
- Conversion equation: .[ 00, 100 ) cents US / 1 dollar (country), ie. .76 cents US == 1 dollar AU  
					   1 dollar US / .[ 00, 100 ) cents (country), ie. 1 dollar US == 1.32 AU

----

Project Name: StoneMoney

Purpose:

- Learn to use templates.
- Understand the difference between compile-time and run-time code. 

In this project you will leave the shores of New Zealand and sail NW to the island of [Yap](https://en.wikipedia.org/wiki/Yap). 

The island of Yap has treasure all over the island, and it isn't even hidden. The money isn't in the form of gold, but in the form of large [Rai stones](https://en.wikipedia.org/wiki/Rai_stones). 

You could just walk up and take the money, except you don't know if it is worth the effort. 

To figure this out, you need to write templates to convert the value of local currency to other currencies. 

You need to write templates to convert between currencies. Your goal is to generate **NO** code. Ideally this means everything is calculated by the compiler.  

Here is a conversion table you can use for your software:  

| Country          | Code | Value |
| ---------------- | ---- | ----- |
| United States    | US   | 1.0   |
| Australia        | AU   | 0.76  |
| New Zealand      | NZ   | 0.71  |
| Fiji             | FJ   | 0.49  |
| Tonga            | TO   | 0.45  | 
| Papua New Guinea | PG   | 0.31  |
| Solomon Islands  | SB   | 0.13  | 
| Yap              | YP   | 69.00 |

see: https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2 for a list of 2 letter country codes

----

Citations:

- See:[Metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming).
