#include<iostream>
#include<sstream>
#include<chrono>
#include<iomanip>
#include<vector>
#include<string>
int stringToInteger(const std::string &s);
void stringToIntegerTest();
void printState(const std::istringstream &iss);
void bufferedExperiment(std::ostream &oss);
double mindlessWork();
int endlEachTime();
int endlAtEnd();
void badWelcomeProgram();
std::vector<std::string> stringSplit(const std::string& str);
void stringSplitTest();
void manipulatorFun();
void printEndTime(const std::string& input);
void printEndTimeTest();
void betterWelcomProgram();
int getInteger(const std::string &prompt);

int main()
{
    // std::ostringstream oss("Ito-En Green Tea");
    // std::cout << oss.str() << std::endl;//output : Ito-En Green Tea
    // oss << "16.9 Ounces";//this will overwrite the string buffer,as oss has be initialized.
    // std::cout << oss.str() << std::endl;//output : 16.9 Ouncesn Tea

    // std::ostringstream oss2;
    // oss2 << "Ito-En Green Tea";
    // oss2 << " 16.9 Ounces";//add string in the end of oss2,ass oss2 don't be initialized
    // std::cout << oss2.str() << std::endl;

    // std::ostringstream oss3("Ito-En Green Tea" , std::ostringstream::ate);
    // //ate:at the end, means next input string will be add at the end of oss3
    // oss3 << " 16.9 Ounces ";
    // oss3 << 666;//turn integer into string automatically
    // std::cout << oss3.str() << std::endl;


    // std::istringstream iss("16.9 Ounces");
    // double amount;
    // std::string unit;
    // iss >> amount >> unit;

    // std::istringstream _iss("16.9 Ounces");
    // int _amount;// get 16
    // std::string _unit;//get .9
    // std::string _tail;
    // _iss >> _amount >> _unit >> _tail;

    // std::cout << _amount << _unit << " " << _tail << std::endl;


    // std::cout << stringToInteger("123") << std::endl;
    // stringToIntegerTest();


    
    //Sadly,I can't see the difference between buffered and unbuffered in my Windows laptop
    //But I replicate it in my Linux(Centos7) Server.
    // bufferedExperiment(std::cout);//print "CS106L is awesome!" immediately
    // bufferedExperiment(std::cerr);//print "CS106L" , then wait serveral seconds, then print "is awesome!"
    //no buffer in std::cerr(in order to print error message in time)

    // int time1 = endlEachTime();
    // int time2 = endlAtEnd();
    // std::cout << "endlEachTime: " << time1 << "ms" << std::endl;
    // std::cout << "endlAtEnd: "    << time2 << "ms" << std::endl;
    // std::cout << "endlEachTime is " << (time1 - time2) << "ms slower than endlAtEnd" << std::endl;
    

    // badWelcomeProgram();

    // stringSplitTest();

    // manipulatorFun();

    // printEndTimeTest();
    
    // badWelcomeProgram();
    betterWelcomProgram();
    return 0;
}

int stringToInteger(const std::string &s){
    std::istringstream iss(s);
    int i;
    printState(iss);
    iss >> i;
    printState(iss);
    if(iss.fail())  throw std::domain_error("no value int at beginning");
    char cc;
    iss >> cc;
    if(!iss.fail()) throw std::domain_error("stuff after integer");
    return i;
    
}
void stringToIntegerTest(){
    while(true){
        std::cout << "Type in an integer: ";
        std::string s;
        if(!getline(std::cin , s))  throw std::domain_error("getline failed");

        int result = stringToInteger(s);
        std::cout << "As an integer, this is: " << result << std::endl;
        std::cout << "Half of that is: " << result/2 << std::endl;

    }
}

void printState(const std::istringstream &iss){
    std::cout << "State bits: ";
    std::cout << (iss.good() ? "G" : "-");//good state, has no errors
    std::cout << (iss.fail() ? "F" : "-");//non-fatal error,formatting error or type mismatch
    std::cout << (iss.eof()  ? "E" : "-");//The stream has reached the end of the input
    std::cout << (iss.bad()  ? "B" : "-");//fatal error,like hardware failure or memory corruption
    std::cout << std::endl;
}


void bufferedExperiment(std::ostream& oss) {
    oss << "CS106L";
    mindlessWork();

    oss << " is";
    mindlessWork();

    oss << " awesome!";
    mindlessWork();

    oss << std::endl;
    /*
     * 1. std::cout is buffered, which means it stores the output in a temporary storage area (buffer) before sending it to the output device.
     * 2. The buffer is flushed (i.e., the output is sent to the output device) when:
     *    - The buffer is full.
     *    - The program ends.
     *    - The buffer is explicitly flushed using std::flush or std::endl(equals to '\n' + std::flush).
     *    - The buffer is tied to another stream (e.g., std::cin is tied to std::cout).
     * 3. The buffer is not flushed when the program crashes or terminates abnormally.
    */
}

double mindlessWork(){
    double result = 0;
    for(int i = 0 ; i < 400000000 ; ++i){
        result += i / 999959;//use large prime number to avoid compiler optimization
    }
    return result;
}

int endlEachTime(){
    // put 0 in buffer
    // then print 0 (std::endl('\n'+std::flush) flush the buffer)
    // put 1 in bufer
    // then print 1

    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0 ; i < 100 ; ++i){
        std::cout << i << std::endl;//flush the buffer every time， which is slow
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count();
}

int endlAtEnd(){
    // put 0~99 in the buffer firstly
    // then print 0~99 at once when buffer is flushed
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0 ; i < 100 ; ++i){
        std::cout << i << '\n';
    }
    std::cout << std::flush;//flush the buffer one time at the end, which is faster

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count();

}



/*
 *-------------------------------------
 *-------------HOMEWORK----------------
 *-------------------------------------
 */
// splits a string with whitespace separated tokens
// into a vector of tokens
std::vector<std::string> stringSplit(const std::string& str) {
    std::vector<std::string> tokens;
    // to add a token to tokens, use tokens.push_back(token);
    std::istringstream iss(str);
    while(!iss.eof()){
        std::string token;
        iss >> token;
        tokens.push_back(token);
    }
    return tokens;
}

void stringSplitTest(){
    while(true){
        std::cout << "Enter a string: ";
        std::string str;
        if(!std::getline(std::cin , str))   throw std::domain_error("Invalid input");

        std::vector<std::string> tokens = stringSplit(str);
        std::cout << "Tokens: ";
        for(auto token : tokens){
            std::cout << token << " , ";
        }
        std::cout << std::endl;

    }
}

// some fun with manipulators
// we're not gonna spend too much time on these
// just google them and find the one you wnat to use
void manipulatorFun() {
    std::cout << "[" << std::setw(10) << "Ito" << "]";
    std::cout << "[" << std::left << std::setw(10) << "Ito" << "]";
    std::cout << "[" << std::left << std::setfill('-')
         << std::setw(10) << "Ito" << "]";

}


// Given a start time and a duration,
// calculate the end time.
// Assume correct formatting of string.

// input string: “1:30 PM \n 1 hour 20 minute”
// console string: “2:50 PM”

// Common bug: "1:30 PM \n 0 hour 30 minute"
// should print "2:00 PM", not "2:0 PM"
// Hint: use manipulators
void printEndTime(const std::string& input) {
    // you fill this out!
    std::istringstream iss(input);
    std::string start_time , duration;
    if(!std::getline(iss , start_time) || !std::getline(iss , duration)){
        throw std::domain_error("Invalid input");
    }

    //parse the start time
    int hour , minute;
    char colon;
    std::string ampm;
    std::istringstream startTime_iss(start_time);
    startTime_iss >> hour >> colon >> minute >> ampm;
    if(ampm == "PM" && hour != 12){
        hour += 12;
    }
    else if(ampm == "AM" && hour == 12){
        hour = 0;
    }
    int cur_total_minutes = hour * 60 + minute;
    
    int duration_hour , duration_minute;
    std::string hUnit , mUnit;
    std::istringstream duration_iss(duration);
    duration_iss >> duration_hour >> hUnit >> duration_minute >> mUnit;
    int duration_total_minutes = duration_hour * 60 + duration_minute;

    cur_total_minutes = (cur_total_minutes + duration_total_minutes) % (24 * 60);
    hour = cur_total_minutes / 60;
    minute = cur_total_minutes % 60;
    if(hour < 12){
        ampm = "AM";
    }
    else if(hour > 12){
        hour -= 12;
        ampm = "PM";
    }// hour === 12
    else    ampm = "PM";

    std::cout << hour << ':' <<  std::setw(2) << std::setfill('0') 
                                << minute << ' ' << ampm << std::endl;
}

void printEndTimeTest(){
    while(true){
        std::cout << "input start time and a duration(seperated by \\n): ";
        std::string input , start_time , duration;
        if(!getline(std::cin , start_time) || !getline(std::cin , duration)){
            throw std::domain_error("invalid input");
        }

        input = start_time + '\n' + duration;
        std::cout << "input string: " << input << std::endl;
        std::cout << "end time: ";
        printEndTime(input);
    }
}


// This is a bad program, and is how most C++ beginners get themselves into
// trouble (so don't use it in CS 106B!)
// WE DID NOT GET TO THIS IN LECTURE, WILL BEGIN LECTURE 3 WITH THIS
// cin with >> is a nightmare
void badWelcomeProgram() {
    std::string name, response;
    int age;

    std::cout << "What is your name? "; // sidenote: no flush needed! why?
    std::cin >> name;// if input “Benkang Peng",this program will fail.(cin stops up to white space)
    //cin will jump the leading white spaces but not consume the white spaces
    std::cout << "What is your age? ";
    std::cin >> age;

    std::cout << "Hello " << name << " (age " << age << ")" << '\n';

    std::cout << "Do you want to try again? ";
    std::cin >> response;

    std::cout << "You said: " << response << std::endl;
}

/*
badWelcomeProgram()
if input "benkang peng\n"
name will be "benkang"
then, cin >> age , but "peng" is not a integer , so cin >> age failed , age will be a random value
cause cin.fail() = 1 , cin >> response can't work and response is null
*/

void betterWelcomProgram(){
    std::string name , response;
    int age;

    std::cout << "What is your name? ";
    // getline reads up to the new line character('\n') and also consume it('\n').
    std::getline(std::cin , name);

    age = getInteger("What is your age? ");

    std::cout << "Hello " << name << " (age " << age << ")" << '\n';

    std::cout << "Do you want to try again? ";
    std::getline(std::cin , response);

    std::cout << "You said: " << response << std::endl;
}

int getInteger(const std::string &prompt){
    while(true){
        std::cout << prompt;
        std::string line;
        if(!std::getline(std::cin , line))
            throw std::domain_error("invalid input. ");
        
        std::istringstream iss(line);
        int res;
        char trash;
        if(iss >> res && !(iss >> trash)){//iss >> trash consumes the '\n'
            return res;
        }
    }
    

}