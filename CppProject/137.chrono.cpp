#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
#include <boost/date_time.hpp>

int main() {

	// Get current system time
	/*boost::posix_time::ptime timeLocal =
		boost::posix_time::second_clock::local_time();*/
	auto timeLocal = boost::posix_time::second_clock::local_time();

	std::cout << "Current System Time = " << timeLocal << std::endl;

	// Get Date object from ptime object
	boost::gregorian::date dateObj = timeLocal.date();

	std::cout << "Date Object = " << dateObj << std::endl;

	// Get Time object from ptime object
	boost::posix_time::time_duration durObj = timeLocal.time_of_day();

	std::cout << "Time Object = " << durObj << std::endl;

	std::cout << "Year = " << timeLocal.date().year() << std::endl;
	std::cout << "Month = " << timeLocal.date().month() << std::endl;
	std::cout << "Day of Month = " << timeLocal.date().day() << std::endl;
	std::cout << "Hour of the Day = " << timeLocal.time_of_day().hours() << std::endl;
	std::cout << "Minute : = " << timeLocal.time_of_day().minutes() << std::endl;
	std::cout << "Seconds : = " << timeLocal.time_of_day().seconds() << std::endl;

	// Get the current time in UTC Timezone
	boost::posix_time::ptime timeUTC =
		boost::posix_time::second_clock::universal_time();

	std::cout << "Current Time in UTC Timezone : " << timeUTC << std::endl;
	std::cin.get();
}