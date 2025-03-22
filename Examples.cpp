#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

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

//Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
    };

//Practice 4

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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


    int main() {
        Solution1 exercise1;
        Solution2 exercise2;
        Solution3 exercise3;
        Solution4 exercise4;

        vector<int> nums1 = {2, 7, 11, 15};
        vector<int> res1 = exercise1.twoSum(nums1, 9);
        cout << "Resultado del ejercicio 1: ";
        for (int num : res1) {
            cout << num << " ";
        }
        cout << endl;


        ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
        ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        ListNode* res2 = exercise2.mergeTwoLists(list1,list2);

        vector<int> nums2 = {3,2,2,3};
        int res3 = exercise3.removeElement(nums2, 3);

        TreeNode* root = new TreeNode(5, 
            new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), nullptr),
            new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(1)))
        );

        bool res4 = exercise4.hasPathSum(root,22);

        

        cout << "Resultado del ejercicio 2: ";
        ListNode* temp = res2;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;

        cout << "Resultado del ejercicio 3: " << res3 << endl;

        cout << "Resultado del ejercicio 4: " << (res4 ? "true" : "false") << endl;
    }