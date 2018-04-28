#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

//剑指offer第一题：二维有序数组中的查找
//此题并不存在时间复杂度log(col) + log(row)的算法。(自己想多了)
//解法有两种

//一种是逐行(列)查找，每一行(列)使用二分查找，时间复杂度为col*log(row)或row*log(col)；

//另一种是从左下角开始比较当target小于位置值时候，则target必然在位置的上方，否则在位置的右方，
//这种做法复杂度为col+row

//两种做法复杂度大小相比较与m，n以及输入有关。

class Solution1 {
public:
    bool Find(int target, vector<int> array) {
        int col = array.size();
//        int row = array[0].size();

        int low_x, mid_x, high_x;
//        int low_y, mid_y, high_y;
        low_x = 0;
        high_x = col - 1;
//        low_y = 0;
//        high_y = row - 1;
        while(low_x <= high_x) {
            //第一步mid_x等于4，c++默认向下取整，即舍去小数部分,即n为偶数时比较较小的中间数
            mid_x = (low_x + high_x) / 2; // #1
            //避免溢出的写法：
            //mid_x = low_x + (high_x - low_x) / 2; #2
            //注： #1与#2在任何时候都相等，包含方向相同的取整运算时；
            cout << "mid_x:" << mid_x << endl;
            if(array[mid_x] < target) {
                low_x = mid_x + 1;
            } else if(array[mid_x] > target) {
                high_x = mid_x - 1;
            } else {
                return true;
            }
        }
//        while(low_y < high_y) {
//            mid_y = (low_y + high_y) / 2;
//            if(array[low_x][mid_y] < target) {
//                low_y = mid_y + 1;
//            } else if(array[low_x][mid_y] > target) {
//                high_y = mid_y - 1;
//            } else {
//                return true;
//            }
//        }
        return false;
    }
};

class Solution2 {
public:
    void replaceSpace(char* str, int length) {
        int oldlength = 0;
        int spacenumber = 0;

        int i = 0;
        //注意这里单引号与双引号的区别，单引号是字符类型，双引号为字符串类型
        while(str[i] != '\0') {
            oldlength++;
            if(str[i] == ' ') {
                spacenumber++;
            }
            i++;
        }
        int newlength = oldlength + spacenumber * 2;
        int poldlength = oldlength;
        int pnewlength = newlength;
        while(pnewlength >= 0 && poldlength >= 0) {
            if(str[poldlength] == ' ') {
                str[pnewlength--] = '0';
                str[pnewlength--] = '2';
                str[pnewlength--] = '%';
            } else {
                str[pnewlength--] = poldlength;
            }
            poldlength--;
        }
        cout << oldlength << endl;
        cout << spacenumber << endl;
    }
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main()
{
    //question 1

//    int target;
//    int col;
////    int col, row;
//    cin >> target;
////    cin >> col;
//
//    vector<int> myarray;
//    int a;
//    while(cin >> a) {
//        myarray.push_back(a);
//    }
//
////    vector<int> v(row, 0);
////    vector<vector<int>> myarray(col, v);
////    for(int i = 0; i < col; i++) {
////        for(int j = 0; j < row; j++) {
////            cin >> myarray[i][j];
////        }
////    }
//
//    Solution1 solution;
//    cout << solution.Find(target, myarray) << endl;

    //question 2
//    int length;
//    string str;
//    cin >> length;
//    getchar();//getchar用来处理回车输入，使程序不会立即退出
//    getline(cin, str);
//    Solution2 solution;

    //注意：string类的c_str()方法返回const char* 类型，
    //而const char* 不能直接转化为char*；
//    solution.replaceSpace(&str[0], length);
//    cout << str << endl;

//    int s = "a";
//    cout << s << endl;
    //单引号双引号问题：
    //int s = 'a'; cout << s << endl; 输出为a的ascii码32
    //cout << 'a' << endl; 输出字符a
    //cout << 'aa' << endl; 输出24929(不知道怎么算的)
    //int s = "a"; 则会报错常量字符串类型为常量指针const char*，不能转化为int类型
//    getchar();//getchar()使程序运行完毕后不会立即退出，而是再次输入回车时退出

    ListNode* head;
    ListNode* tail;
    cin >> head->val;
    tail->val = head->val;

    getchar();

    return 0;
}
