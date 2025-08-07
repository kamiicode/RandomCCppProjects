#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <string>
#include <chrono>

std::list<std::string> tasks{"Task1\n", "Task2\n", "Task3\n", "Task4\n", "Task5\n", "Task6\n", "Task7\n", "Task8\n", "Task9\n", "Task10\n"};
std::mutex tasksMutex{};

void doTask(std::chrono::milliseconds sleepFor) {
	std::string currentTask{};
	while (true) {
		{
			std::lock_guard<std::mutex> lock(tasksMutex);
			if (tasks.empty())
				break;

			currentTask = tasks.front();
			tasks.pop_front();
		}

		std::this_thread::sleep_for(sleepFor);
		std::cout << currentTask;
	}
}

int main() {
	std::thread t1(doTask, std::chrono::milliseconds(50));
	std::thread t2(doTask, std::chrono::milliseconds(50));

	t1.join();
	t2.join();
}
