/* Launching a thread
 * It doesn't matter what the thread is going to do, or where it's
 * launched from, but starting a thread using C++ Thread Library always
 * boils down to constructing a ```std::thread``` object.
 * 	```void do_some_work();
 * 	   std::thread my_thread(do_some_work);```
 *
 * std::thread works with any callable type, so you can pass an instance of a class
 * of a class with a function call operator to std::thread constructor
 */

/* In this case, the supplied function object is copied into the storage belonging to the newly
 * created thread of execution, and invoked from there. It's therefore essential that the copy
 * behave equivalently to the original. 
 *
 * If you pass a temporary rather than a named variable, then the syntax can be the same as
 * that of a function declaration. You avoid this by naming your function by adding an extra set of
 * parentheses, or by using the new uniform init syntax:
 * 	std::thread my_thread((background_task())); -> allows my_thread to be a variable of type
 * 						       std::thread
 * 	std::thread my_thread{background_task()}; -> The same
 *
 * One type of callable object that avoids this problem is a lambda expression
 *
 * Once you start your thread, you must explicitly decide whether to wait for it to
 * finished or leave it to run on its own. If you don't decide before the
 * std::thread object is destroyed, the program terminates, as std::terminate()
 * is called.
 *
 * If you don't wait for your thread to finish, then you need to ensure that the
 * data accessed by the thread is valid until the thread has finished with it.
 *
 * Example:
 * 	struct func
	{
		int& i;
		func(int& i_):i(i_){}
		void operator()()
		{
			for(unsigned j=0;j<1000000;++j)
			{
				do_something(i); // Potential access to dangling
						 // reference
			}
		}
	};
	
	void oops()
	{
		int some_local_state=0;
		func my_func(some_local_state);
		std::thread my_thread(my_func);
		my_thread.detach(); // Don't wait for thread to finish
	} // New thread might still be running
 *
 */

// If you need to wait for a thread to complete, you can do this by calling join() on the
// associated std::thread instance. In the above, if we use .join() instead of .detach()
// before the closing brace of the function body with a call to my_thread.join() would
// therefore be sufficient to ensure that the thread was finished before the function
// was exited, and thus before the local variables were destroyed.
//
// If you're detaching a thread, you can usually call detach() immediately after the thread
// has been started, so this isn't a prolem. But if you're intending to wait for the thread,
// you need to carefully pick when to call .join(), as it's liable to be skipped if an
// exception is thrown after the thread has been started. So, it's usually good to call it
// in catch statements, and then in the normal place you'd expect.

/* 
	struct func;
	void f()
	{
		int some_local_state=0;
		func my_func(some_local_state);
		std::thread t(my_func);
		try
		{
			do_something_in_current_thread();
		}
		catch(...)
		{
			t.join();
			throw;
		}
		t.join();
	}
 */ 

// The use of try/catch blocks is verbose, and it's eassy to get the
// scope slightly wrong, so it isn't an ideal scenario. To ensure the
// thread completes before the function exists, for whatever reason,
// we can use thread guards, RAII idiom.

/*	class thread_guard
 *	{
 *		std::thread& t;
 *		public:
 *			explicit thread_guard(std::thread& t_):
 *				t(t_)
 *			{}
 *			~thread_guard()
 *			{
 *				if (t.joinable())
 *				{
 *					t.join();
 *				}
 *			}
 *			thread_guard(thread_guard const&) = delete;
 *			thread_guard& operator = (thread_guard const&) = delete;
 *	};
 *
 */
