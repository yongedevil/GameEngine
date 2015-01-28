#ifndef _MANAGER_H
#define _MANAGER_H

namespace GameEngine
{
	template<class T>
	class Manager
	{
	protected:
		typedef std::vector<T*> ManagerList;

	public:
		Manager();
		virtual ~Manager();

		typename ManagerList::iterator begin() { return m_list.begin(); }
		typename ManagerList::iterator end() { return m_list.end(); };
		typename ManagerList::const_iterator cbegin() const { return m_list.cbegin; } ;
		typename ManagerList::const_iterator cend() const { return m_list.cend; }

		template<class K>
		K * create();

		void remove(T * item);

	private:
		ManagerList m_list;
	};

	template<class T>
	Manager<T>::Manager()
	{
		m_list = ManagerList();
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
	template<class K>
	K * Manager<T>::create()
	{
		K * item = new K();
		m_list.push_back(item);

		return item;
	}
}

#endif