#include <gtest/gtest.h>
#include "realization/header.hpp"
#include "realization/point.hpp"
#include "realization/curve.hpp"


TEST(points, constructors) {
    point a(2, 3);
    point b;
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


    point f(3, 6);
    point a(3, 6);
    point b(3, 6);
    point c(3, 6);
    a += f;
    b = f * 2;
    c = c + f;
    EXPECT_EQ(c.y, a.y);
    EXPECT_EQ(c.y, b.y);
    EXPECT_EQ(a.y, b.y);
    EXPECT_EQ(c.x, a.x);
    EXPECT_EQ(c.x, b.x);
    EXPECT_EQ(a.x, b.x);
    a += f;
    b = f * 3;
    c = c + f;
    EXPECT_EQ(c.y, a.y);
    EXPECT_EQ(c.y, b.y);
    EXPECT_EQ(a.y, b.y);
    EXPECT_EQ(c.x, a.x);
    EXPECT_EQ(c.x, b.x);
    EXPECT_EQ(a.x, b.x);
    a += f;
    b = f * 4;
    c = c + f;
    EXPECT_EQ(c.y, a.y);
    EXPECT_EQ(c.y, b.y);
    EXPECT_EQ(a.y, b.y);
    EXPECT_EQ(c.x, a.x);
    EXPECT_EQ(c.x, b.x);
    EXPECT_EQ(a.x, b.x);
    a += f;
    b = f * 5;
    c = c + f;
    EXPECT_EQ(c.y, a.y);
    EXPECT_EQ(c.y, b.y);
    EXPECT_EQ(a.y, b.y);
    EXPECT_EQ(c.x, a.x);
    EXPECT_EQ(c.x, b.x);
    EXPECT_EQ(a.x, b.x);
    a += f;
    b = f * 6;
    c = c + f;
    EXPECT_EQ(c.y, a.y);
    EXPECT_EQ(c.y, b.y);
    EXPECT_EQ(a.y, b.y);
    EXPECT_EQ(c.x, a.x);
    EXPECT_EQ(c.x, b.x);
    EXPECT_EQ(a.x, b.x);

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
