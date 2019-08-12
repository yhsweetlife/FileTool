#ifndef _FILE_HANDLE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class FileHandler{
public:
	struct KeyValuePair {
		std::string key;
		std::string value;
	};
	//Delete a file
	void DeleteFile(std::string fileName);
	//Clear contents of a file without deleting it
	void ClearFile(std::string fileName);
    std::string &GetLastErrMsg()
    {
        return last_err_msg_;
    }
    uint32_t GetDataMd5(const std::string& data);

private:
    std::string last_err_msg_;
};

#endif