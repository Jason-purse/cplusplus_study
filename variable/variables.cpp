//
// Created by Smile Boy on 2022/7/20.
//
#include <iostream>
#include <string>

/**
 * 变量声明,
 * sizeof 占用内存尺寸计算 ...
 * 数组类型
 */

/**
 * 变量声明
 */
void variableDeclared() {

    int value = 12;

}

/**
 * 常量定义
 * 1. 宏常量
 *  通过#define 进行定义常量
 * 2. const 修饰变量
 */
void constVariable() {
#define Day 7
    std::cout << "宏变量值" << Day << "打印结束" << std::endl;

    // 动态运行时不可变 ....
    const int value = 12;
}

/**
 * c++ 基础数据类型
 */
void baseType() {

    std::cout << "基本数据类型介绍" << std::endl;
    /**
     * 一个字节
     *
     * 字符型变量 也可以直接声明一个ascii 码放入内存管理 ....
     *
     * ascii 码作为字符的码值(通过int强转即可得到) ....
     */
    char z = 0;
    std::cout << "char 类型声明" << "值:" << z << std::endl;
    /**
     * 另一个中声明字符的方式 ...
     */
    char x = '0';
    /**
     * 两个字节
     */
    short a = 1;
    std::cout << "short 类型声明" << "值:" << a << std::endl;
    /**
     * 4个字节
     */
    int b = 2;
    std::cout << "int 类型声明" << "值:" << b << std::endl;

    /**
     * 4个字节
     * window 四个字节, linux 32位 4个字节  64位 8个字节
     */
    long c = 4;
    std::cout << "long 类型声明" << "值:" << c << std::endl;
    /**
     * 8个字节 ...
     */
    long long d = 8;
    std::cout << "long long 类型声明" << "值:" << d << std::endl;


    /**
     * boolean 值
     * 内存长度  1个字节 ...
     */
    std::cout << "boolean value" << true << std::endl;


    std::cout << "基础变量介绍完毕" << std::endl;

}

void sizeofFunc() {
    int length = sizeof(4);
    // 可以判断一个类型的所占空间大小
    int length_1 = sizeof(long);
    std::cout << "长度" << length << std::endl;
}

/**
 * 浮点型
 * float
 * double
 */
void floatTypes() {
    /**
     * float 4字节(小数点最多7位)
     * 但是一般显示6位 ...
     */
    float value = 1.2f;
    /**
     * double 8字节 (小数点16位)
     */
    double doubleValue = 2.0;


    // 科学计数法 ...
    double value1 = 1e2;
    double value2 = 1e-2;
}

/**
 * 数组类型
 *
 * 数组都是同一个类型
 * 数组都是连续的内存 ....
 *
 * 数组定义方式:
 *  仅定义不实例化 ...
 * type name [ length ]
 *  指定 数组长度 ...
 * type name [length] = { ... value }
 *
 * 自动推断
 * type name [] = { .... value };
 *
 * 初始化时未填充满的 使用0填充(如果是整型数组)
 *
 * 数组必须有初始长度 ...
 *
 * 一维数组名 的用途
 *  1. 指向数组的第一个元素的内存地址 .
 *  2. 用来统计数组的在内存中的总体长度 ... 通过sizeof 进行统计 ...
 *
 *  当通过指针传递一个数组的时候,我们完全可以通过数组的总体内存长度大小 / 单个数据类型的长度 即可得到整个数组的长度(个数)
 *
 *  二维数组 ...
 *  1.指向数组的首地址
 *  2. 可以查看整体数组所占内存大小 ...
 *  获取一个二维数组的具体是x * y矩的数组,可以通过整体尺寸,查看二维一列的长度大小(然后进行计算) ... 可以得出有多少行(x) ...
 *  // 然后获取一个元素的大小(通过一列的长度进行计算,可以得到一列有多少个元素 ..) ..
 *
 */
void arrayTypes() {
    /**
     * c 风格的字符串
     */
    char value[] = "123123";
    std::string value3 = "123123";

    int value1[] = {12,2,3,4,5};
    int value2[12] = {};


    // 二维数组 初始化的时候,可以不传递行值 ...
    int array[][4] = {1,2,3,4};

    // 也可以它进行分配...
    // 但是这种非常不直观,我们一般很少使用...
    int array1[2][5] = {1,2,3,4,5,1,2,3,4,5};
    int array2[2][2] = {{1,2},{2,3}};

    // 获取一个元素的地址 通过取地址符进行处理 ...

}


