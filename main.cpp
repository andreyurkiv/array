//
// Created by dinamic on 11/10/18.
//

#include <iostream>
#include "my_array.h"

using namespace std;

int main() {

    my_array<int, 3> val;

    val.fill(1);

    for (auto x : val)
        cout << x << endl;



    return 0;
}