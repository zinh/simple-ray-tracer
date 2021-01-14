#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestRay

#include <boost/test/unit_test.hpp>
#include "ray.h"

BOOST_AUTO_TEST_CASE(test_at_fn) {
  point3 p(1,2,3);
  vec3 v(1,1,1);
  ray r(p, v);
  BOOST_TEST(r.at(10) == point3(11, 12, 13));
}
