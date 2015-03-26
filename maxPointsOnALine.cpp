/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 /*
 记录与第一个点相同的点的个数
 有时候斜率回事正无穷大。
 */
class Solution {
public:
	int maxPoints(vector<Point> &points) {
		if (points.size() <= 1)
			return points.size();
		map<double, int> slapMap;
		int maxV = 1;
		for (int i = 0; i < points.size(); i++)
		{
			int maxSlap = 0,samePoint=0;
			slapMap.clear();
			int maxtmp = 0;
			for (int j = i+1; j < points.size(); j++)
			{
				if (points[i].x == points[j].x&&points[i].y == points[j].y)
				{
					samePoint++;//记录相同的点
					continue;
				}
				if (points[i].x == points[j].x)
				{
					maxSlap++;
					maxtmp = max(maxtmp, maxSlap);
					continue;
				}
				double slap = (points[j].y - points[i].y) ;//it is very import 
				slap/=(points[j].x - points[i].x);//at first make the diff to double or it will be integer
				if (slapMap.find(slap) == slapMap.end())
					slapMap[slap] = 1;
				else
					slapMap[slap]++;
				maxtmp = max(maxtmp, slapMap[slap]);
			}
			maxV = max(maxV,maxtmp+samePoint);
		}
		return maxV+1;
	}
};
