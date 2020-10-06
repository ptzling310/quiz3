#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define asr_i(m,n) \
    _Generic((m), \
	             int16_t: asr_16, \
				 int32_t: asr_32, \
				 int64_t: asr_64 \
	 )(m,n)


#define asr(type) \
    const type logical = (((type) -1) >>1 ) > 0; \
	u##type fixu = -(logical & (m<0)); \
	type fix = *(type *) &fixu; \
	return (m >> n) | (fix ^ (fix >> n))

int16_t asr_16(int16_t m, unsigned int n)
{
    asr(int16_t);
}

int32_t asr_32(int32_t m, unsigned int n)
{
    asr(int32_t);
}

int64_t asr_64(int64_t m, unsigned int n)
{
    asr(int64_t);
}

int main() {
    int16_t a = 8;
	int32_t b = 64;
	int64_t c = 128;
	printf("asr_i(8,1)= %d\n",asr_i(a,1));
	printf("asr_i(64,2)= %d\n",asr_i(b,2));
	printf("asr_i(128,3)= %ld\n",asr_i(c,3));
	return 0;
}
