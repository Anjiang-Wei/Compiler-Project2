#include "../run.h"

void kernel_case3(int (&B)[16][32], int (&C)[16][32],int (&A)[16][32]) {
	int _tmp0[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			_tmp0[i][j] = _tmp0[i][j] + B[i][j];
			_tmp0[i][j] = _tmp0[i][j] + C[i][j];
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			A[i][j] = _tmp0[i][j];
		}
	}
}
