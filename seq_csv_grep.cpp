#include <fstream>
#include <iostream>
#include <boost/lexical_cast.hpp>

int32_t GetWorkflow(const std::string& line, char sep)
{
    int32_t workflow = 0;
    for(size_t iPos = 0; iPos < line.size() && line[iPos] != sep; ++iPos)
    {
        workflow = 10 * workflow + (line[iPos] - '0');
    }
    return workflow;
}

int main(int argc, char** argv)
{
    if(3 > argc)
    {
        std::cout << "usage: gcsv [workflow] [files]" << std::endl;
        return -1;
    }

    int32_t workflow = boost::lexical_cast<int32_t>(argv[1]);

    for(int32_t iFile = 2; iFile <= argc; ++iFile)
    {
        auto fileName = argv[iFile];
        std::ifstream file(fileName);
        if(file)
        {
            std::string line;
            //读取文件头
            std::getline(file, line);
            while(std::getline(file, line))
            {
                auto myWorkflow = GetWorkflow(line, ',');
                if(myWorkflow == workflow)
                {
                    std::cout<< fileName << ":" << line << '\n';
                }
                else if(myWorkflow > workflow)
                {
                    break;
                }
            }//while
        }//if(file)
    }//for(files)
    return 0;
}

