#ifndef _COMPONENT_REFERENCE_H
#define _COMPONENT_REFERENCE_H


namespace GameEngine
{
	class Component;

	class ComponentReference
	{
		friend class iComponentManager;

	private:
		iComponentManager * m_cManager;
		int m_index;

	public:
		ComponentReference();
		~ComponentReference();

		iComponentManager const* componentManager() const { return m_cManager; }
		int index() const { return m_index; }

		Component * getComponent();
	};
}

#endif