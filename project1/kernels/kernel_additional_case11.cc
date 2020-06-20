#include "../run.h"

void kernel_additional_case11(int (&A)[32][16],int (&B)[32][16], int (&tmp)[16][32]) {
	int _tmp0[16][32] = {0};
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			if (i < 16 && i >= 0) {
				if (j < 32 && j >= 0) {
					if (i < 16 && i >= 0) {
						if (j < 32 && j >= 0) {
							if (j < 32 && j >= 0) {
								if (i < 16 && i >= 0) {
									_tmp0[i][j] = _tmp0[i][j] + A[j][i] * A[j][i];
								} else {
								}
							} else {
							}
						} else {
						}
					} else {
					}
				} else {
				}
			} else {
			}
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 32; ++j) {
			tmp[i][j] = _tmp0[i][j];
		}
	}
	int _tmp1[32][16] = {0};
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 16; ++j) {
			if (i < 32 && i >= 0) {
				if (j < 16 && j >= 0) {
					if (j < 16 && j >= 0) {
						if (i < 32 && i >= 0) {
							_tmp1[i][j] = _tmp1[i][j] + tmp[j][i];
						} else {
						}
					} else {
					}
				} else {
				}
			} else {
			}
		}
	}
	for (int i = 0; i < 32; ++i) {
		for (int j = 0; j < 16; ++j) {
			B[i][j] = _tmp1[i][j];
		}
	}
}
