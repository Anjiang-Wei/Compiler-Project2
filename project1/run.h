#ifndef PROJECT1_RUN_H
#define PROJECT1_RUN_H

void kernel_example(float (&B)[32][16], float (&C)[32][16], float (&A)[32][16]);
void kernel_case1(float (&A)[32][16]);
void kernel_case4(float (&B)[16][32], float (&C)[32][32], float (&A)[16][32]);
void kernel_case5(float (&B)[16][32], float (&C)[32][32], float (&D)[16][32],
    float &alpha, float &beta, float (&A)[16][32]);
void kernel_case6(float (&B)[2][16][7][7], float (&C)[8][16][3][3], float (&A)[2][8][5][5]);
void kernel_case7(float (&A)[32][16], float (&B)[16][32]);
void kernel_case10(float (&B)[10][10], float (&A)[8][8]);
void kernel_additional_case11(int (&A)[32][16], int (&B)[32][16], int (&tmp)[16][32]);
void kernel_additional_case12(float (&B)[3], float (&C)[3], float (&D)[3], float (&A)[3]);
void kernel_additional_case13(float (&B)[3], float (&C)[3], float (&A)[3]);
void kernel_additional_case14(float (&A)[2][2], float (&B)[2][2], float (&D)[2][4], float (&E)[4][2], float (&C)[2][2]);
void kernel_additional_case15(float (&A)[2][2], float (&B)[2][2], float (&D)[2][4], float (&E)[4][2], float (&C)[2][2]);
void kernel_additional_case16(int (&B)[16][32], int (&C)[32][32], int (&D)[16][32],
    int &alpha, int &beta, int (&A)[16][32]);
void kernel_additional_case17(float (&B)[5][5], float (&C)[7], float (&A)[5][5]);
void kernel_additional_case18(int (&B)[10][10], int (&C)[9][64], int& scalar, int (&A)[8][6]);
#endif  // PROJECT1_RUN_H