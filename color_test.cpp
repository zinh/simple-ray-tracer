#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TestColor

#include <boost/test/unit_test.hpp>
#include <sstream>
#include "color.h"

BOOST_AUTO_TEST_CASE(test_write_color) {
  std::stringstream out;
  color pixel(0.1, 0.2, 0.3);
  write_color(out, pixel);
  write_color(std::cout, pixel);
  BOOST_TEST(std::string("25 51 76\n").compare(out.str()) == 0);
}
