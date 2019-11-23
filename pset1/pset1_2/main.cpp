#include "polynomial.h"

int main() {
    int m, n, coeff, power;
    cin >> m >> n;

    polynomial a, b, c;
    for(int i = 0; i < m; i++){
        cin >> coeff >> power;
        a.add(coeff, power);
    }
    for(int i = 0; i < n; i++){
        cin >> coeff >> power;
        b.add(coeff, power);
    }

    c = a + b;
    c.show();

    return 0;
}

/*2.
【问题描述】现有2个一元稀疏多项式A和B，请使用线性表完成A+B的运算。
 注：在一元稀疏多项式中，只有1个变量x，且x的指数只为非负整数，如：x^5-2x^4+x^2-3x+5。

【输入形式】

第一行：多项式A和多项式B的项数，用空格隔开。

第二行：多项式A，格式为“系数 次数”，降幂排列，每项均用空格隔开。

第三行：多项式B，格式为“系数 次数”，降幂排列，每项均用空格隔开。

【输出形式】

多项式A+B，格式为“系数 次数”，降幂排列，每项均用空格隔开。
【样例输入】

6 3

2 5 1 4 1 3 -1 2 1 1 1 0

-2 4 1 2 -1 1

【样例输出】

2 5 -1 4 1 3 1 0

【样例说明】

输入的第一行表示多项式A的项数为6，多项式B的项数为2；

输入的第二行表示多项式A的具体内容，为：2x^5+x^4+x^3-x^2+x+1；

输入的第三行表示多项式B的具体内容，为：-2x^4+x^2-x；

输出表示多项式A+B的具体内容，为：2x^5-x^4+x^3+1。

【评分标准】

通过所有测试用例给满分。

注意：若多项式A+B的结果系数全为0，则输出"0 0"。*/