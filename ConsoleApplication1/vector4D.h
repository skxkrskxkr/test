#pragma once

#include <iostream>
class vector4D
{
public:
	int x_, y_, z_, k_;

	vector4D()
		: x_(0), y_(0), z_(0),  k_(0)
	{}
	vector4D(const int& x_in, const int& y_in, const int& z_in, const int& k_in)
		: x_(x_in), y_(y_in), z_(z_in), k_(k_in)
	{}
	int operator* (const vector4D& input)
	{
		int ans;

		ans = this->x_ * input.x_;
		ans += this->y_ * input.y_;
		ans += this->z_ * input.z_;
		ans += this->k_ * input.k_;
		return ans;
	}
	vector4D operator+ (const vector4D& input)
	{
		vector4D vec;

		vec.x_ = this->x_ + input.x_;
		vec.y_ = this->y_ + input.y_;
		vec.z_ = this->z_ + input.z_;
		vec.k_ = this->k_ + input.k_;
	}
};

std::ostream& operator<<(std::ostream& os, const vector4D& obj)
{
	os << obj.x_ << " " << obj.y_ << " " << obj.z_ << " " << obj.k_ << std::endl;
	return os;
}