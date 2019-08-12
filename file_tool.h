#include <string>
#include "file_reader.h"
#include "file_writer.h"

class FileTool {
    public:
        FileTool(const std::string& file_name);
        ~FileTool();
        int AppendFile(std::string data);
        int ReadFile(std::string& data);
    private:
        std::string file_name_;


}