#ifndef __CSTRING_HELPER_H__
#define __CSTRING_HELPER_H__


#include <string>
#include <vector>


namespace Util
{
    
    using String = std::string;
    using StrVec = std::vector<String>;

    class CStringHelper
    {
    private:
        /* data */
    public:
        CStringHelper(/* args */);
        ~CStringHelper();
        //
        static String remove(const String& src,const String& val);
        static size_t replace(String &input, const String &from, const String &to);
        static String trim(const String &str, const String &whitespace = " \t");
        static StrVec split(const String& split_on_any_delimiters, const String& stringToSplit);
        static StrVec explode(const String& complete_match, const String& stringToExplode);
        static StrVec extract(const String& complete_match_start, const String& complete_match_end, const String& content);
        //
        static String to_lower(const String &str);
        static String to_upper(const String &str);
        static bool to_bool(const String &str);
        //
        static String remove_extension(const String& s);
        static String get_extension(const String& s);

        //
    };

}

#endif