#include<iostream>
#include<fstream>
#include<string>
std::string promptUserForFile(std::ifstream& stream, std::string prompt = "", std::string reprompt = "");

int main()
{
    std::ifstream stream;
    std::string prompt("input the filename: ");
    std::string reprompt("please input the correct filename: ");
    std::string filename = promptUserForFile(stream , prompt , reprompt);
    std::cout << filename << " has been opened! " << std::endl;
    return 0;
}

// Write the following function which prompts
// the user for a filename, opens the ifstream to
// the file, reprompt if the filename is not valid
// and then return the filename.
std::string promptUserForFile(std::ifstream& stream, std::string prompt, std::string reprompt) {

 // your implementation here
    std::cout << prompt;

    std::string filename;
    if(!std::getline(std::cin , filename)){
        throw std::domain_error("invalid filename!");
    }

    stream.open(filename);
    if(stream.is_open()){
        stream.close();
        return filename;
    }
    else{
        while(true){
            std::cout << reprompt;
            if(!std::getline(std::cin , filename)){
                throw std::domain_error("invalid filename!");
            }
            stream.close(); 
            stream.open(filename);
            if(stream.is_open()){
                // std::cout << filename << " has been opened! " << std::endl;
                stream.close();
                return filename;
            }
        }
    }

    return "";
    
}