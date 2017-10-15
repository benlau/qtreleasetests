#include <QtQuickTest/quicktest.h>
#include <QtGlobal>

int main(int argc, char **argv)
{
    qputenv("QTEST_FUNCTION_TIMEOUT", "1000");

    return quick_test_main(argc, argv, "QuickTests", QUICK_TEST_SOURCE_DIR);
}
