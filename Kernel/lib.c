#include <stdint.h>
void * memset(void * destination, int32_t c, uint64_t length)
{
	uint8_t chr = (uint8_t)c;
	char * dst = (char*)destination;

	while(length--)
		dst[length] = chr;

	return destination;
}

void * memcpy(void * destination, const void * source, uint64_t length)
{
	/*
	* memcpy does not support overlapping buffers, so always do it
	* forwards. (Don't change this without adjusting memmove.)
	*
	* For speedy copying, optimize the common case where both pointers
	* and the length are word-aligned, and copy word-at-a-time instead
	* of byte-at-a-time. Otherwise, copy by bytes.
	*
	* The alignment logic below should be portable. We rely on
	* the compiler to be reasonably intelligent about optimizing
	* the divides and modulos out. Fortunately, it is.
	*/
	uint64_t i;

	if ((uint64_t)destination % sizeof(uint32_t) == 0 &&
		(uint64_t)source % sizeof(uint32_t) == 0 &&
		length % sizeof(uint32_t) == 0)
	{
		uint32_t *d = (uint32_t *) destination;
		const uint32_t *s = (const uint32_t *)source;

		for (i = 0; i < length / sizeof(uint32_t); i++)
			d[i] = s[i];
	}
	else
	{
		uint8_t * d = (uint8_t*)destination;
		const uint8_t * s = (const uint8_t*)source;

		for (i = 0; i < length; i++)
			d[i] = s[i];
	}

	return destination;
}
/*
void printRegisters(){
		drawString("Registro RAX: ");
		drawBin(getRegister(RAX));
		newLine();

		drawString("Registro RBX: ");
		drawBin(getRegister(RBX));
		newLine();

		drawString("Registro RCX: ");
		drawBin(getRegister(RCX));
		newLine();

		drawString("Registro RDX: ");
		drawBin(getRegister(RDX));
		newLine();

		drawString("Registro RBP: ");
		drawBin(getRegister(RBP));
		newLine();

		drawString("Registro RDI: ");
		drawBin(getRegister(RDI));
		newLine();

		drawString("Registro RSI: ");
		drawBin(getRegister(RSI));
		newLine();

		drawString("Registro R8: ");
		drawBin(getRegister(R8));
		newLine();

		drawString("Registro R9: ");
		drawBin(getRegister(R9));
		newLine();

		drawString("Registro R10: ");
		drawBin(getRegister(R10));
		newLine();

		drawString("Registro R11: ");
		drawBin(getRegister(R11));
		newLine();

		drawString("Registro R12: ");
		drawBin(getRegister(R12));
		newLine();

		drawString("Registro R13: ");
		drawBin(getRegister(R13));
		newLine();

		drawString("Registro R14: ");
		drawBin(getRegister(R14));
		newLine();

		drawString("Registro R15: ");
		drawBin(Register(R15));
		newLine();
}
*/
