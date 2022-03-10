#ifndef GENERIC_FUNC_H
#define GENERIC_FUNC_H

#include "DataTypes.h"

namespace gnfnc
{
    //TODO: Check if the argument in the functions below should a const ref to string or just ref to string.
    /*!
     * Returns the absolute (full) path of the executable.
     * @return the absolute (full) path of the executable.
     */
    std::string getExecutablePath();

    /*!
     * Returns the absolute (full) path of the executable concatenated with a specific filename.
     * @param the filename.
     * @return the absolute (full) path of the executable concatenated with a specific filename.
     */
    std::string getExecutablePathAndMatchItWithFilename(const std::string& filename);

    /*!
     * Returns only the absolute path of a full filename.
     * @param the full filename.
     * @return the absolute path of a full filename.
     */
    std::string getPathFromFullFilename(const std::string& fullFilename);

    /*! 
     * Returns the names of all files within a directory.
     * @param the absolute path of the directory.
     * @return the names of all files within a directory.
     */
    StringVector getAllFilenamesWithinDirectory(const std::string& directory);

    /*!
     * Counts the number of lines in a file.
     * @param the name of the file.
     * @return the number of lines in the file.
     */
    int countNumberOfLinesInFile(const std::string& filename);
}

#endif  //  GENERIC_FUNC_H