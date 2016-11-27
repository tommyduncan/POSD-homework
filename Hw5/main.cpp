#include "..\cppunitlite\TestHarness.h"
#include "utShapes.h"
#include "Shape.h"

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}
