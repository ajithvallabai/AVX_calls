// icpc -xCOMMON-AVX512 -O3 sample.cpp -o sampleexe

#include <immintrin.h>
#include <stdio.h>
#include <iostream>

int main() {

  //   /* Initialize the two argument vectors */
  __m512 t0 = _mm512_set_ps(1.0, 14.0, 61.0, 18.0, 11.0, 2.0, 22.0, 6.0,
                          21.0, 3.0, 5.0, 3.0, 3.0, 8.0, 9.0, 11.0);
  __m512 t1 = _mm512_set_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0,
                          12.0, 42.0, 64.0, 18.0, 2.0, 15.0, 11.0, 8.0);

  const __m512i t4 = _mm512_set_epi32(29,25,21,17,13,9,5,1, 
  28,24,20,16,12,8,4,0);

  __m512 row0 = _mm512_permutex2var_ps(t0, t4, t1);

  float* f = (float*)&row0;
  printf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n",
  f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7],
  f[8], f[9], f[10], f[11], f[12], f[13], f[14], f[15]);
// result : 11.000000 3.000000 6.000000 18.000000 8.000000 18.000000 16.000000 8.000000
// 9.000000 5.000000 22.000000 61.000000 11.000000 64.000000 14.000000 6.000000

  return 0;
}