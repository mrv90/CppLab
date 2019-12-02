#include <cpprest/json.h>

int main() {
	try
	{
		utility::stringstream_t is1(L"{\"id\": 1, \"name\" : \"Foo\", \"price\" : 123, \"tags\" : [\"Bar\", \"Eek\"], \"stock\" : {\"warehouse\": 300, \"retail\" : 20 } }");
		utility::stringstream_t is2(L"{\"student_id\": 1, \"name\": \"Ali\", \"family_name\": \"Naseri\", \"birth_date\": \"13700101\", \"enable\": 1}");
		
		// this THROWS exeption; we should replace ' with " and also include { and } each side of string
		utility::stringstream_t is3(L"\"student_id\": 1, \"name\": 'Ali', \"family_name\": 'Naseri', \"birth_date\": 13700101, \"enable\": 1"); 
		std::wstring ws1 = L"{\"Allow\": \"OPTIONS\"}";
		std::wstring ws2 = L"{\"Allow\": [\"GET\", \"POST\", \"PUT\", \"PATCH\", \"DEL\", \"OPTIONS\", \"HEAD\"]}";


		web::json::value resp;
		
		resp = web::json::value::parse(is1);
		resp = web::json::value::parse(is2);
		//resp = web::json::value::parse(is3); // NOTE: exception raise here!
		resp = web::json::value::parse(ws1);
		resp = web::json::value::parse(ws2);
	}
	catch (const std::exception& e)
	{
		throw e.what();
	}
}