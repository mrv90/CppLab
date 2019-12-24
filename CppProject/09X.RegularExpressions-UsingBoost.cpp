#include <iostream>
#include <boost/regex.hpp>

int main() {
	std::string url = "/class?class_id=-1&course_ref=1&student_ref=2&score_ref=1";
	
	const boost::regex pattern("[a-zA-Z0-9_=-]+((?=&)|(?=$))");
	boost::sregex_token_iterator iter(url.begin(), url.end(), pattern, 0);
	boost::sregex_token_iterator end;
	
	for (; iter != end; ++iter) {
		std::cout << *iter << '\n';
	}	
	
	std::cin.get();
}

//#include <boost/regex.hpp>
//#include <iostream>
//#include <string>
//
//int main() {
//	std::string text("abc abd");
//	boost::regex regex("ab.");
//
//	boost::sregex_token_iterator iter(text.begin(), text.end(), regex, 0);
//	boost::sregex_token_iterator end;
//
//	for (; iter != end; ++iter) {
//		std::cout << *iter << '\n';
//	}
//
//	std::cin.get();
//	return 0;
//}