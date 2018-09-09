#pragma once

#include <limits>

namespace sonic {
	namespace math {
		const int     MAXINT = (std::numeric_limits<int>::max)();
		const double  MAXDOUBLE = (std::numeric_limits<double>::max)();
		const double  MINDOUBLE = (std::numeric_limits<double>::min)();
		const float   MAXFLOAT = (std::numeric_limits<float>::max)();
		const float   MINFLOAT = (std::numeric_limits<float>::min)();
	}
}