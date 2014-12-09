#ifndef _COMPONENT_MANAGER_INTERFACE_H
#define _COMPONENT_MANAGER_INTERFACE_H


namespace GameEngine
{
	class iComponentManager
	{
	public:
		class iterator
		{
		private:
			iComponentManager * m_manager;
			int m_index;

		public:
			iterator() : m_manager(0), m_index(-1) { }
			iterator(iComponentManager * manager) : m_manager(manager), m_index(0) { }
			iterator(iComponentManager * manager, int index) : m_manager(manager), m_index(index) { }
			iterator(iterator const& other) : m_manager(other.m_manager), m_index(other.m_index) { }
			~iterator() { }

		public:
			iterator & operator=(iterator const& other)
			{
				m_manager = other.m_manager;
				m_index = other.m_index;
			}
			iterator & operator+=(int difference)
			{
				m_index += difference;

				if (m_index >= m_manager->size())
					m_index = m_manager->size();
				else if (m_index < 0)
					m_index = 0;

				return *this;
			}
			iterator & operator-=(int difference)
			{
				return *this += -difference;
			}

			iterator & operator++()
			{
				m_index++;
				return *this;
			}
			iterator & operator++(int)
			{
				iterator it = *this;
				m_index++;
				return it;
			}
			iterator & operator--()
			{
				m_index--;
				return *this;
			}
			iterator & operator--(int)
			{
				iterator it = *this;
				m_index--;
				return it;
			}

			Component * operator*()
			{
				return (m_manager->getComponent(m_index));
			}

			bool equals(iterator const& other) const
			{
				return m_manager == other.m_manager && m_index == other.m_index;
			}

			friend bool operator==(iterator const& it1, iterator const& it2)
			{
				return it1.equals(it2);
			}
			friend bool operator!=(iterator const& it1, iterator const& it2)
			{
				return !it1.equals(it2);
			}

			friend iterator operator+(iterator const& it1, int difference)
			{
				iterator it = it1;
				it += difference;
				return it;
			}
			friend iterator operator-(iterator const& it1, int difference)
			{
				iterator it = it1;
				it -= difference;
				return it;
			}
		};

		virtual ComponentType getType() = 0;

		virtual Component * createComponent() = 0;
		virtual void removeComponent(Component * component) = 0;

		virtual Component * getComponent(int index) = 0;

		virtual iterator begin() = 0;
		virtual iterator end() = 0;
		virtual int size() const = 0;

	protected:
		void setReference(ComponentReference * reference, int index)
		{
			if (NULL != reference)
			{
				reference->m_cManager = this;
				reference->m_index = index;
			}
		}
	};
}
#endif