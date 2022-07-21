//
// Created by Smile Boy on 2022/7/20.
//
#include <iostream>

/**
 * 逻辑条件处理 ...
 *
 * for
 * while
 * do-while
 * switch
 * if
 * label: goto
 */

void logicProcess() {

    int value = 23;
    if( value == 23) {
        printf("value gt 23");
    }

    if(value < 23) {
        printf("value lt 23");
    }

    if(true) {
        //
    }
    else {
        //
    }

    if(true) {
        //
    }
    else if(true) {
        //
    }
    else {
        //
    }
    /**
     * switch 中包含一个表达式,case 表示结果  ....
     */
    switch(value - 20) {
        case 3:
            // handle
            break;
        case 24:
            // ....
            break;
        default:
            //
            break;
    }
/**
 * switch 只支持 基础类型中的boolean / char / int ...等整形 不支持字符串 ...
 */
//    switch ("123") {
//        case "12":
//            break;
//        case "0":
//            break;
//        default:
//            break;
//    }
    bool  value3 = false;
    // switch 效率比if 稍高..
    switch (value3) {
        case true:
            break;
        default:
            break;
    }

    int value1  = 3;
    // 0 表示false ...
    while(value1 -- ) {
        // 循环3次 ...
    }

    do {
        // 循环
        // 直接结束 ....
//        break;
    } while (value1 != -1);

    // 这是我们的标记 ...
    label:for(int value  = 0; value < 3; value ++) {
        // .... value 值处理
        // continue;
        continue;
        if(true) {
            break;
        }
        else {
            // 标记是为goto 准备的 ....
            goto label;
        }
    }

}

