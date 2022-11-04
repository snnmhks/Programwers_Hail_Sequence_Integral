#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 간단하다. 논리대로 점을 우선 찍어준다.
// 각 구역간의 넓이를 구한다. 사다리꼴 넓이는 (윗+밑)*높/2 다.
// 범위를 받아온다. 시작점은 첫번째 값, 끝 점은 찍어준 점의 마지막 위치 - 두번째 값
// 주의해야 할 점이 점을 6개 찍어서 마지막 위치가 6이 아니다 0,1,2,3,4,5 이렇게 6개를
// 찍었기 때문에 마지막 위치는 찍어준 점 - 1이다.
// 그 범위에 해당되는 넓이를 다 더해준다.
//

vector<double> solution(int k, vector<vector<int>> ranges) 
{
    vector<double> area;
    vector<double> Yvalue;
    vector<double> answer;
    int index = 0;

    while (1)
    {
        Yvalue.push_back(k);
        if (k == 1)
        {
            break;
        }
        else if (k % 2 == 0)
        {
            k = k / 2;
        }
        else if (k % 2 == 1)
        {
            k = k * 3 + 1;
        }
    }

    cout << "Yvalue : ";
    for (int i = 0; i < Yvalue.size(); i++)
    {
        cout << Yvalue[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < Yvalue.size()-1; i++)
    {
        double a = (Yvalue[i] + Yvalue[i + 1]) / 2;
        area.push_back(a);
    }

    cout << "area : ";
    for (int i = 0; i < area.size(); i++)
    {
        cout << area[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < ranges.size(); i++)
    {
        int start = ranges[i][0];
        int end = Yvalue.size() - 1 + ranges[i][1];
        if (start > Yvalue.size() || end < start)
        {
            answer.push_back(-1);
        }
        else
        {
            double R = 0;
            for (int j = start; j < end; j++)
            {
                R += area[j];
            }
            answer.push_back(R);
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>>ranges = {{0,0},{0,-1},{2,-3},{3,-3}};
    vector<double> result = solution(5, ranges);
    //for (int i = 0; i < result.size(); i++)
    //{
    //    cout << result[i] << " ";
    //}
    cout << endl;

    int j;
    cin >> j;
}