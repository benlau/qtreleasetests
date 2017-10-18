#include <QString>
#include <QtTest>
#include <QtQuickTest/quicktest.h>
#include "screencontroller.h"

#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
#include <execinfo.h>
#include <unistd.h>
#include <signal.h>
void handleBacktrace(int sig) {
  void *array[100];
  size_t size;

  // get void*'s for all entries on the stack
  size = backtrace(array, 100);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}
#endif

namespace AutoTestRegister {
QUICK_TEST_MAIN(QuickTests)
}

int main(int argc, char *argv[])
{
#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
    signal(SIGSEGV, handleBacktrace);
#endif

    QGuiApplication app(argc, argv);
    Q_UNUSED(app);

    for (int i = 0 ; i < 10;i++) {

    ScreenController screenController;
    screenController.init();
    app.exec();
    }

    return 0;

//    QEventLoop loop;

//    QTimer::singleShot(2000, [&]() {
//        loop.exec();
//    });

//    loop.exec();

//    app.exec();
//    int code;

//    for (int i = 0 ; i < 10 ;i++) {

//        code = quick_test_main(argc, argv, "qtbug-56935", QUICK_TEST_SOURCE_DIR);
//    }

//    return code;
}
