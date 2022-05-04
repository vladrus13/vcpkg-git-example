//
// Created by Vladislav.Kuznetsov on 04.05.22.
//
#include <iostream>
#include <sqlite3.h>

namespace vcpkgexample {
    void get_sql_version() {
        std::cout << sqlite3_libversion();
    }
}