#include "../run.h"

void kernel_additional_case14(float (&A)[2][2], float (&B)[2][2], float (&D)[2][4], float (&E)[4][2],float (&C)[2][2]) {
	float _tmp0[2][2] = {0};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				_tmp0[i][j] = _tmp0[i][j] + (A[i][k] * B[k][j]);
			}
			for (int k = 0; k < 2; ++k) {
				_tmp0[i][j] = _tmp0[i][j] + (D[i][k] * E[k][j]);
			}
		}
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			C[i][j] = _tmp0[i][j];
		}
	}
}
