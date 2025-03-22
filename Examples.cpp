#include <unordered_map>
#include <vector>

//Practice 1
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
    
        for (int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            if (map.find(num) != map.end()) {
                return {map[num], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};


//Practice2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution2 {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* res = new ListNode();
            ListNode* current = res;
    
            while (list1 && list2) {
                if (list1->val <= list2->val) {
                    current->next = list1;
                    list1 = list1->next;
                } else {
                    current->next = list2;
                    list2 = list2->next;
                }
                current = current->next;
            }
            current->next = list1 ? list1 : list2;
    
            return res->next;
        }
    };


//Practice 3
class Solution3 {
    public:
        int removeElement(vector<int>& nums, int val) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == val) {
                    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
                    int k = nums.size();
                    return k;
                }
            }
            return 0;
        }
    };

//Practice 4
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution4 {
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            int aux = targetSum;
    
            if (root == nullptr) {
                return false;
            }
    
            targetSum -= root->val;
    
            if (root->left == nullptr && root->right == nullptr) {
                return targetSum == 0;
            } else {
                return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
            }
        }
    };