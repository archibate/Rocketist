#pragma once

#include "Vector.h"
#include <iostream>

template <typename T>
std::ostream &operator<<(std::ostream &out, const Vector2<T> &v) {
	return out << '(' << v.x << ',' << v.y << ')';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Vector3<T> &v) {
	return out << '(' << v.x << ',' << v.y << ',' << v.z << ')';
}

