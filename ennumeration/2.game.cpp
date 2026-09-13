#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, w;
ll d0, s1, s2;

// 物体的各个参数
struct Obj
{
    ll x, l, r, t, v;
};
// 操作的各个参数
struct Op
{
    ll p, a, b;
};
// 创建物体组、操作组
vector<Obj> objs;
vector<Op> ops;

// 传入当前物体，计算高度
ll curL(int i, ll T) { return objs[i].l - objs[i].v * (T - objs[i].t); } // 最低点
ll curR(int i, ll T) { return objs[i].r - objs[i].v * (T - objs[i].t); } // 组高点

int main()
{
    scanf("%d %d", &n, &m);
    // 物体组总数设置
    objs.resize(n);
    // 填写每个物体的参数
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld %lld %lld %lld", &objs[i].x, &objs[i].l, &objs[i].r, &objs[i].t, &objs[i].v);
    }
    // 操作组总数设置
    ops.resize(m);
    // 填写每个操作的参数
    for (int i = 0; i < m; i++)
        scanf("%lld %lld %lld", &ops[i].p, &ops[i].a, &ops[i].b);
    // 填写不变的固定数据
    scanf("%lld %lld %lld %d", &d0, &s1, &s2, &w);

    vector<ll> times;
    // 存放关键时刻：开始时间，物体落到x=0的时间
    for (int i = 0; i < n; i++)
    {
        times.push_back(objs[i].t);
        times.push_back(objs[i].t + objs[i].l / objs[i].v + 1);
    }
    // 操作标记时刻，取消标记时刻
    for (int i = 0; i < m; i++)
    {
        times.push_back(ops[i].a);
        times.push_back(ops[i].b);
    }
    // 将时刻的先后顺序进行排序
    sort(times.begin(), times.end());
    // 删除重复元素
    times.erase(unique(times.begin(), times.end()), times.end());

    // 创建状态数组
    vector<char> appeared(n, 0), alive(n, 0); // 判断是否出现，是否依然在场
    vector<int> markedBy(n, -1);              // 判断是否被标记与取消标记，以及具体的操作编号
    ll total = 0, combo = 0, missCnt = 0, endTime = -1, dd0 = d0 * d0;

    for (ll T : times)
    {
        for (int i = 0; i < n; i++)
            // 物体下落到第四象限，未做任何操作
            if (alive[i] && markedBy[i] < 0 && curL(i, T) < 0)
            {
                alive[i] = 0;
                missCnt++;
                combo = 0;
            }
        for (int i = 0; i < n; i++)
            // 物体出现
            if (!appeared[i] && objs[i].t == T)
            {
                appeared[i] = 1;
                alive[i] = 1;
            }

        // 将操作分成标记操作、取消标记操作
        vector<int> markHere, cancelHere;
        for (int j = 0; j < m; j++)
        {
            if (ops[j].a == T)
                markHere.push_back(j);
            if (ops[j].b == T)
                cancelHere.push_back(j);
        }

        // 流程
        vector<ll> bases;
        for (int i = 0; i < n; i++)
        {
            // 已不在场，或者，已经被标记一次。不参与标记的统计
            if (!alive[i] || markedBy[i] >= 0)
                continue;
            ll dx, d2, bestD2 = -1, bestP = -1, bestJ = -1;
            ll h = curL(i, T);
            for (int j : markHere)
            {
                dx = ops[j].p - objs[i].x;
                d2 = dx * dx + h * h;
                // 超出打击范围，不得分
                if (d2 > dd0)
                    continue;
                // 找出最合适的点，作为对应操作点
                if (bestD2 < 0 || d2 < bestD2 || (d2 == bestD2 && ops[j].p < bestP))
                {
                    bestD2 = d2;
                    bestP = ops[j].p; // 最佳操作点的横坐标
                    bestJ = j;        // 最佳操作点对应的操作编号
                }
            }
            if (bestJ >= 0)
            {
                bases.push_back(dd0 - bestD2);
                // 如果是点
                if (objs[i].l == objs[i].r)
                    alive[i] = 0;
                // 如果是线段
                else
                    markedBy[i] = bestJ;
            }
        }
        vector<int> opMiss;
        for (int j : cancelHere)
            for (int i = 0; i < n; i++)
            {
                // 已不在场，或者，标记操作与取消操作编号不一致。不参与取消标记统计
                if (!alive[i] || markedBy[i] != j)
                    continue;
                ll dx = ops[j].p - objs[i].x, h = curR(i, T);
                ll d2 = dx * dx + h * h;
                if (d2 <= dd0)
                    bases.push_back(dd0 - d2);
                else
                    opMiss.push_back(i);
                alive[i] = 0;
            }
        for (ll b : bases)
        {
            combo++; // 连击数+1
            total += b * s1 + combo * s2;
        }
        for (int i : opMiss)
        {
            missCnt++; // miss数+1
            combo = 0;
        }

        // 判定物体是否全部下落完毕，或者，miss超过要求数
        bool allGone = true;
        for (int i = 0; i < n; i++)
            if (!(appeared[i] && !alive[i]))
                allGone = false;
        if (allGone)
        {
            endTime = T;
            break;
        }
        if (missCnt > w)
        {
            endTime = T;
            break;
        }
    }
    printf("%lld\n%lld\n", total, endTime);
}