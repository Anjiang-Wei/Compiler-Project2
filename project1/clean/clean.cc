#include <fstream>
#include <string>


void clean_write(std::string dst, std::string src) {
    std::ofstream out(dst, std::ios::out);
    out << src;
    out.close();
}


int main() {
    clean_write("./kernels/kernel_example.cc",
        "#include \"../run.h\"\n\nvoid kernel_example(float (&B)[32][16], float (&C)[32][16], float (&A)[32][16]) {}");
    clean_write("./kernels/kernel_case1.cc",
        "#include \"../run.h\"\n\nvoid kernel_case1(float (&A)[32][16]) {}");
    clean_write("./kernels/kernel_case4.cc",
        "#include \"../run.h\"\n\nvoid kernel_case4(float (&B)[16][32], float (&C)[32][32], float (&A)[16][32]) {}");
    clean_write("./kernels/kernel_case5.cc",
        "#include \"../run.h\"\n\nvoid kernel_case5(float (&B)[16][32], float (&C)[32][32], float (&D)[16][32], float &alpha, float &beta, float (&A)[16][32]) {}");
    clean_write("./kernels/kernel_case6.cc",
        "#include \"../run.h\"\n\nvoid kernel_case6(float (&B)[2][16][7][7], float (&C)[8][16][3][3], float (&A)[2][8][5][5]) {}");
    clean_write("./kernels/kernel_case7.cc",
        "#include \"../run.h\"\n\nvoid kernel_case7(float (&A)[32][16], float (&B)[16][32]) {}");
    clean_write("./kernels/kernel_case10.cc",
        "#include \"../run.h\"\n\nvoid kernel_case10(float (&B)[10][10], float (&A)[8][8]) {}");
    clean_write("./kernels/kernel_additional_case11.cc",
        "#include \"../run.h\"\n\nvoid kernel_additional_case11(int (&A)[32][16], int (&B)[32][16], int (&tmp)[16][32]) {}");
    clean_write("./kernels/kernel_additional_case12.cc",
        "#include \"../run.h\"\n\nvoid kernel_additional_case12(float (&B)[3], float (&C)[3], float (&D)[3], float (&A)[3]) {}");
    clean_write("./kernels/kernel_additional_case13.cc",
        "#include \"../run.h\"\n\nvoid kernel_additional_case13(float (&B)[3], float (&C)[3], float (&A)[3]) {}");
    clean_write("./kernels/kernel_additional_case14.cc",
        "#include \"../run.h\"\n\nvoid kernel_additional_case14(float (&A)[2][2], float (&B)[2][2], float (&D)[2][4], float (&E)[4][2], float (&C)[2][2]) {}");
    clean_write("./kernels/kernel_additional_case15.cc",
        "#include \"../run.h\"\n\nvoid kernel_additional_case15(float (&A)[2][2], float (&B)[2][2], float (&D)[2][4], float (&E)[4][2], float (&C)[2][2]) {}");
    clean_write("./kernels/kernel_additional_case16.cc",
        "#include \"../run.h\"\n\nvoid kernel_additional_case16(int (&B)[16][32], int (&C)[32][32], int (&D)[16][32], int &alpha, int &beta, int (&A)[16][32]) {}");
    clean_write("./kernels/kernel_additional_case17.cc",
        "#include \"../run.h\"\n\nvoid kernel_additional_case17(float (&B)[5][5], float (&C)[7],float (&A)[5][5]) {}");
    clean_write("./kernels/kernel_additional_case18.cc",
        "#include \"../run.h\"\n\nvoid kernel_additional_case18(int (&B)[10][10], int (&C)[9][64], int& scalar, int (&A)[8][6]) {}");
    return 0;
}