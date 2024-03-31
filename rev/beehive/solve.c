#include <stdio.h>

__uint8_t v[29] =
{
  86,
  174,
  206,
  236,
  250,
  44,
  118,
  246,
  46,
  22,
  204,
  78,
  250,
  174,
  206,
  204,
  78,
  118,
  44,
  182,
  166,
  2,
  70,
  150,
  12,
  206,
  116,
  150,
  118
};

__uint8_t quad_shift(__uint8_t curr)
{
	return (curr & 0xf0) >> 4 | (curr & 0xf) << 4;
}

__uint8_t double_shift(__uint8_t curr)
{
	return curr >> 2 & 0x33 | (curr & 0x33) << 2;
}

__uint8_t single_shift(__uint8_t curr)
{
	return curr >> 1 & 0x55 | (curr & 0x55) << 1;
}

int main()
{
	int i = -1;

	while (++i < 29)
	{
		__uint8_t shifted = quad_shift(v[i]);
		shifted = double_shift(shifted);
		shifted = single_shift(shifted);
		printf("%c", (char)shifted);
	}
	printf("\n");
}

// bi0sctf{jus7_4noth3r_us3rn4me@bi0s.in}

