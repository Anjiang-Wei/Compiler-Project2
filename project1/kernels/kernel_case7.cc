#include "../run.h"

void kernel_case7(float (&A)[32][16],float (&B)[16][32]) {
	float _tmp0[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			_tmp0[i][j] = _tmp0[i][j] + A[j][i];
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			B[i][j] = _tmp0[i][j];
		}
	}
}
