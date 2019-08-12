#includ "file_writer.h"

void FileWriter::AppendFile(std::string fileName, std::string data){
	std::ofstream file;
	file.open(fileName, std::ios_base::app);
	file << data;
	file.close();
}

void FileWriter::AppendFile(std::string fileName, KeyValuePair keyValuePair){
	std::ofstream file;
	file.open(fileName, std::ios_base::app);
	std::string writeableData = keyValuePair.key + ':' + keyValuePair.value + ',';
	file << writeableData;
	file.close();
}

void FileWriter::AppendFile(std::string fileName, std::vector<KeyValuePair> keyValuePairs){
	std::ofstream file;
	file.open(fileName, std::ios_base::app);
	std::string writeableData;
	for (int i = 0; i < keyValuePairs.size(); i++){
		writeableData += keyValuePairs.at(i).key + ':' + keyValuePairs.at(i).value + ',';
	}
	file << writeableData;
	file.close();
}

int FileWriter::WriteFile(std::string file_name, std::string data)
{
    std::ofstream file;
    std::string file_name_tmp = file_name + "_tmp";
    file.open(file_name_tmp, std::ofstream::out | std::ofstream::binary);
    if(!file.is_open()){
        last_err_msg_ = "error opening file";
        file.close();
        return 1;
    }
    //cal data's md5
    uint32_t data_md5 = GetDataMd5(data);
    file << data;
    file.close();

    std::string data_md5_tmp = "";
    if(GetFileMd5(file_name_tmp, data_md5_tmp) != 0)
    {
        last_err_msg_ = "error get tmp file md5";
        return 1;
    }
    if( data_md5_tmp == data_md5){
        return MoveFile(file_name_tmp, file_name);
    }
    else{
        last_err_msg_ = "error write tmp file";
        return 1;
    }
}