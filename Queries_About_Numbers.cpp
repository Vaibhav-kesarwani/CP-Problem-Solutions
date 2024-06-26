#include <stdio.h>

#include <assert.h>

#define REP(i, a, b) for (i = a; i < b; i++)

#define rep(i, n) REP(i, 0, n)

#define ll long long

int int_read(void)
{

    int res, c;

    for (;;)
    {

        c = getchar() - '0';

        if (0 <= c && c <= 9)
        {
            res = c;
            break;
        }
    }

    for (;;)
    {

        c = getchar() - '0';

        if (0 <= c && c <= 9)
        {
            res = res * 10 + c;
            continue;
        }

        break;
    }

    return res;
}

ll ll_read(void)
{

    ll res;
    int c;

    for (;;)
    {

        c = getchar() - '0';

        if (0 <= c && c <= 9)
        {
            res = c;
            break;
        }
    }

    for (;;)
    {

        c = getchar() - '0';

        if (0 <= c && c <= 9)
        {
            res = res * 10 + c;
            continue;
        }

        break;
    }

    return res;
}

int main()
{

    int Q, T;
    ll N, K;

    int i, j;

    ll p[15];

    int np[15], kp[15];

    int ps, nd, res;

    N = ll_read();

    Q = int_read();

    /*  assert( scanf("%lld%d",&N,&Q)==2 );*/

    assert(1LL <= N && N <= 1000000000000LL);

    assert(1 <= Q && Q <= 500000);

    ps = 0;

    j = 0;
    while (N % 2 == 0)
        j++, N /= 2;

    if (j)
        p[ps] = 2, np[ps] = j, ps++;

    for (i = 3; i * (ll)i <= N; i += 2)
    {

        j = 0;

        while (N % i == 0)
            j++, N /= i;

        if (j)
            p[ps] = i, np[ps] = j, ps++;
    }

    if (N > 1)
        p[ps] = N, np[ps] = 1, ps++;

    nd = 1;

    rep(i, ps) nd *= np[i] + 1;

    while (Q--)
    {

        /*    assert( scanf("%d%lld",&T,&K)==2 );*/

        T = int_read();

        K = ll_read();

        assert(1 <= T && T <= 3);

        assert(1LL <= K && K <= 1000000000000LL);

        rep(i, ps)
        {

            kp[i] = 0;

            while (kp[i] < np[i] && K >= p[i] && K % p[i] == 0)
                kp[i]++, K /= p[i];
        }

        if (T == 1)
        {

            res = 1;

            rep(i, ps) res *= kp[i] + 1;

            printf("%d\n", res);

            continue;
        }

        res = 0;

        if (K == 1)
        {

            res = 1;

            rep(i, ps)
            {

                j = np[i] - kp[i];

                if (j < 0)
                {
                    res = 0;
                    break;
                }

                res *= j + 1;
            }
        }

        if (T == 3)
            res = nd - res;

        printf("%d\n", res);
    }

    return 0;
}