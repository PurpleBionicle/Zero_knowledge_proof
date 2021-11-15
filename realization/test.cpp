#include <gtest/gtest.h>
#include "header.hpp"
#include "point.hpp"
#include "curve.hpp"

TEST(points, constructors) {
    Point a(2, 3);
    Point b;
    b.x = 2;
    b.y = 3;
    EXPECT_EQ(2, a.x);
    EXPECT_EQ(3, a.y);
    EXPECT_EQ(2, b.x);
    EXPECT_EQ(3, b.y);
    EXPECT_EQ(a.y, b.y);
    EXPECT_EQ(a, a);
    EXPECT_EQ(a, b);
}

TEST(points, sum_multi) {


    Point f(3, 6);
    Point a(3, 6);
    Point b(3, 6);
    Point c(3, 6);
    a += f;
    b = f * 2;
    c = c + f;
    EXPECT_EQ(a, b);
    EXPECT_EQ(a, c);
    EXPECT_EQ(c, b);
    a += f;
    b = f * 3;
    c = c + f;
    EXPECT_EQ(a, b);
    EXPECT_EQ(a, c);
    EXPECT_EQ(c, b);
    a += f;
    b = f * 4;
    c = c + f;
    EXPECT_EQ(a, b);
    EXPECT_EQ(a, c);
    EXPECT_EQ(c, b);
    a += f;
    b = f * 5;
    c = c + f;
    EXPECT_EQ(a, b);
    EXPECT_EQ(a, c);
    EXPECT_EQ(c, b);
    a += f;
    b = f * 6;
    c = c + f;
    EXPECT_EQ(a, b);
    EXPECT_EQ(a, c);
    EXPECT_EQ(c, b);

    b = b * 0;
    EXPECT_EQ(b.y, 0);
    EXPECT_EQ(b.x, 0);
}

TEST(curve, singularity)
{
    // проверка на сингулярность  эллиптической кривой.
    EXPECT_ANY_THROW(singularity(0,0));
    EXPECT_ANY_THROW(singularity(-3,2));

}
