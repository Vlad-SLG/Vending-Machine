
#ifndef DOMAIN_EXCEPTION_H
#define DOMAIN_EXCEPTION_H

#include <stdexcept>

using namespace std;

class Domain_Exception : public runtime_error {
private:
    const char *message;
public:
    Domain_Exception(const char *message) : runtime_error(message), message(message) {}

    const char *what() {
        return message;
    };
};

#endif

