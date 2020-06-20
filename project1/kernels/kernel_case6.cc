#include "../run.h"

void kernel_case6(float (&B)[2][16][7][7], float (&C)[8][16][3][3],float (&A)[2][8][5][5]) {
	float _tmp0[2][8][5][5] = {0};
	for (int n = 0; n < 2; ++n) {
		for (int k = 0; k < 8; ++k) {
			for (int p = 0; p < 5; ++p) {
				for (int q = 0; q < 5; ++q) {
					if (q < 5 && q >= 0) {
						if (p < 5 && p >= 0) {
							if (k < 8 && k >= 0) {
								if (n < 2 && n >= 0) {
									if (q < 5 && q >= 0) {
										if (p < 5 && p >= 0) {
											if (k < 8 && k >= 0) {
												if (n < 2 && n >= 0) {
													_tmp0[n][k][p][q] = _tmp0[n][k][p][q] + A[n][k][p][q];
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
						} else {
						}
					} else {
					}
					for (int c = 0; c < 16; ++c) {
						for (int r = 0; r < 3; ++r) {
							for (int s = 0; s < 3; ++s) {
								if (s < 3 && s >= 0) {
									if (r < 3 && r >= 0) {
										if (c < 16 && c >= 0) {
											if (k < 8 && k >= 0) {
												if (q + s < 7 && q + s >= 0) {
													if (p + r < 7 && p + r >= 0) {
														if (c < 16 && c >= 0) {
															if (n < 2 && n >= 0) {
																_tmp0[n][k][p][q] = _tmp0[n][k][p][q] + B[n][c][p + r][q + s] * C[k][c][r][s];
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
									} else {
									}
								} else {
								}
							}
						}
					}
				}
			}
		}
	}
	for (int n = 0; n < 2; ++n) {
		for (int k = 0; k < 8; ++k) {
			for (int p = 0; p < 5; ++p) {
				for (int q = 0; q < 5; ++q) {
					A[n][k][p][q] = _tmp0[n][k][p][q];
				}
			}
		}
	}
}
