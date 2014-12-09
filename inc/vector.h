#ifndef _VECTOR_H
#define _VECTOR_H

#include <cmath>

namespace GameEngine
{
	template<class T>
	class Vector2
	{
	private:
		T m_vals[2];

	public:
		Vector2(T x, T y) { m_vals[0] = x; m_vals[1] = y; }
		Vector2() : Vector2<T>(0, 0) { }
		Vector2(Vector2<T> const& vec2) : Vector2<T>(vec2.x(), vec2.y()) { }
		~Vector2() { }


		/***********************\
		* Getters and Setters *
		\***********************/
		T x() const { return m_vals[0]; }
		T y() const { return m_vals[1]; }
		T x(T x) { return m_vals[0] = x; }
		T y(T y) { return m_vals[1] = y; }


		/*************\
		* Operations *
		\*************/
		T magnitude() const;
		T magnitudeSqr() const;

		void normalize();
		Vector2<T> normalized() const;

		T dot(Vector2<T> const& vec2) const { return Vector2<T>::dot(this, vec2); }

		static Vector2<T> zero();
		static T dot(Vector2<T> const& vec1, Vector2<T> const& vec2);

		/********************************\
		* Assignment Operator overloads *
		\********************************/
		//Assignment
		Vector2<T> & operator=(Vector2<T> const& vec2);

		//Addition, Subtraction Assignment
		Vector2<T> & operator+=(Vector2<T> const& vec2);
		Vector2<T> & operator-=(Vector2<T> const& vec2);

		//Multiplication, Division Assignment
		Vector2<T> & operator*=(T scaler);
		Vector2<T> & operator/=(T scaler);
	};

	typedef Vector2<float> Vector2f;


	template<class T>
	class Vector3
	{
	private:
		T m_vals[3];

	public:
		Vector3(T x, T y, T z) { m_vals[0] = x; m_vals[1] = y; m_vals[2] = z; }
		Vector3() : Vector3<T>(0, 0, 0) { }
		Vector3(Vector3<T> const& vec2) : Vector3<T>(vec2.x(), vec2.y(), vec2.z()) { }
		~Vector3() { }


		/***********************\
		 * Getters and Setters *
		\***********************/
		T x() const { return m_vals[0]; }
		T y() const { return m_vals[1]; }
		T z() const { return m_vals[2]; }
		T x(T x) { return m_vals[0] = x; }
		T y(T y) { return m_vals[1] = y; }
		T z(T z) { return m_vals[2] = z; }


		/*************\
		* Operations *
		\*************/
		T magnitude() const;
		T magnitudeSqr() const;

		void normalize();
		Vector3<T> normalized() const;

		T dot(Vector3<T> const& vec2) const { return Vector3<T>::dot(this, vec2); }
		Vector3<T> cross(Vector3<T> const& vec2) const { return Vector3<T>::cross(this, vec2); }

		static Vector3<T> zero();
		static T dot(Vector3<T> const& vec1, Vector3<T> const& vec2);
		static Vector3<T> cross(Vector3<T> const& vec1, Vector3<T> const& vec2);
	

		/********************************\
		* Assignment Operator overloads *
		\********************************/
		//Assignment
		Vector3<T> & operator=(Vector3<T> const& vec2);

		//Addition, Subtraction Assignment
		Vector3<T> & operator+=(Vector3<T> const& vec2);
		Vector3<T> & operator-=(Vector3<T> const& vec2);

		//Multiplication, Division Assignment
		Vector3<T> & operator*=(T scaler);
		Vector3<T> & operator/=(T scaler);
	};

	typedef Vector3<float> Vector3f;




	/*********************\
	* Operations Vector2 *
	\*********************/
	template<class T>
	T Vector2<T>::magnitude() const { return std::sqrt(magnitudeSqr()); }
	template<class T>
	T Vector2<T>::magnitudeSqr() const { return x() * x() + y() * y(); }

	template<class T>
	void Vector2<T>::normalize()
	{
		if (0 != magnitudeSqr())
			*this /= magnitude();
	}
	template<class T>
	Vector2<T> Vector2<T>::normalized() const
	{
		return magnitudeSqr() != 0 ? *this / magnitude() : *this;
	}

	template<class T>
	Vector2<T> Vector2<T>::zero()
	{
		return Vector2<T>(0, 0);
	}

	template<class T>
	T Vector2<T>::dot(Vector2<T> const& vec1, Vector2<T> const& vec2)
	{
		return vec1.x() * vec2.x() + vec1.y() * vec2.y();
	}

	/*****************************\
	* Operator overloads Vector2 *
	\*****************************/
	//Assignment
	template<class T>
	Vector2<T> & Vector2<T>::operator=(Vector2<T> const& vec2)
	{
		x(vec2.x());
		y(vec2.y());
		return *this;
	}

	//Addition, Subtraction Assignment
	template<class T>
	Vector2<T> & Vector2<T>::operator+=(Vector2<T> const& vec2)
	{
		x(x() + vec2.x());
		y(y() + vec2.y());
		return *this;
	}
	template<class T>
	Vector2<T> & Vector2<T>::operator-=(Vector2<T> const& vec2)
	{
		x(x() - vec2.x());
		y(y() - vec2.y());
		return *this;
	}

	//Multiplication, Division Assignment
	template<class T>
	Vector2<T> & Vector2<T>::operator*=(T scaler)
	{
		x(x() * scaler);
		y(y() * scaler);
		return *this;
	}
	template<class T>
	Vector2<T> & Vector2<T>::operator/=(T scaler)
	{
		if (0 != scaler)
		{
			x(x() / scaler);
			y(y() / scaler);
		}
		return *this;
	}

	//Equals, Not Equals
	template<class T>
	bool operator==(Vector2<T> const& vec1, Vector2<T> const& vec2)
	{
		return vec1.x() == vec2.x() && vec1.y() == vec2.y();
	}
	template<class T>
	bool operator!=(Vector2<T> const& vec1, Vector2<T> const& vec2)
	{
		return !(vec1 == vec2);
	}

	//Addition, Subtraction
	template<class T>
	Vector2<T> operator+(Vector2<T> const& vec1, Vector2<T> const& vec2)
	{
		return Vector2<T>(vec1.x() + vec2.x(), vec1.y() + vec2.y());
	}
	template<class T>
	Vector2<T> operator-(Vector2<T> const& vec1, Vector2<T> const& vec2)
	{
		return Vector2<T>(vec1.x() - vec2.x(), vec1.y() - vec2.y());
	}

	//Multiplication, Division
	template<class T>
	Vector2<T> operator*(Vector2<T> const& vec1, T scaler)
	{
		return Vector2<T>(vec1.x() * scaler, vec1.y() * scaler);
	}
	template<class T>
	Vector2<T> operator*(T scaler, Vector2<T> const& vec2)
	{
		return vec2 * scaler;
	}
	template<class T>
	Vector2<T> operator/(Vector2<T> const& vec1, T scaler)
	{
		if (0 == scaler)
			scaler = 1;
		return Vector2<T>(vec1.x() / scaler, vec1.y() / scaler);
	}


	/*********************\
	* Operations Vector3 *
	\*********************/
	template<class T>
	T Vector3<T>::magnitude() const { return std::sqrt(magnitudeSqr()); }
	template<class T>
	T Vector3<T>::magnitudeSqr() const { return x() * x() + y() * y() + z() * z(); }

	template<class T>
	void Vector3<T>::normalize()
	{
		if (0 != magnitudeSqr())
			*this /= magnitude();
	}
	template<class T>
	Vector3<T> Vector3<T>::normalized() const
	{
		return 0 != magnitudeSqr() ? *this / magnitude() : *this;
	}

	template<class T>
	Vector3<T> Vector3<T>::zero()
	{
		return Vector3<T>(0, 0, 0);
	}

	template<class T>
	T Vector3<T>::dot(Vector3<T> const& vec1, Vector3<T> const& vec2)
	{
		return vec1.x() * vec2.x() + vec1.y() * vec2.y() + vec1.z() * vec2.z();
	}

	template<class T>
	Vector3<T> Vector3<T>::cross(Vector3<T> const& vec1, Vector3<T> const& vec2)
	{
		return Vector3<T>( vec1.y()*vec2.z() - vec1.z()*vec2.y(), vec1.z()*vec2.x() - vec1.x()*vec2.z(), vec1.x()*vec2.y() - vec1.y()*vec2.x() );
	}


	/*****************************\
	* Operator overloads Vector3 *
	\*****************************/
	//Assignment
	template<class T>
	Vector3<T> & Vector3<T>::operator=(Vector3<T> const& vec2)
	{
		x(vec2.x());
		y(vec2.y());
		z(vec2.z());
		return *this;
	}

	//Addition, Subtraction Assignment
	template<class T>
	Vector3<T> & Vector3<T>::operator+=(Vector3<T> const& vec2)
	{
		x(x() + vec2.x());
		y(y() + vec2.y());
		z(z() + vec2.z());
		return *this;
	}
	template<class T>
	Vector3<T> & Vector3<T>::operator-=(Vector3<T> const& vec2)
	{
		x(x() - vec2.x());
		y(y() - vec2.y());
		z(z() - vec2.z());
		return *this;
	}

	//Multiplication, Division Assignment
	template<class T>
	Vector3<T> & Vector3<T>::operator*=(T scaler)
	{
		x(x() * scaler);
		y(y() * scaler);
		z(z() * scaler);
		return *this;
	}
	template<class T>
	Vector3<T> & Vector3<T>::operator/=(T scaler)
	{
		if (0 != scaler)
		{
			x(x() / scaler);
			y(y() / scaler);
			z(z() / scaler);
		}
		return *this;
	}

	//Equals, Not Equals
	template<class T>
	bool operator==(Vector3<T> const& vec1, Vector3<T> const& vec2)
	{
		return vec1.x() == vec2.x() && vec1.y() == vec2.y() && vec1.z() == vec2.z();
	}
	template<class T>
	bool operator!=(Vector3<T> const& vec1, Vector3<T> const& vec2)
	{
		return !(vec1 == vec2);
	}

	//Addition, Subtraction
	template<class T>
	Vector3<T> operator+(Vector3<T> const& vec1, Vector3<T> const& vec2)
	{
		return Vector3<T>(vec1.x() + vec2.x(), vec1.y() + vec2.y(), vec1.z() + vec2.z());
	}
	template<class T>
	Vector3<T> operator-(Vector3<T> const& vec1, Vector3<T> const& vec2)
	{
		return Vector3<T>(vec1.x() - vec2.x(), vec1.y() - vec2.y(), vec1.z() - vec2.z());
	}

	//Multiplication, Division
	template<class T>
	Vector3<T> operator*(Vector3<T> const& vec1, T scaler)
	{
		return Vector3<T>(vec1.x() * scaler, vec1.y() * scaler, vec1.z() * scaler);
	}
	template<class T>
	Vector3<T> operator*(T scaler, Vector3<T> const& vec2)
	{
		return vec2 * scaler;
	}
	template<class T>
	Vector3<T> operator/(Vector3<T> const& vec1, T scaler)
	{
		if (0 == scaler)
			scaler = 1;
		return Vector3<T>(vec1.x() / scaler, vec1.y() / scaler, vec1.z() / scaler);
	}
}

#endif