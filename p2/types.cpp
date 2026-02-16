#include <cstring>

int foo() { return 0; }
void bar(void (*)()) {}

char *stcat(char *x, char *y) {
    return strcat(x, y);
}

class A {
public:
    int i;
    int f(int *) { return 0; }
    int g(double (*)(float &)) { return 0; }
};

int main() {

    // int *
    int *p = new int;

    // int &
    int i = 5; int &ir(i);

    // double
    double x = 3.14;

    // A *
    A *a = new A;

    // char const *
    char const *c = "hello";

    // char const &
    char const c2 = '!'; char const &cr(c2);

    // long[7]
    long l[7];

    // int **
    int **pp = new int*;

    // int *&
    int *&rp = *pp;

    // float &
    float f = 1.0f; float &fr(f);

    // int (*)()
    int (*fp)() = &foo;

    // int (*&)()
    int (*&rfp)() = fp;

    // char *(*)(char *, char *)
    char *(*sfp)(char *, char *) = &stcat;

    // int A::*
    int A::*mp = &A::i;

    // int (A::*)(int *)
    int (A::*mfp)(int *) = &A::f;

    // int (A::**)(int *)
    int (A::**mfpp)(int *) = &mfp;

    // int (A::*&)(int *)
    int (A::*&rmfp)(int *) = mfp;

    // int (A::*)(double (*)(float &))
    int (A::*mfp2)(double (*)(float &)) = &A::g;

    // void (*[10])(void (*)())
    void (*pa[10])(void (*)()) = {bar};

}