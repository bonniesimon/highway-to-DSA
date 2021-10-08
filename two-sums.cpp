/*Question : https://leetcode.com/problems/two-sum/ */

// Problem right now 
// I should not sort the array since we need to return the index


#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> v){
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); ++it){
        int num = *it;
        cout << num << "  "; 
    }
    cout << "\n";
}


// int linear_search(vector<int> &arr, int start_index, int to_find){
//     for(int i = start_index; i<= arr.size(); i++){
//         if(arr[i] == to_find){
//             return i;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

// 	vector<int> nums = {2, 8, 3, 6, 7};
//     vector<int> result;
//     int target = 14, desired_value;
//     int index = 0;

//     while(index != nums.size()-1){
//         desired_value = target - nums[index];
//         int is_found_at = linear_search(nums, index+1, desired_value);
//         if(is_found_at > -1){
//             result.push_back(index);
//             result.push_back(is_found_at);
//             break;
//         }
//         index++;
//     }

//     print_vec(result);

//     return 0;
// }




// Solution using a Hash Map

// Issue with this code is that if there are 2 or more identical items in the nums array, then finding from the hash fails

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Given in Question
	vector<int> nums = {3, 2, 4, 2};
    int target = 6;


    unordered_multimap<int, int> hash_table;
    vector<int> result;
    int desired_value, index = 0;

    for(int i=0; i<nums.size(); i++){
        hash_table.insert({nums[i], i});
    }


    while(index < nums.size()-1){
        desired_value = target - nums[index];
        unordered_multimap<int, int>::iterator it = hash_table.equal_range(desired_value);
        if(it != hash_table.end()){
            // cout<<it->first<<"  "<< it->second;
            for(auto itr = it.first; itr != it.second; itr++){
                cout << itr->first << "   "<< itr->second << endl;
            }
            // result.push_back(it->second);
            // result.push_back(index);
            break;
        }
        index++;
    }

    print_vec(result);

    return 0;
}