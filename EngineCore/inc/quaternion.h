#ifndef _QUATERNION_H
#define _QUATERNION_H

#include <cmath>
#include "vector.h"

namespace GameEngine
{
	template<class T>
	class Quaternion
	{
	private:
		T m_vals[4];

	public:
		Quaternion(T w, T x, T y, T z) { m_vals[0] = w; m_vals[1] = x; m_vals[2] = y; m_vals[3] = z; }
		Quaternion() : Quaternion<T>(1, 0, 0, 0) { }
		Quaternion(T angle, Vector3<T> axis);
		Quaternion(Quaternion<T> const& quat2) : Quaternion<T>(quat2.w(), quat2.x(), quat2.y(), quat2.z()) { }
		~Quaternion() { }


		/***********************\
		* Getters and Setters *
		\***********************/
		T w() const { return m_vals[0]; }
		T x() const { return m_vals[1]; }
		T y() const { return m_vals[2]; }
		T z() const { return m_vals[3]; }
		T w(T w) { return m_vals[0] = w; }
		T x(T x) { return m_vals[1] = x; }
		T y(T y) { return m_vals[2] = y; }
		T z(T z) { return m_vals[3] = z; }


		/*************\
		* Operations *
		\*************/
		T magnitude() const;
		T magnitudeSqr() const;

		void normalize();
		Quaternion<T> normalized() const;

		static Quaternion<T> zero();

		/********************************\
		* Assignment Operator overloads *
		\********************************/
		//Assignment
		Quaternion<T> & operator=(Quaternion<T> const& quat2);
		
		//Multiplication, Division Assignment
		Quaternion<T> & operator*=(Quaternion<T> const& quat2);
		Quaternion<T> & operator*=(T scaler);
		Quaternion<T> & operator/=(T scaler);

	};

	typedef Quaternion<float> Quaternionf;


	/***************\
	* Constructors *
	\***************/
	template<class T>
	Quaternion<T>::Quaternion(T angle, Vector3<T> axis)
	{
		angle /= 2;

		if (std::abs(axis.magnitudeSqr() - 1) > 0.0001)
			axis.normalize();

		w(std::cos(angle));
		x(axis.x() * std::sin(angle));
		y(axis.y() * std::sin(angle));
		z(axis.z() * std::sin(angle));
	}

	/************************\
	* Operations Quaternion *
	\************************/
	template<class T>
	T Quaternion<T>::magnitude() const { return std::sqrt(magnitudeSqr()); }
	template<class T>
	T Quaternion<T>::magnitudeSqr() const { return w() * w() + x() * x() + y() * y() + z() * z(); }

	template<class T>
	void Quaternion<T>::normalize()
	{
		if (0 != magnitudeSqr()) *this /= magnitude();
	}
	template<class T>
	Quaternion<T> Quaternion<T>::normalized() const
	{
		return 0 != magnitudeSqr() ? *this / magnitude() : *this;
	}
	
	template<class T>
	Quaternion<T> Quaternion<T>::zero()
	{
		return Quaternion<T>(1, 0, 0, 0);
	}

	/********************************\
	* Operator overloads Quaternion *
	\********************************/
	//Assignment
	template<class T>
	Quaternion<T> & Quaternion<T>::operator=(Quaternion<T> const& quat2)
	{
		w(quat2.w());
		x(quat2.x());
		y(quat2.y());
		z(quat2.z());
		return *this;
	}

	//Multiplication, Division Assignment
	template<class T>
	Quaternion<T> & Quaternion<T>::operator*=(Quaternion const& quat2)
	{
		return *this = quat2 * *this;
	}
	template<class T>
	Quaternion<T> & Quaternion<T>::operator*=(T scaler)
	{
		w(w() * scaler);
		x(x() * scaler);
		y(y() * scaler);
		z(z() * scaler);
		return *this;
	}
	template<class T>
	Quaternion<T> & Quaternion<T>::operator/=(T scaler)
	{
		if (0 != scaler)
		{
			w(w() / scaler);
			x(x() / scaler);
			y(y() / scaler);
			z(z() / scaler);
		}
		return *this;
	}

	//Equals, Not Equals
	template<class T>
	bool operator==(Quaternion<T> const& quat1, Quaternion<T> const& quat2)
	{
		return quat1.w() == quat2.w() && quat1.x() == quat2.x() && quat1.y() == quat2.y() && quat1.z() == quat2.z();
	}
	template<class T>
	bool operator!=(Quaternion<T> const& quat1, Quaternion<T> const& quat2)
	{
		return !(quat1 == quat2);
	}

	//Addition

	//Multiplication
	template<class T>
	Quaternion<T>operator*(Quaternion<T> const& quat1, Quaternion<T> const& quat2)
	{
		return Quaternion<T>(
			quat1.w()*quat2.w() - quat1.x()*quat2.x() - quat1.y()*quat2.y() - quat1.z()*quat2.z(),
			quat1.w()*quat2.x() + quat1.x()*quat2.w() + quat1.y()*quat2.z() - quat1.z()*quat2.y(),
			quat1.w()*quat2.y() - quat1.x()*quat2.z() + quat1.y()*quat2.w() + quat1.z()*quat2.x(),
			quat1.w()*quat2.z() + quat1.x()*quat2.y() - quat1.y()*quat2.x() + quat1.z()*quat2.w())
	}
	template<class T>
	Quaternion<T> operator*(Quaternion<T> const& quat1, T scaler)
	{
		return Quaternion<T>(quat1.w() * scaler, quat1.x() * scaler, quat1.y() * scaler, quat1.z() * scaler);
	}
	template<class T>
	Quaternion<T> operator*(T scaler, Quaternion<T> const& quat2)
	{
		return quat2 * scaler;
	}
	template<class T>
	Quaternion<T> operator/(Quaternion<T> const& quat1, T scaler)
	{
		if (0 == scaler)
			scaler = 1;
		return Quaternion<T>(quat1.w() / scaler, quat1.x() / scaler, quat1.y() / scaler, quat1.z() / scaler);
	}
}

#endif