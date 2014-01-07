#include <string>

class Logger
{
	public:
		static Logger* Instance()
		{
		if (!m_pInstance)   // Only allow one instance of class to be generated.
		      m_pInstance = new Logger;

		   return m_pInstance;	
		}

		bool openLogFile(std::string logFile);
		void writeToLogFile();
		bool closeLogFile();

	private:
		Logger(){};  // Private so that it can  not be called
		
		// Alternate way to inherit from a boost::noncopyable class
		Logger(Logger const&){};             // copy constructor is private
		Logger& operator=(Logger const&){};  // assignment operator is private
		static Logger* m_pInstance;
};

int
