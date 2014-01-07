#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <stdlib.h>

using namespace std;
const int maxInput = 1000;

using boost::mutex;
using boost::thread;

class Users {

	private:
		vector<string> userList;
	public:
		Users (int max)
		{
			userList = vector<string> (max);
		}

		void Add (string user)
		{
			userList.push_back (user);
		}

		bool Search (string user)
		{
			for (vector<string>::iterator it = userList.begin (); it != userList.end (); it++)
			{
				if (*it == user)
					return true;
			}

			return false;
		}

		~Users ()
		{
		}
	
};

string strings [] = {"one", "two", "three","four","five","six","seven","eight","nine","ten"};

static void
useradd_thread (Users &usrs, int max, mutex *mtx)
{
	for (int i =0; i < max; i++)
	{
		mtx->lock ();
		usrs.Add(strings[rand()%10]);
		mtx->unlock ();
	}
}

class NonCopyable
{
	NonCopyable (NonCopyable &noncopy);
	NonCopyable & operator= (NonCopyable const &noncopy);
	public:
	NonCopyable ()
	{
	}
};

class AutoLock : private NonCopyable
{
	private:
		mutex *lock;
	public:
		AutoLock (mutex *mtx):lock(mtx)
		{
			lock->lock();
			cout << "Locked using the AutoLock" << endl;
		}

		~AutoLock () 
		{
			lock->unlock();
			cout << "UnLocked using the AutoLock" << endl;
		}
};

class AutoDelete : private NonCopyable
{
	private:
		string **temp;
	public:
		AutoDelete (string **t):temp(t)
		{
		}
		~AutoDelete () 
		{
			cout << "Auto deleting the string " << endl;
			delete *temp;
			*temp = NULL;
		}
};

static bool
user_search (Users &usrs, string usr, mutex *mtx)
{
	AutoLock Lock(mtx);

	return usrs.Search (usr);
}

int 
main ()
{
	Users usrs(maxInput);
	mutex mtx;
	string *usrSearch = new string ("six");
	
	// Deallocate the memory once we get out of scope
	// Similar strategy can be used for file descriptors as well
	AutoDelete deferedDelete(&usrSearch);

	thread th1 (useradd_thread, usrs, maxInput, &mtx);

	bool result = user_search (usrs, *usrSearch, &mtx);
	if (result)
		cout << "Found the user " << *usrSearch << " " << endl;
	else
		cout << "Could not find the user " << *usrSearch << " " << endl;

	th1.join ();

	return 0;
}
