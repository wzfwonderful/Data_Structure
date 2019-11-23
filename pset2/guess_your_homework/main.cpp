#include <iostream>
using namespace std;

int main() {
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    //calculate the count
    int count = 1;
    for(int i = 0; i < k; i++) {
        count *= 10;
    }

    int No = x;
    for(int i = 0; i < count; i++) {
        No = (No + m) % n;
        //search the same circle and simplify the computation
        //faster way
        if(No == x){
            count = count % (i + 1);
            i = -1;
        }
        //slower way
        /*if(No == x){
            int tmp = i + 1;
            while((i + tmp) < count){
                i += tmp;
            }
        }*/
    }

    cout << No;
    return 0;
}

/*
2.
【问题描述】

n个助教（编号从0到n-1）给大家出题。每次作业每人出一道题，也就是说，每次作业有n个题，题目的编号也为0到n-1。
最初，第0号助教出的题题号为0，第1号助教出的题题号为1，……，依此类推。
但是，助教们觉得一直这样也没有意思，于是，他们制定了如下规则：
每出完一次作业后，出第0号题的助教改出第m号题，出第1号题的助教改出第m+1号题，……，依此类推，
出第n−m号题目的助教改出第0号题，出第n-m+1号题目的助教改出第1号题目，……，出第n-1号题目的助教改出第m-1号题。
现在，一共出了10^k (10的k次方)次作业，请问x号助教下次出题的题号。

【输入形式】

输入共1行，包含4个整数n、m、k、x每两个整数之间用一个空格隔开。

【输出形式】

输出共1行，包含1个整数，表示10^k(10的k次方)轮后x号助教下次出题的题号。

【样例输入】

10 3 4 5

【样例输出】

5

【样例说明】

对于100%的数据，1<𝑛<1,000,000，0<𝑚<𝑛，1≤x≤n，0<𝑘<100。

【评分标准】
 */
