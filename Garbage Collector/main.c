#include <stdio.h>
#include <stdlib.h>

#include "interpreter/vm.interpreter.h"
#include "src/gc.h"
#include "src/utils.h"
#include "interpreter/vars.interpreter.h"
#include "src/tests.h"

int main(int argc, const char **argv) {
    first_test();
    second_test();
    third_test();
    another_test();
    //performance();

    return 0;
}