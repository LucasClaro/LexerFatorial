#include "tinyexpr.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    double x, y;
    /* Store variable names and pointers. */
    te_variable vars[] = {{"x", &x}, {"y", &y}};

    int err;
    /* Compile the expression with variables. */
    te_expr *expr = te_compile("sqrt(x^2+y^2)", vars, 2, &err);

    if (expr) {
        x = 3; y = 4;
        const double h1 = te_eval(expr); /* Returns 5. */
        printf("%f\n", h1);

        x = 5; y = 12;
        const double h2 = te_eval(expr); /* Returns 13. */
        printf("%f\n", h2);

        te_free(expr);
    } else {
        printf("Parse error at %d\n", err);
    }

    return 0;
}