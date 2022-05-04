//
// Created by Vladislav.Kuznetsov on 04.05.22.
//
#include <iostream>
#include <sqlite3.h>
#include "../include/example.h"


namespace vcpkgexample {
    void vcpkgexample::VCPKGExampleStruct::get_sql_version() {
        std::cout << sqlite3_libversion();
    }
}