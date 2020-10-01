#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int16_t asr_16(int16_t m, unsigned int n)
{
    const int16_t logical = (((int16_t) -1) >>1 ) > 0;
    uint16_t fixu = -(logical & (m<0));
    int16_t fix = *(int *) &fixu;
    return (m >> n) | (fix ^ (fix >> n));
}

int32_t asr_32(int32_t m, unsigned int n)
{
    const int32_t logical = (((int32_t) -1) >>1 ) > 0;
    uint32_t fixu = -(logical & (m<0));
    int32_t fix = *(int *) &fixu;
    return (m >> n) | (fix ^ (fix >> n));
}

int64_t asr_64(int64_t m, unsigned int n)
{
    const int64_t logical = (((int64_t) -1) >>1 ) > 0;
    uint64_t fixu = -(logical & (m<0));
    int16_t fix = *(int *) &fixu;
    return (m >> n) | (fix ^ (fix >> n));
}

#define asr_i(m,n) \
    _Generic((m), \
	int16_t: asr_16, \
	int32_t: asr_32, \
	int64_t: asr_64 \
	) (m,n)



int main() {
    int16_t a = 8;
    int32_t b = 64;
    int64_t c = 128;
    printf("asr_i(8,1)= %d\n",asr_i(a,1));
    printf("asr_i(64,2)= %d\n",asr_i(b,2));
    printf("asr_i(128,3)= %ld\n",asr_i(c,3));
    return 0;
}
 
