#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestVec3

#include <boost/test/unit_test.hpp>
#include "vec3.h"

namespace utf = boost::unit_test;

BOOST_AUTO_TEST_CASE(init_vector_without_params) {
  vec3 v;
  BOOST_TEST(v[0] == 0);
  BOOST_TEST(v[1] == 0);
  BOOST_TEST(v[2] == 0);
}

BOOST_AUTO_TEST_CASE(element_access) {
  vec3 u{1,2,3};
  BOOST_TEST(u[0] == 1);
  BOOST_TEST(u[1] == 2);
  BOOST_TEST(u[2] == 3);
}

BOOST_AUTO_TEST_CASE(minus_operator) {
  vec3 u{1, 2, 3};
  vec3 v = -u;
  BOOST_TEST(v[0] == -1);
  BOOST_TEST(v[1] == -2);
  BOOST_TEST(v[2] == -3);
}

BOOST_AUTO_TEST_CASE(assignment) {
  vec3 v{1,2,3};
  v[0] = 10;
  BOOST_TEST(v[0] == 10);
  BOOST_TEST(v[1] == 2);
  BOOST_TEST(v[2] == 3);
}

BOOST_AUTO_TEST_CASE(vector_add_to_itself) {
  vec3 v1{1,2,3};
  vec3 v2{4,5,6};
  v1 += v2;
  BOOST_TEST(v1[0] == 5);
  BOOST_TEST(v1[1] == 7);
  BOOST_TEST(v1[2] == 9);
}

BOOST_AUTO_TEST_CASE(vector_multiply_with_number) {
  vec3 v1{1,2,3};
  v1 *= 10;

  BOOST_TEST(v1[0] == 10);
  BOOST_TEST(v1[1] == 20);
  BOOST_TEST(v1[2] == 30);
}

BOOST_AUTO_TEST_CASE(add_two_vectors) {
  vec3 u{1,2,3};
  vec3 v{4,5,6};
  auto r = u + v;
  BOOST_TEST(r[0] == 5);
  BOOST_TEST(r[1] == 7);
  BOOST_TEST(r[2] == 9);
}

BOOST_AUTO_TEST_CASE(substract_two_vectors) {
  vec3 u{1,2,3};
  vec3 v{4,5,6};
  auto r = u - v;
  BOOST_TEST(r[0] == -3);
  BOOST_TEST(r[1] == -3);
  BOOST_TEST(r[2] == -3);
}

BOOST_AUTO_TEST_CASE(vector_product) {
  vec3 u{1,2,3};
  vec3 v{4,5,6};
  auto r = u * v;
  BOOST_TEST(r[0] == 4);
  BOOST_TEST(r[1] == 10);
  BOOST_TEST(r[2] == 18);
}

BOOST_AUTO_TEST_CASE(vector_and_number_product, * utf::tolerance(0.00001)) {
  vec3 v{4,5,6};
  auto r = 0.1 * v;
  auto h = v * 0.1;
  BOOST_TEST(r[0] == 0.4);
  BOOST_TEST(r[1] == 0.5);
  BOOST_TEST(r[2] == 0.6);

  BOOST_TEST(h[0] == 0.4);
  BOOST_TEST(h[1] == 0.5);
  BOOST_TEST(h[2] == 0.6);
}

BOOST_AUTO_TEST_CASE(vector_and_number_division, * utf::tolerance(0.00001)) {
  vec3 v{4, 6, 10};
  auto r = v / 2;
  BOOST_TEST(r[0] == 2);
  BOOST_TEST(r[1] == 3);
  BOOST_TEST(r[2] == 5);
}

BOOST_AUTO_TEST_CASE(dot_product) {
  vec3 u{1, 3, 5};
  vec3 v{2, 4, 6};
  BOOST_TEST(dot(u, v) == 44);
}

BOOST_AUTO_TEST_CASE(length) {
  vec3 v1{1,2,3};
  BOOST_TEST(v1.length_squared() == 14);
}

BOOST_AUTO_TEST_CASE(vector_comparision) {
  vec3 v1{1,2,3};
  vec3 v2{1,2,3};
  vec3 u{4,5,6};
  BOOST_TEST(v1 == v2);
  BOOST_TEST((v1 == u) == false);
}

BOOST_AUTO_TEST_CASE(cross_product) {
  vec3 u{1,2,3};
  vec3 v{4,5,6};
  BOOST_TEST(cross(u, v) == vec3(-3, 6, -3));
}

BOOST_AUTO_TEST_CASE(test_unit_vector, * utf::tolerance(0.0001)) {
  vec3 v(1,2,3);
  auto u = unit_vector(v);
  BOOST_TEST(u[0] == 0.267261241912424);
  BOOST_TEST(u[1] == 0.534522483824849);
  BOOST_TEST(u[2] == 0.801783725737273);
}
