#include<bits/stdc++.h>
using namespace std;

const int maxlen = 1e6 + 7;

int f[maxlen];
int prime[1000000];
int notprime[maxlen];
int cnt = 0;
void euler(int m)
{
	notprime[1] = 1;
	f[1] = 1;
	for (int i = 2; i <= m; i++)
	{
		if (!notprime[i])
		{
			f[i] = 2;
			prime[++cnt] = i;
		}
		for (int j = 1; j <= cnt && prime[j]*i <= m; j++)
		{
			notprime[i * prime[j]] = 1;
			if (i % prime[j])
			{
				f[i * prime[j]] = f[i] * 2;
			}
			else
			{
				int now = i;
				while (now > 1 && !(now % prime[j]))
				{
					now /= prime[j];
				}
				f[i * prime[j]] = f[i] + f[now];
				break;
			}

		}
	}
}


int main()
{
	int a, b;
	cin >> a >> b;
	euler(b);
	int ans = 0;
	int res = 0;
	for (int i = a; i <= b; i++)
	{
		if (ans < f[i])
		{
			ans = f[i];
			res = i;
		}
	}
	cout << ans <<" " << res << endl;
	return 0;
}
