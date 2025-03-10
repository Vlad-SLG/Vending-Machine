#include <iostream>
#include "tests.h"
#include "create_tonomat.h"
#include "service.h"
#include "ui.h"
#include "repo_file.h"

using namespace std;
int main() {
    tests();
    Repo r;
    create_tonomat(r);
    Service s(r);
    UI ui(s);
    ui.run();
    cout<<"merge!!!!";
    return 0;
}

