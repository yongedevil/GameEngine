#ifndef _VECTOR_H
#define _VECTOR_H

#include "vectorGeneric.h"

namespace GameEngine
{
	class Vector2f : private Vector2<float>
	{
	private:

	public:
		Vector2f(float x, float y) : Vector2<float>(x, y) { }
		Vector2f() : Vector2<float>() { }
		Vector2f(Vector2f const& vec2) : Vector2<float>(vec2.x(), vec2.y()) { }
		Vector2f(Vector2<float> const& vec2) : Vector2<float>(vec2) { }

		~Vector2f() { }

		/***********************\
		* Getters and Setters *
		\***********************/
		float x() const { return Vector2<float>::x(); }
		float y() const { return Vector2<float>::y(); }
		float x(float x) { return Vector2<float>::x(x); }
		float y(float y) { return Vector2<float>::y(y); }

		/*************\
		* Operations *
		\*************/
		float magnitude() const { return Vector2<float>::magnitude(); }
		float magnitudeSqr() const { return Vector2<float>::magnitudeSqr(); }

		float dot(Vector2f const& vec2) const { return Vector2f::dot(*this, vec2); }

		static Vector2f zero() { return Vector2<float>::zero(); }
		static float dot(Vector2f const& vec1, Vector2f const& vec2) { return Vector2<float>::dot(vec1, vec2); }

		/********************************\
		* Assignment Operator overloads *
		\********************************/
		//Assignment
		Vector2f & operator=(Vector2f const& vec2) { return Vector2f(Vector2<float>::operator=(vec2)); }

		//Addition, Subtraction Assignment
		Vector2f & operator+=(Vector2f const& vec2) { return Vector2f(Vector2<float>::operator+=(vec2)); }
		Vector2f & operator-=(Vector2f const& vec2) { return Vector2f(Vector2<float>::operator-=(vec2)); }

		//Multiplication, Division Assignment
		Vector2f & operator*=(float scaler) { return Vector2f(Vector2<float>::operator*=(scaler)); }
		Vector2f & operator/=(float scaler) { return Vector2f(Vector2<float>::operator/=(scaler)); }
	};

	class Vector3f : private Vector3<float>
	{
	private:

	public:
		Vector3f(float x, float y, float z) : Vector3<float>(x, y, z) { }
		Vector3f() : Vector3<float>() { }
		Vector3f(Vector3f const& vec2) : Vector3<float>(vec2.x(), vec2.y(), vec2.z()) { }
		Vector3f(Vector3<float> const& vec2) : Vector3<float>(vec2) { }

		~Vector3f() { }

		/***********************\
		* Getters and Setters *
		\***********************/
		float x() const { return Vector3<float>::x(); }
		float y() const { return Vector3<float>::y(); }
		float z() const { return Vector3<float>::z(); }
		float x(float x) { return Vector3<float>::x(x); }
		float y(float y) { return Vector3<float>::y(y); }
		float z(float z) { return Vector3<float>::z(z); }

		/*************\
		* Operations *
		\*************/
		float magnitude() const { return Vector3<float>::magnitude(); }
		float magnitudeSqr() const { return Vector3<float>::magnitudeSqr(); }

		float dot(Vector3f const& vec2) const { return Vector3f::dot(*this, vec2); }
		Vector3f cross(Vector3f const& vec2) const { return Vector3f::cross(*this, vec2); }

		static Vector3f zero() { return Vector3<float>::zero(); }
		static float dot(Vector3f const& vec1, Vector3f const& vec2) { return Vector3<float>::dot(vec1, vec2); }
		static Vector3f cross(Vector3f const& vec1, Vector3f const& vec2) { return Vector3f(Vector3<float>::cross(vec1, vec2)); }

		/********************************\
		* Assignment Operator overloads *
		\********************************/
		//Assignment
		Vector3f & operator=(Vector2f const& vec2) { return Vector3f(Vector3<float>::operator=(vec2)); }

		//Addition, Subtraction Assignment
		Vector3f & operator+=(Vector2f const& vec2) { return Vector3f(Vector3<float>::operator+=(vec2)); }
		Vector3f & operator-=(Vector2f const& vec2) { return Vector3f(Vector3<float>::operator-=(vec2)); }

		//Multiplication, Division Assignment
		Vector3f & operator*=(float scaler) { return Vector3f(Vector3<float>::operator*=(scaler)); }
		Vector3f & operator/=(float scaler) { return Vector3f(Vector3<float>::operator/=(scaler)); }
	};


	/*****************************\
	* Operator overloads Vector2 *
	\*****************************/
	//Addition, Subtraction
	Vector2f operator+(Vector2f const& vec1, Vector2f const& vec2)
	{
		return vec1 + vec2;
	}
	Vector2f operator-(Vector2f const& vec1, Vector2f const& vec2)
	{
		return vec1 - vec2;
	}

	//Multiplication, Division
	Vector2f operator*(Vector2f const& vec1, float scaler)
	{
		return vec1 * scaler;
	}
	Vector2f operator*(float scaler, Vector2f const& vec2)
	{
		return vec2 * scaler;
	}
	Vector2f operator/(Vector2f const& vec1, float scaler)
	{
		return vec1 / scaler;
	}


	/*****************************\
	* Operator overloads Vector3 *
	\*****************************/
	//Addition, Subtraction
	Vector3f operator+(Vector3f const& vec1, Vector3f const& vec2)
	{
		return vec1 + vec2;
	}
	Vector3f operator-(Vector3f const& vec1, Vector3f const& vec2)
	{
		return vec1 - vec2;
	}

	//Multiplication, Division
	Vector3f operator*(Vector3f const& vec1, float scaler)
	{
		return vec1 * scaler;
	}
	Vector3f operator*(float scaler, Vector3f const& vec2)
	{
		return vec2 * scaler;
	}
	Vector3f operator/(Vector3f const& vec1, float scaler)
	{
		return vec1 / scaler;
	}


}

#endif