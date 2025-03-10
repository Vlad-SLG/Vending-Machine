
#ifndef UI_EXCEPTION_H
#define UI_EXCEPTION_H
#include <stdexcept>

using namespace std;

class UI_Exception : public runtime_error {
private:
    const char *message;
public:
    UI_Exception(const char *message) : runtime_error(message), message(message) {}

    const char *what() {
        return message;
    };
};
#endif

