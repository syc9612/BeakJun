#include <string>
#include <vector>
#include <iostream>

//using namespace std;

std::string solution(std::string video_len, std::string pos, std::string op_start, std::string op_end, std::vector<std::string> commands) {
    std::string answer = "";
    return answer;
}

class video{
    private:
    std::string video_len, pos, op_start, op_end;
    std::vector<std::string> commands;

    public:
    bool isValid(std::string video_len, std::string pos, std::string op_start, std::string op_end);
    void cPrev();
    void cNext();

    int minuteFromLen(std::string const& len);    
    int secondFromLen(std::string const& len);    
};

int video::minuteFromLen(std::string const& len)
{
    if(len.size() != 5)
    {
        return -1;
    }

    return stoi(len.substr(0, 2));
}

int video::secondFromLen(std::string const& len)
{
    if(len.size() != 5)
    {
        return -1;
    }

    return stoi(len.substr(3, 2));
}

bool video::isValid(std::string video_len, std::string pos, std::string op_start, std::string op_end){
    //한번에 비교할방법이...흐으으으음
    int min = minuteFromLen(video_len);
    int sec = secondFromLen(video_len);
    if(min < 0 || min > 59)
    {
        // wrong minute
        return false;
    }

    if(sec < 0 || sec > 59)
    {
        // wrong minute
        return false;
    }
    int video_len_h = stoi(video_len.substr(0,1));
    std::cout << "check: string to int [video_len_h]" << video_len_h << std::endl;
    

    return true;
}

#include <string>
#include <vector>
#include <sstream>

using namespace std;

int timeToSeconds(const string& time) {
    int minutes = stoi(time.substr(0, 2));
    int seconds = stoi(time.substr(3, 2));
    return minutes * 60 + seconds;
}

string secondsToTime(int totalSeconds) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    stringstream ss;
    ss << (minutes < 10 ? "0" : "") << minutes << ":";
    ss << (seconds < 10 ? "0" : "") << seconds;
    return ss.str();
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int videoLen = timeToSeconds(video_len);
    int currentTime = timeToSeconds(pos);
    int openingStart = timeToSeconds(op_start);
    int openingEnd = timeToSeconds(op_end);

    for (const string& command : commands) {
        if (command == "next") {
            currentTime = min(currentTime + 10, videoLen);
        } else if (command == "prev") {
            currentTime = max(currentTime - 10, 0);
        }
        
        if (currentTime >= openingStart && currentTime <= openingEnd) {
            currentTime = openingEnd;
        }
    }

    return secondsToTime(currentTime);
}
