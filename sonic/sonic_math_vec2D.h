#pragma once

namespace sonic {
	namespace math {
		// 2D space vector
		class vec2D {
		public:

			// Constructors
			vec2D();
			vec2D(double x, double y);

			// Returns the length
			double length() const noexcept;

			// Returns the length squared
			double length_sq() const noexcept;

			// Returns the distance to other
			double dist_to(const vec2D& other) const noexcept;

			// Returns the distance to other squared
			double dist_to_sq(const vec2D& other) const noexcept;

			// Returns the angle to another vector in degrees
			double angle_to(const vec2D& other) const noexcept;

			// Returns the dot product between the caller and other
			double dot(const vec2D& other) const noexcept;

			// Returns a copy of the caller rotated by angle (degrees)
			vec2D rotate(double angle) const noexcept;

			// Returns a copy of the caller normalized
			vec2D norm() const noexcept;

			// Returns a copy of the the caller truncated to size
			vec2D trunc(double size) noexcept;

			// Returns a vector that is perpendicular to the calling vector
			vec2D perp() const noexcept;

			// Turns the caller into the zero vector
			void zero() noexcept;

			// Returns whether or not this vector is the zero vector
			bool is_zero() const noexcept;

			// Operators
			vec2D& operator+=(const vec2D& other) noexcept;
			vec2D& operator-=(const vec2D& other) noexcept;
			vec2D& operator*=(double scale) noexcept;
			vec2D& operator/=(double scale) noexcept;

			double x, y;

		};

		// Additional operators
		vec2D operator+(const vec2D& lhs, const vec2D& rhs) noexcept;
		vec2D operator-(const vec2D& lhs, const vec2D& rhs) noexcept;
		vec2D operator*(const vec2D& lhs, double scale) noexcept;
		vec2D operator*(double scale, const vec2D& rhs) noexcept;
		vec2D operator/(const vec2D& lhs, double scale) noexcept;
		vec2D operator/(double scale, const vec2D& rhs) noexcept;
		bool operator==(const vec2D& lhs, const vec2D& rhs) noexcept;
		bool operator!=(const vec2D& lhs, const vec2D& rhs) noexcept;

	}
}