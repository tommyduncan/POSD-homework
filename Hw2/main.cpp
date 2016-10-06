#include "..\cppunitlite\TestHarness.h"
#include "utShapes.h"
#include "Shapes.h"

using namespace std;

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);

    return 0;
}


