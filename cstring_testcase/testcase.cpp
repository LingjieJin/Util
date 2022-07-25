#include "../CStringHelper.h"


int main()
{

std::string filename = "aaa.text";
std::string ext =  Util::CStringHelper::get_extension(filename);

return 0;
}