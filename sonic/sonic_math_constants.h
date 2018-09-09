#pragma once

#include <limits>

namespace sonic {
	namespace math {
		const int     MAXINT     = (std::numeric_limits<int>::max)();
		const int     MININT     = (std::numeric_limits<int>::min)();
		const double  MAXDOUBLE  = (std::numeric_limits<double>::max)();
		const double  MINDOUBLE  = (std::numeric_limits<double>::min)();
		const double  EPSILON    = (std::numeric_limits<double>::epsilon)();
	}
}