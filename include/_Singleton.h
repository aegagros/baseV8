/*
 * Singleton.h
 */

namespace base {
	template <class T>
	class Singleton
	{
	public:
		static T* getInstance()
		{
			if(!m_pInstance)
				m_pInstance = new Singleton();
			return m_pInstance;
		}

	protected:
		Singleton() {};
		virtual ~Singleton()
		{
			if (m_pInstance)
				delete m_pInstance;
			m_pInstance = 0;
		};
	private:
		static T* m_pInstance;
	};

	template <class T> T* Singleton<T>::m_pInstance = 0;
};
