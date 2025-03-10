
#ifndef SERVICE_EXCEPTION_H
#define SERVICE_EXCEPTION_H
#include <stdexcept>

using namespace std;

class Service_Exception : public runtime_error {
private:
    const char *message;
public:
    Service_Exception(const char *message) : runtime_error(message), message(message) {}

    const char *what() {
        return message;
    };
};
#endif

