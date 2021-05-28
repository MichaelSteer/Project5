/** File:   FileLoader.h
 *  Author: Michael Steer
 *  Date:   28-05-21
 * 
 *  Load information from a file and return a file type
*/

#pragma once
#include <string>

enum FILE_TYPE {
    FILE_OBJ,
    FILE_UNKNOWN
};

template<typename T>
class FileLoader {
    public:
        FileLoader();
        FileLoader(std::string path);
        FileLoader(char* path);
        ~FileLoader();
        T getFile();
        FILE_TYPE getFileType();
    private:
        FILE_TYPE filetype;
};