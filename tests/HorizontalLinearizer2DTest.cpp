#define BOOST_TEST_MODULE ROBOT VALLEY TEST MODULE
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "utils/HorizontalLinearizer2D.hpp"
#include <cstdlib>

void horizontalLinearizer2D_test_array(const std::size_t width, const std::size_t height)
{
  HorizontalLinearizer2D linearizer (width, height, -10, -20);

  std::size_t linearized = 0;

  for(int x = -10; x < width; ++x) {
    for(int y = -20; y < height; ++y) {
      BOOST_REQUIRE(linearizer.getX(linearized) == x);
      BOOST_REQUIRE(linearizer.getY(linearized) == y);
      BOOST_REQUIRE(linearizer.linearize(x, y) == linearized);
      linearized += 1;
    }
  }
}

BOOST_AUTO_TEST_CASE( HorizontalLinearizer2DTest )
{
  horizontalLinearizer2D_test_array(0, 0);
  horizontalLinearizer2D_test_array(10, 10);
  horizontalLinearizer2D_test_array(20, 60);
  horizontalLinearizer2D_test_array(60, 20);
}
