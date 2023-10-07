#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isPossible(vector<int>& boards, int painters, long long int max_time) {
    int num_painters = 1;
    long long int current_time = 0;
    
    for (int i = 0; i < boards.size(); i++) {
        current_time += boards[i];
        
        if (current_time > max_time) {
            num_painters++;
            current_time = boards[i];
        }
        
        if (num_painters > painters)
            return false;
    }
    
    return true;
}

long long int painterPartition(vector<int>& boards, int painters, int time_limit) {
    long long int low = *max_element(boards.begin(), boards.end());
    long long int high = accumulate(boards.begin(), boards.end(), 0);
    
    while (low < high) {
        long long int mid = low + (high - low) / 2;
        
        if (isPossible(boards, painters, mid))
            high = mid;
        else
            low = mid + 1;
    }
    
    return low * time_limit;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;
    int time_limit = 5;
    
    long long int minTime = painterPartition(boards, painters, time_limit);
    
    cout << "Minimum time required: " << minTime << " units" << endl;
    
    return 0;
}
