//
// Created by Smile Boy on 2022/7/21.
//
// 结构体 ...
#include <string>
#include <iostream>
using namespace std;
/**
 * 有点类似于 类的形式 ... 但是c++ 应该使用类更加的简单...
 */
 struct Student {
     string name;
     int age;
     int score;
 } student2;

 struct Students {
     Student student;
     int values[10];
 };

void structureParams(Student student);

void nestStructParams(Students students);
void structureTest() {
     // 这是普通的函数体 ...
     // c++ 这个 struct 关键字声明变量可以省略 ...
     struct Student student;
     student.age = 123;
     student.name = "张三";
     student.score = 64;

     cout << student.age << endl;

     // 另外一种赋值方式
     Student student1 = {
             "李四",
             234,
             53
     };

     // 创建结构体并声明一个 / 多个结构体变量 ...
     structureParams(student1);

     cout << student1.name << endl;

     cout << "nested structure" << endl;
     Students students = {
             {
                 "zs",
                 23,
                 45
             },
             {1,2,3,4}
     };

     nestStructParams(students);

    cout << "real param value " << students.student.name << endl;
    cout << "real param value " << students.values[0] << endl;

 }

 // 结构体指针（也就是是用箭头的情况 区分是自身是一个指针,那么属性访问就用箭头) ..
 // 如果属性也是指针,那么访问属性的属性,也使用箭头 ...
 void structurePointer() {
     Student value = {"李四",23,534};
     Student *student = &value;
     cout << "age" <<      student->age << "name" << student -> name << "score" << student -> score << endl;
 }


 // 值传递,这个数据修改并不会影响原始的数据 ...
 // 因为这是一份新的数据..
 /// c /c++ 中的值传递就是真正的数据copy (深度复制)
 // java 中引用传递 ...

 // 结构体也可以有地址传递 ...
 // 其次也可以使用常量指针 / 指针常量来做相应的限制 ...
 // 例如 常量指针 不允许修改地址中的数据
 // 指针常量,不允许修改引用的地址(指向的地址) ...
 void structureParams(Student student) {
     student.name = "sdfsd";
 }

 void nestStructParams(Students students) {
     students.student.name = "lisi";
     cout << "func inside param value" << students.student.name << endl;
     students.values[0] = 456;
 }

 void test(const Student * student) {
    // 虽然地址中的值无法改变,但是student 是可以改变指向的 ..
    student =  {};

}

void test1(Student * const student) {
    // 这就无法修改指向地址了 ...
}

