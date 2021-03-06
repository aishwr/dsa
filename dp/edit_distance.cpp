/*

Given strings s1 and s2, we need to transform s1 into s2 by deleting, inserting, or replacing 
characters. Write a function to calculate the count of the minimum number of edit operations.

Example 1:
    Input: s1 = "bat"       s2 = "but"
    Output: 1
    Explanation: We just need to replace 'a' with 'u' to transform s1 to s2.

Example 2:
    Input: s1 = "abdca"     s2 = "cbda"
    Output: 2
    Explanation: We can replace first 'a' with 'c' and delete second 'c'.

Example 3:
    Input: s1 = "passpot"       s2 = "ppsspqrt"
    Output: 3 
    Explanation: Replace 'a' with 'p', 'o' with 'q', and insert 'r'.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int edit(string& input1, string& input2, int i1, int i2) {
    if(memo[i1][i2] == -1) {
        if(i1 == input1.size()) {
            memo[i1][i2] = input2.size()-i2;
        } else  if(i2 == input2.size()) {
            memo[i1][i2] = input1.size()-i1;
        } else if(input1[i1] == input2[i2]) {
            memo[i1][i2] = edit(input1, input2, i1+1, i2+1);
        } else {
            int cost1 = edit(input1, input2, i1+1, i2)+1;   
            int cost2 = edit(input1, input2, i1, i2+1)+1;   
            int cost3 = edit(input1, input2, i1+1, i2+1)+1; 

            memo[i1][i2] = min(cost1, min(cost2, cost3));
        }
    }
    
    return memo[i1][i2];
}

int main() {
    string input1 = "intention", input2 = "execution";
    int n1 = input1.size(), n2 = input2.size();
    memo.resize(n1+1, vector<int>(n2+1, -1));
    cout << edit(input1, input2, 0, 0);
    return 0;
}