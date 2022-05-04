//
// Created by Vladislav.Kuznetsov on 04.05.22.
//
#include <iostream>
#include "../include/example.h"


namespace vcpkgexample {
    void vcpkgexample::VCPKGExampleStruct::get_sql_version() {
        std::cout << "SQL version - 3.0";
    }
}