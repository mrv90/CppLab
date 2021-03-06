﻿#include <iostream>
#include <string>
//#include <regex>
//
//void find_pattern(std::string &text, const std::regex &pattern) {
//	auto words_begin = std::sregex_iterator(text.begin(), text.end(), pattern);
//	auto words_end = std::sregex_iterator();
//	
//	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
//		std::smatch match = *i;
//		std::string match_str = match.str();
//		if (match_str.size() > 1) {
//			std::cout << " " << match_str << std::endl;
//		}
//	}
//
//	std::cout << "=================================================" << std::endl;
//}

//int main() {
//	std::string text =
//	"\
//	https://john.doe@www.example.com:123/forum/questions/?tag=networking&order=newest#top\
//	http://michael.white@5.238.111.43:8080/archive/forum/questions/?tag=programming&order=oldest\
//	ftp://2.181.129.127/posts/?tag=nfc\
//	ldap://[2001:db8::7]/c=GB?objectClass?one\
//	news:comp.infosystems.www.servers.unix\
//	telnet://192.0.2.16:80/\
//	urn:oasis:names:specification:docbook:dtd:xml:4.1.2";
//	
//	//regex patterns
//	std::regex scheme(R"(\w+(?=:\/))");
//	std::regex authority(R"([^\/{2}]([A-Za-z0-9\.]+)[@])"); // @ remains at the end
//	std::regex domain(R"((\/{2}|\@)[a-z0-9.]+(\:|\/))"); // @ remains in the start and : at the end
//	std::regex port(R"([:](\d{2,5})+[^\/])"); // : remains at begining
//	std::regex from(R"((\:\d{2,5}|\.\w{2,3})\/\w+)"); // capture after / until end
//	std::regex any_path(R"([\/]\w+(?=\/))"); // / remains at begining
//	std::regex any_query(R"(([\?\&][A-Za-z0-9=]+[^\&\#]))"); // ? or & remains at begining
//	std::regex fragment(R"(\#\w+)"); // # remains at the begining
//
//	return 0;
//}

//#include <boost/regex.hpp>
////#include <regex>
//
//int main() {
//	
//	std::string text = "name=Ali&family_name=Pouri&birth_date=14000101";
//	// std::regex does not support positive lookbehind (makes regex syntax error) so we used boost regex
//	boost::regex find("((?<==)\\w+)");
//	std::cout << boost::regex_replace(text, find, "'$0'") << std::endl;
//
//	const boost::wregex id(L"_id");
//	bool exist = boost::regex_search(L"/course/course_id?name=Math", id);
//
//	std::cin.get();
//}

//int main()
//{
//	std::string text = "Quick brown fox";
//	std::regex vowel_re("a|e|i|o|u");
//
//	// write the results to an output iterator
//	/*std::regex_replace(std::ostreambuf_iterator<char>(std::cout),
//		text.begin(), text.end(), vowel_re, "*");*/
//
//	// construct a string holding the results
//	std::cout << '\n' << std::regex_replace(text, vowel_re, "[$&]") << '\n';
//	std::cin.get();
//}

//===========================================================================
//https://www.geeksforgeeks.org/smatch-regex-regular-expressions-in-c/
#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
	string sp("geeksforgeeks");
	regex re("(geeks)(.*)");

	// flag type for determining the matching behavior 
	// && here it is for matches on strings. 
	smatch match;

	// we can use member function on match 
	// to extract the matched pattern. 
	if (regex_search(sp, match, re) == true) {

		// The size() member function indicates the 
		// number of capturing groups plus one for the overall match 
		// match size = Number of capturing group + 1 
		// (.*) which "forgeeks" ). 
		cout << "Match size = " << match.size() << endl;

		// Capturing group is index from 0 to match_size -1  
		// .....here 0 to 2 
		// pattern at index 0 is the overall match "geeksforgeeks" 
		// pattern at index 1 is the first capturing group "geeks" 
		// pattern at index 2 is the 2nd capturing group "forgeeks" 

		cout << "Whole match : " << match.str(0) << endl;
		cout << "First capturing group is '" << match.str(1)
			<< "' which is captured at index " << match.position(1)
			<< endl;
		cout << "Second capturing group is '" << match.str(2)
			<< "' which is captured at index " << match.position(2)
			<< endl;
	}
	else {
		cout << "No match is found" << endl;
	}

	cin.get();
	return 0;
}