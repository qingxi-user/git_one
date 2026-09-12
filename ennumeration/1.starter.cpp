#include <bits/stdc++.h>
using namespace std;
// 题目一：n元数组，可重复，每格1-k，字典序
int n, k;
int arr1[10];
void def(int pos)
{
    if (pos == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << " " << arr1[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        arr1[pos] = i;
        def(pos + 1);
    }
}
// 题目二：从1-k里取n个，不重复取数，字典序
int arr2[10];
void aef(int pos, int start)
{
    if (pos == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << " " << arr2[i];
        }
        cout << endl;
        return;
    }
    for (int x = start; x <= k; x++)
    {
        arr2[pos] = x;
        aef(pos + 1, x + 1);
    }
}
// 题目三：n个学生挑任意个学生去参加比赛，去的标Y，不去的标N
char brr[3] = {'N', 'Y'};
char crr[50];
void bef(int pos)
{
    if (pos == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << crr[i];
        }
        cout << endl;
        return;
    }
    for (int x = 0; x < 2; x++)
    {
        crr[pos] = brr[x];
        bef(pos + 1);
    }
}
int main()
{
    cout << "输入要填充几个数字/学生数n：";
    cin >> n;
    cout << "数字范围上限k：";
    cin >> k;
    cout << "元组法：n个位置，每个位置数的范围都是“1-k”，按字典序排列\n";
    def(0);
    cout << "组合元组：1-k取n个数，按字典序排列\n";
    aef(0, 1);
    cout << "参赛人数序列\n";
    bef(0);
    return 0;
}