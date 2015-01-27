#ifndef _MANAGER_H
#define _MANAGER_H

namespace GameEngine
{
	template<class T>
	class Manager
	{
	protected:
		typedef std::vector<T *> ManagerList;

	public:
		Manager();
		virtual ~Manager();

		void init() = 0;

		typename ManagerList::iterator begin() { return m_list.begin(); }
		typename ManagerList::iterator end() { return m_list.end(); };
		typename ManagerList::const_iterator cbegin() const { return m_list.cbegin; } ;
		typename ManagerList::const_iterator cend() const { return m_list.cend; }

		template<class T>
		T * create();

		void remove(T * item);

	private:
		MangerList m_list;
	};

	template<class T>
	Manager<T>::Manger() : m_list(NULL)
	{
	}

	template<class T>
	Manager<T>::~Manager()
	{
		for(ManagerList::iterator it = begin(); it != end(); ++it)
		{
			delete *it;
		}
	}

	template<class T>
	void Manager<T>::init()
	{
		m_list = new ManagerList();
	}

	template<class T>
	T * Manager<T>::create()
	{
		T * item = new T();
		m_list.push_back(item);

		return item;
	}
}

#endif