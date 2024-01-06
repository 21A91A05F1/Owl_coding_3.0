/*
We can quickly check if bits in a number are in an alternate pattern (like 101010). 

Compute bitwise XOR (XOR denoted using ^) of n and (n >> 1).
If n has an alternate pattern, then n ^ (n >> 1) operation will produce a number having all bits set.
*/
// function to check if all the bits
// are set or not in the binary
// representation of 'n'
static bool allBitsAreSet(int n)
{
  //code for all set bits or not???
	// if true, then all bits are set
	if (((n + 1) & n) == 0)
		return true;

	// else all bits are not set
	return false;
}

// Function to check if a number
// has bits in alternate pattern
bool bitsAreInAltOrder(unsigned int n)
{
	unsigned int num = n ^ (n >> 1);

	// To check if all bits are set in 'num'
	return allBitsAreSet(num);
}
