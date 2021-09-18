#include <gtest/gtest.h>
#include "header.hpp"

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(points,constructors){
    point a(2,3);
    point b;
    b.x=2;b.y=3;
    EXPECT_EQ(2,a.x);
    EXPECT_EQ(3,a.y);
    EXPECT_EQ(2,b.x);
    EXPECT_EQ(3,b.y);
    EXPECT_EQ(a.y,b.y);
    EXPECT_EQ(a,a);
    EXPECT_EQ(a,b);
}
TEST(points,sum_multi)
{
    point a(2,3);
    point b;
    b.x=2;b.y=3;
    EXPECT_EQ(a+a,a*2);
    EXPECT_EQ(a+a+a,a*3);
    b+=a;
    EXPECT_EQ(b,a+a);
   //// EXPECT_EQ(a+a+a+a,a*4); //  бесконечный запуск ??????
}
// проверка на сингулярность  эллиптической кривой.

//Проверка G∈эллиптическая кривая

// проверка p — простое число

// проверка |p| ≈ 1024 бит, |q| ≈ 160 бит      -  такое ?

// проверка, q – некоторый (достаточно большой) простой делитель числа |E p (a, b)|

//Проверка что 1<xi<q-2