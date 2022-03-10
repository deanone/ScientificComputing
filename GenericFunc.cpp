#include "GenericFunc.h"
#include "dirent.h"

std::string gnfnc::getExecutablePath()
{
    char result[PATH_MAX];
    size_t found = 0;
    size_t count = readlink("/proc/self/exe", result, PATH_MAX);
    found = std::string(result).find_last_of("/");
    return (std::string(result).substr(0,found) + "/");
}

std::string gnfnc::getExecutablePathAndMatchItWithFilename(const std::string& filename)
{
    std::string execPath = getExecutablePath();
    size_t found = execPath.find_last_of("/");
    execPath = execPath.substr(0, found);
    std::stringstream ss;
    ss << execPath << "/" << filename;
    return ss.str();
}

std::string gnfnc::getPathFromFullFilename(const std::string& fullFilename)
{
    return fullFilename.substr(0, fullFilename.find_last_of("/"));
}

StringVector gnfnc::getAllFilenamesWithinDirectory(const std::string& directory)
{
    StringVector names;
    std::string search_path = directory + "/";
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (search_path.c_str())) != NULL)
    {
        // print all the files and directories within directory
        while ((ent = readdir (dir)) != NULL)
        {
            std::string s(ent->d_name);
            if ((s.compare(".") != 0) && (s.compare("..") != 0))
            {
                names.push_back(s);
            }
        }
        closedir (dir);
    }
    else
    {
        std::cout << "Could not open directory.\n";
    }
    return names;
    //else
    //{
        /* could not open directory */
    //  perror ("");
    //  return /*EXIT_FAILURE*/ 0;
    //}
}

int gnfnc::countNumberOfLinesInFile(const std::string& filename)
{
    int numberOfLines = 0;
    std::string dataline = "";
    std::ifstream in(filename);
    if (in.is_open())
    {
        while (std::getline(in, dataline))
        {
            numberOfLines++;
        }
        in.close();
    }
    else
    {
        numberOfLines = -1; // error code
    }
    return numberOfLines;
}