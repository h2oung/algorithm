#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {

    map<string, int> inTime;
    map<string, int> totalTime;

    for (string record : records) {
        string time, car, status;

        stringstream ss(record);
        ss >> time >> car >> status;

        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));
        int t = hour * 60 + minute;

        if (status == "IN") {
            inTime[car] = t;
        }
        else {
            totalTime[car] += t - inTime[car];
            inTime.erase(car);
        }
    }

    // 출차 기록이 없는 차량은 23:59에 출차 처리
    for (auto p : inTime) {
        string car = p.first;
        int t = p.second;

        totalTime[car] += 1439 - t;
    }

    vector<int> answer;

    for (auto p : totalTime) {
        int total = p.second;
        int fee = fees[1];

        if (total > fees[0]) {
            int extra = total - fees[0];

            fee += (extra + fees[2] - 1) / fees[2] * fees[3];
        }

        answer.push_back(fee);
    }

    return answer;
}