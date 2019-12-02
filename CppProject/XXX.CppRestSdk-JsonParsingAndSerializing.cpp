#include <iostream>
#include <cpprest/json.h>

int main() {
	const utility::string_t my_student = L"{\"student_id\": 1, \"name\": \"Ali\", \"family_name\": \"Naseri\", \"birth_date\": \"13700101\", \"enable\": 1}";
	web::json::value expected = web::json::value::parse(my_student);

	if (my_student.compare(expected.serialize()))
		std::wcout << "these 2 wstring" << std::endl << my_student << std::endl << " and" << std::endl << expected.serialize() << std::endl << " are equal." << std::endl;
	else
		std::cout << "these 2 are not equal" << std::endl;

	std::cin.get();
}