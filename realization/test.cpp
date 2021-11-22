#include <gtest/gtest.h>
#include "header.hpp"
#include "point.hpp"
#include "curve.hpp"
#include "client.hpp"
#include "server.hpp"

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
    Curve curve1;
    int c=1;
    EXPECT_ANY_THROW(curve1.choose_curve(c));
}

TEST(curve, q)
{
    Curve c;
    // тк по умолчанию кофактор =1
    EXPECT_EQ(c.get_order(),c.find_biggest_prime_divisor());
}
TEST(client,notation)
{
    mpz_class a=10;
    EXPECT_EQ(two_notation(a),1010);
    mpz_class b=11;
    EXPECT_EQ(two_notation(b),1011);
}

TEST(server, check_equality)
{
    mpz_class Rx("65894259648758421443437230783433096339050672621484269209197919813743417299546",10);
    mpz_class Ry("91008091816188884883650476377516467254553254156350439155365587688628276883287",10);
    mpz_class s("8552812578962852531",10);
    Point R(Rx,Ry);
    mpz_class x("43388560704938532662760090038566541731547416530236634123158546717086656688203",10);
    mpz_class y("75240556658070224935011815458462249982974901475776713224130125628529227783733",10);
    Point x1(x,y);
    std::vector<Point> Y={x1};
    mpz_class binary=1;
    EXPECT_TRUE(check_equality(R,s,Y,binary));
    mpz_class Ry_wrong("145181618888488366725455325415635043915536558643",10);
    Point R_wrong(Rx,Ry_wrong);
    EXPECT_FALSE(check_equality(R_wrong,s,Y,binary));
}

TEST(server,sum){
    mpz_class Rx("37345868539091544051527128367773235403076598078165299078871510572380691238069",10);
    mpz_class Ry("64367411737056574862445324080759056675051064762316895440969671788954556627850",10);
    Point R(Rx,Ry);
    mpz_class x("33158942591319202694013880364699812464227945537966885412147324692873653802917",10);
    mpz_class y("85875540803720275149401408357132968986239117159133030975829892709916152604163",10);
    Point x1(x,y);
    mpz_class x_("37345868539091544051527128367773235403076598078165299078871510572380691238069",10);
    mpz_class y_("64367411737056574862445324080759056675051064762316895440969671788954556627850",10);
    Point x1_(x_,y_);
    std::vector<Point> Y={x1,x1_};
    mpz_class binary=1;
    EXPECT_EQ(sum(binary,Y),R);
}
