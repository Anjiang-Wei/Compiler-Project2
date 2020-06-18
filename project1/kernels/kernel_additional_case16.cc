#include "../run.h"

void kernel_additional_case16(int (&B)[16][32], int (&C)[32][32], int (&D)[16][32], int &alpha, int &beta,int (&A)[16][32]) {
	int _tmp0[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			for (int k = 0; k < 32; ++k) {
				_tmp0[i][j] = _tmp0[i][j] + alpha / (B[i][k] * C[k][j]);
			}
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			A[i][j] = _tmp0[i][j];
		}
	}
	int _tmp1[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			_tmp1[i][j] = _tmp1[i][j] + A[i][j];
			_tmp1[i][j] = _tmp1[i][j] + (beta * 1000 - 500) / (D[i][j] * 10 + 100);
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			A[i][j] = _tmp1[i][j];
		}
	}
}
