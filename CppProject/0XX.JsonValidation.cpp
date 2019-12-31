#include <cpprest/json.h>

int main() {
	const std::wstring s1(L"{\"family_name\": \"mousavi\"");
	if (web::json::value(s1).is_object())
		std::cout << "string is not JSON" << std::endl;
	else
		std::cout << "unable to verify value of s1" << std::endl;

	const std::wstring js1(L"[{\"name\": \"michael\"}]");
	if (web::json::value(js1).is_string())
		std::wcout << web::json::value(js1).as_string() << "is string" << std::endl;
	else
		std::cout << "unable to validate json" << std::endl;

	std::cin.get();
}