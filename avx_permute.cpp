// icpc -xCOMMON-AVX512 -O3 sample.cpp -o sampleexe

#include <immintrin.h>
#include <stdio.h>
#include <iostream>

int main() {
  __m256 t0_0 = _mm256_set_ps(1.0, 14.0, 61.0, 18.0, 11.0, 2.0, 22.0, 6.0);
  __m256 t0_1 = _mm256_set_ps(21.0, 3.0, 5.0, 3.0, 3.0, 8.0, 9.0, 11.0);
  __m256 t1_0 = _mm256_set_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);
  __m256 t1_1 = _mm256_set_ps(12.0, 42.0, 64.0, 18.0, 2.0, 15.0, 11.0, 8.0);

  const __m256i t4_0 = _mm256_set_epi32(29,25,21,17,13,9,5,1);
  const __m256i t4_1 = _mm256_set_epi32(28,24,20,16,12,8,4,0);

  const __m256 t5_r = _mm256_permute2f128_ps(t0_0, t1_0, 0x20);

  float* fl = (float*)&t5_r;
  printf("%f %f %f %f %f %f %f %f\n",
  fl[0], fl[1], fl[2], fl[3], fl[4], fl[5], fl[6], fl[7]);

  return 0;
}