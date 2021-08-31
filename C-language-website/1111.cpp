#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double PI = acos(-1);
int main()
{
	double w, h, r, tmp1, tmp2, ans;
	while (~scanf("%lf%lf", &w, &h))
	{
		if (w == 0 || h == 0)
			break;
		r = (w / 2.0) < (h / (2.0 * PI + 2.0)) ? (w / 2.0) : (h / (2.0 * PI + 2.0));
		tmp1 = PI * r * r * w;
		r = w / (2.0 * PI) < (h / 3.0) ? w / (2.0 * PI) : (h / 3.0);
		tmp2 = PI * r * r * (h - 2.0 * r);
		ans = tmp1 > tmp2 ? tmp1 : tmp2;
		printf("%.3lf\n", ans);
	}
	return 0;
}
