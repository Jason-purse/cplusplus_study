#include <iostream>
#include "variable/variables.h"
#include "variable/dataInput.h"
#include "logic-process/LogicProcess.h"

using namespace std;
int main() {
    // 由于这里没有使用命名空间,那么 count / endl 需要通过命名空间进行调用 ...
    std::cout << "Hello, World!" << std::endl;

//    baseType();


    std::cout << "sizeof length " << sizeof(long) << std::endl;

    char a = '0';
    char b = 0; // int = 0;
    std::cout << "char 0 ascii code = " << (int)a << std::endl;

    std::cout << "a    \t bbbbbbbbbb" << std::endl;
    std::cout << "bbbbb \t ccccc" << std::endl;
    std::cout << "ccc\t sdfsdfs" << std::endl;

    string value = "123123";
    cout << "string type contains in std namespace " << value << endl;

//    dataInput();

    logicProcess();


    //
    int data[2][2] = {{1,2},{3,4}};

    // 这仅仅是指向地址 ....
    std::cout << "retrieve data[0][0]:  " << *data[0] << std::endl;
    return 0;
}
