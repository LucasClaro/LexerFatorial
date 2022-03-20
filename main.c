#include "tinyexpr.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("%f\n", te_interp("3 + 5!", 0));
}