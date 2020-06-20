#include "../run.h"

void kernel_additional_case17(float (&B)[5][5], float (&C)[7],float (&A)[5][5]) {
	float _tmp0[5][5] = {0};
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			_tmp0[i][j] = _tmp0[i][j] + B[i][j];
			if (i + j < 7 && i + j >= 0) {
				_tmp0[i][j] = _tmp0[i][j] + C[i + j];
			} else {
			}
		}
	}
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			A[i][j] = _tmp0[i][j];
		}
	}
}
