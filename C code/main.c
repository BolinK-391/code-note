#include <stdio.h>

int main() {

    int i = 0 , a = 0 , b = 2 , c = 3 , d = 4;

    i = a++  && ++b && d++;
    //逻辑操作符 && 中若其中一个有假( 0 ),则全部为假
    //a++执行时是0,该逻辑为假,则&&后面所有的运算都不需要执行
    //由于a是已经执行了的,所以要++

    i = a++ || ++b || d++;
    //逻辑操作符 || 中当前一项为真( 非0 )的时候,后面就不需要执行了(后面不重要了)
    //此时a为0( 假 ),则执行++b,又因为++b为3( 真 ),则后面的d++无需执行
    //由于a是已经执行了的,所以要++
    
    printf("a = %d\nb = %d\nc = %d\nd = %d\n",a,b,c,d);
}