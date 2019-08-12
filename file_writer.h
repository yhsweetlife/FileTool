#ifndef __FILE_WRITER_H_


class FileWriter : public FileHandler{
private:
public:
	//Append string text to file called fileName
	void AppendFile(std::string fileName, std::string data);
	//Append fileName with single keyValuePair
	void AppendFile(std::string fileName, KeyValuePair keyValuePair);
	//Append fileName with a vector of keyValuePairs
	void AppendFile(std::string fileName, std::vector<KeyValuePair> keyValuePair);

    void WriteFile(std::string file_name, std::string data);
};

#endif