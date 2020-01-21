#pragma once
#include <sched.h>
#include <signal.h>
#include <functional>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

#define STACK_SIZE 1024 * 10

#define CHECK(fun) \
    if ((fun) == -1) { \
        throw std::system_error(errno, std::generic_category()); \
    }

int threadHelper(void *ptr) {
    auto *fn = static_cast<std::function<int()> *>(ptr);
    return (*fn)();
}

class myThread{
public:
	myThread() = default;

	myThread(std::function<int()> &&fn) {
		// std::cout<<"myThread(std::function<int()> &&fn)\n";
        stack = new char[STACK_SIZE];
        CHECK(pid = clone(threadHelper, stack + STACK_SIZE, CLONE_VM | SIGCHLD, &fn));
		// CHECK(kill(pid, SIGSTOP));
	}

	pid_t get_id() { return pid; }

	~myThread(){
		if(pid != NULL)
			kill(pid, SIGTERM);
		delete[] stack;
	}

	myThread &operator=(myThread&& other){
		// std::cout<<"myThread &operator=(myThread&& other)\n";
		this->swap(other);
		return *this;
	}

	void swap(myThread& other){
		std::swap(this->pid, other.pid);
		std::swap(this->stack, other.stack);
	}

	bool joinable() {
		// std::cout<<"bool joinable()\n";
        return pid != 0;
    }

	void join() {
		// std::cout<<"void join()\n";
		int status;
		// CHECK(kill(pid, SIGCONT));
        CHECK(waitpid(pid, &status, 0));
		// CHECK(kill(pid, SIGTERM));
		pid = NULL;
    }

private:
	int pid = NULL;
	char *stack = nullptr;
};