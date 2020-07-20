#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int cnt[9];

int getMax()
{
	for(int i=8; i>=0; i--)
	{
		if(cnt[i])
			return i+1;
	}
}
int main()
{
	int t,N,M,ans=0;
	cin >> t;
	
	int tc;
	while(t--)
	{
		queue<pair<int, bool> > q;
		cin >> N >> M;
		
		for(int i=0; i<N; i++)
		{
			cin >> tc;
			cnt[tc-1]++;
			if(i==M)
				q.push({tc, true});
			else
				q.push({tc, false});
		}
		
		while(!q.empty())
		{
			pair<int, bool> temp = q.front();
			q.pop();
			
			int max = getMax();
			//cout << "max : " << max << "\n";
			if(temp.first<max)//max가 아닌 경우 
			{ 
				q.push(temp);
			}
			else if(temp.first==max)//max인 경우 
			{
				if(temp.second == true)//ㅇ 
				{
					ans++;
					break;
				}
				else
				{
					ans++;
					cnt[max-1]--;	
				}
				                   	 
			} 
		}
		
		cout << ans << '\n';
		ans=0;
		memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}
