// COSC 2030
// Lab 3
// Tamara Linse

1. //

2. You can detect an overflow when the number turns into a negative number. The number that turns it negative is 243.

3. The value that causes overflow is 199,999,992.

4. The way to detect an overflow is "inf". The value is 35.

5. The value is 171.

6. Float gave me more digits after the decimal, while double rounded to one.  However, double is two times more 
precise than float.  Float = 32 bit. Double = 64 bit.

7.  It does not stop before 4.4 with type float. In other words, it goes on even when i = 4.4.  It has to do with 
precision.  When changed to type double, it does stop before 4.4.

Longer explanation:

Float x = 1.1;
if x != 1.1)
	printf("Print this is not equal");

This program will print the string because it is the same as if (float(1.1) != double(1.1)), which is true. 
Since there are twice as many digits/bits in double than in a float, then there are many doubles that do
not equal similar floats.  

All binary numbers (base 2) can be exactly represented in decimal (base 10), but not all decimals can be 
exactly represented in binary. 

float(1.1) =  %1.00011001100110011001101                              = 1.10000002384185791015625
double(1.1) = %1.0001100110011001100110011001100110011001100110011010 = 1.100000000000000088817841970012523233890533447265625

Therefore, float(1.1) != double (1.1).

Taken from https://randomascii.wordpress.com/2012/06/26/doubles-are-not-floats-so-dont-compare-them/.
