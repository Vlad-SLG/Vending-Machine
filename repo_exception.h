

#ifndef REPO_EXCEPTION_H
#define REPO_EXCEPTION_H
#include <stdexcept>

using namespace std;

class Repo_Exception : public runtime_error {
private:
    const char *message;
public:
    Repo_Exception(const char *message) : runtime_error(message), message(message) {}

    const char *what() {
        return message;
    };
};
#endif
