#pragma once

struct SDL_Point;

namespace sonic {
	namespace math {

		class vec2D {
		public:

			// Constructors
			vec2D();
			vec2D(double x, double y);
			vec2D(const SDL_Point& point);

			// Returns the length of the vector
			double length() const;

			// Returns the length of the vector squared
			double length_sq() const;

			// Returns the distance to another vector
			double dist_to(const vec2D& other) const;

			// Returns the distance to another vector squared
			double dist_to_sq(const vec2D& other) const;

			// Returns the angle to another vector in degrees
			double angle_to(const vec2D& other) const;

			// Returns a copy of the calling vector rotated by angle
			vec2D rotate(double angle) const;

			// Returns a copy of the normalized calling vector 
			vec2D norm() const;

			// Truncates the length of the vector to size 
			void trunc(double size);

			// Returns the dot product of this with other
			double dot(const vec2D& other) const;

			// Returns a vector that is perpendicular to the calling vector
			vec2D perp() const;

			// Turns the caller into the zero vector
			void zero();

			// Returns whether or not this vector is the zero vector
			bool is_zero() const;

			// Operators
			vec2D& operator+=(const vec2D& other);
			vec2D& operator-=(const vec2D& other);
			vec2D& operator*=(double scale);
			vec2D& operator/=(double scale);

			// Converts to SDL_Point
			operator SDL_Point();

			double x, y;

		};

		// Additional operators
		vec2D operator+(const vec2D& lhs, const vec2D& rhs);
		vec2D operator-(const vec2D& lhs, const vec2D& rhs);
		vec2D operator*(const vec2D& lhs, double scale);
		vec2D operator*(double scale, const vec2D& rhs);
		vec2D operator/(const vec2D& lhs, double scale);
		vec2D operator/(double scale, const vec2D& rhs);
		bool operator<(const vec2D& lhs, const vec2D& rhs);
		bool operator>(const vec2D& lhs, const vec2D& rhs);
		bool operator==(const vec2D& lhs, const vec2D& rhs);
		bool operator!=(const vec2D& lhs, const vec2D& rhs);

	}
}