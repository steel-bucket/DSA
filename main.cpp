//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }

    int pop();
    void push(int);
};


// } Driver Code Ends
// Function to push an integer into the stack.

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack ::push(int x) {
    // Your Code
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
}


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Flush the newline character left by cin
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        delete sq;
    }
    return 0;
}

// } Driver Code Ends


// int myAtoi(string s) {
//     long long int ans = 0;
//     int i = 0;
//     while (s[i] == ' ') i++;
//     int sign = 0;
//     if (s[i] == '-') {
//         sign = 1;
//         i++;
//     } else if (s[i] == '+') {
//         sign = 0;
//         i++;
//     }
//     while (s[i] == '0') i++;
//     while (s[i] >= '0' && s[i] <= '9') {
//         if (ans > INT_MAX) {
//             if (sign) return INT_MIN;
//             return INT_MAX;
//         }
//         ans = ans * 10 + s[i] - '0';
//         i++;
//     }
//     if (sign)ans *= -1;
//     if (ans > INT_MAX) return INT_MAX;
//     if (ans < INT_MIN) return INT_MIN;
//     return (int) ans;
// }
