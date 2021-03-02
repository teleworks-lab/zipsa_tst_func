#include "utils.h"

std::vector<std::string> tokenize_getline(const std::string& data, const char delimiter)
{
	std::vector<std::string> result;
	std::string token;
	std::stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}

bool isNumber(const std::string& str)
{
    for (char const &c : str)
	{
        if (std::isdigit(c) == 0)
			return false;
    }
    return true;
}

std::string trim(const std::string& s)
{
    if (s.length() == 0)
    {
        return s;
    }

    std::size_t beg = s.find_first_not_of(" \a\b\f\n\r\t\v");
    std::size_t end = s.find_last_not_of(" \a\b\f\n\r\t\v");
    if (beg == std::string::npos)  // No non-spaces
    {
        return "";
    }
    return std::string(s, beg, end - beg + 1);
}

size_t getFileSize(const char *filename)
{
    size_t fsize;
    std::ifstream ifs;
    std::string fn = filename;

    ifs.open(fn, std::ios::binary);

    ifs.seekg(0, std::ios::end);
    fsize = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    ifs.close();
    return fsize;
}

std::string getApplicationDirectory()
{
    char result[ PATH_MAX ];
    ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
    std::string appPath = std::string( result, (count > 0) ? count : 0 );

    std::size_t found = appPath.find_last_of("/\\");
    return appPath.substr(0,found);
}
