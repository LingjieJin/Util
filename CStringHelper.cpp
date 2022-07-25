#include "CStringHelper.h"

#include <algorithm>

namespace Util
{
    String CStringHelper::remove(const String& src,const String& val)
    {
        String str(src);
        int before_str = str.find(val);
        str.erase(before_str, val.size());

        return str;
    }

    size_t CStringHelper::replace(String &input, const String &from, const String &to)
    {
        if (from.empty() || input.empty())
        {
            return 0;
        }

        size_t pos = 0;
        size_t count = 0;
        while ((pos = input.find(from, pos)) != String::npos)
        {
            input.replace(pos, from.length(), to);
            pos += to.length();
            ++count;
        }

        return count;
    }

    String CStringHelper::trim(const String &str, const String &whitespace)
    {
        const auto &begin = str.find_first_not_of(whitespace);
        if (String::npos == begin)
        {
            return {};
        }

        const auto &end = str.find_last_not_of(whitespace);
        const auto &range = end - begin + 1;
        return str.substr(begin, range);
    }

    StrVec CStringHelper::split(const String &delimiters, const String &stringToSplit)
    {
        using namespace std;
        // Skip all the text until the first delimiter is found
        string::size_type start = stringToSplit.find_first_not_of(delimiters, 0);
        string::size_type stop = stringToSplit.find_first_of(delimiters, start);

        StrVec tokens;
        while (string::npos != stop || string::npos != start)
        {
            tokens.push_back(stringToSplit.substr(start, stop - start));
            start = stringToSplit.find_first_not_of(delimiters, stop);
            stop = stringToSplit.find_first_of(delimiters, start);
        }
        return tokens;
    }

    StrVec CStringHelper::explode(const String &matchAll, const String &toExplode)
    {
        if (matchAll.empty())
        {
            return {toExplode};
        }

        StrVec foundMatching;
        String::size_type position = 0;
        String::size_type keySize = matchAll.size();
        String::size_type found = 0;

        while ((found != String::npos))
        {
            found = toExplode.find(matchAll, position);
            String item = toExplode.substr(position, found - position);
            position = found + keySize;

            bool ignore = item.empty() && (String::npos == found);
            if (false == ignore)
            {
                foundMatching.push_back(item);
            }
        }

        return foundMatching;
    }

    StrVec CStringHelper::extract(const String &complete_match_start, const String &complete_match_end, const String &content)
    {

        if (complete_match_start.size() == 0 or complete_match_end.size() == 0)
        {
            return {};
        }

        std::vector<std::string> result;
        const std::string::size_type startKeySize = complete_match_start.size();
        const std::string::size_type stopKeySize = complete_match_end.size();
        std::string::size_type found = 0;

        auto ContinueSearch = [](std::string::size_type found)
        { return found != std::string::npos; };

        while (ContinueSearch(found))
        {
            auto found_start = content.find(complete_match_start, found);
            if (!ContinueSearch(found_start))
            {
                break;
            }

            auto found_stop = content.find(complete_match_end, found_start + startKeySize);
            if (!ContinueSearch(found_stop))
            {
                break;
            }

            found = found_stop + stopKeySize;
            auto size = found - found_start;
            result.push_back(content.substr(found_start, size));
            if (found >= content.size())
            {
                break;
            }
        }

        return result;
    }

    String CStringHelper::to_lower(const String &str)
    {
        String copy(str);
        std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
        return copy;
    }

    String CStringHelper::to_upper(const String &str)
    {
        String copy(str);
        std::transform(copy.begin(), copy.end(), copy.begin(), ::toupper);
        return copy;
    }

    bool CStringHelper::to_bool(const String &str)
    {
        if (str == "1")
        {
            return true;
        }
        else if (str == "0")
        {
            return false;
        }

        String lowerStr = to_lower(str);
        if (lowerStr == "true")
        {
            return true;
        }
        else if (lowerStr == "false")
        {
            return false;
        }

        return false;
    }

    String CStringHelper::remove_extension(const String &s)
    {
        return s.substr(0, s.find_last_of("."));
    }

    String CStringHelper::get_extension(const String &s)
    {
        auto lastIndexOfPeriod = s.find_last_of(".");
        if (lastIndexOfPeriod != std::string::npos)
        {
            return s.substr(lastIndexOfPeriod + 1, s.size() + 1);
        }

        return "";
    }
}