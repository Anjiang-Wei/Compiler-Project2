#include "../run.h"

void kernel_case5(float (&B)[16][32], float (&C)[32][32], float (&D)[16][32], float &alpha, float &beta,float (&A)[16][32]) {
	float _tmp0[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			_tmp0[i][j] = _tmp0[i][j] + A[i][j];
			for (int k = 0; k < 32; ++k) {
				_tmp0[i][j] = _tmp0[i][j] + alpha * (B[i][k] * C[k][j]);
			}
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			A[i][j] = _tmp0[i][j];
		}
	}
	float _tmp1[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			_tmp1[i][j] = _tmp1[i][j] + A[i][j];
			_tmp1[i][j] = _tmp1[i][j] + beta * D[i][j];
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			A[i][j] = _tmp1[i][j];
		}
	}
}
