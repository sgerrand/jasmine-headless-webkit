#include "ConsoleOutput.h"

namespace HeadlessSpecRunner {
  ConsoleOutput::ConsoleOutput() : QObject(),
  showColors(false) {
    outputIO = &std::cout;
  }

  void ConsoleOutput::passed(const QString &specDetail) {
    green();
    *outputIO << '.';
    clear();
    fflush(stdout);

    successes.push(specDetail);
  }

  void ConsoleOutput::failed(const QString &specDetail)
  {
    red();
    *outputIO << 'F';
    clear();
    fflush(stdout);

    failures.push(specDetail);
  }

  void ConsoleOutput::green() {
    if (showColors) std::cout << "\033[0;32m";
  }

  void ConsoleOutput::clear() {
    if (showColors) std::cout << "\033[m";
  }

  void ConsoleOutput::red() {
    if (showColors) std::cout << "\033[0;31m";
  }
}
