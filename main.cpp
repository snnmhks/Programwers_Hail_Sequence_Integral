#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �����ϴ�. ����� ���� �켱 ����ش�.
// �� �������� ���̸� ���Ѵ�. ��ٸ��� ���̴� (��+��)*��/2 ��.
// ������ �޾ƿ´�. �������� ù��° ��, �� ���� ����� ���� ������ ��ġ - �ι�° ��
// �����ؾ� �� ���� ���� 6�� �� ������ ��ġ�� 6�� �ƴϴ� 0,1,2,3,4,5 �̷��� 6����
// ����� ������ ������ ��ġ�� ����� �� - 1�̴�.
// �� ������ �ش�Ǵ� ���̸� �� �����ش�.
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