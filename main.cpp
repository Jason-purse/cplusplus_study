#include <iostream>
#include "variable/variables.h"
#include "variable/dataInput.h"
#include "logic-process/LogicProcess.h"
//#include "mathModule.h"

#include "SturctureStudy.h"

using namespace std;

void replace(double &value) {
    value = 123;
}

void printfArray(int * array,int length);

void bubbledSort(int * array,int length);

void arrayTests();

int main() {
//     由于这里没有使用命名空间,那么 count / endl 需要通过命名空间进行调用 ...
//    std::cout << "Hello, World!" << std::endl;
//
////    baseType();
//
//
//    std::cout << "sizeof length " << sizeof(long) << std::endl;
//
//    char a = '0';
//    char b = 0; // int = 0;
//    std::cout << "char 0 ascii code = " << (int)a << std::endl;
//
//    std::cout << "a    \t bbbbbbbbbb" << std::endl;
//    std::cout << "bbbbb \t ccccc" << std::endl;
//    std::cout << "ccc\t sdfsdfs" << std::endl;
//
//    string value = "123123";
//    cout << "string type contains in std namespace " << value << endl;
//
////    dataInput();
//
//    logicProcess();
//
//
//    //
//    int data[2][2] = {{1,2},{3,4}};
//
//    // 这仅仅是指向地址 ....
//    std::cout << "retrieve data[0][0]:  " << *data[0] << std::endl;
//
//
//    int array1[2][5] = {1,2,3,4,5,1,2,3,4,5};
//    int totalSize = sizeof(array1);
//    int secondTotalSize = sizeof(array1[0]);
//
//    int x = totalSize / secondTotalSize;
//    long long y = secondTotalSize / sizeof(*array1[0]);
//    cout << "receive data is ["<<x <<"]["<< y << "] array" << endl;
//
//    cout << "replace value ..." << endl;
//    double aa = 23.23f;
//    replace(aa);
//    cout << "replaced value: " << aa <<endl;
//
//    cout << "array forEach" << endl;
//    int array[] = {1,2,3,4,5,6};
//    int *p = NULL;
//    p = array;
//    for(int index = 0 ; index < sizeof(array) / 4; index ++) {
//        std::cout << *p << std::endl;
//        // 指向下一个元素的地址 ...
//        p ++;
//    }
//
//
//    double doubleArray[] = {1,2,3,4,5,6666};
//    double *c = doubleArray;
//    for(int index = 0; index < sizeof(doubleArray) / 8; index ++) {
//        std::cout << *c << std::endl;
//        c++;
//    }
//
//    // 非法地址(野指针) ...
////    c++;
////    std::cout << *c << std::endl;

//    arrayTests();

    structureTest();
    return 0;
}

void arrayTests() {
    cout << "bubble sort" << endl;
    // 这种称为静态数组 .. 动态数组,没法直接通过数组名获取 整体长度 ...
// 详情 https://blog.csdn.net/qq_40692109/article/details/102766573
    int arrays[6] = {0,23,345,12,6,1};
    bubbledSort(arrays,sizeof(arrays) / 4);
    printfArray(arrays,sizeof(arrays) / 4);
}

// 冒泡排序...
void bubbledSort(int * array,int length) {

    int *p = NULL;
    int *temp = NULL;
    for (int i = 0; i < length; ++i) {
        p =  &array[i];
        for(int j = i+ 1;  j < length ; j ++ ) {
            temp =  &array[j];
            if(*p > *temp) {
                *p += *temp;
                *temp = *p - *temp;
                *p -= *temp;
            }
        }
    }
}

void printfArray(int * array,int length) {
    cout << "printf start" << endl;
    for (int i = 0; i < length; ++i) {
        cout << "ele" << array[i] << endl;
    }
    cout << "printf over" << endl;
}


