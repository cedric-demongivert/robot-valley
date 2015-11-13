#define BOOST_TEST_DYN_LINK
#include "boost/test/unit_test.hpp"
#include "utils/VerticalLinearizer2D.hpp"
#include <cstdlib>

void verticalLinearizer2D_test_array(const std::size_t width, const std::size_t height)
{
  VerticalLinearizer2D linearizer (width, height, -10, -20);

  std::size_t linearized = 0;

  for(int y = -20; y < height; ++y) {
    for(int x = -10; x < width; ++x) {
      BOOST_TEST(linearizer.getX(linearized) == x);
      BOOST_TEST(linearizer.getY(linearized) == y);
      BOOST_TEST(linearizer.linearize(x, y) == linearized);
      linearized += 1;
    }
  }
}

BOOST_AUTO_TEST_CASE( VerticalLinearizer2DTest )
{
  verticalLinearizer2D_test_array(0, 0);
  verticalLinearizer2D_test_array(10, 10);
  verticalLinearizer2D_test_array(20, 60);
  verticalLinearizer2D_test_array(60, 20);
}
