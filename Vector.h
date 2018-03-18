#pragma once

#include "real.h"
#include <cmath>

template <typename T>
struct Vector2 {
	T x, y;

	Vector2() {}
	explicit Vector2(const T &x)
		: x(x), y(x)
	{}
	Vector2(const Vector2 &other)
		: x(other.x), y(other.y)
	{}
	Vector2(const T &x, const T &y)
		: x(x), y(y)
	{}

	Vector2 operator+() const {
		return Vector3(+x, +y);
	}

	Vector2 operator-() const {
		return Vector3(-x, -y);
	}

	Vector2 operator+(const Vector2 &other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(const Vector2 &other) const {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator*(const T &other) const {
		return Vector2(x * other, y * other);
	}

	Vector2 operator/(const T &other) const {
		return Vector2(x / other, y / other);
	}

	Vector2 &operator+=(const Vector2 &other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2 &operator-=(const Vector2 &other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2 &operator*=(const T &other) {
		x *= other;
		y *= other;
		return *this;
	}

	Vector2 &operator/=(const T &other) {
		x /= other;
		y /= other;
		return *this;
	}

	T operator%(const Vector2 &other) const {
		return x * other.x + y * other.y;
	}

	T cross(const Vector2 &other) const {
		return x * other.y - y * other.x;
	}
};

template <typename T>
struct Vector3 {
	T x, y, z;

	Vector3() {}
	explicit Vector3(const T &x)
		: x(x), y(x), z(x)
	{}
	Vector3(const Vector3 &other)
		: x(other.x), y(other.y), z(other.z)
	{}
	Vector3(const T &x, const T &y, const T &z)
		: x(x), y(y), z(z)
	{}

	Vector3 operator+() const {
		return Vector3(+x, +y, +z);
	}

	Vector3 operator-() const {
		return Vector3(-x, -y, -z);
	}

	Vector3 operator+(const Vector3 &other) const {
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3 operator-(const Vector3 &other) const {
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	Vector3 operator*(const T &other) const {
		return Vector3(x * other, y * other, z * other);
	}

	Vector3 operator/(const T &other) const {
		return Vector3(x / other, y / other, z / other);
	}

	Vector3 &operator+=(const Vector3 &other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3 &operator-=(const Vector3 &other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3 &operator*=(const T &other) {
		x *= other;
		y *= other;
		z *= other;
		return *this;
	}

	Vector3 &operator/=(const T &other) {
		x /= other;
		y /= other;
		z /= other;
		return *this;
	}

	T operator%(const Vector3 &other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3 cross(const Vector3 &other) const {
		return Vector3( y * other.z - z * other.y,
				z * other.x - x * other.z,
				x * other.y - y * other.x);
	}
};

namespace Vectorial {
	static auto length(const auto &v) {
		return std::sqrt(v % v);
	}
	static auto inversedLength(const auto &v) {
		return 1 / length(v);
	}
	static const auto &normalized(const auto &v) {
		return v * inversedLength(v);
	}
	static auto &makeNormalize(auto &v) {
		return v *= inversedLength(v);
	}
}

typedef Vector2<real_t> Vector2f;
typedef Vector3<real_t> Vector3f;
