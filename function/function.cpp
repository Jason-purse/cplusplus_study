//
// Created by Smile Boy on 2022/7/21.
//
#include <iostream>

//函数地址传递
// 指针
// 指针和数组
// 指针和函数 ....

// 引用传递 ...
void invoke(double &value) {
    value = 12;
}

// 函数声明
// 由于c++ 调用函数时,此函数声明必须存在 ...
//那么我们在实现具体函数之前,我们可以声明,先让代码流程可以继续走动 ..
int getValue();
int getValue() {
    return 0;
}
void invoke1() {
    // 函数声明,并不会报错
    getValue();
}

/**
 * 指针在32位操作系统 指针占4个字节 ,64位操作系统8个字节 ...
 */
void pointerStudy() {
    int a = 123;
    int * p = &a;
    std::cout << sizeof(p) << std::endl;

    std::cout << sizeof(int *) << std::endl;

    // 由于指针指向一个地址,那么如何直接指向一个地址呢 ...
    // 以下这段代码指向了一个野指针 ...
    int *b = (int *)0x123123;
}

// 空指针,指向 内存地址为0的空间的变量 =用来初始化未初始化的指针变量 ...
// 空指针不能够访问值(因为它本身就是NULL) ...
// 0~ 255 内存地址(系统暂用,程序无法访问) ...
void nullPointerStudy(){
    int *p = NULL;

    // 野指针,避免出现 ...(指针指向了非法内存空间 ...
}


// const 修饰指针
// 常量指针 ..(根据const 的位置进行名称说明的这一类形式)
void constPointer() {
    int a = 0;
    // 这就称为常量指针
    // 指针指向的地址的值无法修改,但是可以改变指向 ...
    const int *p = &a;
    // 这称为 指针常量
    // 指针的指向无法修改,但是指针指向的地址中的值可以修改 ...
    int* const b = &a;

    // 既修饰指针又修饰 常量的情况
    // 这种情况啥也改不了 ...
    const int * const c = &a;

}

void pointerAndArray() {
    int array[] = {1,2,3,4};
    // 由于array 变量指向数组的首地址 ...
    int *p = array;
    std::cout << *p << std::endl;
    // 通过指针访问地址中的值,称为解引用 ...

    // 根据地址进行for循环 ... item是变量(&取地址,每次给item对应的地址 赋值单个元素) ...
    for (const auto &item : array) {
        std::cout << item << std::endl;
    }

    for(int index = 0 ; index < sizeof(array) / 4; index ++) {
        p = array;
        std::cout << *p << std::endl;
        // 指向下一个元素的地址 ...
        p++;
    }

}
/**
 * 地址传递 ...
 * @param x
 * @param y
 */
void pointerAddressTrans(int *x,int *y) {
    *x = *y;
    *y = *x;
}

// 冒泡排序...
void bubbleArray(int * array) {
    int *temp = NULL;
    int *p = NULL;
    for(int index = 1; index < sizeof(array) / 4 ; index ++ ) {
        temp = &array[index];
        for(int j = 0; j < sizeof(array) / 4; j++) {
            p = &array[j];
            // 将比它大的值进行向后排序
            if(*temp > *p) {
                *p = *temp + *p;
                *temp = *p -  *temp;
                *p -=  *temp;
            }
        }
    }
}